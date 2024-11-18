
+++
authors = ["grid47"]
title = "Leetcode 1695: Maximum Erasure Value"
date = "2024-05-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1695: Maximum Erasure Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "XIFl0gXnq9s"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/maximum-erasure-value/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int sum = 0, n = nums.size();
        map<int, int> mp;
        
        int mx = 0;
        int j = 0;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
            sum += nums[i];
            
            while(mp[nums[i]] > 1) {
                mp[nums[j]]--;
                sum -= nums[j];
                j++;
            }
            
            mx = max(mx, sum);
        }
        return mx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1695.md" >}}
---
{{< youtube XIFl0gXnq9s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1696: Jump Game VI](https://grid47.xyz/leetcode/solution-1696-jump-game-vi/) |
| --- |
