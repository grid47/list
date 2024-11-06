class Solution {
public:
    bool parseBoolExpr(string e) {
  if (e.size() == 1) return e == "t" ? true : false;
  if (e[0] == '!') return !parseBoolExpr(e.substr(2, e.size() - 3));
  bool isAnd = e[0] == '&' ? true : false, res = isAnd;
  for (auto i = 2, j = 2, cnt = 0; res == isAnd && i < e.size(); ++i) {
    if (e[i] == '(') ++cnt;
    if (e[i] == ')') --cnt;      
    if (i == e.size() - 1 || (e[i] == ',' && cnt == 0)) {
      if (isAnd) res &= parseBoolExpr(e.substr(j, i - j));
      else res |= parseBoolExpr(e.substr(j, i - j));
      j = i + 1;
    }
  }
  return res;
}
};