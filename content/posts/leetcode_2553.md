
+++
authors = ["Crafted by Me"]
title = "Leetcode 2553: Separate the Digits in an Array"
date = "2016-11-05"
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

{{< highlight cpp >}}
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

