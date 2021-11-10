#include "square.h"
#include "modPower.h"
#include <math.h>
#include "symbolLegendre.h"

int power(int a, int b)
{
    int answer = 1;
    while (b > 0)
    {
        b--;
        answer *= a;
    }
    return answer;
}

long int quadratic_comparison(long int a, long int p)
{
    long int r, k = 0, c = 2, b = 1, h = p-1;

    while ((h & 1) == 0)
    {
        k++;
        h >>= 1;
    }


    while (symbolLegendreByTheLawOfQuadraticReciprocity(c, p) >= 0)
        c++;


    if (k == 1)
        r = k;
    else if (k >= 2)
        r = k - 1;
    else
        r = 0;


    while (r > 0)
    {
        for (int i = 0; i <= r; i++)
        {
            if ((moduloPowerRecursive(a, pow(2, i) * h, p) * moduloPowerRecursive(b, pow(2, i + 1), p)) == 1)
            {
                r = i;
                break;
            }
        }
        b *= moduloPowerRecursive(c, h * (pow(2, k - r - 1)), p);
        r--;
    }

    long int x = (moduloPowerRecursive(a, (h+1)/2, p) * b) % p;
    return x;
}
