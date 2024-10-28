
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 611: Valid Triangle Number"
date = "2023-02-26"
description = "Solution to Leetcode 611"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/valid-triangle-number/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int cnt = 0, n = nums.size();
        
        for(int i = n - 1; i >= 0; i--)
            for(int j = 0, k = i - 1; j < k;) {
                if(nums[i] < nums[j] + nums[k]) {
                    cnt+= k - j;
                    k--;
                } else j++;
            }
        
        return cnt;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

