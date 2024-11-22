
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement

The problem involves assigning tasks to a set of servers based on their availability and processing power. Each server can only handle one task at a time, and each task has a specific processing time. The goal is to determine which server is assigned to each task and in what order. When multiple servers are available, the server with the least processing power should be chosen. If a server is busy, tasks must wait until the server is available.

### Approach

The solution employs two priority queues: one for available servers and another for busy servers. This allows efficient management of task assignments based on server availability and processing capacity. The approach can be summarized as follows:

1. **Initialization**: Create a priority queue for available servers and another for busy servers. Each server in the available queue is represented by an array containing the time it will be free, its processing power, and its index.

2. **Processing Tasks**: For each task:
   - If any servers are busy and their processing time is up, move them back to the available queue.
   - Assign the next task to the available server with the least processing power.
   - Update the busy queue with the server that is now handling the task.

3. **Result Collection**: Maintain a list to keep track of which server is assigned to which task.

### Code Breakdown (Step by Step)

1. **Class Definition**: The solution is encapsulated in a class named `Solution`.

   ```cpp
   class Solution {
   public:
   ```

2. **Function Definition**: The function `assignTasks` takes two vectors as parameters: `servers` and `tasks`.

   ```cpp
       vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
   ```

3. **Priority Queue Initialization**: Two priority queues are defined: `avail` for available servers and `busy` for busy servers. The available queue is populated with all servers initialized to be free at time 0.

   ```cpp
           priority_queue<array<long, 3>, vector<array<long, 3>>, greater<array<long, 3>>> avail, busy;
           int n = servers.size();
           for(int i = 0; i < n; i++)
               avail.push({0, servers[i], i});
   ```

4. **Task Processing**: Loop through each task to assign it to a server.

   ```cpp
           int m = tasks.size();
           vector<int> ans;        
           for(int t = 0; t < m; t++) {
   ```

5. **Handling Busy Servers**: While there are busy servers and the task time has exceeded their completion time, move these servers back to the available queue.

   ```cpp
               while(!busy.empty() && (busy.top()[0] <= t || avail.empty())) {
                   auto [time, w, idx] = busy.top();
                   busy.pop();
                   avail.push({time <= t? 0: time, w, idx});
               }
   ```

6. **Assigning Tasks**: Extract the server with the least processing power from the available queue, and assign the task. Update the busy queue with the new busy status of the server.

   ```cpp
               auto [time, w, idx] = avail.top();
               avail.pop();
               busy.push({ max(time, (long)t) + tasks[t], w, idx});
               ans.push_back(idx);
           }
   ```

7. **Return Result**: Finally, return the list of server indices corresponding to the assigned tasks.

   ```cpp
           return ans;
       }
   };
   ```

### Complexity

- **Time Complexity**: The time complexity is \( O((m + n) \log n) \), where \( m \) is the number of tasks and \( n \) is the number of servers. Each task and server operation involves log operations due to the priority queue manipulations.

- **Space Complexity**: The space complexity is \( O(n) \) for storing the servers in the priority queue.

### Conclusion

The `assignTasks` function provides an efficient solution to the problem of task assignment to servers based on their availability and processing power. By utilizing priority queues, the function ensures that servers are managed optimally, allowing for a quick assignment process.

This approach not only effectively handles the task assignment but also accommodates the dynamic nature of server availability, enabling it to scale well with the input size. The structured method of handling available and busy servers illustrates a robust technique applicable to various scheduling problems in computer science.

The implementation showcases the importance of understanding data structures like priority queues for efficiently managing dynamic sets of data, such as server workloads. Mastering such techniques is vital for solving complex problems related to task scheduling, resource allocation, and load balancing in computing systems.

In summary, the `assignTasks` function exemplifies a clear and efficient algorithm for task assignment, reinforcing the significance of effective data management in algorithm design.

[`Link to LeetCode Lab`](https://leetcode.com/problems/process-tasks-using-servers/description/)

---
{{< youtube XKA22PecuMQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
