
+++
authors = ["grid47"]
title = "Leetcode 2542: Maximum Subsequence Score"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2542: Maximum Subsequence Score in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-subsequence-score/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<pair<int, int>> nums;
    int n;
    priority_queue<int, vector<int>, greater<int>> pq;

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

        n = nums2.size(); 
        for(int i = 0; i < n; i++)
            nums.push_back({nums2[i], nums1[i]});
        
        sort(nums.rbegin(), nums.rend());
        
        long long score = 0, sum = 0;

        for(auto& [n2, n1]: nums) {
            
            pq.push(n1);
            sum += n1;
            
            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            
            if(pq.size() == k)
            score = max(score, sum * n2);
        }

        return score;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2542.md" >}}
---
{{< youtube vJ7ZWmfO1Rw >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2543: Check if Point Is Reachable](https://grid47.xyz/posts/leetcode-2543-check-if-point-is-reachable-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}