class Solution
{
public:
  bool isValid(string s)
  {
    vector<char> st;
    for (char c : s) {
      switch (c) {
        case '(':
        case '[':
        case '{':
          st.push_back(c);
          break;
        case ')':
        case ']':
        case '}':
          if (st.empty()) return false;
          char b1 = st.back();
          char b2 = c - (c == ')' ? 1 : 2);
          if (b1 != b2) return false;
          st.pop_back();
          break;
      }
    }
    return st.empty();
  }
};
