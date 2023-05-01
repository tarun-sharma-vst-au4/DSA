#include <iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solve(vector<int>& arr, int i, int sum, int &maxi){
  //base case 
  if( i >= arr.size()){
    //maxi update
    maxi = max(sum, maxi);
    return 0;
  }
  //include
  solve(arr, i+2, sum+arr[i], maxi);
  //exclude
  solve(arr, i+1, sum, maxi);
 
}

int main() {
  vector<int> arr{1,2,3,4,5};
  int sum=0;
  int maxi = INT_MIN;
  int i =0;
  solve(arr,i,sum,maxi);

  cout << maxi << endl;

  return 0;
}