
+++
authors = ["grid47"]
title = "Leetcode 138: Copy List with Random Pointer"
date = "2024-10-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 138: Copy List with Random Pointer in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Linked List"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/138.webp"
youtube = "5Y2EiZST97Y"
youtube_upload_date="2021-03-05"
youtube_thumbnail="https://i.ytimg.com/vi/5Y2EiZST97Y/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/copy-list-with-random-pointer/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/138.webp" 
    alt="A glowing linked list with a soft, gentle pointer connecting to another, showing the copying process."
    caption="Solution to LeetCode 138: Copy List with Random Pointer Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> mp;
    Node* copyRandomList(Node* head) {
        mp.clear();
        return copy(head);
        
    }
    
    Node* copy(Node* head) {
        if(!head) return head;
        if(mp.count(head)) return mp[head];
        
        Node* node = new Node(head->val);
        mp[head] = node;
        node->next = copy(head->next);
        node->random = copy(head->random);
        
        return node;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/138.md" >}}
---
{{< youtube 5Y2EiZST97Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #139: Word Break](https://grid47.xyz/leetcode/solution-139-word-break/) |
| --- |