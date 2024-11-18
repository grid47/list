
+++
authors = ["grid47"]
title = "Leetcode 2049: Count Nodes With the Highest Score"
date = "2024-04-16"
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2049.md" >}}
---
{{< youtube 4sOMPJvDX_o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2053: Kth Distinct String in an Array](https://grid47.xyz/leetcode/solution-2053-kth-distinct-string-in-an-array/) |
| --- |
