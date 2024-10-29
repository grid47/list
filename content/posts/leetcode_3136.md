
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 3136: Valid Word"
date = "2016-03-30"
description = "Solution to Leetcode 3136"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/valid-word/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isValid(string word) {
        set<char> st;
        bool upper = false, lower = false;
        bool vowel = false, conso = false, number = false;
        
        for(char x : word) {
            
            if(x >= 'a' && x <= 'z') lower = true;
            if(x >= 'A' && x <= 'Z') upper = true;
            st.insert(x);
            if(x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U' ||
               x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
                    vowel = true;
            else if((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
                    conso  = true;
            else if(isdigit(x)) {}
            else    return false;
            
        }
        
        return vowel && conso && st.size() >= 3;
        
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

