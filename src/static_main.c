#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(void)
{
    int q;
    while (scanf("%d", &q) > 0)
    {
        float arg1, arg2, result;

        scanf("%f %f", &arg1, &arg2);
        
        if (q == 1)
        {
            result = Derivative(arg1, arg2);
        }
        else if (q == 2)
        {  
            result = Square(arg1, arg2);
        }
        printf("%f\n", result);
    }

    return 0;
}
