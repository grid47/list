
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
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/705.webp"
youtube = "VymjPQUXjL8"
youtube_upload_date="2023-05-30"
youtube_thumbnail="https://i.ytimg.com/vi/VymjPQUXjL8/maxresdefault.jpg"
+++


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
---

### Problem Statement:
The task is to design a data structure called `MyHashSet` that supports three operations: `add(key)`, `remove(key)`, and `contains(key)` for a given integer key. The goal is to efficiently perform these operations in constant time, on average. The `MyHashSet` class should be capable of storing unique keys and allow for fast insertion, deletion, and look-up.

### Approach:
The optimal solution for implementing a hash set involves using a **hashing** technique. Hashing allows us to map keys to indices of an array (or list), so we can perform constant-time operations, on average, for `add`, `remove`, and `contains`.

To achieve this:
1. We use an array of size `sz` (10,000 in this case) to store linked lists.
2. Each index of the array corresponds to a hash bucket where the keys are stored.
3. **Hash Function**: The index of the bucket is determined by the hash of the key (`key % sz`). This ensures that the keys are uniformly distributed across the array.
4. **Chaining**: Since multiple keys may map to the same bucket (collision), we use a **linked list** to store all elements that hash to the same index. If a key is already present in the linked list, we avoid adding it again.

### Code Breakdown (Step by Step):

#### Step 1: Define the ListNode Class
```cpp
// class ListNode {
//     public:
//     int val;
//     ListNode* next;
//     ListNode(int val, ListNode* nxt) {
//         this->val = val;
//         this->next = nxt;
//     }
// };
```
- The `ListNode` class represents an individual node in the linked list. Each node stores an integer `val` and a pointer `next` to the next node in the list. This class is used for **chaining** in case of hash collisions.

#### Step 2: Define the `MyHashSet` Class
```cpp
class MyHashSet {
public:
    int sz = 10000;  // Size of the hash table
    vector<ListNode*> lst;  // Array of ListNode pointers (buckets)
    
    MyHashSet() {
        lst.resize(sz, NULL);  // Initialize the hash set with NULL pointers
    }
```
- `sz` is the size of the hash table (set to 10,000 to ensure an adequate number of buckets).
- `lst` is a vector that stores the linked list heads (buckets) for each hash bucket.
- The constructor initializes the vector `lst` to have `sz` elements, all set to `NULL`.

#### Step 3: Implement the `add` Function
```cpp
void add(int key) {
    int num = key % sz;  // Hash the key to find the bucket index
    if(lst[num] == NULL) {
        lst[num] = new ListNode(key, NULL);  // Create a new ListNode if bucket is empty
        return;
    }
    ListNode* cur = lst[num], *prv = NULL;
    while(cur) {  // Traverse the linked list to check if the key already exists
        if(cur->val == key) return;  // Key is already in the set, no need to add it
        prv = cur;
        cur = cur->next;
    }
    prv->next = new ListNode(key, NULL);  // Add the key at the end of the linked list
}
```
- **Hashing**: We first hash the key using `key % sz` to determine the bucket index.
- **Empty Bucket**: If the bucket is empty (`lst[num] == NULL`), a new `ListNode` is created with the key.
- **Check for Duplicates**: If the bucket is not empty, we traverse the linked list to check if the key already exists. If the key is found, we return without adding it.
- **Add the Key**: If the key is not found in the linked list, we add a new node containing the key at the end of the list.

#### Step 4: Implement the `remove` Function
```cpp
void remove(int key) {
    int num = key % sz;  // Hash the key to find the bucket index
    if(lst[num] == NULL) {
        return;  // Key is not in the set, no need to remove anything
    }
    if(lst[num]->val == key) {  // Special case for the first element in the linked list
        auto it = lst[num];
        lst[num] = lst[num]->next;  // Remove the first node
        it->next = NULL;
        return;
    }
    ListNode* cur = lst[num]->next, *prv = lst[num];
    while(cur) {  // Traverse the linked list to find and remove the key
        if(cur->val == key) {
            prv->next = cur->next;  // Remove the node by updating the previous node's next pointer
            cur->next = NULL;
            return;
        }
        prv = cur;
        cur = cur->next;
    }
}
```
- **Hashing**: We hash the key to find the correct bucket.
- **Empty Bucket**: If the bucket is empty (`lst[num] == NULL`), the key is not in the set, and no action is taken.
- **Special Case for Head Node**: If the first node in the bucket contains the key, we remove it by updating the bucket head (`lst[num]`).
- **Traverse and Remove**: If the key is found in the linked list, we update the previous node’s `next` pointer to skip the node with the key, effectively removing it from the list.

#### Step 5: Implement the `contains` Function
```cpp
bool contains(int key) {
    int num = key % sz;  // Hash the key to find the bucket index
    ListNode* cur = lst[num];
    while(cur) {  // Traverse the linked list to check if the key exists
        if(cur->val == key) {
            return true;  // The key is found in the set
        }
        cur = cur->next;
    }
    return false;  // The key is not found in the set
}
```
- **Hashing**: We hash the key to find the correct bucket.
- **Traverse**: We traverse the linked list at the corresponding bucket and check if the key is present.
- **Return**: If the key is found, return `true`. Otherwise, return `false`.

### Complexity Analysis:

#### Time Complexity:
- **Add Operation (`add(key)`)**: 
  - On average, the time complexity is **O(1)**, because the key is distributed uniformly across buckets, and the linked list at each bucket is expected to be small.
  - In the worst case, if all keys hash to the same bucket (very rare), the time complexity could become **O(n)**, where `n` is the number of elements in the hash set.

- **Remove Operation (`remove(key)`)**:
  - Similar to the `add` operation, the time complexity is **O(1)** on average.
  - In the worst case, if there are many collisions and a long linked list, the time complexity could become **O(n)**.

- **Contains Operation (`contains(key)`)**:
  - The time complexity is **O(1)** on average for the same reasons as the `add` and `remove` operations.
  - In the worst case, it could become **O(n)** if there are long chains in a single bucket.

#### Space Complexity:
- **O(n)**: The space complexity is **O(n)**, where `n` is the number of elements in the set, because each element is stored in a linked list.

### Conclusion:

This implementation of `MyHashSet` efficiently handles insertion, removal, and lookup operations using a hash table and linked list chaining for collision resolution. The expected time complexity for all operations is **O(1)** on average, making it highly efficient for dynamic sets where elements can be added and removed frequently. The space complexity is **O(n)**, where `n` is the number of elements in the set, due to the storage of the linked lists. This solution is optimal for managing large sets of unique keys with minimal overhead, and it performs well even as the size of the set grows.

[`Link to LeetCode Lab`](https://leetcode.com/problems/design-hashset/description/)

---
{{< youtube VymjPQUXjL8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
