
+++
authors = ["grid47"]
title = "Leetcode 1137: N-th Tribonacci Number"
date = "2024-07-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1137: N-th Tribonacci Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Memoization"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "3lpNp5Ojvrw"
youtube_upload_date="2023-01-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/3lpNp5Ojvrw/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;
        
        int n0 = 0, n1 = 1, n2 = 1, tmp;
        
        for(int i = 3; i < n + 1; i++) {
            tmp = n2 + n1 + n0;
            n0  = n1;
            n1  = n2;
            n2  = tmp;
        }
        
        return n2;
    }
};
{{< /highlight >}}
---


### Problem Statement
The Tribonacci sequence is a generalization of the Fibonacci sequence where each number is the sum of the three preceding ones, starting from 0, 1, and 1. The sequence can be defined as follows:

- \( T(0) = 0 \)
- \( T(1) = 1 \)
- \( T(2) = 1 \)
- \( T(n) = T(n-1) + T(n-2) + T(n-3) \) for \( n \geq 3 \)

The task is to compute the n-th Tribonacci number efficiently given a non-negative integer \( n \).

### Approach
To compute the n-th Tribonacci number, we can use an iterative approach. This method avoids the exponential time complexity of a naive recursive solution by using a loop to calculate each Tribonacci number from the previous three. The space complexity is kept constant by using only a few variables to store intermediate results, making it efficient for larger values of \( n \).

### Code Breakdown (Step by Step)
Here's a breakdown of the code, examining it piece by piece to understand its functionality:

```cpp
class Solution {
public:
    int tribonacci(int n) {
```
- **Line 1-2**: A class named `Solution` is defined, and a public member function `tribonacci` is declared, which takes an integer \( n \) as an argument. This function is responsible for calculating the n-th Tribonacci number.

```cpp
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;
```
- **Line 3-5**: These lines handle the base cases:
  - If \( n \) is 0, return 0 since \( T(0) = 0 \).
  - If \( n \) is 1 or 2, return 1 as both \( T(1) \) and \( T(2) \) are equal to 1.

```cpp
        int n0 = 0, n1 = 1, n2 = 1, tmp;
```
- **Line 6**: Here, we initialize three variables to represent the last three Tribonacci numbers:
  - `n0` is initialized to \( T(0) \), which is 0.
  - `n1` is initialized to \( T(1) \), which is 1.
  - `n2` is initialized to \( T(2) \), which is also 1.
  - A temporary variable `tmp` is declared to hold the sum of the three previous numbers during iteration.

```cpp
        for(int i = 3; i < n + 1; i++) {
```
- **Line 7**: This for loop starts at \( i = 3 \) and runs until \( i \) is less than or equal to \( n \). This loop will compute Tribonacci numbers from \( T(3) \) up to \( T(n) \).

```cpp
            tmp = n2 + n1 + n0;
```
- **Line 8**: Inside the loop, `tmp` is assigned the sum of `n2`, `n1`, and `n0`, which calculates the next Tribonacci number \( T(i) \).

```cpp
            n0  = n1;
            n1  = n2;
            n2  = tmp;
```
- **Lines 9-11**: Update the three variables to shift them:
  - `n0` is updated to the value of `n1`, which becomes the second last number.
  - `n1` is updated to the value of `n2`, which becomes the last number.
  - `n2` is updated to `tmp`, which now holds the newly computed Tribonacci number.

```cpp
        }
```
- **Line 12**: This closes the for loop, indicating that the computation for all Tribonacci numbers up to \( n \) has been completed.

```cpp
        return n2;
```
- **Line 13**: The function returns `n2`, which holds the value of \( T(n) \) after the loop ends.

```cpp
    }
};
```
- **Line 14-15**: This closes the function and the class definition.

### Complexity
- **Time Complexity**: The time complexity of this algorithm is \( O(n) \), as we iterate through the numbers from 3 to \( n \) exactly once.
- **Space Complexity**: The space complexity is \( O(1) \), as we are using a fixed amount of space for variables, regardless of the size of \( n \).

### Conclusion
The provided C++ solution efficiently computes the n-th Tribonacci number using an iterative approach. By leveraging the properties of the Tribonacci sequence and maintaining a constant space footprint, the algorithm ensures optimal performance even for larger values of \( n \). This approach is superior to naive recursive methods that may suffer from exponential time complexity and stack overflow issues. The implementation is clean, concise, and clearly conveys the logic necessary to compute the desired result.


[`Link to LeetCode Lab`](https://leetcode.com/problems/n-th-tribonacci-number/description/)

---
{{< youtube 3lpNp5Ojvrw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
