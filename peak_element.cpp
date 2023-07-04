#include <bits/stdc++.h>
using namespace std;

int peak(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    while (high >= low)
    {
        int mid = (high + low) / 2;
        if ((mid == 0 && arr[mid] >= arr[mid + 1]) || (mid == n - 1 && arr[mid] >= arr[mid - 1]))
        {
            return mid;
        }
        else if (mid > 0 && arr[mid - 1] > arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << peak(arr, n);
}