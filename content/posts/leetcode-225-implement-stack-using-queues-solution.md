
+++
authors = ["grid47"]
title = "Leetcode 225: Implement Stack using Queues"
date = "2024-10-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 225: Implement Stack using Queues in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Stack","Design","Queue"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/implement-stack-using-queues/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/225.webp" 
    alt="A series of glowing queues stacked neatly, showing elements being added and removed smoothly."
    caption="Solution to LeetCode 225: Implement Stack using Queues Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class MyStack {
public:
    queue<int> que;
    MyStack() {
        
    }
    
    void push(int x) {
		que.push(x);
		for(int i=0;i<que.size()-1;++i){
			que.push(que.front());
			que.pop();
		}        
    }
    
    int pop() {
        int x = que.front();
        que.pop();
        return x;
    }
    
    int top() {
        return que.front();
    }
    
    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/225.md" >}}
---
{{< youtube rW4vm0-DLYc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #226: Invert Binary Tree](https://grid47.xyz/posts/leetcode-226-invert-binary-tree-solution/) |
| --- |
