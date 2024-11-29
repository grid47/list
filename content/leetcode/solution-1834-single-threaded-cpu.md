
+++
authors = ["grid47"]
title = "Leetcode 1834: Single-Threaded CPU"
date = "2024-05-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1834: Single-Threaded CPU in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "RR1n-d4oYqE"
youtube_upload_date="2021-04-18"
youtube_thumbnail="https://i.ytimg.com/vi/RR1n-d4oYqE/maxresdefault.jpg"
comments = true
+++



---
You are given a list of tasks, where each task is represented by a pair of integers: [enqueueTime, processingTime]. The task can only be processed once its enqueueTime has passed. Your goal is to find the order in which tasks are processed by a single-threaded CPU that follows a specific processing strategy.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer n representing the number of tasks and a 2D array of integers tasks where each element tasks[i] = [enqueueTime[i], processingTime[i]].
- **Example:** `tasks = [[1,2], [2,4], [3,2], [4,1]]`
- **Constraints:**
	- 1 <= n <= 10^5
	- 1 <= enqueueTime[i], processingTime[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an array of integers representing the order in which the CPU processes the tasks.
- **Example:** `[0, 2, 3, 1]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine the order of task processing by the CPU based on the rules outlined.

- Sort the tasks based on their enqueueTime to determine when each task is available.
- Use a priority queue to store tasks based on their processing time and index.
- At each time step, process the task with the shortest processing time, breaking ties with the smallest index.
- Update the time as tasks are processed and track the order of processing.
{{< dots >}}
### Problem Assumptions ✅
- The CPU processes one task at a time, and no task is preempted once started.
{{< dots >}}
## Examples 🧩
- **Input:** `tasks = [[1,2], [2,4], [3,2], [4,1]]`  \
  **Explanation:** At time = 1, task 0 is available, and the CPU starts processing it. The CPU continues processing tasks in the order of their availability and processing times, resulting in the output [0, 2, 3, 1].

{{< dots >}}
## Approach 🚀
We will use sorting and a priority queue to solve the problem efficiently. First, we sort the tasks by enqueueTime, and then use a priority queue to process the tasks with the shortest processing times first.

### Initial Thoughts 💭
- The CPU will process tasks based on their enqueueTime and processingTime.
- We need to efficiently choose the next task to process at any given time. A priority queue will help us with this decision.
{{< dots >}}
### Edge Cases 🌐
- No tasks are given.
- When n is very large, the solution should handle it efficiently.
- Tasks with the same enqueueTime but different processingTimes.
- Ensure that tasks are processed in the correct order even when some tasks have the same enqueueTime.
{{< dots >}}
## Code 💻
```cpp
vector<int> getOrder(vector<vector<int>>& tasks) {
    
    for(int i = 0; i < tasks.size(); i++)
        tasks[i].push_back(i);
    
    sort(tasks.begin(), tasks.end());
    
    vector<int> ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    long i = 0, time = 0;
    while(i < tasks.size() || pq.size()) {

        if(pq.empty()) {
            time = max(time, (long) tasks[i][0]);
        }
        
        while(i < tasks.size() && tasks[i][0] <= time) {
            pq.push({tasks[i][1], tasks[i][2]});
            i++;
        }
        
        auto [pro, idx] = pq.top();
        pq.pop();
        time += pro;
        ans.push_back(idx);

    }

    return ans;
}
```

This function schedules tasks based on the available time, following a priority queue to process tasks in the correct order based on their processing time and arrival time.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> getOrder(vector<vector<int>>& tasks) {
	```
	Defines the `getOrder` function, which takes a vector of task details (`tasks`) and returns the order in which they should be processed.

2. **Loop Initialization**
	```cpp
	    for(int i = 0; i < tasks.size(); i++)
	```
	Iterates over each task in the `tasks` vector to prepare the data for sorting and processing.

3. **Adding Index to Task**
	```cpp
	        tasks[i].push_back(i);
	```
	Appends the task index to each task, which helps in tracking the original task order after sorting.

4. **Sorting**
	```cpp
	    sort(tasks.begin(), tasks.end());
	```
	Sorts the tasks based on their start time, which helps in processing them in the order of their arrival.

5. **Vector Initialization**
	```cpp
	    vector<int> ans;
	```
	Initializes the `ans` vector to store the order of task indices as they are processed.

6. **Priority Queue Initialization**
	```cpp
	    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	```
	Initializes a priority queue to store tasks based on their processing time, allowing the task with the smallest processing time to be processed first.

7. **Variable Initialization**
	```cpp
	    long i = 0, time = 0;
	```
	Initializes the `i` variable to keep track of the tasks being processed, and `time` to track the current time.

8. **While Loop**
	```cpp
	    while(i < tasks.size() || pq.size()) {
	```
	Starts a while loop that continues until all tasks are processed and the priority queue is empty.

9. **Empty Priority Queue Check**
	```cpp
	        if(pq.empty()) {
	```
	Checks if the priority queue is empty. If it is, the next task will be scheduled based on its start time.

10. **Time Adjustment**
	```cpp
	            time = max(time, (long) tasks[i][0]);
	```
	If the priority queue is empty, adjust the current time (`time`) to the start time of the next task if it is greater than the current time.

11. **Processing Tasks within Time**
	```cpp
	        while(i < tasks.size() && tasks[i][0] <= time) {
	```
	Starts a while loop that adds tasks to the priority queue as long as their start time is less than or equal to the current time.

12. **Push Task to Priority Queue**
	```cpp
	            pq.push({tasks[i][1], tasks[i][2]});
	```
	Pushes the task's processing time and its original index into the priority queue for scheduling.

13. **Increment Task Index**
	```cpp
	            i++;
	```
	Increments the task index to process the next task.

14. **Task Processing**
	```cpp
	        auto [pro, idx] = pq.top();
	```
	Extracts the task with the smallest processing time from the priority queue.

15. **Pop Task from Priority Queue**
	```cpp
	        pq.pop();
	```
	Removes the processed task from the priority queue.

16. **Time Update**
	```cpp
	        time += pro;
	```
	Increments the current time (`time`) by the processing time of the task just completed.

17. **Store Processed Task Index**
	```cpp
	        ans.push_back(idx);
	```
	Stores the index of the processed task in the `ans` vector, representing the order of completion.

18. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the vector `ans`, which contains the indices of the tasks in the order they were processed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting of the tasks and the operations on the priority queue.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of tasks and the priority queue.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/single-threaded-cpu/description/)

---
{{< youtube RR1n-d4oYqE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
