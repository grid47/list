
+++
authors = ["Crafted by Me"]
title = "Leetcode 2049: Count Nodes With the Highest Score"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2049: Count Nodes With the Highest Score in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-nodes-with-the-highest-score/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<vector<int>> g(n);
        for(int i = 1; i < n; i++)
        g[parents[i]].push_back(i);

        vector<int> size(n, 0);
        helper(0, g, size);

        long long cnt = 0, maxi = 0;
        for(int i = 0; i < n; i++) {
            long long pro = 1;
            pro = max(pro, (long long) n - size[i]);
            for(int node : g[i]) {
                pro = pro * size[node];
            }

            if (pro > maxi) {
                maxi = pro;
                cnt = 1;
            }
            else if(pro == maxi) {
                cnt++;
            }
        }
        return cnt;
    }

    int helper(int src, vector<vector<int>> &gph, vector<int> &size) {
        int ans = 1;
        for(int g: gph[src])
            ans += helper(g, gph, size);
        return size[src] = ans;
    }
};
{{< /highlight >}}


---
{{< youtube 4sOMPJvDX_o >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2050: Parallel Courses III](https://grid47.xyz/posts/leetcode_2050) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
