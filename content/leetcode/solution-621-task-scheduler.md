
+++
authors = ["grid47"]
title = "Leetcode 621: Task Scheduler"
date = "2024-09-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 621: Task Scheduler in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Sorting","Heap (Priority Queue)","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/621.webp"
youtube = "s8p8ukTyA2I"
youtube_upload_date="2021-11-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/s8p8ukTyA2I/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/621.webp" 
    alt="A glowing task list where tasks are scheduled, with optimal scheduling steps softly illuminating."
    caption="Solution to LeetCode 621: Task Scheduler Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a list of tasks and a number n, determine the minimum number of CPU intervals required to complete all tasks, respecting the constraint that the same task must be separated by at least n intervals.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of tasks (represented as uppercase English letters) and an integer n, which denotes the cooling period between the same tasks.
- **Example:** `tasks = ["A", "A", "A", "B", "B", "B"], n = 2`
- **Constraints:**
	- 1 <= tasks.length <= 10^4
	- tasks[i] is an uppercase English letter.
	- 0 <= n <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of CPU intervals required to execute all tasks, including idle times where no task is executed.
- **Example:** `8`
- **Constraints:**
	- The output is a single integer representing the number of intervals.

{{< dots >}}
### Core Logic 🔍
**Goal:** To minimize the number of CPU intervals, the algorithm should schedule tasks in a way that maximizes task completion while respecting the cooling time n.

- 1. Count the frequency of each task.
- 2. Use a priority queue to process tasks in the order of their frequency.
- 3. For each task, perform it and then wait for n intervals before performing it again, using idle periods where necessary.
- 4. Return the total number of intervals.
{{< dots >}}
### Problem Assumptions ✅
- The input tasks list is valid and contains only uppercase English letters.
- n is a non-negative integer representing the cooling time between tasks of the same type.
{{< dots >}}
## Examples 🧩
- **Input:** `tasks = ["A", "A", "A", "B", "B", "B"], n = 2`  \
  **Explanation:** In this example, task A and task B need to be performed in such a way that there are at least 2 intervals between each repetition of the same task. Thus, idling is required between repetitions.

{{< dots >}}
## Approach 🚀
The approach to solving this problem involves calculating the frequencies of tasks and efficiently scheduling them while respecting the cooling interval using a priority queue.

### Initial Thoughts 💭
- This is a scheduling problem with a cooling constraint, which is a typical greedy approach scenario.
- We need to ensure that tasks are performed in an optimal order to minimize idle times.
{{< dots >}}
### Edge Cases 🌐
- If no tasks are provided (empty list), the result is 0 intervals.
- Handle cases where the number of tasks is close to 10^4, requiring efficient scheduling.
- If n = 0, tasks can be performed one after another without idle time.
- Ensure that the solution can efficiently handle large inputs.
{{< dots >}}
## Code 💻
```cpp
int leastInterval(vector<char>& tasks, int n) {
    // if(n == 0) return tasks.size();
    map<char, int> mp;
    for(char x: tasks)
        mp[x]++;
    priority_queue<pair<int, char>> pq;
    for(auto it: mp) {
        pq.push({it.second, it.first});
    }
    int time = 0, net = 0;
    while(!pq.empty()) {
        vector<pair<int, char>> tmp;
        time = 0;
        for(int i = 0; i < n + 1; i++) {
            if(!pq.empty()) {
                // cout<<pq.top().first << " ";
                tmp.push_back(pq.top());
                pq.pop();
                time++;
            }
        }
        for(auto it: tmp) {
            it.first--;
            if(it.first)
                pq.push(it);
        }
        net += !pq.empty()? n + 1: time;
    }
    return net;
}
```

