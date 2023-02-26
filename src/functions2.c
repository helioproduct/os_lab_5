#include "functions.h"
#include <math.h>
    
float Derivative(float A, float deltaX)
{
    return -(cos(A + deltaX) - cos(A)) / deltaX;       
}   

// Фигура - прямоугольник
float Square(float A, float B)
{
    return A * B;
}

