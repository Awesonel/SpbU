#ifndef SYMBOLLEGENDRE_H_INCLUDED
#define SYMBOLLEGENDRE_H_INCLUDED

int symbolLegendreByEulersCriterion(const long long int numerator, const long int denominator);
int symbolLegendreByTheLawOfQuadraticReciprocity(int numerator, int denominator);

void testSymbolLegendreCalculation();

#endif // SYMBOLLEGENDRE_H_INCLUDED
