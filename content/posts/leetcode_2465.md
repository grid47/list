
+++
authors = ["Crafted by Me"]
title = "Leetcode 2465: Number of Distinct Averages"
date = "2017-02-01"
description = "Solution to Leetcode 2465"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-distinct-averages/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        map<long, int> mp;
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        while(i < j){
            int a = nums[j--];
            int b = nums[i++];
            long c = a + b;
            mp[c] = 1;
        }
        return mp.size();
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

