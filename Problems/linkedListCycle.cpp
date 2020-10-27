#include <iostream>
#include <stdlib.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if(head == nullptr || head->next == nullptr) return false;
    ListNode* slow = head;
    ListNode* fast = head->next;

    while(fast != nullptr && slow != nullptr){
        if(slow == fast) return true;
        slow = slow->next;
        if(fast->next && fast->next->next) fast = fast->next->next;
        else return false;
    }

    return false;
}

int main(){


    return 0;
}

