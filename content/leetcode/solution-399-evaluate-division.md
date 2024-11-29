
+++
authors = ["grid47"]
title = "Leetcode 399: Evaluate Division"
date = "2024-09-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 399: Evaluate Division in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Depth-First Search","Breadth-First Search","Union Find","Graph","Shortest Path"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/399.webp"
youtube = "B5uvxUfQxN4"
youtube_upload_date="2023-05-20"
youtube_thumbnail="https://i.ytimg.com/vi/B5uvxUfQxN4/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/399.webp" 
    alt="A set of equations forming a division problem, with the answer softly glowing as it is calculated."
    caption="Solution to LeetCode 399: Evaluate Division Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a list of equations and their corresponding values, where each equation represents a division between two variables. Your task is to determine the result of several queries asking for the division result of two given variables.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two lists: `equations` representing division relations and `values` representing the results of those divisions. You are also given a list of `queries` that you need to evaluate.
- **Example:** `Input: equations = [['a', 'b'], ['b', 'c']], values = [2.0, 3.0], queries = [['a', 'c'], ['b', 'a']]`
- **Constraints:**
	- 1 <= equations.length <= 20
	- 1 <= queries.length <= 20
	- Each equation contains two strings with lengths from 1 to 5.

{{< dots >}}
### Output Specifications 📤
- **Output:** For each query, return the result of the division if it can be determined, otherwise return -1.0.
- **Example:** `Output: [6.0, 0.5, -1.0, 1.0, -1.0]`
- **Constraints:**
	- The division is guaranteed to be valid for each equation.
	- Queries asking for divisions between undefined variables must return -1.0.

{{< dots >}}
### Core Logic 🔍
**Goal:** Use depth-first search (DFS) to explore possible paths in the graph and compute the result of each query.

- Construct a graph where each variable is a node, and each equation provides an edge with a weight representing the division result.
- For each query, use DFS to explore the graph from the starting node (variable) to the target node and compute the division result along the path.
{{< dots >}}
### Problem Assumptions ✅
- All equations are valid and there are no contradictions.
- Evaluating queries will not result in division by zero.
{{< dots >}}
## Examples 🧩
- **Input:** `For the equations [['a', 'b'], ['b', 'c']] and values [2.0, 3.0], the query ['a', 'c'] will return 6.0 because a / b = 2 and b / c = 3, so a / c = 2 * 3 = 6.`  \
  **Explanation:** We first find the direct relations between variables and then use those relations to compute the result for each query.

{{< dots >}}
## Approach 🚀
The problem can be approached by constructing a graph from the equations, where each node represents a variable, and each edge represents a division relation. DFS is then used to traverse the graph to find answers to the queries.

### Initial Thoughts 💭
- Equations form a graph structure, with variables as nodes and division results as edge weights.
- We need to perform DFS to explore possible paths and compute the result for each query.
{{< dots >}}
### Edge Cases 🌐
- Queries for undefined variables should return -1.0.
- Handle large numbers of equations and queries efficiently.
- Return -1.0 for queries involving variables that do not appear in the equations.
- Queries involving variables not present in the equations are invalid and should return -1.0.
{{< dots >}}
## Code 💻
```cpp
vector<double> calcEquation(vector<vector<string>>& eqn, vector<double>& val, vector<vector<string>>& q) {
    map<string, vector<pair<string, double>>> graph;
    
    for(int i = 0; i < eqn.size(); i++) {
        double w = val[i];
        graph[eqn[i][0]].push_back(make_pair(eqn[i][1], w));
        if (w == 0) continue;
        graph[eqn[i][1]].push_back(make_pair(eqn[i][0], 1 / w));
    }
    
    vector<double> ans;
    
    for(int i = 0; i < q.size(); i++) {
        set<string> vis;
        double res = dfs(q[i][0], q[i][1], vis, graph);
        if(res < 0) res = -1;
        ans.push_back(res);
    }
    return ans;
}

double dfs(string start, string end, set<string> &vis, map<string, vector<pair<string, double>>> &gph) {
    
    if(start == end) return gph.count(start)? 1: -1;
    vis.insert(start);
    double ans = -1;
    for(pair<string, double> x: gph[start]) {
        if(vis.count(x.first)) continue;

        double res = x.second * dfs(x.first, end, vis, gph);
        if(res < 0) continue;
        return res;
    }
    return ans;
}
```

