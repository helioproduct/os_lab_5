#include "functions.h"
#include <math.h>

float Derivative(float A, float deltaX)
{
    return (cos(A + deltaX) - cos(A - deltaX)) / (2 * deltaX);
}

// Фигура - прямоугольный треугольник
float Square(float A, float B)
{
    return 0.5 * A * B; 
}