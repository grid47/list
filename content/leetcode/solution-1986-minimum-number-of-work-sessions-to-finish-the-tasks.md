
+++
authors = ["grid47"]
title = "Leetcode 1986: Minimum Number of Work Sessions to Finish the Tasks"
date = "2024-04-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1986: Minimum Number of Work Sessions to Finish the Tasks in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Backtracking","Bit Manipulation","Bitmask"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "8TU3WceDlzI"
youtube_upload_date="2021-09-03"
youtube_thumbnail="https://i.ytimg.com/vi/8TU3WceDlzI/maxresdefault.jpg"
comments = true
+++



---
You are assigned several tasks, each with a specified time required to complete. A work session allows you to work continuously for up to sessionTime consecutive hours before taking a break. Your goal is to determine the minimum number of work sessions required to complete all tasks under the following conditions: 

- If a task is started in a session, it must be completed within that same session.
- You may complete the tasks in any order.
- You can begin a new task immediately after finishing the previous one.

Return the minimum number of work sessions needed to complete all tasks.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers 'tasks' where each element represents the time required to complete a task and an integer 'sessionTime' which defines the maximum allowed duration for each work session.
- **Example:** `tasks = [3, 1, 3, 2], sessionTime = 7`
- **Constraints:**
	- 1 <= n <= 14
	- 1 <= tasks[i] <= 10
	- max(tasks[i]) <= sessionTime <= 15

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of work sessions required to complete all tasks.
- **Example:** `Output: 2`
- **Constraints:**
	- The output should be an integer representing the minimum number of work sessions.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the number of work sessions required to finish all tasks while adhering to the constraints of session time.

- Use a backtracking approach to explore different task orderings and configurations for work sessions.
- For each combination of tasks, track the time spent in the current work session and check if the session time limit is exceeded.
- Memoize results to avoid redundant calculations and improve efficiency.
{{< dots >}}
### Problem Assumptions ✅
- The number of tasks is small enough (up to 14 tasks) that backtracking and memoization will be efficient.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: tasks = [3, 1, 3, 2], sessionTime = 7`  \
  **Explanation:** By sorting and grouping tasks, you can complete the tasks in two work sessions. The first session can handle tasks 3, 2, and 1 (3 + 2 + 1 = 6 hours). The second session handles the remaining task of 3 hours.

- **Input:** `Input: tasks = [4, 2, 5], sessionTime = 6`  \
  **Explanation:** You can complete all tasks in one session, as the sum of 4 + 2 = 6 hours is exactly equal to the session time.

{{< dots >}}
## Approach 🚀
We will solve this problem using backtracking, where we explore different ways to assign tasks to work sessions and use memoization to store the results of subproblems for efficiency.

### Initial Thoughts 💭
- The problem has a small number of tasks (up to 14), making backtracking feasible.
- Each session can handle a set of tasks as long as their total time does not exceed sessionTime.
- Using a recursive approach with memoization can reduce the number of redundant calculations, making the solution efficient.
{{< dots >}}
### Edge Cases 🌐
- The input will always contain at least one task, so no need to handle an empty input array.
- For larger inputs (up to 14 tasks), the algorithm should be efficient enough due to the constraints.
- When all tasks have the same time, it should be easy to group tasks together into fewer sessions.
- The number of tasks is small, so the solution needs to handle up to 14 tasks with backtracking.
{{< dots >}}
## Code 💻
```cpp
vector<int> task;
// map<int, map<int, int>> memo; map is costly
int memo[1<<15][16];
int minSessions(vector<int>& tasks, int sessionTime) {
    this->task = tasks;
    map<int, int> mp;
    int mask = 0;
    int tgt = ~(~0u << task.size());
    memset(memo, -1, sizeof(memo));
    // for(int i = 0; i < task.size(); i++)
    //     tgt |= 1 << i;
    return bt(tgt, 0, sessionTime, mask);
    
}

int bt(int tgt, int net, int st, int mask) {
    if(tgt == mask) {
        return 1;
    }
    if(memo[mask][net] != -1) return memo[mask][net];
    
    int ans = task.size();
    for(int i = 0; i < task.size(); i++) {
        if((mask >> i) & 1) continue;
        mask |= (1 << i);
        if(net + task[i] > st)
            ans = min(ans, 1 + bt(tgt, task[i], st, mask));
        else
            ans = min(ans, bt(tgt, net + task[i], st, mask));
        mask ^= (1 << i);
    }
    return memo[mask][net] = ans;
}

