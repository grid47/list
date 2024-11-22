
+++
authors = ["grid47"]
title = "Leetcode 382: Linked List Random Node"
date = "2024-09-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 382: Linked List Random Node in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Math","Reservoir Sampling","Randomized"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/382.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/382.webp" 
    alt="A glowing linked list where the randomly selected node is softly highlighted."
    caption="Solution to LeetCode 382: Linked List Random Node Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* head;
public:
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        int ans = 0, i = 1;
        ListNode* p = this->head;
        while(p) {
            if(rand() % i == 0) ans = p->val;
            i++;
            p = p->next;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
{{< /highlight >}}
---

### 🚀 Problem Statement

In this problem, we're tasked with implementing a `Solution` class for a **singly linked list**. The class should have a method called `getRandom()` that returns the value of a random node from the list. The catch? We need to ensure that each node has **equal probability** of being selected, and we can't use extra space proportional to the size of the list.

---

### 🧠 Approach

To solve this challenge, we will use an algorithm called **Reservoir Sampling**. This technique allows us to pick a random element from a stream (in this case, the linked list) while maintaining **uniform probability**.

#### Key Idea:
1. **Traverse the List**: We'll go through the list node by node.
2. **Maintain a Running Random Value**: At each node, we have a chance to replace the current selected value with the value of the current node. The probability of replacing the value decreases as we move through the list.
3. **End of List**: Once we reach the end, we'll have our random selection.

By applying this approach, we ensure that each node has the same probability of being selected, and it only takes one pass through the list. This results in a time complexity of **O(n)**, where n is the length of the list, and a space complexity of **O(1)**.

---

### 🔨 Step-by-Step Code Breakdown

Let's break down the implementation in a step-by-step manner:

#### Step 1: Definition of `ListNode`
```cpp
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
```
- The `ListNode` structure defines the linked list node. Each node holds a `val` (its value) and a pointer `next` to the next node in the list.
- We provide multiple constructors to easily create nodes with or without a `next` pointer.

#### Step 2: `Solution` Class and Constructor
```cpp
class Solution {
    ListNode* head;
public:
    Solution(ListNode* head) {
        this->head = head;
    }
};
```
- The `Solution` class has a member `head`, which holds a reference to the head of the linked list.
- The constructor initializes the `head` from the passed argument, linking the list to the solution object.

#### Step 3: `getRandom` Method
```cpp
    int getRandom() {
        int ans = 0, i = 1;
        ListNode* p = this->head;
        while(p) {
            if(rand() % i == 0) ans = p->val;
            i++;
            p = p->next;
        }
        return ans;
    }
};
```
- **Random Selection Process**: 
    - We initialize `ans` to store the current random selection and `i` to keep track of the current node's index.
    - For each node, we calculate `rand() % i`. If the result is 0, we replace the current `ans` with the value of the current node. This gives each node a 1/i chance of being selected.
    - As we move to the next node, the probability of selecting it adjusts, but the overall probability remains uniform across the list.
- At the end of the traversal, `ans` holds the value of the randomly selected node.

#### Step 4: Instantiating the `Solution` Class
```cpp
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
```
- We create a `Solution` object by passing the head of the linked list.
- Then, we call the `getRandom()` method to fetch a random node’s value.

---

### 📈 Complexity Analysis

#### Time Complexity:
- **O(n)** where n is the number of nodes in the linked list. We traverse each node exactly once and perform a constant amount of work at each step (generating a random number and potentially updating the selection).

#### Space Complexity:
- **O(1)**. We use only a few variables (`ans`, `i`, and `p`), regardless of the size of the linked list. No extra space proportional to the list is used.

---

### 🏁 Conclusion

This solution leverages **Reservoir Sampling** to efficiently select a random node from a singly linked list with **uniform probability**. By doing so, we achieve optimal time and space complexities:

- **Time Complexity**: **O(n)**, as we traverse the list once.
- **Space Complexity**: **O(1)**, since we only use a few variables for the process.

The beauty of this solution lies in its simplicity: by adjusting the probability at each node and using just a single traversal, we ensure that each node has an equal chance of being selected. This makes the approach both **time-efficient** and **space-efficient**, making it ideal for situations where the list might be large.

---


[`Link to LeetCode Lab`](https://leetcode.com/problems/linked-list-random-node/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
