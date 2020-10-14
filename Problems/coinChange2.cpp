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

/*
void solve(vector<int> coins, int amount, int sum, int& q, int ind){
    if(sum > amount) return;

    if(sum == amount){
        q++;
        return;
    }

    for(int i = ind; i < coins.size(); i++){
        solve(coins, amount, sum+coins[i], q, i);
    }

}
*/

int change(int amount, vector<int>& coins) {
    vector<int> dp;
    for(int i = 0; i < amount+1; i++) dp.push_back(0);
    dp[0] = 1;

    for(auto c : coins){
        for(int i = c; i < amount+1; i++){
                dp[i] += dp[i-c];
            printv(dp);
        }
    }

    return dp[amount];
}

int main(){
    vector<int> c{1,2,5,7,15};
    cout << change(37, c) << endl;
    system("PAUSE");
    return 0;
}






