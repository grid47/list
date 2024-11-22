
+++
authors = ["grid47"]
title = "Leetcode 1015: Smallest Integer Divisible by K"
date = "2024-07-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1015: Smallest Integer Divisible by K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "kaEYJUNhQ3k"
youtube_upload_date="2020-11-25"
youtube_thumbnail="https://i.ytimg.com/vi/kaEYJUNhQ3k/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        for(int r = 0, N = 1; N <= k; N++)
        if((r = (r * 10 + 1)%k )== 0) return N;
        return -1;
    }
};
{{< /highlight >}}
---



### Problem Statement
A repunit is a number that consists only of the digit '1'. For example, the numbers 1, 11, 111, and 1111 are all repunits. The task is to find the smallest repunit number that is divisible by a given integer \( k \).

For instance, if \( k = 3 \), the smallest repunit number is 111, which equals 3 × 37. However, if \( k = 2 \), the result should be -1 because no repunit number can be even and divisible by 2.

The goal is to implement a function that takes \( k \) as input and returns the length of the smallest repunit number that is divisible by \( k \) or -1 if no such number exists within the constraints.

### Approach
To find the smallest repunit divisible by \( k \), we can use a straightforward simulation approach that leverages properties of modular arithmetic:
1. **Iterate Through Possible Lengths**: We'll generate repunit numbers of increasing length and check their divisibility by \( k \).
2. **Use Remainders**: Instead of constructing large numbers, we can keep track of the remainder when divided by \( k \) to avoid overflow and to optimize our checks.
3. **Stop When Divisible**: If at any point the remainder becomes zero, we return the current length of the repunit. If we reach \( k \) without finding a divisible repunit, we return -1.

### Code Breakdown (Step by Step)

1. **Function Declaration**:
   - The function `smallestRepunitDivByK` is defined as a public member of the `Solution` class, taking an integer \( k \) as input.

2. **Initializing Loop Variables**:
   - We initialize a loop that will iterate \( N \) from 1 to \( k \). The variable \( N \) will represent the number of ones in our repunit.
   - A variable \( r \) is initialized to zero. This variable will store the remainder when the current repunit (expressed as a number of ones) is divided by \( k \).

3. **Iterating Through Lengths**:
   - Within the loop, we update the remainder \( r \) using the formula: 
     \[
     r = (r \times 10 + 1) \mod k
     \]
     This formula essentially constructs the number of ones in modular form:
     - The multiplication by 10 shifts the number left (increasing its place value) and adding 1 appends another '1' to the end.
   - After updating \( r \), we check if it equals zero. If it does, we return the current value of \( N \) because this means we have found a repunit of length \( N \) that is divisible by \( k \).

4. **Returning -1**:
   - If the loop completes without finding a divisible repunit (i.e., we checked all lengths up to \( k \)), we return -1.

### Complexity Analysis
- **Time Complexity**: The time complexity of this function is \( O(k) \). We loop through values from 1 to \( k \), performing a constant amount of work in each iteration.
- **Space Complexity**: The space complexity is \( O(1) \) because we only use a fixed number of variables regardless of the input size.

### Conclusion
The `smallestRepunitDivByK` function provides an efficient method for finding the length of the smallest repunit that is divisible by a given integer \( k \). By leveraging modular arithmetic to track remainders, we avoid the need to handle potentially large numbers and instead focus on their properties.

This solution showcases the application of number theory and modular arithmetic in algorithm design, offering a clear path to solving problems involving divisibility. Understanding this approach not only aids in tackling similar problems but also enhances overall algorithmic thinking skills.

Furthermore, the simplicity and efficiency of this implementation make it ideal for competitive programming and technical interviews. The method is easy to grasp and can be adapted to solve related problems, such as finding patterns in numerical sequences or exploring properties of modular arithmetic.

In summary, the `smallestRepunitDivByK` function exemplifies how to effectively use mathematical properties to derive solutions in a computational context. It highlights the intersection of theory and practical application, reinforcing the value of mathematical insights in programming challenges.


[`Link to LeetCode Lab`](https://leetcode.com/problems/smallest-integer-divisible-by-k/description/)

---
{{< youtube kaEYJUNhQ3k >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
