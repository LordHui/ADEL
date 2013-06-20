#ifndef OPERATIONS_H
#define OPERATIONS_H

const double MaxValue = 1000;

struct BinaryOperation {
    virtual double GetValue(double left, double right) = 0;
    virtual bool CheckArgs(double left, double right) = 0;
    virtual std::string ToString(std::string left, std::string right) = 0;
};

struct UnaryOperation {
    virtual double GetValue(double right) = 0;
    virtual bool CheckArgs(double right) = 0;
    virtual std::string ToString(std::string right) = 0;
};

struct Add : BinaryOperation {
    double GetValue(double left, double right) {
        return left + right;
    }
    bool CheckArgs(double left, double right) {
        return abs(left + right) < MaxValue;
    }
    std::string ToString(std::string left, std::string right) {
        return "(" + left + " + " + right + ")";
    }
};

struct Sub : BinaryOperation {
    double GetValue(double left, double right) {
        return left - right;
    }
    bool CheckArgs(double left, double right) {
        return abs(left - right) < MaxValue;
    }
    std::string ToString(std::string left, std::string right) {
        return "(" + left + " - " + right + ")";
    }
};

struct Mul : BinaryOperation {
    double GetValue(double left, double right) {
        return left * right;
    }
    bool CheckArgs(double left, double right) {
        return abs(left * right) < MaxValue;
    }
    std::string ToString(std::string left, std::string right) {
        return left + " * " + right;
    }
};

struct Div : BinaryOperation {
    double GetValue(double left, double right) {
        return left / right;
    }
    bool CheckArgs(double left, double right) {
        return (right != 0) && (abs(left / right) < MaxValue);
    }
    std::string ToString(std::string left, std::string right) {
        return left + " / " + right;
    }
};

struct Pow : BinaryOperation {
    double GetValue(double left, double right) {
        return pow(left, right);
    }
    bool CheckArgs(double left, double right) {
        return (left > 0) && (abs(pow(left, right) < MaxValue));
    }
    std::string ToString(std::string left, std::string right) {
        return "pow(" + left + ", " + right + ")";
    }
};

struct Atan2 : BinaryOperation {
    double GetValue(double left, double right) {
        return atan2(left, right);
    }
    bool CheckArgs(double left, double right) {
        return (left * right) != 0 && (atan2(left, right) < MaxValue);
    }
    std::string ToString(std::string left, std::string right) {
        return "atan2(" + left + ", " + right + ")";
    }
};

struct Sin : UnaryOperation {
    double GetValue(double right) {
        return sin(right);
    }
    bool CheckArgs(double right) {
        return true;
    }
    std::string ToString(std::string right) {
        return "sin(" + right + ")";
    }
};

struct Cos : UnaryOperation {
    double GetValue(double right) {
        return cos(right);
    }
    bool CheckArgs(double right) {
        return true;
    }
    std::string ToString(std::string right) {
        return "cos(" + right + ")";
    }
};

struct Tan : UnaryOperation {
    double GetValue(double right) {
        return tan(right);
    }
    bool CheckArgs(double right) {
        return (cos(right) != 0) && (abs(tan(right) < MaxValue));
    }
    std::string ToString(std::string right) {
        return "tan(" + right + ")";
    }
};

struct Asin : UnaryOperation {
    double GetValue(double right) {
        return asin(right);
    }
    bool CheckArgs(double right) {
        return abs(right) <= 1.0;
    }
    std::string ToString(std::string right) {
        return "asin(" + right + ")";
    }
};

struct Acos : UnaryOperation {
    double GetValue(double right) {
        return acos(right);
    }
    bool CheckArgs(double right) {
        return abs(right) <= 1.0;
    }
    std::string ToString(std::string right) {
        return "acos(" + right + ")";
    }
};

struct Atan : UnaryOperation {
    double GetValue(double right) {
        return atan(right);
    }
    bool CheckArgs(double right) {
        return abs(atan(right)) < MaxValue;
    }
    std::string ToString(std::string right) {
        return "atan(" + right + ")";
    }
};

struct Sinh : UnaryOperation {
    double GetValue(double right) {
        return sinh(right);
    }
    bool CheckArgs(double right) {
        return abs(sinh(right)) < MaxValue;
    }
    std::string ToString(std::string right) {
        return "sinh(" + right + ")";
    }
};

struct Cosh : UnaryOperation {
    double GetValue(double right) {
        return cosh(right);
    }
    bool CheckArgs(double right) {
        return abs(cosh(right)) < MaxValue;
    }
    std::string ToString(std::string right) {
        return "cosh(" + right + ")";
    }
};

struct Tanh : UnaryOperation {
    double GetValue(double right) {
        return tanh(right);
    }
    bool CheckArgs(double right) {
        return abs(tanh(right)) < MaxValue;
    }
    std::string ToString(std::string right) {
        return "tanh(" + right + ")";
    }
};

struct UnaryMinus : UnaryOperation {
    double GetValue(double right) {
        return -right;
    }
    bool CheckArgs(double right) {
        return true;
    }
    std::string ToString(std::string right) {
        return "(-" + right + ")";
    }
};

struct Log : UnaryOperation {
    double GetValue(double right) {
        return log(right);
    }
    bool CheckArgs(double right) {
        return (right > 0) && (abs(log(right)) < MaxValue);
    }
    std::string ToString(std::string right) {
        return "log(" + right + ")";
    }
};

struct Log10 : UnaryOperation {
    double GetValue(double right) {
        return log10(right);
    }
    bool CheckArgs(double right) {
        return (right > 0) && (abs(log10(right)) < MaxValue);
    }
    std::string ToString(std::string right) {
        return "log10(" + right + ")";
    }
};

struct Exp : UnaryOperation {
    double GetValue(double right) {
        return exp(right);
    }
    bool CheckArgs(double right) {
        return abs(exp(right)) < MaxValue;
    }
    std::string ToString(std::string right) {
        return "exp(" + right + ")";
    }
};

struct Sqrt : UnaryOperation {
    double GetValue(double right) {
        return sqrt(right);
    }
    bool CheckArgs(double right) {
        return right > 0;
    }
    std::string ToString(std::string right) {
        return "sqrt(" + right + ")";
    }
};

struct Abs : UnaryOperation {
    double GetValue(double right) {
        return abs(right);
    }
    bool CheckArgs(double right) {
        return right != 0;
    }
    std::string ToString(std::string right) {
        return "abs(" + right + ")";
    }
};

struct Ceil : UnaryOperation {
    double GetValue(double right) {
        return ceil(right);
    }
    bool CheckArgs(double right) {
        return right != ceil(right);
    }
    std::string ToString(std::string right) {
        return "ceil(" + right + ")";
    }
};

struct Floor : UnaryOperation {
    double GetValue(double right) {
        return floor(right);
    }
    bool CheckArgs(double right) {
        return right != floor(right);
    }
    std::string ToString(std::string right) {
        return "floor(" + right + ")";
    }
};

#endif  // OPERATIONS_H
