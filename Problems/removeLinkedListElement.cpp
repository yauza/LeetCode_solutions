#include <iostream>

using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



ListNode* removeElements(ListNode* head, int val){
    if(!head) return nullptr;


    while(head->val == val){
        if(head->next == nullptr) return nullptr;
        head = head->next;
    }

    ListNode* prev = head;
    ListNode* ptr = head->next;

    while(ptr){
        if(ptr->val == val){
            ptr = ptr->next;
            prev->next = ptr;
        }else{
        ptr = ptr->next;
        prev = prev->next;
        }
    }

    return head;
}


int main(){


    return 0;
}
