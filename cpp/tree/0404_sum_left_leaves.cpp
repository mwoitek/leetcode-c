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
  int rec(TreeNode* n, bool lp)
  {
    if (!n) return 0;
    if (!n->left && !n->right) return lp ? n->val : 0;
    return rec(n->left, true) + rec(n->right, false);
  }

  int sumOfLeftLeaves(TreeNode* root)
  {
    return rec(root, false);
  }
};
