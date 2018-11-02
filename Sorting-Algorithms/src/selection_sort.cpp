#include <iostream>
#include "sorting.h"

using namespace std;


int* Sort::selection_sort(int* unsorted_arr, int array_length)
{
    int* array_copy = new int[array_length];
    int sorted_num = 0;
    int comp_num = 0;
    int swap_num = 0;

    // make a copy of the input array
    for (int i = 0; i < array_length; i++)
    {
        array_copy[i] = unsorted_arr[i];
    }

    // sorting starts
    while (sorted_num < array_length - 1)
    {
        // store the position of the minimum value that are unsorted
        // sorted_num is the first position of the unsorted elements
        int unsorted_min_id = sorted_num;
        // start with the first unsorted elements
        for (int i = sorted_num + 1; i < array_length; i++)
        {
            comp_num++;
            // update the minimum id
            if (array_copy[i] < array_copy[unsorted_min_id])
            {
                unsorted_min_id = i;
            }
        }
        // if the minimum element is not the first one, swap them
        if (unsorted_min_id != sorted_num)
        {
            swap_ud(array_copy[unsorted_min_id], array_copy[sorted_num]);
            swap_num++;
        }
        // update the number of sorted elements
        sorted_num++;
    }

    cout << "[selection sort] The number of comparison is: " << comp_num << endl;
    cout << "[selection sort] The number of swap is: " << swap_num << endl;
    cout << "========================================" << endl;

    return array_copy;
}
