
+++
authors = ["Crafted by Me"]
title = "Leetcode 2521: Distinct Prime Factors of Product of Array"
date = "2017-12-07"
description = "Solution to Leetcode 2521"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    set<int> cnt;
    
    void fact(int num) {
        while(num % 2 == 0) {
            cnt.insert(2);
            num /= 2;
        }
        for(int i = 3; i <= num; i+=2) {
            while(num % i == 0) {
                cnt.insert(i);
                num /= i;
            }
        }
    }
    
    int distinctPrimeFactors(vector<int>& nums) {
        
        int n = nums.size();
        for(int i = 0; i < n; i++)
            fact(nums[i]);
        
        
        return cnt.size() ;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

