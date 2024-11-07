
+++
authors = ["Crafted by Me"]
title = "Leetcode 2521: Distinct Prime Factors of Product of Array"
date = "2024-11-01"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2522: Partition String Into Substrings With Values at Most K](https://grid47.xyz/posts/leetcode_2522) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
