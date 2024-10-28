
+++
authors = ["Yasir"]
title = "Leetcode 2465: Number of Distinct Averages"
date = "2018-01-29"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

