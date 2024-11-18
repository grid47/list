
+++
authors = ["grid47"]
title = "Leetcode 3044: Most Frequent Prime"
date = "2024-01-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3044: Most Frequent Prime in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Matrix","Counting","Enumeration","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "vyLo_FMR3IU"
youtube_upload_date="2024-02-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/vyLo_FMR3IU/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/most-frequent-prime/description/)

---
**Code:**

{{< highlight cpp >}}
char sieve[1000001] = {};
class Solution {
public:
    int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
    int dy[8] = {1, 0, -1, 1, 0, -1, 1, -1};
    void make() {
        sieve[1] = 1;
        for (int i = 2; i < 1000001; i++) {
            if (!sieve[i]) for (int j = 2*i; j < 1000001; j += i) sieve[j] = 1;
        }
    } 
    int mostFrequentPrime(vector<vector<int>>& mat) {
        if (sieve[1] == 0) make();
        map<int, int> freq;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                for (int k = 0; k < 8; k++) {
                    int a = i, b = j;
                    int cur = 0;
                    while (a >= 0 && b >= 0 && a < mat.size() && b < mat[i].size()) {
                        cur *= 10;
                        cur += mat[a][b];
                        if(cur>10 && sieve[cur] == 0) freq[cur]++;
                        a += dx[k]; b += dy[k];
                    }
                }
            }
        }
        int mx = -1;
        int ans = -1;
        for (auto i : freq) {
            if(i.second >= mx) {
                ans = i.first;
                mx = i.second;
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3044.md" >}}
---
{{< youtube vyLo_FMR3IU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #3046: Split the Array](https://grid47.xyz/leetcode/solution-3046-split-the-array/) |
| --- |
