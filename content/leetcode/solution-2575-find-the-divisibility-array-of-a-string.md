
+++
authors = ["grid47"]
title = "Leetcode 2575: Find the Divisibility Array of a String"
date = "2024-02-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2575: Find the Divisibility Array of a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "kizI7M64xXQ"
youtube_upload_date="2023-02-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/kizI7M64xXQ/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/find-the-divisibility-array-of-a-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.size();
        vector<int> ans(n, 0);
        long num = 0;
        for(int i = 0; i < n; i++) {
            num = num * 10 + (word[i] - '0');
            num %= m;
            if(num % m == 0) ans[i] = 1;
            else ans[i] = 0;
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2575.md" >}}
---
{{< youtube kizI7M64xXQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2576: Find the Maximum Number of Marked Indices](https://grid47.xyz/leetcode/solution-2576-find-the-maximum-number-of-marked-indices/) |
| --- |