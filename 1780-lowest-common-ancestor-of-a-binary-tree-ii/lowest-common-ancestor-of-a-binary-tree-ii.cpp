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
    bool found_p = false, found_q = false;

    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;

        TreeNode* left = LCA(root->left, p, q);
        TreeNode* right = LCA(root->right, p, q);
        if ((root == p || root == q) || (left != nullptr && right != nullptr)) {
            if (root == p) {
                found_p = true;
            }
            else if (root == q) {
                found_q = true;
            }
            return root;
        }
        if (left != nullptr) {
            return left;
        }
        if (right != nullptr) {
            return right;
        }
        return nullptr;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ancestor = LCA(root, p, q);
        if (found_p && found_q)
            return ancestor;
        return nullptr;
    }
};