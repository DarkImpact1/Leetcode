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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        if(!root) return ans;
        queue<pair<TreeNode*,int>> q;// will store Node,index
        q.push({root,0});
        while(!q.empty()){
            int n = q.size();
            long long mini_ind = q.front().second;
            long long first = 0, last = 0; // to track the index of leftest node and rightest node of that level;
            for(int i =0; i<n; i++){
                long long curr_mini_ind = q.front().second - mini_ind;
                TreeNode* node = q.front().first;
                q.pop();
                if(i == 0) first = curr_mini_ind; // update first as index of first node of that level
                if(i == n-1) last = curr_mini_ind; // update last as index of last node of that level

                if(node->left) q.push({node->left, 2*curr_mini_ind +1});
                if(node->right) q.push({node->right, 2*curr_mini_ind + 2});
            }
            ans = max(ans,int(last-first+1));
        }
        return ans;
    }
};