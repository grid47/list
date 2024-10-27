
+++
authors = ["Yasir"]
title = "Leetcode 707: Design Linked List"
date = "2022-11-21"
description = "Solution to Leetcode 707"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/design-linked-list/description/)

---

**Code:**

{{< highlight html >}}
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

