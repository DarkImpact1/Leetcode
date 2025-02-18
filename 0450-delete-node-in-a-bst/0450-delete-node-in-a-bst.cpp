class Solution {
public:

    TreeNode* findLastRight(TreeNode* root){
        while (root->right) {
            root = root->right;
        }
        return root;
    }

    // This function merges the last right node of the left subtree to the right subtree
    TreeNode* join(TreeNode* root) {
        if (!root->left) {
            return root->right; // If no left child, return right child
        }
        if (!root->right) {
            return root->left;  // If no right child, return left child
        }

        // Find the last right node of the left subtree
        TreeNode* lastRight_Left = findLastRight(root->left);
        lastRight_Left->right = root->right;  // Attach the right subtree

        return root->left;  // Return new root
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (root->val == key) {
            return join(root);  // If root itself needs to be deleted
        }

        TreeNode* curr = root;
        while (curr) {
            if (curr->val > key) {  // Move to left subtree
                if (curr->left && curr->left->val == key) {
                    curr->left = join(curr->left);  // Delete node and reattach
                    break;
                } else {
                    curr = curr->left;
                }
            } else {  // Move to right subtree
                if (curr->right && curr->right->val == key) {
                    curr->right = join(curr->right);  // Delete node and reattach
                    break;
                } else {
                    curr = curr->right;
                }
            }
        }
        return root;
    }
};
