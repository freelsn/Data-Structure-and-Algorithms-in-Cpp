#include "sorting.h"


void Sort::swap_ud(int& left_var, int& right_var)
{
    int temp = left_var;
    left_var = right_var;
    right_var = temp;
}

void Sort::swap_ud(int* left_var, int* right_var)
{
    int temp = *left_var;
    *left_var = *right_var;
    *right_var = temp;
}
