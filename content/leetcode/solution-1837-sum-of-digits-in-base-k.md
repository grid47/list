
+++
authors = ["grid47"]
title = "Leetcode 1837: Sum of Digits in Base K"
date = "2024-05-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1837: Sum of Digits in Base K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "tPbypmspAi8"
youtube_upload_date="2021-04-25"
youtube_thumbnail="https://i.ytimg.com/vi/tPbypmspAi8/maxresdefault.jpg"
comments = true
+++



---
Given an integer n in base 10 and a base k, convert n to base k and return the sum of the digits in base 10.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer n (in base 10) and a base k (2 <= k <= 10).
- **Example:** `n = 45, k = 7`
- **Constraints:**
	- 1 <= n <= 100
	- 2 <= k <= 10

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a single integer representing the sum of the digits of n after converting it to base k, in base 10.
- **Example:** `10`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the sum of the digits of a number after converting it from base 10 to base k.

- Convert the number n from base 10 to base k.
- Sum the digits of the resulting base k number.
- Return the sum of the digits in base 10.
{{< dots >}}
### Problem Assumptions ✅
- The base k will be a valid integer between 2 and 10.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 45, k = 7`  \
  **Explanation:** We first convert 45 from base 10 to base 7, resulting in '63'. The sum of the digits is 6 + 3 = 10, which is the final answer.

{{< dots >}}
## Approach 🚀
We will convert the number n from base 10 to base k and then sum the digits of the resulting base k number.

### Initial Thoughts 💭
- The conversion from base 10 to base k is straightforward using division and modulus operations.
- We can convert n to base k by repeatedly dividing n by k and storing the remainders. These remainders represent the digits in base k.
{{< dots >}}
### Edge Cases 🌐
- n should always be at least 1, so there are no empty inputs.
- Ensure that the function handles values of n up to 100 efficiently.
- Consider values of n that are already in base 10 or are powers of k.
- Ensure that the number is correctly converted to base k and that the sum is calculated properly.
{{< dots >}}
## Code 💻
```cpp
int sumBase(int n, int k) {
    int res=0;
    while(n!=0)
    {
        res+=(n%k);
        n/=k;
    }
    return res;
}
```

This function calculates the sum of the digits of a number `n` when represented in base `k`. It iterates through the digits of `n` in base `k` and adds them up.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int sumBase(int n, int k) {
	```
	Defines the function `sumBase` which takes two parameters, `n` (the number) and `k` (the base), and returns the sum of the digits of `n` in base `k`.

2. **Variable Initialization**
	```cpp
	    int res=0;
	```
	Initializes the variable `res` to store the running sum of the digits in base `k`.

3. **While Loop**
	```cpp
	    while(n!=0)
	```
	Starts a while loop that continues as long as `n` is not zero, processing each digit of `n` in base `k`.

4. **Digit Calculation**
	```cpp
	        res+=(n%k);
	```
	Calculates the current digit in base `k` by taking the remainder of `n` when divided by `k`, and adds it to `res`.

5. **Base Division**
	```cpp
	        n/=k;
	```
	Divides `n` by `k` to remove the current digit and move to the next one in the next iteration.

6. **Return Statement**
	```cpp
	    return res;
	```
	Returns the accumulated sum `res`, which is the sum of the digits of `n` in base `k`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log n)
- **Average Case:** O(log n)
- **Worst Case:** O(log n)

The time complexity is logarithmic in n, as we repeatedly divide n by k until it becomes 0.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(log n)

The space complexity is O(log n) due to the storage required for the digits of the base k representation.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-digits-in-base-k/description/)

---
{{< youtube tPbypmspAi8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
