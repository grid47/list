
+++
authors = ["Yasir"]
title = "Leetcode 705: Design HashSet"
date = "2022-11-22"
description = "Solution to Leetcode 705"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/design-hashset/description/)

---

**Code:**

{{< highlight html >}}
// class ListNode {
//     public:
//     int val;
//     ListNode* next;
//     ListNode(int val, ListNode* nxt) {
//         this->val = val
//         this->next = nxt;
//     }
// };

class MyHashSet {
public:
    int sz = 10000;
    vector<ListNode*> lst;
    MyHashSet() {
        lst.resize(sz, NULL);
    }
    
    void add(int key) {
        int num = key%sz;
        if(lst[num] == NULL) {
            lst[num] = new ListNode(key, NULL);
            return;
        }
        ListNode* cur = lst[num], *prv = NULL;
        while(cur) {
            if(cur->val == key) return;
            prv = cur;
            cur = cur->next;
        }
        prv->next = new ListNode(key, NULL);
    }
    
    void remove(int key) {
        int num = key%sz;
        if(lst[num] == NULL) {
            return;
        }
        if(lst[num]->val == key) {
            auto it = lst[num];
            lst[num] = lst[num]->next;
            it->next = NULL;            
            return;
        }
        ListNode* cur = lst[num]->next, *prv = lst[num];
        while(cur) {
            if(cur->val == key) {
                prv->next = cur->next;
                cur->next = NULL;
                return;
            }
            prv = cur;
            cur = cur->next;
        }
    }
    
    bool contains(int key) {
        int num = key%sz;
        ListNode* cur = lst[num];
        while(cur) {
            if(cur->val == key) {
                return true;
            }
            cur = cur->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
{{< /highlight >}}

