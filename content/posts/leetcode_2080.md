
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2080: Range Frequency Queries"
date = "2019-02-18"
description = "Solution to Leetcode 2080"
tags = [
    
]
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

