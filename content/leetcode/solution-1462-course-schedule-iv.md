
+++
authors = ["grid47"]
title = "Leetcode 1462: Course Schedule IV"
date = "2024-06-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1462: Course Schedule IV in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Graph","Topological Sort"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "cEW05ofxhn0"
youtube_upload_date="2023-02-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/cEW05ofxhn0/maxresdefault.webp"
comments = true
+++



---
You are given a set of courses numbered from 0 to numCourses - 1 and a list of prerequisites. Each prerequisite is a pair [ai, bi], indicating that you must complete course ai before course bi. For a series of queries, where each query asks whether a specific course is a prerequisite for another, you are tasked with determining whether each query is true or false.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are provided with two inputs: numCourses, the number of courses, and prerequisites, an array of pairs indicating course dependencies. Additionally, you are given queries, where each query asks whether one course is a prerequisite for another.
- **Example:** `Input: numCourses = 3, prerequisites = [[1,0],[2,1],[2,0]], queries = [[1,0], [0,2]]`
- **Constraints:**
	- 2 <= numCourses <= 100
	- 0 <= prerequisites.length <= (numCourses * (numCourses - 1) / 2)
	- prerequisites[i].length == 2
	- 0 <= ai, bi <= numCourses - 1
	- ai != bi
	- All pairs [ai, bi] are unique
	- The graph of prerequisites contains no cycles
	- 1 <= queries.length <= 10^4
	- 0 <= ui, vi <= numCourses - 1
	- ui != vi

{{< dots >}}
### Output Specifications 📤
- **Output:** The output consists of a boolean array, where each element represents the answer to the corresponding query. If the first course in a query is a prerequisite of the second course, the corresponding answer is true; otherwise, it is false.
- **Example:** `Output: [true, false]`
- **Constraints:**
	- The output is an array of booleans, each indicating whether the first course in a query is a prerequisite for the second course.

{{< dots >}}
### Core Logic 🔍
**Goal:** Efficiently determine whether each course in the queries list is a prerequisite of another.

