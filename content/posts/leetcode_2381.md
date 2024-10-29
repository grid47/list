
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2381: Shifting Letters II"
date = "2018-04-24"
description = "Solution to Leetcode 2381"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/shifting-letters-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& sh) {
        int n = s.length();
        vector<int> net(n, 0);
        for(auto &x: sh) {
            int k = x[2] == 1? 1 : -1;
            net[x[0]] += k;
           // net[x[0]] %= 26;
            if(x[1] + 1 < n) {
            net[x[1] + 1] -= k;
           // net[x[1] + 1] %= 26;
                }



        }
        
        partial_sum(net.begin(), net.end(), net.begin());
        
        int i = 0;
        for(char &c : s) {
            
            int res = ((c - 'a') + net[i])% 26;
                     res = (res + 26)%26;
            c = 'a' + res;
            i++;
        }
        
        return s;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

