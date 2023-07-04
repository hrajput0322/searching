#include<bits/stdc++.h>
using namespace std;

double median(int arr1[], int arr2[], int n1, int n2){
    int low=0;
    int high=n1;
    while (high>=low){
        int i1=(high+low)/2;
        int i2=(n1+n2+1)/2-i1;
        int max1= (i1==0)?INT_MIN:arr1[i1-1];
        int max2= (i2==0)?INT_MIN:arr2[i2-1];
        int min1= (i1==n1)?INT_MAX:arr1[i1];
        int min2= (i2==n2)?INT_MAX:arr2[i2];
        if (max1<=min2 && max2<=min1){
            if ((n1+n2)%2==0){
                return ((max(max1,max2)+min(min1,min2))/2.0);
            }
            else {
                return (max(max1,max2));
            }
        }
        else if (max1>min2){
            high=i1-1;
        }
        else {
            low=i1+1;
        }
    }
}

int main(){
    int n1,n2;
    cin>>n1>>n2;
    int arr1[n1];
    int arr2[n2];
    for (int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    for (int i=0;i<n2;i++){
        cin>>arr2[i];
    }
    cout<<median(arr1, arr2, n1, n2);
}