#ifndef TESTFUNCTIONS_H
#define TESTFUNCTIONS_H

const int DataInSize = 10;
const int SimpleTestCases = 100;
const int ComplexTestCases = 10;
const int LoopTestCases = 1;
const int TotalTestCases = 111;
const int LoopIterations = 10;

const real realArgs[DataInSize] = {3.317, 3.227, -3.062, -1.149, -1.147, 1.992, -2.961, 1.800, 2.924, 3.003};

template<typename ADType>
struct FunctionBase {
    virtual ADType TestFunction(const ADType(&x)[DataInSize]) = 0;
};

template<typename ADType>
struct FunctionSpec0 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (((x[8] + sin(x[7])) + x[1]) + (atan(atan(x[3])) / (-4.973) - pow((x[0] - (-3.071)), ((-1.579) - cos(2.166)) / x[5]))) / (x[6] - tan(acos(exp(x[4]))) / x[9] * x[2]) * (-3.129);
    };
};

template<typename ADType>
struct FunctionSpec1 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (x[8] * x[1] + ((-4.547) + (pow(sin((-3.190)), x[9]) + ((((-x[5]) - cos(x[3])) + log(((-2.908) + x[0]))) / atan(sin(x[6])) + (-3.256)) * (x[4] - (tan((x[2] + x[7])) + (-1.979))))));
    };
};

template<typename ADType>
struct FunctionSpec2 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (-3.714) * (sin(x[8]) - x[1]) / ((sin(x[4]) - (-1.182) * x[5] * 1.837) * acos(cos((-0.6790))) - (x[7] + tan(x[3]))) / ((-2.938) * x[0] - (x[2] + x[6])) * tan(sqrt(x[9]));
    };
};

template<typename ADType>
struct FunctionSpec3 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return x[6] * (log(x[9]) * log(((pow(0.7240, x[2]) + acos(0.6090)) + (x[8] - atan(3.638)))) - atan(x[5] / x[4]) * (-exp(x[3] * 4.205)) * (x[0] - (x[7] - (-0.07200) / x[1])));
    };
};

template<typename ADType>
struct FunctionSpec4 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (x[5] + ((4.656 + x[7]) + tan(tan((-2.764))))) * acos(0.8810) * asin(cos((x[1] - x[4]))) * atan(cos(x[6])) * pow((x[8] + (-2.328)), x[2]) * ((x[9] - x[0]) - sin((-2.864)) / asin(atan(x[3])));
    };
};

template<typename ADType>
struct FunctionSpec5 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((tan(x[4]) - (x[8] - x[1]) / (pow(pow(tan(x[6]) * x[9] * sin(x[7]), exp((-3.410))), (-0.2830)) - (x[3] + cos(1.957))) * x[0] * 1.137 / log(3.450)) - (-x[5] * tan(x[2])));
    };
};

template<typename ADType>
struct FunctionSpec6 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return x[5] / ((x[1] + (-0.1340)) - exp(x[6])) / x[0] / atan(x[8]) * cos(1.576) * (atan(x[9]) / x[3] + (2.813 + x[2] * x[7]) / pow(acos(exp((-2.337))), (cos(x[4]) - (-4.923))));
    };
};

template<typename ADType>
struct FunctionSpec7 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (((-tan(sin(x[1]))) + sin((-2.177)) / x[6] * x[3] / (x[2] * 3.152 / (-2.347) / x[5] + (x[0] + x[9]))) - (x[7] * 2.730 + pow((-x[4]), (-4.791))) * (-x[8]));
    };
};

template<typename ADType>
struct FunctionSpec8 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (((-atan(x[4])) * (-x[1]) + x[9] * x[5]) - (x[0] / x[6] / (atan((-2.772)) + (cos((-0.1720)) - (-3.007))) + cos(x[2])) * ((x[7] + exp((-4.710 * x[8]))) + x[3]) * (-4.592));
    };
};

template<typename ADType>
struct FunctionSpec9 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((x[2] / x[1] - (pow(x[8], ((-0.2200) + tan(1.722))) + pow(x[7], atan(4.089))) * exp(sin(atan(x[0])))) - log(x[9]) / pow(exp(2.384), x[3]) / (x[4] - ((-1.843) + pow(exp(x[5]), x[6]))));
    };
};

template<typename ADType>
struct FunctionSpec10 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return pow((pow((0.5510 - (-3.551)), pow(x[5], cos(x[6]) * (x[8] - x[4]) * asin(cos(x[1]))) * x[2] / 3.465 * (-2.806) * x[3]) + (tan(x[0]) + cos(4.654))), pow(x[9], (-x[7])));
    };
};

template<typename ADType>
struct FunctionSpec11 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (x[9] * ((x[5] * (-exp((-2.876))) + x[4]) - pow(exp(x[0]), x[3]) * (x[2] + (acos(cos(x[6])) + tan(4.265))) * (-2.627) / x[1]) + (-4.843) / pow(pow(x[8], x[7]), tan((-0.6210))));
    };
};

template<typename ADType>
struct FunctionSpec12 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((cos(1.315) + x[7]) * (sin(1.786) + x[3]) + (-4.218) / asin(cos(x[9]))) / cos(x[8]) * (((sin(x[6]) + atan(1.797)) / acos(x[5] / pow(x[0], x[1])) + cos((-3.353))) + (x[4] + x[2]));
    };
};

template<typename ADType>
struct FunctionSpec13 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (tan(tan(2.430)) * ((-3.415) - x[8] * (-(-3.783))) / (-4.002) / tan(tan(atan(x[9]))) / (tan(x[3]) + (-x[6]) / x[2]) / x[4] * 3.883 * x[0] / x[1] * sqrt(x[7]) - x[5]);
    };
};

template<typename ADType>
struct FunctionSpec14 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (pow((-4.297) / ((-exp(x[4]) * x[5]) + x[6]) * (1.461 + pow((-x[3]), x[1])), x[7] / x[9] * (-3.896) / sqrt(x[0])) - cos(sin(tan(x[8]))) * x[2] / (-2.803) * 3.405);
    };
};

template<typename ADType>
struct FunctionSpec15 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((x[1] * (x[0] - x[4]) * 2.000 * log(0.9450) - exp(x[5])) + ((log(x[8]) - x[2]) + (-3.279))) * pow(exp((-x[3])), ((atan(x[7]) / x[6] - atan(sin(2.873))) + x[9])) * 2.893;
    };
};

template<typename ADType>
struct FunctionSpec16 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return pow(pow(((pow(tan(1.201), pow(0.5110, x[0])) - x[4]) - x[2]), x[9] * (-4.820)), (atan(x[8]) * x[5] * sin((-3.920)) / x[3] + (x[1] + atan(x[6])))) / (x[7] - 4.530);
    };
};

template<typename ADType>
struct FunctionSpec17 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((x[4] + x[9]) * x[6] + x[3]) * pow(acos((-x[2] / 4.886)), (tan(x[5]) - ((-2.656) - pow(log(x[1]), 4.928)))) * (pow(sin((-4.468)), (-(-0.5300))) + x[7]) / x[0] / sqrt(x[8]);
    };
};

template<typename ADType>
struct FunctionSpec18 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((x[2] - cos(x[9]) * x[1]) + ((log(atan(x[5])) + 3.041) * cos(tan(x[3])) * pow(sqrt(sqrt(x[8])), x[4]) / x[0] / ((x[6] + x[7] / (-1.417)) + cos((-3.814))) * log(0.5400) - (-0.8350)));
    };
};

template<typename ADType>
struct FunctionSpec19 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((cos(x[5]) + (1.356 - ((-2.494) - x[2]))) / (pow(x[8], (-3.191)) - (x[4] - (x[6] + pow(log(x[9]), (-x[3]))))) + x[0] * sin(x[1]) * log((3.285 - x[7])) / 2.873);
    };
};

template<typename ADType>
struct FunctionSpec20 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (cos((-1.541)) / (-2.527) * (pow((x[0] + (0.1660 + x[4])) * (log(x[1]) + x[3]), x[9]) + (x[2] / x[6] + (-3.708))) / acos(cos(x[7])) / exp(x[5]) / 3.188 - x[8]);
    };
};

template<typename ADType>
struct FunctionSpec21 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((-x[9]) - (((pow(x[7], x[3]) + (-3.916)) + log(x[8])) * tan(3.464) + (((asin((-0.9820)) + x[2]) - sin(x[4])) + pow((x[0] - (sin(1.463) - x[1]) * 1.490) / x[5], exp(x[6])))));
    };
};

