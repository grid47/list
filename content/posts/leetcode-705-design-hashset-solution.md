
+++
authors = ["grid47"]
title = "Leetcode 705: Design HashSet"
date = "2024-08-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 705: Design HashSet in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Linked List","Design","Hash Function"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/design-hashset/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/705.webp" 
    alt="A set of elements where the hashset design is highlighted, with each element glowing softly in its unique location."
    caption="Solution to LeetCode 705: Design HashSet Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/705.md" >}}
---
{{< youtube VymjPQUXjL8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #707: Design Linked List](https://grid47.xyz/posts/leetcode-707-design-linked-list-solution/) |
| --- |
