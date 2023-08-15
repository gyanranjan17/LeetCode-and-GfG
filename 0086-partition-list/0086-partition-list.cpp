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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        ListNode *sm,*gr,*temp=head,*first=NULL,*f=NULL;
        
        while(temp){
            if(temp->val<x){
                if(!first){ 
                    first=new ListNode(temp->val);
                    sm=first;
                }
                else {sm->next=new ListNode(temp->val);sm=sm->next;}
            }
            else{
                if(!f){ 
                    f=new ListNode(temp->val);
                    gr=f;
                }
                else {gr->next=new ListNode(temp->val);gr=gr->next;}
            }
            temp=temp->next;
        }
        if(!first) return f;
        if(!f) return first;
        sm->next=f;
        return first;
    }
};