#include <stdio.h>
#include <stdlib.h>
#include "euclidExt.h"
#include "diophantineLinearEquation.h"

int diophantineLinearEquationSolution(const int numberOfVariables, const int *coefficients, int freeElement, int *solution)
{
    int interimSolution[numberOfVariables], interimCoefficient[numberOfVariables-1], tempGreatestCommonDivisor = coefficients[0];
    interimSolution[0] = 1;

    for (int i = 1; i < numberOfVariables; i++)
    {
        tempGreatestCommonDivisor = euclidExtended(tempGreatestCommonDivisor, coefficients[i], &interimCoefficient[i-1], &interimSolution[i]);
    }

    if (freeElement % tempGreatestCommonDivisor == 0)
    {
        freeElement /= tempGreatestCommonDivisor;
        for (int i = 0; i < numberOfVariables; i++)
        {
            solution[i] = interimSolution[i] * freeElement;

            for (int j = i; j < numberOfVariables-1; j++)
            {
                solution[i] *= interimCoefficient[j];
            }
        }
        return 0;
    }
    else return -1;
}

void testDiophantineLinearEquationSolution()
{
    int numberOfVariables, freeElement;
    printf("Enter a number of variables: ");
    scanf("%d", &numberOfVariables);

    int coefficients[numberOfVariables], solution[numberOfVariables];
    for (int i = 0; i < numberOfVariables; i++)
    {
        printf("%d coefficient: ", i+1);
        scanf("%d", &coefficients[i]);
    }
    printf("Enter a free element: ");
    scanf("%d", &freeElement);

    int resultOfAlgorithm = diophantineLinearEquationSolution(numberOfVariables, coefficients, freeElement, solution);
    printf("Result of algorithm (0 if there is a solution and -1 if not): %d\n", resultOfAlgorithm);
    if (resultOfAlgorithm == 0)
    {
        printf("There are solutions: ");
        for (int i = 0; i < numberOfVariables; i++)
        {
            printf("%d ", solution[i]);
        }
    }
    printf("/n");
}
