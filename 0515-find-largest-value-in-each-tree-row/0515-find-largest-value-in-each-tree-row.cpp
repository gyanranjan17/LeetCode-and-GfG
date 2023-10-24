/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        while(!q.empty()){
            int sz=q.size();
            int temp=INT_MIN;
            while(sz--){
                TreeNode* u=q.front();
                q.pop();
                temp=max(temp,u->val);
                if(u->left) q.push(u->left);
                if(u->right) q.push(u->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};