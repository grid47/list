
+++
authors = ["grid47"]
title = "Leetcode 1496: Path Crossing"
date = "2024-06-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1496: Path Crossing in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/path-crossing/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0,y=0;
        set<pair<int,int>>s;
        s.insert({0,0});
        for(char p: path){
            if(p == 'N') y++;
            else if(p == 'S')y--;
            else if(p == 'E') x++;
            else x--;
            
            if(s.find({x,y}) != s.end()) return true;
            else s.insert({x,y});
        }
        return false;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1496.md" >}}
---
{{< youtube VWRJBNP7uH8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1497: Check If Array Pairs Are Divisible by k](https://grid47.xyz/leetcode/solution-1497-check-if-array-pairs-are-divisible-by-k/) |
| --- |