The `leastInterval` function calculates the minimum time required to complete all tasks with given constraints. Tasks are represented as characters in a list, and a cooling period of `n` intervals is enforced between tasks of the same type. The algorithm uses a priority queue to process tasks in decreasing order of frequency, ensuring that tasks are completed within the constraints.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int leastInterval(vector<char>& tasks, int n) {
	```
	Declares the `leastInterval` function, which accepts a list of tasks and a cooling period `n`, and returns the minimum time required to complete all tasks.

2. **Map Initialization**
	```cpp
	    map<char, int> mp;
	```
	Initializes a map `mp` to store the frequency of each task (character) in the `tasks` list.

3. **Loop Over Tasks**
	```cpp
	    for(char x: tasks)
	```
	Iterates over the `tasks` list, counting the frequency of each task using the map `mp`.

4. **Increment Task Count**
	```cpp
	        mp[x]++;
	```
	Increments the count of task `x` in the map `mp`, recording how many times each task appears.

5. **Priority Queue Initialization**
	```cpp
	    priority_queue<pair<int, char>> pq;
	```
	Initializes a priority queue `pq` to store tasks in decreasing order of their frequency, where the task with the highest frequency is processed first.

6. **Map to Priority Queue**
	```cpp
	    for(auto it: mp) {
	```
	Iterates over the map `mp` to push each task and its frequency into the priority queue `pq`.

7. **Push to Priority Queue**
	```cpp
	        pq.push({it.second, it.first});
	```
	Pushes the task-frequency pair (`it.second`, `it.first`) into the priority queue, ensuring that tasks are ordered by frequency.

8. **Time Initialization**
	```cpp
	    int time = 0, net = 0;
	```
	Initializes variables `time` (to track the current time) and `net` (to track the total time required to complete all tasks).

9. **While Loop (Priority Queue Processing)**
	```cpp
	    while(!pq.empty()) {
	```
	Starts a loop that continues until all tasks are processed, i.e., until the priority queue is empty.

10. **Temporary Task Storage**
	```cpp
	        vector<pair<int, char>> tmp;
	```
	Creates a temporary vector `tmp` to store tasks that are processed in the current cycle of `n+1` steps.

11. **Reset Time**
	```cpp
	        time = 0;
	```
	Resets the `time` variable to 0 for each new cycle of task processing.

12. **For Loop (Task Processing)**
	```cpp
	        for(int i = 0; i < n + 1; i++) {
	```
	Iterates over the tasks for the current cycle, allowing up to `n+1` steps in each cycle (processing one task per step).

13. **Task Available Check**
	```cpp
	            if(!pq.empty()) {
	```
	Checks if there are tasks available in the priority queue to process in the current step.

14. **Push Task to Temporary Storage**
	```cpp
	                tmp.push_back(pq.top());
	```
	Pushes the task with the highest frequency (top of the priority queue) into the temporary vector `tmp`.

15. **Pop Task from Priority Queue**
	```cpp
	                pq.pop();
	```
	Pops the task from the priority queue, as it has been selected for processing in the current cycle.

16. **Increment Time**
	```cpp
	                time++;
	```
	Increments the `time` variable to account for the time spent processing the current task.

17. **Update Task Counts**
	```cpp
	        for(auto it: tmp) {
	```
	Iterates over the tasks in `tmp` (tasks processed in the current cycle) to update their frequencies.

18. **Decrement Task Count**
	```cpp
	            it.first--;
	```
	Decrements the frequency of the task in `tmp` as it has been processed once.

19. **Re-add Task to Queue**
	```cpp
	            if(it.first)
	```
	Checks if the task still has remaining occurrences (frequency > 0) before re-adding it to the priority queue.

20. **Push Task Back to Queue**
	```cpp
	                pq.push(it);
	```
	Pushes the task back into the priority queue if it still has remaining occurrences.

21. **Update Net Time**
	```cpp
	        net += !pq.empty()? n + 1: time;
	```
	Adds either `n + 1` (if tasks are still remaining) or `time` (if no tasks are left) to the total `net` time.

22. **Return Result**
	```cpp
	    return net;
	```
	Returns the total time required to complete all tasks, represented by the `net` variable.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(N log N)
- **Average Case:** O(N log N)
- **Worst Case:** O(N log N)

The time complexity is dominated by the heap operations which take O(log N) time, where N is the number of unique tasks.

### Space Complexity 💾
- **Best Case:** O(N)
- **Worst Case:** O(N)

The space complexity is O(N) where N is the number of unique tasks, as we need to store them in the priority queue.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/task-scheduler/description/)

---
{{< youtube s8p8ukTyA2I >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
