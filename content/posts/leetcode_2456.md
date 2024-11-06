
+++
authors = ["Crafted by Me"]
title = "Leetcode 2456: Most Popular Video Creator"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2456: Most Popular Video Creator in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/most-popular-video-creator/description/)

---

**Code:**

{{< highlight cpp >}}
#define ll long long
class Solution {

    static bool cmp(pair<ll, string> p1, pair<ll, string> p2) {
        if(p1.first == p2.first) return p1.second < p2.second;
        else return p1.first > p2.first;
    }

public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        vector<vector<string>> ans;
        long long n = creators.size(), maxi = INT_MIN;
        map<string, ll> m1;
        map<string, vector<pair<ll, string>>> m2;

        for(int i = 0; i < n; i++) {
            m1[creators[i]] += views[i];
            m2[creators[i]].push_back(make_pair(views[i], ids[i]));
            maxi = max(maxi, m1[creators[i]]);
        }

        for(auto &[l, r] : m1) {
            if(r == maxi) {
                sort(m2[l].begin(), m2[l].end(), cmp);
                ans.push_back({l, m2[l].front().second});
            }
        }
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube 2xvkEXjtmWE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2457: Minimum Addition to Make Integer Beautiful](https://grid47.xyz/posts/leetcode_2457) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
