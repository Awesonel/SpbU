#include <stdio.h>
#include <stdlib.h>
#include "modPower.h"

unsigned int moduloPowerRecursive(unsigned int basis, unsigned int indicator, unsigned int module)
{
    if (indicator == 1)
        return basis % module;

    if (indicator & 1)
        return (basis * moduloPowerRecursive((basis * basis) % module, indicator >> 1, module)) % module;
    return  moduloPowerRecursive((basis * basis) % module, indicator >> 1, module);
}

unsigned int moduloPowerCycle(unsigned int basis, unsigned int indicator, unsigned int module)
{
    int takenOutNumbers = 1;

    while (indicator)
    {
        if (indicator & 1)
            takenOutNumbers *= basis;
        basis *= basis;
        basis %= module;
        indicator >>= 1;
    }
    return takenOutNumbers % module;
}

void testModuloPower()
{
    unsigned int basis, indicator, module;
    printf("basis^indicator mod module:\ninsert basis, indicator and module separated by a space: ");
    scanf("%d %d %d", &basis, &indicator, &module);
    printf("Result of recursive - %d\n", moduloPowerRecursive(basis, indicator, module));
    printf("Result of cycle - %d", moduloPowerCycle(basis, indicator, module));
}

long long mod_pow(long long x, long long y, long long m){
    long long powi = x % m;
    long long ans = 1;
    while (y){
        if (y & 1){
            ans *= powi;
        }
        powi = (powi * powi) % m;
        y >>= 1;
    }
    return ans % m;
}
