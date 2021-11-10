#include <stdio.h>
#include <stdlib.h>
#include "euclidStd.h"

int euclidStandard(int firstNumber, int secondNumber)
{
    if (secondNumber) return euclidStandard(secondNumber, firstNumber % secondNumber);
    else return firstNumber;
}

int euclidBinary(int firstNumber, int secondNumber)
{
    int countOfTwos=0;
    while ((firstNumber&1)==0 && (secondNumber&1)==0)
    {
        ++countOfTwos;
        firstNumber >>= 1;
        secondNumber >>= 1;
    }
    while (firstNumber!=0 && secondNumber!=0)
    {
        if ((firstNumber&1)==0)
            firstNumber >>= 1;
        if ((secondNumber&1)==0)
            secondNumber >>= 1;
        if (firstNumber > secondNumber)
            firstNumber = (firstNumber-secondNumber) >> 1;
        else
            secondNumber = (secondNumber-firstNumber) >> 1;

    }
    return firstNumber<<countOfTwos;
}

void testEuclidStandard()
{
    int firstNumber, secondNumber;
    printf("Enter first and second numbers separated by a space: ");
    scanf("%d %d", &firstNumber, &secondNumber);
    printf("Result of a standard Euclid - %d", euclidStandard(firstNumber,secondNumber));
}

void testEuclidBinary()
{
    int firstNumber, secondNumber;
    printf("Enter first and second numbers separated by a space: ");
    scanf("%d %d", &firstNumber, &secondNumber);
    printf("Result of a binary Euclid - %d", euclidBinary(firstNumber,secondNumber));
}
