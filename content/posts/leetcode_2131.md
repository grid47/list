
+++
authors = ["Crafted by Me"]
title = "Leetcode 2131: Longest Palindrome by Concatenating Two Letter Words"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2131: Longest Palindrome by Concatenating Two Letter Words in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Greedy","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        int unpaired = 0;
        unordered_map<string, int> mp;

        for(string w: words) {
            if(w[0] == w[1]) {
                if(mp[w] > 0) {
                    unpaired--;
                    ans += 4;
                    mp[w]--;
                } else {
                    unpaired++;
                    mp[w]++;
                }
            } else {
                string rev = w;
                reverse(rev.begin(), rev.end());
                if(mp[rev] > 0) {
                    ans += 4;
                    mp[rev]--;
                } else mp[w]++;
            }
        }


        if (unpaired > 0) ans += 2;
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2131.md" >}}
---
{{< youtube kBMf-m5we-8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2133: Check if Every Row and Column Contains All Numbers](https://grid47.xyz/posts/leetcode_2133) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
