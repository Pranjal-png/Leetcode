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
    long long prev = LLONG_MIN;
    bool solve(TreeNode* root){
        if(root==NULL){
            return true;
        }
        if(!solve(root->left)){
            return false;
        }
        if(!(root->val > prev)){
            return false;
        }
        prev = root->val;
        
        if(!solve(root->right)){
            return false;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        prev = LLONG_MIN;
        return solve(root);
        
    }
};