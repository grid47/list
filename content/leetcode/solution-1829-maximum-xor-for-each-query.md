
+++
authors = ["grid47"]
title = "Leetcode 1829: Maximum XOR for Each Query"
date = "2024-05-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1829: Maximum XOR for Each Query in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-xor-for-each-query/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int bit) {
        int ui = 0;
        for(int x : nums)
            ui ^= x;
        int msk = (1 << bit) - 1;
        
        
        

        
        int res = ui ^ msk;
        vector<int> ans;
        ans.push_back(res);
        while(nums.size() > 1) {
            
            res ^= nums.back();
            nums.pop_back();
            ans.push_back(res);
            
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1829.md" >}}
---
{{< youtube AIGDFYa4aWM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1832: Check if the Sentence Is Pangram](https://grid47.xyz/leetcode/solution-1832-check-if-the-sentence-is-pangram/) |
| --- |
