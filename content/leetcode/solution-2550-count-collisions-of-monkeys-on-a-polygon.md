
+++
authors = ["grid47"]
title = "Leetcode 2550: Count Collisions of Monkeys on a Polygon"
date = "2024-02-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2550: Count Collisions of Monkeys on a Polygon in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Recursion"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "fwdV-VrFRiA"
youtube_upload_date="2023-01-29"
youtube_thumbnail="https://i.ytimg.com/vi/fwdV-VrFRiA/maxresdefault.jpg"
comments = true
+++



---
You are given a regular convex polygon with `n` vertices. Each vertex has one monkey. Every monkey can move either clockwise or anticlockwise to a neighboring vertex. A collision occurs if two monkeys land on the same vertex or cross paths on an edge. Your task is to return the number of ways the monkeys can move such that at least one collision happens, modulo 10^9 + 7.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a single integer `n`, which represents the number of vertices in the polygon.
- **Example:** `n = 4`
- **Constraints:**
	- 3 <= n <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of ways the monkeys can move such that at least one collision happens, modulo 10^9 + 7.
- **Example:** `6`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the number of collision-producing moves for the monkeys.

- 1. Start by calculating the total number of possible movements for the monkeys, which is 2^n.
- 2. Subtract the number of valid movements where no collision occurs (this can be derived from symmetry).
- 3. The result is the number of ways that at least one collision will happen.
{{< dots >}}
### Problem Assumptions ✅
- The monkeys always move simultaneously and only to neighboring vertices.
- The number of possible ways to move can be extremely large, so the result must be computed modulo 10^9 + 7.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 4`  \
  **Explanation:** For `n = 4`, there are 16 possible ways the monkeys can move. Among them, 6 ways result in a collision, where at least two monkeys either meet on the same vertex or cross paths.

- **Input:** `n = 5`  \
  **Explanation:** For `n = 5`, the total possible movements are 32. Out of them, 10 lead to a collision.

{{< dots >}}
## Approach 🚀
To calculate the number of ways that result in at least one collision, we compute the total number of movements and subtract the number of movements that avoid a collision.

### Initial Thoughts 💭
- The total number of movements is 2^n, where `n` is the number of monkeys (vertices).
- We need to count the number of movements that lead to no collision and subtract it from the total.
- The key observation is that the monkeys either move clockwise or anticlockwise, and we need to count how many such configurations avoid any collisions.
{{< dots >}}
### Edge Cases 🌐
- The input `n` is guaranteed to be at least 3, so there are no empty inputs.
- The value of `n` can be as large as 10^9, so the solution needs to be optimized for large values.
- Special values such as `n = 3` can be handled directly by the formula for total possible movements.
- The solution needs to handle very large inputs efficiently, using modular exponentiation.
{{< dots >}}
## Code 💻
```cpp
int mod = (int) 1e9 + 7;

int power(int a, int n) {
    if(n == 0) return 1;
    long long res = power(a, n/2) % mod;

    long long y = (res * res) %mod;
    // cout << (int) y << " " ;
    if(n & 1) {
        y = (a * y) % mod;
        return y;            
    }
    return y % mod;
}

int monkeyMove(int n) {
    
    int res = power(2, n);
    
    return (res - 2)<0? mod - res:res-2 ;
}
```

This code contains two functions: 'power', which computes the exponentiation of a base number 'a' raised to the power 'n' modulo a large prime number, and 'monkeyMove', which uses this power function to compute the result for a specific problem and return the answer modulo 1e9 + 7.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int mod = (int) 1e9 + 7;
	```
	This line initializes the constant 'mod' to the value 1e9 + 7, which is commonly used in competitive programming for modulo operations to prevent overflow.

2. **Function Definition**
	```cpp
	int power(int a, int n) {
	```
	This is the definition of the 'power' function that takes two integers, 'a' (base) and 'n' (exponent), and calculates a^n modulo mod using recursion.

3. **Base Case**
	```cpp
	    if(n == 0) return 1;
	```
	This checks if the exponent 'n' is 0. The base case of exponentiation is that any number raised to the power of 0 is 1.

4. **Recursive Call**
	```cpp
	    long long res = power(a, n/2) % mod;
	```
	This recursive step calls the 'power' function on the halved exponent (n/2) and stores the result in 'res'. The result is then taken modulo 'mod'.

5. **Squaring the Result**
	```cpp
	    long long y = (res * res) %mod;
	```
	After the recursive call, the result 'res' is squared to get the intermediate value 'y'. This operation is also taken modulo 'mod'.

6. **Odd Exponent Check**
	```cpp
	    if(n & 1) {
	```
	This checks if the exponent 'n' is odd using bitwise AND operation. If true, it means 'n' is odd, and further adjustment is needed.

7. **Handling Odd Exponent**
	```cpp
	        y = (a * y) % mod;
	```
	If 'n' is odd, we multiply the result 'y' by the base 'a' and take the result modulo 'mod' to adjust for the odd exponent.

8. **Return Odd Exponent Result**
	```cpp
	        return y;            
	```
	After adjusting for the odd exponent, the function returns the final result 'y'.

9. **Final Result Return**
	```cpp
	    return y % mod;
	```
	If the exponent is even, we simply return the squared result 'y' modulo 'mod'.

10. **Function Definition**
	```cpp
	int monkeyMove(int n) {
	```
	This is the definition of the 'monkeyMove' function that takes an integer 'n' and calculates the number of ways the monkey can move using the 'power' function.

11. **Calculating Power of 2**
	```cpp
	    int res = power(2, n);
	```
	This line calculates 2 raised to the power 'n' using the 'power' function and stores the result in 'res'.

12. **Adjusting Result**
	```cpp
	    return (res - 2)<0? mod - res:res-2 ;
	```
	This line adjusts the result: if the result 'res - 2' is negative, it returns 'mod - res', otherwise, it returns 'res - 2'. This ensures the result is non-negative and modulo 'mod'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log n), due to the use of fast exponentiation to compute 2^n.
- **Average Case:** O(log n), as the exponentiation method is logarithmic in complexity.
- **Worst Case:** O(log n), as the computation of 2^n modulo 10^9 + 7 uses efficient algorithms.

The time complexity is logarithmic due to fast exponentiation.

### Space Complexity 💾
- **Best Case:** O(1), as there is no additional space needed beyond basic variables.
- **Worst Case:** O(1), since we only need to store a few variables.

The space complexity is constant as the solution only uses a few variables to store intermediate results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon/description/)

---
{{< youtube fwdV-VrFRiA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
