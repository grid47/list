
+++
authors = ["grid47"]
title = "Leetcode 116: Populating Next Right Pointers in Each Node"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 116: Populating Next Right Pointers in Each Node in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        Node* nextptr = NULL;
        while(!q.empty()) {
            int sz = q.size();
            nextptr = NULL;
            while(sz--) {
                Node* tmp = q.front();
                q.pop();
                tmp->next = nextptr;
                nextptr = tmp;
                if(tmp->right)  q.push(tmp->right),
                                q.push(tmp->left);
            }
         }
        return root;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/116.md" >}}
---
{{< youtube U4hFQCa1Cq0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #118: Pascal's Triangle](https://grid47.xyz/posts/leetcode-118-pascals-triangle-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
