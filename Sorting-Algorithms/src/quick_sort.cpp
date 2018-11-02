#include <iostream>
#include <cassert>
#include "sorting.h"

using namespace std;

int* Sort::quick_sort(int* unsorted_arr, int array_length)
{
    int* array_copy = new int[array_length];
    int comp_num = 0;
    int swap_num = 0;

    for(int i = 0; i < array_length; i++)
    {
        array_copy[i] = unsorted_arr[i];
    }

    quick_sort_main(array_copy, 0, array_length - 1, comp_num, swap_num);

    cout << "[quick sort] The number of comparison is: " << comp_num << endl;
    cout << "[quick sort] The number of swap is: " << swap_num << endl;
    cout << "========================================" << endl;

    return array_copy;
}

// id_low, id_high inclusive
void Sort::quick_sort_main(int* unsorted_arr, int id_low, int id_high, int& comp_num, int& swap_num)
{
    if(id_low < id_high)
    {
        // select the first element as the initial pivot
        // and update the pivot position
        int pivot = quick_sort_partition(unsorted_arr, id_low, id_high, comp_num, swap_num);

        // sort the part on the left side of the pivot
        quick_sort_main(unsorted_arr, id_low, pivot - 1, comp_num, swap_num);
        // sort the part on the right side of the pivot
        quick_sort_main(unsorted_arr, pivot + 1, id_high, comp_num, swap_num);
    }
}

// id_low, id_high inclusive
int Sort::quick_sort_partition(int* arr, int id_low, int id_high, int& comp_num, int& swap_num)
{
    int id_pivot = id_low;
    int id_small = id_low;  // the end of the elements that are smaller than the pivot
    int id_rest = id_low + 1;  // the rest un-compared elements

    // iterate the rest elements
    while(id_rest < id_high + 1)
    {
        comp_num++;
        // if smaller than pivot, swap with the element which is right after the last smaller element
        if(arr[id_rest] < arr[id_pivot])
        {
            id_small++;
            swap_num++;
            swap_ud(arr[id_rest], arr[id_small]);
        }
        id_rest++;
    }
    // swap the pivot and the last element in the small set
    swap_ud(arr[id_pivot], arr[id_small]);
    swap_num++;

    assert(id_rest == id_high + 1);

    return id_small;
}
