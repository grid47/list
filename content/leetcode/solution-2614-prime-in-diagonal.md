
+++
authors = ["grid47"]
title = "Leetcode 2614: Prime In Diagonal"
date = "2024-02-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2614: Prime In Diagonal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Matrix","Number Theory"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "PEKRvVTWf4g"
youtube_upload_date="2023-04-09"
youtube_thumbnail="https://i.ytimg.com/vi_webp/PEKRvVTWf4g/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
  // seive
  bool isPrime(int n){
      if (n <= 2 || n % 2 == 0) 
          return n == 2;
      for (int i = 3; i * i <= n; i += 2)
          if (n % i == 0)
              return false;
      return true;
  }      
  int diagonalPrime(vector<vector<int>>& n) {
      int p = 0;
      for (int i = 0; i < n.size(); ++i)
          p = max({p, isPrime(n[i][i]) * n[i][i], 
              isPrime(n[i][n.size() - i - 1]) * n[i][n.size() - i - 1]});
      return p;
  }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks you to find the largest prime number from the diagonals of a square matrix `n`. The matrix is of size `n x n`, where each element is an integer. Specifically, you need to examine the two diagonals:
1. The **main diagonal** where the elements have the same row and column index, i.e., `n[i][i]`.
2. The **anti-diagonal** where the elements have row index `i` and column index `n-i-1`.

Your goal is to find the largest prime number from these two diagonals. If no prime number exists on either diagonal, return `0`.

### Approach

To solve this problem efficiently, we can break it down into the following steps:

1. **Prime Check Function (isPrime)**: 
   We need a utility function to check if a number is prime. A prime number is a number greater than 1 that has no divisors other than 1 and itself. For efficient checking, we can use trial division up to the square root of the number, as any factor larger than the square root would have a corresponding factor smaller than the square root.

2. **Iterate Through Diagonals**: 
   Once we have the prime check function, we can iterate through both diagonals (main diagonal and anti-diagonal) of the matrix and apply the prime check on each element.

3. **Track the Largest Prime**:
   As we iterate over the diagonals, we compare the prime numbers and track the largest prime number encountered. If no prime number is found, we return `0`.

### Code Breakdown (Step by Step)

#### Step 1: Prime Check Function (`isPrime`)

```cpp
bool isPrime(int n){
    if (n <= 2 || n % 2 == 0) 
        return n == 2;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}
```

- **Explanation**:
  - The `isPrime` function checks whether a given number `n` is prime.
  - **Base Case**: First, the function checks if `n` is less than or equal to 2 or is even. If `n` is 2, the function returns `true` since 2 is the only even prime number.
  - For numbers greater than 2, we check if the number is divisible by any integer from `3` to `sqrt(n)`. We only check odd numbers (hence `i += 2`), as even numbers greater than 2 cannot be prime.
  - If `n` is divisible by any number in this range, it is not prime, and we return `false`. If no divisors are found, the number is prime, and we return `true`.

#### Step 2: Diagonal Traversal

```cpp
int diagonalPrime(vector<vector<int>>& n) {
    int p = 0;
    for (int i = 0; i < n.size(); ++i)
        p = max({p, isPrime(n[i][i]) * n[i][i], 
            isPrime(n[i][n.size() - i - 1]) * n[i][n.size() - i - 1]});
    return p;
}
```

- **Explanation**:
  - The function `diagonalPrime` is where the main logic resides.
  - We initialize a variable `p` to track the largest prime number found. Initially, `p` is set to `0`.
  - We loop over the matrix `n` using a single loop, where `i` represents the current row and column index.
  - For each iteration, we check both diagonals:
    - **Main Diagonal**: The element at position `[i][i]`.
    - **Anti-Diagonal**: The element at position `[i][n.size() - i - 1]`, where `n.size() - i - 1` calculates the corresponding column index for the anti-diagonal.
  - For each of these elements, we check if they are prime using the `isPrime` function. If they are prime, we multiply the prime number by `1` (since `isPrime` returns `true` or `false`, which can be treated as `1` or `0` respectively).
  - We then compare the current prime number with the current maximum prime `p`. If it is larger, we update `p`.
  - After looping through all rows, we return the value of `p`, which holds the largest prime number found on the diagonals. If no prime was found, `p` will remain `0`.

#### Step 3: Return the Result

- After iterating through the entire matrix and checking both diagonals, the function will return the largest prime found. If no prime numbers are found on the diagonals, the function will return `0`.

### Complexity Analysis

#### Time Complexity:

1. **Prime Check (`isPrime`)**: 
   - For each element on the diagonals, we perform a primality test, which runs in \(O(\sqrt{n})\) time, where `n` is the value of the element being checked.
   
2. **Loop Over Diagonal Elements**:
   - We loop over the diagonals of the matrix, which has a size of \(n\). Therefore, we perform the primality check for `2n` elements in total (both diagonals).

3. **Overall Time Complexity**:
   - The time complexity is \(O(n \cdot \sqrt{m})\), where `n` is the size of the matrix (number of rows or columns), and `m` is the maximum value in the matrix, as we perform a primality test for each diagonal element.

#### Space Complexity:

1. **Input Matrix**: 
   - The space complexity for the input matrix `n` is \(O(n^2)\), where `n` is the size of the matrix (number of rows and columns).

2. **Auxiliary Space**:
   - We use a constant amount of extra space for the prime check (`isPrime`) and the `p` variable to track the largest prime. This does not require additional space beyond \(O(1)\).

3. **Overall Space Complexity**:
   - The space complexity is \(O(n^2)\) for storing the input matrix.

### Conclusion

This solution efficiently solves the problem by:
1. Iterating over both diagonals of the matrix.
2. Using an optimized primality test to check if the elements on the diagonals are prime.
3. Keeping track of the largest prime number found during the iteration.
4. Returning the largest prime number, or `0` if no prime is found.

With a time complexity of \(O(n \cdot \sqrt{m})\) and space complexity of \(O(n^2)\), the solution is efficient for most input sizes. The use of the `isPrime` function allows for a quick check of prime status, while the loop through the diagonals ensures we evaluate all relevant elements in the matrix.

[`Link to LeetCode Lab`](https://leetcode.com/problems/prime-in-diagonal/description/)

---
{{< youtube PEKRvVTWf4g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
