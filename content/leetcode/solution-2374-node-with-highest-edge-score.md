
+++
authors = ["grid47"]
title = "Leetcode 2374: Node With Highest Edge Score"
date = "2024-03-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2374: Node With Highest Edge Score in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "1egOQhIT9Gg"
youtube_upload_date="2022-08-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/1egOQhIT9Gg/maxresdefault.webp"
comments = true
+++



---
You are given a directed graph where each node has exactly one outgoing edge, and the graph is represented by an integer array `edges` of size n. The value at `edges[i]` indicates that there is a directed edge from node i to node `edges[i]`. The edge score of a node i is the sum of all the node labels that have an edge pointing to i. Your task is to find the node with the highest edge score. If multiple nodes have the same edge score, return the node with the smallest index.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `edges` of size n where each element in the array represents an outgoing edge from node i.
- **Example:** `edges = [1, 0, 0, 0, 0, 7, 7, 5]`
- **Constraints:**
	- 2 <= n <= 10^5
	- 0 <= edges[i] < n
	- edges[i] != i

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the index of the node with the highest edge score. If multiple nodes have the same edge score, return the smallest index.
- **Example:** `Output: 7`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the edge score for each node and determine the node with the highest edge score.

- 1. Initialize a map to store the sum of edge scores for each node.
- 2. Iterate through the `edges` array and update the edge scores for the target nodes.
- 3. Track the node with the highest edge score, resolving ties by selecting the smallest index.
{{< dots >}}
### Problem Assumptions ✅
- The graph is a directed graph where each node has exactly one outgoing edge.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: edges = [1, 0, 0, 0, 0, 7, 7, 5]`  \
  **Explanation:** For this input, node 0 has the highest edge score, as the sum of labels of nodes pointing to it is 10 (nodes 1, 2, 3, 4). Node 7 has an edge score of 11 (nodes 5 and 6), which is the highest, so the output is 7.

- **Input:** `Input: edges = [2, 0, 0, 2]`  \
  **Explanation:** In this case, both nodes 0 and 2 have an edge score of 3. Since node 0 has the smallest index, the output is 0.

{{< dots >}}
## Approach 🚀
This problem can be solved by keeping track of the sum of node labels for each target node. The solution involves iterating over the array and updating the edge scores for each target node.

### Initial Thoughts 💭
- We need to track the sum of node labels for each target node to calculate the edge scores.
- We should efficiently track the node with the highest edge score while handling ties.
- A hashmap is an efficient choice to store edge scores and resolve ties based on the node index.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least two nodes in the input.
- The solution should efficiently handle graphs with up to 100,000 nodes.
- If multiple nodes have the same edge score, return the node with the smallest index.
- The graph will always be a valid directed graph where no node points to itself.
{{< dots >}}
## Code 💻
```cpp
int edgeScore(vector<int>& edges) {
    map<int, long long> mp;
    int n = edges.size();
    int mx = -1, idx = -1;
    for(int i = 0; i < n; i++) {
        mp[edges[i]] += i;
        if(mp[edges[i]] > mx) {
            idx = edges[i];
            mx = mp[edges[i]];
        } else if(mp[edges[i]] == mx) {
            if(edges[i] < idx)
                idx = edges[i];
        }
    }
    return idx;
}
```

This function calculates the edge score in a directed graph, where `edges` represents a list of outgoing edges from each node. The function returns the node with the highest score, where the score is the sum of indices of outgoing edges. In case of a tie, the smallest node is selected.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int edgeScore(vector<int>& edges) {
	```
	Defines the function `edgeScore` that takes a vector of integers `edges` and returns an integer representing the node with the highest edge score.

2. **Map Initialization**
	```cpp
	    map<int, long long> mp;
	```
	Initializes a map `mp` to store the sum of indices for each node, where the key is the node, and the value is the accumulated score.

3. **Size Calculation**
	```cpp
	    int n = edges.size();
	```
	Stores the size of the `edges` vector in variable `n`.

4. **Variable Initialization**
	```cpp
	    int mx = -1, idx = -1;
	```
	Initializes two variables: `mx` to track the maximum score (initialized to -1) and `idx` to track the node with the highest score (initialized to -1).

5. **Loop Start**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Starts a loop to iterate over each element of the `edges` vector.

6. **Update Map**
	```cpp
	        mp[edges[i]] += i;
	```
	Updates the map `mp` by adding the current index `i` to the score of the node represented by `edges[i]`.

7. **Max Score Check**
	```cpp
	        if(mp[edges[i]] > mx) {
	```
	Checks if the current node's score is greater than the maximum score `mx`.

8. **Update Max Score and Node**
	```cpp
	            idx = edges[i];
	```
	If the current node's score is higher, update `idx` to the current node.

9. **Update Max Score**
	```cpp
	            mx = mp[edges[i]];
	```
	Updates the maximum score `mx` to the current node's score.

10. **Tie Breaker**
	```cpp
	        } else if(mp[edges[i]] == mx) {
	```
	Checks if the current node's score is equal to the maximum score, indicating a tie.

11. **Handle Tie**
	```cpp
	            if(edges[i] < idx)
	```
	If the current node is smaller than the previously stored node, update `idx` to the current node.

12. **Update Node in Case of Tie**
	```cpp
	                idx = edges[i];
	```
	Updates the node `idx` to the current node in case of a tie in scores, favoring the smaller node.

13. **Return Statement**
	```cpp
	    return idx;
	```
	Returns the node with the highest score, or the smallest node in case of a tie.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), as we iterate through the `edges` array once, updating the edge scores for each node.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the map storing edge scores for each node.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/node-with-highest-edge-score/description/)

---
{{< youtube 1egOQhIT9Gg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
