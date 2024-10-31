
+++
authors = ["Crafted by Me"]
title = "Leetcode 992: Subarrays with K Different Integers"
date = "2022-02-13"
description = "Solution to Leetcode 992"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/subarrays-with-k-different-integers/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k -1);
    }
    
    int atmost(vector<int>& nums, int k) {
        
        int res = 0, j = 0;
        map<int, int> ma;
        for(int i = 0; i < nums.size(); i++) {
            ma[nums[i]]++;
            if(ma[nums[i]] == 1) k--;
            
            while(k < 0) {
                ma[nums[j]]--;
                if(ma[nums[j]] == 0) k++;
                j++;
            }
            res += (i - j + 1);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/992.md" >}}
---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

