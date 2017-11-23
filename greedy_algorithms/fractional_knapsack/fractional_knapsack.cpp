#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values, int n) {
  double value = 0.0;

  // Vector for value-to-weight ratios
  vector<double> ratio(n);

  // Populate ratios vector
  for (int i = 0; i < n; ++i )
  {
      ratio[i] = (double)values[i] / weights[i];
  }

  // Bubble sort ratios for max
  for (int j = 0; j < n-1; ++j)
  {
    for (int k = 0; k < n - j; k++)
    {
      if (ratio[k] < ratio[k + 1])
      {
        double item = ratio[k];
        ratio[k] = ratio[k + 1];
        ratio[k + 1] = item;

        // Update weights
        int w;
        w = weights[k];
        weights[k] = weights[k + 1];
        weights[k + 1] = w;

        // Update values
        int v;
        v = values[k];
        values[k] = values[k + 1];
        values[k + 1] = v;
      }
    }
  }

  // Now update capacity of knapsack
  for (int l = 0; l < n; ++l)
  {
    if(capacity > weights[l])
    {
      value = value + weights[l] * ratio[l];
      capacity = capacity - weights[l];
    }
    else
    {
      value = value + capacity * ratio[l];
      capacity = 0;
      break;
    }
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values, n);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}

// Sample input:
// 3 50
// 60 20
// 100 50
// 120 30
//
// Output:
// 180