template<typename ADType>
struct FunctionSpec22 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (acos(((-4.521) + 4.476)) / x[1] * (exp((x[6] + x[2])) + ((-atan(x[4])) - atan(x[3]))) * x[0] * tan(((-3.403) - x[5])) / (x[8] - x[9]) / (-sin(x[7])) - 0.8700 / sin((-3.665)));
    };
};

template<typename ADType>
struct FunctionSpec23 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((atan((-2.583)) / atan(cos(x[9])) + sqrt((x[6] + x[0]))) - (1.192 / sin(x[4]) / atan((x[7] - 2.228)) * x[3] + (x[5] - x[1] * sqrt(x[8])))) * (pow(1.569, sqrt(4.236)) - x[2]);
    };
};

template<typename ADType>
struct FunctionSpec24 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return pow(atan((-0.9660)) * (-0.7740), (-cos(x[6])) / (-4.619)) * x[9] * x[2] / (pow(exp(x[3]), atan(sin((-0.2030)))) - x[4] / (x[7] - pow(x[5], x[0])) / sqrt(exp((-x[8]))) / (-1.828) * x[1]);
    };
};

template<typename ADType>
struct FunctionSpec25 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (pow((-4.842) / x[3], x[4]) + (x[0] / (x[5] * x[6] - 1.949) * (cos(cos(x[1])) - x[9]) * (sin(x[2]) / (-4.163) - (-1.995)) - (0.02900 + log(x[7] * tan(atan(x[8]))))));
    };
};

template<typename ADType>
struct FunctionSpec26 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (atan(4.529 * sin(atan(x[9])) / (sin(x[7]) - x[4])) - (x[0] + x[2])) / (asin(cos((-1.697))) + x[3]) / x[6] / (((cos((-0.3960)) - 1.360 * x[8]) + log(exp((x[5] - x[1])))) - 2.215);
    };
};

template<typename ADType>
struct FunctionSpec27 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((((x[4] - ((-1.766) - (-2.297) * sin(x[1]))) + x[8]) + pow((-x[6]), tan(x[0])) * x[3] / 2.011) - (sin((atan(exp((x[9] - x[7]))) - cos((-2.182)))) * x[5] + x[2] * sin(4.114)));
    };
};

template<typename ADType>
struct FunctionSpec28 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return pow(2.428, pow(x[0], (-3.468))) * atan(x[4]) * ((x[5] * x[3] - (-0.7420)) - x[9] * sin(exp(((-sin((x[8] + x[2]))) - 3.129)) * x[6] / 1.519) * (-x[1]) / tan(x[7]));
    };
};

template<typename ADType>
struct FunctionSpec29 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((-0.3370) - pow(x[3] / (x[6] + (x[4] - x[9])), cos(x[0]) * x[8] / sin(x[2]) / (tan((asin(0.8000) - x[7] / (-1.833))) - ((-log((4.378 + pow(x[5], log(x[1]))))) + (-1.493)))));
    };
};

template<typename ADType>
struct FunctionSpec30 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (exp(x[7]) + pow(x[2] / tan(x[5]) / x[1], (log(x[0]) + (-4.730))) / (x[4] - 1.070 * x[8]) / x[3] / (-x[9] / (-x[6])) * (1.702 - (-4.315)) * (-exp(1.092)));
    };
};

template<typename ADType>
struct FunctionSpec31 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (((pow(4.022, x[8]) / exp((-1.152 / sin(x[3]))) - x[9]) - ((-x[1]) + sqrt(x[5]))) / (-4.286) + (x[4] * cos((1.240 + x[2])) * atan(x[0]) - (atan(x[6]) - x[7] / 2.124)));
    };
};

template<typename ADType>
struct FunctionSpec32 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((pow(x[1], cos((x[9] + (-0.6190)))) - tan(x[0])) * pow(atan(x[8]), pow((x[7] + x[4] / (-2.913)), (-atan((-2.350))) * tan((-4.859)) / (-1.036))) + x[2] * (x[3] + (x[6] - x[5])));
    };
};

template<typename ADType>
struct FunctionSpec33 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return pow((-1.580) / (-x[4]) / pow(x[7], (-(-2.157))) * (x[5] + (((-4.321) - tan(x[9])) + 0.4250 * 1.385)), (pow(x[1], x[6]) - pow(atan(exp(((-x[0]) - x[8]))), atan(exp((x[2] + x[3]))))));
    };
};

template<typename ADType>
struct FunctionSpec34 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return pow(sqrt(2.369), (acos(atan(x[4])) + x[5])) * (exp(x[8]) * x[2] * x[6] * (tan(x[3]) / x[1] + x[7]) - 2.494 / log(sin(1.097)) / x[0] / sin(4.683) / 4.513 / atan(x[9]));
    };
};

template<typename ADType>
struct FunctionSpec35 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (((2.524 + x[7]) / x[6] + x[4]) - ((x[5] - sin(x[1])) - (x[0] - x[8]))) * ((cos(x[2]) + (x[9] - atan(4.602 / x[3]))) + ((-1.894) - pow(atan(sqrt(1.611)), log(tan(acos(0.06600))))));
    };
};

template<typename ADType>
struct FunctionSpec36 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (2.929 * sin(x[3]) - ((-4.337) / (-2.985) - cos((-x[0]))) * pow((tan(x[5]) + (pow(x[8] * x[7], x[9]) + x[4] * 3.253)), x[6] * x[1])) / (exp(x[2]) - 2.369);
    };
};

template<typename ADType>
struct FunctionSpec37 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (pow((tan((-3.077)) - x[2]), x[3] / pow(pow(sqrt(x[9]), x[1]), x[7] * log(x[0]))) * 1.380 / (exp(x[5]) + (-2.540)) * x[4] * (-3.105) + ((-2.574) - (atan(x[6]) - cos(x[8]))));
    };
};

template<typename ADType>
struct FunctionSpec38 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return pow(x[7], pow(x[5], (-1.152))) / ((-1.793) + (-1.711)) / (x[6] - sin((-2.351)) / 3.005) / (exp(x[8]) + cos(x[0]) * tan(x[4])) / (x[3] + x[1]) / (-x[2]) / sin(exp(x[9]));
    };
};

template<typename ADType>
struct FunctionSpec39 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (tan(cos(((-x[4]) - tan(1.915 * x[8])))) * pow(pow((((x[5] - cos(4.437)) - (x[9] - 3.074)) + (-sin(x[7]))), pow(x[1], x[6])), ((-0.1230) + tan((-2.045)) * x[2] * x[0])) + x[3]);
    };
};

template<typename ADType>
struct FunctionSpec40 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((0.4020 * atan(x[3]) * log(x[9]) / x[4] + (sin(x[8]) - cos(x[6]) * 4.097)) / (-4.817) + (pow(x[5], asin(0.2130)) / pow(x[1], tan(x[2]) * cos(log((1.926 + x[7])))) - exp(x[0])));
    };
};

template<typename ADType>
struct FunctionSpec41 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (((4.926 + (-pow(x[1], log(x[7])))) + (-4.190)) / pow(x[5], acos(cos(x[3]))) - (x[4] - x[2]) * sin(x[8]) / cos((-1.951)) / atan(3.293) * (x[6] - pow(x[9] / x[0], (-2.640))));
    };
};

template<typename ADType>
struct FunctionSpec42 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((cos(x[2]) + x[5]) / atan((-0.9610)) - x[4]) * x[9] / (pow(x[0], cos(x[3])) / (-1.193) / log(x[8]) - ((-4.318) - x[1] / x[7] / (-4.937) / atan(x[6]) * asin(sin(4.592))));
    };
};

template<typename ADType>
struct FunctionSpec43 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (((x[0] * (-3.570) + (log(cos((x[2] + x[6]))) - ((-1.904) + exp((-2.530))))) - pow(atan(x[8]), pow(x[5], asin((-0.5980))))) - exp(3.389) / x[3] / x[7] / cos(x[4]) / cos(x[9]) * (-x[1]));
    };
};

template<typename ADType>
struct FunctionSpec44 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (atan(x[8]) / (x[3] - tan((-3.662))) * pow((x[5] + x[6] * cos(2.860)), acos(cos((x[9] * (x[0] + (-1.256)) * x[7] - x[1])))) * atan((atan((-0.7300)) - 0.3910)) / x[2] - x[4]);
    };
};

