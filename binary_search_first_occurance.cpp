#include <bits/stdc++.h>
using namespace std;

int first_occurance(int arr[], int n, int k)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (arr[mid] == k)
        {
            if (mid == 0 || arr[mid - 1] != k)
            {
                return mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        else if (arr[mid] < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
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
    cout << first_occurance(arr, n, k);
}