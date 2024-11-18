
+++
authors = ["grid47"]
title = "Leetcode 646: Maximum Length of Pair Chain"
date = "2024-09-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 646: Maximum Length of Pair Chain in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "LcNNorqMVTw"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/646.webp"
+++



[`Problem Link`](https://leetcode.com/problems/maximum-length-of-pair-chain/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/646.webp" 
    alt="A sequence of pairs where the longest chain is highlighted and softly glowing."
    caption="Solution to LeetCode 646: Maximum Length of Pair Chain Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}

class Solution {
public:

    static bool cmp(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) return a[1] < b[1];
        else return a[0] < b[0];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        
        int n = pairs.size();
        
        vector<int> dp(n, 1);
        int mx = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    mx = max(mx, dp[i]);
                }
            }
        }
        
        return mx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/646.md" >}}
---
{{< youtube LcNNorqMVTw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #647: Palindromic Substrings](https://grid47.xyz/leetcode/solution-647-palindromic-substrings/) |
| --- |
