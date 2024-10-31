
+++
authors = ["Crafted by Me"]
title = "Leetcode 2434: Using a Robot to Print the Lexicographically Smallest String"
date = "2018-03-04"
description = "Solution to Leetcode 2434"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    char low(vector<int> &frq) {
        for(int i = 0; i < 26; i++)
            if(frq[i] != 0) return 'a'+i;
        return 'z';
    }
    
    string robotWithString(string s) {
        
        vector<int> frq(26, 0);
        for(char c: s)
            frq[c - 'a']++;
        
        stack<int> t;
        string ans = "";
        
        for(char c : s) {
            t.push(c);
            frq[c - 'a']--;
            while(!t.empty() && t.top() <= low(frq)) {
                ans += t.top();
                t.pop();
            }
        }
        
        return ans;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

