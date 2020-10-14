#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char,int> hashmap;
    int res = 0, i = 0, ctr = 0;

    while(i < s.size()){
        if(hashmap.find(s[i]) == hashmap.end()){
            hashmap[s[i]] = 1;
            ctr++;
        }else{
            i -= (ctr);
            ctr = 0;
            hashmap.clear();
            //hashmap[s[i]] = 1;
        }
        i++;
        res = max(res, ctr);
    }

    return res;
}


int main(){
    string s = "abcabcbb";
    string s1 = "bbbbbb";
    cout << lengthOfLongestSubstring(s1) << endl;

    return 0;
}





