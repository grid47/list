
+++
authors = ["grid47"]
title = "Leetcode 1969: Minimum Non-Zero Product of the Array Elements"
date = "2024-04-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1969: Minimum Non-Zero Product of the Array Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy","Recursion"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "1O57f1H8EyA"
youtube_upload_date="2021-08-15"
youtube_thumbnail="https://i.ytimg.com/vi_webp/1O57f1H8EyA/maxresdefault.webp"
comments = true
+++



---
You are given a positive integer `p`. Consider an array `nums` (1-indexed) that consists of the integers in the inclusive range `[1, 2p - 1]` represented in binary form. You are allowed to perform the following operation any number of times: Choose two elements `x` and `y` from `nums`. Choose a bit in `x` and swap it with its corresponding bit in `y`. The goal is to find the minimum non-zero product of the elements in `nums` after performing the above operation any number of times. Return this minimum product modulo (10^9 + 7).
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer `p`.
- **Example:** `p = 3`
- **Constraints:**
	- 1 <= p <= 60

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the minimum non-zero product of the elements in `nums` modulo (10^9 + 7).
- **Example:** `Output: 1512`
- **Constraints:**
	- The product should be returned modulo (10^9 + 7).

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the product of the elements in `nums` by swapping bits between elements.

- Step 1: Determine the maximum value in the range `[1, 2^p - 1]`.
- Step 2: Calculate the minimum non-zero product of the array by applying the bit-swapping operations as needed.
- Step 3: Return the product modulo (10^9 + 7).
{{< dots >}}
### Problem Assumptions ✅
- The integer `p` is always a positive integer and within the given bounds.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: p = 1, Output: 1`  \
  **Explanation:** In this case, the array `nums` contains only one element [1]. Therefore, the product is simply 1.

- **Input:** `Input: p = 2, Output: 6`  \
  **Explanation:** The array `nums` contains [1, 2, 3]. The product of these numbers is 1 * 2 * 3 = 6. No further bit-swapping is needed as the product is already minimized.

- **Input:** `Input: p = 3, Output: 1512`  \
  **Explanation:** In this case, the array `nums` consists of [1, 2, 3, 4, 5, 6, 7]. After performing the bit-swapping operations, we achieve a minimized product of 1512.

{{< dots >}}
## Approach 🚀
To minimize the product of the numbers in `nums`, we need to efficiently calculate the product of the numbers while applying the bit-swapping operation. The key is to identify the largest possible numbers and optimize the product using modular arithmetic.

### Initial Thoughts 💭
- We need to minimize the product of numbers using bit-swapping, which suggests an approach involving modular arithmetic.
- The key idea is to reduce the product as much as possible by strategically applying bit-swapping, ensuring the result is not zero.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs as the integer `p` is always provided.
- For large values of `p`, up to 60, the solution should handle large arrays efficiently.
- When `p = 1`, the array contains only one element, which simplifies the problem.
- Ensure that the solution works within the time and space limits for `p` values up to 60.
{{< dots >}}
## Code 💻
```cpp
long long mod = 1000000007;

long long expn(long long n, long long p) {
    if(p == 0) return 1;
    if(p == 1) return n%mod;
    if(p % 2 == 0) {
        long long ans = expn(n, p / 2);
        return ((ans ) * (ans )) % mod;
    } else {
        long long ans = expn(n, p / 2);
        ans = ((ans ) * (ans )) % mod;
        return (ans * (n % mod)) % mod;
    }
    return 0;
}


int minNonZeroProduct(int p) {
    long long val = pow(2, p);
    val--;
    long long ans = expn(val-1, val/2);
    return ans * (val %mod)% mod;
}
```

The provided code computes a modular exponentiation to efficiently handle large numbers in the context of mathematical problems. The first function `expn` is a recursive function to calculate powers modulo a large number, and `minNonZeroProduct` computes a result based on modular exponentiation using a formula derived from powers of 2.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Declaration**
	```cpp
	long long mod = 1000000007;
	```
	This line declares a constant `mod` with the value 1000000007, used as a modulus for all calculations to prevent overflow in large integer computations.

2. **Function Definition**
	```cpp
	long long expn(long long n, long long p) {
	```
	Defines the function `expn` which calculates the exponentiation of `n` raised to the power `p` modulo `mod`. It uses recursion to efficiently compute the result.

3. **Base Case**
	```cpp
	    if(p == 0) return 1;
	```
	Base case for recursion: when the exponent `p` is 0, return 1, as any number raised to the power of 0 is 1.

4. **Base Case**
	```cpp
	    if(p == 1) return n%mod;
	```
	Base case: when the exponent `p` is 1, return `n` modulo `mod`.

5. **Recursive Case**
	```cpp
	    if(p % 2 == 0) {
	```
	Checks if the exponent `p` is even. If it is, it recursively calculates `n^(p/2)`.

6. **Recursive Case**
	```cpp
	        long long ans = expn(n, p / 2);
	```
	Recursively calculates `n^(p/2)`, stores the result in `ans`.

7. **Recursive Case**
	```cpp
	        return ((ans ) * (ans )) % mod;
	```
	Returns the square of `ans` modulo `mod` to compute `n^p` when `p` is even.

8. **Recursive Case**
	```cpp
	    } else {
	```
	Handles the case when `p` is odd.

9. **Recursive Case**
	```cpp
	        long long ans = expn(n, p / 2);
	```
	Recursively calculates `n^(p/2)` for odd `p`.

10. **Recursive Case**
	```cpp
	        ans = ((ans ) * (ans )) % mod;
	```
	Squares `ans` and takes modulo `mod` to compute the result of `n^p`.

11. **Recursive Case**
	```cpp
	        return (ans * (n % mod)) % mod;
	```
	Since `p` is odd, multiply `ans` with `n % mod` and return the result modulo `mod`.

12. **End of Function**
	```cpp
	    return 0;
	```
	If the exponentiation process does not resolve correctly (though this should never happen), return 0 as a fallback.

13. **Function Definition**
	```cpp
	int minNonZeroProduct(int p) {
	```
	Defines the function `minNonZeroProduct` which computes a specific result using the `expn` function.

14. **Calculation**
	```cpp
	    long long val = pow(2, p);
	```
	Calculates 2 raised to the power `p`.

15. **Calculation**
	```cpp
	    val--;
	```
	Decreases `val` by 1.

16. **Calculation**
	```cpp
	    long long ans = expn(val-1, val/2);
	```
	Calls the `expn` function to calculate `(val-1)^(val/2) % mod`.

17. **Return Statement**
	```cpp
	    return ans * (val %mod)% mod;
	```
	Returns the result of multiplying `ans` by `val % mod` and taking modulo `mod`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log p)
- **Average Case:** O(log p)
- **Worst Case:** O(log p)

The time complexity is dominated by the exponentiation step, which is O(log p) due to the binary exponentiation algorithm.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, O(1), as we only need a few variables for the computation.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/description/)

---
{{< youtube 1O57f1H8EyA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
