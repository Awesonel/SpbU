#include <stdio.h>
#include <stdlib.h>
#include "euclidExt.h"
#include "euclidStd.h"
#include "chineseReminder.h"

int chineseReminderUsingInverse(int numberOfEquations, const int* residue, const int* module)
{
    for (int i = 0; i < numberOfEquations; i++)
    {
        for (int j = i+1; j < numberOfEquations; j++)
        {
            if (euclidStandard(module[i], module[j]) != 1) return -1;
        }
    }

    int productOfModules = 1;
    for (int i = 0; i < numberOfEquations; i++) productOfModules *= module[i];

    int solution = 0;

    for (int i = 0; i < numberOfEquations; i++)
    {
        int temp = productOfModules / module[i];
        int inverseToTemp = moduloInverse(temp, module[i]);
        solution += temp * inverseToTemp * residue[i];
    }

    return (solution % productOfModules);
}

int chineseReminderUsingMainEquation(int numberOfEquations, const int* residue, const int* module)
{
    for (int i = 0; i < numberOfEquations; i++)
    {
        for (int j = i+1; j < numberOfEquations; j++)
        {
            if (euclidStandard(module[i], module[j]) != 1) return -1;
        }
    }

    int moduleOfMainEquation = module[0], residueOfMainEquation = residue[0]; // "Главные" модуль и остаток

    for (int i = 1; i < numberOfEquations; i++)
    {
        int firstCoefficient, secondCoefficient;
        euclidExtended(moduleOfMainEquation, module[i], &firstCoefficient, &secondCoefficient);
        residueOfMainEquation = residueOfMainEquation * secondCoefficient * module[i] + residue[i] * firstCoefficient * moduleOfMainEquation;
        moduleOfMainEquation *= module[i];
    }
    return (residueOfMainEquation % moduleOfMainEquation + moduleOfMainEquation)% moduleOfMainEquation;
}

void testChineseReminder()
{
    int numberOfEquations;
    printf("Number of equations: ");
    scanf("%d", &numberOfEquations);
    int residue[numberOfEquations], module[numberOfEquations];
    for (int i = 0; i < numberOfEquations; i++)
    {
        printf("%d residue - ", i+1);
        scanf("%d", &residue[i]);
        printf("%d module - ", i+1);
        scanf("%d", &module[i]);
    }
    printf("Result of the algorithm by finding inverse - %d\n", chineseReminderUsingInverse(numberOfEquations, residue, module));
    printf("Result of the algorithm by main equation - %d\n", chineseReminderUsingMainEquation(numberOfEquations, residue, module));
}
