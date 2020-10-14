#include <iostream>
#include <stdlib.h>
//#include <unordered_map>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void sumOfVal(TreeNode* root, int L, int R, int& sum){
    if(root->val <= R && root->val >= L) sum += root->val;

    if(root->left) sumOfVal(root->left, L, R, sum);
    if(root->right) sumOfVal(root->right, L, R, sum);

    return;
}

int rangeSumBST(TreeNode* root, int L, int R) {
    int sum = 0;
    sumOfVal(root, L, R, sum);
    return sum;
}

int main(){

    return 0;
}





