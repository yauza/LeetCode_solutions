#include <iostream>
#include <vector>

using namespace std;

int maxPower(string s) {
    int res = 1, longest = 1;

    for(int i = 1; i < s.size(); i++){
        if(s[i-1] == s[i]) longest++;
        else longest = 1;
        res = max(res, longest);
    }

    return res;
}

int main(){
    string s = "leetcode";
    string s1 = "hooraaaaaaaaaaay";
    cout << maxPower("a") << endl;
    return 0;
}
