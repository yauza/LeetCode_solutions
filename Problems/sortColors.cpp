#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <vector>

using namespace std;


void print(vector<int> v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
}

void sortColorsOnePass(vector<int>& nums){  //ne dzia³¹ eleo
    int i = 0, j = nums.size()-1;

    while(i < j){
            cout << "a";
        if(nums[i] == 0) i++;
        else if(nums[j] == 2) j--;
        else if(nums[i] == 2){
            swap(nums[i], nums[j]);
            j--;
        }else if(nums[j] == 0){
            swap(nums[i], nums[j]);
            i++;
        }else if(nums[i] == 1){
            swap(nums[i], nums[(j-i)/2]);
        }else if(nums[j] == 1){
            swap(nums[j], nums[(j-i)/2]);
        }else{
            i++;
            j--;
        }
    }
}

void sortColors(vector<int>& nums) {
    vector<int> countSort(3);
    countSort[0] = 0;
    countSort[1] = 0;
    countSort[2] = 0;

    for(int i = 0; i < nums.size(); i++){
        countSort[nums[i]]++;
    }

    for(int i = 0; i < nums.size(); i++){
        if(i < countSort[0]) nums[i] = 0;
        else if(i < countSort[0]+countSort[1]) nums[i] = 1;
        else nums[i] = 2;
    }

}


int main(){
    vector<int> nums{2,0,2,1,1,0};
    vector<int> nums1{1,1,1,1,1,2,1,2,1,2,1,2,0,0,0,2,1,0,0,0,0,2,1,0,2,1,0,1,1,0,0,0};
    print(nums1);
    sortColorsOnePass(nums1);
    print(nums1);
    return 0;
}




