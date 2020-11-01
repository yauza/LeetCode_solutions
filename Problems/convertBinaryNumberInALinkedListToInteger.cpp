#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printlist(ListNode* head){
    while(head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int getDecimalValue(ListNode* head) {
    int res = 0;

    while(head != nullptr){
        if(head->val == 0) res = res << 1;
        else{
            res = res << 1;
            res = (res | 1);
        }
        //cout << res << " " << head->val << endl;
        head = head->next;
    }

    return res;
}

int main(){
    ListNode* p1 = new ListNode(0);
    ListNode* p2 = new ListNode(1, p1);
    ListNode* p3 = new ListNode(1, p2);
    ListNode* p4 = new ListNode(0, p3);
    ListNode* p5 = new ListNode(1, p4);
    printlist(p5);
    cout << getDecimalValue(p5) << endl;
    return 0;
}
