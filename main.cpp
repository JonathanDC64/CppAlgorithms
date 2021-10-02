#include <iostream>
#include <vector>
#include "sorting/selection-sort.h"

using namespace std;

void print_array(const vector<int> &array)
{
  for (int i : array)
  {
    cout << i << ",";
  }
  cout << endl;
}

int main()
{
  cout << "Selection sort: " << endl;
  vector<int> selection_sort_values = {64, 25, 12, 22, 11};
  selection_sort(&selection_sort_values[0], selection_sort_values.size());
  print_array(selection_sort_values);
  return 0;
}