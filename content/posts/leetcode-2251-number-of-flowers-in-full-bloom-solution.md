
+++
authors = ["grid47"]
title = "Leetcode 2251: Number of Flowers in Full Bloom"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2251: Number of Flowers in Full Bloom in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Sorting","Prefix Sum","Ordered Set"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-flowers-in-full-bloom/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flo, vector<int>& peo) {
        
        sort(flo.begin(), flo.end());

        vector<pair<int, int>> pp;
        
        for(int i = 0; i < peo.size(); i++) {
            pp.push_back(make_pair(peo[i], i));
        }

        sort(pp.begin(), pp.end());        
        
        vector<int> ans(peo.size(), 0);
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int j = 0;
        for(int i = 0; i < peo.size(); i++) {

            while(!pq.empty() && pp[i].first > pq.top()) {
                // cout << pq.top() << ',';
                pq.pop();
            }
            // cout << '-';            
            
            while(j < flo.size() && pp[i].first >= flo[j][0]) {
                // cout << flo[j][1] << ',';
                if (pp[i].first <= flo[j][1])
                pq.push(flo[j][1]);
                j++;
            }
            // cout << '_';
            // cout << pp[i].first;
            // cout << '\n';
            
            ans[pp[i].second] = pq.size();
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2251.md" >}}
---
{{< youtube zY3Uty9IwvY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2255: Count Prefixes of a Given String](https://grid47.xyz/posts/leetcode-2251-number-of-flowers-in-full-bloom-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
