
+++
authors = ["Yasir"]
title = "Leetcode 786: K-th Smallest Prime Fraction"
date = "2022-09-02"
description = "Solution to Leetcode 786"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/k-th-smallest-prime-fraction/description/)

---

**Code:**

{{< highlight html >}}
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

