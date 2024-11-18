
+++
authors = ["grid47"]
title = "Leetcode 707: Design Linked List"
date = "2024-08-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 707: Design Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Design"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "Wf4QhpdVFQo"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/707.webp"
+++



[`Problem Link`](https://leetcode.com/problems/design-linked-list/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/707.webp" 
    alt="A glowing linked list where each node is linked and highlighted softly as it’s connected."
    caption="Solution to LeetCode 707: Design Linked List Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Node {
    public:
        int val;
        Node* next;
    Node(int x): val(x), next(nullptr) {}
};
class MyLinkedList {
    int sz;
    Node* head;

public:
    MyLinkedList(): sz(0), head(nullptr) { }
    
    int get(int index) {
        if(index < 0 || index >= sz)
        return -1;
        else {
            Node* curr = head;
            for(int i = 0; i < index;i++)
            curr = curr->next;
            return curr->val;
        }
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(sz, val);        
    }
    
    void addAtIndex(int index, int val) {
        if(index > sz || index < 0) return;
        Node* cur = head;
        Node* new_node = new Node(val);
        if(index == 0) {
            new_node->next = head;
            head = new_node;
        } else {
            for(int i = 0; i < index - 1; i++)
                cur = cur->next;
            new_node->next = cur->next;
            cur->next = new_node;
        }
        sz++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= sz || index < 0) return;

        if(index == 0) {
            Node* nxt = head->next;
            delete head;
            head = nxt;
        } else {
            Node* cur = head;
            for(int i = 0; i < index - 1; i++)
                cur = cur->next;
            Node* nxt = cur->next->next;
            delete cur->next;
            cur->next = nxt;
        }
        sz--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/707.md" >}}
---
{{< youtube Wf4QhpdVFQo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #712: Minimum ASCII Delete Sum for Two Strings](https://grid47.xyz/leetcode/solution-712-minimum-ascii-delete-sum-for-two-strings/) |
| --- |
