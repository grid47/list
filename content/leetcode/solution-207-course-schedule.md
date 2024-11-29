
+++
authors = ["grid47"]
title = "Leetcode 207: Course Schedule"
date = "2024-10-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 207: Course Schedule in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Graph","Topological Sort"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/207.webp"
youtube = "IWLpZbu1wco"
youtube_upload_date="2020-06-26"
youtube_thumbnail="https://i.ytimg.com/vi/IWLpZbu1wco/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/207.webp" 
    alt="A calming flowchart with courses linking together, showing dependencies in a gentle, glowing path."
    caption="Solution to LeetCode 207: Course Schedule Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a set of courses and a list of prerequisites. Each prerequisite is a pair of courses where the second course must be taken before the first one. Determine if it is possible to complete all courses based on these prerequisites. If there are cycles in the dependencies, it would be impossible to finish all courses.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer numCourses representing the total number of courses and an array prerequisites where each element [a, b] indicates that course b must be completed before course a.
- **Example:** `numCourses = 3, prerequisites = [[1, 0], [2, 1]]`
- **Constraints:**
	- 1 <= numCourses <= 2000
	- 0 <= prerequisites.length <= 5000
	- prerequisites[i].length == 2
	- 0 <= ai, bi < numCourses
	- All prerequisites pairs are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if it is possible to finish all the courses. Otherwise, return false.
- **Example:** `Output: true`
- **Constraints:**
	- The returned value must indicate whether it is possible to complete all courses given the prerequisites.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine if there is a cycle in the prerequisite graph. If there is no cycle, return true. If a cycle exists, return false.

- Create a graph where each course points to its dependent courses.
- Use a counter to track the number of prerequisites for each course.
- Start with the courses that have no prerequisites and reduce the count of prerequisites for their dependent courses.
- If all courses can be completed (i.e., the prerequisite counter reaches zero for all), return true. Otherwise, return false if any course cannot be completed.
{{< dots >}}
### Problem Assumptions ✅
- The input graph is well-formed with valid course numbers and prerequisites.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: numCourses = 2, prerequisites = [[1, 0]]`  \
  **Explanation:** There are 2 courses. To take course 1, you must first take course 0. This is possible, so the output is true.

- **Input:** `Input: numCourses = 2, prerequisites = [[1, 0], [0, 1]]`  \
  **Explanation:** There are 2 courses. Course 1 requires course 0, and course 0 requires course 1. This forms a cycle, so it is impossible to complete all courses. The output is false.

{{< dots >}}
## Approach 🚀
The solution involves topological sorting of the graph formed by courses and their prerequisites. If there is a cycle in the graph, it is impossible to complete all courses.

### Initial Thoughts 💭
- The problem can be viewed as a cycle detection problem in a directed graph.
- Topological sorting using Kahn's algorithm can be used to detect cycles efficiently.
{{< dots >}}
### Edge Cases 🌐
- If there are no prerequisites, you can finish all courses.
- The solution should handle up to 2000 courses and 5000 prerequisites efficiently.
- If there is only one course, it can always be completed.
- Ensure that the solution handles cycles efficiently, especially with a large number of courses.
{{< dots >}}
## Code 💻
```cpp
bool canFinish(int n, vector<vector<int>>& pre) {
    vector<vector<int>> graph(n);
    vector<int> cnt(n, 0);

    // Created graph and dependecy counter
    for(int i = 0; i < pre.size(); i++) {
        graph[pre[i][1]].push_back(pre[i][0]);
        cnt[pre[i][0]]++;
    }

     queue<int> q;

    // Triaged course which does not have any dependency.
    for(int i = 0; i < n; i++)
        if(cnt[i] == 0)
            q.push(i);
   

    while(!q.empty()) {
        int size = q.size();
        while(size-- > 0) {
            int course = q.front();
            q.pop();
            for(int dep: graph[course]) {

                cnt[dep]--;

                if(cnt[dep] == 0) {
                    q.push(dep);
                }
            }                
        }
    }

    for(int i = 0; i < n; i++)
        if(cnt[i] != 0)
            return false;   

    return true;
}
```

This function checks whether it's possible to finish all courses given the prerequisites. It uses a graph and dependency counter to simulate course ordering, employing a queue for processing courses that can be taken next.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool canFinish(int n, vector<vector<int>>& pre) {
	```
	Define the function `canFinish` which takes the number of courses `n` and a vector of prerequisites `pre` representing course dependencies.

