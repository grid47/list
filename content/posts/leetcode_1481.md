
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1481: Least Number of Unique Integers after K Removals"
date = "2020-10-11"
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
{{< youtube nan >}}
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

