
+++
authors = ["Crafted by Me"]
title = "Leetcode 2243: Calculate Digit Sum of a String"
date = "2024-11-01"
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


---
{{< youtube Lyesi93Z6_A >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2244: Minimum Rounds to Complete All Tasks](https://grid47.xyz/posts/leetcode_2244) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
