
+++
authors = ["grid47"]
title = "Leetcode 2208: Minimum Operations to Halve Array Sum"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2208: Minimum Operations to Halve Array Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-operations-to-halve-array-sum/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:

    int halveArray(vector<int>& nums) {
        int n = nums.size();
        double sum = 0;
        priority_queue<double, vector<double>, less<double>> pq;
        for(int i = 0; i < n; i++){
            pq.push(nums[i]);
            sum += nums[i];
        }
        
        sum = sum / 2;
        
        double tmp = 0;
        int cnt = 0;
        while(tmp < sum && !pq.empty()) {

            double x = (pq.top() / 2);
            tmp += x;

            pq.pop();
            pq.push(x);

            cnt++;
        }
        
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2208.md" >}}
---
{{< youtube 4HrGj7pwQww >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2210: Count Hills and Valleys in an Array](https://grid47.xyz/posts/leetcode-2210-count-hills-and-valleys-in-an-array-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
