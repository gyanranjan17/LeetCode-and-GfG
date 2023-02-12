//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
    bool isPrime(int x){
        if(x==1) return 0;
        if(x==2 || x==3) return 1;
        if(x%2==0 || x%3==0) return 0;
        for(int i=5;i*i<=x;i=i+6){
            if(x%i==0 || x%(i+2)==0)
            return 0;
        }
        return 1;
    }
    Node *primeList(Node *head){
        Node *y=head;
        while(head){
            int i=head->val,j=head->val;
            while(isPrime(i)==0)
            i--;
            while(isPrime(j)==0)
            j++;
            
            if(head->val-i>j-head->val)
                head->val=j;
            else
            head->val=i;
            head=head->next;
        }
        return y;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends