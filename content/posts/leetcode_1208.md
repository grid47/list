
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1208: Get Equal Substrings Within Budget"
date = "2021-07-09"
description = "Solution to Leetcode 1208"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/get-equal-substrings-within-budget/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int equalSubstring(string s, string t, int mxc) {
        vector<int> nums(s.size(), 0);
        for(int i = 0; i < s.size(); i++) {
            nums[i] = abs(s[i] - t[i]);
        }
        int res = 0, j = 0;
        for(int i = 0; i < nums.size(); i++) {
            mxc -= nums[i];
            while(mxc < 0) {
                mxc += nums[j++];
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

