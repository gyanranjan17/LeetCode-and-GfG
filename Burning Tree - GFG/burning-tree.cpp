//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int minTime(Node* root, int tar) 
    {
        unordered_map<Node*,Node*> par;
        queue<Node*> q;
        q.push(root);
        par[root]=NULL;
        Node *target;
        while(!q.empty()){
            Node*u=q.front();
            q.pop();
            if(u->data==tar) target=u;
            if(u->left){
                par[u->left]=u;
                q.push(u->left);
            }
            if(u->right){
                par[u->right]=u;
                q.push(u->right);
            }
        }
        unordered_map<Node*,bool> vis;
        int lvl=0;
        q.push(target);
        vis[target]=1;
        while(!q.empty()){
            lvl++;
            int sz=q.size();
            while(sz--){
                Node *u=q.front();
                q.pop();
                if(u->left && !vis[u->left]){
                    q.push(u->left);
                    vis[u->left]=1;
                }
                if(u->right && !vis[u->right]){
                    q.push(u->right);
                    vis[u->right]=1;
                }
                if(!vis[par[u]] && par[u]!=NULL){
                    q.push(par[u]);
                    vis[par[u]]=1;
                }
            }
        }
        
        return lvl-1;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends