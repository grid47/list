
+++
authors = ["grid47"]
title = "Leetcode 279: Perfect Squares"
date = "2024-10-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 279: Perfect Squares in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/279.webp"
youtube = "HLZLwjzIVGo"
youtube_upload_date="2021-05-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/HLZLwjzIVGo/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/279.webp" 
    alt="A series of glowing squares being formed from numbers, each square glowing brighter as it becomes perfect."
    caption="Solution to LeetCode 279: Perfect Squares Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer n, return the least number of perfect square numbers that sum to n. A perfect square is a number that is the square of an integer. Your goal is to determine the minimum number of perfect squares that sum up to the given integer n.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a positive integer n. Your task is to find the least number of perfect square numbers that sum up to n.
- **Example:** `Input: n = 15`
- **Constraints:**
	- 1 <= n <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the least number of perfect square numbers that sum to n.
- **Example:** `Output: 4`
- **Constraints:**
	- The returned number represents the minimum number of perfect squares that sum to n.

{{< dots >}}
### Core Logic 🔍
**Goal:** Minimize the number of perfect square numbers that sum up to n.

- Step 1: Initialize an array `cnt` where `cnt[i]` represents the least number of perfect squares that sum to i.
- Step 2: Set `cnt[0] = 0` since no perfect squares are needed to sum to 0.
- Step 3: For each number `i` from 1 to n, try subtracting all perfect squares less than or equal to `i` and update the value of `cnt[i]` by taking the minimum value.
- Step 4: After iterating through all numbers, `cnt[n]` will store the least number of perfect square numbers that sum to n.
{{< dots >}}
### Problem Assumptions ✅
- The input n is always a positive integer.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 12`  \
  **Explanation:** The least number of perfect square numbers that sum up to 12 is 3, since 12 = 4 + 4 + 4.

- **Input:** `Input: n = 15`  \
  **Explanation:** The least number of perfect square numbers that sum up to 15 is 4, since 15 = 9 + 4 + 1 + 1.

{{< dots >}}
## Approach 🚀
The approach uses dynamic programming to solve the problem by iterating over all integers up to n and finding the minimum number of perfect squares that sum to each integer.

### Initial Thoughts 💭
- The problem can be solved efficiently using dynamic programming by iterating over all numbers up to n and using the previous results to calculate the minimum for the current number.
- By using dynamic programming, we avoid redundant calculations, making the solution scalable for large values of n.
{{< dots >}}
### Edge Cases 🌐
- No empty input is expected as n is always greater than or equal to 1.
- For large values of n (e.g., up to 10^4), ensure that the dynamic programming approach efficiently calculates the solution.
- If n is a perfect square (e.g., 1, 4, 9), the answer is 1.
- The solution should handle inputs up to 10^4 efficiently, with an optimal time complexity.
{{< dots >}}
## Code 💻
```cpp
int numSquares(int n) {
    vector<long> cnt(n + 1, INT_MAX);

    cnt[0] = 0;

    for(int i = 1; i <= n; i++)
    for(int j = 1; j * j <= i; j++)
        cnt[i] = min(cnt[i], cnt[i - j * j] + 1);

    return cnt[n];

}
```

This function calculates the least number of perfect square numbers that sum up to a given number `n` using dynamic programming.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int numSquares(int n) {
	```
	Defines the function `numSquares`, which takes an integer `n` and returns the minimum number of perfect squares that sum up to `n`.

2. **Initialize DP Array**
	```cpp
	    vector<long> cnt(n + 1, INT_MAX);
	```
	Initializes a dynamic programming array `cnt` of size `n + 1` to store the minimum number of squares needed to sum up to each number. Initially, all values are set to `INT_MAX`, except `cnt[0]`.

3. **Base Case Initialization**
	```cpp
	    cnt[0] = 0;
	```
	Sets the base case `cnt[0] = 0`, as 0 requires 0 squares.

4. **Outer Loop - Iterate Through Numbers**
	```cpp
	    for(int i = 1; i <= n; i++)
	```
	Starts an outer loop to iterate through all numbers from 1 to `n`. Each `i` represents the target number to decompose into perfect squares.

5. **Inner Loop - Check Perfect Squares**
	```cpp
	    for(int j = 1; j * j <= i; j++)
	```
	Starts an inner loop to check all possible perfect squares `j * j` less than or equal to the current number `i`.

6. **Update DP Array**
	```cpp
	        cnt[i] = min(cnt[i], cnt[i - j * j] + 1);
	```
	Updates the value of `cnt[i]` by considering the current perfect square `j * j` and finding the minimum number of squares required by checking `cnt[i - j * j] + 1`.

7. **Return Result**
	```cpp
	    return cnt[n];
	```
	Returns the minimum number of perfect squares needed to sum up to `n` from the `cnt` array.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * sqrt(n))
- **Average Case:** O(n * sqrt(n))
- **Worst Case:** O(n * sqrt(n))

The time complexity is O(n * sqrt(n)) because we need to check each number from 1 to n and iterate over all perfect squares less than or equal to that number.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) as we use an array to store the minimum number of perfect squares for each number from 0 to n.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/perfect-squares/description/)

---
{{< youtube HLZLwjzIVGo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
