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
    void trackParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> que;
        que.push(root);
        
        while (!que.empty()) {
            TreeNode* front = que.front();
            que.pop();

            if (front->left) {
                parent[front->left] = front;
                que.push(front->left);
            }

            if (front->right) {
                parent[front->right] = front;
                que.push(front->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if (!root) return ans; // Fix #2: Avoid calling trackParent if root is null

        unordered_map<TreeNode*, TreeNode*> parent;
        trackParent(root, parent);
        
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        
        int cur_dist = 0;
        while (!q.empty()) {
            if (cur_dist == k) {
                break;
            }
            cur_dist++; // Increase the distance
            int n = q.size();
            
            for (int i = 0; i < n; i++) {
                TreeNode* front = q.front();
                q.pop();
                
                if (front->left && !visited[front->left]) {
                    visited[front->left] = true;
                    q.push(front->left);
                }

                if (front->right && !visited[front->right]) {
                    visited[front->right] = true;
                    q.push(front->right);
                }

                if (parent.count(front) && !visited[parent[front]]) { // Fix #1: Check if parent exists
                    visited[parent[front]] = true;
                    q.push(parent[front]);
                }
            }
        }

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        
        return ans;
    }

};