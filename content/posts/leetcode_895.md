
+++
authors = ["Yasir"]
title = "Leetcode 895: Maximum Frequency Stack"
date = "2022-05-16"
description = "Solution to Leetcode 895"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-frequency-stack/description/)

---

**Code:**

{{< highlight html >}}
class FreqStack {
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> m;
    int maxFreq = 0;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        maxFreq = max(maxFreq, ++freq[val]);
        m[freq[val]].push(val);
    }
    
    int pop() {
        int x = m[maxFreq].top();
        m[maxFreq].pop();
        if(!m[freq[x]--].size()) maxFreq--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
{{< /highlight >}}

