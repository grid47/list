
+++
authors = ["grid47"]
title = "Leetcode 97: Interleaving String"
date = "2024-10-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 97: Interleaving String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "3Rw3p9LrgvE"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/97.webp"
+++



[`Problem Link`](https://leetcode.com/problems/interleaving-string/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/97.webp" 
    alt="Two glowing strings weaving together in an intricate, peaceful interleaving pattern."
    caption="Solution to LeetCode 97: Interleaving String Problem"
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
    string s1, s2, s3;
    vector<vector<int>> memo;
    bool dp(int i, int j) {
        if(i == s1.size() && j == s2.size()) return true;

        if(memo[i][j] != -1) return memo[i][j];
        int ans = 0;
        int k = i + j;
        if(i < s1.size() && s1[i] == s3[k])
            ans |= dp(i + 1, j);
        
        if(j < s2.size() && s2[j] == s3[k])
            ans |= dp(i, j + 1);
        
        return memo[i][j] = ans;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        if(s1.size() + s2.size() != s3.size()) return false;
        memo.resize(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return dp(0, 0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/97.md" >}}
---
{{< youtube 3Rw3p9LrgvE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #98: Validate Binary Search Tree](https://grid47.xyz/leetcode/solution-98-validate-binary-search-tree/) |
| --- |
