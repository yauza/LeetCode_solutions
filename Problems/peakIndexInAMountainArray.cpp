#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int n = arr.size();
    int p = 0, q = n-1, peak = (p+q+1)/2;

    while(!(arr[peak] > arr[peak-1] && arr[peak] > arr[peak+1])){
        //cout << peak << " ";
        peak = (p+q+1)/2;
        if(arr[peak] < arr[peak-1]){
            q = peak-1;
        }else if(arr[peak] < arr[peak+1]){
            p = peak+1;
        }

    }
    return peak;
}


int main(){

    vector<int> arr{24,69,100,99,79,78,67,36,26,19};  //2
    vector<int> arr1{0,1,0};  //1
    vector<int> arr2{0,2,1,0};  //1
    vector<int> arr3{3,4,5,1};  //2
    cout << peakIndexInMountainArray(arr3) << endl;

    return 0;
}

