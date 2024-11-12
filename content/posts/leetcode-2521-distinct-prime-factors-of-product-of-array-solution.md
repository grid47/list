
+++
authors = ["grid47"]
title = "Leetcode 2521: Distinct Prime Factors of Product of Array"
date = "2024-02-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2521: Distinct Prime Factors of Product of Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    set<int> cnt;
    
    void fact(int num) {
        while(num % 2 == 0) {
            cnt.insert(2);
            num /= 2;
        }
        for(int i = 3; i <= num; i+=2) {
            while(num % i == 0) {
                cnt.insert(i);
                num /= i;
            }
        }
    }
    
    int distinctPrimeFactors(vector<int>& nums) {
        
        int n = nums.size();
        for(int i = 0; i < n; i++)
            fact(nums[i]);
        
        
        return cnt.size() ;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2521.md" >}}
---
{{< youtube HKc9PcSzNic >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2522: Partition String Into Substrings With Values at Most K](https://grid47.xyz/posts/leetcode-2522-partition-string-into-substrings-with-values-at-most-k-solution/) |
| --- |
