
+++
authors = ["grid47"]
title = "Leetcode 2196: Create Binary Tree From Descriptions"
date = "2024-04-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2196: Create Binary Tree From Descriptions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "yWkrFfqO7NA"
youtube_upload_date="2024-07-15"
youtube_thumbnail="https://i.ytimg.com/vi/yWkrFfqO7NA/maxresdefault.jpg"
comments = true
+++



---
You are given a list of triplets representing the structure of a binary tree. Each triplet `[parent, child, isLeft]` indicates that `parent` is the parent of `child`, and if `isLeft` is 1, `child` is the left child of `parent`, otherwise, it's the right child. Your task is to reconstruct the binary tree and return the root node.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of triplets where each triplet represents a parent-child relationship in a binary tree. The structure of the input is: `[parent, child, isLeft]`. The list contains information about all nodes of the tree.
- **Example:** `descriptions = [[10, 5, 1], [10, 20, 0], [5, 3, 1], [3, 2, 0]]`
- **Constraints:**
	- 1 <= descriptions.length <= 10^4
	- descriptions[i].length == 3
	- 1 <= parent, child <= 10^5
	- 0 <= isLeft <= 1
	- The binary tree described by descriptions is valid.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the root node of the reconstructed binary tree, represented as a binary tree node. The output should be in the form of an array representation of the tree starting from the root.
- **Example:** `[10, 5, 20, 3, 2]`
- **Constraints:**
	- The output should represent the tree starting from the root node.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to reconstruct the binary tree from the descriptions and return its root node.

- 1. Parse the descriptions to identify the root node (the node that does not have any parent).
- 2. Create a map to store the nodes as we build the tree.
- 3. For each triplet, connect the parent and child nodes as left or right based on the value of `isLeft`.
- 4. Return the root node once the tree is fully constructed.
{{< dots >}}
### Problem Assumptions ✅
- The binary tree is guaranteed to be valid and can always be constructed from the descriptions.
{{< dots >}}
## Examples 🧩
- **Input:** `descriptions = [[10, 5, 1], [10, 20, 0], [5, 3, 1], [3, 2, 0]]`  \
  **Explanation:** In this example, we construct the binary tree where 10 is the root, 5 is the left child of 10, 20 is the right child of 10, 3 is the left child of 5, and 2 is the right child of 3.

- **Input:** `descriptions = [[1, 2, 1], [2, 3, 0], [3, 4, 1]]`  \
  **Explanation:** In this example, the tree is constructed such that 1 is the root, 2 is the left child of 1, 3 is the right child of 2, and 4 is the left child of 3.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to build the tree by identifying the root node (which does not appear as a child in any triplet), then iterating over the descriptions to connect the parent and child nodes accordingly. After constructing the tree, we return the root node.

### Initial Thoughts 💭
- The first step is to identify the root node by checking which node is not a child of any other node.
- Using a map to store each node allows us to easily connect parents and children while building the tree.
{{< dots >}}
### Edge Cases 🌐
- There will always be valid input as per the problem constraints.
- The approach should be efficient enough to handle the input size up to 10^4 descriptions.
- If there is only one node (parent = child), it will be the root node.
- Ensure that the tree is always valid and does not contain cycles.
{{< dots >}}
## Code 💻
```cpp
TreeNode* createBinaryTree(vector<vector<int>>& desc) {
    set<int> s;
    for(vector<int> v: desc) {
        s.insert(v[0]);
        s.insert(v[1]);
    }

    for(auto v: desc) {
        if(s.find(v[1]) != s.end()) {
            s.erase(v[1]);
        }
    }

    int root = *s.begin();

    // found root
    // next create map for nodes
    // connect them as given in desc

    map<int, TreeNode*> mp;
    for(auto v: desc) {
        if(mp.find(v[0]) == mp.end()) {
            mp[v[0]] = new TreeNode(v[0]);
        }
        if(mp.find(v[1]) == mp.end()) {
            mp[v[1]] = new TreeNode(v[1]);
        }
    }

    for(auto v: desc) {
        int paret = v[0];
        int child = v[1];
        int left  = v[2];

        if(left) mp[paret]->left  = mp[child];
        else     mp[paret]->right = mp[child];
    }

    return mp[root];
}
```

