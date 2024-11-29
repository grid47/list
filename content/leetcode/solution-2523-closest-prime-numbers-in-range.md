
+++
authors = ["grid47"]
title = "Leetcode 2523: Closest Prime Numbers in Range"
date = "2024-02-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2523: Closest Prime Numbers in Range in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "HqSBI1RVM8c"
youtube_upload_date="2023-01-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/HqSBI1RVM8c/maxresdefault.webp"
comments = true
+++



---
Given two integers `left` and `right`, find the two prime numbers `num1` and `num2` such that: `left <= num1 < num2 <= right`, both are prime numbers, and the difference `num2 - num1` is the smallest among all valid pairs. If multiple pairs have the same smallest difference, return the pair with the smallest `num1`. If no such pair exists, return `[-1, -1]`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two integers `left` and `right`. Find the pair of prime numbers `num1` and `num2` where `left <= num1 < num2 <= right`.
- **Example:** `left = 15, right = 30`
- **Constraints:**
	- 1 <= left <= right <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the pair `[num1, num2]` where `num1` and `num2` are prime numbers and the difference `num2 - num1` is the smallest. If no such pair exists, return `[-1, -1]`.
- **Example:** `Output: [17, 19]`
- **Constraints:**
	- The output must be a list of two integers representing the prime numbers, or [-1, -1] if no such pair exists.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the pair of prime numbers `num1` and `num2` such that the difference between them is minimized, while satisfying the constraints.

- Generate all prime numbers up to the value of `right` using the Sieve of Eratosthenes.
- Find all prime numbers between `left` and `right`.
- Iterate through the primes to find the pair with the smallest difference.
{{< dots >}}
### Problem Assumptions ✅
- The input values `left` and `right` are within the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `left = 15, right = 30`  \
  **Explanation:** The prime numbers between 15 and 30 are [17, 19, 23, 29]. The smallest difference is 2, which occurs between 17 and 19.

- **Input:** `left = 50, right = 60`  \
  **Explanation:** The prime numbers between 50 and 60 are [53, 59], with a difference of 6.

- **Input:** `left = 8, right = 10`  \
  **Explanation:** There are no prime numbers between 8 and 10, so the output is `[-1, -1]`.

{{< dots >}}
## Approach 🚀
We can solve this problem by generating prime numbers up to `right` using the Sieve of Eratosthenes, then finding the pair of primes within the range `[left, right]` with the smallest difference.

### Initial Thoughts 💭
- We need to efficiently find prime numbers within a given range.
- The Sieve of Eratosthenes is a good approach to generate prime numbers efficiently up to `right`.
{{< dots >}}
### Edge Cases 🌐
- There are no cases with empty inputs since `left` and `right` are always positive integers.
- The algorithm should be efficient enough to handle inputs where `right` can be as large as 10^6.
- If there are no primes between `left` and `right`, return `[-1, -1]`.
- The solution must handle input ranges efficiently using the Sieve of Eratosthenes.
{{< dots >}}
## Code 💻
```cpp
bool seive[1000001] = {};
vector<int> p = {2};
vector<int> closestPrimes(int left, int right) {
    
    for(int i = 3; i < 1000001; i += 2) {
        if(!seive[i]) {
            p.push_back(i);
            for (long long j = (long long) i * i; j < 1000001; j += i) {
                seive[j] = true;
            }
        }
    }
    
    int n1 = -1, n2 = -1, i = lower_bound(p.begin(), p.end(), left) - p.begin();
    
    for(; i + 1 < p.size() && p[i + 1] <= right; i++) {
        if(n1 == -1 || n2 - n1 > p[i + 1] - p[i]) {
            n1 = p[i];
            n2 = p[i + 1];
            if(n2 - n1 < 3) break;
        }
    }
    return {n1, n2};
}
```

This code defines a function to find the closest prime numbers within a given range, using the Sieve of Eratosthenes to generate prime numbers up to a large limit. It returns the closest primes within the given range where the difference between them is at least 3.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	bool seive[1000001] = {};
	```
	This initializes a sieve array to mark non-prime numbers. The array size is 1000001, which is large enough for the range we're dealing with.

2. **Vector Initialization**
	```cpp
	vector<int> p = {2};
	```
	This initializes a vector 'p' with the first prime number (2) to start the prime search.

3. **Function Definition**
	```cpp
	vector<int> closestPrimes(int left, int right) {
	```
	This defines the function 'closestPrimes' which takes two integers, 'left' and 'right', representing the range in which to find the closest primes.

4. **Prime Sieve Loop**
	```cpp
	for(int i = 3; i < 1000001; i += 2) {
	```
	This loop iterates over odd numbers starting from 3 up to 1000001 to find primes. Even numbers (except 2) are skipped.

5. **Prime Check**
	```cpp
	if(!seive[i]) {
	```
	This checks if 'i' is a prime number by verifying if it has been marked as non-prime in the sieve.

6. **Prime Addition**
	```cpp
	p.push_back(i);
	```
	If 'i' is a prime, it is added to the vector 'p' of prime numbers.

7. **Sieve Update**
	```cpp
	for (long long j = (long long) i * i; j < 1000001; j += i) {
	```
	This inner loop marks all multiples of 'i' as non-prime in the sieve, starting from 'i*i' to optimize the sieve process.

8. **Mark Non-Primes**
	```cpp
	seive[j] = true;
	```
	This marks 'j' as a non-prime number in the sieve.

9. **Variable Initialization**
	```cpp
	int n1 = -1, n2 = -1, i = lower_bound(p.begin(), p.end(), left) - p.begin();
	```
	This initializes variables 'n1' and 'n2' to store the closest primes, and 'i' to find the first prime number greater than or equal to 'left' using binary search.

10. **Prime Pair Search**
	```cpp
	for(; i + 1 < p.size() && p[i + 1] <= right; i++) {
	```
	This loop iterates through the vector of primes, starting from the first prime greater than or equal to 'left', and checks if the next prime is within the range 'right'.

11. **Update Closest Primes**
	```cpp
	if(n1 == -1 || n2 - n1 > p[i + 1] - p[i]) {
	```
	This condition checks if the current pair of primes has a smaller difference than the previously found pair. If so, it updates 'n1' and 'n2'.

12. **Assign Closest Primes**
	```cpp
	n1 = p[i];
	```
	This assigns the current prime to 'n1'.

13. **Assign Closest Primes**
	```cpp
	n2 = p[i + 1];
	```
	This assigns the next prime to 'n2'.

14. **Early Termination**
	```cpp
	if(n2 - n1 < 3) break;
	```
	If the difference between 'n2' and 'n1' is less than 3, the loop breaks as no closer primes can be found.

15. **Return Result**
	```cpp
	return {n1, n2};
	```
	This returns a vector containing the two closest primes 'n1' and 'n2'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log log n)
- **Average Case:** O(n log log n)
- **Worst Case:** O(n log log n)

The time complexity is dominated by the Sieve of Eratosthenes, which runs in O(n log log n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

Space complexity is O(n) due to storing prime numbers up to `right`.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/closest-prime-numbers-in-range/description/)

---
{{< youtube HqSBI1RVM8c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
