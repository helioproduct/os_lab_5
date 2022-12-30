#include "declaration.h"

float derivative(float A, float deltaX)
{
    return (cos(A + deltaX) - cos(A - deltaX)) / (2 * deltaX);
}