
+++
authors = ["grid47"]
title = "Leetcode 2443: Sum of Number and Its Reverse"
date = "2024-03-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2443: Sum of Number and Its Reverse in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ESqVFCHtAGg"
youtube_upload_date="2022-10-16"
youtube_thumbnail="https://i.ytimg.com/vi_webp/ESqVFCHtAGg/maxresdefault.webp"
comments = true
+++



---
Given a non-negative integer `num`, determine if `num` can be expressed as the sum of a non-negative integer and its reverse. If so, return `true`, otherwise return `false`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a non-negative integer `num`.
- **Example:** `num = 527`
- **Constraints:**
	- 0 <= num <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return `true` if there exists a non-negative integer `x` such that `x + reverse(x) = num`. Otherwise, return `false`.
- **Example:** `Output: true`
- **Constraints:**
	- The solution must be efficient enough to handle values of `num` up to 10^5.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find whether a number can be represented as the sum of a number and its reverse.

- 1. Reverse a number using a helper function.
- 2. Check for each number `i` from 0 to `num` if `i + reverse(i)` equals `num`.
- 3. If a valid number `i` is found, return `true`. Otherwise, return `false`.
{{< dots >}}
### Problem Assumptions ✅
- The number `num` is always non-negative and lies within the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `num = 443`  \
  **Explanation:** We check for integers `i` such that `i + reverse(i)` equals 443. For `i = 172`, the reverse of 172 is 271, and `172 + 271 = 443`, so the answer is `true`.

- **Input:** `num = 63`  \
  **Explanation:** No number `i` exists such that `i + reverse(i)` equals 63, so the answer is `false`.

{{< dots >}}
## Approach 🚀
The approach involves checking if for any number `i` between 0 and `num`, the sum of `i` and its reverse equals `num`.

### Initial Thoughts 💭
- We need a function to reverse the digits of a number.
- We will check all numbers from 0 to `num` to see if the sum of a number and its reverse equals `num`.
- By reversing a number and adding it to the original number, we can check if it equals the target number.
{{< dots >}}
### Edge Cases 🌐
- The input will never be empty as per the constraints.
- The algorithm should efficiently handle `num` values up to 10^5.
- When `num = 0`, it should correctly return `true` as `0 + reverse(0) = 0`.
- Ensure the algorithm works within the time limits for `num` values up to 10^5.
{{< dots >}}
## Code 💻
```cpp
int rev(int num) {
    int tmp = 0;
    while(num) {
        tmp = tmp * 10 + num % 10;
        num /= 10;
    }
    return tmp;
}

bool sumOfNumberAndReverse(int num) {
    
    for(int i = 0; i <= num; i++) {
        if((i + rev(i) )== num) {
            return true;
        }
    }
    return false;
}
```

This code contains two functions: `rev`, which reverses a given number, and `sumOfNumberAndReverse`, which checks if there exists a number `i` such that `i + rev(i) == num`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int rev(int num) {
	```
	Defining the `rev` function, which takes an integer `num` and returns its reversed value.

2. **Variable Initialization**
	```cpp
	    int tmp = 0;
	```
	Initializing `tmp` to store the reversed number, starting with a value of 0.

3. **Loop**
	```cpp
	    while(num) {
	```
	A loop that continues as long as `num` is greater than 0, reversing the digits of `num`.

4. **Mathematical Operation**
	```cpp
	        tmp = tmp * 10 + num % 10;
	```
	Extracting the last digit of `num` and adding it to `tmp` after shifting `tmp` one place to the left.

5. **Integer Update**
	```cpp
	        num /= 10;
	```
	Removing the last digit from `num` by dividing it by 10.

6. **Return Statement**
	```cpp
	    return tmp;
	```
	Returning the reversed integer `tmp`.

7. **Function Definition**
	```cpp
	bool sumOfNumberAndReverse(int num) {
	```
	Defining the `sumOfNumberAndReverse` function, which takes an integer `num` and checks if there exists an integer `i` such that `i + rev(i) == num`.

8. **Loop**
	```cpp
	    for(int i = 0; i <= num; i++) {
	```
	A loop that iterates through integers `i` from 0 to `num` to check if `i + rev(i) == num`.

9. **Condition Check**
	```cpp
	        if((i + rev(i) )== num) {
	```
	Checking if the sum of `i` and its reverse equals `num`.

10. **Return Statement**
	```cpp
	            return true;
	```
	Returning `true` if there exists an integer `i` such that `i + rev(i) == num`.

11. **Return Statement**
	```cpp
	    return false;
	```
	Returning `false` if no integer `i` satisfies the condition `i + rev(i) == num`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(num)
- **Average Case:** O(num)
- **Worst Case:** O(num)

The time complexity is O(num), as we are iterating through all numbers from 0 to `num` and performing constant-time operations (reversing a number).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we are not using any additional space that scales with the input size.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-number-and-its-reverse/description/)

---
{{< youtube ESqVFCHtAGg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
