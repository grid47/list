
+++
authors = ["grid47"]
title = "Leetcode 1626: Best Team With No Conflicts"
date = "2024-05-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1626: Best Team With No Conflicts in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Sorting"]
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1630: Arithmetic Subarrays](https://grid47.xyz/leetcode/solution-1630-arithmetic-subarrays/) |
| --- |
