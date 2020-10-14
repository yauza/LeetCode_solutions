
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

int maxScore(string s){
    int k = 0, score = INT_MIN;
    vector<int> ones(s.size());

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1') k++;
    }

    if(k == s.size() || k == 0) return s.size()-1;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1'){
            ones[i] = k;
            k--;
        }
    }
    printv(ones);
    k = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0' && i < s.size()-1) k++;
        cout << s[i] << " " << k << endl;
        if(i > 0) score = max(score, k + ones[i]);
        //score = max(score, k + ones[i]);
    }

    return score;
}

int main(){
    string s = "111000";
    cout << maxScore(s) << endl;
    system("PAUSE");
    return 0;
}



