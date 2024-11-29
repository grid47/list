
+++
authors = ["grid47"]
title = "Leetcode 210: Course Schedule II"
date = "2024-10-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 210: Course Schedule II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Graph","Topological Sort"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/210.webp"
youtube = "2cpihwDznaw"
youtube_upload_date="2024-05-21"
youtube_thumbnail="https://i.ytimg.com/vi/2cpihwDznaw/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/210.webp" 
    alt="A series of tasks gently forming a schedule, with dependencies softly highlighted as the courses unfold."
    caption="Solution to LeetCode 210: Course Schedule II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a set of courses with prerequisites, and you need to find a valid order to take them, or return an empty array if no valid order exists.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a number of courses, `numCourses`, and a list of prerequisite pairs where each pair [ai, bi] indicates that you need to take course bi before course ai.
- **Example:** `[numCourses = 3, prerequisites = [[1,0], [2,1]]]`
- **Constraints:**
	- 1 <= numCourses <= 2000
	- 0 <= prerequisites.length <= numCourses * (numCourses - 1)
	- prerequisites[i].length == 2
	- 0 <= ai, bi < numCourses
	- ai != bi
	- All pairs [ai, bi] are distinct.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a valid order in which to complete all the courses, or an empty array if no valid order exists.
- **Example:** `For numCourses = 3 and prerequisites = [[1,0], [2,1]], the output is [0, 1, 2].`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine if it is possible to complete all the courses by sorting the courses in a valid order considering their prerequisites.

- Represent the courses and their prerequisites as a directed graph.
- Perform topological sorting on the graph using a queue to process nodes with no prerequisites.
- Return the topologically sorted order if all courses can be taken, otherwise return an empty array.
{{< dots >}}
### Problem Assumptions ✅
- The input courses and prerequisites form a directed graph, which may or may not have cycles.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1`  \
  **Explanation:** In this case, you need to take course 1 after course 0, and course 2 after course 1, so the valid order is [0, 1, 2].

- **Input:** `Example 2`  \
  **Explanation:** The courses form a directed graph with dependencies, and a valid order is [0, 2, 1, 3].

- **Input:** `Example 3`  \
  **Explanation:** The prerequisites form a cycle, making it impossible to complete the courses, so the output is an empty array.

{{< dots >}}
## Approach 🚀
This problem can be solved using topological sorting on a directed graph representing course dependencies.

### Initial Thoughts 💭
- The problem involves checking if a directed graph is acyclic and finding a valid topological order.
- A queue can be used to process nodes with no incoming edges (prerequisites), and we can iteratively build the valid order.
{{< dots >}}
### Edge Cases 🌐
- If no prerequisites are given, the courses can be completed in any order.
- The solution must handle up to 2000 courses efficiently.
- If the prerequisites form a cycle, it is impossible to complete the courses.
- Ensure that the solution works within the time limits for large arrays (O(n + m) time complexity).
{{< dots >}}
## Code 💻
```cpp
vector<int> findOrder(int n, vector<vector<int>>& pre) {
    
    vector<vector<int>> gph(n);
    vector<int> incnt(n, 0);
    for(int i = 0; i < pre.size(); i++) {
        gph[pre[i][1]].push_back(pre[i][0]);
        incnt[pre[i][0]]++;
    }

    queue<int> q;
    for(int i = 0; i < n; i++)
        if(incnt[i] == 0)
            q.push(i);
    vector<int> ans;
    while(!q.empty()) {
        int y = q.front();
        ans.push_back(y);
        q.pop();
        for(auto x: gph[y]) {
            incnt[x]--;
            if(incnt[x] == 0)
                q.push(x);
        }
    }
    return ans.size() == n? ans: vector<int>();
}
```

This code implements the topological sorting algorithm using Kahn's Algorithm, which is a method of performing a topological sort on a directed graph using a queue. It returns the order of courses or nodes that respect all prerequisites, or an empty vector if it's not possible.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> findOrder(int n, vector<vector<int>>& pre) {
	```
	Define the function `findOrder`, which takes an integer `n` (number of courses/nodes) and a 2D vector `pre` (prerequisites), and returns the topological order of nodes.

