#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void printtab(vector<int> v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
}

int numSquares(int n){    //coin change problem
    int m, i = 1;
    while(m*m <= n) m++;
    vector<int> dp(m);
    vector<int> res(n+1);

    for(int i = 0; i < m; i++) dp[i] = (i+1)*(i+1);
    for(int i = 0; i < n+1; i++) res[i] = INT_MAX;
    res[0] = 0;

    for(int j = 0; j < m; j++){
        for(int i = 1; i < n+1; i++){
            if(i >= dp[j]){
                if(res[i-dp[j]]+1 < res[i]){
                    res[i] = 1 + res[i-dp[j]];
                }
            }
        }
    }
    printtab(res);
    return res[n];
}

int main(){
    cout << numSquares(12) << endl;
    return 0;
}

