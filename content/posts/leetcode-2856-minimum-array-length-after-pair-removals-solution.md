
+++
authors = ["grid47"]
title = "Leetcode 2856: Minimum Array Length After Pair Removals"
date = "2024-01-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2856: Minimum Array Length After Pair Removals in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers","Binary Search","Greedy","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-array-length-after-pair-removals/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i : nums){
            mp[i]++;
        }
        int maxi = 0;
        for(auto it : mp){
            maxi = max(maxi, it.second);
        }
        if(maxi <= n/2){
            if(n%2){
                return 1;
            }
            else{
                return 0;
            }
        }
        return 2*maxi - n;
        
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2856.md" >}}
---
{{< youtube 6IPtNE3fIew >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2857: Count Pairs of Points With Distance k](https://grid47.xyz/posts/leetcode-2857-count-pairs-of-points-with-distance-k-solution/) |
| --- |
