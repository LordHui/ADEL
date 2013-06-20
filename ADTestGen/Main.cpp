#include <map>
#include <vector>
#include <fstream>
#include "TestGenHelper.h"
#include "Operations.h"

const unsigned SimpleTestCases = 100;
const unsigned ComplexTestCases = 10;
const unsigned LoopTestCases = 1;
const unsigned TotalTestCases =  SimpleTestCases + ComplexTestCases + LoopTestCases;

const unsigned MaxVarCount = 10;
const unsigned MaxTmpCount = 5;
const unsigned MaxConstCount = 5;

const unsigned MaxTestGenIterations = 1000;
const unsigned LoopIterations = 10;
const double MaxConstValue = 5.0;
const double MaxVarValue = 5.0;

const unsigned UnaryOpsLimit = MaxVarCount;

double Truncate(double value) {
    return  floor(value * pow(10.0, Precision)) / pow(10.0, Precision);
};

double GetRandomValue(double maxValue) {
    return Truncate(maxValue * (2.0 * (rand() % RAND_MAX) / (1.0 * RAND_MAX) - 1.0));
};

int PopulateBinaryOps(std::map<int, BinaryOperation*>& binaryOps) {
    int index = 0;
    binaryOps[index++] = new Add();
    binaryOps[index++] = new Sub();
    binaryOps[index++] = new Mul();
    binaryOps[index++] = new Div();
    binaryOps[index++] = new Pow();
    //binaryOps[index++] = new Atan2();
    return index;
};

int PopulateUnaryOps(std::map<int, UnaryOperation*>& unaryOps) {
    int index = 0;
    unaryOps[index++] = new Sin();
    unaryOps[index++] = new Cos();
    unaryOps[index++] = new Tan();
    unaryOps[index++] = new Asin();
    unaryOps[index++] = new Acos();
    unaryOps[index++] = new Atan();
    //unaryOps[index++] = new Sinh();
    //unaryOps[index++] = new Cosh();
    //unaryOps[index++] = new Tanh();
    unaryOps[index++] = new UnaryMinus();
    unaryOps[index++] = new Exp();
    unaryOps[index++] = new Log();
    //unaryOps[index++] = new Log10();
    unaryOps[index++] = new Sqrt();
    //unaryOps[index++] = new Abs();
    return index;
};

void CleanBinaryOps(std::map<int, BinaryOperation*>& binaryOps, int count) {
    for (int i = 0; i < count; i++) {
        delete binaryOps[i];
    }
};

void CleanUnaryOps(std::map<int, UnaryOperation*>& unaryOps, int count) {
    for (int i = 0; i < count; i++) {
        delete unaryOps[i];
    }
};

void AddVariables(std::map<std::string, double>& expressions, const double(&variables)[MaxVarCount]) {
    for (int i = 0; i < MaxVarCount; i++) {
        expressions[ "x[" + IntToStr(i) + "]"] = variables[i];
    }
};

void AddTemporaries(std::map<std::string, double>& expressions, const double(&temporaries)[MaxTmpCount]) {
    for (int i = 0; i < MaxTmpCount; i++) {
        expressions[ "tmp" + IntToStr(i)] = temporaries[i];
    }
};

void AddConstants(std::map<std::string, double>& expressions) {
    for (int i = 0; i < MaxConstCount; i++) {
        double constant = GetRandomValue(MaxConstValue);
        std::string key = DoubleToStr(constant);
        if (constant < 0.0) {
            key = "(" + key + ")";
        }
        expressions[key] = constant;
    }
};