template<typename ADType>
struct FunctionSpec45 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((cos(3.173) - ((-1.617) / x[3] / ((-4.647) + sin(atan((x[6] - 4.437)))) + x[9])) - ((-0.09700) * x[2] + sin(x[1]) * ((-exp(x[0])) - x[7])) * (x[5] + tan(x[8])) / x[4]);
    };
};

template<typename ADType>
struct FunctionSpec46 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return pow((x[2] + (-1.127) * (-3.206)), x[9]) / (pow((x[1] - 1.302), x[7]) * exp((pow(x[5], x[4]) - asin(pow((x[8] + (-1.378)), x[6])))) * cos(x[0]) - x[3]) / atan(4.136);
    };
};

template<typename ADType>
struct FunctionSpec47 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return pow((-atan(x[6])) / tan(pow(x[7] / x[9] / pow(2.569, cos(1.985)), x[0])) / (atan((-0.8810)) / x[3] / (-0.5100) * ((-x[2]) - x[4]) * x[5] + (exp(x[8]) - (-(-4.184)))), x[1]);
    };
};

template<typename ADType>
struct FunctionSpec48 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((-x[5]) + (atan(x[6] * 4.335) - 0.8630)) / x[4] / ((x[1] + sqrt(x[9]) / tan(x[3])) * (exp(x[8]) * atan(x[0]) + cos(x[2])) + (((-4.353) + pow(x[7], 2.316)) + (-2.241)));
    };
};

template<typename ADType>
struct FunctionSpec49 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((exp(2.403) * pow(sin(x[9]) * x[7] / (-x[6]), exp(x[3])) + tan(0.5590)) - (x[2] + 1.170) * atan((-0.1820)) * cos(sin(x[4]))) / ((x[0] + x[1]) + (x[5] - 3.886 * x[8]));
    };
};

template<typename ADType>
struct FunctionSpec50 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (x[3] / cos(x[7]) * (x[5] + tan(x[4])) * x[2] * x[9] * x[6] * tan(1.454) / 0.8210 / x[8] - pow(((-1.963) - (-3.250)), ((x[1] + log(log(sqrt(x[0])))) - log(asin(0.6250)))));
    };
};

template<typename ADType>
struct FunctionSpec51 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (pow(tan(x[7] * (-1.730) * sin(log(x[8] * (-4.741) / x[3]))), (x[2] - log(x[0]))) - ((x[1] - ((-1.929) - (-2.618))) + ((x[6] - x[4]) + tan(sin(log(x[9])) * (-4.951) / x[5]))));
    };
};

template<typename ADType>
struct FunctionSpec52 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return pow(atan(x[7]), ((x[0] + x[9]) - (-x[4]))) / x[6] / ((x[2] - (-1.240)) + (-2.719)) / 3.413 / ((x[5] - x[3]) - sin(sin(atan(0.1090))) * (-0.3960) / x[1]) / (-atan(x[8]));
    };
};

template<typename ADType>
struct FunctionSpec53 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return pow(pow(pow(2.104, sin(x[3])) * (pow(x[5], (sin(x[9]) - x[6])) - (3.274 - (-4.459))) / sqrt(x[8]) * x[2] * atan(x[1]) / atan((-1.848)), sin((-0.5890))), ((asin(cos(x[0])) - x[7]) + x[4]));
    };
};

template<typename ADType>
struct FunctionSpec54 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((pow(atan(exp(x[5]) / 0.3710), x[6]) - (-1.939)) + (pow(exp(x[2]), pow(x[8], cos(x[1]))) + ((x[4] - x[0]) - pow(pow(x[9], cos((-1.253))), (x[3] + log(x[7]))))) / ((-1.012) - tan(tan(3.847))));
    };
};

template<typename ADType>
struct FunctionSpec55 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (((sqrt(x[7]) + atan(4.749) * exp(x[4]) / exp(x[2])) + (0.5780 / 1.102 + ((-3.233) + x[6]) / cos(x[0]))) / (x[9] * x[5] - acos((-0.1170))) - (sin(x[1]) + sqrt((x[8] - x[3]))));
    };
};

template<typename ADType>
struct FunctionSpec56 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (-0.8340) * x[7] / x[1] / x[4] / pow(x[5], cos(x[9] / x[3]) * pow(x[0], exp((-x[8])))) / pow(sin(((-3.412) - exp(0.8880))), acos(acos(cos(sin((-4.411) * x[6] * x[2] * 3.775)))));
    };
};

template<typename ADType>
struct FunctionSpec57 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((((-0.9020) + x[1]) + sin(exp(x[2])) / exp(tan(x[0] / x[5] * x[4]))) + (4.801 - (exp((-2.212)) - ((1.918 - x[6]) / x[8] - (4.865 - x[7] / x[3] * sin(x[9]))))));
    };
};

template<typename ADType>
struct FunctionSpec58 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (pow((x[8] / exp((x[0] - 0.1350)) - (x[1] + x[2] * x[5])), cos(x[6] / 4.887)) + (-0.6070) / log(0.2530)) * (x[7] + (sin(x[3]) + x[4])) * cos(1.300 * x[9]);
    };
};

template<typename ADType>
struct FunctionSpec59 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (((-3.927) - (atan(x[0]) + (pow(exp((-3.986)), x[9]) + x[3]))) + ((((-atan(atan(1.198))) + pow(x[5], sin(x[8]))) / x[2] * 4.025 + x[1]) + (-sqrt(x[7])))) / ((x[4] + 1.136) - x[6]);
    };
};

template<typename ADType>
struct FunctionSpec60 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (((x[0] - (x[6] - sin(x[4]))) - x[8] * pow(x[7], x[3] / x[1]) / ((x[5] + sin((-3.419))) - (1.407 - (-4.608)))) + ((-4.831) + ((-0.4400) + x[2])) * cos(sqrt(x[9])));
    };
};

template<typename ADType>
struct FunctionSpec61 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((atan(exp(3.124)) - x[6] * 0.3140) * x[7] - cos((-x[2] * x[4]))) / ((exp(2.962) - x[5] * (-x[1]) / x[8] / (-2.535)) - sin(pow(x[9], x[0] / (-3.950))) / x[3]);
    };
};

template<typename ADType>
struct FunctionSpec62 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((pow(tan(sin(x[8])), x[5]) / pow(x[0], (-2.072)) + (-1.121) / pow(pow((-x[6]), x[2]), (4.005 / (-3.042) - x[4]))) + ((((-1.849) - x[7]) - tan(x[9])) + x[3] / atan(x[1])));
    };
};

template<typename ADType>
struct FunctionSpec63 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (exp((-3.367)) / (x[5] - x[3]) / (sin(0.3420) + sqrt(x[8])) - ((atan(((-2.314) - x[1] * x[7])) - (-4.111)) + (0.6660 / (x[9] + x[2]) - (x[0] + x[6]))) * acos(exp(sin(x[4]))));
    };
};

template<typename ADType>
struct FunctionSpec64 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (((x[5] + x[2]) + 1.443) + ((tan(x[7]) * exp(x[3]) + (-0.6270) * (-0.4390)) / (pow(x[1], x[8]) * x[9] - tan(4.163)) * cos(atan(cos(x[0]))) / x[4] + (x[6] + 4.436)));
    };
};

template<typename ADType>
struct FunctionSpec65 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return pow(atan(cos((-(-2.128) / (-2.726)))) / atan(x[1]), (exp(tan(x[7])) - (atan(((-4.815) + 4.258)) - ((x[9] + (x[4] + x[8])) - (-0.02400))))) * (-(x[3] + x[6] * x[2] / x[0] * x[5]));
    };
};

template<typename ADType>
struct FunctionSpec66 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (((-0.5290) - x[3] / (-0.5170) / ((x[6] / cos(2.887) + sin(cos((x[5] + x[9])))) * x[7] - x[1])) / cos(atan(x[4])) - x[0] / x[8] / (-2.483) / x[2] * (-4.041));
    };
};

template<typename ADType>
struct FunctionSpec67 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return pow(pow((-(-0.004000)) * sqrt(x[7]) / exp((-4.656)), (x[4] + log(pow(x[0], 4.715)))), (x[8] - x[2]) / ((2.370 + x[6]) / (pow(x[5], x[1]) + 1.647) + x[9] * x[3]));
    };
};