2. **Graph Initialization**
	```cpp
	    vector<vector<int>> gph(n);
	```
	Initialize an adjacency list `gph` to represent the directed graph, where each node will store a list of its neighbors (nodes that depend on it).

3. **In-degree Initialization**
	```cpp
	    vector<int> incnt(n, 0);
	```
	Initialize a vector `incnt` to keep track of the in-degree (number of incoming edges) for each node. Set all in-degrees initially to 0.

4. **Building Graph**
	```cpp
	    for(int i = 0; i < pre.size(); i++) {
	```
	Loop through the prerequisite pairs in `pre` to build the graph and update the in-degrees.

5. **Graph Population**
	```cpp
	        gph[pre[i][1]].push_back(pre[i][0]);
	```
	For each pair in `pre`, add the directed edge from `pre[i][1]` to `pre[i][0]` in the adjacency list `gph`.

6. **In-degree Update**
	```cpp
	        incnt[pre[i][0]]++;
	```
	Increase the in-degree of the node `pre[i][0]`, indicating that it has one more prerequisite.

7. **Queue Initialization**
	```cpp
	    queue<int> q;
	```
	Initialize a queue `q` to keep track of nodes with no prerequisites (i.e., nodes with an in-degree of 0).

8. **Queue Population**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Loop through all nodes and add those with no incoming edges (in-degree of 0) to the queue.

9. **In-degree Check**
	```cpp
	        if(incnt[i] == 0)
	```
	Check if the current node has no prerequisites (in-degree 0), indicating it can be processed.

10. **Queue Push**
	```cpp
	            q.push(i);
	```
	Add the current node with no prerequisites to the queue.

11. **Answer Initialization**
	```cpp
	    vector<int> ans;
	```
	Initialize an empty vector `ans` to store the topologically sorted nodes.

12. **Processing Queue**
	```cpp
	    while(!q.empty()) {
	```
	While the queue is not empty, process each node in topological order.

13. **Node Processing**
	```cpp
	        int y = q.front();
	```
	Get the front node from the queue to process.

14. **Answer Update**
	```cpp
	        ans.push_back(y);
	```
	Add the current node `y` to the answer vector `ans` as part of the topological order.

15. **Queue Pop**
	```cpp
	        q.pop();
	```
	Remove the processed node from the front of the queue.

16. **Graph Traversal**
	```cpp
	        for(auto x: gph[y]) {
	```
	For each node `x` that depends on the current node `y`, reduce its in-degree by 1.

17. **In-degree Decrement**
	```cpp
	            incnt[x]--;
	```
	Decrement the in-degree of node `x`, as one of its prerequisites (`y`) has been processed.

18. **Queue Update**
	```cpp
	            if(incnt[x] == 0)
	```
	If node `x` now has no prerequisites left (in-degree 0), it can be added to the queue.

19. **Queue Push Again**
	```cpp
	                q.push(x);
	```
	Add node `x` to the queue for processing.

20. **Return Statement**
	```cpp
	    return ans.size() == n? ans: vector<int>();
	```
	If all nodes have been processed (i.e., the answer size equals `n`), return the topologically sorted order; otherwise, return an empty vector indicating a cycle or an impossible ordering.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + m), where n is the number of courses and m is the number of prerequisites.
- **Average Case:** O(n + m), since all nodes and edges must be processed.
- **Worst Case:** O(n + m), in the worst case all courses and prerequisites must be processed.

The time complexity is dominated by the graph traversal and topological sorting.

### Space Complexity 💾
- **Best Case:** O(n + m), since all the nodes and edges must be stored in memory.
- **Worst Case:** O(n + m), to store the graph and incoming edges.

The space complexity is proportional to the number of nodes (courses) and edges (prerequisites).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/course-schedule-ii/description/)

---
{{< youtube 2cpihwDznaw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
