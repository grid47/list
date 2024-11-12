
+++
authors = ["grid47"]
title = "Leetcode 2150: Find All Lonely Numbers in the Array"
date = "2024-04-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2150: Find All Lonely Numbers in the Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2150.md" >}}
---
{{< youtube oX00CiVJ00Q >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2154: Keep Multiplying Found Values by Two](https://grid47.xyz/posts/leetcode-2154-keep-multiplying-found-values-by-two-solution/) |
| --- |