template<typename ADType>
struct FunctionSpec68 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return pow(pow((x[6] / x[3] - (cos(x[9] * (-2.669)) - atan(x[8])) * (atan(sin(exp(x[4]))) + cos(x[5]) / (-3.203))), (-0.7400)), pow(pow(x[1], (-2.437) * (x[7] + x[0])), ((-0.5460) - x[2])));
    };
};

template<typename ADType>
struct FunctionSpec69 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((((-2.047) + (x[7] - exp(x[8]))) - x[5]) + (atan(exp(x[6])) - pow(2.897, x[1] * 1.172 / 2.759))) * (((x[2] - (-0.5140)) + x[0]) - x[3]) * (x[4] + exp(x[9]));
    };
};

template<typename ADType>
struct FunctionSpec70 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((-0.8380) * log(x[7]) * (exp(x[3]) - atan(x[9])) * x[1] + pow(pow((x[4] + tan(x[5] / (4.485 + (-2.798)))), tan(x[6])), pow(x[2] * (-4.081), tan(log(x[8])))) / sin(x[0])) / (-3.621);
    };
};

template<typename ADType>
struct FunctionSpec71 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (x[6] + ((x[4] - x[7]) + (x[1] - (-3.246) / pow(x[8], x[3]) / x[5]))) / (x[2] - sin(sin((sin(x[0]) + 0.2980)))) / ((cos((-2.247)) - atan(log(tan((-2.579))))) + x[9]) * 4.872;
    };
};

template<typename ADType>
struct FunctionSpec72 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (-4.410) * (x[6] - x[9]) / x[3] / pow(x[8], ((3.442 - ((2.541 + atan(x[1])) - (cos((-3.177)) - (-4.549)))) + pow((-sin(x[0])), x[4]) / pow(x[5], (x[7] - x[2]))));
    };
};

template<typename ADType>
struct FunctionSpec73 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (x[2] / x[8] - (((x[3] - (-1.994)) + cos(x[6])) + (log(4.770) * (x[0] - (-(-0.8480))) / ((sqrt(x[9]) - x[7]) + log(sqrt(exp(atan(exp(x[4])))))) - x[1] * (0.7850 + log((x[5] - (-0.3720)))))));
    };
};

template<typename ADType>
struct FunctionSpec74 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (((atan(1.480) / pow(x[7] * 2.285, x[8]) + x[5] * sin(x[3])) / sin(x[6]) - (x[2] + (sqrt(sqrt(1.312)) - x[4]))) - ((-x[9]) - (atan(x[1]) + pow(sqrt(2.815) / 4.257, x[0]))));
    };
};

template<typename ADType>
struct FunctionSpec75 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (exp(x[3]) + (4.730 / 3.015 + ((-4.085) - x[5] / cos((-x[2])) * x[9] * (sin(x[6]) - tan(exp(x[7]))))) / (-4.570) * ((cos((x[4] + x[1])) + 1.325) - x[0] * sin(x[8])));
    };
};

template<typename ADType>
struct FunctionSpec76 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (-(x[6] + x[2])) / (-log(pow(sin(exp((-2.266))), (-2.001)))) / 1.681 / (sqrt((x[4] + x[8])) - (x[9] - atan(pow((-(-1.594)), x[3] / ((-1.005) + x[0]))) * exp(sin(x[7])) * x[1] * x[5]));
    };
};

template<typename ADType>
struct FunctionSpec77 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((atan(atan(x[5])) + x[1]) + asin(((-3.541) + 3.552) * (-4.743) / x[0]) / (sin(sin((-3.757))) / (x[4] + pow(x[8], x[3])) - pow(((x[7] - x[6]) + x[2] / x[9]), log(sqrt(1.471)))));
    };
};

template<typename ADType>
struct FunctionSpec78 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((log(4.485) + pow(sqrt(log(x[9])), sin((-2.272)) / x[5])) / (tan(3.408 * x[2]) - x[6] * (-x[1])) * ((-3.079) + x[0]) / cos(x[3] * (-0.03200)) * (tan(x[7]) - cos(x[4])) + cos(x[8]));
    };
};

template<typename ADType>
struct FunctionSpec79 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (((-tan(x[7])) * 4.781 - (x[3] - exp((-3.442) / sqrt(x[0])))) - x[4] * (-2.604) / sin(x[6]) * sqrt(x[9]) * ((atan(x[2]) + sqrt(x[8])) - (-0.5590))) / ((log(x[1]) - 1.840) - cos(x[5]));
    };
};

template<typename ADType>
struct FunctionSpec80 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (((exp(x[8]) - x[5] * (4.389 - (-1.011))) - atan(sin(log(x[9]))) / x[0]) - (x[2] / ((x[3] - atan(x[6])) - cos(4.510)) * 1.908 + (sin(x[4]) - x[1]) / 3.791 / x[7]));
    };
};

template<typename ADType>
struct FunctionSpec81 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (x[6] + pow(pow(0.1520, (-3.543)), exp(x[3])) * (x[1] + (x[2] - (-4.392)) * tan(x[7]))) * x[4] / (cos(x[5]) + (x[8] - (-2.000)) * exp(x[9])) * (-0.5500) * sqrt(x[0]);
    };
};

template<typename ADType>
struct FunctionSpec82 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((x[6] - x[3]) / (x[2] - pow(x[0], x[7]) / x[5]) * exp((-1.323)) * (1.466 - x[4]) - cos(sin((-1.586)) * x[9])) * (atan(3.218) + x[8]) / (exp(x[1]) - cos((-2.752)));
    };
};

template<typename ADType>
struct FunctionSpec83 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (tan((-2.336)) / (-2.781) * x[2] / x[4] / exp(x[1]) * sin(x[5]) * (acos(atan((-2.930) / x[0]) * x[3]) - ((-3.639) + cos(x[7]))) / pow(x[8], x[9]) - (x[6] - atan(3.471)));
    };
};

template<typename ADType>
struct FunctionSpec84 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (((-3.888) * 0.5570 / x[9] + ((-2.034) + ((-x[8]) + (x[7] - x[2])) * 0.5530)) - ((-x[4]) + (x[5] * log(cos(x[3])) - (x[6] - (-3.696))) * x[1] * sqrt(exp(x[0]))));
    };
};

template<typename ADType>
struct FunctionSpec85 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return pow(x[8], x[1]) * (tan((-3.661)) * (cos(sqrt(sqrt(3.612))) - cos(1.781)) - cos(sqrt(x[5]))) / x[6] * ((x[7] - (-4.008)) * x[9] - x[4] / x[0] * ((atan(x[2]) - (-4.358)) + x[3]));
    };
};

template<typename ADType>
struct FunctionSpec86 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (((-2.465) / x[3] / (((sin(x[1]) + 0.2960) + x[6]) + ((pow(sqrt(x[0]), log(x[8])) - sin(x[4])) - 4.849 * x[5] * (asin(sin(0.8270)) - sin(x[9])))) + 2.901) + (cos(x[7]) + x[2]));
    };
};

template<typename ADType>
struct FunctionSpec87 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (cos(x[6]) - x[5] / 4.315 * (-2.385)) * (sqrt((x[1] + (-2.873))) / ((-x[4]) - (x[2] - cos(sqrt(x[9])))) + atan((-0.8130))) * ((x[8] + (x[3] - x[0])) * cos(3.467) - x[7]);
    };
};

template<typename ADType>
struct FunctionSpec88 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((-4.227) - 3.720) / pow(x[8], atan(x[3])) / (x[1] - (((-x[6]) + x[2]) + (-4.642) * pow(exp(x[9]), (sqrt(x[0]) + (-2.813))) * atan((x[5] + x[7])) * exp((-3.474)) / (-x[4])));
    };
};

template<typename ADType>
struct FunctionSpec89 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((((-4.400) - x[7]) + (((x[5] + x[3]) - (-1.509)) - x[8])) - pow(exp(exp(x[4])), ((x[1] + cos(3.481) * cos(x[9])) / x[6] + (pow((-(-4.249)), tan(x[2])) + (-2.162) / tan(x[0])))));
    };
};

template<typename ADType>
struct FunctionSpec90 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((x[3] - x[7]) - ((pow(pow(exp(x[5]), (x[1] - (x[4] * x[2] - tan(x[6])))), (pow(exp(((-2.173) + log(x[0])) / 2.618), 0.2300) + (-3.428))) - exp(x[9]) * (-2.973)) + x[8]));
    };
};

