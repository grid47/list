
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1493: Longest Subarray of 1's After Deleting One Element"
date = "2020-09-27"
description = "Solution to Leetcode 1493"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int longestSubarray(vector<int>& nums) {
        
        int ans = 0;
        
        int n = nums.size();
        
        int k = 1;
        
        int j = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) k--;
            
            while(k < 0) {
                if(nums[j] == 0)
                    k++;
                j++;
            }
            ans = max(ans, i - j);
        }
        
        /*
        i - j mean one elment will be cut from [j, i] closed interval
        what k does is, make that element a zero.
        */

        return ans;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