```

This solution minimizes the number of sessions needed to complete all tasks where each task takes a certain amount of time, and each session can only have a total time up to `sessionTime`. The solution uses bitmasking and memoization for optimization.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	vector<int> task;
	```
	Declares a vector `task` to store the time for each task.

2. **Memoization Array Initialization**
	```cpp
	int memo[1<<15][16];
	```
	Declares a 2D array `memo` to store the results of previously computed states, optimizing the recursive calls.

3. **Function Definition**
	```cpp
	int minSessions(vector<int>& tasks, int sessionTime) {
	```
	Defines the function `minSessions` which calculates the minimum number of sessions required to complete the tasks.

4. **Assign Task Array**
	```cpp
	    this->task = tasks;
	```
	Assigns the input `tasks` vector to the member variable `task` for further use in the function.

5. **Map Initialization**
	```cpp
	    map<int, int> mp;
	```
	Declares a map `mp` to store intermediate states, though it's not used in the solution.

6. **Mask Initialization**
	```cpp
	    int mask = 0;
	```
	Initializes the bitmask `mask` to represent the state of tasks that have been assigned to sessions.

7. **Target Mask Calculation**
	```cpp
	    int tgt = ~(~0u << task.size());
	```
	Calculates the target bitmask `tgt` that represents all tasks having been completed.

8. **Memoization Setup**
	```cpp
	    memset(memo, -1, sizeof(memo));
	```
	Initializes the memoization array `memo` to `-1`, indicating that no state has been computed yet.

9. **Recursive Call**
	```cpp
	    return bt(tgt, 0, sessionTime, mask);
	```
	Returns the result of the recursive function `bt`, which solves the problem using backtracking.

10. **Recursive Function Definition**
	```cpp
	int bt(int tgt, int net, int st, int mask) {
	```
	Defines the recursive function `bt` that performs backtracking to calculate the minimum number of sessions.

11. **Base Case Check**
	```cpp
	    if(tgt == mask) {
	```
	Checks if all tasks have been assigned to sessions by comparing the `tgt` and `mask` bitmasks.

12. **Base Case Return**
	```cpp
	        return 1;
	```
	Returns 1 if all tasks are completed, indicating that one session is sufficient.

13. **Memoization Check**
	```cpp
	    if(memo[mask][net] != -1) return memo[mask][net];
	```
	Checks if the result for the current state has already been computed and stored in `memo`.

14. **Variable Initialization**
	```cpp
	    int ans = task.size();
	```
	Initializes the variable `ans` to the maximum possible number of sessions (one session per task).

15. **Loop Through Tasks**
	```cpp
	    for(int i = 0; i < task.size(); i++) {
	```
	Iterates over each task in the `task` vector.

16. **Skip Already Assigned Task**
	```cpp
	        if((mask >> i) & 1) continue;
	```
	Checks if the task `i` has already been assigned by inspecting the corresponding bit in `mask`.

17. **Assign Task to Session**
	```cpp
	        mask |= (1 << i);
	```
	Assigns the task `i` to a session by setting the corresponding bit in `mask`.

18. **Check Session Time**
	```cpp
	        if(net + task[i] > st)
	```
	Checks if the task `i` can fit into the current session without exceeding `sessionTime`.

19. **Recursive Call with New Session**
	```cpp
	            ans = min(ans, 1 + bt(tgt, task[i], st, mask));
	```
	If the task does not fit in the current session, a new session is started and the recursive function is called.

20. **Recursive Call with Continued Session**
	```cpp
	        else
	```
	If the task fits in the current session, continue with the same session.

21. **Recursive Call with Updated State**
	```cpp
	            ans = min(ans, bt(tgt, net + task[i], st, mask));
	```
	Continues with the current session and the updated total time `net` after adding task `i`.

22. **Backtrack Task Assignment**
	```cpp
	        mask ^= (1 << i);
	```
	Backtracks by removing the task `i` from the session (resetting the corresponding bit in `mask`).

23. **Memoization Save**
	```cpp
	    return memo[mask][net] = ans;
	```
	Stores the result of the current state in `memo` to avoid redundant calculations.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n!)
- **Average Case:** O(n!)
- **Worst Case:** O(2^n)

The recursive approach explores all possible task groupings. However, memoization reduces redundant calculations, leading to faster results.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(2^n)

The space complexity is influenced by the memoization storage and the depth of the recursion stack.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/description/)

---
{{< youtube 8TU3WceDlzI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
