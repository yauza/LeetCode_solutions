#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

void printv(vector<int> v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
}

string removeDuplicateLetters(string s) {
    vector<int> letters(26,0);
    vector<int> used(26,0);
    for(int i = 0; i < s.size(); i++) letters[s[i]-'a']++;
    string res = "";
    //printv(used);
    for(auto l : s){
        letters[l-'a']--;
        if(used[l-'a']++ > 0) continue;

        while(!res.empty() && res.back() > l && letters[res.back()-'a'] > 0){
            used[res.back()-'a'] = 0;
            res.pop_back();
        }
        res.push_back(l);
        cout << res << endl;
    }

    return res;
}

int main(){
    string s = "cbacdcbc";
    cout << removeDuplicateLetters(s) << endl;
    return 0;
}
