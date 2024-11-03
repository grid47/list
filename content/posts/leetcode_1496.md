
+++
authors = ["Crafted by Me"]
title = "Leetcode 1496: Path Crossing"
date = "2020-09-28"
description = "In-depth solution and explanation for Leetcode 1496: Path Crossing in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1497: Check If Array Pairs Are Divisible by k](https://grid47.xyz/posts/leetcode_1497) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

