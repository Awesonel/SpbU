#include <stdio.h>
#include <stdlib.h>
#include "modPower.h"
#include "symbolLegendre.h"

int symbolLegendreByEulersCriterion(const long long int numerator, const long int denominator)
{
    if (numerator % denominator == 0) return 0;
    if (moduloPowerRecursive(numerator, (denominator - 1)/2, denominator) == 1) return 1;
    return -1;
}

int BANsymbolLegendreByTheLawOfQuadraticReciprocityBAN(int numerator, int denominator)
{
    int result = 1;

    if (numerator % denominator == 0) return 0;

    while ((numerator > 1) && (denominator > 1))
    {
        numerator %= denominator;

        while ((numerator & 1) == 0)
        {
            numerator >>= 1;
            if (((denominator & 7) == 3) || ((denominator & 7) == 5)) result *= -1;
        }


        numerator += denominator;
        denominator = numerator - denominator;
        numerator -= denominator;

        if ((denominator & 3 == 3) && (numerator & 3 == 3)) result *= -1;

    }
    return result;
}

void testSymbolLegendreCalculation()
{
    int numerator, denominator, start, stop;
    printf("enter a numerator of symbol - ");
    scanf("%d", &numerator);
    printf("enter a denominator of symbol - ");
    scanf("%d", &denominator);

    printf("Result of Euler's Criterion algorithm: %d\n", symbolLegendreByEulersCriterion(numerator, denominator));

    printf("Result of the law of quadratic reciprocity algorithm: %d\n", symbolLegendreByTheLawOfQuadraticReciprocity(numerator, denominator));
}

int symbolLegendreByTheLawOfQuadraticReciprocity(int numerator, int denominator)
{
    int degree = 1;

    if (numerator % denominator == 0) return 0;

    while ((numerator > 1) && (denominator > 1))
    {
        numerator %= denominator;

        while ((numerator & 1) == 0)
        {
            numerator >>= 1;
            if (((denominator & 7) == 3) || ((denominator & 7) == 5)) degree *= -1;
        }


        numerator += denominator;
        denominator = numerator - denominator;
        numerator -= denominator;

        if ((((numerator - 1)*(denominator - 1) >> 2) & 1 ) == 1) degree *= -1;

    }
    return degree;
}
