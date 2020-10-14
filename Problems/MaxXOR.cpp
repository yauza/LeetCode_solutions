#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath>

using namespace std;


class Trie{
public:
    Trie* right;
    Trie* left;
    Trie(){
        left = right = nullptr;
    }

    ~Trie(){
        if(right) delete right;
        if(left) delete left;
    }

};

Trie* insert_to_Trie(int n, Trie* root){
        Trie* current = root;

        for(int i = 31; i >= 0; --i){
            if((n >> i) & 1){
                if(!current->right){
                    current->right = new Trie();
                }
                current = current->right;
            }else{
                if(!current->left) {
                    current->left = new Trie();
                }
                current = current->left;
            }
        }
        return root;
    }

int findMaxXOR(Trie* root, vector<int> nums){

        int res = INT_MIN;
        for(int j = 0; j < nums.size(); ++j){
            Trie* current = root;
            int val = nums[j];
            int maxVal = 0;
            for(int i = 31; i >= 0; --i){
                if(((val >> i) & 1) == 0){
                    if(current->right){
                            maxVal += pow(2,i);
                            current = current->right;
                    }
                    else current = current->left;
                }else{
                    if(current->left){
                            maxVal += pow(2, i);
                            current = current->left;
                    }
                    else current = current->right;
                }
            }
            res = max(res, maxVal);

        }
       // maxVal = max(INT_MIN, maxVal);
        return res;
    }



int findMaximumXOR(vector<int>& nums){
    Trie* trie = new Trie();
    int res = 0;

    for(auto i : nums){
        trie = insert_to_Trie(i, trie);
    }


    return findMaxXOR(trie, nums);
}

int main(){
    vector<int> nums{2, 4, 3};
    cout << findMaximumXOR(nums);


    return 0;
}
