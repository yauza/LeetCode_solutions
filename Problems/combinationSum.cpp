#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void printtab(vector<vector<int>> v){
    for(auto j : v){
        for(auto i : j){
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void rec(vector<int> candidates, int T, int sum, int next, vector<vector<int>>& res, vector<int> ans){
    if(sum == T) res.push_back(ans);
    if(sum > T || next >= candidates.size()) return;

    for(int i = next; i < candidates.size(); i++){
        ans.push_back(candidates[i]);
        rec(candidates, T, sum+candidates[i], i, res, ans);
        ans.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> ans;
    if(candidates.size() == 0) return res;
    sort(candidates.begin(), candidates.end());
    int sum = 0;
    rec(candidates, target, sum, 0, res, ans);

    return res;
}

int main(){
    vector<int> candidates{2,3,5};
    int t = 8;
    vector<vector<int>> res = combinationSum(candidates, t);
    printtab(res);

    return 0;
}


