/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==nullptr or head==nullptr)return nullptr;
        ListNode*slow=head;ListNode* fast=head;
        ListNode*prev=nullptr;
        while(fast!=NULL and fast->next!=NULL){
            prev=slow;
            fast=(fast->next)->next;
            slow=slow->next;
        }
        if(slow->next==NULL)prev->next=nullptr;
        else{
            prev->next=slow->next;
        }
        return head;
    }
};