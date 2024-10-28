
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2197: Replace Non-Coprime Numbers in Array"
date = "2018-10-24"
description = "Solution to Leetcode 2197"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/replace-non-coprime-numbers-in-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            
            ans.push_back(nums[i]);
            
            while(ans.size() > 1 && __gcd(ans.back(), ans[ans.size() - 2]) > 1) {
                long long a = ans.back(),
                    b = ans[ans.size() - 2];
                ans.pop_back();
                ans.pop_back();
                ans.push_back(a * b/ __gcd(a, b));
            }
            
        }
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

