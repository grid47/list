
+++
authors = ["Crafted by Me"]
title = "Leetcode 116: Populating Next Right Pointers in Each Node"
date = "2024-07-09"
description = "In-depth solution and explanation for Leetcode 116: Populating Next Right Pointers in Each Node in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

