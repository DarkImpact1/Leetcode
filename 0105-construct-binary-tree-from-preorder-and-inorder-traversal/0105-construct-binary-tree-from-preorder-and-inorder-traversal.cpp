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

    TreeNode* build(vector<int>& preorder,int prestart, int preend, vector<int>& inorder, int instart, int inend, map<int,int>& inmap){

        if(prestart > preend || instart > inend) return nullptr;

        TreeNode* root = new TreeNode(preorder[prestart]);

        int inroot = inmap[root->val];

        int numEleLeft = inroot - instart;

        root->left = build(preorder, prestart+1, prestart + numEleLeft,inorder, instart, inroot-1,inmap);

        root->right = build(preorder,prestart+numEleLeft +1, preend, inorder, inroot+1,inend, inmap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inMap;
        for(int i=0; i<inorder.size(); i++){
            inMap[inorder[i]] = i;
        }

        TreeNode* root = build(preorder,0,preorder.size()-1,
                                inorder,0,inorder.size()-1,inMap);

        return root;
    }
};