template<typename ADType>
struct FunctionSpec91 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (x[1] / x[4] / cos((x[0] - x[9])) + ((-3.275) + 2.471) / pow(3.541, x[2]) * tan(x[8]) * tan(x[3])) * (x[7] + pow(x[5], (-4.130))) / acos(exp((-2.309))) / atan(x[6]);
    };
};

template<typename ADType>
struct FunctionSpec92 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (log(x[5]) * (x[3] - tan((-4.377))) + x[4] / 3.066 * cos(x[8] / x[9]) / ((-3.912) + (log(atan(0.1950)) - (x[7] + x[2])) / acos(cos(x[1])) / (log(x[0]) + (0.5690 + x[6]))));
    };
};

template<typename ADType>
struct FunctionSpec93 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((sqrt(x[3] / (x[6] - 0.7010)) / (-0.9950) + (x[9] + (sqrt(x[8]) * x[4] - (x[7] + x[1]) * x[2] / (x[0] + x[5])))) - (-4.918) * exp((-(-1.196)) * (-3.158)));
    };
};

template<typename ADType>
struct FunctionSpec94 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (x[5] * pow(x[8], (atan(x[4]) + (-(-3.972)))) * ((x[1] - (x[3] - asin(0.4310) / asin((-0.3930)))) + x[0]) / exp((x[6] / 2.849 - cos(x[2]))) + (x[7] - exp(acos((-2.086) / x[9]))));
    };
};

template<typename ADType>
struct FunctionSpec95 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((pow((x[0] + (-(-0.5280))), (-3.432)) / x[1] - cos(((-0.2880) - cos(x[9])))) / asin((x[3] - x[4])) + pow((x[8] - (-4.657)), exp(x[6])) / (((-4.085) + (x[2] + x[7])) + x[5]));
    };
};

template<typename ADType>
struct FunctionSpec96 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return (x[1] / (-1.815) + (x[3] / x[6] / x[4] - tan(x[8])) * (-(cos(x[5]) + 2.740))) / (exp((-x[9])) - sin((atan((-3.501) * x[7]) + (-2.485)))) * ((x[2] - x[0]) - 0.8790);
    };
};

template<typename ADType>
struct FunctionSpec97 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((x[3] - atan((x[0] - x[4]))) * (x[8] - x[6]) * (x[7] + tan(x[9] * (-2.257) / x[5])) + ((-(-2.282)) / (-0.4840) + (-1.621)) / log(x[1]) * 4.507 / x[2]);
    };
};

template<typename ADType>
struct FunctionSpec98 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return x[4] * sin(sin(x[0])) / (-x[5]) * ((-(atan(x[2]) + asin(pow(x[7], (-1.819))))) + (1.167 * 0.3080 + (-1.735))) / x[3] * sin(x[8]) * (-0.1520) / pow(x[1], x[9]) / x[6];
    };
};

template<typename ADType>
struct FunctionSpec99 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        return ((atan(tan(4.965)) / pow(x[8], (-4.658)) + (x[6] - 2.880)) + pow(pow(log(3.769), (x[0] - (x[2] + tan((x[4] + x[9]))))), ((-2.929) - sin(x[3])) / pow(x[1], atan(x[7]) / x[5])));
    };
};

template<typename ADType>
struct FunctionSpec100 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        ADType tmp0 = ((cos(x[2]) - (x[1] / (-3.018) - (-log(3.351))) / x[7] / 3.550) * x[5] * pow(acos(cos(x[9])), x[0]) * x[8] / (-3.841) * (asin(sin(x[3])) + sin(x[4])) + cos(x[6]) / (-3.786));
        ADType tmp1 = (tan(cos(x[9])) / atan(x[7] / atan(0.1550)) / atan(4.942) * x[6] / tan(cos(x[1])) * (cos((x[5] - x[3])) - (-0.02700)) - pow(x[8], 0.4710 / (x[2] + (-0.1720) * (x[4] - x[0]))));
        ADType tmp2 = (exp(x[0]) / (tan(tan((-x[5]))) + (-0.1650)) * (x[4] + 0.1510) - ((((x[3] + (x[1] + tan(0.9400))) - x[8] / (-x[7])) + (-x[9]) * x[6] / sin(2.782)) + ((-0.1380) + x[2])));
        ADType tmp3 = ((x[1] - (atan(x[8]) - x[9])) / (-4.826) / x[7] / (x[0] / tan((-x[4])) / x[6] + 2.033) - (x[2] + acos(exp(x[3])) * (-0.5010)) / (x[5] - (sqrt(3.731) - (-2.549))));
        ADType tmp4 = ((((-0.8420) - sqrt(x[8])) + (-x[2])) / x[0] * pow(exp(x[1]), x[3]) - (sin(sqrt(2.061)) * ((x[6] - log(x[7])) / (1.104 + (exp(2.422) + x[9])) - x[4]) - (-(x[5] + 1.757))));
        return ((atan(tan(3.901)) * atan(sin(3.232)) - ((x[6] - tmp0) - (((tan(x[9]) + x[1]) + x[7] / x[0]) + sin(x[4])))) + tmp2 / (x[3] - tmp3 * (x[5] * x[8] * exp(1.666) + pow(atan(0.09400) * tmp4, x[2] * (-3.505) / atan(tmp1)))));
    };
};

template<typename ADType>
struct FunctionSpec101 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        ADType tmp0 = (x[6] + pow((x[2] + (-3.233)) * x[3], ((x[7] - exp(4.075) / (x[8] - x[4])) + 3.807 * (-sin(sqrt(x[1])))))) / ((-4.801) - x[9] * (x[0] + atan(((-4.363) - x[5]))));
        ADType tmp1 = (((-2.744) - (x[2] * (-x[3]) + sqrt(sin((-3.808))))) + pow(acos(tan(x[6])), x[0] * (-(x[5] * 2.781 + (-0.8950)) * (-0.8400))) / (x[9] - (pow(x[7], x[1]) + (x[4] - atan(x[8])))));
        ADType tmp2 = (pow(sin(sqrt(x[1])), (x[7] + (atan(x[0]) - ((-4.544) / x[6] - 4.812)))) - ((x[4] + ((exp(cos(x[9])) - (-x[3])) - ((-3.412) + (x[8] - x[5])))) + (-3.759) * atan(atan(2.481)))) / x[2];
        ADType tmp3 = ((((tan(x[9]) - x[6]) - log(3.659)) - (atan(0.8150) / pow(exp((-exp(x[2]))), pow((2.232 - x[7]), x[3]) / x[8] / x[5]) + 4.801)) + (-x[1]) / x[4] / (tan(x[0]) - 0.3560));
        ADType tmp4 = (((-4.053) / (-tan((-2.166))) * pow(x[9], atan(sqrt((log(x[5]) + 3.588)))) + x[4]) / (x[6] + (-1.268)) / x[1] + (x[0] / x[3] + exp(x[8]) / x[7] / x[2] * (-1.897)));
        return (((((tmp4 + (-2.382)) + (x[4] + exp((-3.525))) * x[1] / sin(tan(x[3])) * 4.502 * x[9] * x[7] / x[6] / tmp0) + x[2]) - tmp1 * tmp2) + log(x[5]) * x[0] * tmp3 * x[8] * (-3.758) * (-(-1.596)));
    };
};

template<typename ADType>
struct FunctionSpec102 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        ADType tmp0 = ((2.159 / (-tan(3.006)) * exp(x[5]) * (x[6] / x[4] - x[3]) - log((x[7] - 0.6740)) * exp(x[9]) * (-0.5620)) - pow(x[1] * 3.589, x[2] / x[8] * x[0]));
        ADType tmp1 = ((-1.409) + (sqrt(atan(x[8])) * (pow((-x[6]), ((0.6130 - 3.265) - x[3])) - x[7]) - (x[1] / x[9] / exp(x[0]) - exp(exp((((x[5] - (x[2] + 3.751)) - x[4]) + atan((-0.8050))))))));
        ADType tmp2 = (x[9] + (x[6] - exp(2.441)) * (-1.150) * (((x[3] - x[8]) + cos(log(x[7]))) + cos(4.829))) * x[2] / log(log(x[0])) / log(0.3150) * x[1] * x[4] * x[5] / tan(3.859);
        ADType tmp3 = pow((exp(x[8]) - (pow((x[5] + atan((x[4] - (-3.660)))), sin((-0.4650))) - x[7])) / pow(cos(x[0]) / x[2], pow(sqrt(x[1]), sin(3.493))), (x[3] - (x[6] + x[9]) * sin((-2.702)) / cos(1.649)));
        ADType tmp4 = (cos(3.204) / x[6] / x[8] - sin(cos(4.747 * tan(1.808))) * x[2]) * ((sin(x[5]) + x[3]) * ((x[7] - x[0]) - log(atan(x[9]))) - cos(2.148)) * (atan(x[1]) * x[4] + (-3.506));
        return ((tan(x[9]) - (x[4] - sqrt(tan((-2.285))) / (-tmp3) * (-2.097) / atan((-1.374)) * (cos(log(1.473)) + (tmp1 - x[3])) * (-2.745) * tmp2)) + pow(x[2] / log(x[7]) * x[8] * x[6], tmp0 / (((-x[0]) + tmp4) + x[1] / x[5])));
    };
};

