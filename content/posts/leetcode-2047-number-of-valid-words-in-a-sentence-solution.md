
+++
authors = ["grid47"]
title = "Leetcode 2047: Number of Valid Words in a Sentence"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2047: Number of Valid Words in a Sentence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-valid-words-in-a-sentence/description/)

---
**Code:**

{{< highlight cpp >}}
// Time: O(N)
// Space: O(N)
class Solution {
    bool valid(string &s) {
        int hyphen = 0, N = s.size();
        for (int i = 0; i < N; ++i) {
            if (isdigit(s[i])) return false; // no digit
            if (isalpha(s[i])) continue; // skip letters
            if (s[i] == '-') {
                if (++hyphen > 1) return false; // at most one hyphen allowed
                if (i - 1 < 0 || !isalpha(s[i - 1]) || i + 1 >= N || !isalpha(s[i + 1])) return false; // hyphen must be surrounded by letters
            } else if (i != N - 1) return false; // punctuation, if any, must be the last character of token
        }
        return true;
    }
public:
    int countValidWords(string s) {
        string w;
        istringstream ss(s);
        int ans = 0;
        while (ss >> w) ans += valid(w);
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2047.md" >}}
---
{{< youtube sl4thQAqnJg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2048: Next Greater Numerically Balanced Number](https://grid47.xyz/posts/leetcode-2048-next-greater-numerically-balanced-number-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}