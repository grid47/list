
+++
authors = ["Crafted by Me"]
title = "Leetcode 2660: Determine the Winner of a Bowling Game"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2660: Determine the Winner of a Bowling Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/determine-the-winner-of-a-bowling-game/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int isWinner(vector<int>& p1, vector<int>& p2) {
        int sc1 = 0, sc2 = 0;
        int n = p1.size();
        for(int i = 0; i < n; i++) {
            if(i > 1 && (p1[i - 1] == 10 || p1[i - 2] == 10)) {
                sc1 += 2 * p1[i];
            } else if(i > 0 && p1[i - 1] == 10){
                sc1 += 2 * p1[i];                
            }
            else sc1 += p1[i];
            if(i > 1 && (p2[i - 1] == 10 || p2[i - 2] == 10)) {
                sc2 += 2 * p2[i];
            }else if(i > 0 && p2[i - 1] == 10){
                sc2 += 2 * p2[i];                
            } else sc2 += p2[i];            
        }
        if(sc1 > sc2) return 1;
        if(sc2 > sc1) return 2;
        return 0;
    }
};
{{< /highlight >}}


---
{{< youtube UzLjzmjhVqs >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2661: First Completely Painted Row or Column](https://grid47.xyz/posts/leetcode_2661) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

