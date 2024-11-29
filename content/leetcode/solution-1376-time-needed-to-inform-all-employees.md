
+++
authors = ["grid47"]
title = "Leetcode 1376: Time Needed to Inform All Employees"
date = "2024-06-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1376: Time Needed to Inform All Employees in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "d0xAcl58SXg"
youtube_upload_date="2024-04-07"
youtube_thumbnail="https://i.ytimg.com/vi/d0xAcl58SXg/maxresdefault.jpg"
comments = true
+++



---
A company has `n` employees with a unique ID for each employee from 0 to n-1. The head of the company is the one with `headID`. Each employee has one direct manager. The head will inform his direct subordinates, and they will inform their subordinates, and so on until all employees know about the urgent news. Each employee needs `informTime[i]` minutes to inform their direct subordinates. Return the total time required to inform all employees.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer `n`, the number of employees in the company, the integer `headID`, which identifies the head of the company, an array `manager[]` of size `n` where `manager[i]` is the ID of the direct manager of employee `i`, and an array `informTime[]` of size `n` where `informTime[i]` is the time it takes for employee `i` to inform all of their direct subordinates.
- **Example:** `n = 6, headID = 2, manager = [2, 2, -1, 2, 2, 2], informTime = [0, 0, 1, 0, 0, 0]`
- **Constraints:**
	- 1 <= n <= 10^5
	- 0 <= headID < n
	- manager.length == n
	- 0 <= manager[i] < n
	- manager[headID] == -1
	- informTime.length == n
	- 0 <= informTime[i] <= 1000
	- informTime[i] == 0 if employee i has no subordinates.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer representing the total time required for all employees to be informed about the urgent news.
- **Example:** `1`
- **Constraints:**
	- The output will be a single integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine the total time needed for all employees to receive the news, considering the time each employee takes to inform their subordinates.

- Construct a graph representing the tree structure of employee-manager relationships.
- Use a depth-first search (DFS) approach to calculate the time required for each employee to inform their subordinates.
- For each employee, calculate the maximum time taken among their subordinates and add the time they take to inform them.
{{< dots >}}
### Problem Assumptions ✅
- The manager-subordinate relationships form a tree structure, ensuring that all employees can be informed.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime = [0,0,1,0,0,0]`  \
  **Explanation:** The head (employee 2) informs all the direct subordinates. The subordinates then take 1 minute to inform their own subordinates.

- **Input:** `n = 5, headID = 0, manager = [-1, 0, 0, 1, 1], informTime = [0, 10, 0, 0, 0]`  \
  **Explanation:** The head (employee 0) informs employees 1 and 2 in 10 minutes. Employee 1 further informs employees 3 and 4.

{{< dots >}}
## Approach 🚀
The problem is solved using depth-first search (DFS) to traverse the tree structure and calculate the time taken to inform all employees.

### Initial Thoughts 💭
- The problem essentially involves traversing a tree structure and calculating the total time recursively.
- Using DFS, we can compute the maximum time required to inform all subordinates for each employee.
{{< dots >}}
### Edge Cases 🌐
- If the tree has only one employee (head), the result will be 0.
- Ensure the solution works efficiently for large values of `n` up to 100,000.
- If all employees take 0 minutes to inform others, the result will be 0.
- The problem constraints guarantee a valid tree structure and that all employees can be informed.
{{< dots >}}
## Code 💻
```cpp
int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    map<int, vector<int>> gph;
    for(int i = 0; i < manager.size(); i++)
    gph[manager[i]].push_back(i);
    
    return dfs(headID, gph, informTime);
}

int dfs(int cur, map<int, vector<int>> &gph, vector<int> &it) {
    if(!gph.count(cur)) return 0;
    
    int mx = 0;
    for(auto x: gph[cur])
        mx = max(mx, dfs(x, gph, it));
    
    return mx + it[cur];
}

```

This is the complete implementation of the solution. It includes the main function `numOfMinutes` to calculate the total time and a helper function `dfs` for depth-first search to compute the maximum time required to inform all employees.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
	```
	The function `numOfMinutes` is the main entry point. It takes the number of employees `n`, the head of the company `headID`, a list of managers for each employee, and a list of the time taken by each employee to inform others.

2. **Map Initialization**
	```cpp
	    map<int, vector<int>> gph;
	```
	We declare a map `gph` where the key represents a manager's ID and the value is a vector of employees they manage.

3. **Looping**
	```cpp
	    for(int i = 0; i < manager.size(); i++)
	```
	We loop through the list of managers and create the graph where each employee is linked to their manager.

4. **Graph Construction**
	```cpp
	    gph[manager[i]].push_back(i);
	```
	For each employee `i`, we add them as a subordinate to their manager in the graph.

5. **Recursive Call**
	```cpp
	    return dfs(headID, gph, informTime);
	```
	We initiate the depth-first search starting from the `headID`, using the constructed graph and the `informTime` list to calculate the total time.

6. **Recursive Function**
	```cpp
	int dfs(int cur, map<int, vector<int>> &gph, vector<int> &it) {
	```
	The `dfs` function performs a depth-first search to find the maximum time needed to inform all subordinates of a particular employee.

7. **Base Case**
	```cpp
	    if(!gph.count(cur)) return 0;
	```
	If the current employee does not have any subordinates (i.e., they don't appear in the graph), return 0.

8. **Variable Declaration**
	```cpp
	    int mx = 0;
	```
	We declare a variable `mx` to track the maximum time it takes to inform subordinates.

9. **Iterate Over Subordinates**
	```cpp
	    for(auto x: gph[cur])
	```
	We iterate over all subordinates of the current employee.

10. **Recursive Call**
	```cpp
	        mx = max(mx, dfs(x, gph, it));
	```
	For each subordinate, we recursively calculate the time needed to inform them and their subordinates, updating `mx` with the maximum time.

11. **Return Statement**
	```cpp
	    return mx + it[cur];
	```
	After processing all subordinates, we return the maximum time plus the time it takes for the current employee to inform others.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) as each employee is visited once during DFS.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the recursion stack and the graph representation of the tree.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/time-needed-to-inform-all-employees/description/)

---
{{< youtube d0xAcl58SXg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
