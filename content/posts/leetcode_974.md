
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 974: Subarray Sums Divisible by K"
date = "2022-03-02"
description = "Solution to Leetcode 974"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/subarray-sums-divisible-by-k/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int res = 0, n = nums.size(), sum = 0;        
        vector<int> frq(k, 0);
        frq[0] = 1;
        for(int j = 0; j < n; j++) {
            sum += nums[j];
            int rm = sum % k;
            if(rm < 0) rm += k;            
            res += frq[rm];
            frq[rm]++;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/974.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

