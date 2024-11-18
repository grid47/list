
+++
authors = ["grid47"]
title = "Leetcode 1404: Number of Steps to Reduce a Number in Binary Representation to One"
date = "2024-06-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1404: Number of Steps to Reduce a Number in Binary Representation to One in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numSteps(string s) {
        
        int idx = s.size() - 1, cnt = 0;
        
        while(idx > 0) {
            if(s[idx] == '0') {
                cnt++;
                idx--;
            } else {
                int tmp = idx;
                while(idx >= 0 && s[idx] == '1') idx--;
                cnt++; // add one
                if(idx >= 0) {
                    s[idx] = '1';
                    cnt += (tmp-idx); // divide by 2
                } else {
                    cnt += (tmp-idx);
                }
            }
        }
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1404.md" >}}
---
{{< youtube qxt7_HD8Cag >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1405: Longest Happy String](https://grid47.xyz/leetcode/solution-1405-longest-happy-string/) |
| --- |
