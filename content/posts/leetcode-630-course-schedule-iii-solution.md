
+++
authors = ["grid47"]
title = "Leetcode 630: Course Schedule III"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 630: Course Schedule III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Heap (Priority Queue)"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/course-schedule-iii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& nums) {
        
        priority_queue<int> pq;
        
        sort(nums.begin(), nums.end(), [&](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
        
        int sum = 0;
        for(auto it: nums) {
            sum += it[0];
            pq.push(it[0]);
            if(sum > it[1]) {
                sum -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/630.md" >}}
---
{{< youtube q_EX4BV4-Cs >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #632: Smallest Range Covering Elements from K Lists](https://grid47.xyz/posts/leetcode-632-smallest-range-covering-elements-from-k-lists-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
