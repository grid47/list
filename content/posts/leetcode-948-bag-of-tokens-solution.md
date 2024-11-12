
+++
authors = ["grid47"]
title = "Leetcode 948: Bag of Tokens"
date = "2024-08-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 948: Bag of Tokens in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/bag-of-tokens/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int res = 0, pts = 0, i = 0, j = tokens.size() - 1;
        while(i <= j) {
            if(power >= tokens[i]) {
                power -= tokens[i++];
                res = max(res, ++pts);
            } else if(pts > 0) {
                power += tokens[j--];
                pts--;
            } else break;
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/948.md" >}}
---
{{< youtube prI82maTivg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #949: Largest Time for Given Digits](https://grid47.xyz/posts/leetcode-949-largest-time-for-given-digits-solution/) |
| --- |
