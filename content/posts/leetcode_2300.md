
+++
authors = ["Crafted by Me"]
title = "Leetcode 2300: Successful Pairs of Spells and Potions"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2300: Successful Pairs of Spells and Potions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potion, long long success) {
        
        int n = spells.size();
        
        vector<int> ans(n, 0);
        
        sort(potion.begin(), potion.end());
        
        for(int i = 0; i < n; i++) {
            
            long long tgt = success % spells[i]? (success/ spells[i]) + 1 : (success/ spells[i]);
            
            ans[i] = potion.end() - lower_bound(potion.begin(), potion.end(), tgt);
        }
        
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube vO6FxLZpKg4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2301: Match Substring After Replacement](https://grid47.xyz/posts/leetcode_2301) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

