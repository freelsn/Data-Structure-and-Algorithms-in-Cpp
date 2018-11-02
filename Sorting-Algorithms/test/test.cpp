#include <iostream>
#include "test.h"
#include "sorting.h"

using namespace std;

void test()
{
    int array_length;

    // int unsorted[] = {};
    // int unsorted[] = {3};
    // int unsorted[] = {3, 2};
    // int unsorted[] = {3, 44, 38, 5, 47, 15};
    int unsorted[] = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    // int unsorted[] = {50, 48, 47, 46, 44, 38, 36, 27, 26, 19, 15, 5, 4, 3, 2};
    // int unsorted[] = {2, 3, 4, 5, 15, 19, 26, 27, 36, 38, 44, 46, 47, 48, 50};

    array_length = sizeof(unsorted) / sizeof(unsorted[0]);
    test_proc(unsorted, array_length);
}

void test_proc(int* unsorted, int array_length)
{
    int* sorted_bubble = new int[array_length];
    int* sorted_selection = new int[array_length];
    int* sorted_insertion = new int[array_length];
    int* sorted_merge = new int[array_length];
    int* sorted_quick = new int[array_length];

    Sort sort_inst;

    sorted_bubble = sort_inst.bubble_sort(unsorted, array_length);
    sorted_selection = sort_inst.selection_sort(unsorted, array_length);
    sorted_insertion = sort_inst.insertion_sort(unsorted, array_length);
    sorted_merge = sort_inst.merge_sort(unsorted, array_length);
    sorted_quick = sort_inst.quick_sort(unsorted, array_length);

    cout << "The original array is" << endl;
    print_array(unsorted, array_length);
    cout << "After bubble sort" << endl;
    print_array(sorted_bubble, array_length);
    cout << "After selection sort" << endl;
    print_array(sorted_selection, array_length);
    cout << "After insertion sort" << endl;
    print_array(sorted_insertion, array_length);
    cout << "After merge sort" << endl;
    print_array(sorted_merge, array_length);
    cout << "After quick sort" << endl;
    print_array(sorted_quick, array_length);

    delete[] sorted_bubble;
    delete[] sorted_selection;
    delete[] sorted_insertion;
    delete[] sorted_merge;
    delete[] sorted_quick;
}


void print_array(const int* arr, int array_length)
{
    for (int i = 0; i < array_length; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
