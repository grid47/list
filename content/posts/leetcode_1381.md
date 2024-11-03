
+++
authors = ["Crafted by Me"]
title = "Leetcode 1381: Design a Stack With Increment Operation"
date = "2021-01-21"
description = "In-depth solution and explanation for Leetcode 1381: Design a Stack With Increment Operation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/design-a-stack-with-increment-operation/description/)

---

**Code:**

{{< highlight cpp >}}
class CustomStack {
    vector<int> stk;
    int ptr, m;
public:
    
    CustomStack(int mx) {
        stk.resize(mx);
        ptr = -1;
        m = mx;
    }
    
    void push(int x) {
        if (ptr < m - 1) {
            ptr++;
            stk[ptr] = x;
        }
    }
    
    int pop() {
        if(ptr == -1) return -1;
        return stk[ptr--];
    }
    
    void increment(int k, int val) {
        
        for(int i = 0; i < min(m, k); i++)
            stk[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1381.md" >}}
---


"| 1382: Balance a Binary Search Tree |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

