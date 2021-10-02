#include <algorithm>
#include "quick-sort.h"
using namespace std;

// Custom implementation of https://www.geeksforgeeks.org/quick-sort/

int partition(int *array, int bottom, int top)
{
  int pivot = array[top];
  int cursor = bottom - 1;

  for (int j = bottom; j <= top - 1; j++)
  {
    if (array[j] < pivot)
    {
      cursor++;
      swap(array[cursor], array[j]);
    }
  }
  swap(array[cursor + 1], array[top]);
  return cursor + 1;
}

void quick_sort_helper(int *array, int bottom, int top)
{
  if (bottom < top)
  {
    int pivot = partition(array, bottom, top);
    quick_sort_helper(array, bottom, pivot - 1);
    quick_sort_helper(array, pivot + 1, top);
  }
}

void quick_sort(int *array, int length)
{
  quick_sort_helper(array, 0, length - 1);
}