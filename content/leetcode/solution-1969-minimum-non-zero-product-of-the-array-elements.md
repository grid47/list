
+++
authors = ["grid47"]
title = "Leetcode 1969: Minimum Non-Zero Product of the Array Elements"
date = "2024-04-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1969: Minimum Non-Zero Product of the Array Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy","Recursion"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "1O57f1H8EyA"
youtube_upload_date="2021-08-15"
youtube_thumbnail="https://i.ytimg.com/vi_webp/1O57f1H8EyA/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long mod = 1000000007;
    
    long long expn(long long n, long long p) {
        if(p == 0) return 1;
        if(p == 1) return n%mod;
        if(p % 2 == 0) {
            long long ans = expn(n, p / 2);
            return ((ans ) * (ans )) % mod;
        } else {
            long long ans = expn(n, p / 2);
            ans = ((ans ) * (ans )) % mod;
            return (ans * (n % mod)) % mod;
        }
        return 0;
    }

    
    int minNonZeroProduct(int p) {
        long long val = pow(2, p);
        val--;
        long long ans = expn(val-1, val/2);
        return ans * (val %mod)% mod;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1969.md" >}}
---
{{< youtube 1O57f1H8EyA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1971: Find if Path Exists in Graph](https://grid47.xyz/leetcode/solution-1971-find-if-path-exists-in-graph/) |
| --- |