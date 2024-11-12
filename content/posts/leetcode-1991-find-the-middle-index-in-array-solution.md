
+++
authors = ["grid47"]
title = "Leetcode 1991: Find the Middle Index in Array"
date = "2024-04-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1991: Find the Middle Index in Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-middle-index-in-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);
        for(int i = 0; i < n; i++)
            sum[i + 1] = nums[i] + sum[i];
        
        int net = sum[n];
        
        for(int i = 0; i < n; i++) {
            if(net - sum[i + 1] == sum[i]) return i;
        }
        return -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1991.md" >}}
---
{{< youtube C9PhqirC9vs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1992: Find All Groups of Farmland](https://grid47.xyz/posts/leetcode-1992-find-all-groups-of-farmland-solution/) |
| --- |
