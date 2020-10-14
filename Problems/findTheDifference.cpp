#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <vector>

using namespace std;


char findTheDifference(string s, string t) {
    unordered_map<char, int> hashmap;
    char res;

    for(int i = 0; i < s.size(); i++){
        if(hashmap.find(s[i]) == hashmap.end()){
            hashmap[s[i]] = 1;
        }else{
            hashmap[s[i]]++;
        }
    }

    for(int i = 0; i < t.size(); i++){
        if(hashmap.find(t[i]) == hashmap.end()){
            res = t[i];
            return res;
        }else{
            hashmap[t[i]]--;
        }
    }


    for(int i = 0; i < t.size(); i++){
        if(hashmap[t[i]] < 0){
            res = t[i];
            break;
        }
    }
    return res
}


int main(){
    string s = "abcde";
    string t = "eabdca";
    cout << findTheDifference(s, t);
    return 0;
}


