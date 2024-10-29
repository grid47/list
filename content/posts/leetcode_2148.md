
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2148: Count Elements With Strictly Smaller and Greater Elements "
date = "2018-12-13"
description = "Solution to Leetcode 2148"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, l = -1, r = -1, n = nums.size();
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) {
              l = i;
              break;
            }
        }
        for(int i = n - 1; i > 0; i--) {
            if(nums[i] > nums[i - 1]) {
              r = i;
              break;
            }
        }
        if(l < r) return r - l;
        return 0;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