void PopulateExpressions(std::map<std::string, double>& expressions, int maxInterations = MaxTestGenIterations) {
    std::map<int, BinaryOperation*> binaryOps;
    int binaryOpsCount = PopulateBinaryOps(binaryOps);
    std::map<int, UnaryOperation*> unaryOps;
    int unaryOpsCount = PopulateUnaryOps(unaryOps);

    int unaryOpsCounter = 0;
    while (expressions.size() > 1 && maxInterations > 0) {
        maxInterations--;
        std::map<std::string, double>::iterator leftArg = expressions.begin();
        std::advance(leftArg, (rand() % expressions.size()));
        std::map<std::string, double>::iterator rightArg = expressions.begin();
        std::advance(rightArg, (rand() % expressions.size()));
        if (rightArg == leftArg) {
            continue;
        }
        int opIndex = rand() % (binaryOpsCount + unaryOpsCount);

        if (opIndex < binaryOpsCount) {
            std::map<int, BinaryOperation*>::iterator binaryOp = binaryOps.begin();
            std::advance(binaryOp, opIndex);
            if (binaryOp->second->CheckArgs(leftArg->second, rightArg->second)) {
                expressions[binaryOp->second->ToString(leftArg->first, rightArg->first)] = binaryOp->second->GetValue(leftArg->second, rightArg->second);
                expressions.erase(leftArg);
                expressions.erase(rightArg);
            }
        } else {
            if (unaryOpsCounter >= UnaryOpsLimit) {
                continue;
            }
            unaryOpsCounter++;
            std::map<int, UnaryOperation*>::iterator unaryOp = unaryOps.begin();
            std::advance(unaryOp, opIndex - binaryOpsCount);
            if (unaryOp->second->CheckArgs(leftArg->second)) {
                expressions[unaryOp->second->ToString(leftArg->first)] = unaryOp->second->GetValue(leftArg->second);
                expressions.erase(leftArg);
            }
        }
    }

    CleanBinaryOps(binaryOps, binaryOpsCount);
    CleanUnaryOps(unaryOps, unaryOpsCount);
}

void GenerateFunctionHeader(std::vector<std::string>& lines, int i) {
    lines.push_back("template<typename ADType>");
    lines.push_back("struct FunctionSpec" + IntToStr(i) + " : FunctionBase<ADType> {");
    lines.push_back("    ADType TestFunction(const ADType(&x)[DataInSize]) {");
}

void GenerateFunctionFooter(std::vector<std::string>& lines) {
    lines.push_back("    };");
    lines.push_back("};");
    lines.push_back("");
}

void GenerateSimpleTestCases(int startIndex, std::vector<std::string>& lines, std::map<std::string, double>& expressions, const double(&variables)[MaxVarCount]) {
    for (int i = startIndex; i < startIndex + SimpleTestCases; i++) {
        GenerateFunctionHeader(lines, i);
        AddVariables(expressions, variables);
        AddConstants(expressions);
        PopulateExpressions(expressions);
        std::map<std::string, double>::iterator expression = expressions.begin();
        std::advance(expression, rand() % expressions.size());
        lines.push_back("        return " + expression->first + ";");
        expressions.clear();
        GenerateFunctionFooter(lines);
    }
}

void GenerateComplexTestCases(int startIndex, std::vector<std::string>& lines, std::map<std::string, double>& expressions, double(&variables)[MaxVarCount]) {
    double temporaries[MaxTmpCount];
    for (int i = startIndex; i < startIndex + ComplexTestCases; i++) {
        GenerateFunctionHeader(lines, i);
        for (int j = 0; j < MaxTmpCount; j++) {
            AddVariables(expressions, variables);
            AddConstants(expressions);
            PopulateExpressions(expressions);
            std::map<std::string, double>::iterator expression = expressions.begin();
            std::advance(expression, rand() % expressions.size());
            temporaries[j] = expression->second;
            lines.push_back("        ADType tmp" + IntToStr(j) + " = " + expression->first + ";");
            expressions.clear();
        }

        AddVariables(expressions, variables);
        AddConstants(expressions);
        AddTemporaries(expressions, temporaries);
        PopulateExpressions(expressions);

        std::map<std::string, double>::iterator expression = expressions.begin();
        std::advance(expression, rand() % expressions.size());
        lines.push_back("        return " + expression->first + ";");
        expressions.clear();
        GenerateFunctionFooter(lines);
    }
}

