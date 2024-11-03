
+++
authors = ["Crafted by Me"]
title = "Leetcode 2300: Successful Pairs of Spells and Potions"
date = "2018-07-17"
description = "In-depth solution and explanation for Leetcode 2300: Successful Pairs of Spells and Potions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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
| Next : [LeetCode #2301: Match Substring After Replacement](https://grid47.xyz/posts/leetcode_2301) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

