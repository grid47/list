
+++
authors = ["Crafted by Me"]
title = "Leetcode 1904: The Number of Full Rounds You Have Played"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1904: The Number of Full Rounds You Have Played in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/the-number-of-full-rounds-you-have-played/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfRounds(string login, string logout) {
        
        int in = (((login[0] - '0') * 10 + (login[1]- '0')) * 60) + ((login[3] - '0') * 10 + (login[4] - '0'));
        int out = (((logout[0] - '0') * 10 + (logout[1]- '0')) * 60) + ((logout[3] - '0') * 10 + (logout[4] - '0'));
        // cout << in << " " << out;
        int cnt = 0;
        if(in > out) {
            for(int i = 0; i < 24 * 60; i += 15) {
                if(i + 15 <= out || i >= in) cnt++;
            }
            return cnt;
        }

        for(int i = 0; i < 24 * 60; i += 15) {
            // cout << "\n" << i; 
            if(i >= in && (i + 15) <= out) cnt++;
        }
        return cnt;
        
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1904.md" >}}
---
{{< youtube kwvB82HHvoQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1905: Count Sub Islands](https://grid47.xyz/posts/leetcode_1905) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

