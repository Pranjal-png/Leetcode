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

    vector<vector<int>> solve(TreeNode* root){
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(root == NULL){
            return {};
        }
        if(root!=NULL){
            q.push(root);
        }
        while(!q.empty()){
            int n = q.size();
            vector<int>level;
            for(int i=0 ; i<n ; i++){
                TreeNode* x = q.front();
                q.pop();
                level.push_back(x->val);
                if(x->left!=NULL)
                    q.push(x->left);
                if(x->right!=NULL)
                    q.push(x->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        return solve(root);
    }
};