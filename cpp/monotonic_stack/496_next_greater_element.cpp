class Solution
{
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
  {
    unordered_map<int, int> a;
    vector<int> s;
    for (int n : nums2) {
      while (s.size() && n > s.back()) {
        a[s.back()] = n;
        s.pop_back();
      }
      s.push_back(n);
    }
    vector<int> ans;
    ans.reserve(nums1.size());
    for (int n : nums1) ans.push_back(a.contains(n) ? a[n] : -1);
    return ans;
  }
};