This function builds a binary tree based on the given description where each entry defines a parent-child relationship, and whether the child is on the left or right of the parent.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	TreeNode* createBinaryTree(vector<vector<int>>& desc) {
	```
	This is the function definition, where we pass a 2D vector `desc` that contains the tree's node relationships.

2. **Set Initialization**
	```cpp
	    set<int> s;
	```
	Here, a set `s` is initialized to store unique node values from the description.

3. **Iterate over Desc**
	```cpp
	    for(vector<int> v: desc) {
	```
	We iterate over each entry in the `desc` vector to process the parent-child relationships.

4. **Insert Parent**
	```cpp
	        s.insert(v[0]);
	```
	Insert the parent node value `v[0]` into the set `s`.

5. **Insert Child**
	```cpp
	        s.insert(v[1]);
	```
	Insert the child node value `v[1]` into the set `s`.

6. **Second Loop**
	```cpp
	    for(auto v: desc) {
	```
	A second iteration over `desc` to refine the node relationships and determine the root.

7. **Find Node in Set**
	```cpp
	        if(s.find(v[1]) != s.end()) {
	```
	Check if the child node `v[1]` exists in the set `s`.

8. **Erase Node from Set**
	```cpp
	            s.erase(v[1]);
	```
	If the child node is found in the set, remove it from the set, as it's no longer a potential root.

9. **Determine Root**
	```cpp
	    int root = *s.begin();
	```
	The root of the tree is the only element left in the set `s`.

10. **Map Initialization**
	```cpp
	    map<int, TreeNode*> mp;
	```
	A map `mp` is initialized to store the tree nodes, with their values as keys.

11. **Third Loop**
	```cpp
	    for(auto v: desc) {
	```
	Iterate over `desc` again to create the nodes if they don't already exist in the map.

12. **Check and Create Node for Parent**
	```cpp
	        if(mp.find(v[0]) == mp.end()) {
	```
	If the parent node `v[0]` is not already in the map, create it.

13. **Add Parent to Map**
	```cpp
	            mp[v[0]] = new TreeNode(v[0]);
	```
	Create a new TreeNode for the parent and add it to the map.

14. **Check and Create Node for Child**
	```cpp
	        if(mp.find(v[1]) == mp.end()) {
	```
	If the child node `v[1]` is not already in the map, create it.

15. **Add Child to Map**
	```cpp
	            mp[v[1]] = new TreeNode(v[1]);
	```
	Create a new TreeNode for the child and add it to the map.

16. **Fourth Loop**
	```cpp
	    for(auto v: desc) {
	```
	A loop to establish parent-child connections between the nodes.

17. **Assign Left or Right Child**
	```cpp
	        int paret = v[0];
	```
	Assign the parent node value to `paret`.

18. **Assign Left or Right Child**
	```cpp
	        int child = v[1];
	```
	Assign the child node value to `child`.

19. **Assign Left or Right Child**
	```cpp
	        int left  = v[2];
	```
	Assign the left flag value to `left`.

20. **Assign Left Child**
	```cpp
	        if(left) mp[paret]->left  = mp[child];
	```
	If `left` is true, set the left child of the parent node.

21. **Assign Right Child**
	```cpp
	        else     mp[paret]->right = mp[child];
	```
	If `left` is false, set the right child of the parent node.

22. **Return Root**
	```cpp
	    return mp[root];
	```
	Return the root node, which is the result of the function.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the number of descriptions.
- **Average Case:** O(n), where n is the number of descriptions.
- **Worst Case:** O(n), where n is the number of descriptions.

The time complexity is linear with respect to the number of descriptions, as we only need to process each description once.

### Space Complexity 💾
- **Best Case:** O(1), when there is only one node.
- **Worst Case:** O(n), where n is the number of nodes in the tree.

The space complexity is linear with respect to the number of nodes in the tree, as we store each node in a map.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/create-binary-tree-from-descriptions/description/)

---
{{< youtube yWkrFfqO7NA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