2. **Graph Initialization**
	```cpp
	    vector<vector<int>> graph(n);
	```
	Initialize a graph where each course is represented by an index, and the corresponding vector stores its dependent courses.

3. **Dependency Counter Initialization**
	```cpp
	    vector<int> cnt(n, 0);
	```
	Initialize a counter array `cnt` to track the number of prerequisites (dependencies) each course has.

4. **Graph and Dependency Counter Update**
	```cpp
	    for(int i = 0; i < pre.size(); i++) {
	```
	Iterate through each prerequisite pair in the `pre` list.

5. **Graph Update**
	```cpp
	        graph[pre[i][1]].push_back(pre[i][0]);
	```
	For each prerequisite, add the dependent course to the corresponding graph entry.

6. **Dependency Counter Update**
	```cpp
	        cnt[pre[i][0]]++;
	```
	Increment the counter for the dependent course, indicating it has one more prerequisite.

7. **Queue Declaration**
	```cpp
	     queue<int> q;
	```
	Declare a queue `q` to hold the courses that are ready to be taken (i.e., those with zero dependencies).

8. **Queue Population**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Loop through all courses to find those with no prerequisites.

9. **Queue Population Condition**
	```cpp
	        if(cnt[i] == 0)
	```
	Check if a course has no dependencies by examining its counter value.

10. **Enqueue Course**
	```cpp
	            q.push(i);
	```
	Add the course with no dependencies to the queue.

11. **While Queue Not Empty**
	```cpp
	    while(!q.empty()) {
	```
	Start a `while` loop to process courses in the queue until it's empty.

12. **Queue Size Calculation**
	```cpp
	        int size = q.size();
	```
	Get the current number of courses in the queue, which need to be processed.

13. **Inner While Loop**
	```cpp
	        while(size-- > 0) {
	```
	Iterate through all the courses in the queue.

14. **Dequeue Course**
	```cpp
	            int course = q.front();
	```
	Get the course at the front of the queue to process.

15. **Pop Course from Queue**
	```cpp
	            q.pop();
	```
	Remove the course from the queue after processing it.

16. **Process Dependencies**
	```cpp
	            for(int dep: graph[course]) {
	```
	For each dependent course of the current course, reduce its dependency count.

17. **Dependency Counter Decrement**
	```cpp
	                cnt[dep]--;
	```
	Decrement the counter for each dependent course, indicating one less prerequisite.

18. **Check If Course Is Ready**
	```cpp
	                if(cnt[dep] == 0) {
	```
	If a course now has no dependencies, it can be added to the queue.

19. **Enqueue Ready Course**
	```cpp
	                    q.push(dep);
	```
	Enqueue the course that has no remaining prerequisites.

20. **Final Check Loop**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Loop through all courses to check for any remaining prerequisites.

21. **Cycle Detection**
	```cpp
	        if(cnt[i] != 0)
	```
	If any course has remaining prerequisites, return `false` as there's a cycle.

22. **Return False**
	```cpp
	            return false;   
	```
	Return `false` indicating it's not possible to finish all courses due to a cycle.

23. **Final Return**
	```cpp
	    return true;
	```
	Return `true` if all courses can be finished without any cycles.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + e)
- **Average Case:** O(n + e)
- **Worst Case:** O(n + e)

The time complexity is O(n + e), where n is the number of courses and e is the number of prerequisites.

### Space Complexity 💾
- **Best Case:** O(n + e)
- **Worst Case:** O(n + e)

The space complexity is O(n + e) due to the graph representation and the prerequisite count array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/course-schedule/description/)

---
{{< youtube IWLpZbu1wco >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
