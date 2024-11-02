
+++
authors = ["Crafted by Me"]
title = "Leetcode 2161: Partition Array According to Given Pivot"
date = "2017-12-02"
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

