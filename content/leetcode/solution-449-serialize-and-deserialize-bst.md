
+++
authors = ["grid47"]
title = "Leetcode 449: Serialize and Deserialize BST"
date = "2024-09-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 449: Serialize and Deserialize BST in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Tree","Depth-First Search","Breadth-First Search","Design","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/449.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/449.webp" 
    alt="A binary search tree being serialized and deserialized, with each node softly glowing during the transformation."
    caption="Solution to LeetCode 449: Serialize and Deserialize BST Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Design an algorithm to serialize and deserialize a binary search tree (BST). Serialization is converting the tree to a string format, while deserialization reconstructs the tree from this string. The goal is to ensure that the BST can be serialized to a compact string and can be accurately deserialized back into the original tree structure.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the root node of a binary search tree, where each node contains an integer value, a left child, and a right child.
- **Example:** `[3,1,4,null,2]`
- **Constraints:**
	- The number of nodes in the tree is in the range [0, 10^4].
	- 0 <= Node.val <= 10^4.
	- The tree is a valid binary search tree (BST).

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a string representing the serialized binary search tree. The serialized string should be as compact as possible while ensuring it can be deserialized back into the original tree.
- **Example:** `[3,1,4,null,2]`
- **Constraints:**
	- The serialized string should accurately represent the structure of the binary search tree.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to implement efficient serialization and deserialization methods for a binary search tree.

- 1. For serialization, traverse the tree and convert each node's value into a string format, ensuring that the null nodes are also represented.
- 2. For deserialization, read the serialized string, and rebuild the tree structure by placing nodes in the correct positions based on the BST properties.
{{< dots >}}
### Problem Assumptions ✅
- The input tree is a valid binary search tree.
- The serialized string should be compact and able to be deserialized back into the original tree.
{{< dots >}}
## Examples 🧩
- **Input:** `[3,1,4,null,2]`  \
  **Explanation:** In this case, the tree is represented as a string where 'null' is used to indicate the absence of a node.

- **Input:** `[]`  \
  **Explanation:** An empty tree is represented by an empty string.

{{< dots >}}
## Approach 🚀
We will implement two functions: one for serialization and one for deserialization. The serialization function will traverse the tree and convert it into a string. The deserialization function will reconstruct the tree from the string, ensuring that the BST structure is preserved.

### Initial Thoughts 💭
- Serialization involves converting the tree to a string in a way that preserves its structure.
- Deserialization requires careful parsing of the serialized string to recreate the tree with the correct structure.
- To serialize, we can use a pre-order traversal and represent the tree in a compact string format. For deserialization, we will parse the string and build the tree using the BST properties.
{{< dots >}}
### Edge Cases 🌐
- Handle the case where the input tree is empty.
- The algorithm should be able to handle up to 10^4 nodes efficiently.
- Ensure the tree can handle special values such as zero or the maximum possible value (10^4).
- The algorithm must work within the time and space constraints specified.
{{< dots >}}
## Code 💻
```cpp
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    string str;
    serial(str, root);
    return str;
}

void serial(string& ss, TreeNode* root) {
    if (!root) return;
    char c[4];
    memcpy(c, &(root->val), sizeof(int));
    for (int i = 0; i < 4; i++) ss.push_back(c[i]);
    serial(ss, root->left );
    serial(ss, root->right);
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    int pos = 0;
    return deserial(data, pos, INT_MIN, INT_MAX);
}

TreeNode* deserial(string& data, int& pos, int left, int right) {
    if (pos >= data.size()) return NULL;

    int val;
    memcpy(&val, &(data[pos]), sizeof(int));
    if (val < left || val > right) return NULL;

    TreeNode* root = new TreeNode(val);
    pos += sizeof(int);
    root->left  = deserial ( data, pos, left,   val );
    root->right = deserial ( data, pos,  val, right );
    return root;
}
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
```

The `Codec` class is responsible for serializing and deserializing a binary tree. It includes methods for converting a tree into a string and reconstructing it from that string.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Structure Definition**
	```cpp
	 * struct TreeNode {
	```
	Defines a struct `TreeNode` representing a node in the binary tree, with an integer value and pointers to its left and right children.

2. **Structure Fields**
	```cpp
	 *     int val;
	```
	The `val` field stores the integer value of the node.

3. **Structure Fields**
	```cpp
	 *     TreeNode *left;
	```
	The `left` pointer points to the left child of the node.

4. **Structure Fields**
	```cpp
	 *     TreeNode *right;
	```
	The `right` pointer points to the right child of the node.

