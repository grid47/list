
+++
authors = ["grid47"]
title = "Leetcode 2300: Successful Pairs of Spells and Potions"
date = "2024-03-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2300: Successful Pairs of Spells and Potions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sorting"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2300.md" >}}
---
{{< youtube vO6FxLZpKg4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2304: Minimum Path Cost in a Grid](https://grid47.xyz/posts/leetcode-2304-minimum-path-cost-in-a-grid-solution/) |
| --- |
