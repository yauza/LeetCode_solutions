#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int solve(vector<int>& nums, int a, int b){
    vector<int> dp(nums.size(), INT_MIN);
    dp[a] = nums[a];
    dp[a+1] = max(nums[a], nums[a+1]);

    for(int i = a+2; i <= b; i++){
        dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
    }

    return dp[b];
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return nums[0];
    int res = max(solve(nums, 0, n-2), solve(nums, 1, n-1));
    return res;
}

int main(){
    vector<int> a{2,3,2,6,2,4,5,7,1,8,3,6,4};
    cout << rob(a) << endl;
    return 0;
}
