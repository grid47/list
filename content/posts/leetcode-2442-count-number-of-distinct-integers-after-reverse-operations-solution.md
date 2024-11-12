
+++
authors = ["grid47"]
title = "Leetcode 2442: Count Number of Distinct Integers After Reverse Operations"
date = "2024-03-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2442: Count Number of Distinct Integers After Reverse Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int rev(int num) {
        int res = 0;
        while(num > 0) {
            res = res * 10 + num % 10;
            num /= 10;
        }
        return res;
    }
    
    int countDistinctIntegers(vector<int>& nums) {
        set<int> cnt;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            cnt.insert(nums[i]);
            cnt.insert(rev(nums[i]));
        }
        
        return cnt.size();        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2442.md" >}}
---
{{< youtube YQ_8I9TmsyA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2443: Sum of Number and Its Reverse](https://grid47.xyz/posts/leetcode-2443-sum-of-number-and-its-reverse-solution/) |
| --- |
