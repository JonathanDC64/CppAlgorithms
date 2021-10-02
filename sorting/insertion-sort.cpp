#include "insertion-sort.h"

void insertion_sort(int *array, int length)
{
  for (int i = 1; i < length; i++)
  {
    int index = array[i];
    int cursor = i - 1;

    while (cursor >= 0 && array[cursor] > index)
    {
      array[cursor + 1] = array[cursor];
      cursor = cursor - 1;
    }
    array[cursor + 1] = index;
  }
}