
+++
authors = ["grid47"]
title = "Leetcode 1882: Process Tasks Using Servers"
date = "2024-05-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1882: Process Tasks Using Servers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "XKA22PecuMQ"
youtube_upload_date="2021-05-30"
youtube_thumbnail="https://i.ytimg.com/vi/XKA22PecuMQ/maxresdefault.jpg"
comments = true
+++



---
You are given two integer arrays, `servers` and `tasks`. The `servers` array represents the weights of the servers, and the `tasks` array represents the processing times of tasks. Tasks are assigned to servers based on the smallest server weight and index. If no server is available, tasks wait for a server to become free.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two arrays: `servers` and `tasks`. The `servers` array is a list of integers representing the weight of each server. The `tasks` array contains integers representing the processing times for tasks. At each second, a new task enters the queue and is assigned to the server based on availability and weight priorities.
- **Example:** `servers = [5, 1, 4, 3, 2], tasks = [2, 1, 2, 4, 5, 2, 1]`
- **Constraints:**
	- 1 <= n, m <= 2 * 10^5
	- 1 <= servers[i], tasks[j] <= 2 * 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** You need to return an array of indices representing which server each task is assigned to. The output should follow the task queue order.
- **Example:** `[1, 4, 1, 4, 1, 3, 2]`
- **Constraints:**
	- The output array will have the same length as the `tasks` array.

{{< dots >}}
### Core Logic 🔍
**Goal:** To simulate task assignments to servers based on availability, weight, and index priority.

- Initialize a priority queue for free servers based on their weights and indices.
- For each task, check if there are any free servers available. If so, assign the task to the one with the smallest weight and index.
- If no servers are available, check when the next server becomes free and assign tasks accordingly.
- Keep track of task assignments and update the server statuses (free or busy).
{{< dots >}}
### Problem Assumptions ✅
- Each server is initially free and available to process tasks.
- Tasks are processed in the order they are added to the queue.
- Servers will be used based on availability, weight, and index priority.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1`  \
  **Explanation:** In the first example, we see that tasks are assigned based on server weights. Server 1 (weight 4) is assigned task 0, and the process continues in this manner for each task in the queue. Servers that become free are used for subsequent tasks.

- **Input:** `Example 2`  \
  **Explanation:** In this case, server 1 is used for task 1 because it has the smallest weight (4), and after task completion, it gets assigned additional tasks as servers become free.

{{< dots >}}
## Approach 🚀
This approach simulates the task assignment process by tracking server availability and using a priority queue for efficient task allocation based on server weight and index.

### Initial Thoughts 💭
- Servers should be processed in order of their availability and weight.
- Use a priority queue to efficiently assign tasks to the smallest available server.
- The problem requires efficient simulation with a focus on managing availability and task queueing. A priority queue is ideal for maintaining the smallest available server.
{{< dots >}}
### Edge Cases 🌐
- If there are no servers or no tasks, the result should be an empty array.
- Make sure the algorithm can handle large numbers of servers and tasks efficiently.
- If servers or tasks contain extreme values, ensure proper handling of edge cases.
- The approach should work efficiently with the given constraints (up to 2 * 10^5 servers and tasks).
{{< dots >}}
## Code 💻
```cpp
vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
    
    priority_queue<array<long, 3>, vector<array<long, 3>>, greater<array<long, 3>>> avail, busy;
    
    int n = servers.size();
    for(int i = 0; i < n; i++)
        avail.push({0, servers[i], i});
    
    int m = tasks.size();
    
    vector<int> ans;        
    
    for(int t = 0; t < m; t++) {
        
        while(!busy.empty() && (busy.top()[0] <= t || avail.empty())) {
            auto [time, w, idx] = busy.top();
            busy.pop();
            avail.push({time <= t? 0: time, w, idx});
        }

        auto [time, w, idx] = avail.top();
        avail.pop();
        busy.push({ max(time, (long)t) + tasks[t], w, idx});
        ans.push_back(idx);
    }
    return ans;
}
```

This is a function that assigns tasks to servers using a priority queue. The function efficiently assigns each task to the server that becomes available the earliest.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Initial Setup**
	```cpp
	vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
	```
	Defines the function `assignTasks` that takes in two vectors: `servers` representing the server capacities and `tasks` representing the tasks to be completed.

2. **Queue Initialization**
	```cpp
	    priority_queue<array<long, 3>, vector<array<long, 3>>, greater<array<long, 3>>> avail, busy;
	```
	Declares two priority queues: `avail` for tracking available servers and `busy` for tracking servers that are currently occupied with tasks.

3. **Server Assignment**
	```cpp
	    int n = servers.size();
	```
	Gets the number of servers by finding the size of the `servers` vector.

4. **Queue Population**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Loops through each server and pushes a tuple containing the initial time (0), the server's capacity, and the server index into the `avail` priority queue.

5. **Task Counting**
	```cpp
	        avail.push({0, servers[i], i});
	```
	Pushes each server into the `avail` queue with the initial time set to 0.

6. **Task Size Setup**
	```cpp
	    int m = tasks.size();
	```
	Stores the number of tasks by finding the size of the `tasks` vector.

7. **Answer Initialization**
	```cpp
	    vector<int> ans;        
	```
	Initializes a vector `ans` to store the indices of the servers assigned to each task.

8. **Task Assignment Loop**
	```cpp
	    for(int t = 0; t < m; t++) {
	```
	Loops through each task in the `tasks` vector.

9. **Server Availability Check**
	```cpp
	        while(!busy.empty() && (busy.top()[0] <= t || avail.empty())) {
	```
	Checks if any server is free or if there are available servers that need to be assigned tasks.

10. **Pop Busy Server**
	```cpp
	            auto [time, w, idx] = busy.top();
	```
	Pops the top of the `busy` queue to get the earliest available server.

11. **Push to Available Queue**
	```cpp
	            busy.pop();
	```
	Removes the server from the `busy` queue as it becomes free.

12. **Reassign Available Server**
	```cpp
	            avail.push({time <= t? 0: time, w, idx});
	```
	Pushes the server back into the `avail` queue with updated time.

13. **Assign Task to Server**
	```cpp
	        auto [time, w, idx] = avail.top();
	```
	Assigns the task to the server at the top of the `avail` queue.

14. **Update Available Queue**
	```cpp
	        avail.pop();
	```
	Removes the assigned server from the `avail` queue.

15. **Server Occupy**
	```cpp
	        busy.push({ max(time, (long)t) + tasks[t], w, idx});
	```
	Pushes the server into the `busy` queue with the updated time when it will be free.

16. **Log Task Assignment**
	```cpp
	        ans.push_back(idx);
	```
	Adds the server index to the `ans` vector, indicating that the task has been assigned to this server.

17. **Return Result**
	```cpp
	    return ans;
	```
	Returns the vector `ans` containing the indices of the servers to which tasks were assigned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m log n) where m is the number of tasks and n is the number of servers.
- **Average Case:** O(m log n)
- **Worst Case:** O(m log n)

In the worst case, each task involves an insertion and extraction from the priority queue, leading to a time complexity of O(m log n).

### Space Complexity 💾
- **Best Case:** O(n + m)
- **Worst Case:** O(n + m) due to the space required for the priority queues and the task assignments.

The space complexity is dominated by the need to store the server states and task assignments.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/process-tasks-using-servers/description/)

---
{{< youtube XKA22PecuMQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
