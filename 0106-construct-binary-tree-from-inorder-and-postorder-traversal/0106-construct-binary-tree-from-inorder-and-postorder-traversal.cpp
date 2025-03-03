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
    TreeNode* BT(vector<int>&inorder, int instart, int inend,
                 vector<int>&postorder, int poststart, int postend,
                 map<int,int>& mpp){
        if(instart > inend || poststart > postend) return nullptr;

        TreeNode* root = new TreeNode(postorder[postend]);
        int rootindex = mpp[postorder[postend]];

        int numEleLeft = rootindex - instart;

        root->left = BT(inorder,instart,rootindex-1,
                        postorder,poststart,poststart+numEleLeft-1,
                        mpp);

        root->right = BT(inorder,rootindex+1,inend,
                         postorder,poststart+numEleLeft,postend-1,
                         mpp);

        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()) return nullptr;

        map<int,int> mpp;
        for(int i=0; i<inorder.size(); i++){
            mpp[inorder[i]] = i;
        }
        int instart = 0, inend = inorder.size()-1;
        int poststart = 0, postend = postorder.size()-1;
        return BT(inorder,instart,inend,postorder,poststart,postend,mpp);
    }
};