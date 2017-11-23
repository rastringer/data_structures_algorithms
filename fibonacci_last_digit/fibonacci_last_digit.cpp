#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_naive_fast(int n) {
  int fibonacci_array[n];
  fibonacci_array[0] = 0;
  fibonacci_array[1] = 1;
  for (int i = 2; i <= n; i++)
    fibonacci_array[i] = (fibonacci_array[i-1] + fibonacci_array[i - 2]) % 10;

    return fibonacci_array[n];
}

int main() {
    int n;
    std::cin >> n;
    // int c = get_fibonacci_last_digit_naive(n);
    // std::cout << c << '\n';
    int d = get_fibonacci_last_digit_naive_fast(n);
    std::cout << d << '\n';
    }
