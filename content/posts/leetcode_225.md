
+++
authors = ["Yasir"]
title = "Leetcode 225: Implement Stack using Queues"
date = "2024-03-16"
description = "Solution to Leetcode 225"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/implement-stack-using-queues/description/)

---

**Code:**

{{< highlight html >}}
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

