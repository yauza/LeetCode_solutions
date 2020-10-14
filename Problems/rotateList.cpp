#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printlist(ListNode* node){
    while(node != nullptr){
        cout << node->val << endl;
    }
    cout << endl;
}


ListNode* rotateRight(ListNode* head, int k) {
    if(k == 0 || head == nullptr) return head;

    ListNode* p = head;
}

int main(){
    ListNode* n1 = new ListNode(1,n2);
    ListNode* n2 = new ListNode(2,n3);
    ListNode* n3 = new ListNode(3,n4);
    ListNode* n4 = new ListNode(4,n5);
    ListNode* n5 = new ListNode(5);
    printlist(n1);
    printlist(rotateRight(n1, 2));
    system("PAUSE");
    return 0;
}






