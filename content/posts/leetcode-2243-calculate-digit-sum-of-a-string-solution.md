
+++
authors = ["grid47"]
title = "Leetcode 2243: Calculate Digit Sum of a String"
date = "2024-03-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2243: Calculate Digit Sum of a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/calculate-digit-sum-of-a-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string digitSum(string s, int k) {
    while(s.size() > k) {
        string s1;
        for (int i = 0; i < s.size(); i += k)
            s1 += to_string(accumulate(begin(s) + i, begin(s) + min((int)s.size(), i + k), 0, 
                [](int n, char ch){ return n + ch - '0'; }));
        swap(s1, s);
    }
    return s;
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2243.md" >}}
---
{{< youtube Lyesi93Z6_A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2245: Maximum Trailing Zeros in a Cornered Path](https://grid47.xyz/posts/leetcode-2245-maximum-trailing-zeros-in-a-cornered-path-solution/) |
| --- |
