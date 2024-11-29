
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
comments = true
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
You are given a list of logs representing the execution of n functions on a single-threaded CPU. Each log contains a function's ID, whether the function has started or ended, and the timestamp of the event. The goal is to calculate the exclusive time of each function, which is the total time the function spends executing, excluding the time spent on other nested function calls.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a list of logs formatted as strings with the structure {function_id}:{start|end}:{timestamp}. The logs indicate when a function starts or ends at a given timestamp.
- **Example:** `n = 2, logs = ["0:start:0", "1:start:2", "1:end:5", "0:end:6"]`
- **Constraints:**
	- 1 <= n <= 100
	- 1 <= logs.length <= 500
	- 0 <= function_id < n
	- 0 <= timestamp <= 10^9
	- No two start events will happen at the same timestamp.
	- No two end events will happen at the same timestamp.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the exclusive time for each function as an array, where the value at the ith index represents the exclusive time for function i.
- **Example:** `[3, 4]`
- **Constraints:**
	- The output will be an array of n integers representing the exclusive times for each function.

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the exclusive time for each function based on the logs.

- Iterate through the logs and simulate the execution of the functions using a stack.
- Track the start and end times for each function call and compute the total time spent executing each function.
{{< dots >}}
### Problem Assumptions ✅
- Each function has a start and end log.
- The logs will be given in chronological order.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 2, logs = ["0:start:0", "1:start:2", "1:end:5", "0:end:6"]`  \
  **Explanation:** Function 0 starts at time 0 and runs for 2 units of time, function 1 starts at time 2 and runs for 4 units. Function 0 resumes at time 6 and runs for 1 unit, making the total exclusive time of function 0 equal to 3, and function 1 equal to 4.

{{< dots >}}
## Approach 🚀
We use a stack to simulate the function calls and calculate the exclusive time by tracking the start and end timestamps.

### Initial Thoughts 💭
- Each function's exclusive time needs to account for recursive calls and nested execution times.
- By using a stack to keep track of function calls and their start times, we can easily calculate the total exclusive time for each function.
{{< dots >}}
### Edge Cases 🌐
- The input will not be empty, as logs always contain at least one function call.
- The solution should be efficient enough to handle up to 500 logs.
- Consider cases with recursive function calls where a function calls itself multiple times.
- Ensure the solution is efficient for the given problem size.
{{< dots >}}
## Code 💻
```cpp
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
```

This function calculates the exclusive time for each task in a set of logs, where each log represents a task's start or end time. It uses a stack to manage nested tasks and computes the total time spent on each task.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> exclusiveTime(int n, vector<string>& logs) {
	```
	This line defines the function `exclusiveTime` that takes an integer `n` (number of tasks) and a vector of logs. It returns a vector of integers representing the exclusive time for each task.

2. **Variable Initialization**
	```cpp
	    vector<int> ans(n, 0);
	```
	A vector `ans` is initialized with size `n` (number of tasks), and all elements are set to 0. This will store the exclusive time for each task.

3. **Stack Declaration**
	```cpp
	    stack<Log> stk;
	```
	A stack `stk` is declared to hold `Log` objects, which will track the tasks as they are being processed. The stack is used to manage nested tasks.

4. **Log Iteration**
	```cpp
	    for(string log : logs) {
	```
	A `for` loop is used to iterate through each log in the `logs` vector, where each log is processed to extract task information.

5. **Log Parsing**
	```cpp
	        stringstream ss(log);
	```
	A stringstream `ss` is created from the current log to easily extract individual components (task ID, status, and time).

6. **Log Variables Declaration**
	```cpp
	        string num, adj, time;
	```
	Three string variables `num`, `adj`, and `time` are declared to hold the task ID, status (start or end), and time values extracted from the log.

7. **Extract Task ID**
	```cpp
	        getline(ss, num,  ':');
	```
	The task ID (`num`) is extracted from the log by reading until the first colon `:`.

8. **Extract Status**
	```cpp
	        getline(ss, adj,  ':');
	```
	The task status (`adj`), which indicates whether the task has started or ended, is extracted by reading the next section of the log.

9. **Extract Time**
	```cpp
	        getline(ss, time, ':');
	```
	The task time (`time`) is extracted by reading the final section of the log.

10. **Log Item Creation**
	```cpp
	        Log item = { stoi(num), adj, stoi(time) };
	```
	A `Log` object is created with the parsed task ID (`num`), status (`adj`), and time (`time`). The `stoi` function is used to convert the `num` and `time` from strings to integers.

11. **Start Task Handling**
	```cpp
	        if(item.status == "start") {
	```
	If the task status is 'start', the task is pushed onto the stack, indicating that it has started.

12. **Push Task to Stack**
	```cpp
	            stk.push(item);
	```
	The `item` (task) is pushed onto the stack to keep track of the active task.

13. **End Task Handling**
	```cpp
	        } else {
	```
	If the task status is not 'start' (i.e., it's 'end'), the function proceeds to handle the task completion.

14. **Assert Task ID Match**
	```cpp
	            assert(stk.top().id == item.id);
	```
	This assertion checks that the task ID of the current log matches the task ID of the task at the top of the stack, ensuring that tasks are being ended in the correct order.

15. **Calculate Task Duration**
	```cpp
	            int t = item.time - stk.top().time +1;
	```
	The exclusive time for the task is calculated as the difference between the current time and the time of the task at the top of the stack, plus 1.

16. **Add Duration to Task**
	```cpp
	            ans[item.id] += t;
	```
	The calculated exclusive time `t` is added to the corresponding task ID in the `ans` vector.

17. **Pop Task from Stack**
	```cpp
	            stk.pop();
	```
	The task is removed from the stack after processing its end time.

18. **Handle Nested Task**
	```cpp
	            if(!stk.empty()){
	```
	If there are still tasks in the stack (indicating a nested task), the function continues to handle the exclusive time for the parent task.

19. **Assert Parent Task is Start**
	```cpp
	                assert(stk.top().status == "start");
	```
	This assertion checks that the task at the top of the stack is a 'start' task, ensuring the parent task is still active.

20. **Subtract Duration from Parent Task**
	```cpp
	                ans[stk.top().id] -= t;
	```
	The exclusive time of the parent task is reduced by `t` to ensure the nested task's time is not counted in the parent.

21. **Return Result**
	```cpp
	    return ans;
	```
	The function returns the `ans` vector, which contains the exclusive time for each task.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(m)
- **Worst Case:** O(m)

The time complexity is linear in terms of the number of logs.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of the call stack.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/exclusive-time-of-functions/description/)

---
{{< youtube Rjcwy-Q2uDo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
