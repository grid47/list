
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1726: Tuple with Same Product"
date = "2020-02-07"
description = "Solution to Leetcode 1726"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/tuple-with-same-product/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int, int> mp;
        
        int n = nums.size(), res = 0;
        
        for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++) {
            int x = nums[i] * nums[j];
            if(mp.count(x)) res+=mp[x];
            mp[x]++;
        }
        return res * 8;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

