#include <iostream>
#include <vector>

using namespace std;


int lengthOfLIS(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    vector<int> dp(nums.size());
    int maxL = 0;
    dp[0] = 1;


    for(int i = 1; i < nums.size(); i++){
        dp[i] = 1;

        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i] && dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
        }

        if(dp[maxL] < dp[i]) maxL = i;
    }

    return dp[maxL];
}


int main(){
    vector<int> v{10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS(v) << endl;
    return 0;
}

