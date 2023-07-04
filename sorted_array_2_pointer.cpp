#include <bits/stdc++.h>
using namespace std;

bool sum_present(int arr[], int n, int k)
{
    int l = 0;
    int r = n - 1;
    while (l < r)
    {
        int sum = arr[l] + arr[r];
        if (sum == k)
        {
            return true;
        }
        else if (sum > k)
        {
            r--;
        }
        else
        {
            l++;
        }
    }
    return false;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << sum_present(arr, n, k);
}