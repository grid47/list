
+++
authors = ["grid47"]
title = "Leetcode 1952: Three Divisors"
date = "2024-04-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1952: Three Divisors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Enumeration","Number Theory"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/three-divisors/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isThree(int n) {
    int d = 2;
    for (int i = 2; i < n && d <= 3; i += 1)
        d += n % i == 0;
    return d == 3;
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1952.md" >}}
---
{{< youtube Rl-JOgrVru0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1957: Delete Characters to Make Fancy String](https://grid47.xyz/posts/leetcode-1957-delete-characters-to-make-fancy-string-solution/) |
| --- |
