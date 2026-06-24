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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)return nullptr;
        ListNode* odd=head;ListNode* even=head->next;ListNode* k=even;int i=1;
        ListNode* temp=nullptr;
        if(head->next)temp=head->next->next;
        while(temp){
            if(i%2){
                odd->next=temp;
                odd=temp;
                temp=temp->next;
            }else{
                even->next=temp;
                even=temp;
                temp=temp->next;
            }
            even->next=nullptr;
            i++;
        }
        odd->next=k;
        return head;
    }
};