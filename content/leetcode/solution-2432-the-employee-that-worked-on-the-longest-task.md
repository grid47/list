
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement

The problem involves finding the "hardest worker" among a set of workers based on their work logs. You are given `n` workers and a list of work logs. Each work log contains two values: the worker’s ID and the timestamp of when they completed a task. The task here is to find the worker who worked the most amount of time between tasks, where the time between tasks is measured by the difference in timestamps. In case of a tie, the worker with the smaller ID should be chosen. The goal is to return the ID of the hardest worker.

### Approach

The approach can be broken down into a few clear steps:

1. **Initialization**: 
   We start by initializing variables to track the worker ID of the hardest worker, the maximum time worked between tasks, and the previous task's end time.
   
2. **Iterate through logs**: 
   For each log entry, we calculate the amount of time the worker worked between their current task and the previous task by subtracting the previous task's end timestamp from the current task's end timestamp.

3. **Determine the hardest worker**: 
   During each iteration, we compare the time worked between tasks for the current worker. If the worker has worked more time than the current hardest worker, we update the hardest worker's ID and the maximum time worked.

4. **Handle ties**: 
   If two workers worked the same amount of time, we choose the worker with the smaller ID, as specified in the problem statement.

5. **Final result**: 
   After processing all the logs, the ID of the hardest worker is returned.

### Code Breakdown (Step by Step)

#### Step 1: Initialization
```cpp
int end = 0, id = 0, max_t = 0;
```
- `end`: Tracks the end time of the previous task.
- `id`: Tracks the ID of the hardest worker.
- `max_t`: Tracks the maximum time worked between tasks.

#### Step 2: Iterate through logs
```cpp
for (auto &l : logs) {
```
- We loop through each log entry in the `logs` vector. Each log entry is a pair of values, where `l[0]` is the worker's ID, and `l[1]` is the timestamp of when they completed a task.

#### Step 3: Calculate time worked
```cpp
if (max_t <= l[1] - end) {
    id = max_t < l[1] - end ? l[0] : min(id, l[0]);
    max_t = l[1] - end;
}
```
- The difference `l[1] - end` represents the time worked between the current and previous tasks.
- If the time worked for the current worker is greater than or equal to the `max_t` (maximum time worked so far), we update `max_t` to this new value.
- If the current time worked is strictly greater than `max_t`, we set the worker’s ID (`id`) to the current worker's ID (`l[0]`).
- In case of a tie in time worked (`max_t == l[1] - end`), we choose the worker with the smaller ID by using the `min(id, l[0])` expression. This ensures that if two workers worked the same amount of time, the one with the smaller ID is chosen.

#### Step 4: Update the end time
```cpp
end = l[1];
```
- We update the `end` variable to the current task's timestamp (`l[1]`) to use it for calculating the time worked between the next pair of tasks.

#### Step 5: Return the result
```cpp
return id;
```
- After processing all the logs, we return the ID of the worker who worked the most time between tasks (or the one with the smallest ID in case of a tie).

### Complexity Analysis

#### Time Complexity:
The time complexity of this solution is **O(m)**, where `m` is the number of logs. This is because we iterate through each log entry exactly once and perform constant-time operations (comparison and updating variables) for each log.

#### Space Complexity:
The space complexity is **O(1)** because the solution only uses a few integer variables to store the current worker ID, maximum time worked, and the end time of the previous task. No additional space proportional to the input size is used.

### Conclusion

This solution efficiently identifies the hardest worker among a set of workers based on the amount of time they worked between tasks. The algorithm runs in linear time relative to the number of logs, making it scalable even for large inputs. The space complexity is constant, as the solution only requires a few auxiliary variables. Additionally, the solution handles ties by selecting the worker with the smaller ID, which is specified in the problem statement.

[`Link to LeetCode Lab`](https://leetcode.com/problems/the-employee-that-worked-on-the-longest-task/description/)

---
{{< youtube BxVwXRLZlhk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
