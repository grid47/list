
+++
authors = ["grid47"]
title = "Leetcode 2730: Find the Longest Semi-Repetitive Substring"
date = "2024-02-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2730: Find the Longest Semi-Repetitive Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-longest-semi-repetitive-substring/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        
        vector<int> sem(10, 0);
        int cnt = 0;
        
        int j = 0, len = 1;        
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i - 1]) {
                cnt++;
                sem[s[i] - '0']++;
            }
            while(cnt > 1 && j < i) {
                if(s[j] == s[j + 1]) {
                    sem[s[j] - '0']--;
                    cnt--;
                }
                j++;
            }
            len = max(len, i - j + 1);
        }
        return len;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2730.md" >}}
---
{{< youtube x_tHB_M7a_g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2731: Movement of Robots](https://grid47.xyz/posts/leetcode-2731-movement-of-robots-solution/) |
| --- |
