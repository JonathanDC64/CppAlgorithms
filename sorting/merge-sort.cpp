#include "merge-sort.h"
#include <algorithm>

using namespace std;

// Custom implementation of https://www.geeksforgeeks.org/merge-sort/

void merge(int *array, int const left, int const middle, int const right)
{
  int const left_array_size = middle - left + 1;
  int const right_array_size = right - middle;

  int *left_array = new int[left_array_size];
  int *right_array = new int[right_array_size];

  copy(&array[left], &array[left + left_array_size], left_array);
  copy(&array[middle + 1], &array[middle + 1 + right_array_size], right_array);

  int left_array_index = 0;
  int right_array_index = 0;
  int merged_index = left;

  while (left_array_index < left_array_size && right_array_index < right_array_size)
  {
    if (left_array[left_array_index] <= right_array[right_array_index])
    {
      array[merged_index] = left_array[left_array_index];
      left_array_index++;
    }
    else
    {
      array[merged_index] = right_array[right_array_index];
      right_array_index++;
    }
    merged_index++;
  }

  while (left_array_index < left_array_size)
  {
    array[merged_index] = left_array[left_array_index];
    left_array_index++;
    merged_index++;
  }

  while (right_array_index < right_array_size)
  {
    array[merged_index] = right_array[right_array_index];
    right_array_index++;
    merged_index++;
  }
}

void merge_sort_helper(int *array, int const begin, int const end)
{
  if (begin >= end)
    return;

  auto middle = begin + (end - begin) / 2;
  merge_sort_helper(array, begin, middle);
  merge_sort_helper(array, middle + 1, end);
  merge(array, begin, middle, end);
}

void merge_sort(int *array, int length)
{
  merge_sort_helper(array, 0, length - 1);
}