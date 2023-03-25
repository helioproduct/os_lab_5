#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

const char* DYN_LIB_1 = "./libfuns1.so";
const char* DYN_LIB_2 = "./libfuns2.so";

const char *FUN1_NAME = "Derivative";
const char *FUN2_NAME = "Square";

int main(void)
{
    int lib_number = 1;
    void* handle = dlopen(DYN_LIB_1, RTLD_LAZY);

    float arg1, arg2;
    float (*Derivative)(float, float);
    float (*Square)(float, float);

    *(void**) (&Derivative) = dlsym(handle, FUN1_NAME);
    *(void**) (&Square) = dlsym(handle, FUN2_NAME);

    int command;
    while (scanf("%d", &command) == 1)
    {
        switch (command)
        {
        // switch libaries
        case 0:
            if (dlclose(handle) != 0)
            {
                printf("error closing libary\n");
                return 1;
            }
            if (lib_number == 1) 
            {
                handle = dlopen(DYN_LIB_2, RTLD_LAZY);
                lib_number = 2;
            } 
            else 
            {
                handle = dlopen(DYN_LIB_1, RTLD_LAZY);
                lib_number = 1;
            }
            if (handle == NULL) 
            {
                printf("dlopen error\n");
                return 2;
            }
            *(void**) (&Derivative) = dlsym(handle, FUN1_NAME);
            *(void**) (&Square) = dlsym(handle, FUN2_NAME);
            printf("switched libs to lib%d\n", lib_number);
            break;
        
        // Derivative
        case 1:
            if (scanf("%f %f", &arg1, &arg2) != 2)
            {
                printf("error reading arguments\n");
                return 3;
            }
            printf("%f\n", Derivative(arg1, arg2)); 
            break;
        // Square
        case 2:
            if (scanf("%f %f", &arg1, &arg2) != 2)
            {
                printf("error reading arguments\n");
                return 3;
            }
            printf("%f\n", Square(arg1, arg2)); 
            break;

        default:
            break;
        }
    }
    
    return 0;
}
