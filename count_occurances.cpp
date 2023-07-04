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

int last_occurance(int arr[], int n, int k)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (arr[mid] == k)
        {
            if (mid == n - 1 || arr[mid + 1] != k)
            {
                return mid;
            }
            else
            {
                low = mid + 1;
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

int count_occurances(int arr[], int n, int k)
{
    int first = first_occurance(arr, n, k);
    if (first == -1)
    {
        return 0;
    }
    return (last_occurance(arr, n, k) - first + 1);
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
    cout << count_occurances(arr, n, k);
}