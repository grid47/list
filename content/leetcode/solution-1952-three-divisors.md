
+++
authors = ["grid47"]
title = "Leetcode 1952: Three Divisors"
date = "2024-04-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1952: Three Divisors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Enumeration","Number Theory"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "Rl-JOgrVru0"
youtube_upload_date="2021-08-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Rl-JOgrVru0/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isThree(int n) {
    int d = 2;
    for (int i = 2; i < n && d <= 3; i += 1)
        d += n % i == 0;
    return d == 3;
}
};
{{< /highlight >}}
---

### Problem Statement

The problem is to determine if a given integer \( n \) has exactly three distinct positive divisors. A number with exactly three divisors can only be a square of a prime number. For example:
- The number \( 4 \) (which is \( 2^2 \)) has divisors \( 1, 2, 4 \).
- The number \( 9 \) (which is \( 3^2 \)) has divisors \( 1, 3, 9 \).

In contrast, numbers that are not perfect squares or squares of primes do not meet this criterion. 

### Approach

To solve the problem, we need to count the number of divisors of \( n \). The logic for determining the number of divisors involves iterating from \( 2 \) up to \( n-1 \) and checking how many numbers can divide \( n \) without a remainder. For each divisor found, we increase our count. At the end of the iteration, if the count of divisors equals three, we return true; otherwise, we return false.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the provided code:

```cpp
class Solution {
public:
```
The class `Solution` is defined, and the method `isThree` is declared as a public member function.

```cpp
    bool isThree(int n) {
```
The `isThree` function takes an integer \( n \) as input and returns a boolean indicating whether \( n \) has exactly three distinct positive divisors.

```cpp
    int d = 2;
```
We initialize a variable `d` to \( 2 \). This represents the count of divisors, starting with \( 1 \) (which is a divisor of all integers) and \( n \) itself. 

```cpp
    for (int i = 2; i < n && d <= 3; i += 1)
```
We use a `for` loop to iterate through potential divisors starting from \( 2 \) up to \( n-1 \). The loop will also terminate early if the count of divisors \( d \) exceeds \( 3 \).

```cpp
        d += n % i == 0;
```
Within the loop, we check if \( i \) is a divisor of \( n \) by evaluating the expression `n % i == 0`. If true, \( i \) divides \( n \) without a remainder, and we increment the divisor count \( d \) by \( 1 \).

```cpp
    return d == 3;
```
Finally, after exiting the loop, we return whether \( d \) equals \( 3 \). This indicates whether \( n \) has exactly three distinct positive divisors.

### Complexity

- **Time Complexity**: 
  - The time complexity of this solution is \( O(n) \) in the worst case because the algorithm checks all integers from \( 2 \) to \( n-1 \). However, since we terminate early if \( d \) exceeds \( 3 \), in practice, the number of iterations could be much smaller, especially for larger values of \( n \).

- **Space Complexity**: 
  - The space complexity is \( O(1) \) since we are using a constant amount of space for variables and do not utilize any additional data structures.

### Conclusion

The `isThree` function effectively determines if a given integer has exactly three distinct positive divisors. This is done by counting the divisors in a straightforward manner. While this brute-force approach is easy to understand and implement, it may not be the most efficient for very large values of \( n \).

### Key Features

1. **Direct Counting of Divisors**: The approach directly counts divisors by checking potential candidates from \( 2 \) to \( n-1 \).

2. **Early Termination**: The algorithm benefits from an early termination condition which can help reduce the number of iterations in practice.

3. **Simplicity**: The solution is simple and straightforward, making it easy to understand and modify if needed.

### Use Cases

This function can be useful in various mathematical applications, including:
- **Number Theory**: Determining properties of numbers, particularly when studying prime numbers and their powers.
- **Cryptography**: Some cryptographic algorithms may rely on properties of numbers and their factors.
- **Mathematical Puzzles**: This kind of function can be a part of larger problems in programming competitions or educational tools focused on mathematics.

### Implementation Considerations

When implementing this solution, consider the following:

- **Edge Cases**: Handle cases where \( n \) is less than \( 1 \) (e.g., negative numbers or zero), as they do not have positive divisors.

- **Optimization for Large Numbers**: For very large integers, a more sophisticated method for counting divisors might be necessary, such as using prime factorization or a sieve method to reduce the search space.

By understanding this approach, one can apply similar logic to other problems involving divisor counting and number properties.

[`Link to LeetCode Lab`](https://leetcode.com/problems/three-divisors/description/)

---
{{< youtube Rl-JOgrVru0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
