
+++
authors = ["Crafted by Me"]
title = "Leetcode 1996: The Number of Weak Characters in the Game"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1996: The Number of Weak Characters in the Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/description/)

---

**Code:**

{{< highlight cpp >}}

class Solution {

    public:
    static bool comp(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) {
            return a[1] > b[1];
        } else return a[0] < b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& prpt) {
        sort(prpt.begin(), prpt.end(), comp);
        
        int mn = INT_MIN;
        int ans = 0;
        
        for(int i = prpt.size() - 1; i >= 0; i--) {
            if(prpt[i][1] < mn) ans++;
            mn = max(mn, prpt[i][1]);
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1996.md" >}}
---
{{< youtube DFqwkF9a6KI >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1997: First Day Where You Have Been in All the Rooms](https://grid47.xyz/posts/leetcode_1997) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

