
+++
authors = ["Crafted by Me"]
title = "Leetcode 2840: Check if Strings Can be Made Equal With Operations II"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2840: Check if Strings Can be Made Equal With Operations II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkStrings(string s1, string s2) {

int map[2][26] = {0}; // Initialize a 2D array with all elements set to 0

for (int i = 0; i < s1.length(); i++) {
    map[i % 2][s1[i] - 'a']++;
    map[i % 2][s2[i] - 'a']--;
}

for (int i = 0; i < 26; i++) {
    if (map[0][i] != 0 || map[1][i] != 0) return false;
}

return true;}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2840.md" >}}
---
{{< youtube yc9CXLWctOU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2841: Maximum Sum of Almost Unique Subarray](https://grid47.xyz/posts/leetcode_2841) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
