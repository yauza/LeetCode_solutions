#include <iostream>

using namespace std;

class Trie {
public:
    Trie() {
        for(int i = 0; i < 26; ++i){
            next[i] = nullptr;
        }
        word = "";
    }

    void insert(string word) {

    }

    bool search(string word) {
        for(i : word){

        }
    }

    bool startsWith(string prefix) {

    }
private:
    Trie* next[26];
    string word;
};

int main(){


    return 0;
}
