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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        if(!root) return answer;
        TreeNode* cur = root;
        while(cur){
            if(!cur->left) {
                answer.push_back(cur->val); // if does not have left push the answer
                cur = cur->right; // move to right
            }else{
                TreeNode *left = cur->left;
                while(left->right && left->right != cur){
                    left = left->right; // move to the rightest node of left subtree
                }
                if(left -> right == nullptr){ 
                    left->right = cur; // connect the thread
                    cur = cur->left; // then move to the left
                }else{
                    left->right = nullptr; // remove the thread
                    answer.push_back(cur->val); // after removing thread -> add the answer
                    cur = cur->right; // move to right
                }
            }
        }
        return answer;
    }
};