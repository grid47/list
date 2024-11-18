
+++
authors = ["grid47"]
title = "Leetcode 2080: Range Frequency Queries"
date = "2024-04-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2080: Range Frequency Queries in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Design","Segment Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "1gZinwGx3lk"
youtube_upload_date="2021-11-21"
youtube_thumbnail="https://i.ytimg.com/vi/1gZinwGx3lk/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/range-frequency-queries/description/)

---
**Code:**

{{< highlight cpp >}}
class RangeFreqQuery {
public:
    map<int, vector<int>> mp;
    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        return upper_bound(mp[value].begin(), mp[value].end(), right) -             
            lower_bound(mp[value].begin(), mp[value].end(), left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2080.md" >}}
---
{{< youtube 1gZinwGx3lk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2086: Minimum Number of Food Buckets to Feed the Hamsters](https://grid47.xyz/leetcode/solution-2086-minimum-number-of-food-buckets-to-feed-the-hamsters/) |
| --- |
