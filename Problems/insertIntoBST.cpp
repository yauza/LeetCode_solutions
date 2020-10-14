#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(!root){
        TreeNode* newNode = new TreeNode(val);
        return newNode;
    }

    if(val > root->val){
        root->right = insertIntoBST(root->right, val);
    }else{
        root->left = insertIntoBST(root->left, val);
    }

    return root;
}


int main(){

    return 0;
}


