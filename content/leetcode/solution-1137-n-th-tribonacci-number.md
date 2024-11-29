
+++
authors = ["grid47"]
title = "Leetcode 1137: N-th Tribonacci Number"
date = "2024-07-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1137: N-th Tribonacci Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Memoization"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "3lpNp5Ojvrw"
youtube_upload_date="2023-01-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/3lpNp5Ojvrw/maxresdefault.webp"
comments = true
+++



---
The Tribonacci sequence is defined by the following recurrence relation: T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0. Given an integer n, return the value of Tn.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer n. You need to calculate the value of the nth term in the Tribonacci sequence.
- **Example:** `Input: n = 4`
- **Constraints:**
	- 0 <= n <= 37
	- The answer is guaranteed to fit within a 32-bit integer.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the value of Tn, which is the nth term in the Tribonacci sequence.
- **Example:** `Output: 4`
- **Constraints:**
	- The output is an integer value of the nth term.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the nth term in the Tribonacci sequence efficiently.

- Use an iterative approach to calculate the value of the nth term.
- Start with the base cases T0 = 0, T1 = 1, T2 = 1.
- For each subsequent term, compute Tn by summing the previous three terms.
{{< dots >}}
### Problem Assumptions ✅
- The input n will always be a valid integer within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 4`  \
  **Explanation:** For n = 4, the sequence is: T0 = 0, T1 = 1, T2 = 1, T3 = 2, T4 = 4. Hence, the output is 4.

- **Input:** `Input: n = 6`  \
  **Explanation:** For n = 6, the sequence is: T0 = 0, T1 = 1, T2 = 1, T3 = 2, T4 = 4, T5 = 7, T6 = 13. Hence, the output is 13.

{{< dots >}}
## Approach 🚀
To solve the problem efficiently, we can use an iterative approach where we calculate each term using the previous three terms.

### Initial Thoughts 💭
- The problem is similar to the Fibonacci sequence but involves the sum of the last three terms instead of two.
- Since the constraint is small (n <= 37), a simple iterative solution should work without optimization concerns.
{{< dots >}}
### Edge Cases 🌐
- There will always be a valid input n, and no empty inputs will be provided.
- The solution should be efficient enough to handle n up to 37.
- When n is 0, 1, or 2, the result is directly returned from the base cases.
- The answer will fit within a 32-bit signed integer, so no need to worry about overflow.
{{< dots >}}
## Code 💻
```cpp
int tribonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;
    
    int n0 = 0, n1 = 1, n2 = 1, tmp;
    
    for(int i = 3; i < n + 1; i++) {
        tmp = n2 + n1 + n0;
        n0  = n1;
        n1  = n2;
        n2  = tmp;
    }
    
    return n2;
}
```

This function calculates the `n`-th number in the Tribonacci sequence, where each term is the sum of the three preceding ones, starting with 0, 1, 1.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int tribonacci(int n) {
	```
	This line defines the `tribonacci` function, which takes an integer `n` and returns the `n`-th number in the Tribonacci sequence.

2. **Base Case Check (n == 0)**
	```cpp
	    if (n == 0) return 0;
	```
	If the input `n` is 0, the function returns 0, as the first term of the Tribonacci sequence is 0.

3. **Base Case Check (n == 1)**
	```cpp
	    if (n == 1) return 1;
	```
	If `n` is 1, the function returns 1, as the second term of the Tribonacci sequence is 1.

4. **Base Case Check (n == 2)**
	```cpp
	    if (n == 2) return 1;
	```
	If `n` is 2, the function returns 1, as the third term of the Tribonacci sequence is also 1.

5. **Variable Initialization**
	```cpp
	    int n0 = 0, n1 = 1, n2 = 1, tmp;
	```
	The variables `n0`, `n1`, and `n2` represent the first three terms of the Tribonacci sequence. The variable `tmp` will be used to store intermediate values during the iteration.

6. **Empty Line**
	```cpp
	    
	```
	This empty line is just for readability and has no impact on the logic.

7. **Main Loop**
	```cpp
	    for(int i = 3; i < n + 1; i++) {
	```
	A `for` loop starts from index 3 and runs until `n` (inclusive), calculating each subsequent term in the Tribonacci sequence.

8. **Tribonacci Calculation**
	```cpp
	        tmp = n2 + n1 + n0;
	```
	The current term in the Tribonacci sequence (`tmp`) is calculated as the sum of the previous three terms (`n0`, `n1`, and `n2`).

9. **Update n0**
	```cpp
	        n0  = n1;
	```
	The value of `n0` is updated to the previous term `n1` for the next iteration.

10. **Update n1**
	```cpp
	        n1  = n2;
	```
	The value of `n1` is updated to the previous term `n2` for the next iteration.

11. **Update n2**
	```cpp
	        n2  = tmp;
	```
	The value of `n2` is updated to the current term `tmp` for the next iteration.

12. **Return Statement**
	```cpp
	    return n2;
	```
	The final result `n2`, which holds the `n`-th term of the Tribonacci sequence, is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) due to the iterative calculation of each term.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we only store a few variables to keep track of the previous terms.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/n-th-tribonacci-number/description/)

---
{{< youtube 3lpNp5Ojvrw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
