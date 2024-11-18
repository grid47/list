
+++
authors = ["grid47"]
title = "Leetcode 1824: Minimum Sideway Jumps"
date = "2024-05-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1824: Minimum Sideway Jumps in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "IDTzmXD5H58"
youtube_upload_date="2021-04-11"
youtube_thumbnail="https://i.ytimg.com/vi/IDTzmXD5H58/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-sideway-jumps/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> memo;
    int dp(int cur, int idx, vector<int> &obs) {

        if(idx == obs.size()) return 0;
        if(memo[cur][idx] != -1) return memo[cur][idx];
        if(obs[idx] == cur) return INT_MAX - 1;
        
        int ans = dp(cur, idx + 1, obs);

        int left  = (cur - 1 + 1) % 3 + 1;
        int right = (cur - 1 + 2) % 3 + 1;
        
        if(obs[idx] != left) {
            ans = min(ans, dp(left, idx + 1, obs) + 1);
        }
        if(obs[idx] != right) {
            ans = min(ans, dp(right, idx + 1, obs) + 1);
        }
        return memo[cur][idx] = ans;
    }
    
    int minSideJumps(vector<int>& obs) {
        
        int n = obs.size();
        int cur = 2, idx = 0;
        
        memo.resize(4, vector<int>(n + 1, -1));
        
        return dp(cur, idx, obs);
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1824.md" >}}
---
{{< youtube IDTzmXD5H58 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1827: Minimum Operations to Make the Array Increasing](https://grid47.xyz/leetcode/solution-1827-minimum-operations-to-make-the-array-increasing/) |
| --- |
