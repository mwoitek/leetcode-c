class Solution
{
public:
  bool rec(vector<int>& arr, int i, vector<bool>& visited)
  {
    if (visited[i]) return false;
    if (!arr[i]) return true;
    visited[i] = true;
    int j = i + arr[i];
    if (j < arr.size() && rec(arr, j, visited)) return true;
    int k = i - arr[i];
    if (k >= 0 && rec(arr, k, visited)) return true;
    return false;
  }

  bool canReach(vector<int>& arr, int start)
  {
    auto visited = vector<bool>(arr.size(), false);
    return rec(arr, start, visited);
  }
};
