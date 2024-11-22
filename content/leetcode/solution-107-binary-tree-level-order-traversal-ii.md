
+++
authors = ["grid47"]
title = "Leetcode 107: Binary Tree Level Order Traversal II"
date = "2024-10-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 107: Binary Tree Level Order Traversal II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/107.webp"
youtube = "6e4pmYyr_1o"
youtube_upload_date="2021-01-20"
youtube_thumbnail="https://i.ytimg.com/vi/6e4pmYyr_1o/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/107.webp" 
    alt="A tree with soft concentric circles, each level glowing and expanding outward from the center."
    caption="Solution to LeetCode 107: Binary Tree Level Order Traversal II Problem"
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        vector<vector<int>> ans;        
        queue<TreeNode*> q;
        if(root == NULL) return ans;
        
        q.push(root);        
        stack<vector<int>> stk;
                
        while(!q.empty())
        {
            vector<int> ans;
            int sz = q.size();

            while(sz--) {
                TreeNode* tmp = q.front();
                q.pop();
                ans.push_back(tmp->val);

                if(tmp->left)   q.push(tmp->left);
                if(tmp->right)  q.push(tmp->right);                
            }
            stk.push(ans);
        }

        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }

        return ans;      
    }
};
{{< /highlight >}}
---

### **🌲 Problem Overview: Reverse Level Order Traversal**

The challenge is to perform a **level order traversal** of a binary tree, but with a twist: instead of going from top to bottom, we need to return the traversal in reverse order (from bottom to top). This means we visit the **bottommost level** first and work our way upwards.

---

### **🚀 Approach: A Simple Twist with BFS**

To solve this, we'll use **breadth-first search (BFS)** to explore the tree level by level. After gathering the levels in the usual order, we'll reverse them before returning the result. Let's break it down step by step!

---

#### **1️⃣ Level Order Traversal Using a Queue**

We start by performing a standard **level order traversal** using a queue. This lets us process each level one by one.

```cpp
queue<TreeNode*> q;
if(root == NULL) return ans;
q.push(root);
```

💡 **Quick Tip:** 
- We use a queue to manage the nodes. The queue ensures that we process nodes in the right order: *root → left → right*. 🧩
- If the tree is empty (i.e., `root == NULL`), we immediately return an empty result. 📅

---

#### **2️⃣ Process Each Level**

For each level, we need to capture all nodes before moving to the next level.

```cpp
while(!q.empty()) {
    vector<int> ans;
    int sz = q.size();  // Get number of nodes at this level
```

🌱 **Explain Simply:** 
- We check how many nodes are at the current level using `q.size()`. This tells us how many nodes to process before moving to the next level.

---

#### **3️⃣ Visit Each Node in the Level**

For each node at the current level, we pop it from the queue, record its value, and enqueue its left and right children (if they exist).

```cpp
while(sz--) {
    TreeNode* tmp = q.front();
    q.pop();
    ans.push_back(tmp->val);

    if(tmp->left) q.push(tmp->left);  // Enqueue left child
    if(tmp->right) q.push(tmp->right);  // Enqueue right child
}
```

🔄 **In Action:**
- We dequeue nodes one by one, push their values into a temporary `ans` vector, and enqueue their children (if they exist) to visit in the next cycle.

---

#### **4️⃣ Store the Level in a Stack (Reversal Coming!)**

Now, we store the nodes of the current level into a **stack**. The stack will help us reverse the order later. 📦

```cpp
stk.push(ans);  // Push the current level into the stack
```

💡 **Why a Stack?**
- The stack lets us reverse the levels easily: the last level processed will be the first one popped out, achieving our bottom-up order.

---

#### **5️⃣ Reverse the Level Order**

Once all the levels are processed, we pop the stack to retrieve the levels in reverse order.

```cpp
while(!stk.empty()) {
    ans.push_back(stk.top());  // Pop each level from the stack
    stk.pop();
}
```

🔄 **Reversal Magic:**
- By popping from the stack, we get the levels from bottom to top, which is exactly what the problem asks for. 🎩✨

---

### **⏱️ Time and Space Complexity**

Let's analyze the efficiency of this approach:

- **Time Complexity:** **O(n)**  
  - We traverse each node exactly once during the BFS process.
  - Reversing the levels (via popping from the stack) also takes **O(n)** time, since each level is popped once.  
  Hence, the overall time complexity is **O(n)**.

- **Space Complexity:** **O(n)**  
  - We use a **queue** to store nodes during the BFS traversal. In the worst case, the queue will hold all the nodes at the bottommost level, which is about **O(n)** in space.
  - The **stack** temporarily holds all levels before they are reversed, contributing **O(n)** space as well.
  
Thus, the overall space complexity is **O(n)**.

---

### **🌳 Example Walkthrough**

Let’s walk through an example to see this approach in action!

Given this tree:

```
        3
       / \
      9  20
         /  \
        15   7
```

1. **Level 0:** The root node `3` is processed first. We enqueue its children `9` and `20`.
2. **Level 1:** The nodes `9` and `20` are processed. We enqueue the children of `20`, which are `15` and `7`.
3. **Level 2:** The nodes `15` and `7` are processed, both of which have no children.

The **standard order** of levels would be:

```
[[3], [9, 20], [15, 7]]
```

After reversing with the stack, the final result is:

```
[[15, 7], [9, 20], [3]]
```

🎉 Now we have the levels in **bottom-to-top** order as required!

---

### **🎯 Conclusion**

By using BFS and a stack, we efficiently traverse the tree level by level, and then reverse the levels to give the desired **bottom-to-top** order. 

This approach is **time-efficient** (**O(n)**) and **space-efficient** (**O(n)**), making it a solid solution for this problem. 🌟

### **💡 Harmonic Thought:**
> *"Step by step, we build a tree that stands from bottom to top!"* 🌱

---

[`Link to LeetCode Lab`](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/)

---
{{< youtube 6e4pmYyr_1o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
