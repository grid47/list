
+++
authors = ["grid47"]
title = "Leetcode 786: K-th Smallest Prime Fraction"
date = "2024-08-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 786: K-th Smallest Prime Fraction in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/k-th-smallest-prime-fraction/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>> pq;

        for(int i = 0; i < n; i++)
        pq.push(make_pair(-1.0*arr[i]/arr[n - 1], make_pair(i, n - 1)));
        int i, j;        
        while(k--) {
            auto p = pq.top().second; pq.pop();
            i = p.first;
            j = p.second;
            pq.push(make_pair(-1.0*arr[i]/arr[j-1], make_pair(i, j - 1)));
        }
        return vector<int>{arr[i], arr[j]};
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/786.md" >}}
---
{{< youtube sJdJTXhxqjo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #787: Cheapest Flights Within K Stops](https://grid47.xyz/posts/leetcode-787-cheapest-flights-within-k-stops-solution/) |
| --- |
