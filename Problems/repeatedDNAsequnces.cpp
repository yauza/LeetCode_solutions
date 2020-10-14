#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;


class Trie{
    public:
    int val;
    Trie* dna[4];

    Trie(){
        this->val = 0;
        for(int i = 0; i < 4; i++) this->dna[i] = nullptr;
    }

};


vector<string> findRepeatedDnaSequences(string s) {

}



int main(){


    return 0;
}

