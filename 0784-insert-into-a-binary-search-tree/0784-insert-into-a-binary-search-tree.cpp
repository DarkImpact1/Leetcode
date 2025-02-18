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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        TreeNode* start = root;
        while(start){
            if(start->val < val){
                if(start->right) start = start->right;
                else{
                    start->right = new TreeNode(val);
                    break;
                }
            }else{
                if(start ->left){
                    start = start->left;
                }else{
                    start->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};