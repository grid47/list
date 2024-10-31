
+++
authors = ["Crafted by Me"]
title = "Leetcode 1177: Can Make Palindrome from Substring"
date = "2021-08-12"
description = "Solution to Leetcode 1177"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/can-make-palindrome-from-substring/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& q) {
        vector<bool> ans;
        
        vector<int> pt(1,0);
        int mask = 0;
        
        for(int i = 0; i < s.length(); i++) {
        pt.push_back(mask ^= 1 << (s[i] - 'a'));
        }
        
        
        for(int i = 0; i < q.size(); i++) {
        
auto &v = q[i];

  
int cnt = __builtin_popcount(pt[v[1]+1] ^ pt[v[0]]);

    ans.push_back(cnt/2 <= v[2]);
        }
        
        return ans;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

