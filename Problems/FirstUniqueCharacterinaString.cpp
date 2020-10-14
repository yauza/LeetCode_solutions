#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>

using namespace std;

int firstUniqChar(string s) {
    unordered_map<char,int> hashmap;

    for(int i = 0; i < s.size(); i++){
        if(hashmap.find(s[i]) == hashmap.end()){
            hashmap[s[i]] = 1;
        }else{
            hashmap[s[i]]++;
        }
    }

    for(int i = 0; i < s.size(); i++){
        if(hashmap[s[i]] == 1) return i;
    }

    return -1;
}

int main(){
    cout << firstUniqChar("leetcode") << endl;

    return 0;
}


