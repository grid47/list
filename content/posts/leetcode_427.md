
+++
authors = ["Crafted by Me"]
title = "Leetcode 427: Construct Quad Tree"
date = "2023-09-02"
description = "Solution to Leetcode 427"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/construct-quad-tree/description/)

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


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

