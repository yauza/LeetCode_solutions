#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printv(vector<string> v){
    for(auto i : v) cout << i << " ";
    cout << endl;
}

vector<string> summaryRanges(vector<int>& nums) {
    if(nums.empty()) return {};
    int s, e;
    vector<string> res;
    e = s = nums[0];

    for(int i = 1; i < nums.size(); i++){
        if(nums[i] == e+1){
            e = nums[i];
            continue;
        }else{
            if(s != e) res.push_back(to_string(s) + "->" + to_string(e));
            else res.push_back(to_string(s));
            e = s = nums[i];
        }
    }

    if(s != e) res.push_back(to_string(s) + "->" + to_string(e));
    else res.push_back(to_string(s));

    return res;
}

int main(){
    vector<int> nums{0,2,3,4,6,8,9};
    vector<int> n1{0,2,4,6};
    printv(summaryRanges(n1));
    return 0;
}
