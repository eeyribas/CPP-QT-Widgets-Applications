#ifndef TEST_H
#define TEST_H

#include <math.h>

class Test
{
public:
    double SumCalc(double, double);
    double SubstractCalc(double, double);
    double MultipleCalc(double, double);
    double DivideCalc(double, double);

    double sum_value;
    double substract_value;
    double multiple_value;
    double divide_value;
    double first_value;
    double second_value;
};

#endif // TEST_H
