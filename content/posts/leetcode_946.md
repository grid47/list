
+++
authors = ["Yasir"]
title = "Leetcode 946: Validate Stack Sequences"
date = "2022-03-27"
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

{{< highlight html >}}
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

