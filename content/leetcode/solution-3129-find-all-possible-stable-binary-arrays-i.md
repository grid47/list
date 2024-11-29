
+++
authors = ["grid47"]
title = "Leetcode 3129: Find All Possible Stable Binary Arrays I"
date = "2023-12-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3129: Find All Possible Stable Binary Arrays I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "PVsRUVGHVCY"
youtube_upload_date="2024-04-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/PVsRUVGHVCY/maxresdefault.webp"
comments = true
+++



---
You are given three positive integers: `zero`, `one`, and `limit`. A binary array is called stable if it satisfies the following conditions:

1. It contains exactly one occurrence of the number 1.
2. It contains exactly zero occurrences of the number 0.
3. Any subarray of size greater than `limit` must contain both 0 and 1.

Return the total number of stable binary arrays that can be formed. Since the answer can be large, return it modulo 10^9 + 7.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given three positive integers: `zero`, `one`, and `limit`.
- **Example:** `Example 1:
Input: zero = 1, one = 1, limit = 2
Output: 2`
- **Constraints:**
	- 1 <= zero, one, limit <= 200

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of stable binary arrays modulo 10^9 + 7.
- **Example:** `Example 1:
Input: zero = 1, one = 1, limit = 2
Output: 2`
- **Constraints:**
	- The result must be returned modulo 10^9 + 7.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the number of stable binary arrays that can be formed based on the given inputs `zero`, `one`, and `limit`.

- Define a dynamic programming function that tracks the current state of the binary array with values for `zero`, `one`, and the array's length constraint `limit`.
- Use memoization to store intermediate results to optimize the computation.
- At each step, calculate the number of valid arrays by considering valid transitions between states of the array.
{{< dots >}}
### Problem Assumptions ✅
- The binary array must contain exactly one occurrence of 1 and exactly zero occurrences of 0.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1:`  \
  **Explanation:** The binary arrays [1, 0] and [0, 1] are both stable because both satisfy the conditions: they have exactly one 1 and zero 0s, and no subarray of size greater than 2 violates the condition of containing both 0 and 1.

- **Input:** `Example 2:`  \
  **Explanation:** In this case, the only valid stable binary array is [1, 0, 1]. The arrays [1, 1, 0] and [0, 1, 1] are not stable because they contain a subarray of size 2 with identical elements.

{{< dots >}}
## Approach 🚀
We will use dynamic programming and memoization to efficiently calculate the number of valid stable binary arrays. The key idea is to track the current state of the binary array and count the valid transitions between states while respecting the size constraint `limit`.

### Initial Thoughts 💭
- The problem involves binary arrays, so it is important to track the occurrences of 0s and 1s.
- Memoization will help avoid redundant calculations and improve the efficiency of the solution.
{{< dots >}}
### Edge Cases 🌐
- The inputs should always be non-zero integers, so there are no edge cases involving empty inputs.
- The algorithm should be optimized to handle the upper limits of `zero`, `one`, and `limit` efficiently.
- Consider the case where `zero` and `one` are both equal to 1, which results in a single valid binary array.
- Ensure that the result is returned modulo 10^9 + 7.
{{< dots >}}
## Code 💻
```cpp
vector<vector<vector<vector<int>>>> mem;
int limit, mod = 1000000007;
int dp(int z, int o, int p, int lmt, vector<vector<vector<vector<int>>>> &mem) {
    if(z == 0 && o == 0) return 1;
    if(mem[p][o][lmt][z] != -1) return mem[p][o][lmt][z];
    long ans = 0;
    if(p == 0) {
        if(z > 0 && lmt < limit)    ans += dp(z - 1, o, 0, lmt + 1, mem) % mod;
        if(o > 0)                   ans += dp(z, o - 1, 1, 1, mem)% mod;
    } else {
        if(o > 0 && lmt < limit)    ans += dp(z, o - 1, 1, lmt + 1, mem)% mod;
        if(z > 0)                   ans += dp(z - 1, o, 0, 1, mem)% mod;
    }
    return mem[p][o][lmt][z] = ans % mod;
}
int numberOfStableArrays(int zero, int one, int limit) {
    vector<vector<vector<vector<int>>>> mem(2, vector<vector<vector<int>>>(one + 1, vector<vector<int>>(limit + 1, vector<int>(zero + 1, -1))));
    this->limit = limit;
    long res  = (dp(zero - 1, one, 0, 1, mem) +
                 dp(zero, one - 1, 1, 1, mem)) % mod;
    return res;
}
```

This code defines a dynamic programming approach to solve the problem of counting stable arrays with given constraints. It utilizes memoization to efficiently calculate the number of stable arrays possible, given the number of zeros, ones, and a limit.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	vector<vector<vector<vector<int>>>> mem;
	```
	Initializes a 4-dimensional vector `mem` to store the results of subproblems for memoization, avoiding redundant calculations.

