#include <stdio.h>
#include <stdlib.h>
#include "euclidStd.h"
#include "modPower.h"
#include "euclidExt.h"
#include "chineseReminder.h"
#include "diophantineLinearEquation.h"
#include "symbolLegendre.h"
#include <time.h>
#include "square.h"

int main()
{
    long int tests[6][4] = {
        {13, 43, 20, 23},
        {53, 13, 1, 12},
        {23, 43, 18, 25},
        {83, 47, 6, 41},
        {43, 53, 19, 34},
        {23, 83, 40, 43}};
    //[residue, module, answer1, answer2]


    for (int i = 0; i < 6; i++)
    {
        int result = quadratic_comparison(tests[i][0], tests[i][1]);
        if ((result == tests[i][2]) || (result == tests[i][3])) printf("True\n");
        else printf("False\n");
    }
	return 0;
}

/*
long int a, p;
	printf("a = ");
	scanf("%d", &a);
	printf("p = ");
	scanf("%d", &p);
	printf("%d\n", symbolLegendreByTheLawOfQuadraticReciprocity(a, p));
	printf("x = %d", quadratic_comparison(a, p)); */

