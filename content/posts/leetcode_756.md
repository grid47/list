
+++
authors = ["Yasir"]
title = "Leetcode 756: Pyramid Transition Matrix"
date = "2022-10-02"
description = "Solution to Leetcode 756"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/pyramid-transition-matrix/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    
    unordered_set<string> invalid;

  bool pyramidTransition(string bottom, vector<string>& allowed) {
      invalid.clear();
    unordered_map<string, vector<char>> m;
    for(auto& s:allowed) m[s.substr(0, 2)].push_back(s.back());
    return helper(bottom, m, 0, "");
  }

  bool helper(string bottom, unordered_map<string, vector<char>>& m, int start, string next){

    if(bottom.size() == 1) return true;
    else if(invalid.find(bottom) != invalid.end()) return false;
    else if(start == (int)bottom.size() - 1) {
           bool res = helper(next, m, 0, "");
           if (!res) { invalid.insert(next); }
           return res;
       }
    for(char c : m[bottom.substr(start, 2)])
      if(helper(bottom, m, start+1, next+c)) return true;

    return false;
  }
};
{{< /highlight >}}

