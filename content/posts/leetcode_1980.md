
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1980: Find Unique Binary String"
date = "2019-05-29"
description = "Solution to Leetcode 1980"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-unique-binary-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        int n = nums.size();
        for(int i = 0; i < n; i++)
        ans += nums[i][i] == '0'? '1':'0';
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

