
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 128: Longest Consecutive Sequence"
date = "2024-06-24"
description = "Solution to Leetcode 128"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-consecutive-sequence/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(int x: nums)
            s.insert(x);
        if(s.empty()) return 0;
        int mx = 1;
        for(int i = 0; i < nums.size(); i++) {
            int y = nums[i];
            int c = 1;
            if(!s.count(y + 1))
            while(s.count(y - 1)) {
                c++;
                y = y -1;
                mx = max(mx, c);
            }
        }
        return mx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/128.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
