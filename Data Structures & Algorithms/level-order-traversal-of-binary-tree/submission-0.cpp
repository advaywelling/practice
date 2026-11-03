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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        std::queue<TreeNode*> q;
        int level_size{};
        int level{};
        if (root == nullptr) {}
        else {
            q.push(root);
            while(!q.empty()) {
                level_size = q.size();
                result.emplace_back();
                while (level_size) {
                    TreeNode* curr = q.front();
                    if (curr->left != nullptr) q.push(curr->left);
                    if (curr->right != nullptr) q.push(curr->right);
                    result[level].push_back(q.front()->val);
                    q.pop();
                    level_size--;
                }
                level += 1;
            }
        }
        return result;
    }
};
