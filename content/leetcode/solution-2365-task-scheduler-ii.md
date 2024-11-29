
+++
authors = ["grid47"]
title = "Leetcode 2365: Task Scheduler II"
date = "2024-03-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2365: Task Scheduler II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "iuiNCc0HkX8"
youtube_upload_date="2022-08-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/iuiNCc0HkX8/maxresdefault.webp"
comments = true
+++



---
You are given an array of integers, tasks, representing tasks that need to be completed in order. Each element in tasks[i] represents the type of the i-th task. Additionally, a positive integer space is provided, representing the minimum number of days that must pass after completing a task before another task of the same type can be performed. Each day, you either complete the next task or take a break. Your goal is to determine the minimum number of days needed to complete all tasks.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array tasks, where each element tasks[i] represents the type of the i-th task, and an integer space that represents the minimum number of days between completing tasks of the same type.
- **Example:** `tasks = [2, 3, 2, 3, 1], space = 2`
- **Constraints:**
	- 1 <= tasks.length <= 10^5
	- 1 <= tasks[i] <= 10^9
	- 1 <= space <= tasks.length

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer, representing the minimum number of days required to complete all tasks.
- **Example:** `Output: 7`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** We need to calculate the minimum number of days required to complete all tasks while respecting the space constraint between tasks of the same type.

- Use a map to track the last day a task type was completed.
- For each task, check if the task has been completed recently based on the space constraint.
- If the task can be completed immediately, proceed to the next task, else take a break until the task can be completed.
- Accumulate the days required for task completion and break days.
{{< dots >}}
### Problem Assumptions ✅
- The input tasks array will always have at least one task.
- The space constraint ensures that tasks of the same type cannot be performed consecutively without taking a break.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: tasks = [2, 3, 2, 3, 1], space = 2`  \
  **Explanation:** In this example, to complete all tasks in 7 days, we need to respect the space constraint. The sequence could look like: Day 1: task 0, Day 2: task 1, Day 3: break, Day 4: task 2, Day 5: break, Day 6: task 3, Day 7: task 4.

{{< dots >}}
## Approach 🚀
The solution involves tracking the last completion day for each task type and determining when a task can be completed again based on the space constraint.

### Initial Thoughts 💭
- We need to track the days each task type was last completed.
- If the same task appears, we must respect the space constraint before completing it again.
- The task completion logic can be optimized by using a map to efficiently track and update task completion days.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that the input will have at least one task, so no need to handle empty task arrays.
- The solution should efficiently handle arrays of up to 100,000 tasks.
- If tasks contains only one type of task, the solution must respect the space constraint and return the correct number of days.
- Ensure the solution handles cases where tasks are spaced just enough or need breaks in between.
{{< dots >}}
## Code 💻
```cpp
long long taskSchedulerII(vector<int>& tasks, int space) {
    
    map<int, long long> mp;
    
    long long n= tasks.size(), days = 0;
    
    int i = 0;
    while(i < n) {
        if(mp.count(tasks[i])) {
            if(days - mp[tasks[i]] > space) {
                mp[tasks[i]] = days;
                days++;
                i++;
            } else {
                days = mp[tasks[i]] + space + 1;
            }
        } else {
            mp[tasks[i]] = days;                
            days++;
            i++;
        }
    }
    
    
    return days;
}
```

This function schedules tasks given a set of task IDs and a space constraint between consecutive executions of the same task. It tracks the last execution day of each task and ensures there is a gap of at least 'space' days between the executions of the same task.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	long long taskSchedulerII(vector<int>& tasks, int space) {
	```
	This is the function declaration. It initializes the function 'taskSchedulerII', which takes a vector of tasks and a space value representing the required gap between the same tasks.

2. **Map Initialization**
	```cpp
	    map<int, long long> mp;
	```
	This declares a map 'mp' to store the last execution day of each task, where the task ID is the key and the execution day is the value.

3. **Task and Days Initialization**
	```cpp
	    long long n= tasks.size(), days = 0;
	```
	This line initializes 'n' to the number of tasks and 'days' to 0, which will be used to track the total number of days spent scheduling tasks.

4. **Loop Start**
	```cpp
	    int i = 0;
	```
	This initializes the index 'i' to 0, which will be used to iterate through the 'tasks' vector.

5. **While Loop**
	```cpp
	    while(i < n) {
	```
	This begins the while loop, which continues as long as there are tasks to schedule.

6. **Task Check**
	```cpp
	        if(mp.count(tasks[i])) {
	```
	This checks if the current task has been scheduled before by looking it up in the map 'mp'.

7. **Space Check**
	```cpp
	            if(days - mp[tasks[i]] > space) {
	```
	This checks if the space constraint has been satisfied, i.e., if the gap between the current day and the last execution of the same task is greater than 'space'.

8. **Task Scheduling**
	```cpp
	                mp[tasks[i]] = days;
	```
	This updates the map with the current task's last execution day.

9. **Increment Day and Task Index**
	```cpp
	                days++;
	```
	This increments the total number of days.

10. **Task Index Increment**
	```cpp
	                i++;
	```
	This increments the task index to move to the next task.

11. **Else Case**
	```cpp
	            } else {
	```
	If the space constraint is not met, the code moves to the else block.

12. **Adjust Days for Space**
	```cpp
	                days = mp[tasks[i]] + space + 1;
	```
	This adjusts the day count to ensure that the current task can only be scheduled after 'space' days from its last execution.

13. **Task Not Scheduled**
	```cpp
	        } else {
	```
	This block handles the case where the task has not been scheduled before.

14. **Task Scheduling (New Task)**
	```cpp
	            mp[tasks[i]] = days;                
	```
	This schedules the task by adding it to the map 'mp' with the current day.

15. **Increment Day and Task Index**
	```cpp
	            days++;
	```
	This increments the day count.

16. **Task Index Increment**
	```cpp
	            i++;
	```
	This increments the task index to move to the next task.

17. **Return Result**
	```cpp
	    return days;
	```
	This returns the total number of days it took to schedule all tasks while respecting the space constraint.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the tasks array, because we process each task exactly once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n), as we store the last completion day for each task type in the map.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/task-scheduler-ii/description/)

---
{{< youtube iuiNCc0HkX8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
