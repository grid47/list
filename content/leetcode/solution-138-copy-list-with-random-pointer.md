
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
comments = true
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
Given a linked list where each node contains a value, a next pointer, and a random pointer (which can point to any node in the list or be null), create a deep copy of the list. The deep copy should consist of exactly n new nodes where each node has its value set to the value of its corresponding original node, and the next and random pointers of the new nodes should represent the same list state as the original. None of the pointers in the new list should point to nodes in the original list.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A linked list of nodes, each containing two pointers: a next pointer and a random pointer, which can point to any node or be null.
- **Example:** `head = [[5,null],[10,0],[15,4],[20,2],[25,1]]`
- **Constraints:**
	- 0 <= n <= 1000
	- -10^4 <= Node.val <= 10^4
	- Node.random is null or points to some node in the linked list.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the head of the deep copied linked list, where the copied list has the same values, next pointers, and random pointers as the original list.
- **Example:** `Output: [[5,null],[10,0],[15,4],[20,2],[25,1]]`
- **Constraints:**
	- The copied list should have no shared nodes with the original list.

{{< dots >}}
### Core Logic 🔍
**Goal:** Create a deep copy of the linked list by ensuring that both the next and random pointers of the new nodes represent the same list structure as the original list.

- 1. Iterate through the original list and create new nodes for each node in the original list.
- 2. Set the next pointer of each new node to match the corresponding next pointer in the original list.
- 3. Set the random pointer of each new node to match the corresponding random pointer in the original list.
- 4. Use a map or hash table to store mappings between the original nodes and their corresponding new nodes to handle random pointers efficiently.
{{< dots >}}
### Problem Assumptions ✅
- The input list contains nodes with valid random pointers that either point to a valid node or are null.
{{< dots >}}
## Examples 🧩
- **Input:** `head = [[5,null],[10,0],[15,4],[20,2],[25,1]]`  \
  **Explanation:** The original list contains five nodes with random pointers. The deep copy should have the same structure, where the next and random pointers of the new nodes match the original list.

- **Input:** `head = [[1,1],[2,1]]`  \
  **Explanation:** This example contains a two-node list where both nodes have random pointers pointing to each other. The deep copy should replicate the same structure.

{{< dots >}}
## Approach 🚀
To solve this problem, we will create a deep copy of the list by iterating through the original list and using a map to maintain references to the new nodes.

### Initial Thoughts 💭
- We need to handle the random pointers, which require mapping original nodes to new nodes to ensure the correct structure.
- We will use a hash map to store the relationship between the original nodes and the copied nodes, allowing us to efficiently update the random pointers.
{{< dots >}}
### Edge Cases 🌐
- If the input list is empty (null head), return null.
- The solution should handle lists with up to 1000 nodes efficiently.
- If a node's random pointer is null, the corresponding new node's random pointer should also be null.
- The solution should maintain a linear time complexity and constant space for the mapping.
{{< dots >}}
## Code 💻
```cpp
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
```

This code defines a solution to clone a linked list where each node contains a `next` pointer to the next node and a `random` pointer to any node in the list. It uses a map to store previously copied nodes to handle cycles and avoid duplication.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	map<Node*, Node*> mp;
	```
	A map `mp` is declared to store the mapping between the original node and the newly copied node.

2. **Function Definition (copyRandomList)**
	```cpp
	Node* copyRandomList(Node* head) {
	```
	This is the definition of the `copyRandomList` function, which will clone the entire list starting from the given head node.

3. **Clear Map**
	```cpp
	    mp.clear();
	```
	The map `mp` is cleared to ensure that no previous data remains before starting the copy process.

4. **Recursive Call (copyRandomList)**
	```cpp
	    return copy(head);
	```
	The `copyRandomList` function calls the helper function `copy`, passing the head node to begin the cloning process.

5. **Helper Function Definition (copy)**
	```cpp
	Node* copy(Node* head) {
	```
	This is the definition of the helper function `copy`, which handles the actual node cloning process for each individual node.

6. **Base Case (null)**
	```cpp
	    if(!head) return head;
	```
	If the input `head` is null, return null. This is the base case of the recursion.

7. **Check if Node is Already Copied**
	```cpp
	    if(mp.count(head)) return mp[head];
	```
	If the node has already been copied (i.e., it exists in the map `mp`), return the corresponding copied node.

8. **Node Creation**
	```cpp
	    Node* node = new Node(head->val);
	```
	A new node is created with the same value as the original node.

9. **Store Copy in Map**
	```cpp
	    mp[head] = node;
	```
	The newly created node is stored in the map `mp`, with the original node as the key.

10. **Recursive Copy (Next Pointer)**
	```cpp
	    node->next = copy(head->next);
	```
	Recursively copy the `next` pointer of the current node by calling `copy` on the next node.

11. **Recursive Copy (Random Pointer)**
	```cpp
	    node->random = copy(head->random);
	```
	Recursively copy the `random` pointer of the current node by calling `copy` on the random node.

12. **End Function (copy)**
	```cpp
	    return node;
	```
	Return the newly created and fully cloned node.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) as we need to traverse the entire linked list once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the map used to store the original-to-new node mapping.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/copy-list-with-random-pointer/description/)

---
{{< youtube 5Y2EiZST97Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
