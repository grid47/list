
+++
authors = ["Crafted by Me"]
title = "Leetcode 1358: Number of Substrings Containing All Three Characters"
date = "2021-02-12"
description = "Solution to Leetcode 1358"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfSubstrings(string s) {
        return atmost(s, 3) - atmost(s, 2);
    }
    int atmost(string s, int k) {
        map<char, int> ma;
        int res = 0, j = 0;
        for(int i = 0; i < s.size(); i++) {
            ma[s[i]]++;
            if(ma[s[i]] == 1) k--;
            while(k < 0) {
                ma[s[j]]--;
                if(ma[s[j]] == 0) k++;
                j++;
            }
            res += (i - j + 1);
        }
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

