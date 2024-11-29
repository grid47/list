
+++
authors = ["grid47"]
title = "Leetcode 2432: The Employee That Worked on the Longest Task"
date = "2024-03-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2432: The Employee That Worked on the Longest Task in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "BxVwXRLZlhk"
youtube_upload_date="2022-10-09"
youtube_thumbnail="https://i.ytimg.com/vi_webp/BxVwXRLZlhk/maxresdefault.webp"
comments = true
+++



---
You are given a group of employees, each identified by a unique ID. A series of tasks have been completed, where each task has a specific start and end time. Your task is to identify which employee worked the longest on a task. If there is a tie between multiple employees, return the one with the smallest ID. The time for each task is calculated by subtracting the start time from the end time, and each task starts right after the previous one ends.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two inputs: n (the total number of employees) and logs (a 2D array where each element logs[i] = [idi, leaveTimei], representing the ID of the employee and the time they finished the task).
- **Example:** `n = 5, logs = [[0,3],[1,7],[2,10],[0,15],[3,20]]`
- **Constraints:**
	- 2 <= n <= 500
	- 1 <= logs.length <= 500
	- logs[i].length == 2
	- 0 <= idi <= n - 1
	- 1 <= leaveTimei <= 500
	- logs are sorted in strictly increasing order of leaveTimei

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the ID of the employee who worked the longest on a task. If there is a tie, return the smallest ID.
- **Example:** `Output: 0`
- **Constraints:**
	- There will always be a unique solution.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine the employee who worked the longest by calculating the time each employee spent on tasks, then selecting the employee with the maximum task time.

- 1. Initialize variables to track the end time of the last task, the maximum task duration, and the employee ID.
- 2. Iterate through each task in logs and calculate the duration of each task.
- 3. Compare the duration of the current task with the maximum and update the employee ID accordingly, ensuring that ties are broken by selecting the smallest ID.
- 4. Return the ID of the employee with the longest task duration.
{{< dots >}}
### Problem Assumptions ✅
- The leaveTime for each task is unique.
- Each employee works on at least one task.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 5, logs = [[0,3],[1,7],[2,10],[0,15],[3,20]]`  \
  **Explanation:** In this case, the employee tasks are as follows: Task 0: [0, 3] (duration 3), Task 1: [1, 7] (duration 6), Task 2: [2, 10] (duration 3), Task 3: [0, 15] (duration 12), Task 4: [3, 20] (duration 5). The employee with ID 0 worked the longest (12 units), so the output is 0.

- **Input:** `n = 4, logs = [[0,4],[1,6],[0,9],[2,15]]`  \
  **Explanation:** Here, the tasks are: Task 0: [0, 4] (duration 4), Task 1: [1, 6] (duration 2), Task 2: [0, 9] (duration 5), Task 3: [2, 15] (duration 6). The longest task duration is 6 units, and employee with ID 2 worked the longest, so the output is 2.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to iterate through the tasks and compute the duration of each task for every employee. While doing so, we will track the maximum duration and the corresponding employee ID.

### Initial Thoughts 💭
- The task times are sequential, meaning each task starts immediately after the last one finishes.
- We can calculate the duration of each task by subtracting the leaveTime of the previous task from the current task's leaveTime.
{{< dots >}}
### Edge Cases 🌐
- There are no edge cases with empty inputs because logs will always have at least one entry.
- Ensure that the solution works within time limits for the maximum input size.
- Consider cases where all employees have equal task durations (e.g., tasks with the same duration for multiple employees).
- The solution must handle up to 500 tasks efficiently.
{{< dots >}}
## Code 💻
```cpp
  int hardestWorker(int n, vector<vector<int>>& logs) {
  int end = 0, id = 0, max_t = 0;
  for (auto &l : logs) {
      if (max_t <= l[1] - end) {
          id = max_t < l[1] - end ? l[0] : min(id, l[0]);
          max_t = l[1] - end;
      }
      end = l[1];
  }
  return id;
  }
```

This function identifies the hardest worker from a set of logs. It compares the time spent between different workers and returns the ID of the worker who worked the most.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	  int hardestWorker(int n, vector<vector<int>>& logs) {
	```
	Function definition where 'n' is the number of workers and 'logs' is a 2D vector containing the log of each worker's activity.

2. **Variable Initialization**
	```cpp
	  int end = 0, id = 0, max_t = 0;
	```
	Initializing variables: 'end' keeps track of the last log end time, 'id' stores the worker ID, and 'max_t' stores the maximum time worked by a worker.

3. **Loop**
	```cpp
	  for (auto &l : logs) {
	```
	For each log entry in 'logs', the loop processes worker details.

4. **Condition Check**
	```cpp
	      if (max_t <= l[1] - end) {
	```
	Checks if the current worker's time is greater than or equal to the max time tracked so far.

5. **Assign Worker ID**
	```cpp
	          id = max_t < l[1] - end ? l[0] : min(id, l[0]);
	```
	If the current worker's work time is greater than the max time, assign this worker's ID, else keep the current ID if the times are equal.

6. **Update Max Time**
	```cpp
	          max_t = l[1] - end;
	```
	Update the 'max_t' variable with the current worker's time worked.

7. **Update End Time**
	```cpp
	      end = l[1];
	```
	Set the 'end' variable to the current worker's log end time for comparison in the next iteration.

8. **Return Result**
	```cpp
	  return id;
	```
	Return the worker ID that worked the most time.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of logs. We only need to iterate through the logs once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we only use a constant amount of space to store the intermediate results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/the-employee-that-worked-on-the-longest-task/description/)

---
{{< youtube BxVwXRLZlhk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
