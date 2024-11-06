
+++
authors = ["Crafted by Me"]
title = "Leetcode 2217: Find Palindrome With Fixed Length"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2217: Find Palindrome With Fixed Length in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
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


---
{{< youtube yHa83HDgTdk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2218: Maximum Value of K Coins From Piles](https://grid47.xyz/posts/leetcode_2218) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

