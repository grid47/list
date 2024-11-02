
+++
authors = ["Crafted by Me"]
title = "Leetcode 2404: Most Frequent Even Element"
date = "2017-04-03"
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

{{< highlight cpp >}}
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

