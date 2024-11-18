
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
+++



[`Problem Link`](https://leetcode.com/problems/construct-quad-tree/description/)
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/427.md" >}}
---
{{< youtube UQ-1sBMV0v4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #429: N-ary Tree Level Order Traversal](https://grid47.xyz/leetcode/solution-429-n-ary-tree-level-order-traversal/) |
| --- |
