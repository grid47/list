
+++
authors = ["grid47"]
title = "Leetcode 400: Nth Digit"
date = "2024-09-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 400: Nth Digit in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/400.webp"
youtube = "4QAGxDIVpdM"
youtube_upload_date="2020-07-13"
youtube_thumbnail="https://i.ytimg.com/vi_webp/4QAGxDIVpdM/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/400.webp" 
    alt="A glowing sequence of digits where the nth digit is softly illuminated and revealed."
    caption="Solution to LeetCode 400: Nth Digit Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a positive integer n. Your task is to find the nth digit in an infinite sequence of consecutive integers starting from 1. The sequence starts as [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, ...].
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You will be given an integer n, where 1 <= n <= 2^31 - 1.
- **Example:** `For n = 12, the sequence up to the 12th digit is: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12], and the 12th digit is 1.`
- **Constraints:**
	- 1 <= n <= 2^31 - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the nth digit in the infinite sequence of consecutive integers.
- **Example:** `For n = 5, the output should be 5.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to identify the nth digit in the infinite sequence efficiently.

- 1. Determine the length of the digits for the current number range.
- 2. Identify the range where the nth digit falls.
- 3. Calculate the specific number and digit within that range.
{{< dots >}}
### Problem Assumptions ✅
- The value of n is always valid and within the given constraints.
- The sequence of integers is unbounded.
{{< dots >}}
## Examples 🧩
- **Input:** `For n = 12, the sequence is [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]. The 12th digit is part of the number 12, which is 1.`  \
  **Explanation:** By breaking the sequence into ranges based on the number of digits, we can pinpoint that the 12th digit lies in the 10-99 range.

{{< dots >}}
## Approach 🚀
The approach is to break down the sequence into chunks of numbers with the same number of digits and locate the range containing the nth digit.

### Initial Thoughts 💭
- The sequence starts with single-digit numbers, then transitions to two-digit numbers, and so on.
- Each range of numbers contributes a different number of digits.
- We need to calculate which range the nth digit lies in and then pinpoint the exact number and digit.
{{< dots >}}
### Edge Cases 🌐
{{< dots >}}
## Code 💻
```cpp
int findNthDigit(int n) {
    lli len = 1;
    lli cnt = 9;
    lli start = 1;
    while(n > len * cnt) {

        n -= len * cnt;
        
        len++;
        cnt *= 10;
        start *= 10;

    }
    start += (n - 1) / len;
    string s = to_string(start);     
    return s[(n - 1) % len] - '0';
}
```

This function calculates the nth digit of a number in a sequence formed by concatenating integers starting from 1. It iteratively reduces the value of n by the length and count of the current digit group (1-digit, 2-digit, etc.) until it finds the target digit.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findNthDigit(int n) {
	```
	Define the function `findNthDigit` that takes an integer `n` as input, which represents the position of the digit to find.

2. **Variable Initialization**
	```cpp
	    lli len = 1;
	```
	Initialize `len` to 1, which represents the number of digits in the current group (starting with 1-digit numbers).

3. **Variable Initialization**
	```cpp
	    lli cnt = 9;
	```
	Initialize `cnt` to 9, representing the number of 1-digit numbers (1 to 9).

4. **Variable Initialization**
	```cpp
	    lli start = 1;
	```
	Initialize `start` to 1, representing the first number in the current digit group (starting with 1).

5. **While Loop**
	```cpp
	    while(n > len * cnt) {
	```
	Enter a while loop that continues until `n` is less than or equal to the total number of digits in the current group.

6. **While Loop End**
	```cpp
	
	```
	End of the while loop that processes the current group of numbers based on their digit length.

7. **Update n**
	```cpp
	        n -= len * cnt;
	```
	Subtract the total number of digits in the current group from `n` to shift to the next group of numbers.

8. **Increment Length**
	```cpp
	        len++;
	```
	Increase the digit length `len` to move to the next group of numbers (e.g., from 1-digit to 2-digit numbers).

9. **Update Count**
	```cpp
	        cnt *= 10;
	```
	Multiply `cnt` by 10 to account for the next group of numbers (e.g., from 9 one-digit numbers to 90 two-digit numbers).

10. **Update Start**
	```cpp
	        start *= 10;
	```
	Multiply `start` by 10 to move to the first number of the next group (e.g., from 1 to 10).

11. **Find Target Digit**
	```cpp
	    start += (n - 1) / len;
	```
	Calculate the starting number in the group that contains the target digit.

12. **Convert to String**
	```cpp
	    string s = to_string(start);     
	```
	Convert the calculated starting number `start` to a string for easy indexing.

13. **Return Result**
	```cpp
	    return s[(n - 1) % len] - '0';
	```
	Return the digit at the target position by converting it from a character to an integer.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log n)
- **Average Case:** O(log n)
- **Worst Case:** O(log n)

The time complexity is logarithmic in terms of n, as we reduce the number of possible ranges by orders of magnitude with each iteration.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, as the solution only requires a fixed amount of space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/nth-digit/description/)

---
{{< youtube 4QAGxDIVpdM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
