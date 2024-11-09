
+++
authors = ["grid47"]
title = "Leetcode 2589: Minimum Time to Complete All Tasks"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2589: Minimum Time to Complete All Tasks in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Stack","Greedy","Sorting"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-time-to-complete-all-tasks/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [&](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });

        int n = tasks.size(), res = 0;
        vector<bool> line(2001, false);
        for(int i = 0; i < n; i++) {
            int st = tasks[i][0], ed = tasks[i][1], cnt = tasks[i][2];
            cnt -= count(line.begin() + st, line.begin() + ed + 1, true);

            for(int i = ed; cnt > 0; i--) {
                cnt -= !line[i];
                line[i] = true;
            }

        }

        return count(line.begin(), line.end(), true);
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2589.md" >}}
---
{{< youtube oK101s3U4GE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2591: Distribute Money to Maximum Children](https://grid47.xyz/posts/leetcode-2589-minimum-time-to-complete-all-tasks-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
