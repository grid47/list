
+++
authors = ["grid47"]
title = "Leetcode 3099: Harshad Number"
date = "2024-01-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3099: Harshad Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "QplrY0LW62M"
youtube_upload_date="2024-03-31"
youtube_thumbnail="https://i.ytimg.com/vi_webp/QplrY0LW62M/maxresdefault.webp"
comments = true
+++



---
An integer is called a Harshad number if it is divisible by the sum of its digits. You are given an integer `x`. Your task is to return the sum of the digits of `x` if `x` is a Harshad number. Otherwise, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer `x` where `1 <= x <= 100`.
- **Example:** `x = 36`
- **Constraints:**
	- 1 <= x <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the sum of the digits of `x` if `x` is a Harshad number. Otherwise, return -1.
- **Example:** `Output: 9`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine if the number is divisible by the sum of its digits and return the appropriate result.

- Calculate the sum of the digits of the number `x`.
- Check if `x` is divisible by this sum.
- If divisible, return the sum of the digits. Otherwise, return -1.
{{< dots >}}
### Problem Assumptions ✅
- The input will always be a positive integer less than or equal to 100.
{{< dots >}}
## Examples 🧩
- **Input:** `x = 36`  \
  **Explanation:** The sum of the digits of `x` is `9`, and since `36` is divisible by `9`, the result is `9`.

- **Input:** `x = 25`  \
  **Explanation:** The sum of the digits of `x` is `7`, and since `25` is not divisible by `7`, the result is `-1`.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to compute the sum of the digits of `x` and check if `x` is divisible by this sum.

### Initial Thoughts 💭
- We can easily calculate the sum of the digits by repeatedly extracting the last digit and adding it to the sum.
- We need to check if the number is divisible by the sum of its digits and return the sum or -1 accordingly.
{{< dots >}}
### Edge Cases 🌐
- This problem does not have any empty inputs since `x` is always a positive integer.
- The maximum value for `x` is 100, so performance will not be an issue.
- If `x` is a single-digit number, it will always be divisible by the sum of its digits.
- The solution should work efficiently for all integers in the range from 1 to 100.
{{< dots >}}
## Code 💻
```cpp
int sumOfTheDigitsOfHarshadNumber(int x) {
    int sum = 0;
    int tmp = x;
    while(tmp > 0) {
        sum += tmp % 10;
        tmp /= 10;
    }
    return x % sum == 0? sum : -1;
}
```

This function computes the sum of the digits of a number `x` and checks whether `x` is divisible by the sum. If it is, it returns the sum, otherwise it returns -1.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int sumOfTheDigitsOfHarshadNumber(int x) {
	```
	Defines the function `sumOfTheDigitsOfHarshadNumber`, which takes an integer `x` and returns the sum of its digits if `x` is divisible by this sum.

2. **Variable Initialization**
	```cpp
	    int sum = 0;
	```
	Initializes a variable `sum` to 0, which will be used to store the sum of the digits of `x`.

3. **Variable Initialization**
	```cpp
	    int tmp = x;
	```
	Copies the value of `x` into `tmp`. `tmp` will be used for manipulating the digits of `x` without modifying the original value.

4. **Loop Setup**
	```cpp
	    while(tmp > 0) {
	```
	Begins a `while` loop to process each digit of `tmp` by extracting and summing the digits until all digits are processed.

5. **Digit Extraction**
	```cpp
	        sum += tmp % 10;
	```
	Extracts the last digit of `tmp` using the modulo operator (`% 10`), adds it to `sum`, and prepares for the next iteration.

6. **Digit Removal**
	```cpp
	        tmp /= 10;
	```
	Removes the last digit from `tmp` by performing integer division by 10.

7. **Harshad Check**
	```cpp
	    return x % sum == 0? sum : -1;
	```
	Checks if `x` is divisible by the sum of its digits. If true, returns the sum; otherwise, returns -1 to indicate that `x` is not a Harshad number.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The solution involves iterating through the digits of the number `x` once, which makes the time complexity O(1) for the given constraints.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we are only using a few variables for storing the sum of digits and the result.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/harshad-number/description/)

---
{{< youtube QplrY0LW62M >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
