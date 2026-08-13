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

    int solve(TreeNode* root , int &ans){
        if(root== NULL){
            return 0;
        }

        int leftres = solve(root->left , ans);
        int rightres = solve(root->right , ans);

        int leftval = max(0 , leftres);
        int rightval = max(0, rightres);

        ans = max(ans , root->val + leftval + rightval);
        return root->val + max(leftval,rightval);
    }
    int maxPathSum(TreeNode* root) {
        int ans = root->val;
        solve(root,ans);
        return ans;
    }
};