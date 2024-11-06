
+++
authors = ["Crafted by Me"]
title = "Leetcode 2080: Range Frequency Queries"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2080: Range Frequency Queries in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Design","Segment Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
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


---
{{< youtube 1gZinwGx3lk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2081: Sum of k-Mirror Numbers](https://grid47.xyz/posts/leetcode_2081) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
