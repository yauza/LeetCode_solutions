#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>

using namespace std;


int findPairs(vector<int>& nums, int k) {
    int ctr = 0;
    if(nums.size() == 1) return ctr;
    unordered_map<int, int> hashmap;
    if(k == 0){
        for(int i = 0; i < nums.size(); i++){
            if(hashmap.find(nums[i]) == hashmap.end()){
                hashmap[nums[i]] = i;
            }else{
                if(hashmap[nums[i]] >= 0){
                    hashmap[nums[i]] = -1;
                    ctr++;
                }
            }
        }


    }else{

    //unordered_map<int, int> hashmap;

    for(int i = 0; i < nums.size(); i++){
        if(hashmap.find(nums[i]) == hashmap.end()){
            hashmap[nums[i]] = {i};
        }
    }


    for(auto i : hashmap){
        if(hashmap.find(k+i.first) != hashmap.end()){
            if(i.second != hashmap[k+i.first]) ctr++;
        }
    }
    }

    return ctr;
}


int main(){
    vector<int> nums{1,3,1,5,4,3,5,4,1};
    int k = 0;
    cout << findPairs(nums, k);

    return 0;
}




