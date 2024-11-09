
+++
authors = ["grid47"]
title = "Leetcode 2516: Take K of Each Character From Left and Right"
date = "2024-11-01"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2517: Maximum Tastiness of Candy Basket](https://grid47.xyz/posts/leetcode-2516-take-k-of-each-character-from-left-and-right-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
