
+++
authors = ["grid47"]
title = "Leetcode 967: Numbers With Same Consecutive Differences"
date = "2024-08-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 967: Numbers With Same Consecutive Differences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Backtracking","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "TAfXh2l9FyA"
youtube_upload_date="2020-08-18"
youtube_thumbnail="https://i.ytimg.com/vi/TAfXh2l9FyA/hqdefault.jpg?sqp=-oaymwEmCOADEOgC8quKqQMa8AEB-AHSBoAC4AOKAgwIABABGHIgYygcMA8=&rs=AOn4CLAoEY7qSAKZyDcVLs0164H3CuKvvg"
comments = true
+++



---
Generate all numbers of length n such that the absolute difference between every two consecutive digits is exactly k. The generated numbers must not have leading zeros, and all digits should be valid.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integers, n and k, where n is the length of the numbers to generate and k is the required difference between consecutive digits.
- **Example:** `"n": 4, "k": 2`
- **Constraints:**
	- 2 <= n <= 9
	- 0 <= k <= 9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of integers of length n that satisfy the conditions. The order of the integers in the output does not matter.
- **Example:** `[1232, 3210, 3454, 5656]`
- **Constraints:**
	- The integers must have exactly n digits.
	- No leading zeros are allowed.
	- All integers in the output must adhere to the given difference condition.

{{< dots >}}
### Core Logic 🔍
**Goal:** Construct all valid integers of length n such that the difference between consecutive digits is k.

- Start with all one-digit numbers (1-9) as potential candidates for valid numbers.
- For each candidate, iteratively add a new digit to its right, ensuring the absolute difference between the last digit and the new digit is k.
- If adding a new digit creates an invalid number (e.g., leading zeroes or out-of-bound digits), discard it.
- Repeat the process until all numbers reach the required length n.
{{< dots >}}
### Problem Assumptions ✅
- The input values n and k are valid and within the specified range.
- The output must include all valid numbers that meet the criteria.
{{< dots >}}
## Examples 🧩
- **Input:** `"n": 3, "k": 3`  \
  **Explanation:** For n=3 and k=3, valid numbers include 141, 258, 303, etc. Numbers like 012 are invalid due to leading zeros, and numbers like 123 are invalid because the difference between digits does not match k.

{{< dots >}}
## Approach 🚀
Use a breadth-first search (BFS) or iterative construction to build numbers digit by digit. Maintain a list of current valid numbers and extend each by adding a digit that satisfies the difference condition.

### Initial Thoughts 💭
- Each number starts with one digit from 1-9.
- To extend a number, the last digit determines the next valid digits.
- Leading zeros are not allowed, so the first digit must always be non-zero.
- Iterative construction allows tracking and extending only valid numbers.
- Handling the case k=0 separately simplifies the logic since all digits would repeat.
{{< dots >}}
### Edge Cases 🌐
- N/A (n and k are always provided as per constraints).
- Maximum n=9 and k=9. Ensure the algorithm handles a potentially large output efficiently.
- k=0, where consecutive digits must be identical.
- k=9, where differences between digits can only occur at the extreme bounds of valid digits.
- Ensure numbers do not exceed the digit limit.
- Numbers starting with zero should be discarded.
{{< dots >}}
## Code 💻
```cpp
vector<int> numsSameConsecDiff(int n, int k) {
    vector<int> cur = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(int i = 2; i <= n; i++) {
        vector<int> cur2;
        for(int x: cur) {
            int y = x % 10;
            if(y + k < 10)
                cur2.push_back(x * 10 + y + k);
            if(k>0 && y - k >= 0)
                cur2.push_back(x * 10 + y - k);
            
        }
        cur = cur2;
    }
    return cur;
}
```

This function generates all numbers of length `n` such that the absolute difference between any two consecutive digits is `k`. It uses dynamic programming to progressively build the numbers.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> numsSameConsecDiff(int n, int k) {
	```
	The main function definition to compute numbers with specified properties.

2. **Variable Initialization**
	```cpp
	    vector<int> cur = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	```
	Initialize the current list of numbers to all single-digit numbers (1-9).

3. **Loop Construct**
	```cpp
	    for(int i = 2; i <= n; i++) {
	```
	Iterate to build numbers of increasing length from 2 to `n`.

4. **Variable Initialization**
	```cpp
	        vector<int> cur2;
	```
	Initialize a temporary vector to store numbers of the current length.

5. **Iteration**
	```cpp
	        for(int x: cur) {
	```
	Iterate over all numbers in the current list to build new numbers.

6. **Mathematical Operation**
	```cpp
	            int y = x % 10;
	```
	Extract the last digit of the current number.

7. **Conditional Check**
	```cpp
	            if(y + k < 10)
	```
	Check if adding `k` to the last digit yields a valid single digit.

8. **Vector Insertion**
	```cpp
	                cur2.push_back(x * 10 + y + k);
	```
	Add the new number formed by appending `(y + k)` to `x`.

9. **Conditional Check**
	```cpp
	            if(k>0 && y - k >= 0)
	```
	Check if subtracting `k` from the last digit yields a valid single digit.

10. **Vector Insertion**
	```cpp
	                cur2.push_back(x * 10 + y - k);
	```
	Add the new number formed by appending `(y - k)` to `x`.

11. **Variable Update**
	```cpp
	        cur = cur2;
	```
	Update `cur` to hold numbers of the current length for the next iteration.

12. **Return Statement**
	```cpp
	    return cur;
	```
	Return the final list of numbers meeting the criteria.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(2^n)
- **Average Case:** O(2^n)
- **Worst Case:** O(2^n)

Each number can branch into at most two new numbers at each step, resulting in 2^(n-1) numbers for length n.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(2^n)

Space used to store the current and next list of numbers during the iterative process.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/numbers-with-same-consecutive-differences/description/)

---
{{< youtube TAfXh2l9FyA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
