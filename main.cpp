#include <iostream>
#include <vector>
#include <string>
#include "sorting/selection-sort.h"
#include "sorting/bubble-sort.h"
#include "sorting/insertion-sort.h"
#include "sorting/merge-sort.h"
#include "sorting/quick-sort.h"
#include "sorting/heap-sort.h"

using namespace std;

void print_array(const vector<int> &array)
{
  for (int i : array)
  {
    cout << i << ",";
  }
  cout << endl;
}

void test_sort(const string &name, void (*sort_func)(int *, int))
{
  vector<int> sort_values = {64, 25, 12, 22, 11, 4, 28, 32, 14, 1};
  cout << name << " sort: " << endl;
  sort_func(&sort_values[0], sort_values.size());
  print_array(sort_values);
}

int main()
{
  test_sort("Selection", selection_sort);
  test_sort("Bubble", bubble_sort);
  test_sort("Insertion", insertion_sort);
  test_sort("Merge", merge_sort);
  test_sort("Quick", quick_sort);
  test_sort("Heap", heap_sort);

  return 0;
}