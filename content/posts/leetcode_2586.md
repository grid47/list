
+++
authors = ["Yasir"]
title = "Leetcode 2586: Count the Number of Vowel Strings in Range"
date = "2017-09-30"
description = "Solution to Leetcode 2586"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool check(char s)
    {
        return (s=='a' || s=='e'|| s=='o'|| s=='i' || s=='u');
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++)
        {
            if(check(words[i].front()) && check(words[i].back())) ans++;
        }
        return ans;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

