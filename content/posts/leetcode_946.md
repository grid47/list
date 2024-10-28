
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 946: Validate Stack Sequences"
date = "2022-03-28"
description = "Solution to Leetcode 946"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/validate-stack-sequences/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int i = 1, j = 0;
        stk.push(pushed[0]);
        int n = pushed.size();
        while(i < n) {
            while(j < n && !stk.empty() && stk.top() == popped[j]) {
                j++;
                stk.pop();
            }
            stk.push(pushed[i++]);
        }
        while(j < n && !stk.empty() && stk.top() == popped[j]) {
            j++;
            stk.pop();
        }        
        
        return stk.empty();
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

