class Solution
{
public:
  vector<int> dailyTemperatures(vector<int>& temperatures)
  {
    auto n = temperatures.size();
    auto answer = vector<int>(n);
    vector<int> s;
    for (int i = 0; i < n; i++) {
      while (s.size() && temperatures[i] > temperatures[s.back()]) {
        int j = s.back();
        s.pop_back();
        answer[j] = i - j;
      }
      s.push_back(i);
    }
    return answer;
  }
};
