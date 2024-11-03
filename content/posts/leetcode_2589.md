
+++
authors = ["Crafted by Me"]
title = "Leetcode 2589: Minimum Time to Complete All Tasks"
date = "2017-10-01"
description = "In-depth solution and explanation for Leetcode 2589: Minimum Time to Complete All Tasks in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


---


"| 2590: Design a Todo List |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

