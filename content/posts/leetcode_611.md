
+++
authors = ["Crafted by Me"]
title = "Leetcode 611: Valid Triangle Number"
date = "2023-03-02"
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


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/611.md" >}}
- by gpt
        
---
{{< youtube AZrQMv5ne54 >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

