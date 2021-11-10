#include <stdio.h>
#include <stdlib.h>
#include "euclidExt.h"

int euclidExtended(int firstNumber, int secondNumber, int *firstCoefficient,int *secondCoefficient)
{
    int signBeforeMatrix = 1, matrix[4];

    // Если firstNumber или secondNumber - отрицательные - "переносим" этот минус в firstCoefficient или secondCoefficient
    if (firstNumber < 0)
    {
        firstNumber = -firstNumber;
        *firstCoefficient = -1;
    }
    else *firstCoefficient = 1;

    if (secondNumber < 0)
    {
        secondNumber = -secondNumber;
        *secondCoefficient = -1;
    }
    else *secondCoefficient = 1;


    matrix[0] = matrix[3] = 1;
    matrix[1] = matrix[2] = 0;

    while (secondNumber > 0)
    {
        signBeforeMatrix ++;
        int quotient =  firstNumber / secondNumber;
        int residue = firstNumber % secondNumber;
        firstNumber = secondNumber;
        secondNumber = residue;

        // Перемножение матриц
        int temp = matrix[0] * quotient + matrix[1];
        matrix[1] = matrix[0];
        matrix[0] = temp;
        temp = matrix[2] * quotient + matrix[3];
        matrix[3] = matrix[2];
        matrix[2] = temp;
    }

    signBeforeMatrix = (signBeforeMatrix & 1) ? -1 : 1;

    *firstCoefficient *= -matrix[3] * signBeforeMatrix;
    *secondCoefficient *= matrix[1] * signBeforeMatrix;

    return firstNumber;
}

void testEuclidExtended()
{
    int firstNumber, secondNumber, firstCoefficient, secondCoefficient;
    printf("Enter first and second numbers separated by a space: ");
    scanf("%d %d", &firstNumber, &secondNumber);
    printf("The greatest common divisor - %d\n", euclidExtended(firstNumber, secondNumber, &firstCoefficient, &secondCoefficient));
    printf("The coefficients before numbers - %d %d\n", firstCoefficient, secondCoefficient);
}

int moduloInverse(int number, int module)
{
    int firstCoefficient, secondCoefficient;
    int d = euclidExtended(number, module, &firstCoefficient, &secondCoefficient);
    return (d == 1) ? (firstCoefficient % module + module) % module : -1;
}

void testModuloInverse()
{
    int number, module;
    printf("insert number and module separated by a space: ");
    scanf("%d %d", &number, &module);
    printf("inverse number modulo %d - %d\n", module, moduloInverse(number, module));
}
