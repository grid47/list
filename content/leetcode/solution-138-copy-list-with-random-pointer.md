
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
---

### 🌟 **Problem Overview: Deep Copying a Linked List with Random Pointers**

In this challenge, you are given a **linked list**, where each node has an additional **random pointer**. The task is to **clone** or **deep copy** the linked list, ensuring both the `next` and `random` pointers are copied. The random pointer can point to any node in the list, or be `NULL`, adding complexity to the task. But don't worry, we're going to break this down step by step! 😎

---

### 🔍 **Understanding the Key Challenges**

To solve this problem, we need to perform a **deep copy** of the linked list. Here are the main obstacles:
1. **Copying the `next` pointers**: The next pointers will just form a straightforward chain in the new list.
2. **Copying the `random` pointers**: This is trickier because the random pointer can point anywhere in the list, or even be `NULL`. The key is to ensure the random pointers in the cloned list point to the corresponding nodes in the original list.

Our solution approach will leverage a **hash map (or dictionary)** to keep track of the correspondence between the original nodes and their cloned counterparts. This map will allow us to handle the copying of both the `next` and `random` pointers effectively. 

---

### 🛠️ **Step-by-Step Breakdown of the Solution**

#### 1️⃣ **Node Structure Definition**

```cpp
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
```

- This `Node` class represents a node in the linked list. Each node has:
  - `val`: The node’s value.
  - `next`: A pointer to the next node.
  - `random`: A pointer to any random node, or `NULL`.

---

#### 2️⃣ **Initializing the Copying Process**

```cpp
map<Node*, Node*> mp;
Node* copyRandomList(Node* head) {
    mp.clear();
    return copy(head);
}
```

- We declare a **map (`mp`)** to store the mapping between the original nodes and their corresponding clones.
- The function `copyRandomList` starts the deep copy process by calling the `copy` function, passing the `head` of the list. We clear the map before starting to ensure no old mappings are carried over.

---

#### 3️⃣ **Recursive Copying Function**

```cpp
Node* copy(Node* head) {
    if (!head) return head;
    if (mp.count(head)) return mp[head];
    
    Node* node = new Node(head->val);
    mp[head] = node;
    node->next = copy(head->next);
    node->random = copy(head->random);
    
    return node;
}
```

- **Base Case**: If `head` is `NULL`, we return `NULL` as there’s nothing to copy.
- **Check if Node is Already Copied**: Before creating a new node, we check if it's already been copied by looking it up in the `mp` map. If it has, we return the existing clone.
- **Create a New Node**: If the node hasn't been copied yet, we create a new node with the same value.
- **Store the Mapping**: We store the new node in the map with the original node as the key. This lets us efficiently retrieve the copied node later.
- **Copy the `next` Pointer**: We recursively copy the `next` pointer by calling `copy(head->next)`.
- **Copy the `random` Pointer**: Similarly, we recursively copy the `random` pointer using `copy(head->random)`.
- **Return the Copied Node**: After copying both the `next` and `random` pointers, we return the new node.

---

#### 4️⃣ **Handling Special Cases**

- **Empty List**: If the input list is empty (`head == NULL`), we simply return `NULL`.
- **Circular Random Pointers**: Even if the random pointers form a circular reference, our map ensures that each node is copied only once, so no infinite loops occur during recursion.

---

### 📊 **Time and Space Complexity**

#### ⏱️ Time Complexity:
- **O(n)**: We process each node exactly once. Since the algorithm only makes recursive calls for the `next` and `random` pointers, each node is copied only once, making the overall time complexity **O(n)**, where `n` is the number of nodes in the linked list.

#### 🧳 Space Complexity:
- **O(n)**: We use a map to store the correspondence between the original nodes and their copied nodes. In the worst case, the map stores one entry for each node, so the space complexity is **O(n)**.

---

### 🎯 **Conclusion: The Power of Recursive Cloning**

This solution efficiently clones the linked list, handling both the `next` and `random` pointers. By using a **recursive approach** and a **hash map**, we ensure that:
- **Each node is copied exactly once**.
- The algorithm works even with **circular random pointers** or **empty lists**.

#### Key Takeaways:
- **Recursive Deep Copying**: We recursively copy both the `next` and `random` pointers.
- **Map for Tracking**: The map ensures no node is copied more than once and allows us to efficiently handle the random pointer connections.
- **Optimal Time and Space Complexity**: With **O(n)** time and **O(n)** space complexity, this approach is optimal for large linked lists.

With this solution, you’re equipped to tackle linked lists with random pointers like a pro! Keep practicing and improving your skills—you’re one step closer to becoming a coding superstar! ✨🚀

[`Link to LeetCode Lab`](https://leetcode.com/problems/copy-list-with-random-pointer/description/)

---
{{< youtube 5Y2EiZST97Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
