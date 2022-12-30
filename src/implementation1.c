#include <math.h>
    
float derivative(float A, float deltaX)
{
    return -(cos(A + deltaX) - cos(A)) / deltaX;       
}   