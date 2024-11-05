
+++
authors = ["Crafted by Me"]
title = "Leetcode 1947: Maximum Compatibility Score Sum"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1947: Maximum Compatibility Score Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-compatibility-score-sum/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        vector<int> pos;
        int ans = 0;
        for(int i = 0; i < students.size(); i++)
            pos.push_back(i);
        do {

            int curr = 0;
            for(int i = 0; i < students.size(); i++)
            for(int j = 0; j < students[pos[i]].size(); j++)
                curr += (students[pos[i]][j] == mentors[i][j]);
            ans = max(ans, curr);

        } while(next_permutation(pos.begin(), pos.end()));
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1947.md" >}}
---
{{< youtube HinLw7adoH8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1948: Delete Duplicate Folders in System](https://grid47.xyz/posts/leetcode_1948) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

