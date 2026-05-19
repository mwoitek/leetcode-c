class Solution
{
public:
  int getCommon(vector<int>& nums1, vector<int>& nums2)
  {
    vector<int> i;
    set_intersection(begin(nums1),
                     end(nums1),
                     begin(nums2),
                     end(nums2),
                     back_inserter(i));
    return i.size() ? i[0] : -1;
  }
};
