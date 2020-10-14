#include <iostream>
#include <stdlib.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* mergeLists(ListNode* l1, ListNode* l2){

    ListNode* p = nullptr;

    if(l1->val < l2->val){
        p = l1;
        l1 = l1->next;
    }else{
        p = l2;
        l2 = l2->next;
    }

    ListNode* res = p;

    while(l1 && l2){
        if(l1->val < l2->val){
            res->next = l1;
            l1 = l1->next;
        }else{
            res->next = l2;
            l2 = l2->next;
        }
        res = res->next;
    }

    if(l1) res->next = l1;
    else res->next = l2;


    return p;
}


ListNode* sortList(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* slow = head;
    ListNode* fast = head->next;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* secHead = slow->next;
    slow->next = nullptr;
    head = sortList(head);
    secHead = sortList(secHead);
    return mergeLists(head, secHead);

}

 void printlist(ListNode* p){

    while(p != nullptr){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
 }

int main(){
    ListNode* p1 = new ListNode(3);
    ListNode* p2 = new ListNode(2, p1);

    ListNode* k1 = new ListNode(8);
    ListNode* k2 = new ListNode(6, k1);

    printlist(p2);
    printlist(k2);

    printlist(mergeLists(p2, k2));
    return 0;
}
