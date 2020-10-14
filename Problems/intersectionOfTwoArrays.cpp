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


vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> hashmap;

    for(auto i : nums1){
        if(hashmap.find(i) == hashmap.end()){
            hashmap[i] = 1;
        }
    }

    vector<int> res;

    for(auto i : nums2){
        if(hashmap.find(i) != hashmap.end()){
            if(hashmap[i] != 0){
                res.push_back(i);
                hashmap[i]--;
            }
        }
    }

    return res;
}


int main(){
    vector<int> res;
    vector<int> nums1{1,2,2,1};
    vector<int> nums2{2,2};
    vector<int> nums3{4,9,5};
    vector<int> nums4{9,4,9,8,4};
    vector<int> nums5{6,5,5};
    vector<int> nums6{1,1,1,2,2,2,2,2,2};
    res = intersection(nums5, nums6);
    print(res);
    return 0;
}

