
+++
authors = ["grid47"]
title = "Leetcode 2614: Prime In Diagonal"
date = "2024-02-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2614: Prime In Diagonal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Matrix","Number Theory"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "PEKRvVTWf4g"
youtube_upload_date="2023-04-09"
youtube_thumbnail="https://i.ytimg.com/vi_webp/PEKRvVTWf4g/maxresdefault.webp"
comments = true
+++



---
Given a 2D grid of integers, you need to determine the largest prime number present on any of the diagonals of the grid. A number is considered prime if it is greater than 1 and divisible only by 1 and itself. The diagonal elements are those where the row and column indices are the same or sum to the length of the grid minus 1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a square grid of integers 'nums', represented as a 2D array. Each element in nums is an integer between 1 and 4*10^6.
- **Example:** `nums = [[2, 3, 5], [7, 11, 13], [17, 19, 23]]`
- **Constraints:**
	- 1 <= nums.length <= 300
	- nums.length == numsi.length
	- 1 <= nums[i][j] <= 4 * 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the largest prime number present on any of the diagonals in the grid. If no prime number is found, return 0.
- **Example:** `Output: 23`
- **Constraints:**
	- The output is a single integer representing the largest prime number on the diagonals, or 0 if none is found.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the largest prime number that appears on at least one diagonal of the matrix.

- Step 1: Loop through the grid and check both diagonals (top-left to bottom-right and top-right to bottom-left).
- Step 2: For each number on the diagonals, check if it is prime.
- Step 3: Keep track of the largest prime number encountered.
- Step 4: Return the largest prime, or 0 if no prime is found.
{{< dots >}}
### Problem Assumptions ✅
- You can assume the matrix will be square (same number of rows and columns).
- The elements are integers, and the prime check will be done for values between 1 and 4*10^6.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [[2, 3, 5], [7, 11, 13], [17, 19, 23]]`  \
  **Explanation:** The diagonals are [2, 11, 23] and [5, 11, 17]. The prime numbers on these diagonals are 2, 11, 17, 23, and the largest prime is 23.

- **Input:** `nums = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]`  \
  **Explanation:** The diagonals are [1, 5, 9] and [3, 5, 7]. The prime numbers are 5 and 7, and the largest prime is 7.

{{< dots >}}
## Approach 🚀
We will first iterate through the diagonal elements of the 2D grid and check if each element is prime. We will keep track of the largest prime number encountered during the iteration.

### Initial Thoughts 💭
- Prime number checking can be computationally expensive, so we need an efficient method to check for primes, such as using a sieve of Eratosthenes for precomputation.
- We can precompute prime numbers up to 4 * 10^6 using a sieve, which will allow us to quickly check if a number is prime during the iteration through the matrix diagonals.
{{< dots >}}
### Edge Cases 🌐
- If the input grid is empty, return 0.
- Ensure that the algorithm handles grids of size up to 300x300 efficiently.
- Consider cases where all diagonal elements are non-prime, in which case the function should return 0.
- Handle cases where the matrix contains the maximum integer value of 4 * 10^6.
{{< dots >}}
## Code 💻
```cpp
  // seive
  bool isPrime(int n){
  if (n <= 2 || n % 2 == 0) 
      return n == 2;
  for (int i = 3; i * i <= n; i += 2)
      if (n % i == 0)
          return false;
  return true;
  }      
  int diagonalPrime(vector<vector<int>>& n) {
  int p = 0;
  for (int i = 0; i < n.size(); ++i)
      p = max({p, isPrime(n[i][i]) * n[i][i], 
          isPrime(n[i][n.size() - i - 1]) * n[i][n.size() - i - 1]});
  return p;
  }
```

The complete solution defines two functions. The 'isPrime' function checks whether a number is prime, and 'diagonalPrime' finds the largest prime number on the diagonals of a 2D matrix.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	  bool isPrime(int n){
	```
	The function 'isPrime' checks if a number is prime. It takes an integer 'n' as input.

2. **Condition**
	```cpp
	  if (n <= 2 || n % 2 == 0) 
	```
	The condition checks if the number is less than or equal to 2 or if it is divisible by 2, immediately returning true for number 2.

3. **Return Statement**
	```cpp
	      return n == 2;
	```
	If 'n' equals 2, the function returns true, indicating that 2 is a prime number.

4. **Loop**
	```cpp
	  for (int i = 3; i * i <= n; i += 2)
	```
	This loop checks all odd numbers starting from 3 up to the square root of 'n' to see if any divide 'n'.

5. **Condition**
	```cpp
	      if (n % i == 0)
	```
	This condition checks if 'n' is divisible by the current value of 'i'.

6. **Return Statement**
	```cpp
	          return false;
	```
	If 'n' is divisible by any number 'i', the function returns false, indicating that 'n' is not a prime number.

7. **Return Statement**
	```cpp
	  return true;
	```
	If no divisors are found, the function returns true, indicating that 'n' is a prime number.

8. **Function Definition**
	```cpp
	  int diagonalPrime(vector<vector<int>>& n) {
	```
	The function 'diagonalPrime' takes a 2D vector 'n' as input and finds the largest prime number on its diagonals.

9. **Variable Declaration**
	```cpp
	  int p = 0;
	```
	A variable 'p' is declared to store the largest prime number found on the diagonals.

10. **Loop**
	```cpp
	  for (int i = 0; i < n.size(); ++i)
	```
	This loop iterates through each index of the 2D vector to check the diagonals.

11. **Max Calculation**
	```cpp
	      p = max({p, isPrime(n[i][i]) * n[i][i], 
	```
	The current maximum prime value is updated by comparing it with the prime values found at the current diagonal positions.

12. **Max Calculation**
	```cpp
	          isPrime(n[i][n.size() - i - 1]) * n[i][n.size() - i - 1]});
	```
	The second diagonal element is also checked for primality and the maximum prime is updated.

13. **Return Statement**
	```cpp
	  return p;
	```
	The function returns the largest prime number found on either of the diagonals.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2 + P), where P is the sieve's precomputation time

The sieve of Eratosthenes takes O(P) time, where P is the largest number in the grid, and checking the diagonals takes O(n^2) time, where n is the size of the grid.

### Space Complexity 💾
- **Best Case:** O(P)
- **Worst Case:** O(P)

The space complexity is dominated by the storage required for the sieve array, which has a space complexity of O(P), where P is 4 * 10^6.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/prime-in-diagonal/description/)

---
{{< youtube PEKRvVTWf4g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
