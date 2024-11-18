
+++
authors = ["grid47"]
title = "Leetcode 116: Populating Next Right Pointers in Each Node"
date = "2024-10-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 116: Populating Next Right Pointers in Each Node in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/116.webp"
youtube = "U4hFQCa1Cq0"
youtube_upload_date="2022-04-12"
youtube_thumbnail="https://i.ytimg.com/vi/U4hFQCa1Cq0/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/116.webp" 
    alt="A glowing grid of nodes, with gentle arrows connecting them, showing the next right pointer linkages."
    caption="Solution to LeetCode 116: Populating Next Right Pointers in Each Node Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #118: Pascal's Triangle](https://grid47.xyz/leetcode/solution-118-pascals-triangle/) |
| --- |
