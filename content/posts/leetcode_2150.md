
+++
authors = ["Crafted by Me"]
title = "Leetcode 2150: Find All Lonely Numbers in the Array"
date = "2018-12-14"
description = "In-depth solution and explanation for Leetcode 2150: Find All Lonely Numbers in the Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2151: Maximum Good People Based on Statements](https://grid47.xyz/posts/leetcode_2151) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

