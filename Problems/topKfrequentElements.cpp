#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void printv(vector<int> v){
    for(auto i : v) cout << i << " ";
    cout << endl;
}


vector<int> topKFrequent(vector<int>& nums, int k) {
    if(nums.size() == 0) return {};
    vector<int> res;
    unordered_map<int, int> map1;
    vector<vector<int>> buckets(nums.size()+1);

    for(auto el : nums){
        if(map1.find(el) == map1.end()) map1[el] = 1;
        else map1[el]++;
    }

    for(auto i : map1){
        buckets[i.second].push_back(i.first);
    }

    for(int i = nums.size(); i >= 0 && k > 0; i--){
        if(buckets[i].size() > 0){
            for(auto el : buckets[i]){
                res.push_back(el);
                k--;
            }
        }
    }

    return res;
}


int main(){
    vector<int> nums{1,1,1,2,2,2,2,3};
    printv(topKFrequent(nums, 2));

    return 0;
}
