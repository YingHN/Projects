#include <bits/stdc++.h>
using namespace std;
class Heap
// the biggest one is at the top of the heap
{
public:
  vector<int> heap;
  void Up(signed index)
  // O(k) (k is the deepth of the node#index)
  {
    for (signed i = index; i > 0 && heap[i >> 1] < heap[i]; i >>= 1)
      swap(heap[i >> 1], heap[i]);
  }
  void Down(signed index)
  // O((\log n) - k)
  {

    for (signed i = index, son = i << 1, n = heap.size(); son < n; i = son, son = i * 2)
    {
      if (son + 1 < n && heap[son] < heap[son + 1])
        ++son;
      if (heap[son] <= heap[i])
        break;
      swap(heap[son], heap[i]);
    }
  }
  Heap(vector<int> &vec)
  // O(n)
  {
    heap = vec;
    for (int i = (heap.size() >> 1); i >= 0; --i)
      Down(i);
  }
  int GetTop()
  // O(1)
  {
    return heap[0];
  }
  void Insert(int a)
  // O(\log n)
  {
    heap.push_back(a);
    Up(heap.size() - 1);
  }
  void Deleteintop()
  // O(\log n)
  {
    swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();
    Down(0);
  }
};

int main()
{
  vector<int> vec;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    int t;
    cin >> t;
    vec.push_back(t);
  }
  Heap heap(vec);
  /*
  building heap in this way is in O(n)
  if you use Insert() when inputting,
  it'll be O(n\log n)
  */

  /*do something here*/
}