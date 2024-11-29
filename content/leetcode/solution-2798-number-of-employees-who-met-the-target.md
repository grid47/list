
+++
authors = ["grid47"]
title = "Leetcode 2798: Number of Employees Who Met the Target"
date = "2024-02-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2798: Number of Employees Who Met the Target in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "2AJL4Oh1snk"
youtube_upload_date="2023-07-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/2AJL4Oh1snk/maxresdefault.webp"
comments = true
+++



---
You are given an array 'hours' where each element represents the number of hours an employee has worked at the company. The company requires each employee to work for at least 'target' hours. Your task is to return the number of employees who worked at least 'target' hours.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a 0-indexed array 'hours' representing the hours worked by employees and a non-negative integer 'target'.
- **Example:** `Input: hours = [0, 1, 3, 5, 7], target = 3`
- **Constraints:**
	- 1 <= n == hours.length <= 50
	- 0 <= hours[i], target <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of employees who have worked at least 'target' hours.
- **Example:** `Output: 3`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine how many employees worked at least the target number of hours.

- Iterate through the array of hours.
- For each employee, check if their worked hours are greater than or equal to the target.
- Count the employees who meet the target hours.
{{< dots >}}
### Problem Assumptions ✅
- The input array contains non-negative integers.
- The number of employees is small enough to allow a straightforward solution.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: hours = [0, 1, 3, 5, 7], target = 3`  \
  **Explanation:** Here, the company wants employees to work for at least 3 hours. Employees with hours >= 3 are employee 2, 3, and 4, so the output is 3.

- **Input:** `Input: hours = [4, 2, 1, 6], target = 5`  \
  **Explanation:** Here, the company wants employees to work for at least 5 hours. Only employee 3 worked 6 hours, so the output is 1.

{{< dots >}}
## Approach 🚀
We can simply iterate through the list of hours and count how many employees worked hours greater than or equal to the target.

### Initial Thoughts 💭
- We need to check each employee's worked hours to determine if they meet the target.
- The solution requires a single pass through the list, making it efficient.
{{< dots >}}
### Edge Cases 🌐
- The input array is guaranteed to contain at least one element.
- The solution should handle arrays of up to 50 elements efficiently.
- If all employees have worked fewer hours than the target, the result will be 0.
- The input size and values are small enough that a simple linear scan will suffice.
{{< dots >}}
## Code 💻
```cpp
int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
    int cnt = 0;
    for(int i = 0; i < hours.size(); i++)
        if(hours[i] >= target) cnt++;
    return cnt;
}
```

This function counts how many employees met or exceeded a target number of working hours. It iterates through a vector of hours worked by employees and checks if each value meets or exceeds the target. If so, the counter is incremented and the total count is returned.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
	```
	This line declares the function `numberOfEmployeesWhoMetTarget`, which takes a reference to a vector of integers (`hours`) and an integer `target` as inputs. It returns the number of employees who met or exceeded the target hours.

2. **Variable Initialization**
	```cpp
	    int cnt = 0;
	```
	The variable `cnt` is initialized to 0. This will count how many employees have met or exceeded the target.

3. **Loop Initialization**
	```cpp
	    for(int i = 0; i < hours.size(); i++)
	```
	A `for` loop is initialized to iterate through the `hours` vector. The loop will process each employee's hours worked.

4. **Condition Check**
	```cpp
	        if(hours[i] >= target) cnt++;
	```
	Inside the loop, an `if` condition checks if the current employee's hours (i.e., `hours[i]`) meet or exceed the target. If the condition is true, the counter `cnt` is incremented.

5. **Return Result**
	```cpp
	    return cnt;
	```
	After the loop completes, the function returns the value of `cnt`, which represents the total number of employees who met or exceeded the target hours.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we iterate through the array once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we only use a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-employees-who-met-the-target/description/)

---
{{< youtube 2AJL4Oh1snk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
