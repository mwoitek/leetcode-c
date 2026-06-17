/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */

class Spreadsheet
{
private:
  unordered_map<string, int> data;

  int getCellValue(string& cell)
  {
    return data[cell];
  }

public:
  Spreadsheet(int rows) {}

  void resetCell(string cell)
  {
    auto it = data.find(cell);
    if (it != data.end()) data.erase(it);
  }

  void setCell(string cell, int value)
  {
    if (value == 0)
      resetCell(cell);
    else
      data[cell] = value;
  }

  int getValue(string formula)
  {
    auto i = formula.find('+', 1);
    auto x = formula.substr(1, i - 1);
    auto y = formula.substr(i + 1);
    int valX = isalpha(x.front()) ? getCellValue(x) : stoi(x);
    int valY = isalpha(y.front()) ? getCellValue(y) : stoi(y);
    return valX + valY;
  }
};
