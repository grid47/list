
+++
authors = ["grid47"]
title = "Leetcode 652: Find Duplicate Subtrees"
date = "2024-09-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 652: Find Duplicate Subtrees in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/652.webp"
youtube = "kn0Z5_qPPzY"
youtube_upload_date="2023-02-28"
youtube_thumbnail="https://i.ytimg.com/vi/kn0Z5_qPPzY/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/652.webp" 
    alt="A binary tree where duplicate subtrees are identified, and each duplicate subtree softly glows as it’s found."
    caption="Solution to LeetCode 652: Find Duplicate Subtrees Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given the root of a binary tree, return all duplicate subtrees. For each duplicate subtree, return the root node of any one of them. Two trees are considered duplicates if they have the same structure and node values.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is the root of a binary tree, represented as an array of integers where null indicates no child for a node.
- **Example:** `root = [1,2,3,4,null,2,4,null,null,4]`
- **Constraints:**
	- 1 <= number of nodes <= 5000
	- -200 <= Node.val <= 200

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of root nodes of duplicate subtrees. Each node in the output should be the root of a duplicate subtree.
- **Example:** `[[2,4],[4]]`
- **Constraints:**
	- Only return the root of any duplicate subtree.

{{< dots >}}
### Core Logic 🔍
**Goal:** Identify and return the root of all duplicate subtrees.

- 1. Traverse the tree in a depth-first manner.
- 2. For each subtree, serialize its structure into a string.
- 3. Use a hash map to store the frequency of each serialized subtree.
- 4. If a subtree appears more than once, add its root node to the result.
{{< dots >}}
### Problem Assumptions ✅
- The input tree may contain duplicate subtrees that need to be identified.
{{< dots >}}
## Examples 🧩
- **Input:** `root = [1,2,3,4,null,2,4,null,null,4]`  \
  **Explanation:** In this tree, the subtree [2,4] and the subtree [4] are repeated, so they are returned as the output.

{{< dots >}}
## Approach 🚀
Use serialization of the subtrees to identify duplicates. Each subtree is represented as a string, and a hashmap is used to track how many times each subtree occurs.

### Initial Thoughts 💭
- We need an efficient way to compare subtrees, and serializing them into strings is a good strategy.
- Hash maps can help store the serialized subtrees and detect duplicates.
{{< dots >}}
### Edge Cases 🌐
- The input tree will not be empty, as it is guaranteed to have at least one node.
- For large input sizes (up to 5000 nodes), ensure that the solution is optimized for time and space.
- Handle cases where there are no duplicate subtrees, in which case the output should be an empty list.
- The tree can have up to 5000 nodes, so ensure the solution is efficient.
{{< dots >}}
## Code 💻
```cpp
vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    unordered_map<string, vector<TreeNode*>> mp;
    serialise(mp, root);
    vector<TreeNode*> res;
    for(auto it: mp) {
        if(it.second.size() > 1)
        res.push_back(it.second[0]);
    }
    return res;
}

string serialise(unordered_map<string, vector<TreeNode*>> &mp, TreeNode* root) {
    if(root == NULL) return "";

    string s = "(" + serialise(mp, root->left) + to_string(root->val) + serialise(mp, root->right) + ")";
    mp[s].push_back(root);
    return s;

}
```

This function identifies duplicate subtrees in a binary tree. It uses a helper function `serialise` to convert each subtree into a string representation. The `findDuplicateSubtrees` function collects and returns the duplicate subtrees.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
	```
	The `findDuplicateSubtrees` function is defined to return a vector of TreeNode pointers representing the duplicate subtrees in the given binary tree rooted at `root`.

2. **Map Initialization**
	```cpp
	    unordered_map<string, vector<TreeNode*>> mp;
	```
	An unordered map `mp` is created to store serialized subtree strings as keys and the corresponding vector of TreeNode pointers as values.

3. **Subtree Serialization**
	```cpp
	    serialise(mp, root);
	```
	The helper function `serialise` is called to serialize the binary tree, populating the map `mp` with serialized subtree strings and corresponding TreeNode pointers.

4. **Result Vector Initialization**
	```cpp
	    vector<TreeNode*> res;
	```
	A vector `res` is initialized to store the duplicate subtrees.

5. **Map Iteration**
	```cpp
	    for(auto it: mp) {
	```
	The function iterates over each entry in the map `mp`, where the key is the serialized subtree string and the value is a vector of TreeNode pointers representing that subtree.

6. **Check for Duplicates**
	```cpp
	        if(it.second.size() > 1)
	```
	If the vector associated with a serialized subtree string has more than one element, it means the subtree is a duplicate.

7. **Store Duplicate Subtree**
	```cpp
	        res.push_back(it.second[0]);
	```
	The first occurrence of the duplicate subtree is added to the result vector `res`.

8. **Return Results**
	```cpp
	    return res;
	```
	The function returns the vector `res` containing the duplicate subtrees.

9. **Serialization Function Definition**
	```cpp
	string serialise(unordered_map<string, vector<TreeNode*>> &mp, TreeNode* root) {
	```
	The `serialise` helper function is defined to serialize the binary tree rooted at `root` into a string representation.

10. **Base Case**
	```cpp
	    if(root == NULL) return "";
	```
	If the current node is NULL, return an empty string, which represents a non-existent subtree.

11. **Subtree Serialization**
	```cpp
	    string s = "(" + serialise(mp, root->left) + to_string(root->val) + serialise(mp, root->right) + ")";
	```
	The current node's value is combined with the serialized representations of its left and right subtrees, enclosed in parentheses, to form a complete string representation of the current subtree.

12. **Map Update**
	```cpp
	    mp[s].push_back(root);
	```
	The serialized string `s` is used as a key in the map `mp`, and the current node is added to the vector of TreeNode pointers for that subtree.

13. **Return Serialized String**
	```cpp
	    return s;
	```
	The serialized string `s` representing the current subtree is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

In the worst case, we traverse the tree once, and each subtree serialization takes linear time relative to its size.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

Space complexity is O(n) due to the space used by the hashmap and the recursion stack for tree traversal.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-duplicate-subtrees/description/)

---
{{< youtube kn0Z5_qPPzY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
