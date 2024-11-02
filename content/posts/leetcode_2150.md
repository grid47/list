
+++
authors = ["Crafted by Me"]
title = "Leetcode 2150: Find All Lonely Numbers in the Array"
date = "2017-12-13"
description = "Solution to Leetcode 2150"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int num: nums) mp[num]++;

        vector<int> res;
        for(auto [x, cnt]: mp) {
            if(cnt == 1 && !mp.count(x - 1) && !mp.count(x +1))
                res.push_back(x);
        }

        return res;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

