
+++
authors = ["grid47"]
title = "Leetcode 2840: Check if Strings Can be Made Equal With Operations II"
date = "2024-01-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2840: Check if Strings Can be Made Equal With Operations II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "yc9CXLWctOU"
img_src = ""
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2841: Maximum Sum of Almost Unique Subarray](https://grid47.xyz/leetcode/solution-2841-maximum-sum-of-almost-unique-subarray/) |
| --- |
