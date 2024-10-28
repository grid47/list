
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2161: Partition Array According to Given Pivot"
date = "2018-11-29"
description = "Solution to Leetcode 2161"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/partition-array-according-to-given-pivot/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int low = 0, same = 0, high;
        for(auto num: nums) {
            if(num < pivot) low++;
            else if(num == pivot) same++;
        }
        high = low + same;
        same = low;
        low = 0;
        vector<int> res(nums.size(), 0);
        for(auto num: nums) {
            if(num < pivot) res[low++] = num;
            else if(num == pivot) res[same++] = num;
            else res[high++] = num;
        }
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

