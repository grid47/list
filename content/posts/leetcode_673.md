
+++
authors = ["Yasir"]
title = "Leetcode 673: Number of Longest Increasing Subsequence"
date = "2022-12-26"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

