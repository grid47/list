
+++
authors = ["grid47"]
title = "Leetcode 1035: Uncrossed Lines"
date = "2024-07-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1035: Uncrossed Lines in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "TFBZKlASq3g"
youtube_upload_date="2023-05-11"
youtube_thumbnail="https://i.ytimg.com/vi/TFBZKlASq3g/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/uncrossed-lines/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int m, n;
    vector<int> nums1, nums2;
    vector<vector<int>> memo;

    int dp(int i, int j) {
        if(i == m || j == n) return 0;
        
        if(memo[i][j] != -1) return memo[i][j];
        
        int ans = INT_MIN;
        if(nums1[i] == nums2[j]) {
            ans = 1 + dp(i + 1, j + 1);
            return ans;
        }
        ans = max(dp(i + 1, j), dp(i, j + 1));
        return memo[i][j] = ans;
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        m = nums1.size(), n = nums2.size();
        memo.resize(m+1, vector<int>(n+1, -1));
        
        return dp(0, 0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1035.md" >}}
---
{{< youtube TFBZKlASq3g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1038: Binary Search Tree to Greater Sum Tree](https://grid47.xyz/leetcode/solution-1038-binary-search-tree-to-greater-sum-tree/) |
| --- |
