
+++
authors = ["grid47"]
title = "Leetcode 1981: Minimize the Difference Between Target and Chosen Elements"
date = "2024-04-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1981: Minimize the Difference Between Target and Chosen Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "cfQFu_VDISI"
youtube_upload_date="2021-08-31"
youtube_thumbnail="https://i.ytimg.com/vi/cfQFu_VDISI/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    vector<vector<int>> mat;
    int memo[4901][70];
    int dp(int idx, int sum, int net) {
        if(idx == mat.size()) return abs(sum - net);
        
        if(memo[sum][idx] != -1) return memo[sum][idx];
        
        int ans = INT_MAX;
        for(int i = 0; i < mat[0].size(); i++)
            ans = min(ans, dp(idx + 1, sum + mat[idx][i], net));
        
        return memo[sum][idx] = ans;
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        this->mat = mat;
        memset(memo, -1, sizeof(memo));
        return dp(0, 0, target);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1981.md" >}}
---
{{< youtube cfQFu_VDISI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1984: Minimum Difference Between Highest and Lowest of K Scores](https://grid47.xyz/leetcode/solution-1984-minimum-difference-between-highest-and-lowest-of-k-scores/) |
| --- |