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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> v;
        queue<pair<TreeNode *,pair<int,int>>> q;
        map<int,map<int,vector<int>>>m;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode *curr=p.first;
            int x=p.second.first,y=p.second.second;
            m[x][y].push_back(curr->val);
            if(curr->left) q.push({curr->left,{x-1,y+1}});
            if(curr->right) q.push({curr->right,{x+1,y+1}});
        }
        for(auto i:m){
            vector<int> temp;
            for(auto x:i.second){
                sort(x.second.begin(),x.second.end());
                temp.insert(temp.end(),x.second.begin(),x.second.end());
            }
            v.push_back(temp);
        }
        return v;
    }
};