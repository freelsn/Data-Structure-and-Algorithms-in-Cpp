#include <iostream>
#include <vector>
#include "sorting.h"

using namespace std;

int* Sort::insertion_sort(int* unsorted_arr, int array_length)
{
    int* array_copy = new int[array_length];
    int comp_num = 0;
    int swap_num = 0;
    // the extra space, vector of size n
    vector<int> sorted_array;
    vector<int>::iterator it;

    // insert the first element
    sorted_array.push_back(unsorted_arr[0]);
    // start insert the rest elements
    for(int i = 1; i < array_length; i++)
    {
        it = sorted_array.begin();  // the pointer
        int insert_position = i;
        int value_to_insert = unsorted_arr[i];
        // compare the element to be inserted against the sorted elements
        // while(value_to_insert < sorted_array[insert_position - 1] && insert_position != 0)
        while(insert_position != 0)
        {
            comp_num++;
            if(value_to_insert < sorted_array[insert_position - 1])
            {
                insert_position--;
            }
            else
            {
                break;
            }
        }
        // if the value is the biggest, insert in the end
        if(insert_position == i)
        {
            sorted_array.push_back(value_to_insert);
        }
        else
        {
            swap_num++;
            sorted_array.insert(it + insert_position, value_to_insert);
        }
    }

    cout << "[insertion sort] The number of comparison is: " << comp_num << endl;
    cout << "[insertion sort] The number of insertion is: " << swap_num << endl;
    cout << "========================================" << endl;

    // copy the vector to an array
    // this is for indicating that the vector is the extra space
    for(int i = 0; i < array_length; i++)
    {
        array_copy[i] = sorted_array[i];
    }

    return array_copy;
}
