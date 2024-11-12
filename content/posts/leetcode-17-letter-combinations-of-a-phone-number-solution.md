
+++
authors = ["grid47"]
title = "Leetcode 17: Letter Combinations of a Phone Number"
date = "2024-11-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 17: Letter Combinations of a Phone Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/17.webp" 
    alt="A swirling constellation of letters, with gentle connections forming phone number combinations."
    caption="Solution to LeetCode 17: Letter Combinations of a Phone Number Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, vector<string>> mp;
        mp['2'] = { "a", "b", "c" };
        mp['3'] = { "d", "e", "f" };
        mp['4'] = { "g", "h", "i" };
        mp['5'] = { "j", "k", "l" };
        mp['6'] = { "m", "n", "o" };
        mp['7'] = { "p", "q", "r", "s" };
        mp['8'] = { "t", "u", "v" };
        mp['9'] = { "w", "x", "y", "z" };
        
        vector<string> ans, tmp;
        ans = mp[digits[0]];
        for(int i = 1; i < digits.size(); i++) {
            tmp = ans;
            ans = {};
            for(int j = 0; j < mp[digits[i]].size(); j++) {
                for(int k = 0; k < tmp.size(); k++)
                    ans.push_back(tmp[k] + mp[digits[i]][j]);
            }
        }

        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/17.md" >}}
---
{{< youtube F7EoBxhPmBk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #18: 4Sum](https://grid47.xyz/posts/leetcode-18-4sum-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
