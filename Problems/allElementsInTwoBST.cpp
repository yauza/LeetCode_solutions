#include <iostream>
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

void searchTree(TreeNode* t1, vector<int> &arr){
    if(t1 == nullptr) return;

    if(t1->left) searchTree(t1.left, arr)
    arr.push_back(t1.val)
    if(t1->right != nullptr) searchTree(t1.right, arr)
}

vector<int> mergeArrays(vector<int> t1, vector<int> t2){
    int i = 0, j = 0;

    vector<int> t3;

    while(i < t1.size() && j < t2.size()){
        if(t1[i] < t2[j]){
            t3.push_back(t1[i]);
            i++;
        }else{
            t3.push_back(t2[j]);
            j++;
        }
    }

    while(i < t1.size() && j == t2.size()-1){
        t3.push_back(t1[i]);
        i++;
    }

    while(i == t1.size()-1 && j < t2.size()){
        t3.push_back(t2[j]);
        j++;
    }

    return t3;
}

vector<int> getAllElements(TreeNode *root1, TreeNode *root2){
    vector<int> t1;
    searchTree(root1, t1);

    vector<int> t2;
    t2 = searchTree(root2, t2);

    return mergeArrays(t1, t2);
}


int main(){


    return 0;
}