- Construct a graph where each node represents a course and an edge from course A to course B indicates that A is a prerequisite for B.
- For each course, perform a breadth-first search (BFS) to find all courses that are reachable from it.
- Store the reachable courses in a 2D array (reach), where reach[i][j] is true if course i is a prerequisite of course j.
- For each query, check the reach array to see if the first course is a prerequisite of the second.
{{< dots >}}
### Problem Assumptions ✅
- The graph of prerequisites is a Directed Acyclic Graph (DAG), meaning there are no cycles.
- The input queries are valid and do not contain any invalid course numbers.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: numCourses = 3, prerequisites = [[1,0],[2,1],[2,0]], queries = [[1,0], [0,2]]`  \
  **Explanation:** Output: [true, false]. Course 1 is a prerequisite of course 0, but course 0 is not a prerequisite of course 2.

- **Input:** `Input: numCourses = 2, prerequisites = [], queries = [[0,1], [1,0]]`  \
  **Explanation:** Output: [false, false]. Since there are no prerequisites, no course is a prerequisite of another.

{{< dots >}}
## Approach 🚀
To solve this problem, we will model the courses and their prerequisites as a directed graph and use breadth-first search (BFS) to find all prerequisites for each course.

### Initial Thoughts 💭
- The problem is essentially about finding transitive closures in a directed graph.
- BFS can be used to explore all courses reachable from a given course, thus identifying all its prerequisites.
- Using BFS to traverse the graph ensures we efficiently find all courses that are prerequisites for a given course.
{{< dots >}}
### Edge Cases 🌐
- If there are no prerequisites, all queries will return false unless they are self-referential.
- If there are a large number of queries (up to 10^4), the solution must handle them efficiently without repeated computations.
- For queries where both courses are the same, the result should always be true, as a course is trivially a prerequisite of itself.
- Ensure that the graph has no cycles, as stated in the problem's constraints.
{{< dots >}}
## Code 💻
```cpp
vector<bool> checkIfPrerequisite(int num, vector<vector<int>>& pre, vector<vector<int>>& q) {
    
    vector<vector<bool>> reach(num, vector<bool>(num, false));
    
    vector<vector<int>> grid(num);
    for(auto it: pre) {
        grid[it[0]].push_back(it[1]);
    }

    for(int i = 0; i < num; i++) {
        queue<int> q;
        q.push(i);
        vector<int> vis(num, 0);            
        vis[i] = true;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int tmp = q.front();

                q.pop();
                for(int it: grid[tmp]) {
                    reach[i][it] = true;
                    if(vis[it]) continue;
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
        
    }
    
    vector<bool> ans(q.size());
    for(int i = 0; i < q.size(); i++) {
        // is q[0] a pre of q[1];
        ans[i] = reach[q[i][0]][q[i][1]];
    }
    return ans;
}
```

This code determines whether one course is a prerequisite for another in a graph of courses. It uses breadth-first search (BFS) to check if a path exists between courses and returns the result for each query.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<bool> checkIfPrerequisite(int num, vector<vector<int>>& pre, vector<vector<int>>& q) {
	```
	This function checks if one course is a prerequisite for another, given a list of prerequisites and a set of queries. It returns a boolean vector indicating the answer for each query.

2. **Variable Initialization**
	```cpp
	    vector<vector<bool>> reach(num, vector<bool>(num, false));
	```
	Initializes a 2D boolean array 'reach' to keep track of whether a course can reach another course (i.e., if one is a prerequisite of the other).

3. **Graph Representation**
	```cpp
	    vector<vector<int>> grid(num);
	```
	Creates an adjacency list 'grid' where each index represents a course, and the list at each index holds courses that are directly dependent on that course.

4. **Edge Insertion**
	```cpp
	    for(auto it: pre) {
	```
	Iterates through each prerequisite pair, where 'it' contains two elements: the first is the prerequisite course, and the second is the course that depends on it.

5. **Edge Insertion**
	```cpp
	        grid[it[0]].push_back(it[1]);
	```
	Adds an edge to the adjacency list, indicating that course 'it[0]' is a prerequisite for course 'it[1]'.

6. **BFS Traversal**
	```cpp
	    for(int i = 0; i < num; i++) {
	```
	Iterates over each course to check which other courses it can reach using breadth-first search.

7. **Queue Initialization**
	```cpp
	        queue<int> q;
	```
	Initializes a queue for breadth-first search (BFS).

8. **Queue Operation**
	```cpp
	        q.push(i);
	```
	Pushes the current course (i) into the queue to begin BFS from that course.

9. **Visited Array Initialization**
	```cpp
	        vector<int> vis(num, 0);            
	```
	Initializes a 'vis' vector to track visited courses, ensuring each course is processed only once during BFS.

10. **Visited Array Update**
	```cpp
	        vis[i] = true;
	```
	Marks the current course as visited.

11. **BFS Loop**
	```cpp
	        while(!q.empty()) {
	```
	Starts the BFS loop, which continues as long as there are courses in the queue to process.

12. **Queue Size Calculation**
	```cpp
	            int sz = q.size();
	```
	Stores the number of courses in the queue at the beginning of each BFS iteration.

13. **BFS Loop Inner**
	```cpp
	            while(sz--) {
	```
	Processes all courses at the current BFS level.

14. **Queue Dequeue**
	```cpp
	                int tmp = q.front();
	```
	Gets the next course from the front of the queue to process.

15. **Queue Dequeue**
	```cpp
	                q.pop();
	```
	Removes the processed course from the queue.

16. **Neighbor Processing**
	```cpp
	                for(int it: grid[tmp]) {
	```
	Iterates over all courses that are directly dependent on the current course 'tmp'.

17. **Reach Update**
	```cpp
	                    reach[i][it] = true;
	```
	Marks that course 'it' is reachable from course 'i'.

18. **Visitation Check**
	```cpp
	                    if(vis[it]) continue;
	```
	Checks if the dependent course 'it' has already been visited. If it has, it skips to the next course.

19. **Mark as Visited**
	```cpp
	                    vis[it] = true;
	```
	Marks course 'it' as visited.

20. **Queue Push**
	```cpp
	                    q.push(it);
	```
	Adds course 'it' to the queue for further BFS processing.

21. **Answer Preparation**
	```cpp
	    vector<bool> ans(q.size());
	```
	Initializes a boolean vector 'ans' to store the results of each query.

22. **Query Evaluation**
	```cpp
	    for(int i = 0; i < q.size(); i++) {
	```
	Iterates through each query to check if the first course is a prerequisite of the second.

23. **Query Answering**
	```cpp
	        ans[i] = reach[q[i][0]][q[i][1]];
	```
	For each query, checks if the first course is a prerequisite of the second and stores the result in the 'ans' vector.

24. **Return Final Answer**
	```cpp
	    return ans;
	```
	Returns the vector 'ans', containing the results for each query.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + e)
- **Average Case:** O(n + e)
- **Worst Case:** O(n + e)

The time complexity is O(n + e), where n is the number of courses and e is the number of prerequisites. This is because we traverse all courses and their edges (dependencies) once.

### Space Complexity 💾
- **Best Case:** O(n + e)
- **Worst Case:** O(n^2)

In the worst case, space complexity is O(n^2) to store the reachability matrix, but in general, it will be O(n + e) for storing the graph and visited nodes.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/course-schedule-iv/description/)

---
{{< youtube cEW05ofxhn0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
