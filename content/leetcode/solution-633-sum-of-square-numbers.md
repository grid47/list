
+++
authors = ["grid47"]
title = "Leetcode 633: Sum of Square Numbers"
date = "2024-09-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 633: Sum of Square Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Two Pointers","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/633.webp"
youtube = "B0UrG_X2faA"
youtube_upload_date="2024-06-17"
youtube_thumbnail="https://i.ytimg.com/vi/B0UrG_X2faA/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/633.webp" 
    alt="A series of squares where the sum of square numbers is calculated and softly glowing as it’s computed."
    caption="Solution to LeetCode 633: Sum of Square Numbers Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a non-negative integer c, determine if there exist two non-negative integers a and b such that a^2 + b^2 = c.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a non-negative integer c.
- **Example:** `c = 5`
- **Constraints:**
	- 0 <= c <= 2^31 - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if such integers a and b exist, otherwise return false.
- **Example:** `true`
- **Constraints:**
	- The output is either true or false.

{{< dots >}}
### Core Logic 🔍
**Goal:** Check if there are two integers a and b such that their squares sum up to the given number c.

- Start with two pointers: one at 0 (left) and the other at the square root of c (right).
- Check the sum of their squares: if the sum is less than c, move the left pointer to the right; if it's greater, move the right pointer to the left; if it's equal, return true.
{{< dots >}}
### Problem Assumptions ✅
- The input will always be a valid non-negative integer.
{{< dots >}}
## Examples 🧩
- **Input:** `c = 5`  \
  **Explanation:** In this case, the integers 1 and 2 satisfy the equation 1^2 + 2^2 = 5, so the output is true.

{{< dots >}}
## Approach 🚀
The approach uses two pointers to check if there exist two integers whose squares sum up to c.

### Initial Thoughts 💭
- We need an efficient way to check for the existence of such integers, especially given the large constraint for c.
- Using the two-pointer technique allows us to efficiently check possible pairs of squares without checking every single pair.
{{< dots >}}
### Edge Cases 🌐
- The input is always a non-negative integer, so no empty inputs to handle.
- Ensure the solution works efficiently even for the largest values of c, up to 2^31 - 1.
- For c = 0, the answer should be true since 0^2 + 0^2 = 0.
- The solution must handle values of c from 0 to 2^31 - 1.
{{< dots >}}
## Code 💻
```cpp
bool judgeSquareSum(int c) {
    long left = 0, right = sqrt(c);
    while(left <= right) {
        long res = left * left + right * right;
        if(res < c)
        left++;
        else if(res > c) 
        right--;
        else return true;
    }
    return false;
}
```

This code defines the function `judgeSquareSum` that checks whether a number `c` can be expressed as the sum of two squares. It uses two pointers, `left` and `right`, to iterate over possible values of squares and check if their sum equals `c`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool judgeSquareSum(int c) {
	```
	This line declares the function `judgeSquareSum`, which takes an integer `c` and returns a boolean value indicating whether `c` can be written as the sum of two squares.

2. **Variable Initialization**
	```cpp
	    long left = 0, right = sqrt(c);
	```
	Two variables `left` and `right` are initialized. `left` starts at 0, and `right` is set to the square root of `c` (converted to a `long`). These variables will be used to represent the two numbers whose squares are being summed.

3. **Loop**
	```cpp
	    while(left <= right) {
	```
	A `while` loop starts, running as long as `left` is less than or equal to `right`. This loop will check different combinations of squares of `left` and `right`.

4. **Sum of Squares Calculation**
	```cpp
	        long res = left * left + right * right;
	```
	The sum of squares of `left` and `right` is calculated and stored in the variable `res`.

5. **If Condition for res < c**
	```cpp
	        if(res < c)
	```
	If the sum of squares `res` is less than `c`, the left pointer `left` needs to be incremented to increase the sum.

6. **Increment left**
	```cpp
	        left++;
	```
	If the sum is less than `c`, the left pointer is incremented to explore larger squares.

7. **Else If Condition for res > c**
	```cpp
	        else if(res > c) 
	```
	If the sum of squares `res` is greater than `c`, the right pointer `right` needs to be decremented to reduce the sum.

8. **Decrement right**
	```cpp
	        right--;
	```
	If the sum is greater than `c`, the right pointer is decremented to explore smaller squares.

9. **Found Solution**
	```cpp
	        else return true;
	```
	If the sum of squares equals `c`, the function returns `true`, indicating that `c` can be expressed as the sum of two squares.

10. **Return False**
	```cpp
	    return false;
	```
	If the loop completes without finding a valid sum of squares, the function returns `false`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(sqrt(c))
- **Average Case:** O(sqrt(c))
- **Worst Case:** O(sqrt(c))

The time complexity is O(sqrt(c)) because we only need to iterate over the possible values of left and right, which is proportional to the square root of c.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, as we only use a few variables for the pointers and calculation.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-square-numbers/description/)

---
{{< youtube B0UrG_X2faA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
