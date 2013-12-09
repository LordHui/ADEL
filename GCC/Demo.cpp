#include "ADEL/ADEL.h"
#include <stdio.h>

const int Order = 2;                                                        //the order of differentiation
const int xCount = 2;                                                       //the number of input variables
typedef ADVariable<Order, xCount> ADReverse;                                //the shortname for the active datatype

template<typename T>                                                        //the template based test algorithm
T Algorithm(const T (&x)[xCount]) {                                         //
    return x[0] + sin(x[0])*x[1];                                           //
}


int main() {
    double x[xCount] = {1.0, 2.0};                                          //passive input variables are used for initialization and validation
    ADReverse adX[xCount];                                                  //active input variables that are used for differentiation
    for(int i = 0; i < xCount; i++) {                                       //initialization of active variables
        adX[i].Value = x[i];                                                //set the initial values
        adX[i].ID = i;                                                      //set the IDs, derivatives are obtained via those
        adX[i].Base = true;                                                 //mark the variable as Base(i.e. Independent)
    }

    ADReverse adY;                                                          //active output variable, no initialization required
    adY = Algorithm<ADReverse>(adX);                                        //the algorithm to be differentiated

    double y = Algorithm<double>(x);                                        //the passive version of the algorthm, used for the validation
    double dydx0 = 1.0 + cos(x[0])*x[1];                                    //hardcoded derivative of the algorithm above, used for the validation
    double dydx1 = sin(x[0]);                                               //
    double d2ydx0x0 = -sin(x[0])*x[1];                                      //
    double d2ydx0x1 = cos(x[0]);                                            //
    double d2ydx1x0 = cos(x[0]);                                            //
    double d2ydx1x1 = 0.0;                                                  //

    printf("y value expected: %f, received: %f\n", y, adY.Value);           //value validation
    double jacobian[xCount];                                                //an array do store the first order derivatives (jacobian)
    for(int i = 0; i < xCount; i++) {                                       //retrivement of the the jacobian
        jacobian[i] = adY.Data[i];                                          //
    }
    printf("dy/dx0 expected: %f, received: %f\n", dydx0, jacobian[0]);      //jacobian validation
    printf("dy/dx1 expected: %f, received: %f\n", dydx1, jacobian[1]);      //

    double hessian[xCount*xCount];                                          //an array do store the second order derivatives (hessian)
    for(int i = 0; i < xCount; i++) {                                       //retrivement of the the hessian
        for(int j = 0; j < xCount; j++) {                                   //
            hessian[i*xCount + j] = adY.Data[xCount + i*xCount + j];        //
        }
    }
    printf("d2ydx0x0 expected: %f, received: %f\n", d2ydx0x0, hessian[0]);  //hessian validation
    printf("d2ydx0x1 expected: %f, received: %f\n", d2ydx0x1, hessian[1]);  //
    printf("d2ydx1x0 expected: %f, received: %f\n", d2ydx1x0, hessian[2]);  //
    printf("d2ydx1x1 expected: %f, received: %f\n", d2ydx1x1, hessian[3]);  //
}
