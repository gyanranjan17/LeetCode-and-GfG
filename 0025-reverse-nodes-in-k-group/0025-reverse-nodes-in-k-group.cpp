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
    ListNode* rev(ListNode *head,int k){
        ListNode *temp=head,*prev=NULL,*n;
        while(temp && k--){
            
            n=temp->next;
            temp->next=prev;
            prev=temp;
            temp=n;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *prev=new ListNode(0),*t,*n,*curr=head,*ans;
        int c=0,sz=0;
        while(curr){
            curr=curr->next;
            sz++;
        }
        curr=NULL;
        c=sz/k;
        bool first=1;
        while(head && c--){
            curr=head;
            int ki=k;
            while(head && ki--){
                head=head->next;
            }
            n=head;
            t= rev(curr,k);
            curr->next=n;
            prev->next=t;
            prev=curr;
            if(first) {
                ans=t;
                
                first=0;
            }
        }
        return ans;
    }
};