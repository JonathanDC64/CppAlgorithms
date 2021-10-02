#include <algorithm>
#include "selection-sort.h"

using namespace std;

void selection_sort(int *array, int length)
{
  for (int i = 0; i < length - 1; i++)
  {
    int min_val = i;
    for (int j = i + 1; j < length; j++)
      if (array[j] < array[min_val])
        min_val = j;

    swap(array[min_val], array[i]);
  }
}