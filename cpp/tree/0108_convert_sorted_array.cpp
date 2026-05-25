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
  TreeNode* insert(TreeNode* n, int v)
  {
    if (!n) return new TreeNode(v);
    if (v <= n->val)
      n->left = insert(n->left, v);
    else
      n->right = insert(n->right, v);
    return n;
  }

  TreeNode* insert_from_array(TreeNode* n, vector<int>& nums, int i, int j)
  {
    if (i > j) return nullptr;
    auto m = i + (j - i) / 2;
    n = insert(n, nums[m]);
    n->left = insert_from_array(n->left, nums, i, m - 1);
    n->right = insert_from_array(n->right, nums, m + 1, j);
    return n;
  }

  TreeNode* sortedArrayToBST(vector<int>& nums)
  {
    return insert_from_array(nullptr, nums, 0, nums.size() - 1);
  }
};
