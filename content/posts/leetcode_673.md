
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 673: Number of Longest Increasing Subsequence"
date = "2022-12-27"
description = "Solution to Leetcode 673"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int res = 0, n = nums.size(), max_len = 0;
        vector<int> len(n, 0), cnt(n, 0);
        
        for(int i = 0; i < n; i++) {
            cnt[i] = 1;
            len[i] = 1;
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    if(len[j] + 1 == len[i]) cnt[i] += cnt[j];
                    if(len[j] + 1 >  len[i]) {
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    }
                }   
            }
            if(max_len == len[i]) res += cnt[i];
            if(max_len < len[i]) {
                res = cnt[i];
                max_len = len[i];
            }
            
        }
        
        return res;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/673.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
