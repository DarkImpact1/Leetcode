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
    int countLeft(TreeNode* root){
        int count = 0;
        while(root){
            count++;
            root =  root->left;
        }
        return count;
    }
    int countRight(TreeNode* root){
        int count = 0;
        while(root){
            count++;
            root = root->right;
        }
        return count;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        int lh = countLeft(root);
        int rh = countRight(root);
        
        if( lh == rh) return (1<<lh)-1; // 2^lh -1
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

};