
+++
authors = ["grid47"]
title = "Leetcode 429: N-ary Tree Level Order Traversal"
date = "2024-09-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 429: N-ary Tree Level Order Traversal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/429.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/429.webp" 
    alt="An N-ary tree with nodes being traversed in level order, with each level softly illuminated as it's visited."
    caption="Solution to LeetCode 429: N-ary Tree Level Order Traversal Problem"
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
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        levelOrderT(root, 0, ans);
        return ans;
    }

    void levelOrderT(Node* node, int level, vector<vector<int>> &ans) {
        if(level == size(ans)) {
            ans.push_back({node->val});
        } else {
            ans[level].push_back(node->val);
        }

        for(Node* child: node->children) {
            levelOrderT(child, level+1, ans);
        }
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to perform a level-order traversal on an n-ary tree and return the values of nodes at each level in a 2D vector. An n-ary tree is a tree where each node can have an arbitrary number of children. The solution should provide a way to traverse all the nodes in a breadth-first manner, grouping the node values at each level.

### Approach

Level-order traversal is a type of breadth-first search (BFS) in which we visit all the nodes at one level before moving to the next. In the case of an n-ary tree, each node can have multiple children, and therefore, the traversal must handle an arbitrary number of children at each level.

To achieve this, we can use a **recursive depth-first search (DFS)** approach. We will maintain a 2D list where each sublist corresponds to one level of the tree. For each node, we record its value at the correct level based on its depth in the tree. 

Key steps involved:
1. **Recursive Traversal**: For each node, we traverse its children and append their values at the corresponding level in the result list.
2. **Tracking Levels**: As we move down the tree, we increase the depth level for each child node. We check if a sublist for that level exists and either append the value or create a new sublist for that level.
3. **Base Case**: The recursion stops when there are no more child nodes to traverse.

### Code Breakdown (Step by Step)

#### Step 1: Handle the Base Case

```cpp
if(!root) return {};
```

- We first check if the root is `nullptr`. If the tree is empty (i.e., `root` is `nullptr`), we immediately return an empty result, as there are no nodes to traverse.

#### Step 2: Initialize the Result Vector

```cpp
vector<vector<int>> ans;
```

- We initialize a `vector` of vectors `ans` to store the node values at each level. Each inner vector will hold the values of nodes at the same depth in the tree.

#### Step 3: Begin the Recursive Traversal

```cpp
levelOrderT(root, 0, ans);
```

- We begin the recursive function `levelOrderT` with the root node, starting at level 0. The level starts at 0 because the root node is at depth 0.

#### Step 4: Recursive Traversal Function

```cpp
void levelOrderT(Node* node, int level, vector<vector<int>> &ans) {
    if(level == size(ans)) {
        ans.push_back({node->val});
    } else {
        ans[level].push_back(node->val);
    }
```

- Inside the recursive function, we first check if the current `level` already exists in the `ans` vector. If the current level does not exist (i.e., we are visiting this level for the first time), we create a new sublist for that level and add the node's value to it.
- If the level already exists, we simply append the node's value to the corresponding sublist for that level.

#### Step 5: Traverse Child Nodes

```cpp
for(Node* child: node->children) {
    levelOrderT(child, level + 1, ans);
}
```

- After processing the current node, we recursively visit each of its children. The level is incremented by 1 because we are moving one level deeper into the tree.
- This step ensures that each child node is placed at the correct level in the `ans` vector.

#### Step 6: Return the Final Answer

```cpp
return ans;
```

- After the recursive traversal is complete, we return the `ans` vector, which contains the values of the nodes grouped by their levels.

### Complexity

#### Time Complexity:
- The time complexity of this algorithm is `O(N)`, where `N` is the total number of nodes in the tree. This is because we visit each node exactly once, and each node contributes to one entry in the final result.

#### Space Complexity:
- The space complexity is also `O(N)`. We store the values of all nodes in the result vector `ans`, and the recursion uses extra space for the call stack. In the worst case, the depth of the recursion can go up to the height of the tree, which is `O(H)`. However, since the total number of nodes is `N`, the overall space complexity is still `O(N)`.

### Conclusion

This solution efficiently implements the level-order traversal of an n-ary tree using a recursive depth-first search (DFS) approach. It handles the tree's structure with arbitrary branching at each level and returns the result as a 2D vector, where each sublist contains the values of nodes at a specific level.

- The algorithm performs in linear time, visiting each node once.
- It uses additional space to store the result and maintain the recursive call stack, making it efficient for trees of large size.
- This approach provides a clean, elegant solution to the problem of level-order traversal, making use of recursion to simplify the logic for handling arbitrary numbers of children at each node.

This solution is optimal for scenarios where the tree's structure is irregular (n-ary) and efficiently handles depth-based grouping of node values.

[`Link to LeetCode Lab`](https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