5. **Constructor**
	```cpp
	 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	```
	The constructor initializes the node with a given value `x` and sets both the left and right children to `NULL`.

6. **Class Definition**
	```cpp
	class Codec {
	```
	Defines the `Codec` class which contains methods for serializing and deserializing a binary tree.

7. **Public Section**
	```cpp
	public:
	```
	Marks the beginning of the public section of the class, which contains accessible methods for serialization and deserialization.

8. **Method Definition**
	```cpp
	string serialize(TreeNode* root) {
	```
	The `serialize` method takes the root of the binary tree as input and returns a string representation of the tree.

9. **Variable Initialization**
	```cpp
	    string str;
	```
	A string `str` is initialized to store the serialized binary tree.

10. **Recursive Method Call**
	```cpp
	    serial(str, root);
	```
	The `serial` helper method is called recursively to serialize the binary tree.

11. **Return Statement**
	```cpp
	    return str;
	```
	Returns the serialized string representation of the tree.

12. **Recursive Serialization**
	```cpp
	void serial(string& ss, TreeNode* root) {
	```
	The `serial` method is a helper function that recursively traverses the tree and appends node values to the string.

13. **Base Case**
	```cpp
	    if (!root) return;
	```
	If the current node is `NULL`, the function returns without doing anything.

14. **Data Conversion**
	```cpp
	    char c[4];
	```
	A character array `c` is declared to temporarily store the 4-byte representation of an integer value.

15. **Memory Copy**
	```cpp
	    memcpy(c, &(root->val), sizeof(int));
	```
	The integer value of the current node is copied into the character array `c`.

16. **String Construction**
	```cpp
	    for (int i = 0; i < 4; i++) ss.push_back(c[i]);
	```
	The 4-byte representation of the node's value is appended to the string `ss`.

17. **Recursive Method Call**
	```cpp
	    serial(ss, root->left );
	```
	Recursively calls the `serial` method to serialize the left subtree.

18. **Recursive Method Call**
	```cpp
	    serial(ss, root->right);
	```
	Recursively calls the `serial` method to serialize the right subtree.

19. **End Method**
	```cpp
	}
	```
	Marks the end of the `serial` method.

20. **Method Definition**
	```cpp
	TreeNode* deserialize(string data) {
	```
	The `deserialize` method takes a serialized string `data` and reconstructs the corresponding binary tree.

21. **Variable Initialization**
	```cpp
	    int pos = 0;
	```
	An integer `pos` is initialized to track the current position in the serialized string.

22. **Recursive Call**
	```cpp
	    return deserial(data, pos, INT_MIN, INT_MAX);
	```
	The `deserial` helper method is called recursively to deserialize the string and reconstruct the tree.

23. **End Method**
	```cpp
	}
	```
	Marks the end of the `deserialize` method.

24. **Recursive Deserialization**
	```cpp
	TreeNode* deserial(string& data, int& pos, int left, int right) {
	```
	The `deserial` method is a helper function that recursively reconstructs the tree from the serialized string.

25. **Base Case**
	```cpp
	    if (pos >= data.size()) return NULL;
	```
	If the current position is past the end of the string, the function returns `NULL`.

26. **Data Conversion**
	```cpp
	    int val;
	```
	A variable `val` is declared to hold the integer value extracted from the serialized string.

27. **Memory Copy**
	```cpp
	    memcpy(&val, &(data[pos]), sizeof(int));
	```
	The integer value at the current position in the string is copied into the variable `val`.

28. **Bounds Check**
	```cpp
	    if (val < left || val > right) return NULL;
	```
	If the extracted value is out of bounds (less than `left` or greater than `right`), the function returns `NULL`.

29. **Node Creation**
	```cpp
	    TreeNode* root = new TreeNode(val);
	```
	A new `TreeNode` is created with the extracted value `val`.

30. **Recursive Method Call**
	```cpp
	    pos += sizeof(int);
	```
	Updates the position to move past the 4-byte value of the node.

31. **Recursive Method Call**
	```cpp
	    root->left  = deserial ( data, pos, left,   val );
	```
	Recursively calls the `deserial` method to reconstruct the left subtree.

32. **Recursive Method Call**
	```cpp
	    root->right = deserial ( data, pos,  val, right );
	```
	Recursively calls the `deserial` method to reconstruct the right subtree.

33. **Return Statement**
	```cpp
	    return root;
	```
	Returns the root node of the reconstructed subtree.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Both serialization and deserialization involve visiting every node in the tree once, leading to a time complexity of O(n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the recursive call stack and the storage of the serialized string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/serialize-and-deserialize-bst/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
