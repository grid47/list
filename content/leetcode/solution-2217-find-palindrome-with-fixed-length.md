
+++
authors = ["grid47"]
title = "Leetcode 2217: Find Palindrome With Fixed Length"
date = "2024-03-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2217: Find Palindrome With Fixed Length in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "yHa83HDgTdk"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/find-palindrome-with-fixed-length/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long reverse(long long n, int skip) {
        long long res = 0;
        for(n = skip?n/10: n; n > 0; n/=10)
            res = res * 10 + n % 10;
        return res;
    }
    
    vector<long long> kthPalindrome(vector<int>& queries, int sz) {
        vector<long long> ans;
        long long start = pow(10, (sz + 1)/2-1), end = pow(10, (sz + 1)/2), mul= pow(10, sz/2);
        for(auto q: queries)
            if(start + q > end)
                ans.push_back(-1);
            else {
                long long res = (start + q - 1) * mul + reverse(start + q - 1, sz % 2);
                ans.push_back(res);
            }
        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2217.md" >}}
---
{{< youtube yHa83HDgTdk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2220: Minimum Bit Flips to Convert Number](https://grid47.xyz/leetcode/solution-2220-minimum-bit-flips-to-convert-number/) |
| --- |
