
+++
authors = ["grid47"]
title = "Leetcode 2586: Count the Number of Vowel Strings in Range"
date = "2024-02-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2586: Count the Number of Vowel Strings in Range in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2586.md" >}}
---
{{< youtube mHra3okBpdQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #2587: Rearrange Array to Maximize Prefix Score](https://grid47.xyz/posts/leetcode-2587-rearrange-array-to-maximize-prefix-score-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
