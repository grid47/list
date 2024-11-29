
+++
authors = ["grid47"]
title = "Leetcode 935: Knight Dialer"
date = "2024-08-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 935: Knight Dialer in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "vlsUUm_qqsY"
youtube_upload_date="2023-11-27"
youtube_thumbnail="https://i.ytimg.com/vi/vlsUUm_qqsY/maxresdefault.jpg"
comments = true
+++



---
A knight is on a phone pad, and it can move to adjacent numeric cells according to its unique movement pattern (an L-shape: two squares vertically and one square horizontally, or two squares horizontally and one square vertically). Given an integer n, you need to calculate how many distinct phone numbers of length n the knight can dial, starting from any numeric cell on the pad and performing n-1 valid knight jumps.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer n, representing the length of the phone number to dial.
- **Example:** `Input: n = 3`
- **Constraints:**
	- 1 <= n <= 5000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of distinct phone numbers of length n that can be dialed by the knight, modulo 10^9 + 7.
- **Example:** `Output: 30`
- **Constraints:**
	- The result should be returned modulo 10^9 + 7.

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the number of valid knight paths of length n starting from each numeric cell on the phone pad. Use dynamic programming to compute the total count efficiently by caching intermediate results.

- 1. Use dynamic programming to store the number of valid ways to reach each cell on the pad for each number of moves.
- 2. For each cell, recursively calculate the number of ways to reach it by performing valid knight moves.
- 3. Sum up the results for all starting cells, ensuring the answer is taken modulo 10^9 + 7.
{{< dots >}}
### Problem Assumptions ✅
- The knight always starts on one of the numeric cells on the phone pad.
- Each jump must follow the valid knight's move pattern, as described.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 1`  \
  **Explanation:** For a phone number of length 1, any of the 10 numeric cells on the pad can be the starting point. Thus, there are 10 possible phone numbers.

- **Input:** `Input: n = 2`  \
  **Explanation:** For a phone number of length 2, we count all valid knight moves from each numeric cell. This gives a total of 20 possible valid phone numbers.

{{< dots >}}
## Approach 🚀
The solution uses dynamic programming to compute the number of valid knight moves for each phone number length n. We maintain a table to store the results of all knight moves and use memoization to optimize the solution.

### Initial Thoughts 💭
- The knight has a restricted set of moves, so the problem can be tackled using dynamic programming.
- Using dynamic programming and memoization helps avoid recalculating the number of valid moves for the same cell multiple times.
{{< dots >}}
### Edge Cases 🌐
- The input will always contain a valid n, as per the problem constraints.
- The solution needs to efficiently handle large values of n, up to 5000.
- The smallest value of n is 1, which means the knight just needs to pick a starting point.
- The result must be returned modulo 10^9 + 7.
{{< dots >}}
## Code 💻
```cpp
class Solution {
int mod = 1e9 + 7;
public:
int knightDialer(int n) {
    long long res = 0;
    vector<vector<long long>> arr(4, vector<long long>(3, -1));
    vector<vector<vector<long long>>> mem(n + 1, arr);

    for(int i = 0; i < 4; i++)
    for(int j = 0; j < 3; j++)
    {
        res = (res + path(i, j, n, mem))% mod;
    }
    return res;
}

long long path(int i, int j, int n, vector<vector<vector<long long>>> &mem) {
    
    if(i < 0 || j < 0|| i >= 4 || j >= 3 || (i==3 && j !=1))
        return 0;

    if(mem[n][i][j] != -1) return mem[n][i][j] % mod;

    if (n == 1) return 1;

    mem[n][i][j] = path(i -1 , j -2, n - 1, mem) % mod +
              path(i -1 , j +2, n - 1, mem) % mod +
              path(i -2 , j -1, n - 1, mem) % mod +
              path(i -2 , j +1, n - 1, mem) % mod +
              path(i +1 , j -2, n - 1, mem) % mod +
              path(i +1 , j +2, n - 1, mem) % mod +
              path(i +2 , j -1, n - 1, mem) % mod +
              path(i +2 , j +1, n - 1, mem) % mod;
    return mem[n][i][j];
}

```

