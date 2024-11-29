
+++
authors = ["grid47"]
title = "Leetcode 258: Add Digits"
date = "2024-10-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 258: Add Digits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Simulation","Number Theory"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/258.webp"
youtube = "gPZvXaniFDQ"
youtube_upload_date="2023-04-27"
youtube_thumbnail="https://i.ytimg.com/vi/gPZvXaniFDQ/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/258.webp" 
    alt="A number gradually breaking down into smaller digits, with each step glowing brighter until a single digit is left."
    caption="Solution to LeetCode 258: Add Digits Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a non-negative integer num, repeatedly add all of its digits until the result has only one digit, and return it.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a non-negative integer num.
- **Example:** `For example, num = 56.`
- **Constraints:**
	- 0 <= num <= 231 - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the resulting single-digit number after summing the digits of num repeatedly.
- **Example:** `For num = 56, the output is 2.`
- **Constraints:**
	- The result should be a single-digit number.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to reduce the number num by repeatedly summing its digits until it becomes a single-digit number.

- 1. Initialize a variable to hold the sum of digits.
- 2. While the number has more than one digit, sum its digits and update the number.
- 3. Once the number has only one digit, return it.
{{< dots >}}
### Problem Assumptions ✅
- The input is always a non-negative integer.
{{< dots >}}
## Examples 🧩
- **Input:** `For num = 56, the output is 2.`  \
  **Explanation:** We repeatedly sum the digits of 56: 5 + 6 = 11, and then 1 + 1 = 2, which is a single digit.

{{< dots >}}
## Approach 🚀
The approach is to repeatedly sum the digits of the number num until we get a result that is a single-digit number. This can be done by breaking the number down and summing the digits in each iteration.

### Initial Thoughts 💭
- We can repeatedly break the number down into its individual digits, sum them, and repeat the process until we get a single-digit result.
- To achieve O(1) runtime, we can use properties of numbers in modular arithmetic to avoid loops or recursion.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs as the input num will always be a non-negative integer.
- If the number is very large, the sum of its digits will eventually be reduced to a single-digit number.
- If num is 0, the result will be 0.
- The solution should work for numbers up to 231 - 1.
{{< dots >}}
## Code 💻
```cpp
int addDigits(int num) {
    int res = 0;
    while(num > 9) {
        while(num > 0) {
            res += num % 10;
            num /= 10;
        }
        
        num = res;
        res = 0;
    }
    return num;
}
```

This function reduces a number to a single digit by summing its digits repeatedly. It continues summing the digits of the number until the result is a single digit.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int addDigits(int num) {
	```
	Defines the function `addDigits`, which takes an integer `num` as input and returns the resulting single-digit sum after repeatedly summing the digits of the number.

2. **Result Initialization**
	```cpp
	    int res = 0;
	```
	Initializes the variable `res` to store the sum of digits during each iteration of the inner loop.

3. **Outer Loop Check**
	```cpp
	    while(num > 9) {
	```
	Checks if the number has more than one digit. If `num` is greater than 9, the process continues to sum the digits.

4. **Inner Loop for Digit Summing**
	```cpp
	        while(num > 0) {
	```
	This inner loop processes each digit of `num` by extracting and adding them to `res`. It continues as long as `num` is greater than 0.

5. **Add Current Digit to Result**
	```cpp
	            res += num % 10;
	```
	Adds the last digit of `num` (obtained using the modulo operation) to `res`.

6. **Remove Last Digit**
	```cpp
	            num /= 10;
	```
	Removes the last digit of `num` by dividing it by 10.

7. **Reset and Repeat with Sum**
	```cpp
	        num = res;
	```
	Sets `num` to the value of `res` (the sum of digits) for the next iteration of the outer loop.

8. **Reset Result for Next Iteration**
	```cpp
	        res = 0;
	```
	Resets `res` to 0 for the next iteration, to start fresh for summing the digits of the next `num`.

9. **Return Result**
	```cpp
	    return num;
	```
	Returns the final result, which is the single digit obtained after repeatedly summing the digits of the original `num`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The solution can be optimized to O(1) using a mathematical trick based on the digital root.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we only need a constant amount of space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/add-digits/description/)

---
{{< youtube gPZvXaniFDQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
