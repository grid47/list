
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to schedule tasks in such a way that no task can be executed again within `space` days of its last occurrence. The tasks are represented by integers in the array `tasks`, and we are given an integer `space` which represents the number of days we need to wait before a task can be executed again. The goal is to determine the minimum number of days required to complete all tasks, considering the constraints on task repetition.

### Approach

The solution follows a greedy approach with the help of a **map** (or dictionary) to track the last execution day of each task. Here’s the step-by-step breakdown:

1. **Key Observation:**
   - A task can only be scheduled again after `space` days have passed since its last execution. If we attempt to schedule a task too soon (before the `space` period has passed), we need to jump forward in time (i.e., set the day counter to a value that reflects the gap).
   
2. **Greedy Strategy:**
   - We iterate over the tasks one by one. For each task, we check if it has been executed before (using the `map`).
   - If it has been executed before, we check if the time elapsed since the last execution of this task exceeds the `space` constraint. If it does, we can execute the task; otherwise, we must "skip" days to meet the constraint.
   - If the task hasn’t been executed before, we can execute it immediately and update its last execution day.

3. **Tracking the Last Execution:**
   - We use a map `mp` to track the last day a particular task was executed. This allows us to determine whether we can execute the task on the current day or need to wait until a later day.

4. **Counting the Total Days:**
   - We increment the `days` counter as we schedule each task, ensuring that we account for waiting periods whenever necessary.

### Code Breakdown (Step by Step)

#### Step 1: Initializing Variables

```cpp
long long taskSchedulerII(vector<int>& tasks, int space) {
    map<int, long long> mp;  // Map to track last execution day of each task
    long long n = tasks.size(), days = 0;  // n: number of tasks, days: total days
    int i = 0;
```

- The function starts by initializing the map `mp` to store the last execution day of each task.
- `n` stores the number of tasks, and `days` keeps track of the total number of days used to complete all tasks.
- `i` is used as the index to iterate through the list of tasks.

#### Step 2: Loop Through Tasks

```cpp
while (i < n) {
```

- The `while` loop runs until all tasks are scheduled (`i < n`).

#### Step 3: Check If Task Has Been Executed Before

```cpp
if (mp.count(tasks[i])) {
    if (days - mp[tasks[i]] > space) {
        mp[tasks[i]] = days;  // Update last execution day of the task
        days++;  // Increment day count
        i++;  // Move to the next task
    } else {
        days = mp[tasks[i]] + space + 1;  // Skip to the next available day
    }
}
```

- For each task `tasks[i]`, we first check if it has been executed previously by checking if it exists in the map (`mp.count(tasks[i])`).
- If the task has been executed before, we check whether enough days have passed since its last execution. If the gap between `days` and the last execution day is greater than `space`, we can execute the task. We then:
  - Update the task’s last execution day to the current `days`.
  - Increment `days` and move to the next task (`i++`).
- If not enough time has passed since the last execution, we set the current `days` to the next available day, which is `mp[tasks[i]] + space + 1`.

#### Step 4: Schedule the Task if It’s New

```cpp
else {
    mp[tasks[i]] = days;  // Task has never been executed before
    days++;  // Increment day count
    i++;  // Move to the next task
}
```

- If the task hasn’t been executed before, we can schedule it immediately:
  - We record the current day as the last execution day of the task (`mp[tasks[i]] = days`).
  - We increment `days` and move to the next task.

#### Step 5: Return the Total Days

```cpp
return days;
```

- After all tasks have been scheduled, the function returns the total number of days (`days`), which accounts for both task execution and any waiting periods due to the `space` constraint.

### Complexity

#### Time Complexity:

- The algorithm iterates through the list of tasks once, so the time complexity of the loop is `O(n)`, where `n` is the number of tasks.
- For each task, we perform constant-time operations (checking the map, updating values, and incrementing counters).
- Thus, the overall time complexity is `O(n)`.

#### Space Complexity:

- The space complexity is dominated by the map `mp`, which stores the last execution day of each task. In the worst case, every task could be unique, leading to a space complexity of `O(n)`.

### Conclusion

This solution efficiently schedules tasks while respecting the `space` constraint using a greedy approach with a map to track the last execution day of each task. The algorithm runs in linear time (`O(n)`), making it well-suited for large input sizes. By updating the `days` counter and checking if tasks can be scheduled based on the `space` constraint, the solution ensures that all tasks are completed in the minimum number of days possible, while also handling any necessary waiting periods between repeated tasks. The approach is both time-efficient and space-efficient, making it ideal for real-world applications involving task scheduling with constraints.

[`Link to LeetCode Lab`](https://leetcode.com/problems/task-scheduler-ii/description/)

---
{{< youtube iuiNCc0HkX8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
