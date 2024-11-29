
+++
authors = ["grid47"]
title = "Leetcode 1491: Average Salary Excluding the Minimum and Maximum Salary"
date = "2024-06-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1491: Average Salary Excluding the Minimum and Maximum Salary in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "hTEVGYRGLsQ"
youtube_upload_date="2020-06-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/hTEVGYRGLsQ/maxresdefault.webp"
comments = true
+++



---
You are given an array salary where each element represents the salary of an employee. The salaries are all unique. Return the average salary of the employees, excluding the minimum and maximum salary. Your answer should be correct to an absolute error of no more than 10^-5.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of unique integers, where each integer represents the salary of an employee. The array length will be at least 3.
- **Example:** `salary = [5000, 3000, 1500, 3500]`
- **Constraints:**
	- 3 <= salary.length <= 100
	- 1000 <= salary[i] <= 10^6
	- All salary values are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the average salary, excluding the minimum and maximum salaries in the list. The result should be correct up to an absolute error of no more than 10^-5.
- **Example:** `Output: 3000.00000`
- **Constraints:**
	- The output should be a floating-point value.

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the average of all salaries, excluding the smallest and largest salaries.

- Identify the minimum and maximum salaries from the array.
- Sum the remaining salaries (excluding the minimum and maximum).
- Divide the sum by the number of remaining salaries to get the average.
{{< dots >}}
### Problem Assumptions ✅
- The salary array is guaranteed to have at least 3 unique elements.
- The solution should avoid using any complex operations that will affect performance.
{{< dots >}}
## Examples 🧩
- **Input:** `salary = [5000, 3000, 1500, 3500]`  \
  **Explanation:** The minimum salary is 1500, and the maximum salary is 5000. Excluding these, the average of 3000 and 3500 is 3250.

- **Input:** `salary = [1200, 2200, 3200]`  \
  **Explanation:** The minimum salary is 1200, and the maximum salary is 3200. The only remaining salary is 2200.

{{< dots >}}
## Approach 🚀
The approach is to find the minimum and maximum salaries, exclude them from the total sum, and compute the average of the remaining salaries.

### Initial Thoughts 💭
- We only need to calculate the sum of salaries excluding the minimum and maximum.
- We can use basic list operations to find the minimum and maximum values.
- This is a straightforward problem, where identifying the extreme values (min and max) is crucial to solving it efficiently.
{{< dots >}}
### Edge Cases 🌐
- The array will never be empty, as the minimum length is 3.
- For large input sizes (close to 100), the algorithm must be efficient and should work within time limits.
- Salary values are guaranteed to be unique, so we don't need to account for duplicates.
- Ensure that the solution handles edge cases efficiently, such as when the array has exactly 3 elements.
{{< dots >}}
## Code 💻
```cpp
double average(vector<int>& nums) {
    int n = nums.size();
    double sum = 0, mx = nums[0], mn = nums[0];
    for(int i = 0; i < n; i++) {
        sum += nums[i];
        mx = max((double)nums[i], mx);
        mn = min((double)nums[i], mn);
    }
    return (sum - mx - mn) / (n - 2);
}
```

The `average` function calculates the average of an array of integers, excluding the maximum and minimum values.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method**
	```cpp
	double average(vector<int>& nums) {
	```
	The function `average` calculates the average of numbers in the `nums` vector, excluding the largest and smallest values.

2. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	The variable `n` stores the number of elements in the `nums` vector.

3. **Variable Initialization**
	```cpp
	    double sum = 0, mx = nums[0], mn = nums[0];
	```
	The variables `sum`, `mx`, and `mn` are initialized. `sum` tracks the total sum of numbers, `mx` stores the maximum value, and `mn` stores the minimum value.

4. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	The loop iterates over each element in the `nums` vector to compute the sum and track the maximum and minimum values.

5. **Sum Calculation**
	```cpp
	        sum += nums[i];
	```
	Adds the current element `nums[i]` to the `sum` variable.

6. **Maximum Calculation**
	```cpp
	        mx = max((double)nums[i], mx);
	```
	Updates the `mx` variable to be the larger of the current number and the existing maximum value.

7. **Minimum Calculation**
	```cpp
	        mn = min((double)nums[i], mn);
	```
	Updates the `mn` variable to be the smaller of the current number and the existing minimum value.

8. **Return**
	```cpp
	    return (sum - mx - mn) / (n - 2);
	```
	Returns the average after excluding the maximum and minimum values. The formula subtracts the maximum and minimum from the total sum, then divides by `n - 2` to account for the removed values.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution requires iterating through the entire array once to calculate the minimum, maximum, and sum of salaries.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The solution only needs a constant amount of space, aside from the input array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/description/)

---
{{< youtube hTEVGYRGLsQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
