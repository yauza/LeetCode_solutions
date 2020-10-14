#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

// "131012" - 4
// 1 3 10 1 2, 13 10 1 2, 13 10 12, 1 3 10 12

int numDecodings(string s) {
    int z = 0, res = 0;
    while(s[z] == '0') z++;
    vector<int> dp;

    for(int i = z; i < s.size(); i++) dp.push_back(0);
    dp[0] = 1;

    for(int i = z+1; i < s.size(); i++){
        if(s[i] != '0'){
            cout << ((s[i-1]-'0')*10 + (s[i]-'0')) << endl;
            if((s[i-1]-'0')*10 + (s[i]-'0') <= 26) dp[i] = 1 + dp[i-1];
            else dp[i] = d
        }
    }

    return res;
}


int main(){
    string s;
    cin >> s;
    cout << numDecodings(s) << endl;
    return 0;
}