2. **Variable Initialization**
	```cpp
	int limit, mod = 1000000007;
	```
	Initializes the variable `limit` for the maximum number of allowed operations and `mod` to handle large numbers using modulo arithmetic.

3. **Function Definition**
	```cpp
	int dp(int z, int o, int p, int lmt, vector<vector<vector<vector<int>>>> &mem) {
	```
	Defines the recursive dynamic programming function `dp` which computes the number of stable arrays based on the current state of zeros (`z`), ones (`o`), and the limit (`lmt`).

4. **Base Case**
	```cpp
	    if(z == 0 && o == 0) return 1;
	```
	Base case: if both zeros and ones are exhausted, return 1 as there is one valid configuration (an empty array).

5. **Memoization Check**
	```cpp
	    if(mem[p][o][lmt][z] != -1) return mem[p][o][lmt][z];
	```
	Checks if the current subproblem has already been solved by looking it up in the `mem` table. If so, returns the stored result to avoid redundant computation.

6. **Variable Initialization**
	```cpp
	    long ans = 0;
	```
	Initializes the variable `ans` to accumulate the result of valid stable arrays for the current state.

7. **Conditional Logic**
	```cpp
	    if(p == 0) {
	```
	Checks if the parity (`p`) is 0, determining how the recursive calls should branch for the current state.

8. **Recursive Call**
	```cpp
	        if(z > 0 && lmt < limit)    ans += dp(z - 1, o, 0, lmt + 1, mem) % mod;
	```
	If there are remaining zeros (`z > 0`) and the limit hasn't been reached (`lmt < limit`), recursively calls `dp` to add the result for a configuration where the next element is a zero.

9. **Recursive Call**
	```cpp
	        if(o > 0)                   ans += dp(z, o - 1, 1, 1, mem)% mod;
	```
	If there are remaining ones (`o > 0`), recursively calls `dp` to add the result for a configuration where the next element is a one.

10. **Else Condition**
	```cpp
	    } else {
	```
	If `p` is not 0, it switches the roles of zeros and ones, making recursive calls accordingly.

11. **Recursive Call**
	```cpp
	        if(o > 0 && lmt < limit)    ans += dp(z, o - 1, 1, lmt + 1, mem)% mod;
	```
	If there are remaining ones (`o > 0`) and the limit is not exceeded, recursively calls `dp` for configurations with a one as the next element.

12. **Recursive Call**
	```cpp
	        if(z > 0)                   ans += dp(z - 1, o, 0, 1, mem)% mod;
	```
	If there are remaining zeros (`z > 0`), recursively calls `dp` for configurations with a zero as the next element.

13. **Memoization Store**
	```cpp
	    return mem[p][o][lmt][z] = ans % mod;
	```
	Stores the result of the current subproblem in the `mem` table to prevent redundant calculations in future recursive calls.

14. **Function Definition**
	```cpp
	int numberOfStableArrays(int zero, int one, int limit) {
	```
	Defines the main function `numberOfStableArrays` which sets up the problem parameters, initializes the memoization table, and calls the `dp` function.

15. **Memoization Initialization**
	```cpp
	    vector<vector<vector<vector<int>>>> mem(2, vector<vector<vector<int>>>(one + 1, vector<vector<int>>(limit + 1, vector<int>(zero + 1, -1))));
	```
	Initializes the 4-dimensional memoization table `mem` to store results for subproblems. The dimensions represent the state variables: parity (`p`), number of ones (`o`), limit (`lmt`), and number of zeros (`z`).

16. **Set Limit**
	```cpp
	    this->limit = limit;
	```
	Sets the `limit` variable for the problem instance.

17. **Recursive Call**
	```cpp
	    long res  = (dp(zero - 1, one, 0, 1, mem) +
	                 dp(zero, one - 1, 1, 1, mem)) % mod;
	```
	Calls the `dp` function with initial conditions to compute the result, summing the contributions from configurations starting with either a zero or one.

18. **Return Result**
	```cpp
	    return res;
	```
	Returns the final result for the number of stable arrays.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(zero * one * limit)
- **Average Case:** O(zero * one * limit)
- **Worst Case:** O(zero * one * limit)

The time complexity is determined by the number of states and transitions in the dynamic programming solution.

### Space Complexity 💾
- **Best Case:** O(zero * one * limit)
- **Worst Case:** O(zero * one * limit)

The space complexity is dominated by the memoization table that stores intermediate results for all possible states.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/description/)

---
{{< youtube PVsRUVGHVCY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
