
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2670: Find the Distinct Difference Array"
date = "2017-07-10"
description = "Solution to Leetcode 2670"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-distinct-difference-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        map<int, int> l, r;
        for(int i = 0; i < n; i++) {
            r[nums[i]]++;
        }

        for(int i = 0; i < n; i++) {
            r[nums[i]]--;
            if(r[nums[i]] == 0) r.erase(nums[i]);
            l[nums[i]]++;
            ans[i] = l.size() - r.size();
        }
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

