
+++
authors = ["Crafted by Me"]
title = "Leetcode 1481: Least Number of Unique Integers after K Removals"
date = "2019-10-13"
description = "Solution to Leetcode 1481"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(auto m : arr) mp[m]++;

        sort(begin(arr), end(arr), [&](int x, int y) {
            return mp[x] != mp[y] ? mp[x] < mp[y] : x < y;
        });

        unordered_set<int> st;
        for(int i = k; i < arr.size(); i++) st.insert(arr[i]);

        return st.size();
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

