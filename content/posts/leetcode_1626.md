
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1626: Best Team With No Conflicts"
date = "2020-05-18"
description = "Solution to Leetcode 1626"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
