
+++
authors = ["Yasir"]
title = "Leetcode 2404: Most Frequent Even Element"
date = "2018-03-31"
description = "Solution to Leetcode 2404"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/most-frequent-even-element/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> mp;
        for(auto n: nums) mp[n]++;
        int ans = -1, mx = -1;
        for(auto m: mp){
            if(m.first%2 == 0 && m.second > mx){
                mx = m.second;
                ans = m.first;
            }
        }
        return ans;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

