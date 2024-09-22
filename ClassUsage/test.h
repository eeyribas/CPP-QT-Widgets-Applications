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

    double sum_value = 0;
    double substract_value = 0;
    double multiple_value = 0;
    double divide_value = 0;
    double first_value = 0;
    double second_value = 0;
};

#endif // TEST_H
