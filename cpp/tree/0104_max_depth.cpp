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
class Solution
{
public:
  int maxDepth(TreeNode* root)
  {
    if (!root) return 0;
    auto dl = maxDepth(root->left);
    auto dr = maxDepth(root->right);
    return 1 + max(dl, dr);
  }
};
