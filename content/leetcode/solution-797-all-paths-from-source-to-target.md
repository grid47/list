
+++
authors = ["grid47"]
title = "Leetcode 797: All Paths From Source to Target"
date = "2024-08-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 797: All Paths From Source to Target in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Backtracking","Depth-First Search","Breadth-First Search","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/797.webp"
youtube = "MQU2IIWwaOg"
youtube_upload_date="2024-04-06"
youtube_thumbnail="https://i.ytimg.com/vi/MQU2IIWwaOg/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/797.webp" 
    alt="A graph where all paths are traced from source to target, with each path softly glowing as it is found."
    caption="Solution to LeetCode 797: All Paths From Source to Target Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        queue<pair<int, vector<int>>> q;
        q.push({0, {0}});
        while(!q.empty()) {
            int x = q.front().first;
            vector<int> t = q.front().second;
            q.pop();
            if(x == graph.size() - 1) ans.push_back(t);
            for(int k: graph[x]) {
                t.push_back(k);
                q.push({k, t});
                t.pop_back();
            }
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement
In this problem, we are given a directed graph represented as an adjacency list `graph`, where each node is a non-negative integer. The task is to find all possible paths from the source node (node 0) to the target node (the last node in the graph). Each path must be a sequence of nodes that starts at node 0 and ends at the last node, following the directed edges of the graph.

This problem is essentially about finding all possible paths in a directed graph, starting from the source and ending at the target. The challenge is to explore all paths efficiently while adhering to the structure of the graph.

### Approach
The approach to solve this problem is to use **breadth-first search (BFS)** with a queue. The BFS technique is ideal for exploring all paths from the source to the target because it processes nodes level by level, ensuring that all possible paths are considered. By maintaining the path as we traverse the graph, we can capture all valid paths from the source to the target.

Here’s how we can break the problem into smaller steps:

1. **Use a Queue for BFS**: We'll utilize a queue where each element contains a node and the path taken to reach that node. This ensures that when we reach a node, we know the exact sequence of nodes leading up to it.
  
2. **Traverse the Graph**: From the source node, explore all adjacent nodes recursively, adding them to the current path.

3. **Capture Valid Paths**: Once we reach the target node (the last node in the graph), we add the current path to our result.

4. **Backtrack Efficiently**: Since we are using BFS, we will not need to explicitly backtrack. The queue takes care of processing the nodes in the correct order.

By using this BFS-based approach, we ensure that we explore all potential paths from the source to the target while maintaining efficiency.

### Code Breakdown (Step by Step)

Let’s go through the code step by step to understand its implementation:

#### Step 1: Initialize the Result and Queue
```cpp
vector<vector<int>> ans;
queue<pair<int, vector<int>>> q;
q.push({0, {0}});
```
- `ans`: A vector of vectors that will store all valid paths from the source to the target.
- `q`: A queue used to perform the breadth-first search (BFS). Each element in the queue is a pair, where:
  - The first element is a node `x`.
  - The second element is a vector of integers representing the current path taken to reach node `x`.
- Initially, we push the source node (node 0) into the queue, with the path being `{0}`.

#### Step 2: Start BFS Loop
```cpp
while(!q.empty()) {
    int x = q.front().first;
    vector<int> t = q.front().second;
    q.pop();
```
- The loop continues as long as there are elements in the queue. This ensures that we process all nodes and paths.
- We pop the front element of the queue to get the current node `x` and the path `t` taken to reach that node.
  
#### Step 3: Check for Target Node
```cpp
if(x == graph.size() - 1) ans.push_back(t);
```
- If the current node `x` is the target node (the last node in the graph, which is `graph.size() - 1`), we add the current path `t` to the result `ans`. This indicates that we’ve found a valid path from the source to the target.

#### Step 4: Explore Adjacent Nodes
```cpp
for(int k: graph[x]) {
    t.push_back(k);
    q.push({k, t});
    t.pop_back();
}
```
- For each adjacent node `k` to the current node `x` (i.e., each node that can be reached directly from node `x`), we do the following:
  - Add node `k` to the current path `t`.
  - Push the new node `k` and the updated path `t` into the queue. This ensures that we continue exploring paths from node `k`.
  - After the push, we backtrack by removing node `k` from the path `t` using `t.pop_back()`. This is necessary because we need to keep `t` intact for future iterations, maintaining the correct path sequence.

#### Step 5: Return the Result
```cpp
return ans;
```
- Once the BFS loop has processed all possible paths, we return the result `ans`, which contains all valid paths from the source to the target node.

### Complexity

#### Time Complexity:
The time complexity of this solution is **O(N + E)**, where:
- `N` is the number of nodes in the graph (i.e., `graph.size()`).
- `E` is the total number of edges in the graph (i.e., the sum of the lengths of the adjacency lists in the `graph`).

This is because each node and edge is processed at most once during the BFS. For each node, we explore all of its neighbors (edges), and for each edge, we push a new path into the queue. Therefore, the overall time complexity depends on the number of nodes and edges in the graph.

#### Space Complexity:
The space complexity is **O(N + E)** due to:
- The space required for storing the graph, which is `O(N + E)` as it is represented as an adjacency list.
- The space required for the queue, which could store paths for each possible traversal of the graph. In the worst case, the queue can hold a number of paths proportional to the number of edges.

Thus, the space complexity is dominated by the graph's adjacency list and the queue that stores the paths during BFS.

### Conclusion

This solution uses breadth-first search (BFS) to explore all possible paths from the source node (0) to the target node (the last node in the graph). The BFS approach is suitable because it ensures that all paths are considered without unnecessary recomputation. By maintaining the path along with the node being processed, we are able to efficiently capture all valid paths from the source to the target.

The algorithm is efficient, with a time complexity of O(N + E) and space complexity of O(N + E), making it scalable to large graphs. The use of a queue allows us to explore the graph level by level, ensuring that every potential path is processed correctly. The backtracking step (via `t.pop_back()`) ensures that paths are managed efficiently without modifying the paths prematurely.

This method is optimal for finding all paths in a directed graph from a given source to a target, and its clear and straightforward implementation ensures that it can be easily adapted for similar graph traversal problems.

[`Link to LeetCode Lab`](https://leetcode.com/problems/all-paths-from-source-to-target/description/)

---
{{< youtube MQU2IIWwaOg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
