
+++
authors = ["grid47"]
title = "Leetcode 2208: Minimum Operations to Halve Array Sum"
date = "2024-03-31"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2210: Count Hills and Valleys in an Array](https://grid47.xyz/leetcode/solution-2210-count-hills-and-valleys-in-an-array/) |
| --- |
