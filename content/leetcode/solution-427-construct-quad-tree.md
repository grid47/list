
+++
authors = ["grid47"]
title = "Leetcode 427: Construct Quad Tree"
date = "2024-09-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 427: Construct Quad Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Divide and Conquer","Tree","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/427.webp"
youtube = "UQ-1sBMV0v4"
youtube_upload_date="2023-02-27"
youtube_thumbnail="https://i.ytimg.com/vi/UQ-1sBMV0v4/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/427.webp" 
    alt="A grid where sections gently form a quad tree, each section glowing as it is constructed."
    caption="Solution to LeetCode 427: Construct Quad Tree Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return helper(grid, 0, 0, grid.size());
    }

    Node* helper(vector<vector<int>> &grid, int x, int y, int sz) {
        if(sz == 1) return new Node(grid[x][y] != 0, true, NULL, NULL, NULL, NULL);
        Node* res = new Node();
        Node* topRight    = helper(grid, x , y+sz/2, sz / 2);
        Node* topLeft     = helper(grid, x , y, sz / 2);
        Node* bottomRight = helper(grid, x +sz/2, y+sz/2, sz / 2);
        Node* bottomLeft  = helper(grid, x +sz/2, y, sz / 2);

        if(topRight->isLeaf && topLeft->isLeaf && bottomRight->isLeaf && bottomLeft->isLeaf && 
        topLeft->val == topRight->val && topRight->val == bottomRight->val && bottomRight->val == bottomLeft->val) {
            res->val = topLeft->val;
            res-> isLeaf = true;
        } else {
             res->topRight    = topRight;   
             res->topLeft     = topLeft;   
             res->bottomRight = bottomRight;   
             res->bottomLeft  = bottomLeft;       
        }
        return res;
    }


};
{{< /highlight >}}
---

### Problem Statement

The problem is to construct a QuadTree from a given 2D grid of binary values (0s and 1s). A QuadTree is a tree data structure where each node represents a 4-way partition of the 2D grid, subdividing it into quadrants. Each internal node has four children: top-left, top-right, bottom-left, and bottom-right. A leaf node represents a single square in the grid and holds a value (either 0 or 1). The goal is to create a QuadTree from the grid where the leaves represent uniform values and internal nodes group similar values.

### Approach

To solve this problem, the approach is based on recursive subdivision of the grid. The key idea is:
1. **Subdivide the grid**: At each step, divide the grid into 4 smaller quadrants (top-left, top-right, bottom-left, bottom-right).
2. **Leaf node check**: If all values in a quadrant are the same (either all 0s or all 1s), the corresponding node becomes a leaf node.
3. **Internal node creation**: If a quadrant has mixed values, it requires further subdivision until leaf nodes are formed.
4. **Optimization**: If all four sub-quadrants are identical, we can represent them with a single leaf node.

### Code Breakdown (Step by Step)

#### Step 1: Main Function – `construct`

The `construct` function is the main entry point for the solution. It takes a 2D grid as input and returns the root node of the constructed QuadTree.

```cpp
Node* construct(vector<vector<int>>& grid) {
    return helper(grid, 0, 0, grid.size());
}
```

This function simply invokes the recursive helper function `helper`, starting with the full grid (from index `(0, 0)` to `grid.size()`) to begin constructing the QuadTree.

#### Step 2: Recursive Helper Function – `helper`

The helper function is a recursive function that performs the core logic of subdividing the grid and creating nodes for the QuadTree. It works as follows:

```cpp
Node* helper(vector<vector<int>>& grid, int x, int y, int sz) {
    // Base case: If the grid is of size 1x1, create a leaf node.
    if (sz == 1) {
        return new Node(grid[x][y] != 0, true, NULL, NULL, NULL, NULL);
    }
```

- **Base Case**: When the size of the current sub-grid is 1x1, it is directly converted into a leaf node. The `Node` constructor is invoked with the value from the grid (`grid[x][y]`), and the `isLeaf` flag is set to `true`. If the value is `0`, the `val` is set to `false`, otherwise it is `true`.

#### Step 3: Recursive Subdivision and Node Creation

```cpp
Node* res = new Node();
Node* topRight = helper(grid, x , y + sz / 2, sz / 2);
Node* topLeft = helper(grid, x , y, sz / 2);
Node* bottomRight = helper(grid, x + sz / 2, y + sz / 2, sz / 2);
Node* bottomLeft = helper(grid, x + sz / 2, y, sz / 2);
```

- For grids larger than `1x1`, the current grid is divided into four smaller quadrants:
  - **Top-left**: From `(x, y)` to `(x + sz/2, y + sz/2)`
  - **Top-right**: From `(x, y + sz/2)` to `(x + sz/2, y + sz)`
  - **Bottom-left**: From `(x + sz/2, y)` to `(x + sz, y + sz/2)`
  - **Bottom-right**: From `(x + sz/2, y + sz/2)` to `(x + sz, y + sz)`

Each of these quadrants is recursively processed using the `helper` function.

#### Step 4: Merging the Results

```cpp
if (topRight->isLeaf && topLeft->isLeaf && bottomRight->isLeaf && bottomLeft->isLeaf && 
    topLeft->val == topRight->val && topRight->val == bottomRight->val && bottomRight->val == bottomLeft->val) {
    res->val = topLeft->val;
    res->isLeaf = true;
} else {
    res->topRight = topRight;
    res->topLeft = topLeft;
    res->bottomRight = bottomRight;
    res->bottomLeft = bottomLeft;
}
```

- **Merge Quadrants**: After recursively dividing the grid into quadrants, the next step is to check if all four quadrants are identical and can be merged into a single leaf node. This check is performed using the following conditions:
  - If all four quadrants are leaf nodes (`isLeaf == true`).
  - If the values of all four leaf nodes are the same.
  
  If these conditions are met, the current node (`res`) becomes a leaf node with the value of the shared quadrants. Otherwise, the current node is an internal node with four children (top-left, top-right, bottom-left, and bottom-right).

#### Step 5: Return the Constructed Node

Finally, after checking and possibly merging the quadrants, the constructed node is returned:

```cpp
return res;
```

This node represents the current grid or sub-grid, and the recursive calls continue until the entire grid is processed.

### Complexity

#### Time Complexity:
- The time complexity of this solution is `O(n)`, where `n` is the total number of cells in the grid. The recursive approach ensures that every cell is processed once, with each recursive step handling a smaller grid.

#### Space Complexity:
- The space complexity is `O(n)` due to the space used for the recursive call stack and the additional space required for storing the grid itself. In the worst case, the recursion depth is proportional to the number of grid cells.

### Conclusion

This solution efficiently constructs a QuadTree from a 2D binary grid using recursive subdivision. By leveraging the properties of leaf nodes and internal nodes, it reduces unnecessary subdivisions when all quadrants contain the same value. The approach ensures that the QuadTree is constructed optimally with a time complexity of `O(n)` and a space complexity of `O(n)`. This method provides a clean and efficient solution for handling QuadTree construction problems in a binary grid.

[`Link to LeetCode Lab`](https://leetcode.com/problems/construct-quad-tree/description/)

---
{{< youtube UQ-1sBMV0v4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
