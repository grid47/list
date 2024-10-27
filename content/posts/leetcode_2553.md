
+++
authors = ["Yasir"]
title = "Leetcode 2553: Separate the Digits in an Array"
date = "2017-11-01"
description = "Solution to Leetcode 2553"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/separate-the-digits-in-an-array/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        
        for(auto x: nums) {
            vector<int> tmp;
            while(x) {
                tmp.push_back(x % 10);
                x /= 10;
            }
            while(!tmp.empty()) {
                ans.push_back(tmp.back());
                tmp.pop_back();
            }
        }
        return ans;
    }
};
{{< /highlight >}}

