
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 394: Decode String"
date = "2023-10-01"
description = "Solution to Leetcode 394"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/decode-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }
    
    string decode(string &s, int &i) {
        
        
        string res = "";
        
        while(i < s.size() && s[i] != ']') {
            if(!isdigit(s[i]))
                res += s[i++];
            else {
                int n = 0;
                
                while(i < s.size() && isdigit(s[i]))
                    n = n * 10 + (s[i++] - '0');
                
                i++;
                string t = decode(s, i);
                i++;
                
                while(n--> 0) res += t;
            }
        }
        
        return res;
    }
    
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

