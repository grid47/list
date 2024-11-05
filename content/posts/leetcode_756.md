
+++
authors = ["Crafted by Me"]
title = "Leetcode 756: Pyramid Transition Matrix"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 756: Pyramid Transition Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Hash Table","Depth-First Search","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/pyramid-transition-matrix/description/)

---

**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/756.md" >}}
---
{{< youtube RMkh4P4h7ek >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #757: Set Intersection Size At Least Two](https://grid47.xyz/posts/leetcode_757) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

