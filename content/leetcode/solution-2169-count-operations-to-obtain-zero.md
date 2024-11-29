
+++
authors = ["grid47"]
title = "Leetcode 2169: Count Operations to Obtain Zero"
date = "2024-04-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2169: Count Operations to Obtain Zero in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "yPqe3KshvVo"
youtube_upload_date="2022-02-13"
youtube_thumbnail="https://i.ytimg.com/vi_webp/yPqe3KshvVo/maxresdefault.webp"
comments = true
+++



---
You are given two non-negative integers, num1 and num2. In each operation, subtract the smaller number from the larger one. Continue until one of the numbers becomes zero and return the number of operations performed.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integers, num1 and num2, which represent the two numbers for which the operations are to be performed.
- **Example:** `[4, 5]`
- **Constraints:**
	- 0 <= num1, num2 <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer, representing the total number of operations needed to make either num1 or num2 equal to zero.
- **Example:** `4`
- **Constraints:**
	- At least one of num1 or num2 will become zero after performing the operations.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to keep performing the subtraction operation on the two numbers until one of them becomes zero.

- Perform subtraction on the two numbers until either num1 or num2 becomes zero.
- Count the number of operations required.
{{< dots >}}
### Problem Assumptions ✅
- Both num1 and num2 are non-negative integers.
{{< dots >}}
## Examples 🧩
- **Input:** `[4, 5]`  \
  **Explanation:** In this example, the subtraction process is performed step by step until num1 becomes zero. The total number of steps is 4.

{{< dots >}}
## Approach 🚀
The approach is to repeatedly subtract the smaller number from the larger one and keep track of the number of operations. The process continues until one number becomes zero.

### Initial Thoughts 💭
- The subtraction operation is straightforward, and the number of operations depends on the difference between the two numbers.
- We need to keep track of how many times the subtraction operation is performed until one of the numbers reaches zero.
{{< dots >}}
### Edge Cases 🌐
- The input will not be empty as both num1 and num2 must be non-negative integers.
- The solution must handle cases where num1 and num2 are large, up to 100,000.
- If num1 or num2 is zero at the start, the number of operations is zero.
- Ensure the solution works efficiently for large inputs.
{{< dots >}}
## Code 💻
```cpp
int countOperations(int num1, int num2) {
    int ans = 0;
    while(num1 > 0 && num2 > 0) {
        if(num1 > num2) {
            num1 -= num2;
        } else {
            num2 -= num1;
        }
        ans++;
    }
    return ans;
}
```

This code defines the `countOperations` method that calculates the number of operations needed to reduce two integers to zero using the subtractive method.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method Definition**
	```cpp
	int countOperations(int num1, int num2) {
	```
	This is the method definition for `countOperations`, which takes two integer arguments `num1` and `num2`.

2. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	The variable `ans` is initialized to 0. It will store the number of operations performed.

3. **While Loop**
	```cpp
	    while(num1 > 0 && num2 > 0) {
	```
	The `while` loop continues as long as both `num1` and `num2` are greater than 0.

4. **If Condition**
	```cpp
	        if(num1 > num2) {
	```
	If `num1` is greater than `num2`, the following operation is executed.

5. **Subtraction Operation**
	```cpp
	            num1 -= num2;
	```
	This operation subtracts `num2` from `num1`.

6. **Else Condition**
	```cpp
	        } else {
	```
	If the `if` condition is not met, the following `else` block is executed.

7. **Subtraction Operation**
	```cpp
	            num2 -= num1;
	```
	This operation subtracts `num1` from `num2`.

8. **Increment Operation**
	```cpp
	        ans++;
	```
	The `ans` variable is incremented by 1, representing one operation completed.

9. **Return Statement**
	```cpp
	    return ans;
	```
	The method returns the value of `ans`, which is the number of operations performed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(log(max(num1, num2)))
- **Worst Case:** O(max(num1, num2))

Each operation reduces one of the numbers, and the time complexity is logarithmic in the best case, linear in the worst case.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as we are only storing a few variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-operations-to-obtain-zero/description/)

---
{{< youtube yPqe3KshvVo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
