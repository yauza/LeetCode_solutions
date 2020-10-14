#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums) {
    int n = nums.size();

    if(n == 0 || n == 1) return 0;
    /*
    if(n == 2){
        return max(nums[0], nums[1]);
    }
    */

    int p = 0, q = n-1, peak;

    while(p < q){
        peak = p+(q-p)/2;
        if(nums[peak] > nums[peak+1]) q = peak;
        else p = peak+1;
    }

    return q;
}


int main(){

    vector<int> arr{1,2,3,1};  //2
    vector<int> arr1{1,2,1,3,5,6,4};  //1 or 5
    vector<int> arr2{2,1}; //0
    cout << findPeakElement(arr) << endl;

    return 0;
}


