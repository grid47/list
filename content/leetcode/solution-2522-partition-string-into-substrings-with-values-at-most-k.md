
+++
authors = ["grid47"]
title = "Leetcode 2522: Partition String Into Substrings With Values at Most K"
date = "2024-02-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2522: Partition String Into Substrings With Values at Most K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "XQh9V8PEIiI"
youtube_upload_date="2023-01-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/XQh9V8PEIiI/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string str;
    vector<map<int, int>> mem;
    
    int dp(int idx, int k, int num) {
        
        if(idx == str.size()) return 1;
        
        if(mem[idx].count(num)) return mem[idx][num];

        int ans = 1 + dp(idx + 1, k, str[idx] - '0');

        long long net = (long long)num * 10 + (str[idx] - '0');
        if(net <= k) {
            ans = min(ans, dp(idx + 1, k, net));
        }

        return mem[idx][num] = ans;
    }
    
    int minimumPartition(string s, int k) {
        str = s;
        for(char x: s)
            if(x - '0' > k) return -1;
        mem.resize(s.size());
        int ans = dp(0, k, 0);
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2522.md" >}}
---
{{< youtube XQh9V8PEIiI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2523: Closest Prime Numbers in Range](https://grid47.xyz/leetcode/solution-2523-closest-prime-numbers-in-range/) |
| --- |
