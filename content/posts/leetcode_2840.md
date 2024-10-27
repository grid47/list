
+++
authors = ["Yasir"]
title = "Leetcode 2840: Check if Strings Can be Made Equal With Operations II"
date = "2017-01-18"
description = "Solution to Leetcode 2840"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/description/)

---

**Code:**

{{< highlight html >}}
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

