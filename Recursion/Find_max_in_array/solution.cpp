#include <iostream>
#include<limits.h>
using namespace std;

void findMax(int arr[], int n ,int i, int& maxi){
    if( i >= n){
        return;
    }
    
    if(arr[i] > maxi){
        maxi = arr[i];
    }
    
    findMax(arr,n,i+1,maxi);
}

int main()
{
    int arr[] = {10,30,21,44,32,17,19,66};
    int n =8;
   
    int maxi = INT_MIN;
    
    int i = 0;
    findMax(arr, n , i , maxi);
    
    cout << "Maximum number is : " << maxi << endl;

    return 0;
}