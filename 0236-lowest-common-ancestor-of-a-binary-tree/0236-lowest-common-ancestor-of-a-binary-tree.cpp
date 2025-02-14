/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // return null, or p or q if any of them is found
        if(root == NULL || root == p || root == q){
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p,  q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(!left) return right;
        else if(!right) return left;
        // if both left and right is found then you are the the answer
        return root;
    }
};