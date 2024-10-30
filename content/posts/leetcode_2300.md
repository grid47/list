
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2300: Successful Pairs of Spells and Potions"
date = "2018-07-15"
description = "Solution to Leetcode 2300"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

