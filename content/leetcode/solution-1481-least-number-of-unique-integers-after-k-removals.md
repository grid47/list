
+++
authors = ["grid47"]
title = "Leetcode 1481: Least Number of Unique Integers after K Removals"
date = "2024-06-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1481: Least Number of Unique Integers after K Removals in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Sorting","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Nsp_ta7SlEk"
youtube_upload_date="2024-02-16"
youtube_thumbnail="https://i.ytimg.com/vi/Nsp_ta7SlEk/maxresdefault.jpg"
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1481.md" >}}
---
{{< youtube Nsp_ta7SlEk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1482: Minimum Number of Days to Make m Bouquets](https://grid47.xyz/leetcode/solution-1482-minimum-number-of-days-to-make-m-bouquets/) |
| --- |