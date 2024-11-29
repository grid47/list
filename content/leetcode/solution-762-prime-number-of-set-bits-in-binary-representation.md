
+++
authors = ["grid47"]
title = "Leetcode 762: Prime Number of Set Bits in Binary Representation"
date = "2024-08-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 762: Prime Number of Set Bits in Binary Representation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Bit Manipulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/762.webp"
youtube = "KeCWKJxsyxA"
youtube_upload_date="2024-09-11"
youtube_thumbnail="https://i.ytimg.com/vi/KeCWKJxsyxA/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/762.webp" 
    alt="A set of binary numbers where the prime number of set bits is calculated, each prime set bit glowing softly."
    caption="Solution to LeetCode 762: Prime Number of Set Bits in Binary Representation Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given two integers left and right, return the count of numbers in the inclusive range [left, right] having a prime number of set bits in their binary representation. The number of set bits in a number is the count of 1's when the number is represented in binary. A prime number is a number greater than 1 that is divisible only by 1 and itself.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integers, left and right.
- **Example:** `Input: left = 8, right = 15`
- **Constraints:**
	- 1 <= left <= right <= 10^6
	- 0 <= right - left <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer representing the count of numbers in the range [left, right] that have a prime number of set bits.
- **Example:** `Output: 4`
- **Constraints:**
	- The answer is guaranteed to fit in a 32-bit integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find how many numbers in the range [left, right] have a prime number of set bits.

- For each number in the range [left, right], calculate the number of set bits.
- Check if the number of set bits is prime by using a pre-defined list of prime numbers.
- Count how many numbers have a prime number of set bits.
{{< dots >}}
### Problem Assumptions ✅
- The input integers left and right are within the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: Input: left = 8, right = 15`  \
  **Explanation:** In this example, the prime numbers of set bits are 2 and 3, and there are 4 numbers (9, 10, 11, 12) in the range [8, 15] that have a prime number of set bits.

{{< dots >}}
## Approach 🚀
We can solve this problem by iterating through each number in the given range and checking if the number of set bits is prime.

### Initial Thoughts 💭
- We can use a helper function to count the number of set bits in a number.
- We can precompute prime numbers up to 20 to efficiently check if a number of set bits is prime.
- The most efficient way to count the number of set bits is to use the __builtin_popcount function.
{{< dots >}}
### Edge Cases 🌐
- If the range is very small or has a width of 0, there may be no numbers to check.
- The solution should efficiently handle the maximum possible input size (up to 10^6).
- The number 1 should be handled correctly, as it is not prime.
- Ensure the solution works for the maximum constraint where left and right can be as large as 10^6.
{{< dots >}}
## Code 💻
```cpp
int countPrimeSetBits(int left, int right) {
    int prime[]={2, 3, 5, 7, 11, 13, 17, 19};
    vector<bool> isPrime(21, 0);
    for(int p: prime) isPrime[p]=1;
    int sum=0;
    for(int i=left; i<=right; i++){
        int b=__builtin_popcount(i);
        if (isPrime[b]) sum++;
    }
    return sum;
}
```

This code defines a function to count how many numbers between 'left' and 'right' have a prime number of set bits in their binary representation.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int countPrimeSetBits(int left, int right) {
	```
	This line defines the function 'countPrimeSetBits' which takes two integers 'left' and 'right' as input parameters and returns the count of numbers in the range [left, right] that have a prime number of set bits in their binary representation.

2. **Array Initialization**
	```cpp
	    int prime[]={2, 3, 5, 7, 11, 13, 17, 19};
	```
	This initializes an array 'prime' containing the first few prime numbers. These will be used to check if the count of set bits in a number is prime.

3. **Vector Initialization**
	```cpp
	    vector<bool> isPrime(21, 0);
	```
	This initializes a boolean vector 'isPrime' of size 21, all set to false. It will be used to track which numbers between 0 and 20 are prime.

4. **Prime Marking**
	```cpp
	    for(int p: prime) isPrime[p]=1;
	```
	This loop iterates over the 'prime' array and marks the corresponding positions in the 'isPrime' vector as true for prime numbers.

5. **Variable Initialization**
	```cpp
	    int sum=0;
	```
	This initializes a variable 'sum' to zero. This will keep track of how many numbers in the range have a prime number of set bits.

6. **Looping Over Range**
	```cpp
	    for(int i=left; i<=right; i++){
	```
	This loop iterates through all numbers between 'left' and 'right' inclusive.

7. **Set Bit Counting**
	```cpp
	        int b=__builtin_popcount(i);
	```
	This line calculates the number of set bits (1s) in the binary representation of 'i' using the '__builtin_popcount' function.

8. **Prime Check**
	```cpp
	        if (isPrime[b]) sum++;
	```
	This checks if the count of set bits 'b' is a prime number by referring to the 'isPrime' vector. If it is, 'sum' is incremented.

9. **Return Statement**
	```cpp
	    return sum;
	```
	This returns the final value of 'sum', which represents the count of numbers with a prime number of set bits in the range [left, right].

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) when left == right.
- **Average Case:** O(n) where n is the difference between right and left.
- **Worst Case:** O(n) where n is the difference between right and left, with additional checks for set bits.

The time complexity is mainly dependent on iterating over the range and checking the set bits for each number.

### Space Complexity 💾
- **Best Case:** O(1) for the space used.
- **Worst Case:** O(1) for the space used by the prime list and the set bit calculation.

The space complexity is minimal as we are only using a small list of primes and some basic variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/)

---
{{< youtube KeCWKJxsyxA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
