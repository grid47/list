
+++
authors = ["Crafted by Me"]
title = "Leetcode 1626: Best Team With No Conflicts"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1626: Best Team With No Conflicts in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/best-team-with-no-conflicts/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        vector<pair<int, int>> palyer;
        for(int i = 0; i < n; i++)
        palyer.push_back({ages[i], scores[i]});

        sort(palyer.begin(), palyer.end(), greater<>());
        int ans = 0;
        vector<int> dp(n);
        for(int i = 0; i < n; i++) {
            pair<int, int> young = palyer[i];
            dp[i] = young.second;
            for(int j = 0; j < i; j++) {
                pair<int, int> elder = palyer[j];
                if(young.second <= elder.second)
                dp[i] = max(dp[i], dp[j] + young.second);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1626.md" >}}
---
{{< youtube 7kURH3btcV4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1627: Graph Connectivity With Threshold](https://grid47.xyz/posts/leetcode_1627) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

