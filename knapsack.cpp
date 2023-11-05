#include <iostream>
#include <vector>

using namespace std;

void zeroOneKnapsack(int n, vector<int> val, vector<int> weight, int cap) {

  vector<vector<int>> dp(n + 1, vector<int>(cap + 1));

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < cap + 1; j++) {
      int value = val[i - 1];
      int wei = weight[i - 1];
      if (j - wei >= 0) {
        dp[i][j] =  max(dp[i][j], dp[i - 1][j - wei] + value);
      }
      dp[i][j] =  max(dp[i - 1][j], dp[i][j]);
    }
  }
  cout << dp[n][cap];
}

int main() {

  int n;
  cin >> n;

  vector<int> val(n);
  for (int i = 0; i < n; i++) {
    cin >> val[i];
  }

  vector<int> weight(n);
  for (int i = 0; i < n; i++) {
    cin >> weight[i];
  }

  int cap;
  cin >> cap;

  zeroOneKnapsack(n, val, weight, cap);


}