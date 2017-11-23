#include <iostream>
#include <cassert>

// The goal in this problem is to find the minimum number of coins needed to change the input value
// (an integer) into coins with denominations 1, 5, and 10.

int get_change(int m) {
  //write your code here
  int n = 0;
  if (m % 10 == 0)
    n = m / 10;
  else if (m % 5 == 0)
    n = m / 5;
  else if (m % 1 == 0)
    n = m / 1;
  return n;
}

void test_solution() {
  assert(get_change(15) == 3);
  assert(get_change(150) == 15);
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