template<typename ADType>
struct FunctionSpec103 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        ADType tmp0 = (x[1] - (((-0.8080) / x[3] * sqrt(x[7]) - atan((-2.002))) - (-x[0]) * x[5]) / ((4.194 / x[8] - x[9] * (-x[4])) - (-1.886)) / (((-x[2]) + atan(x[6])) - atan((-2.818))));
        ADType tmp1 = atan(log(exp((-x[7])))) * sin(1.632) / pow(x[8], x[3]) * (x[0] / pow(x[9], x[6]) * (log(((3.656 + 2.634) * 1.531 + (cos(x[4]) - (-3.984)))) + tan(x[1])) - x[5] / (-x[2]));
        ADType tmp2 = atan(x[8]) * cos(x[3]) / pow((x[7] - sin(x[5] / (-0.9200))), atan(x[6]) / sqrt(exp(pow((-4.750) * (-3.575), x[2])) / cos(x[4]))) / ((log(exp(pow(0.1170, pow(x[0], 1.916)))) + x[9]) + (-x[1]));
        ADType tmp3 = (((x[0] + pow(2.752, (-4.298))) / cos(atan(x[9])) * (x[2] - atan(sin(3.200)) * atan(x[4])) - (4.721 - sqrt(x[5]) * x[3] / sin(x[1]))) / (log(x[7]) + (-0.6630)) - (x[6] + atan(log(x[8]))));
        ADType tmp4 = (((-0.3120) + x[0]) + ((-(-x[8])) * ((-4.289) + (-4.359)) + cos(x[9] / 4.917)) * (x[2] - x[3]) / exp((-1.086)) * (x[6] * x[5] - (tan(x[7]) + x[1])) / x[4]);
        return ((acos(sin(tmp2)) + ((-3.359) * x[0] + tmp1)) - (sqrt(x[9]) - x[6]) / x[8] / 3.272 / x[4] * atan(x[3]) * pow(atan((log(tmp4) - x[2])), (tmp3 - 3.596)) / x[1] * (x[7] * sin((2.410 - tmp0)) + (-3.937)) * sin(x[5]));
    };
};

template<typename ADType>
struct FunctionSpec104 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        ADType tmp0 = (((x[8] / (-1.588) + x[7]) / (atan(x[3]) - (atan(x[1] / (-0.5230)) + (-1.892) * x[4]) / log(x[5])) * (tan((x[0] - (-0.9830))) - x[6]) + x[2]) - (atan((-2.673)) + (-x[9])));
        ADType tmp1 = (x[2] * x[8] - (1.873 + x[7])) * pow(((acos((-0.6310)) + exp(x[1])) / cos(exp(x[5])) - (atan(x[4]) + x[3]) / (tan(0.4040) + log(sin(2.164)))), (x[6] * x[0] + x[9] * (-0.04200)));
        ADType tmp2 = (((-4.043) / cos((-x[9]) * x[2]) - tan(cos(x[1]))) * (x[7] + ((-0.5910 / (-(-3.845))) + exp(sqrt(x[0])))) / x[8] / exp((-4.073)) - x[6] / x[3] / (1.706 - cos(x[4])) * x[5]);
        ADType tmp3 = ((x[1] / 4.127 - (x[7] + x[8])) - (x[3] - x[2])) / (pow(0.6030, 3.283) - atan(sqrt(x[0]))) * (tan(x[5]) + x[6] * atan((-0.1760)) / ((-4.103) - cos(cos(x[4])) / exp(x[9])));
        ADType tmp4 = pow((2.026 / (pow(x[9], 4.811) + pow(sqrt((-x[4])), acos(0.2110 / atan(x[3])))) + tan(pow(pow(x[2] * (-0.5150), x[5]), x[1]) * 3.748 / x[7] / x[8])), ((-x[0]) - atan(x[6])));
        return ((sqrt(tmp4) + pow(pow(x[7], (x[8] + (exp(sqrt(tmp0)) - pow(0.6950, x[0])))), ((x[5] + tmp2) - 1.410 * x[1]))) + (exp(tmp3) + tmp1 / x[2] / (exp((-3.859)) - (atan(x[6]) + (-3.749))))) * (x[3] / (-2.982) - x[4] / x[9]);
    };
};

template<typename ADType>
struct FunctionSpec105 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        ADType tmp0 = pow(((x[0] / 3.429 + x[1]) - acos(cos(sin((x[5] - x[4]))))), x[2]) * (3.803 / x[6] + (-pow(x[8], x[7]))) * pow(sqrt(atan(acos((-0.4930))) / log(x[9])) * x[3] * (-2.647), 2.658);
        ADType tmp1 = (x[8] + (cos(3.966) - sin(x[2]) / tan((-1.397)) / (-x[6]))) / x[5] * (x[1] - (-3.716)) * x[9] * (-1.594) * (x[3] - 3.037) / (tan((-x[4])) - (x[0] + cos(x[7])));
        ADType tmp2 = ((sin(x[9]) * ((x[7] * sin(x[2]) + x[5] * x[0]) + x[1]) + exp((-0.5500)) * (-3.708) / exp(3.243 * tan(tan((-x[6]))))) + pow(((-0.5460) - (-3.183)), atan((x[3] + x[8]) / x[4])));
        ADType tmp3 = pow((((atan(x[9] * x[8]) + x[7] / x[4] * log(x[0])) + ((3.141 - (-1.194)) + cos(((x[6] + (-1.220)) - (-1.964))))) - (-4.673)), pow((cos(tan(x[3])) - x[2] / sin(x[5])), atan(tan(x[1]))));
        ADType tmp4 = ((x[0] * (-0.8100) - x[4]) - x[8]) / (pow(pow(pow(sqrt(x[5]), pow(2.565, x[7])), x[2] / x[3]), atan(cos(1.718))) + ((tan(atan(x[6] * (-4.933))) + ((-0.8650) + sqrt(x[9]))) - x[1]));
        return pow((x[3] + x[0]), (x[2] * 3.041 - (tmp4 + atan(x[4])))) * ((0.04500 * tmp3 + tmp2 / x[1] * sin(x[6])) + pow((-1.937) / tmp1, (log(log(tmp0 * (-0.6090))) - asin(cos(log(x[7])))))) * pow(x[5], (tan(x[8]) - x[9])) * (-4.026);
    };
};

template<typename ADType>
struct FunctionSpec106 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        ADType tmp0 = 2.754 * ((-3.529) * x[0] - exp(x[3]) * tan(x[1])) / x[7] / (((atan(cos(x[6])) + (acos(x[4] / (-2.398)) + sin(x[9]))) - ((cos(x[5]) + x[2]) + (-0.1830) / 4.150)) - x[8]);
        ADType tmp1 = (((atan((-3.845)) - (-1.960)) - x[5]) - pow((pow(atan(exp(sqrt(4.080))), (x[2] - tan(x[7]))) + pow(x[0], (-1.661))) / (x[9] + x[6]) / (-2.039) * (-x[1]), pow(log(log(x[8])), sin(x[3]) / x[4])));
        ADType tmp2 = pow((-2.229) / (-3.135) / exp(x[6]) * pow(tan(x[3]) / (x[9] + (-3.903)), cos((-(-1.951)))), (((x[4] + sqrt(x[5])) + (asin(cos(x[1])) - sqrt(3.659))) - x[0])) * pow(x[8] * atan(x[7]), x[2]);
        ADType tmp3 = ((pow(x[9], x[0]) - (-1.055) / (-0.9660) / sqrt(sin(tan(1.795)))) + (sin(x[1]) - cos(pow(x[8], x[7])))) * (((1.192 - (x[4] + x[2])) - 0.7080 * x[6]) + tan(cos(x[3]))) * x[5];
        ADType tmp4 = ((sqrt(exp(x[0])) / sin(x[9] / 2.535) - sin(3.518)) * 3.997 * tan(x[2]) / x[1] - (x[6] + ((x[7] + 4.403) - ((-1.419) + x[3])))) / (sqrt(x[5]) - x[8]) * x[4];
        return ((pow(((-3.270) - x[4] * x[8] / exp(x[9])) / sin(x[5]) / pow(x[7], tmp1) * log((exp(x[6]) + tmp2)) / x[1], tan(x[3])) + sqrt((-3.667) * (-4.027))) + tmp0 / cos(tan(x[0])) * 1.524 * tmp4 / x[2] / ((-4.984) + tmp3));
    };
};

