#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &weights, vector<int> &values, int ind, int W, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (weights[0] <= W)
        {
            return values[0];
        }
        return 0;
    }

    if (dp[ind][W] != -1)
        return dp[ind][W];

    int notTake = 0 + solve(weights, values, ind - 1, W, dp);
    int take = INT_MIN;

    if (weights[ind] <= W)
        take = values[ind] + solve(weights, values, ind - 1, W - weights[ind], dp);

    return dp[ind][W] = max(take, notTake);
}

int solveKnapsack(vector<int> &weights, vector<int> &values, int W, int n)
{
    vector<vector<int>> dp(n + 1, (vector<int>(W + 1, -1)));
    return solve(weights, values, n - 1, W, dp);
}

int main()
{
    int n;
    cout << "Enter number of items: ";
    cin >> n;
    cout << endl;

    vector<int> weights(n);
    vector<int> values(n);
    int W;

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        weights[i] = temp;
    }
    cout << endl;

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        values[i] = temp;
    }
    cout << endl;

    cout << "Enter the weight capacity of knapsack: ";
    cin >> W;
    cout << endl;

    cout << "Optimal Solution: ";
    cout << solveKnapsack(weights, values, W, n);
}