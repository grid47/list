
+++
authors = ["Crafted by Me"]
title = "Leetcode 895: Maximum Frequency Stack"
date = "2022-05-22"
description = "In-depth solution and explanation for Leetcode 895: Maximum Frequency Stack in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/895.md" >}}
---
{{< youtube Z6idIicFDOE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #896: Monotonic Array](https://grid47.xyz/posts/leetcode_896) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