template<typename ADType>
struct FunctionSpec107 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        ADType tmp0 = (x[0] + pow((tan(0.06200) + (-2.043)) * atan(x[2]), (x[8] - pow(((x[9] + 2.289) + (tan(3.504) + x[7])) * (x[5] - x[3]), tan(x[6] / 3.785) * tan((x[1] + x[4]))))));
        ADType tmp1 = (((-x[5]) / x[2] * (-2.483) / x[9] * pow(x[7], sin(x[0])) - 1.691 * (-1.190) * pow(pow(sin(cos((-1.450))), x[6]), x[3])) - ((x[4] - x[1]) - 4.856) / tan(x[8]));
        ADType tmp2 = x[3] * (pow(cos((sin(x[1]) + (((-1.430) - x[5]) - x[0]))), sin(x[2])) - (log(x[8] / x[9]) / x[7] - sin((-4.428)) * (-1.381) * (-4.023)) * (((-1.007) - x[4]) - x[6]));
        ADType tmp3 = (sqrt(x[0]) / (-0.9720) / (-2.668) + ((-3.810) + (x[4] - (x[5] - exp(log(sqrt(x[9])))))) * (x[7] - (x[6] + exp(x[8]) * (exp((-2.066)) - (exp(2.623) - x[2])) / (x[1] + x[3]))));
        ADType tmp4 = (pow(pow(pow((x[3] + tan(4.535)), sin(sqrt(pow(1.944, 1.967)))) / pow((sin(x[5]) / (x[9] - 0.9650) + pow(x[8], (-2.597))), (-x[0])), x[2]), x[7]) + ((x[4] + tan(x[6])) + (-x[1])));
        return (x[8] * ((-3.317) - (exp(x[1]) - exp((-0.3280)))) + (tmp2 + (x[4] * ((x[7] / tmp1 - (x[2] + x[3])) + atan(3.842)) * ((x[9] / log(4.809) - (exp(tmp0) - (tmp4 - x[0]))) - (exp(tan(x[6])) - exp((-2.604)))) - (tmp3 + x[5]))));
    };
};

template<typename ADType>
struct FunctionSpec108 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        ADType tmp0 = ((x[7] * (x[4] + x[6]) - cos(4.308) / x[2]) + x[1] * (x[0] / atan((-4.985)) - x[8])) * ((atan(atan((1.684 + asin(0.8650)))) + (x[3] - sin(x[9]))) - 0.3750 / (-x[5]));
        ADType tmp1 = ((x[0] + 3.994) / x[7] * (exp(x[2]) - x[3] / asin(exp((-2.905)))) - pow(pow(3.222, (-2.431)), pow(atan(1.785), exp(x[9]))) / ((atan((x[4] - (x[8] + cos(x[6])))) - exp(x[5])) + atan(x[1])));
        ADType tmp2 = pow((-x[3]), ((sin(x[1]) - (-0.8740)) - (-4.383) / x[9]) * (((-0.01000) - (pow(log(3.091), (x[6] + atan(1.009))) - exp(x[4] * x[7]))) / sqrt(exp(x[8])) - pow(log((x[0] - x[5])), x[2])));
        ADType tmp3 = pow(pow((((-4.816) + pow(exp(2.000), x[3])) * x[0] / (tan(x[2]) - (-3.856)) - (-x[6]) / 1.817 * (-0.9840) * ((sin(sin(x[8])) + x[9]) + tan(exp(sqrt(x[1]))))), x[4]), tan(x[7]) / x[5]);
        ADType tmp4 = ((x[4] - 4.425) / (tan(((-3.899) + x[3])) * pow(sin(atan(x[1])), x[9]) / x[2] * x[0] / (x[6] + (-2.216)) + sqrt(x[7])) + (exp(x[5]) - (x[8] - pow(4.243, (-1.745)))));
        return ((((cos(x[9]) - tmp2 / x[6]) + x[8] / x[7]) / ((-3.269) + pow(tmp3, (-3.999) * (sqrt(0.07800) - log(0.1140)))) - x[4]) - ((atan(tmp1) + x[2]) - (((x[5] * tmp0 + 0.1680 * x[0]) + tmp4) - sin(x[3]) * x[1])));
    };
};

template<typename ADType>
struct FunctionSpec109 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        ADType tmp0 = pow((sqrt(x[1]) + (-1.148)), (x[7] + x[3]) * log(((4.844 + x[9]) + (-3.224)))) * exp(x[8]) / (x[5] - sin((-x[0]))) / ((-(-2.574)) + exp(x[4])) * (cos(x[6]) + ((-2.570) + x[2]));
        ADType tmp1 = pow((log((log(cos(x[1]) / x[3]) + atan(x[2] / x[6]) * 0.5720)) / (-(-1.900)) - ((-4.769) - tan((-1.908)) * atan(cos(log((x[7] - x[5] / 1.140))) / x[9]))), (x[8] + atan(x[0]) / x[4]));
        ADType tmp2 = (((-1.831) * atan(x[0]) * x[8] / tan((-exp((-2.422)))) + cos(3.818)) / (x[2] + x[4] * (-3.895) / x[6] * x[5]) * ((log(x[1]) - (atan(x[9]) + sin(x[7]))) + (-(-4.407))) - x[3]);
        ADType tmp3 = pow(3.967 * ((-2.161) + x[0]) * pow((x[7] - tan(cos(x[9]))), pow(x[8], x[6])) * sqrt(sqrt(x[1])), x[2] / x[4] * 4.694 / ((-0.6120) + atan(x[3])) / cos(sqrt(x[5])) / exp(sqrt(0.1200)));
        ADType tmp4 = (pow(x[1], (-3.908)) - (exp(exp((x[6] + x[7]))) - (atan((-2.544)) + 4.888) * sqrt(x[9]) * pow((0.3400 - x[3]), tan(x[8]))) * (x[2] + (sin(sin(x[4])) - x[0]) / (x[5] - (-3.196))));
        return (tmp4 * pow((atan(x[4]) - (x[7] + (tmp0 - x[8]))), x[3]) + pow(((-4.839) * (asin(tmp3) + atan((atan(4.029) - x[6]))) + (x[0] / x[1] - (tmp2 + atan(2.009) / x[5] / tmp1 / log(tan(((0.6590 - x[9]) - x[2])))))), sqrt(0.6950)));
    };
};