void GenerateLoopTestCases(int startIndex, std::vector<std::string>& lines, std::map<std::string, double>& expressions, double(&variables)[MaxVarCount]) {
    double temporaries[MaxTmpCount];
    for (int i = startIndex; i < startIndex + LoopTestCases; i++) {
        GenerateFunctionHeader(lines, i);
        for (int j = 0; j < MaxTmpCount; j++) {
            AddVariables(expressions, variables);
            AddConstants(expressions);
            PopulateExpressions(expressions, 0);
            std::map<std::string, double>::iterator expression = expressions.begin();
            std::advance(expression, rand() % expressions.size());
            temporaries[j] = expression->second;
            lines.push_back("        ADType tmp" + IntToStr(j) + " = " + expression->first + ";");
            expressions.clear();
        }
        lines.push_back("        for(int i = 0; i < LoopIterations; i++){");
        for (int j = 0; j < MaxTmpCount; j++) {
            AddVariables(expressions, variables);
            AddConstants(expressions);
            AddTemporaries(expressions, temporaries);
            PopulateExpressions(expressions);
            std::map<std::string, double>::iterator expression = expressions.begin();
            std::advance(expression, rand() % expressions.size());
            temporaries[j] = expression->second;
            lines.push_back("            tmp" + IntToStr(j) + " = " + expression->first + ";");
            expressions.clear();
        }
        lines.push_back("        }");
        AddVariables(expressions, variables);
        AddConstants(expressions);
        AddTemporaries(expressions, temporaries);
        PopulateExpressions(expressions);

        std::map<std::string, double>::iterator expression = expressions.begin();
        std::advance(expression, rand() % expressions.size());
        lines.push_back("        return " + expression->first + ";");
        expressions.clear();
        GenerateFunctionFooter(lines);
    }
}


int main() {
    srand(static_cast<unsigned>(time(NULL)));
    double variables[MaxVarCount];
    for (int i = 0; i < MaxVarCount; i++) {
        variables[i] = GetRandomValue(MaxVarValue);
    }
    std::map<std::string, double> expressions;
    std::ofstream output;
    output.open("../ADTest/TestFunctions.h");
    std::vector<std::string> lines;
    lines.push_back("#ifndef TESTFUNCTIONS_H");
    lines.push_back("#define TESTFUNCTIONS_H");
    lines.push_back("");
    lines.push_back("const int DataInSize = " + IntToStr(MaxVarCount) + ";");
    lines.push_back("const int SimpleTestCases = " + IntToStr(SimpleTestCases) + ";");
    lines.push_back("const int ComplexTestCases = " + IntToStr(ComplexTestCases) + ";");
    lines.push_back("const int LoopTestCases = " + IntToStr(LoopTestCases) + ";");
    lines.push_back("const int TotalTestCases = " + IntToStr(TotalTestCases) + ";");
    lines.push_back("const int LoopIterations = " + IntToStr(LoopIterations) + ";");
    lines.push_back("");
    std::string arguments = "";
    for (int i = 0; i < MaxVarCount; i++) {
        arguments += DoubleToStr(variables[i]) + ", ";
    }
    arguments = arguments.substr(0, arguments.size() - 2);
    lines.push_back("const real realArgs[DataInSize] = {" + arguments + "};");
    lines.push_back("");
    lines.push_back("template<typename ADType>");
    lines.push_back("struct FunctionBase {");
    lines.push_back("    virtual ADType TestFunction(const ADType(&x)[DataInSize]) = 0;");
    lines.push_back("};");
    lines.push_back("");

    GenerateSimpleTestCases(0, lines, expressions, variables);
    GenerateComplexTestCases(SimpleTestCases, lines, expressions, variables);
    GenerateLoopTestCases(SimpleTestCases + ComplexTestCases, lines, expressions, variables);

    lines.push_back("template<typename ADType>");
    lines.push_back("void Initialize(FunctionBase<ADType>* testArray[TotalTestCases]) {");
    for (int i = 0; i < TotalTestCases; i++) {
        lines.push_back("    testArray[" + IntToStr(i) + "] = new FunctionSpec" + IntToStr(i) + "<ADType>();");
    }
    lines.push_back("};");
    lines.push_back("");
    lines.push_back("template<typename ADType>");
    lines.push_back("void Finalize(FunctionBase<ADType>* testArray[TotalTestCases]) {");
    lines.push_back("    for (int i = 0; i < TotalTestCases; i++)");
    lines.push_back("        delete testArray[i]; ");
    lines.push_back("};");
    lines.push_back("");
    lines.push_back("#endif  // TESTFUNCTIONS_H");

    for (std::vector<std::string>::iterator line = lines.begin(); line != lines.end(); line++) {
        output << *line << '\n';
    }
    output.close();
    return 0;
};

