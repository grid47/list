
+++
authors = ["grid47"]
title = "Leetcode 1609: Even Odd Tree"
date = "2024-05-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1609: Even Odd Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "FkNWN1Fj_TY"
youtube_upload_date="2024-02-29"
youtube_thumbnail="https://i.ytimg.com/vi/FkNWN1Fj_TY/maxresdefault.jpg"
comments = true
+++



---
A binary tree is called Even-Odd if the values in each level of the tree follow certain rules. For every even-indexed level, all nodes must contain odd integers in strictly increasing order. For every odd-indexed level, all nodes must contain even integers in strictly decreasing order. Given the root of a binary tree, return true if the tree is Even-Odd, otherwise return false.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given the root of a binary tree. The structure of the tree is represented as a list where each value is a node in the tree, and null represents the absence of a node.
- **Example:** `root = [2,6,4,1,3,7,9,8,10,12]`
- **Constraints:**
	- The binary tree will have between 1 and 10^5 nodes.
	- Each node's value will be between 1 and 10^6.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if the binary tree satisfies the Even-Odd conditions, otherwise return false.
- **Example:** `For root = [2,6,4,1,3,7,9,8,10,12], the output would be true.`
- **Constraints:**
	- The solution should work efficiently for large trees, with up to 10^5 nodes.

{{< dots >}}
### Core Logic 🔍
**Goal:** To check if the tree follows the Even-Odd level rules. Traverse the tree level by level, ensuring that nodes on even-indexed levels have odd values in increasing order, and nodes on odd-indexed levels have even values in decreasing order.

- Use a breadth-first search (BFS) to traverse the tree level by level.
- For each level, check the values of the nodes and verify if they follow the Even-Odd rules for that level's index.
- For even-indexed levels, ensure the node values are odd and in strictly increasing order.
- For odd-indexed levels, ensure the node values are even and in strictly decreasing order.
{{< dots >}}
### Problem Assumptions ✅
- The tree will be a valid binary tree.
- The tree may contain nodes at different levels, but all nodes at a particular level must follow the rules for that level.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [2,6,4,1,3,7,9,8,10,12]`  \
  **Explanation:** At level 0, the node is 2 (even). At level 1, nodes 6 and 4 are even and decreasing. At level 2, nodes 1, 3, 7, 9, 8, 10, and 12 are in strictly increasing order. Thus, the tree follows the Even-Odd rules and the output is true.

- **Input:** `Input: root = [5,8,7,6,4]`  \
  **Explanation:** At level 0, the node is 5 (odd). At level 1, nodes 8 and 7 are not in strictly decreasing order, thus the tree does not follow the Even-Odd rules and the output is false.

{{< dots >}}
## Approach 🚀
We use breadth-first search (BFS) to traverse the binary tree level by level, validating the Even-Odd conditions for each level.

### Initial Thoughts 💭
- The tree is traversed level by level, ensuring that we check the node values at each level sequentially.
- By checking the node values at each level and verifying the conditions for Even-Odd, we can determine if the binary tree is valid.
{{< dots >}}
### Edge Cases 🌐
- An empty tree (null root) would return false as there are no nodes to check.
- Ensure that the solution can handle large trees efficiently (up to 10^5 nodes).
- Check for cases where all nodes at a level are either all even or all odd but still don't follow the required increasing/decreasing order.
- Ensure that node values are valid as per the given constraints.
{{< dots >}}
## Code 💻
```cpp
bool isEvenOddTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);

    bool isEI = true;
    // increasing - I
    // even - E
    while(!q.empty()) {
        int sz = q.size();
        int prv = isEI? INT_MIN : INT_MAX;
        while(sz--) {
            TreeNode* n = q.front();
            q.pop();
            if(isEI) {
                if(n->val % 2 == 0) return false;
                if(n->val <= prv)    return false;
            } else {
                if(n->val % 2 == 1) return false;                    
                if(n->val >= prv)    return false;
            }
            prv = n->val;
            if(n->left) q.push(n->left);
            if(n->right) q.push(n->right);
        }
        isEI = !isEI;
    }

    return true;
}
```

This function `isEvenOddTree` determines whether a given binary tree follows a specific pattern: even levels should have strictly increasing odd values, and odd levels should have strictly decreasing even values.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool isEvenOddTree(TreeNode* root) {
	```
	Define the function `isEvenOddTree` which takes the root of a binary tree and returns a boolean indicating whether the tree follows the 'even-odd' tree condition.

