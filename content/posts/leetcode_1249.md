
+++
authors = ["Crafted by Me"]
title = "Leetcode 1249: Minimum Remove to Make Valid Parentheses"
date = "2021-06-02"
description = "Solution to Leetcode 1249"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> stk, itk;
        for(int i = 0; i < s.length(); i++) {
            char a = s[i];
                 if(a == '(') { stk.push_back(i); }
            else if(a == ')') {
                     if(stk.size()    == 0)    stk.push_back(i);
                else if(s[stk.back()] == '(')  stk.pop_back();
                else stk.push_back(i);
            }
        }
        string res = "";
        set<int> st(stk.begin(), stk.end());
        for(int i = 0; i < s.length(); i++) {
            if(st.count(i)) continue;
            res += s[i];
        }
        return res;        
    }
};
{{< /highlight >}}


---
{{< youtube tMzZUDR_cH0 >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

