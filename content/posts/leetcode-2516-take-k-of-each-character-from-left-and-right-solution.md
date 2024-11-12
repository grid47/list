
+++
authors = ["grid47"]
title = "Leetcode 2516: Take K of Each Character From Left and Right"
date = "2024-02-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2516: Take K of Each Character From Left and Right in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int takeCharacters(string s, int k) {
        
        map<char, int> mp;
        for(int i = 0; i < s.size(); i++)
            mp[s[i]]++;
        if(mp['a'] < k || mp['b'] < k || mp['c'] < k) return -1;
        
        int j = 0, mx = 0;
        for(int i = 0; i < s.size(); i++) {
            // select max window which does not decrements frq below k;
            mp[s[i]]--;
            while(j <= i && mp[s[i]] < k) {
                mp[s[j]]++;
                j++;
            }
            mx = max(mx, i - j + 1);
        }
        return s.size() - mx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2516.md" >}}
---
{{< youtube QI4kCksMru0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2517: Maximum Tastiness of Candy Basket](https://grid47.xyz/posts/leetcode-2517-maximum-tastiness-of-candy-basket-solution/) |
| --- |
