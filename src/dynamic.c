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
    void* dyn_library_handle = dlopen(DYN_LIB_1, RTLD_LAZY);

    float arg1, arg2, result;
    float (*Derivative)(float, float) = dlsym(dyn_library_handle, FUN1_NAME);
    float (*Square)(float, float) = dlsym(dyn_library_handle, FUN2_NAME);

    int command;
    while (scanf("%d", &command) == 1)
    {
        switch (command)
        {
        // switch libaries
        case 0:
            if (dlclose(dyn_library_handle) != 0)
            {
                printf("error closing libary");
                return 1;
            }
            if (lib_number == 1) 
            {
                dyn_library_handle = dlopen(DYN_LIB_2, RTLD_LAZY);
                lib_number = 2;
            } 
            else 
            {
                dyn_library_handle = dlopen(DYN_LIB_2, RTLD_LAZY);
                lib_number = 1;
            }

            if (dyn_library_handle == NULL) 
            {
                printf("dlopen error");
                return 2;
            }
    
            *(void**) (&Derivative) = dlsym(dyn_library_handle, FUN1_NAME);
            *(void**) (&Square) = dlsym(dyn_library_handle, FUN2_NAME);
            
            printf("Switched libs\n");

            break;
        
        // Derivative
        case 1:

            if (scanf("%f %f", &arg1, &arg2) != 2)
            {
                printf("error reading arguments");
                return 3;
            }
            printf("%f\n", Derivative(arg1, arg2)); 

            break;
        // Square
        case 2:

            if (scanf("%f %f", &arg1, &arg2) != 2)
            {
                printf("error reading arguments");
                return 3;
            }
            printf("%f", Square(arg1, arg2)); 

            break;

        default:
            break;
        }
    }
    
    return 0;
}
