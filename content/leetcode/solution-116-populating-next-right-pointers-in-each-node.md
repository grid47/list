
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
comments = true
+++


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
You are given a perfect binary tree where every parent node has two children and all leaves are at the same level. Your task is to populate the 'next' pointer of each node to point to its next right node. If no such node exists, set the 'next' pointer to NULL. Initially, all 'next' pointers are set to NULL.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the root of a perfect binary tree. The binary tree is represented by a node structure, where each node has a 'val', 'left', 'right', and 'next' pointer.
- **Example:** `Input: root = [10, 5, 15, 3, 7, 12, 20]`
- **Constraints:**
	- The binary tree has between 0 and 2^12 - 1 nodes.
	- Node values are between -1000 and 1000.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should return the root of the tree, where each node's 'next' pointer is set to its next right node, or NULL if no next node exists.
- **Example:** `Output: [10,#,5,15,#,3,7,12,20,#]`
- **Constraints:**
	- The next pointer of each node should point to the next right node, or NULL if no such node exists.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to populate the 'next' pointers for each node, connecting nodes at the same level to each other.

- Use a level-order traversal (breadth-first search) of the tree to connect each node to the node on its right.
- For each level, connect nodes to their adjacent nodes and reset the next pointers for the next level.
- Ensure that after the last node of each level, the next pointer is set to NULL.
{{< dots >}}
### Problem Assumptions ✅
- The tree is guaranteed to be a perfect binary tree.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [10, 5, 15, 3, 7, 12, 20]`  \
  **Explanation:** In the tree, each node's next pointer should connect it to the node to its immediate right, such as node 5's next pointer pointing to node 15, node 3's next pointer pointing to node 7, and so on. After processing, the tree should look like: [10, #, 5, 15, #, 3, 7, 12, 20, #].

- **Input:** `Input: root = []`  \
  **Explanation:** If the input tree is empty (root is NULL), the output should also be an empty tree.

{{< dots >}}
## Approach 🚀
To solve this problem, we can use a level-order traversal (BFS) approach. We traverse the tree level by level, connecting each node to its adjacent right node, and ensure that each level's last node points to NULL.

### Initial Thoughts 💭
- We need to connect nodes at the same level, which makes level-order traversal an appropriate choice.
- This problem can be solved using BFS without requiring additional space, as long as we adjust the pointers in-place.
{{< dots >}}
### Edge Cases 🌐
- If the input is an empty tree (root is NULL), the output should also be an empty tree.
- For large perfect binary trees, the solution should efficiently handle up to 2^12 - 1 nodes.
- Handle trees where the root has no children (i.e., a single node).
- The tree can have up to 2^12 - 1 nodes.
{{< dots >}}
## Code 💻
```cpp
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
```

This function connects all nodes at the same level of a binary tree. It uses a queue to traverse the tree level by level and assigns the `next` pointer for each node.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	Node* connect(Node* root) {
	```
	Declare the function to connect all nodes at the same level in the tree.

2. **Base Case**
	```cpp
	    if(!root) return root;
	```
	Handle the base case where the tree is empty.

3. **Queue Initialization**
	```cpp
	    queue<Node*> q;
	```
	Initialize a queue to facilitate level-order traversal.

4. **Queue Operation**
	```cpp
	    q.push(root);
	```
	Push the root node onto the queue to start the traversal.

5. **Pointer Initialization**
	```cpp
	    Node* nextptr = NULL;
	```
	Initialize a pointer to track the next node at the same level.

6. **While Loop**
	```cpp
	    while(!q.empty()) {
	```
	Iterate as long as there are nodes in the queue.

7. **Level Size**
	```cpp
	        int sz = q.size();
	```
	Get the number of nodes at the current level.

8. **Reset Pointer**
	```cpp
	        nextptr = NULL;
	```
	Reset the `next` pointer for the current level.

9. **For Each Level**
	```cpp
	        while(sz--) {
	```
	Iterate over all nodes at the current level.

10. **Queue Front**
	```cpp
	            Node* tmp = q.front();
	```
	Retrieve the front node from the queue.

11. **Queue Operation**
	```cpp
	            q.pop();
	```
	Remove the front node from the queue.

12. **Pointer Assignment**
	```cpp
	            tmp->next = nextptr;
	```
	Assign the `next` pointer of the current node.

13. **Update Pointer**
	```cpp
	            nextptr = tmp;
	```
	Update the `next` pointer to the current node.

14. **Child Nodes Check**
	```cpp
	            if(tmp->right)  q.push(tmp->right),
	```
	If the right child exists, push it onto the queue.

15. **Child Nodes Check**
	```cpp
	                            q.push(tmp->left);
	```
	If the left child exists, push it onto the queue.

16. **Return Statement**
	```cpp
	    return root;
	```
	Return the modified root node.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

In all cases, the time complexity is O(n), where n is the number of nodes in the tree, as each node is processed once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the queue used for level-order traversal. In the worst case, the queue can store all nodes at the current level.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/)

---
{{< youtube U4hFQCa1Cq0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
