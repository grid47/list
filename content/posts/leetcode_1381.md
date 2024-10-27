
+++
authors = ["Yasir"]
title = "Leetcode 1381: Design a Stack With Increment Operation"
date = "2021-01-16"
description = "Solution to Leetcode 1381"
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

{{< highlight html >}}
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