This solution calculates the result of equations represented as pairs of strings using a graph structure and depth-first search (DFS). The graph stores each variable's relationships, and DFS explores possible paths to compute the result of a given equation.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<double> calcEquation(vector<vector<string>>& eqn, vector<double>& val, vector<vector<string>>& q) {
	```
	Define the main function `calcEquation` that takes the list of equations (`eqn`), their corresponding values (`val`), and queries (`q`) as input.

2. **Graph Representation**
	```cpp
	    map<string, vector<pair<string, double>>> graph;
	```
	Create a graph to represent the equations where each node is a string (variable) and each edge is a pair (connected variable and the corresponding value).

3. **Graph Construction**
	```cpp
	    for(int i = 0; i < eqn.size(); i++) {
	```
	Loop through the list of equations to build the graph with the given relationships between variables.

4. **Graph Construction**
	```cpp
	        double w = val[i];
	```
	Extract the weight (value) associated with the current equation.

5. **Graph Construction**
	```cpp
	        graph[eqn[i][0]].push_back(make_pair(eqn[i][1], w));
	```
	For each equation, add the relationship between the first variable and the second variable with the corresponding value to the graph.

6. **Edge Case Handling**
	```cpp
	        if (w == 0) continue;
	```
	Skip equations where the value is zero to avoid division by zero.

7. **Graph Construction**
	```cpp
	        graph[eqn[i][1]].push_back(make_pair(eqn[i][0], 1 / w));
	```
	Add the inverse relationship to the graph for the second variable.

8. **Initialization**
	```cpp
	    vector<double> ans;
	```
	Initialize a vector `ans` to store the results of the queries.

9. **Query Loop**
	```cpp
	    for(int i = 0; i < q.size(); i++) {
	```
	Loop through the queries to calculate the result for each pair of variables.

10. **Visited Set**
	```cpp
	        set<string> vis;
	```
	Create a set `vis` to keep track of visited nodes (variables) during the DFS traversal.

11. **DFS Call**
	```cpp
	        double res = dfs(q[i][0], q[i][1], vis, graph);
	```
	Call the `dfs` function to compute the result of the query.

12. **Edge Case Handling**
	```cpp
	        if(res < 0) res = -1;
	```
	If the result is negative (meaning no path was found), set the result to -1.

13. **Store Result**
	```cpp
	        ans.push_back(res);
	```
	Store the result of the query in the `ans` vector.

14. **Return Result**
	```cpp
	    return ans;
	```
	Return the vector `ans` containing the results of all queries.

15. **DFS Function**
	```cpp
	double dfs(string start, string end, set<string> &vis, map<string, vector<pair<string, double>>> &gph) {
	```
	Define the `dfs` function that performs a depth-first search to find the path between two variables.

16. **DFS Base Case**
	```cpp
	    if(start == end) return gph.count(start)? 1: -1;
	```
	If the start and end variables are the same, return 1 if the variable exists in the graph, or -1 if not.

17. **Mark Visited**
	```cpp
	    vis.insert(start);
	```
	Mark the current node (variable) as visited.

18. **DFS Initialization**
	```cpp
	    double ans = -1;
	```
	Initialize a variable `ans` to store the result of the DFS traversal.

19. **DFS Traversal**
	```cpp
	    for(pair<string, double> x: gph[start]) {
	```
	Iterate through all neighbors of the current node (variable).

20. **DFS Pruning**
	```cpp
	        if(vis.count(x.first)) continue;
	```
	Skip already visited nodes to avoid infinite loops.

21. **Recursive DFS**
	```cpp
	        double res = x.second * dfs(x.first, end, vis, gph);
	```
	Recursively call the `dfs` function for the neighboring node and calculate the result.

22. **DFS Result Check**
	```cpp
	        if(res < 0) continue;
	```
	If the result of the recursive call is negative (no path found), continue to the next neighbor.

23. **Return Result**
	```cpp
	        return res;
	```
	If a valid result is found, return it.

24. **Return Default**
	```cpp
	    return ans;
	```
	If no valid result was found, return the default value (-1).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(V + E) where V is the number of vertices (variables) and E is the number of edges (equations).
- **Average Case:** O(V + E) per query.
- **Worst Case:** O(V + E) per query.

The time complexity is linear with respect to the number of variables and equations, and each query requires traversal of the graph.

### Space Complexity 💾
- **Best Case:** O(V + E) for storing the graph.
- **Worst Case:** O(V + E) where V is the number of vertices and E is the number of edges.

The space complexity is proportional to the size of the graph created from the equations.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/evaluate-division/description/)

---
{{< youtube B5uvxUfQxN4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
