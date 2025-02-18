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
    void find(TreeNode* root, int k, int& ans,int& count){
        if(!root) return;
        find(root->left,k,ans,count);
        count = count+1;
        if(count == k){
            ans = root->val;
            return;
        }
        find(root->right,k,ans,count);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        int ans = 0;
        int count = 0;
        find(root,k,ans,count);
        return ans;
    }
};