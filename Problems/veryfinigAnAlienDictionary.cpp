#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <vector>

using namespace std;

bool compareWords(string w1, string w2, unordered_map<char,int> hashmap){   //unnecessary
    int i = 0, j = 0;

    while(i < w1.size() && j < w2.size()){
        //cout << hashmap[w1[i]] << " " << hashmap[w2[j]] << endl;
        if(hashmap[w1[i]] < hashmap[w2[j]]) return true;
        else if(hashmap[w1[i]] > hashmap[w2[j]]) return false;
        else{
            i++;
            j++;
        }
    }

    if(i == w1.size()) return true;
    else return false;
}


bool isAlienSorted(vector<string>& words, string order) {
    unordered_map<char, int> hashmap;

    for(int i = 0; i < order.size(); i++){
        hashmap[order[i]] = i;
    }

    int i = 0;
    while(i < words.size()-1){
        if(words[i] == words[i+1]) i++;
        int a = 0, b = 0;
        while(a < words[i].size() && b < words[i+1].size()){
            if(hashmap[words[i][a]] < hashmap[words[i+1][b]]) break;
            else if(hashmap[words[i][a]] > hashmap[words[i+1][b]]) return false;
            else{
                a++;
                b++;
            }
        }

        if(b == words[i+1].size()) return false;
        i++;
        //if(compareWords(words[i], words[i+1], hashmap)) i++;
        //else return false;
    }

    return true;
}


int main(){
    vector<string> words{"h","hello", "leetcode"};
    vector<string> words1{"word", "world", "row"};
    string order = "hlabcdefgijkmnopqrstuvwxyz";
    string order1 = "worldabcefghijkmnpqstuvxyz";
    if(isAlienSorted(words, order)) cout << "TRUE" << endl;
    else cout << "FALSE" << endl;

    return 0;
}






