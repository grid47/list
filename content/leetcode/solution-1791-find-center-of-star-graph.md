
+++
authors = ["grid47"]
title = "Leetcode 1791: Find Center of Star Graph"
date = "2024-05-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1791: Find Center of Star Graph in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Graph"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "jBD2_Eh4SlU"
youtube_upload_date="2021-03-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/jBD2_Eh4SlU/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findCenter(vector<vector<int>>& e) {
    return e[0][0] == e[1][0] || e[0][0] == e[1][1] ? e[0][0] : e[0][1];
}
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to identify the "center" of a star graph. A star graph is defined as a tree with one internal node (the center) connected to all other nodes (the leaves). In the context of this problem, we are given edges of a star graph in the form of a 2D vector where each element represents an edge connecting two nodes. The task is to find the center node efficiently.

### Approach

To solve this problem, we can leverage the properties of a star graph:

1. **Understanding the Structure**: In a star graph, the center node is connected directly to all other nodes. This means that if we look at the first two edges of the graph, the center node will appear in both edges.

2. **Direct Comparison**: We can simply check which of the two nodes in the first edge appears in the second edge. If one of them does, it is the center. If neither appears in both, then the other node in the first edge must be the center.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the provided code:

```cpp
class Solution {
public:
    int findCenter(vector<vector<int>>& e) {
```
- We define a class named `Solution` and declare a public method `findCenter` that takes a 2D vector `e` representing the edges of the star graph.

```cpp
    return e[0][0] == e[1][0] || e[0][0] == e[1][1] ? e[0][0] : e[0][1];
```
- This single line of code contains the core logic to determine the center node. 
- We use a conditional (ternary) operator to perform our checks:
  - First, we check if the first node of the first edge (`e[0][0]`) is equal to the first node of the second edge (`e[1][0]`). If they are equal, `e[0][0]` is the center, and we return it.
  - If that condition is not satisfied, we then check if `e[0][0]` is equal to the second node of the second edge (`e[1][1]`). If they are equal, `e[0][0]` is again the center, and we return it.
  - If neither condition is satisfied, we return the second node of the first edge (`e[0][1]`), which must be the center because it is connected to the first node in both edges.

### Complexity

- **Time Complexity**: The time complexity of this solution is \(O(1)\). This is because we are performing a constant number of operations regardless of the size of the input.
  
- **Space Complexity**: The space complexity is also \(O(1)\) since we are not using any additional data structures that scale with the size of the input.

### Conclusion

The `findCenter` function provides a highly efficient way to identify the center of a star graph using simple comparisons. This solution is optimal because it achieves the desired result in constant time and space, making it suitable for even large datasets.

Understanding how to efficiently determine the center of a star graph is essential for solving similar problems in graph theory and algorithm design. This knowledge can be applied in various areas, including networking, tree data structures, and other scenarios where hierarchical relationships are analyzed.

In practical applications, such as in social networks or communication networks, the concept of a central node can help in understanding key influencers or central servers, enhancing overall performance and connectivity analysis. As such, the ability to quickly identify such nodes is a valuable skill in both academic and professional settings.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-center-of-star-graph/description/)

---
{{< youtube jBD2_Eh4SlU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