2. **Queue Initialization**
	```cpp
	    queue<TreeNode*> q;
	```
	Create a queue to help in level order traversal of the tree. This queue will store nodes as they are processed.

3. **Queue Operation**
	```cpp
	    q.push(root);
	```
	Push the root node of the tree into the queue to start the traversal.

4. **Initialization**
	```cpp
	    bool isEI = true;
	```
	Initialize a boolean variable `isEI` to true, which will alternate between true and false to indicate whether the current level is even or odd.

5. **Main Loop**
	```cpp
	    while(!q.empty()) {
	```
	Start a loop that runs as long as there are nodes in the queue (i.e., the tree is not fully traversed).

6. **Queue Size**
	```cpp
	        int sz = q.size();
	```
	Store the current size of the queue, representing the number of nodes at the current level of the tree.

7. **Previous Node Value Initialization**
	```cpp
	        int prv = isEI? INT_MIN : INT_MAX;
	```
	Initialize `prv`, the variable that keeps track of the previous node's value. Set it to `INT_MIN` for an even level (to allow increasing odd values) or `INT_MAX` for an odd level (to allow decreasing even values).

8. **Level Traversal**
	```cpp
	        while(sz--) {
	```
	Start a loop to process all nodes at the current level.

9. **Queue Operation**
	```cpp
	            TreeNode* n = q.front();
	```
	Get the front node from the queue to process.

10. **Queue Operation**
	```cpp
	            q.pop();
	```
	Remove the node from the queue after processing it.

11. **Even Level Check**
	```cpp
	            if(isEI) {
	```
	Check if the current level is even (indicated by `isEI` being true).

12. **Even Value Check**
	```cpp
	                if(n->val % 2 == 0) return false;
	```
	If the node value is even at an even level, return false because odd levels should contain odd values.

13. **Strictly Increasing Check**
	```cpp
	                if(n->val <= prv)    return false;
	```
	Check if the current node value is greater than the previous node value (ensuring strictly increasing order at even levels). If not, return false.

14. **Odd Level Check**
	```cpp
	            } else {
	```
	If the current level is odd (indicated by `isEI` being false), perform the checks for odd levels.

15. **Odd Value Check**
	```cpp
	                if(n->val % 2 == 1) return false;
	```
	If the node value is odd at an odd level, return false because even levels should contain even values.

16. **Strictly Decreasing Check**
	```cpp
	                if(n->val >= prv)    return false;
	```
	Check if the current node value is less than the previous node value (ensuring strictly decreasing order at odd levels). If not, return false.

17. **Update Previous Value**
	```cpp
	            prv = n->val;
	```
	Update `prv` to the current node value, which will be used for the next comparison.

18. **Child Node Check**
	```cpp
	            if(n->left) q.push(n->left);
	```
	If the current node has a left child, push it into the queue to process in the next iteration.

19. **Child Node Check**
	```cpp
	            if(n->right) q.push(n->right);
	```
	If the current node has a right child, push it into the queue to process in the next iteration.

20. **End Level Traversal**
	```cpp
	        }
	```
	End the loop for processing nodes at the current level.

21. **Toggle Level Type**
	```cpp
	        isEI = !isEI;
	```
	Toggle `isEI` to switch between even and odd levels.

22. **Return**
	```cpp
	    return true;
	```
	If all levels satisfy the even-odd tree conditions, return true.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(N)
- **Average Case:** O(N)
- **Worst Case:** O(N)

The best, average, and worst cases all involve traversing each node exactly once, leading to a time complexity of O(N).

### Space Complexity 💾
- **Best Case:** O(N)
- **Worst Case:** O(N)

The space complexity is O(N) due to the space required for the queue in BFS traversal, where N is the number of nodes in the binary tree.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/even-odd-tree/description/)

---
{{< youtube FkNWN1Fj_TY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
