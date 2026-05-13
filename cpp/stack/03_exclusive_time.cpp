class Solution
{
public:
  struct FunCall {
    int id;
    bool start;
    int time;

    FunCall(string& s)
    {
      size_t p1 = 0;
      size_t p2 = s.find(':', p1);
      id = stoi(s.substr(p1, p2));
      p1 = p2 + 1;
      p2 = s.find(':', p1);
      start = s.substr(p1, p2 - p1) == "start";
      p1 = p2 + 1;
      p2 = s.find(':', p1);
      time = stoi(s.substr(p1, p2 - p1));
    }
  };

  vector<int> exclusiveTime(int n, vector<string>& logs)
  {
    auto times = vector<int>(n);
    int dt;
    int t = 0;
    vector<int> s;
    for (auto& l : logs) {
      auto f = FunCall(l);
      if (s.empty()) {
        s.push_back(f.id);
        continue;
      }
      auto id = s.back();
      dt = f.time - t;
      if (f.start) {
        s.push_back(f.id);
      } else {
        dt++;
        s.pop_back();
      }
      times[id] += dt;
      t += dt;
    }
    return times;
  }
};
