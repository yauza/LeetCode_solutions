#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

void printv(vector<int> v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
}

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> hashmap;
    int sum = 0, res = 0;
    hashmap[0] = 1;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        res += hashmap[sum - k];
        hashmap[sum]++;
    }

    return res;
}

int main(){
    vector<int> nums{1,2,3,4,5,5,1,6,3,7,8,9,10};
    int k = 10;
    cout << subarraySum(nums, k) << endl;

    return 0;
}


