
+++
authors = ["grid47"]
title = "Leetcode 2761: Prime Pairs With Target Sum"
date = "2024-02-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2761: Prime Pairs With Target Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Enumeration","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "rEM1dS0cKFc"
youtube_upload_date="2023-07-02"
youtube_thumbnail="https://i.ytimg.com/vi/rEM1dS0cKFc/maxresdefault.jpg"
comments = true
+++



---
You are given an integer 'n'. Your task is to find all pairs of prime numbers [x, y] such that 1 <= x <= y <= n, x + y = n, and both x and y are prime numbers. Return a 2D sorted list of such prime pairs. If no such pairs exist, return an empty array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer 'n'.
- **Example:** `n = 12`
- **Constraints:**
	- 1 <= n <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a 2D list of prime pairs [x, y], sorted by x. If no pairs exist, return an empty list.
- **Example:** `For n = 12, the output is [[5, 7]].`
- **Constraints:**
	- The pairs must be sorted in increasing order of x.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find all prime pairs such that their sum is equal to n.

- Generate all prime numbers up to n using the Sieve of Eratosthenes.
- Iterate through the list of primes and check for each pair (x, y) where x + y = n.
- Store all such valid pairs and return them sorted by x.
{{< dots >}}
### Problem Assumptions ✅
- The value of n is always a positive integer.
{{< dots >}}
## Examples 🧩
- **Input:** `For n = 12`  \
  **Explanation:** The prime numbers less than or equal to 12 are [2, 3, 5, 7, 11]. The valid prime pairs that sum up to 12 are [5, 7].

- **Input:** `For n = 30`  \
  **Explanation:** The prime numbers less than or equal to 30 are [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]. The valid prime pairs that sum up to 30 are [7, 23], [11, 19], and [13, 17].

{{< dots >}}
## Approach 🚀
The solution involves finding all prime numbers up to n and checking for prime pairs that sum up to n.

### Initial Thoughts 💭
- We need to identify all prime numbers up to n.
- The Sieve of Eratosthenes is an efficient algorithm to find primes up to a large number.
- Using the Sieve of Eratosthenes, we can generate a list of primes, and then check which pairs of primes sum to n.
{{< dots >}}
### Edge Cases 🌐
- If no prime pairs sum up to n, return an empty list.
- For large values of n (up to 10^6), the solution should efficiently handle the prime generation using the Sieve of Eratosthenes.
- For n = 2, there are no prime pairs that sum up to 2.
- Ensure that the solution works efficiently even for large values of n.
{{< dots >}}
## Code 💻
```cpp

vector<vector<int>> findPrimePairs(int n) {

    vector<int> net(n + 1, true);
    net[1] = false;
    for(int i = 2; i < n / 2 + 1; i++)
    for(int j = 2; j * i < n; j++)
        net[j * i] = false;

    map<int, int> mp;
    vector<vector<int>> res;

    for(int i = 1; i < n / 2 + 1; i++)
        if(net[i] && net[n - i]) 
        res.push_back({i, n - i});

    return res;
}
```

This function finds all prime pairs that sum up to a given number `n`. It uses the Sieve of Eratosthenes to identify prime numbers up to `n`, then checks for pairs of prime numbers that add up to `n`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<int>> findPrimePairs(int n) {
	```
	Defines the function `findPrimePairs` that takes an integer `n` and returns a vector of vector pairs of prime numbers that sum to `n`.

2. **Variable Initialization**
	```cpp
	    vector<int> net(n + 1, true);
	```
	Initializes a boolean vector `net` of size `n + 1`, where each element is initially set to `true`, representing the assumption that each number is prime.

3. **Marking Non-Primes**
	```cpp
	    net[1] = false;
	```
	Sets `net[1]` to `false` because 1 is not a prime number.

4. **Sieve of Eratosthenes Loop 1**
	```cpp
	    for(int i = 2; i < n / 2 + 1; i++)
	```
	Starts a loop from `i = 2` to `n / 2 + 1`, iterating through potential prime numbers.

5. **Sieve of Eratosthenes Loop 2**
	```cpp
	    for(int j = 2; j * i < n; j++)
	```
	Starts an inner loop for each multiple of `i`, marking these multiples as `false` (non-prime).

6. **Marking Multiples as Non-Primes**
	```cpp
	        net[j * i] = false;
	```
	Marks the multiples of `i` as `false` in the `net` vector, indicating they are not prime numbers.

7. **Map Initialization**
	```cpp
	    map<int, int> mp;
	```
	Declares a map `mp`, which is not used in this implementation but could be used for further optimization or storing prime counts.

8. **Result Vector Initialization**
	```cpp
	    vector<vector<int>> res;
	```
	Initializes an empty vector `res` to store pairs of primes that sum up to `n`.

9. **Prime Pair Search Loop**
	```cpp
	    for(int i = 1; i < n / 2 + 1; i++)
	```
	Starts a loop to iterate through numbers `i` from 1 to `n / 2`. This is to find pairs where `i` and `n - i` are both prime.

10. **Prime Pair Check**
	```cpp
	        if(net[i] && net[n - i]) 
	```
	Checks if both `i` and `n - i` are prime numbers by checking their corresponding values in the `net` array.

11. **Store Valid Prime Pair**
	```cpp
	        res.push_back({i, n - i});
	```
	If both `i` and `n - i` are prime, the pair is added to the result vector `res`.

12. **Return Result**
	```cpp
	    return res;
	```
	Returns the vector `res`, which contains all pairs of prime numbers that sum to `n`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log log n) for the Sieve of Eratosthenes.
- **Average Case:** O(n log log n).
- **Worst Case:** O(n log log n).

The time complexity is dominated by the Sieve of Eratosthenes, which runs in O(n log log n). Checking pairs takes O(n) time.

### Space Complexity 💾
- **Best Case:** O(n).
- **Worst Case:** O(n).

The space complexity is O(n) for storing the prime numbers and their sieve.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/prime-pairs-with-target-sum/description/)

---
{{< youtube rEM1dS0cKFc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
