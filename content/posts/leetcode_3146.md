
+++
authors = ["Yasir"]
title = "Leetcode 3146: Permutation Difference between Two Strings"
date = "2016-03-18"
description = "Solution to Leetcode 3146"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/permutation-difference-between-two-strings/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int sum=0;
        for(int i=0;i<s.length();i++)
        {
            for(int j=0;j<t.length();j++)
            {
                if(s[i]==t[j])
                 sum+=abs(i-j);
            }
        }
        return sum;
    }
};
{{< /highlight >}}

