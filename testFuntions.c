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
    int a, p;
	printf("a = ");
	scanf("%d", &a);
	printf("p = ");
	scanf("%d", &p);
	printf("%d\n", symbolLegendreByEulersCriterion(a, p));
	printf("x = %d", square_comparison(a, p));
	return 0;
}
