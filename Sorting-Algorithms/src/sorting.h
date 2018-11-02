#ifndef SORTING_H_
#define SORTING_H_

// https://visualgo.net/bn/sorting
class Sort
{
public:
    Sort() = default;
    ~Sort() = default;

    void swap_ud(int& left_var, int& right_var);
    void swap_ud(int* left_var, int* right_var);

    int* bubble_sort(int* unsorted_arr, int array_length);

    int* selection_sort(int* unsorted_arr, int array_length);

    int* insertion_sort(int* unsorted_arr, int array_length);

    int* merge_sort(int* unsorted_arr, int array_length);
    void merge_sort_main(int* unsorted_arr, int id_l, int id_r,
                         int& comp_num, int& swap_num);
    void merge_sort_merge(int* arr, int id_l, int id_m, int id_r,
                          int& comp_num, int& swap_num);

    int* quick_sort(int* unsorted_arr, int array_length);
    void quick_sort_main(int* unsorted_arr, int id_low, int id_high,
                         int& comp_num, int& swap_num);
    int quick_sort_partition(int* arr, int id_low, int id_high,
                             int& comp_num, int& swap_num);
};

#endif
