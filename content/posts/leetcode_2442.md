
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2442: Count Number of Distinct Integers After Reverse Operations"
date = "2018-02-21"
description = "Solution to Leetcode 2442"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int rev(int num) {
        int res = 0;
        while(num > 0) {
            res = res * 10 + num % 10;
            num /= 10;
        }
        return res;
    }
    
    int countDistinctIntegers(vector<int>& nums) {
        set<int> cnt;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            cnt.insert(nums[i]);
            cnt.insert(rev(nums[i]));
        }
        
        return cnt.size();        
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

