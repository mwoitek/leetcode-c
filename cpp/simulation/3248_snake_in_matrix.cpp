class Solution
{
public:
  int finalPositionOfSnake(int n, vector<string>& commands)
  {
    int i = 0;
    int j = 0;
    for (const string& cmd : commands) {
      switch (cmd.front()) {
        case 'U':
          i--;
          break;
        case 'R':
          j++;
          break;
        case 'D':
          i++;
          break;
        case 'L':
          j--;
      }
    }
    return i * n + j;
  }
};
