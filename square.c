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

long int square_comparison(long int a, long int p)
{
    long int k = 0, c = 2, b = 1, _p = p-1;

    while ((_p & 1) == 0)
    {
        k++;
        _p >>= 1;
    }

    while (legendre_euclidian(c, p) >= 1)
        c++;

    long r, h = _p;
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
            if ((mod_pow(a, pow(2, i) * h, p) * mod_pow(b, pow(2, i + 1), p)) == 1)
            {
                r = i;
                break;
            }
        }
        b = (b * mod_pow(c, h * (pow(2, k - r - 1)), p)) % p;
        r--;
    }

    long x = (mod_pow(a, (h+1)/2, p) * b) % p;
    return x;
}
