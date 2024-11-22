
+++
authors = ["grid47"]
title = "Leetcode 636: Exclusive Time of Functions"
date = "2024-09-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 636: Exclusive Time of Functions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/636.webp"
youtube = "Rjcwy-Q2uDo"
youtube_upload_date="2020-04-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Rjcwy-Q2uDo/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/636.webp" 
    alt="A timeline of function executions, where the exclusive time for each function is highlighted and softly glowing."
    caption="Solution to LeetCode 636: Exclusive Time of Functions Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
struct Log {
    int id;
    string status;
    int time;
};
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<Log> stk;
        for(string log : logs) {
            stringstream ss(log);
            string num, adj, time;
            getline(ss, num,  ':');
            getline(ss, adj,  ':');
            getline(ss, time, ':');
            Log item = { stoi(num), adj, stoi(time) };

            if(item.status == "start") {
                stk.push(item);
            } else {
                assert(stk.top().id == item.id);
                int t = item.time - stk.top().time +1;
                ans[item.id] += t;
                stk.pop();
                if(!stk.empty()){
                    assert(stk.top().status == "start");
                    ans[stk.top().id] -= t;
                }
            }
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to calculate the exclusive execution time of functions in a system where each log entry records the starting or stopping time of a function, along with its unique function ID. The logs are provided as strings where each log contains the function ID, the status (either "start" or "end"), and the timestamp of when the event occurred.

Given `n` functions, our goal is to compute the exclusive execution time of each function. The exclusive execution time is defined as the total time a function spends executing minus the time it spends in functions that it calls.

### Approach

To solve this problem, we need to simulate the execution of the functions and manage their start and end times. A stack data structure is ideal for this problem because it allows us to keep track of the functions that are currently executing.

The solution can be broken down into the following steps:

1. **Parse the Logs**: Each log entry contains a function ID, a status ("start" or "end"), and a timestamp. We need to extract this information from the log.
2. **Track Start and End Times**: Use a stack to keep track of functions that are currently executing. When a function starts, we push it onto the stack. When a function ends, we pop it from the stack and compute its exclusive execution time.
3. **Adjust the Times**: For each "end" log, we calculate the time spent by the function and update the time of the function at the top of the stack, which represents the function that called the current function.

### Code Breakdown (Step by Step)

Let's go through the code step by step to understand how it works:

#### 1. **Data Structures and Initialization**:
   ```cpp
   vector<int> ans(n, 0);
   stack<Log> stk;
   ```
   - We initialize a `vector<int> ans` with size `n` to store the exclusive execution times of each function. The `vector` is initialized with zeros.
   - A stack `stk` of type `Log` is used to track functions as they start. Each entry in the stack represents a function that is currently running, including its ID, status, and start time.

#### 2. **Iterating Through the Logs**:
   ```cpp
   for(string log : logs) {
       stringstream ss(log);
       string num, adj, time;
       getline(ss, num, ':');
       getline(ss, adj, ':');
       getline(ss, time, ':');
       Log item = { stoi(num), adj, stoi(time) };
   ```
   - We iterate through each log in the `logs` vector. Each log string is passed to a stringstream `ss` to extract the function ID (`num`), status (`adj`), and timestamp (`time`) using `getline()`.
   - We convert `num` and `time` to integers using `stoi()`, and create a `Log` structure with the parsed information.

#### 3. **Processing the "Start" Log**:
   ```cpp
   if(item.status == "start") {
       stk.push(item);
   }
   ```
   - If the log represents a "start" event, we push the `Log` object onto the stack. This indicates that a function has started and is currently executing.

#### 4. **Processing the "End" Log**:
   ```cpp
   else {
       assert(stk.top().id == item.id);
       int t = item.time - stk.top().time + 1;
       ans[item.id] += t;
       stk.pop();
   ```
   - If the log represents an "end" event, we first check that the function ID of the "end" log matches the function ID of the function at the top of the stack (i.e., the currently executing function).
   - We calculate the time spent by the function using the formula `t = item.time - stk.top().time + 1`, where `item.time` is the timestamp of the "end" event and `stk.top().time` is the timestamp of the corresponding "start" event.
   - We add this time to `ans[item.id]`, which stores the total exclusive execution time for the function `item.id`.
   - We then pop the function from the stack because it has finished executing.

#### 5. **Adjusting the Time of the Calling Function**:
   ```cpp
   if(!stk.empty()){
       assert(stk.top().status == "start");
       ans[stk.top().id] -= t;
   }
   ```
   - If the stack is not empty (i.e., there is a function that called the current function), we subtract the execution time of the current function from the exclusive execution time of the function at the top of the stack. This ensures that the time spent in the current function is not counted as part of the calling function's exclusive time.

#### 6. **Returning the Result**:
   ```cpp
   return ans;
   ```
   - After processing all logs, the `ans` vector will contain the exclusive execution times of all functions, which we return.

### Complexity

#### Time Complexity:
- **O(n)**: We iterate through each log exactly once, where `n` is the number of logs. Each operation inside the loop (such as parsing the log and pushing or popping from the stack) takes constant time.

#### Space Complexity:
- **O(n)**: The space complexity is determined by the stack, which can store at most `n` functions in the worst case (when no functions have finished executing).

### Conclusion

This solution efficiently computes the exclusive execution time of each function by simulating the function calls using a stack. The stack allows us to keep track of which function is currently running and ensures that we correctly account for the time spent in functions that are called. By maintaining the exclusive execution time of each function, we handle nested calls and accurately compute the total time spent by each function without counting the time spent in its child functions.

This approach runs in **O(n)** time, where `n` is the number of log entries, and it uses **O(n)** space, making it optimal for solving the problem. The use of a stack ensures that the solution is both simple and efficient.

[`Link to LeetCode Lab`](https://leetcode.com/problems/exclusive-time-of-functions/description/)

---
{{< youtube Rjcwy-Q2uDo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
