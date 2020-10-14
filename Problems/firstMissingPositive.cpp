#include <iostream>
#include <vector>

using namespace std;


void printtab(vector<int> v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
}


int firstMissingPositive(vector<int>& nums) {
    int res = 1, smallest = INT_MAX, biggest = INT_MIN;
    vector<int> temp(nums.size()+1);
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > 0){
            if(nums[i] < nums.size()+1){
                temp[nums[i]] = 1;
            }
        }
    }
    //printtab(temp);
    for(int i = 1; i < nums.size()+1; i++){
        //cout << temp[i] << " ";
        if(temp[i] == 0){
            res = i;
            break;
        }
    }

    return res;
}


int main(){
    vector<int> nums{3,4,6,2,1};
    cout << firstMissingPositive(nums) << endl;

    return 0;
}
