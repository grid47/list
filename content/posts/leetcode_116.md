
+++
authors = ["Yasir"]
title = "Leetcode 116: Populating Next Right Pointers in Each Node"
date = "2024-07-04"
description = "Solution to Leetcode 116"
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

{{< highlight html >}}
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

