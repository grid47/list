
+++
authors = ["Crafted by Me"]
title = "Leetcode 2249: Count Lattice Points Inside a Circle"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2249: Count Lattice Points Inside a Circle in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-lattice-points-inside-a-circle/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countLatticePoints(vector<vector<int>>& cir) {
        set<int> cnt;
        
        for(auto it: cir) {
            
            for(int i = it[0] - it[2]; i <= it[0] + it[2]; i++)
            for(int j = it[1] - it[2]; j <= it[1] + it[2]; j++)                
                if((i - it[0]) * (i - it[0]) + (j - it[1]) * (j - it[1]) <= (it[2] * it[2]))
                    cnt.insert(i * 1000 + j);
            
        }
        return cnt.size();
    }
};
{{< /highlight >}}


---
{{< youtube HCLinlC-JWY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2250: Count Number of Rectangles Containing Each Point](https://grid47.xyz/posts/leetcode_2250) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

