
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;


void printv(vector<int> v){
    for(auto i : v){
        cout << i << "   ";
    }
    cout << endl;
}

int findDuplicate(vector<int>& nums) {
    unordered_map<int,int> hashmap;

    for(int i = 0; i < nums.size(); i++){
        if(hashmap.find(nums[i]) == hashmap.end()){
            hashmap[nums[i]] = 1;
        }else{
            return nums[i];
        }
    }

    return 1;
}


int main(){


    return 0;
}

