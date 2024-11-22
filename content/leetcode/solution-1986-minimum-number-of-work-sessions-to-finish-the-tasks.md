
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
    
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to minimize the number of sessions needed to complete a list of tasks, where each session has a specific time limit. Each task takes a certain amount of time to complete, and multiple tasks can be combined within a single session as long as their total time does not exceed the session limit. The goal is to determine the minimum number of sessions required to finish all tasks.

### Approach

To solve this problem, we can use a **backtracking approach** combined with **bitmasking** to efficiently explore all possible combinations of tasks that can fit within the given session time. The key steps of the approach are as follows:

1. **Bitmask Representation**: We represent the state of tasks using a bitmask where each bit indicates whether a task has been completed (1) or not (0). This allows us to track the completion of tasks easily.

2. **Memoization**: To avoid recalculating results for the same state, we use memoization. A 2D array `memo` is used where `memo[mask][net]` stores the minimum number of sessions needed to complete tasks represented by `mask`, with the current session having a total time of `net`.

3. **Backtracking Function**: The backtracking function `bt` tries to assign tasks to sessions:
   - If all tasks are completed (indicated by the mask), it returns 1 (indicating one more session is needed).
   - If the current session exceeds the time limit, it starts a new session and continues the process.
   - It iteratively tries adding each task to the current session and explores the next state recursively.

4. **Base Cases**: 
   - When all tasks are assigned (the mask equals the target mask), we return the number of sessions.
   - Memoization checks help avoid redundant calculations.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    vector<int> task;
    int memo[1<<15][16]; // Memoization array
```
We define a class `Solution`, with a vector to store tasks and a memoization array to store the results of subproblems.

```cpp
    int minSessions(vector<int>& tasks, int sessionTime) {
        this->task = tasks; // Store tasks in the class member variable
        map<int, int> mp; // This map is unnecessary
        int mask = 0; // Initialize the mask
        int tgt = ~(~0u << task.size()); // Target mask to indicate all tasks completed
        memset(memo, -1, sizeof(memo)); // Initialize memoization array
```
In the `minSessions` method, we store the input tasks and initialize variables. The target mask is calculated to represent all tasks being completed.

```cpp
        return bt(tgt, 0, sessionTime, mask); // Call the backtracking function
    }
```
The `bt` function is called with initial parameters, including the target mask.

```cpp
    int bt(int tgt, int net, int st, int mask) {
        if(tgt == mask) {
            return 1; // All tasks are completed
        }
        if(memo[mask][net] != -1) return memo[mask][net]; // Return memoized result if available
```
The `bt` function checks if all tasks are completed and returns 1 if true. It also checks if the current state has already been computed.

```cpp
        int ans = task.size(); // Initialize the answer with the maximum possible sessions
        for(int i = 0; i < task.size(); i++) {
            if((mask >> i) & 1) continue; // Skip if the task is already included in the mask
            mask |= (1 << i); // Include the current task in the mask
```
We initialize `ans` to the number of tasks, as this is the upper limit for the number of sessions. The loop iterates through each task.

```cpp
            if(net + task[i] > st)
                ans = min(ans, 1 + bt(tgt, task[i], st, mask)); // Start a new session if the limit is exceeded
            else
                ans = min(ans, bt(tgt, net + task[i], st, mask)); // Continue in the same session
            mask ^= (1 << i); // Backtrack and remove the task from the mask
        }
        return memo[mask][net] = ans; // Memoize the result
    }
```
The code checks if adding the current task exceeds the session limit. If it does, it starts a new session; otherwise, it continues in the current session. After exploring both options, it backtracks by removing the task from the mask and updates the memoization array with the result.

### Complexity

- **Time Complexity**: The worst-case scenario involves exploring all possible combinations of tasks, leading to a time complexity of \(O(2^n \cdot n)\), where \(n\) is the number of tasks. The bitmask allows us to efficiently track the state of tasks.

- **Space Complexity**: The space complexity is \(O(2^n \cdot k)\) due to the memoization array, where \(k\) is the maximum number of sessions. The additional space used by the recursion stack may also contribute to space complexity.

### Conclusion

This solution efficiently computes the minimum number of sessions needed to complete all tasks by employing a combination of backtracking and memoization with bitmasking. This approach optimizes the exploration of task combinations while ensuring that previously computed results are reused to reduce computation time.

### Example Usage

Here's an example of how you can utilize the `minSessions` method:

```cpp
#include <vector>
#include <iostream>
using namespace std;

int main() {
    Solution sol;
    vector<int> tasks = {1, 2, 3, 4, 5};
    int sessionTime = 5;
    int result = sol.minSessions(tasks, sessionTime);
    cout << "Minimum sessions needed: " << result << endl; // Example output
    return 0;
}
```

### Potential Improvements

1. **Optimization of Memoization**: The current memoization could be optimized further by using only necessary states to reduce space complexity.

2. **Task Sorting**: Sorting the tasks based on their duration could potentially speed up the backtracking process by prioritizing larger tasks first.

3. **Iterative Approach**: While the backtracking approach is elegant, an iterative dynamic programming solution could be explored for potentially better performance, especially for larger datasets.

This solution demonstrates a thoughtful application of bitmasking and dynamic programming techniques to solve a challenging combinatorial optimization problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/description/)

---
{{< youtube 8TU3WceDlzI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