This code defines a solution to the Knight Dialer problem where the knight moves on a phone's number pad. The function knightDialer calculates the number of distinct phone numbers that can be formed, while the helper function path recursively calculates possible moves.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Declaration**
	```cpp
	class Solution {
	```
	Define the Solution class, which encapsulates the entire problem-solving process.

2. **Variable Declaration**
	```cpp
	int mod = 1e9 + 7;
	```
	Declare the modulus value used for handling large numbers and to avoid overflow.

3. **Access Modifier**
	```cpp
	public:
	```
	Indicates that the following methods and variables are publicly accessible.

4. **Main Function**
	```cpp
	int knightDialer(int n) {
	```
	Define the knightDialer function, which calculates the total number of distinct phone numbers the knight can dial.

5. **Result Initialization**
	```cpp
	    long long res = 0;
	```
	Initialize the result variable to 0. This will accumulate the total number of distinct dialed numbers.

6. **Grid Initialization**
	```cpp
	    vector<vector<long long>> arr(4, vector<long long>(3, -1));
	```
	Initialize the 4x3 grid, representing the phone's keypad, with all values set to -1.

7. **Memoization Table**
	```cpp
	    vector<vector<vector<long long>>> mem(n + 1, arr);
	```
	Create a memoization table to store intermediate results for subproblems, where mem[n][i][j] stores the result for n moves starting from position (i, j).

8. **Outer Loop Start**
	```cpp
	    for(int i = 0; i < 4; i++)
	```
	Start the loop iterating over all rows of the phone's keypad grid.

9. **Inner Loop Start**
	```cpp
	    for(int j = 0; j < 3; j++)
	```
	Start the loop iterating over all columns of the phone's keypad grid.

10. **Path Function Call**
	```cpp
	        res = (res + path(i, j, n, mem))% mod;
	```
	Call the path function for each (i, j) position, adding the result to the total.

11. **Return Result**
	```cpp
	    return res;
	```
	Return the accumulated result, representing the total number of distinct phone numbers the knight can dial.

12. **Path Function Declaration**
	```cpp
	long long path(int i, int j, int n, vector<vector<vector<long long>>> &mem) {
	```
	Define the path function, which recursively calculates the number of valid knight moves from position (i, j).

13. **Base Case Check**
	```cpp
	    if(i < 0 || j < 0 || i >= 4 || j >= 3 || (i==3 && j !=1))
	```
	Check if the current position is out of bounds or invalid (e.g., the knight cannot land on the bottom-right corner).

14. **Return Invalid Case**
	```cpp
	        return 0;
	```
	Return 0 if the knight's current position is invalid.

15. **Memoization Check**
	```cpp
	    if(mem[n][i][j] != -1) return mem[n][i][j] % mod;
	```
	Check if the result for the current position and move count is already computed. If so, return the stored result.

16. **Base Case for n == 1**
	```cpp
	    if (n == 1) return 1;
	```
	If the remaining number of moves is 1, return 1 as the knight can make a valid move.

17. **Recursive Calls**
	```cpp
	    mem[n][i][j] = path(i -1 , j -2, n - 1, mem) % mod +
	```
	Recursively calculate the number of valid moves from the current position by exploring all 8 possible knight moves.

18. **Recursive Calls Continue**
	```cpp
	              path(i -1 , j +2, n - 1, mem) % mod +
	```
	Continue recursive calls for the other knight moves.

19. **Final Recursive Call**
	```cpp
	              path(i +2 , j +1, n - 1, mem) % mod;
	```
	Final recursive call in the sequence, returning the total number of valid moves.

20. **Return Result**
	```cpp
	    return mem[n][i][j];
	```
	Return the calculated result, which is the total number of valid knight moves from position (i, j).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * 10)
- **Average Case:** O(n * 10)
- **Worst Case:** O(n * 10)

Each cell has at most 8 valid moves, and we compute the result for all moves up to n. The total time complexity is proportional to n times the number of cells (10).

### Space Complexity 💾
- **Best Case:** O(n * 10)
- **Worst Case:** O(n * 10)

We store results for all cells at each step of the knight's movement, leading to space complexity proportional to n times the number of cells.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/knight-dialer/description/)

---
{{< youtube vlsUUm_qqsY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
