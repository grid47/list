
+++
authors = ["grid47"]
title = "Leetcode 926: Flip String to Monotone Increasing"
date = "2024-08-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 926: Flip String to Monotone Increasing in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/flip-string-to-monotone-increasing/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cnt_one = 0, cnt_flip = 0;
        for(char c: s) {
            if(c == '1') cnt_one++;
            else         cnt_flip++;
            cnt_flip = min(cnt_one, cnt_flip);
        }
        return cnt_flip;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/926.md" >}}
---
{{< youtube tMq9z5k3umQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #930: Binary Subarrays With Sum](https://grid47.xyz/posts/leetcode-930-binary-subarrays-with-sum-solution/) |
| --- |
