#include <iostream>
#include "sorting.h"

using namespace std;

int* Sort::bubble_sort(int* unsorted_arr, int array_length)
{
    int* array_copy = new int[array_length];
    bool not_sorted;
    int sorted_num = 0;

    int comp_num = 0;
    int swap_num = 0;

    // make a copy of the input array
    for (int i = 0; i < array_length; i++)
    {
        array_copy[i] = unsorted_arr[i];
    }

    do
    {
        not_sorted = false;
        for (int i = 1; i < array_length - sorted_num; i++)
        {
            comp_num++;
            // For every two adjacent numbers, always put the larger one on the right side.
            if (array_copy[i - 1] > array_copy[i])
            {
                swap_ud(array_copy[i - 1], array_copy[i]);
                not_sorted = true;
                swap_num++;
            }
            // After one iteration, the largest number will be in the rightmost position.
        }
        sorted_num++;
    } while (not_sorted);

    cout << "[bubble sort] The number of comparison is: " << comp_num << endl;
    cout << "[bubble sort] The number of swap is: " << swap_num << endl;
    cout << "========================================" << endl;

    return array_copy;
}
