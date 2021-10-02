#include <algorithm>
#include "heap-sort.h"

using namespace std;

// Custom implementation of https://www.geeksforgeeks.org/heap-sort/

void heap(int *array, int size, int node)
{
  int largest = node;
  int left = (2 * node) + 1;
  int right = (2 * node) + 2;

  if (left < size && array[left] > array[largest])
  {
    largest = left;
  }

  if (right < size && array[right] > array[largest])
  {
    largest = right;
  }

  if (largest != node)
  {
    swap(array[node], array[largest]);
    heap(array, size, largest);
  }
}

void heap_sort(int *array, int length)
{
  for (int i = length / 2 - 1; i >= 0; --i)
  {
    heap(array, length, i);
  }

  for (int i = length - 1; i > 0; --i)
  {
    swap(array[0], array[i]);
    heap(array, i, 0);
  }
}
