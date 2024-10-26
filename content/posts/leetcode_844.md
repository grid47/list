
+++
authors = ["Yasir"]
title = "Leetcode 844: Backspace String Compare"
date = "2022-07-06"
description = "Solution to Leetcode 844"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/backspace-string-compare/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.length() - 1, j = T.length() - 1, back;
        while (true) {
            back = 0;
            while (i >= 0 && (back > 0 || S[i] == '#')) {
                back += S[i] == '#' ? 1 : -1;
                i--;
            }
            back = 0;
            while (j >= 0 && (back > 0 || T[j] == '#')) {
                back += T[j] == '#' ? 1 : -1;
                j--;
            }
            if (i >= 0 && j >= 0 && S[i] == T[j]) {
                i--;
                j--;
            } else {
                break;
            }
        }
        return i == -1 && j == -1;        
    }
};
{{< /highlight >}}

