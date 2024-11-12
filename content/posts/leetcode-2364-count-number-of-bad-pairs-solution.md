
+++
authors = ["grid47"]
title = "Leetcode 2364: Count Number of Bad Pairs"
date = "2024-03-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2364: Count Number of Bad Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-number-of-bad-pairs/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long countBadPairs(vector<int>& nums, long cnt = 0) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++)
            cnt += i - mp[i - nums[i]]++;
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2364.md" >}}
---
{{< youtube alyDgY0FCiA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2365: Task Scheduler II](https://grid47.xyz/posts/leetcode-2365-task-scheduler-ii-solution/) |
| --- |
