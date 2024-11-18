
+++
authors = ["grid47"]
title = "Leetcode 416: Partition Equal Subset Sum"
date = "2024-09-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 416: Partition Equal Subset Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "ZFuagJEpeEU"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/416.webp"
+++



[`Problem Link`](https://leetcode.com/problems/partition-equal-subset-sum/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/416.webp" 
    alt="A set of numbers with glowing partitions, showing how they can be divided into equal subsets."
    caption="Solution to LeetCode 416: Partition Equal Subset Sum Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> nums;
    int memo[201][10001];
    
    bool dp(int idx, int sum) {
        
        if(idx == nums.size()) return sum == 0;
        
        if(memo[idx][sum] != -1) return memo[idx][sum];
        
        bool res = dp(idx + 1, sum);
        
        if(sum >= nums[idx])
            res |= dp(idx + 1, sum - nums[idx]);
        
        return memo[idx][sum] = res;
        
    }
    
    bool canPartition(vector<int>& nums) {
        this->nums = nums;
        int sum = 0;
        for(int x: nums)
            sum += x;
        
        if(sum & 1) return false;
        
        sum = sum / 2;
        
        memset(memo, -1, sizeof(memo));
        
        return dp(0, sum);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/416.md" >}}
---
{{< youtube ZFuagJEpeEU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #417: Pacific Atlantic Water Flow](https://grid47.xyz/leetcode/solution-417-pacific-atlantic-water-flow/) |
| --- |
