
+++
authors = ["grid47"]
title = "Leetcode 1201: Ugly Number III"
date = "2024-07-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1201: Ugly Number III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Binary Search","Combinatorics","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int nthUglyNumber(int k, int A, int B, int C) {
        int lo = 1, hi = 2* (int)1e9;
        long a = long(A), b = long(B), c = long(C);
        long ab = a * b / __gcd(a, b);
        long bc = b * c / __gcd(b, c);
        long ac = a * c / __gcd(a, c);
        long abc = a * bc / __gcd(a, bc);
        while (lo < hi ) {
            int mid = lo + (hi - lo)/2;
            int cnt = mid / a + mid / b + mid / c - mid / ab - mid / bc - mid / ac + mid / abc;
            
            if (cnt < k) {
                lo = mid + 1;
            } else hi = mid;
        }
        return lo;
    }
};
{{< /highlight >}}
---



### Problem Statement
The problem requires us to find the k-th "ugly number," where an ugly number is defined as a positive integer whose prime factors only include the integers `A`, `B`, and `C`. The task can be challenging, especially given the potential size of `k` and the values of `A`, `B`, and `C`. The challenge is to implement an efficient solution to compute this k-th ugly number without generating all possible ugly numbers up to that point.

### Approach
To find the k-th ugly number, the algorithm employs a binary search strategy combined with the principle of inclusion-exclusion. This method is efficient because it allows us to count how many ugly numbers exist less than or equal to a certain threshold efficiently. Here are the steps involved:

1. **Binary Search Setup**: We define a search space for the k-th ugly number starting from `1` to `2 * 10^9`. This is the maximum limit because the k-th ugly number cannot exceed this value for reasonable inputs.

2. **Counting Ugly Numbers**: For a mid-point in our search, we calculate how many ugly numbers are less than or equal to `mid`. This is done using the inclusion-exclusion principle:
   - Count the multiples of `A`, `B`, and `C`.
   - Subtract the counts of the least common multiples (LCMs) of pairs to avoid double counting.
   - Add the count of the LCM of all three to adjust for over-subtraction.

3. **Binary Search Execution**: The search continues by adjusting the low and high bounds based on whether the count of ugly numbers at the mid-point is less than or greater than `k`.

4. **Return Result**: When the bounds converge, the low index will point to the k-th ugly number.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int nthUglyNumber(int k, int A, int B, int C) {
        int lo = 1, hi = 2 * (int)1e9;
```
- **Lines 1-3**: The `nthUglyNumber` function is defined with parameters for `k`, `A`, `B`, and `C`. The search space is initialized with `lo` set to `1` and `hi` set to `2 * 10^9`, which is a safe upper limit for the k-th ugly number.

```cpp
        long a = long(A), b = long(B), c = long(C);
```
- **Line 4**: The values of `A`, `B`, and `C` are cast to `long` to avoid potential overflow when calculating LCMs.

```cpp
        long ab = a * b / __gcd(a, b);
        long bc = b * c / __gcd(b, c);
        long ac = a * c / __gcd(a, c);
        long abc = a * bc / __gcd(a, bc);
```
- **Lines 5-8**: Here, the LCMs of the combinations of `A`, `B`, and `C` are calculated using the relationship between LCM and GCD:
  - `lcm(x, y) = (x * y) / gcd(x, y)`
  - `ab`, `bc`, `ac`, and `abc` represent the LCM of pairs and the triplet.

```cpp
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
```
- **Lines 9-10**: A while loop begins to perform the binary search. The `mid` point is calculated to avoid overflow using `lo + (hi - lo) / 2`.

```cpp
            int cnt = mid / a + mid / b + mid / c 
                      - mid / ab - mid / bc - mid / ac 
                      + mid / abc;
```
- **Lines 11-12**: The count of ugly numbers less than or equal to `mid` is calculated using the inclusion-exclusion principle. This counts multiples of `A`, `B`, and `C`, subtracts the overlapping counts from pairs, and adds back the count for the triplet.

```cpp
            if (cnt < k) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
```
- **Lines 13-16**: The count is compared with `k`. If the count of ugly numbers is less than `k`, we adjust the lower bound to `mid + 1`. Otherwise, we set the upper bound to `mid`.

```cpp
        }
        return lo;
    }
};
```
- **Lines 17-19**: The loop continues until the bounds converge. Finally, the function returns `lo`, which points to the k-th ugly number.

### Complexity
1. **Time Complexity**:
   - The time complexity of this algorithm is \(O(\log(\text{hi}))\), where `hi` is \(2 \times 10^9\). This is due to the binary search, which reduces the search space logarithmically. Each check involves calculating the count of ugly numbers, which is done in constant time \(O(1)\).

2. **Space Complexity**:
   - The space complexity is \(O(1)\) because we use a constant amount of space for variables, regardless of the input size.

### Conclusion
The `nthUglyNumber` function efficiently finds the k-th ugly number using a binary search approach combined with the inclusion-exclusion principle. This implementation is optimal for the given problem constraints and handles the potentially large size of `k` and values of `A`, `B`, and `C` with ease. By leveraging mathematical properties of numbers, the function avoids the need for generating large sequences, making it suitable for competitive programming and real-world applications where performance is crucial. This solution highlights the importance of understanding number theory in algorithm design and optimization.

[`Link to LeetCode Lab`](https://leetcode.com/problems/ugly-number-iii/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
