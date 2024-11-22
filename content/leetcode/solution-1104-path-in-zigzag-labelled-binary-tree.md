
+++
authors = ["grid47"]
title = "Leetcode 1104: Path In Zigzag Labelled Binary Tree"
date = "2024-07-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1104: Path In Zigzag Labelled Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {

public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        res.push_back(label);
        int level = log2(label);

        while (level != 0) {
            int left = pow(2 , (level - 1));
            int right = pow(2 , level) - 1;
            label = left + ( right- label / 2);

            res.push_back(label);
            level -= 1;
        }

        int num = res.size();
        reverse(res.begin(), res.end());

        return res;
    }
};
{{< /highlight >}}
---


### Problem Statement
The problem requires us to find the path from a given label to the root in a zigzag binary tree. In this tree:
- Each level alternates between left-to-right and right-to-left numbering.
- The root is labeled as 1, its children as 2 and 3, the next level as 4 to 7, and so on. For even levels, the numbering goes from right to left. 

Given a label, the task is to construct the path from the node with that label to the root of the tree.

### Approach
To solve this problem, we can leverage the properties of the zigzag binary tree. The key steps are:
1. **Identify the Level**: Determine the level of the given label using the logarithm base 2.
2. **Calculate Parent Node**: Use the properties of the zigzag tree to calculate the parent node by:
   - Identifying the left and right bounds for that level.
   - Applying the zigzag transformation to find the parent node.
3. **Trace the Path to Root**: Continue calculating the parent nodes until reaching the root, storing the results along the way.
4. **Reverse the Result**: Since the path is constructed from the label to the root, reverse the result to get it in the correct order.

### Code Breakdown (Step by Step)

1. **Class Definition**: The `Solution` class encapsulates the method to find the path.

   ```cpp
   class Solution {
   public:
   ```

2. **Method Declaration**: The method `pathInZigZagTree` takes an integer `label` and returns a vector of integers representing the path.

   ```cpp
       vector<int> pathInZigZagTree(int label) {
           vector<int> res;
           res.push_back(label);
   ```

3. **Determine the Level**: Calculate the level of the label in the binary tree using the base-2 logarithm.

   ```cpp
           int level = log2(label);
   ```

4. **Loop to Trace the Path**: Use a loop to compute the path to the root. The loop continues until the level reaches zero.

   ```cpp
           while (level != 0) {
               int left = pow(2 , (level - 1));
               int right = pow(2 , level) - 1;
               label = left + ( right - label / 2);
               res.push_back(label);
               level -= 1;
           }
   ```

   - **Calculate Left and Right Bounds**: The variables `left` and `right` represent the start and end of the current level.
   - **Find the Parent**: The expression `left + (right - label / 2)` determines the parent node in the zigzag pattern.

5. **Reverse the Result**: After constructing the path in reverse order, it is reversed to return the correct order from root to the label.

   ```cpp
           int num = res.size();
           reverse(res.begin(), res.end());
           return res;
       }
   };
   ```

### Complexity Analysis
- **Time Complexity**: The time complexity of this solution is \(O(\log n)\), where \(n\) is the label value. This is because the number of levels in the tree is logarithmic relative to the value of the label.
- **Space Complexity**: The space complexity is also \(O(\log n)\) due to the storage of the result vector that holds the path from the label to the root.

### Conclusion
The provided C++ code efficiently finds the path from a given label to the root in a zigzag binary tree. By leveraging the logarithmic properties of binary trees and the specific structure of the zigzag arrangement, the solution efficiently calculates parent nodes and constructs the path.

The method `pathInZigZagTree` is both concise and effective, demonstrating how understanding tree properties can lead to elegant solutions. This approach not only showcases the mathematical foundations of binary trees but also highlights efficient coding practices that minimize unnecessary computations, making it suitable for larger values of labels.

Overall, this implementation is an excellent example of applying theoretical concepts in computer science to practical programming problems, and it serves as a useful reference for those looking to understand tree traversal in non-standard binary tree structures.


[`Link to LeetCode Lab`](https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
