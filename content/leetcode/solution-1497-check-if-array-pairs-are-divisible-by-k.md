
+++
authors = ["grid47"]
title = "Leetcode 1497: Check If Array Pairs Are Divisible by k"
date = "2024-06-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1497: Check If Array Pairs Are Divisible by k in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "lLEmqIblivA"
youtube_upload_date="2020-06-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/lLEmqIblivA/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> frq(k, 0);
        for(int num : arr) {
            num %= k;
            if (num < 0) num += k;
            frq[num]++;
        }
        if(frq[0]%2 != 0) return false;
        for(int i = 1; i <= k/2; i++)
            if(frq[i] != frq[k - i]) return false;
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1497.md" >}}
---
{{< youtube lLEmqIblivA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1498: Number of Subsequences That Satisfy the Given Sum Condition](https://grid47.xyz/leetcode/solution-1498-number-of-subsequences-that-satisfy-the-given-sum-condition/) |
| --- |