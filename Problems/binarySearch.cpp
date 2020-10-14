#include <iostream>
#include <vector>

using namespace std;


int binsearch(vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1;

    while(l <= r){
        int mid = (l+r)/2;
        if(target == nums[mid]) return mid;
        else if(target > nums[mid]) l = mid+1;
        else r = mid-1;
    }

    return -1;
}


int main(){
    vector<int> nums{-1,0,3,5,9,12};
    int t = 2;
    cout << binsearch(nums, t) << endl;

    return 0;
}
