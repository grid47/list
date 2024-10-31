
+++
authors = ["Crafted by Me"]
title = "Leetcode 1073: Adding Two Negabinary Numbers"
date = "2021-11-24"
description = "Solution to Leetcode 1073"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/adding-two-negabinary-numbers/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int carry = 0, i = arr1.size() -1, j = arr2.size() -1;
        vector<int> res;
        while(carry || i >= 0 || j >= 0) {
            if(i >= 0) carry += arr1[i--];
            if(j >= 0) carry += arr2[j--];
            res.push_back(carry&1);
            carry = -(carry>>1);
        }
        while(res.size() > 1 && res.back() == 0)
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

