
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2537: Count the Number of Good Subarrays"
date = "2017-11-18"
description = "Solution to Leetcode 2537"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-the-number-of-good-subarrays/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long res = 0, tmp = 0;
        
        int n = nums.size();
        
        map<int, int> mp, cnt;
        
        int j = 0;
        for(int i = 0; i < n; i++) {
            tmp += (cnt[nums[i]]);
            cnt[nums[i]]++;            
            while(j <= i && tmp >= k) {
                res+= (n - i);
                cnt[nums[j]]--;
                tmp -= cnt[nums[j]];
                j++;
            }
        }
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

