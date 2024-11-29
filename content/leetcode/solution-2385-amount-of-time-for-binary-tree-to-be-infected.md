
+++
authors = ["grid47"]
title = "Leetcode 2385: Amount of Time for Binary Tree to Be Infected"
date = "2024-03-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2385: Amount of Time for Binary Tree to Be Infected in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "3lcaz9lw448"
youtube_upload_date="2022-08-21"
youtube_thumbnail="https://i.ytimg.com/vi/3lcaz9lw448/maxresdefault.jpg"
comments = true
+++



---
You are given the root of a binary tree where each node has a unique value, and an integer start representing the initial infected node. At minute 0, the infection begins at the node with value start. Each minute, an adjacent uninfected node becomes infected. Your task is to return the total number of minutes it takes for the entire tree to become infected.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary tree represented by the root node and an integer start.
- **Example:** `Input: root = [1,5,3,null,4,10,6,9,2], start = 3`
- **Constraints:**
	- 1 <= The number of nodes in the tree <= 10^5
	- 1 <= Node.val <= 10^5
	- Each node has a unique value.
	- A node with the value 'start' exists in the tree.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of minutes it will take for the entire tree to be infected.
- **Example:** `Output: 4`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the time required for the entire tree to be infected by spreading the infection level by level.

- 1. Convert the binary tree into an undirected graph where each node is connected to its adjacent nodes.
- 2. Perform a breadth-first search (BFS) starting from the infected node (start).
- 3. For each level of BFS, increment the time (minute).
- 4. Continue the process until all nodes are infected.
{{< dots >}}
### Problem Assumptions ✅
- The infection spreads to adjacent nodes every minute, and no node is re-infected.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [1,5,3,null,4,10,6,9,2], start = 3`  \
  **Explanation:** At minute 0, the infection starts at node 3. At each subsequent minute, neighboring nodes become infected. It takes 4 minutes for all nodes to be infected, hence the output is 4.

- **Input:** `Input: root = [1], start = 1`  \
  **Explanation:** In this case, there is only one node in the tree, and it's infected at minute 0, so no time is needed for the entire tree to be infected. The output is 0.

{{< dots >}}
## Approach 🚀
The approach to solving this problem involves transforming the binary tree into a graph structure and then using BFS to simulate the infection spread.

### Initial Thoughts 💭
- We can represent the tree as a graph where each node is connected to its neighbors.
- Breadth-first search (BFS) is a natural choice to simulate the spreading of the infection level by level.
{{< dots >}}
### Edge Cases 🌐
- If the tree contains only one node, the answer should be 0 because no infection time is needed.
- For large trees with 10^5 nodes, ensure that the solution can handle the upper limit efficiently.
- Handle the case where the start node is the root or a leaf node.
- Ensure the BFS algorithm is optimized for large input sizes to fit within time limits.
{{< dots >}}
## Code 💻
```cpp
class Solution {
unordered_map<int, vector<int>> mp;
public:
int amountOfTime(TreeNode* root, int start) {
    graph(root);

    queue<int> q;
    q.push(start);
    unordered_map<int, bool> seen;
    seen[start] = true;
    int timer = 0;
    for(; q.size(); timer++) {
        int n = q.size();
        while(n--) {
            auto node = q.front();
            q.pop();
            for(int i: mp[node]) {
                if(!seen[i]) {
                    seen[i] = true;
                    q.push(i);
                }
            }
        }
    }
    
    return timer-1;
}

void graph(TreeNode* root) {
    queue<pair<TreeNode*, int>> q;
    q.push({root, -1});
    while(!q.empty()) {
        auto [node, parent] = q.front();
        q.pop();
        if(parent != -1) {
            mp[parent].push_back(node->val);
            mp[node->val].push_back(parent);
        }
        if(node->left) q.push({node->left, node->val});
        if(node->right) q.push({node->right, node->val});
    }
}
```

This is a C++ implementation of a function to calculate the time needed to inform all nodes in a binary tree starting from a specific node, using breadth-first search (BFS) and constructing a graph representation of the tree.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class Solution {
	```
	The class `Solution` defines the main structure that contains the method `amountOfTime` and helper method `graph`.

2. **Data Structure**
	```cpp
	unordered_map<int, vector<int>> mp;
	```
	This unordered map `mp` maps each node in the binary tree to a list of its connected nodes, essentially representing the graph.

3. **Access Modifier**
	```cpp
	public:
	```
	The access modifier `public:` allows access to the methods `amountOfTime` and `graph` outside the class.

4. **Function Declaration**
	```cpp
	int amountOfTime(TreeNode* root, int start) {
	```
	This function calculates the amount of time needed to inform all nodes in the tree, starting from the `start` node.

5. **Graph Construction**
	```cpp
	    graph(root);
	```
	The `graph` method is called to build the graph representation of the tree.

6. **Queue Initialization**
	```cpp
	    queue<int> q;
	```
	A queue `q` is initialized to store the nodes to be processed in breadth-first search.

7. **Queue Operation**
	```cpp
	    q.push(start);
	```
	The starting node is pushed to the queue to begin the BFS.

8. **Map Initialization**
	```cpp
	    unordered_map<int, bool> seen;
	```
	An unordered map `seen` keeps track of the nodes that have already been visited.

9. **Mark Start Node**
	```cpp
	    seen[start] = true;
	```
	The start node is marked as visited.

10. **Timer Initialization**
	```cpp
	    int timer = 0;
	```
	A timer variable is initialized to count the levels (or time) taken in the BFS.

11. **BFS Loop**
	```cpp
	    for(; q.size(); timer++) {
	```
	The BFS loop continues as long as there are nodes in the queue. The timer increments with each level of BFS.

12. **Queue Size**
	```cpp
	        int n = q.size();
	```
	The size of the queue is recorded to determine how many nodes are at the current level.

13. **Processing Nodes**
	```cpp
	        while(n--) {
	```
	A while loop processes all nodes at the current level.

14. **Node Processing**
	```cpp
	            auto node = q.front();
	```
	The first node in the queue is dequeued and processed.

15. **Queue Operation**
	```cpp
	            q.pop();
	```
	The dequeued node is removed from the queue.

16. **Neighbor Exploration**
	```cpp
	            for(int i: mp[node]) {
	```
	For each neighbor of the current node, check if it has been visited.

17. **Neighbor Check**
	```cpp
	                if(!seen[i]) {
	```
	If the neighbor node has not been visited, mark it as visited.

18. **Mark Neighbor**
	```cpp
	                    seen[i] = true;
	```
	Mark the neighbor node as visited.

19. **Queue Operation**
	```cpp
	                    q.push(i);
	```
	Push the neighbor node to the queue for future processing.

20. **Return Statement**
	```cpp
	    return timer-1;
	```
	Return the time taken (number of levels in the BFS minus one).

21. **Graph Construction Function**
	```cpp
	void graph(TreeNode* root) {
	```
	This function builds the graph representation of the binary tree by traversing it and storing parent-child relationships.

22. **Queue Initialization**
	```cpp
	    queue<pair<TreeNode*, int>> q;
	```
	Initialize a queue to store pairs of nodes and their respective parent nodes.

23. **Queue Operation**
	```cpp
	    q.push({root, -1});
	```
	Push the root node and its parent (which is `-1` indicating no parent) to the queue.

24. **While Loop**
	```cpp
	    while(!q.empty()) {
	```
	Start processing the queue while it's not empty.

25. **Node Dequeuing**
	```cpp
	        auto [node, parent] = q.front();
	```
	Dequeue the front element of the queue and extract the current node and its parent.

26. **Queue Operation**
	```cpp
	        q.pop();
	```
	Remove the front element from the queue.

27. **Parent-Child Relationship**
	```cpp
	        if(parent != -1) {
	```
	If the parent is not `-1`, add the current node to the adjacency list of its parent and vice versa.

28. **Map Update**
	```cpp
	            mp[parent].push_back(node->val);
	```
	Add the current node's value to its parent's adjacency list.

29. **Map Update**
	```cpp
	            mp[node->val].push_back(parent);
	```
	Add the parent node to the current node's adjacency list.

30. **Left Child Check**
	```cpp
	        if(node->left) q.push({node->left, node->val});
	```
	If the current node has a left child, add it to the queue with its parent as the current node.

31. **Right Child Check**
	```cpp
	        if(node->right) q.push({node->right, node->val});
	```
	If the current node has a right child, add it to the queue with its parent as the current node.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the number of nodes, as we visit each node once during BFS.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the adjacency list and BFS queue.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/)

---
{{< youtube 3lcaz9lw448 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
