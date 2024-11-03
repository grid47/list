
+++
authors = ["Crafted by Me"]
title = "Leetcode 946: Validate Stack Sequences"
date = "2022-04-01"
description = "In-depth solution and explanation for Leetcode 946: Validate Stack Sequences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/946.md" >}}
---
{{< youtube YF5ZWSWvMT0 >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