template<typename ADType>
struct FunctionSpec110 : FunctionBase<ADType> {
    ADType TestFunction(const ADType(&x)[DataInSize]) {
        ADType tmp0 = (-0.6230);
        ADType tmp1 = x[7];
        ADType tmp2 = x[0];
        ADType tmp3 = x[1];
        ADType tmp4 = x[5];
        for(int i = 0; i < LoopIterations; i++){
            tmp0 = (pow((pow(sqrt(atan(tmp3)), atan(x[8])) + x[7]), atan((x[6] + (-1.438)))) + atan(tmp1) / (-2.047)) / pow((exp(x[0] / (-tmp2)) - x[3]), pow((-4.251) / (x[4] + tan(tmp0)), (((x[1] * x[2] + exp(x[5])) - (x[9] - tmp4)) + ((-4.691) - 0.2220))));
            tmp1 = ((sqrt(x[9]) + sqrt(log(x[5]))) - (pow(tmp3 * x[1], tmp2 / (-4.996)) * tmp0 + x[3] * x[6]) / (tmp1 - (tmp4 / (0.1470 + exp(x[7]) / ((-3.145) - (-(-4.179)))) / sqrt(pow(x[0], x[8])) - x[2] * x[4] * (-1.453))));
            tmp2 = (((-3.081) / tmp1 - x[8] / (-2.409)) * pow((tmp2 - (-(-0.8490))), pow(sqrt(tmp4), tan(tmp3))) + pow((pow(atan(x[0]), x[3]) + sin((-pow(x[9], x[1])))), tmp0)) * (x[2] - (2.253 - x[5])) / atan((x[7] - 2.942)) * x[6] * tan(x[4]);
            tmp3 = pow((exp(tan((-2.020))) * exp(x[5]) * cos(tmp2) / (x[2] - x[7]) + (3.387 - (-1.376))) / x[1] / x[3], x[6] / tmp0 / pow(((tmp3 * 1.231 * x[0] - cos(tmp4)) + (pow(1.743, x[8] * x[4]) - x[9])), sin(log(tmp1))));
            tmp4 = (pow((tan(x[1]) - (tmp2 - (-1.850))) / x[7] * 4.629 * (-0.8210) / 4.705, (tmp0 + x[2])) + pow((tmp3 + tmp4), cos(sin(x[4]))) * pow(pow(pow(pow(sqrt(x[0]), x[5]), cos(x[6])), pow((-((-x[9]) + (-0.8670))), (x[3] + tmp1))), x[8]));
        }
        return ((log(tmp3) - pow(pow(x[5], x[7]), cos(acos(tmp0))) / pow(x[0], pow((x[3] + 3.372), x[2] / sqrt(x[9]))) / atan(x[4])) / (pow(((-1.712) * x[1] + (-2.784)) / 2.191 * (-2.847), (tmp1 + tmp4)) - (-x[8])) + tmp2) * x[6];
    };
};

template<typename ADType>
void Initialize(FunctionBase<ADType>* testArray[TotalTestCases]) {
    testArray[0] = new FunctionSpec0<ADType>();
    testArray[1] = new FunctionSpec1<ADType>();
    testArray[2] = new FunctionSpec2<ADType>();
    testArray[3] = new FunctionSpec3<ADType>();
    testArray[4] = new FunctionSpec4<ADType>();
    testArray[5] = new FunctionSpec5<ADType>();
    testArray[6] = new FunctionSpec6<ADType>();
    testArray[7] = new FunctionSpec7<ADType>();
    testArray[8] = new FunctionSpec8<ADType>();
    testArray[9] = new FunctionSpec9<ADType>();
    testArray[10] = new FunctionSpec10<ADType>();
    testArray[11] = new FunctionSpec11<ADType>();
    testArray[12] = new FunctionSpec12<ADType>();
    testArray[13] = new FunctionSpec13<ADType>();
    testArray[14] = new FunctionSpec14<ADType>();
    testArray[15] = new FunctionSpec15<ADType>();
    testArray[16] = new FunctionSpec16<ADType>();
    testArray[17] = new FunctionSpec17<ADType>();
    testArray[18] = new FunctionSpec18<ADType>();
    testArray[19] = new FunctionSpec19<ADType>();
    testArray[20] = new FunctionSpec20<ADType>();
    testArray[21] = new FunctionSpec21<ADType>();
    testArray[22] = new FunctionSpec22<ADType>();
    testArray[23] = new FunctionSpec23<ADType>();
    testArray[24] = new FunctionSpec24<ADType>();
    testArray[25] = new FunctionSpec25<ADType>();
    testArray[26] = new FunctionSpec26<ADType>();
    testArray[27] = new FunctionSpec27<ADType>();
    testArray[28] = new FunctionSpec28<ADType>();
    testArray[29] = new FunctionSpec29<ADType>();
    testArray[30] = new FunctionSpec30<ADType>();
    testArray[31] = new FunctionSpec31<ADType>();
    testArray[32] = new FunctionSpec32<ADType>();
    testArray[33] = new FunctionSpec33<ADType>();
    testArray[34] = new FunctionSpec34<ADType>();
    testArray[35] = new FunctionSpec35<ADType>();
    testArray[36] = new FunctionSpec36<ADType>();
    testArray[37] = new FunctionSpec37<ADType>();
    testArray[38] = new FunctionSpec38<ADType>();
    testArray[39] = new FunctionSpec39<ADType>();
    testArray[40] = new FunctionSpec40<ADType>();
    testArray[41] = new FunctionSpec41<ADType>();
    testArray[42] = new FunctionSpec42<ADType>();
    testArray[43] = new FunctionSpec43<ADType>();
    testArray[44] = new FunctionSpec44<ADType>();
    testArray[45] = new FunctionSpec45<ADType>();
    testArray[46] = new FunctionSpec46<ADType>();
    testArray[47] = new FunctionSpec47<ADType>();
    testArray[48] = new FunctionSpec48<ADType>();
    testArray[49] = new FunctionSpec49<ADType>();
    testArray[50] = new FunctionSpec50<ADType>();
    testArray[51] = new FunctionSpec51<ADType>();
    testArray[52] = new FunctionSpec52<ADType>();
    testArray[53] = new FunctionSpec53<ADType>();
    testArray[54] = new FunctionSpec54<ADType>();
    testArray[55] = new FunctionSpec55<ADType>();
    testArray[56] = new FunctionSpec56<ADType>();
    testArray[57] = new FunctionSpec57<ADType>();
    testArray[58] = new FunctionSpec58<ADType>();
    testArray[59] = new FunctionSpec59<ADType>();
    testArray[60] = new FunctionSpec60<ADType>();
    testArray[61] = new FunctionSpec61<ADType>();
    testArray[62] = new FunctionSpec62<ADType>();
    testArray[63] = new FunctionSpec63<ADType>();
    testArray[64] = new FunctionSpec64<ADType>();
    testArray[65] = new FunctionSpec65<ADType>();
    testArray[66] = new FunctionSpec66<ADType>();
    testArray[67] = new FunctionSpec67<ADType>();
    testArray[68] = new FunctionSpec68<ADType>();
    testArray[69] = new FunctionSpec69<ADType>();
    testArray[70] = new FunctionSpec70<ADType>();
    testArray[71] = new FunctionSpec71<ADType>();
    testArray[72] = new FunctionSpec72<ADType>();
    testArray[73] = new FunctionSpec73<ADType>();
    testArray[74] = new FunctionSpec74<ADType>();
    testArray[75] = new FunctionSpec75<ADType>();
    testArray[76] = new FunctionSpec76<ADType>();
    testArray[77] = new FunctionSpec77<ADType>();
    testArray[78] = new FunctionSpec78<ADType>();
    testArray[79] = new FunctionSpec79<ADType>();
    testArray[80] = new FunctionSpec80<ADType>();
    testArray[81] = new FunctionSpec81<ADType>();
    testArray[82] = new FunctionSpec82<ADType>();
    testArray[83] = new FunctionSpec83<ADType>();
    testArray[84] = new FunctionSpec84<ADType>();
    testArray[85] = new FunctionSpec85<ADType>();
    testArray[86] = new FunctionSpec86<ADType>();
    testArray[87] = new FunctionSpec87<ADType>();
    testArray[88] = new FunctionSpec88<ADType>();
    testArray[89] = new FunctionSpec89<ADType>();
    testArray[90] = new FunctionSpec90<ADType>();
    testArray[91] = new FunctionSpec91<ADType>();
    testArray[92] = new FunctionSpec92<ADType>();
    testArray[93] = new FunctionSpec93<ADType>();
    testArray[94] = new FunctionSpec94<ADType>();
    testArray[95] = new FunctionSpec95<ADType>();
    testArray[96] = new FunctionSpec96<ADType>();
    testArray[97] = new FunctionSpec97<ADType>();
    testArray[98] = new FunctionSpec98<ADType>();
    testArray[99] = new FunctionSpec99<ADType>();
    testArray[100] = new FunctionSpec100<ADType>();
    testArray[101] = new FunctionSpec101<ADType>();
    testArray[102] = new FunctionSpec102<ADType>();
    testArray[103] = new FunctionSpec103<ADType>();
    testArray[104] = new FunctionSpec104<ADType>();
    testArray[105] = new FunctionSpec105<ADType>();
    testArray[106] = new FunctionSpec106<ADType>();
    testArray[107] = new FunctionSpec107<ADType>();
    testArray[108] = new FunctionSpec108<ADType>();
    testArray[109] = new FunctionSpec109<ADType>();
    testArray[110] = new FunctionSpec110<ADType>();
};

template<typename ADType>
void Finalize(FunctionBase<ADType>* testArray[TotalTestCases]) {
    for (int i = 0; i < TotalTestCases; i++)
        delete testArray[i]; 
};

#endif  // TESTFUNCTIONS_H
