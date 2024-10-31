
+++
authors = ["Crafted by Me"]
title = "Leetcode 2654: Minimum Number of Operations to Make All Array Elements Equal to 1"
date = "2017-07-27"
description = "Solution to Leetcode 2654"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
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



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

