class Solution
{
public:
  int evalRPN(vector<string>& tokens)
  {
    vector<int> s;
    int a, b;
    for (auto t : tokens) {
      if (t == "+") {
        b = s.back();
        s.pop_back();
        a = s.back();
        s.pop_back();
        s.push_back(a + b);
      } else if (t == "-") {
        b = s.back();
        s.pop_back();
        a = s.back();
        s.pop_back();
        s.push_back(a - b);
      } else if (t == "*") {
        b = s.back();
        s.pop_back();
        a = s.back();
        s.pop_back();
        s.push_back(a * b);
      } else if (t == "/") {
        b = s.back();
        s.pop_back();
        a = s.back();
        s.pop_back();
        s.push_back(a / b);
      } else {
        s.push_back(stoi(t));
      }
    }
    return s[0];
  }
};
