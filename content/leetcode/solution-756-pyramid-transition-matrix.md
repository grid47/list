
+++
authors = ["grid47"]
title = "Leetcode 756: Pyramid Transition Matrix"
date = "2024-08-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 756: Pyramid Transition Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Bit Manipulation","Depth-First Search","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/756.webp"
youtube = "RMkh4P4h7ek"
youtube_upload_date="2019-11-13"
youtube_thumbnail="https://i.ytimg.com/vi_webp/RMkh4P4h7ek/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/pyramid-transition-matrix/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/756.webp" 
    alt="A pyramid structure where transitions occur, with the valid transitions glowing softly as they are made."
    caption="Solution to LeetCode 756: Pyramid Transition Matrix Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #762: Prime Number of Set Bits in Binary Representation](https://grid47.xyz/leetcode/solution-762-prime-number-of-set-bits-in-binary-representation/) |
| --- |