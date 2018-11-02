#include <iostream>
#include <cassert>
#include "sorting.h"

using namespace std;

// https://www.geeksforgeeks.org/merge-sort/
int* Sort::merge_sort(int* unsorted_arr, int array_length)
{
    int* array_copy = new int[array_length];
    int comp_num = 0;
    int swap_num = 0;

    for(int i = 0; i < array_length; i++)
    {
        array_copy[i] = unsorted_arr[i];
    }

    merge_sort_main(array_copy, 0, array_length - 1, comp_num, swap_num);

    cout << "[merge sort] The number of comparison is: " << comp_num << endl;
    cout << "[merge sort] The number of assignment is: " << swap_num << endl;
    cout << "========================================" << endl;

    return array_copy;
}

// id_low, id_high inclusive
void Sort::merge_sort_main(int* unsorted_arr, int id_l, int id_r, int& comp_num, int& swap_num)
{
    if(id_l < id_r)
    {
        int id_m = id_l + (id_r - id_l) / 2;  // split the unsorted
        // sort left part
        merge_sort_main(unsorted_arr, id_l, id_m, comp_num, swap_num);
        // sort right part
        merge_sort_main(unsorted_arr, id_m + 1, id_r, comp_num, swap_num);
        // merge sorted left and right parts
        merge_sort_merge(unsorted_arr, id_l, id_m, id_r, comp_num, swap_num);
    }
}

// id_low, id_high inclusive
void Sort::merge_sort_merge(int* arr, int id_l, int id_m, int id_r, int& comp_num, int& swap_num)
{
    int len_l = id_m - id_l + 1;
    int len_r = id_r - id_m;

    int i = 0;
    int j = 0;
    int k = id_l;

    // copies of the arrays to be merged
    int* arr_l = new int[len_l];
    int* arr_r = new int[len_r];

    for (i = 0; i < len_l; i++)
    {
        arr_l[i] = arr[id_l + i];
    }
    for (i = 0; i < len_r; i++)
    {
        arr_r[i] = arr[id_m + 1 + i];
    }

    // start merging
    i = 0;
    while(i < len_l && j < len_r)
    {
        // if left element is smaller
        if(arr_l[i] < arr_r[j])
        {
            arr[k] = arr_l[i];
            i++;
        }
        else
        {
            arr[k] = arr_r[j];
            j++;
        }
        k++;
        comp_num++;
        swap_num++;
    }
    // if left part is not empty
    while(i < len_l)
    {
        arr[k] = arr_l[i];
        i++;
        k++;
        swap_num++;
    }
    // if right part is not empty
    while(j < len_r)
    {
        arr[k] = arr_r[j];
        j++;
        k++;
        swap_num++;
    }

    assert(i == len_l);
    assert(j == len_r);
    assert(k == id_r + 1);
}
