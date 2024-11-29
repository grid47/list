
+++
authors = ["grid47"]
title = "Leetcode 2507: Smallest Value After Replacing With Sum of Prime Factors"
date = "2024-03-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2507: Smallest Value After Replacing With Sum of Prime Factors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Simulation","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Z11zwNKd89I"
youtube_upload_date="2022-12-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Z11zwNKd89I/maxresdefault.webp"
comments = true
+++



---
You are given a positive integer n. The task is to repeatedly replace n with the sum of its prime factors, and continue this process until n reaches a value that cannot be reduced further. The process stops when the sum of the prime factors is equal to the current value of n. Return the smallest value n will eventually become.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer n, where 2 <= n <= 10^5.
- **Example:** `n = 18`
- **Constraints:**
	- 2 <= n <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the smallest value that n will eventually become.
- **Example:** `5`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the smallest value that n will eventually become after repeatedly replacing it with the sum of its prime factors.

- Find the prime factors of the number n, including repeated factors.
- Replace n with the sum of its prime factors.
- Repeat the process until n cannot be reduced further, i.e., when the sum of the prime factors equals the current value of n.
{{< dots >}}
### Problem Assumptions ✅
- n is always a positive integer.
- n is not a prime number in all cases (except when the prime factors sum process stabilizes).
{{< dots >}}
## Examples 🧩
- **Input:** `n = 18`  \
  **Explanation:** The process goes as follows: 18 -> 8 -> 6 -> 5. Therefore, 5 is the smallest value n will eventually reach.

{{< dots >}}
## Approach 🚀
The approach involves finding the prime factors of n and repeatedly replacing n with the sum of its prime factors until a stable value is reached.

### Initial Thoughts 💭
- Prime factorization can be done using a trial division method.
- If n is divisible by a prime, we repeatedly divide n by that prime, adding it to the sum.
- This process will eventually stabilize because each step reduces n, and the prime factor sum either stays the same or reduces to a smaller number.
{{< dots >}}
### Edge Cases 🌐
- There will always be an input, since n >= 2.
- For large values of n, ensure the factorization is efficient to handle up to n = 10^5.
- If n is prime, the process will immediately stop since the prime factor sum will equal n.
- Ensure that the solution handles edge cases like n being a small prime number.
{{< dots >}}
## Code 💻
```cpp

int getFactSum(int n) {
    int div = 2, sum = 0;
    while(n > 1) {
        if(n % div == 0) {
            sum += div;
            n /= div;
        } else div++;
    }
    return sum;
}

int smallestValue(int n) {
    
    while(1) {
        int sum = getFactSum(n);
        if(sum == n) break;
        n = sum;
    }
    return n;
}
```

The `getFactSum` function calculates the sum of divisors of a number `n`, and the `smallestValue` function iterates by repeatedly updating `n` with the sum of its divisors until `n` becomes equal to the sum of its divisors, at which point the function returns `n`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int getFactSum(int n) {
	```
	Defines the `getFactSum` function that calculates the sum of divisors of the given integer `n`.

2. **Variable Initialization**
	```cpp
	    int div = 2, sum = 0;
	```
	Initializes two variables: `div`, starting at 2 (the smallest prime divisor), and `sum`, which stores the sum of divisors of `n`.

3. **Loop Structure**
	```cpp
	    while(n > 1) {
	```
	Starts a while loop that runs as long as `n` is greater than 1. This loop will find divisors of `n`.

4. **Condition Check**
	```cpp
	        if(n % div == 0) {
	```
	Checks if `n` is divisible by `div`. If true, the loop continues to find the divisors.

5. **Sum Update**
	```cpp
	            sum += div;
	```
	Adds `div` to the sum if `div` is a divisor of `n`.

6. **Variable Update**
	```cpp
	            n /= div;
	```
	Divides `n` by `div` to reduce it for the next iteration, potentially to find other divisors.

7. **Variable Update**
	```cpp
	        } else div++;
	```
	If `n` is not divisible by `div`, it increments `div` to check the next potential divisor.

8. **Return Statement**
	```cpp
	    return sum;
	```
	Returns the sum of divisors of `n`.

9. **Function Definition**
	```cpp
	int smallestValue(int n) {
	```
	Defines the `smallestValue` function that repeatedly updates `n` with the sum of its divisors until `n` equals its divisor sum.

10. **Infinite Loop**
	```cpp
	    while(1) {
	```
	Starts an infinite loop that will keep running until the condition inside the loop is satisfied.

11. **Function Call**
	```cpp
	        int sum = getFactSum(n);
	```
	Calls the `getFactSum` function to calculate the sum of divisors of `n`.

12. **Condition Check**
	```cpp
	        if(sum == n) break;
	```
	Checks if the sum of divisors of `n` is equal to `n`. If they are equal, it exits the loop.

13. **Variable Update**
	```cpp
	        n = sum;
	```
	If the sum of divisors is not equal to `n`, it updates `n` to the sum and continues the loop.

14. **Return Statement**
	```cpp
	    return n;
	```
	Returns the value of `n` after it becomes equal to the sum of its divisors.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log n) for prime numbers, as no further changes are needed.
- **Average Case:** O(sqrt(n)) for factorization of each number.
- **Worst Case:** O(n) for large composite numbers, depending on the prime factorization steps.

Time complexity is dominated by the prime factorization process.

### Space Complexity 💾
- **Best Case:** O(1), if n is prime and no additional storage is needed.
- **Worst Case:** O(log n), due to the storage needed for prime factorization.

The space complexity is minimal unless we store intermediate factors.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors/description/)

---
{{< youtube Z11zwNKd89I >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
