#include<bits/stdc++.h>
using namespace std;

bool is_feasible (int arr[], int n, int k, int mid){
    int count=1;
    int sum=0;
    for (int i=0;i<n;i++){
        if (sum+arr[i]>mid){
            count++;
            sum=arr[i];
        }
        else {
            sum+=arr[i];
        }
    }
    return (count<=k);
}

int minimum_pages(int arr[], int n, int k){
    int maxx=0;
    int sum=0;
    for (int i=0;i<n;i++){
        maxx=max(maxx,arr[i]);
        sum+=arr[i];
    }
    int high=sum;
    int low=maxx;
    int res=0;
    while (low<=high){
        int mid=(high+low)/2;
        if (is_feasible(arr, n, k, mid)){
            res=mid;
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }
    return res;
}

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<minimum_pages(arr, n, k);
}