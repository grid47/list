
+++
authors = ["grid47"]
title = "Leetcode 509: Fibonacci Number"
date = "2024-09-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 509: Fibonacci Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Recursion","Memoization"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/509.webp"
youtube = "WPBTYmvcHXs"
youtube_upload_date="2019-12-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/WPBTYmvcHXs/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/509.webp" 
    alt="A sequence of numbers where each Fibonacci number glows as it is calculated in the sequence."
    caption="Solution to LeetCode 509: Fibonacci Number Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
The Fibonacci sequence is a series of numbers where each number is the sum of the two preceding ones, starting from 0 and 1. Given an integer n, return the nth Fibonacci number.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an integer n, representing the position of the desired Fibonacci number.
- **Example:** `n = 2`
- **Constraints:**
	- 0 <= n <= 30

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the nth Fibonacci number.
- **Example:** `1`
- **Constraints:**
	- The output should be an integer representing the nth Fibonacci number.

{{< dots >}}
### Core Logic 🔍
**Goal:** To compute the nth Fibonacci number efficiently using dynamic programming or iterative methods.

- 1. Initialize an array to store Fibonacci numbers up to n.
- 2. Set the base cases F(0) = 0 and F(1) = 1.
- 3. Use a loop to calculate the Fibonacci numbers for all values up to n.
- 4. Return the value of F(n).
{{< dots >}}
### Problem Assumptions ✅
- The value of n will always be a non-negative integer.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 2`  \
  **Explanation:** For n = 2, the Fibonacci sequence is [0, 1, 1], so F(2) = 1.

{{< dots >}}
## Approach 🚀
The approach is to use an iterative method with dynamic programming to calculate the Fibonacci numbers up to n.

### Initial Thoughts 💭
- The Fibonacci sequence can be computed using recursion, but an iterative approach is more efficient for larger values of n.
- We can use a dynamic programming approach to store previously computed Fibonacci numbers to avoid redundant calculations.
- By using an array to store intermediate results, we can compute Fibonacci numbers in linear time.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs as n will always be an integer between 0 and 30.
- The algorithm is efficient enough to handle n up to 30, so there are no large input concerns.
- The base cases for F(0) and F(1) should be handled correctly.
- The algorithm must run in O(n) time for values of n between 0 and 30.
{{< dots >}}
## Code 💻
```cpp
int fib(int n) {
    if(n == 0) return 0;
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++)
    dp[i] = dp[i - 1] + dp[i - 2];
        
    return dp[n];
}
```

This solution implements the Fibonacci sequence using dynamic programming to optimize the space and time complexity. It uses a bottom-up approach where the previous two Fibonacci numbers are stored and reused to compute the next number.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int fib(int n) {
	```
	Defines the `fib` function that takes an integer `n` and returns the nth Fibonacci number.

2. **Base Case Check**
	```cpp
	    if(n == 0) return 0;
	```
	Checks the base case: if `n` is 0, return 0 since the 0th Fibonacci number is 0.

3. **Array Initialization**
	```cpp
	    vector<int> dp(n + 1, 0);
	```
	Initializes a dynamic programming array `dp` of size `n+1` where each element is set to 0. This array will store the Fibonacci numbers up to the nth number.

4. **Base Case Assignment**
	```cpp
	    dp[0] = 0;
	```
	Assigns the value 0 to the first element in the dp array, corresponding to the 0th Fibonacci number.

5. **Base Case Assignment**
	```cpp
	    dp[1] = 1;
	```
	Assigns the value 1 to the second element in the dp array, corresponding to the 1st Fibonacci number.

6. **Loop Start**
	```cpp
	    for(int i = 2; i <= n; i++)
	```
	Starts a loop from `i = 2` up to `n` to calculate the Fibonacci numbers iteratively.

7. **Fibonacci Calculation**
	```cpp
	    dp[i] = dp[i - 1] + dp[i - 2];
	```
	Calculates the current Fibonacci number by adding the previous two Fibonacci numbers (dp[i-1] and dp[i-2]) and stores the result in dp[i].

8. **Return Statement**
	```cpp
	    return dp[n];
	```
	Returns the nth Fibonacci number from the dp array.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the input number. The algorithm computes Fibonacci numbers in a linear fashion.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n), due to the space required to store Fibonacci numbers in the dp array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/fibonacci-number/description/)

---
{{< youtube WPBTYmvcHXs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
