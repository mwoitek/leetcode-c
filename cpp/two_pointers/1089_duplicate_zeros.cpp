class Solution
{
public:
  void duplicateZeros(vector<int>& arr)
  {
    auto c = vector<int>(arr);
    auto n = arr.size();
    size_t i = 0;  // arr
    size_t j = 0;  // c
    while (i < n) {
      while (i < n && j < n && c[j]) arr[i++] = c[j++];
      while (i < n && j < n && !c[j]) {
        arr[i++] = 0;
        if (i < n) arr[i++] = 0;
        j++;
      }
    }
  }
};
