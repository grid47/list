
+++
authors = ["grid47"]
title = "Leetcode 2654: Minimum Number of Operations to Make All Array Elements Equal to 1"
date = "2024-02-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2654: Minimum Number of Operations to Make All Array Elements Equal to 1 in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "9LOYxdctbs0"
youtube_upload_date="2023-04-23"
youtube_thumbnail="https://i.ytimg.com/vi/9LOYxdctbs0/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int minOperations(vector<int>& nums) {


        int cnt = 0;
        
        for(int x: nums) if (x == 1) cnt++;
        if(cnt > 0) return nums.size() - cnt;
        
        int t = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            int last = nums[i];
            for(int j = i + 1; j < nums.size(); j++) {
                last = __gcd(last, nums[j]);
                if(last == 1) {
                    t = min(t, j - i);
                }
            }
        }
        
        
        return t == INT_MAX? -1: t + nums.size() - 1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2654.md" >}}
---
{{< youtube 9LOYxdctbs0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2656: Maximum Sum With Exactly K Elements ](https://grid47.xyz/leetcode/solution-2656-maximum-sum-with-exactly-k-elements/) |
| --- |
