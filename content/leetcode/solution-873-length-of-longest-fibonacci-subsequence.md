
+++
authors = ["grid47"]
title = "Leetcode 873: Length of Longest Fibonacci Subsequence"
date = "2024-08-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 873: Length of Longest Fibonacci Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "BWj2qT3aTrA"
youtube_upload_date="2022-08-21"
youtube_thumbnail="https://i.ytimg.com/vi/BWj2qT3aTrA/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> s(arr.begin(), arr.end());
        int res = 2, n = arr.size();

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int a = arr[i], b = arr[j], l = 2;
                while(s.count(a + b))
                b = a + b, a = b - a, l++;
                res = max(res, l);
            }            
        }

        return res > 2? res: 0;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/873.md" >}}
---
{{< youtube BWj2qT3aTrA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #875: Koko Eating Bananas](https://grid47.xyz/leetcode/solution-875-koko-eating-bananas/) |
| --- |