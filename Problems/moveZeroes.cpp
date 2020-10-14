#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
    int z = 0, i = 0;

    while(i < nums.size()){
        if(nums[i] == 0){
            z += 1;
            i += 1;
        }else if(nums[i] != 0){
            swap(nums[i-z], nums[i]);
            i -= (z-1);
            z = 0;
            //i += 1;
        }

    }
    /*
    cout << endl << endl;

    for(auto i : nums){
        cout << i << " ";
    }
    */
}

int main(){

    vector<int> arr{0,1,0,3,12};
    vector<int> arr1{1,2,3,4,0,0,0};
    vector<int> arr2{0,0,0,1,20,0,0,3,0,4,0};
    vector<int> arr3{0,0,0,0};
    moveZeroes(arr3);


    return 0;
}



