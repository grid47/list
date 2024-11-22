
+++
authors = ["grid47"]
title = "Leetcode 2513: Minimize the Maximum of Two Arrays"
date = "2024-02-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2513: Minimize the Maximum of Two Arrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Binary Search","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "g6L-jnW2n_4"
youtube_upload_date="2022-12-24"
youtube_thumbnail="https://i.ytimg.com/vi_webp/g6L-jnW2n_4/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    bool isPossible(long long mx, long long div1, long long div2, long long unq1, long long unq2) {
        long long a = mx / div1;
        long long a_ = mx - a;
        long long b = mx / div2;
        long long b_ = mx - b;
        long long aib = mx / (long long)lcm(div1, div2);
        long long aub = a + b - aib;
        long long a_ib_ = mx - aub;
        long long neededA = (a_ - a_ib_ >= unq1) ? 0: unq1 - (a_ - a_ib_);
        long long neededB = (b_ - a_ib_ >= unq2) ? 0: unq2 - (b_ - a_ib_);        
        
        return a_ib_ >= neededA + neededB;
    }
    
    int minimizeSet(int div1, int div2, int unq1, int unq2) {
        
        long long l = 1, r = (long long) pow(10, 17), ans = 1;
        
        
        while(l <= r) {
            long long mid = l + (r - l + 1) / 2;
            if(isPossible(mid, div1, div2, unq1, unq2)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to minimize a set such that the set contains a certain number of unique numbers divisible by two given integers, `div1` and `div2`. Specifically, we are given:
- `div1` and `div2`, two divisors.
- `unq1` and `unq2`, the number of unique integers divisible by `div1` and `div2`, respectively.

Our goal is to find the smallest integer `mx` such that:
- There are at least `unq1` integers in the range `[1, mx]` that are divisible by `div1`.
- There are at least `unq2` integers in the range `[1, mx]` that are divisible by `div2`.

Additionally, there might be some overlap between the two sets of numbers divisible by `div1` and `div2`. We aim to minimize the number `mx` while ensuring these conditions are met.

### Approach

We can solve this problem using **binary search** combined with **mathematical counting** techniques. Here's how:

1. **Basic Counting Strategy**:
   - For any given `mx`, the number of integers divisible by `div1` is `mx // div1`, where `//` represents integer division.
   - Similarly, the number of integers divisible by `div2` is `mx // div2`.
   - The number of integers divisible by both `div1` and `div2` can be counted using the Least Common Multiple (LCM) of `div1` and `div2`. The number of integers divisible by both `div1` and `div2` in the range `[1, mx]` is `mx // lcm(div1, div2)`.

2. **Handling the Overlap**:
   - If there is overlap (i.e., a number is divisible by both `div1` and `div2`), we need to adjust the counts to avoid double-counting. The total number of valid numbers for each divisor can be calculated as:
     - `a = mx // div1` (total numbers divisible by `div1`).
     - `b = mx // div2` (total numbers divisible by `div2`).
     - The overlap is `aib = mx // lcm(div1, div2)` (numbers divisible by both).
     - The combined set of numbers divisible by `div1` or `div2` is `a + b - aib`.

3. **Binary Search for Optimization**:
   - We use binary search to find the smallest `mx` that satisfies the constraints. For a given `mx`, we calculate how many unique numbers divisible by `div1` and `div2` can be included. If it's possible to satisfy the condition, we try smaller values of `mx` to minimize it.
   - The binary search range starts with `l = 1` and `r = 10^17` (a large upper bound). We check the midpoint (`mid = (l + r) // 2`) in each iteration to decide whether we need to look for smaller or larger values.

### Code Breakdown (Step by Step)

#### Step 1: Helper Function `isPossible`
```cpp
bool isPossible(long long mx, long long div1, long long div2, long long unq1, long long unq2) {
    long long a = mx / div1;  // Number of numbers divisible by div1
    long long a_ = mx - a;    // Numbers not divisible by div1
    long long b = mx / div2;  // Number of numbers divisible by div2
    long long b_ = mx - b;    // Numbers not divisible by div2
    long long aib = mx / lcm(div1, div2);  // Numbers divisible by both div1 and div2
    long long aub = a + b - aib;  // Total numbers divisible by div1 or div2
    long long a_ib_ = mx - aub;  // Numbers neither divisible by div1 nor div2

    // Calculate how many more numbers are needed for each set
    long long neededA = (a_ - a_ib_ >= unq1) ? 0 : unq1 - (a_ - a_ib_);
    long long neededB = (b_ - a_ib_ >= unq2) ? 0 : unq2 - (b_ - a_ib_);

    // Check if the total count of remaining numbers can accommodate the additional needed numbers
    return a_ib_ >= neededA + neededB;
}
```
- **Inputs**:
  - `mx`: The current midpoint value in the binary search.
  - `div1`, `div2`: The divisors.
  - `unq1`, `unq2`: The required counts of unique numbers divisible by `div1` and `div2`.
- **Process**:
  - First, we calculate how many numbers are divisible by `div1`, `div2`, and both using integer division.
  - We also calculate how many numbers are not divisible by either.
  - Then, we compute how many more numbers are needed to satisfy the unique count requirements for `div1` and `div2`.
- **Return**:
  - If there are enough numbers available to meet the requirements, the function returns `true`. Otherwise, it returns `false`.

#### Step 2: Main Function `minimizeSet`
```cpp
int minimizeSet(int div1, int div2, int unq1, int unq2) {
    long long l = 1, r = (long long) pow(10, 17), ans = 1;

    // Binary search to find the smallest value of mx that satisfies the condition
    while (l <= r) {
        long long mid = l + (r - l + 1) / 2;  // Calculate the midpoint
        if (isPossible(mid, div1, div2, unq1, unq2)) {  // Check if it's possible to satisfy the condition
            ans = mid;  // If possible, store the result and look for smaller values
            r = mid - 1;  // Move the upper bound to search for a smaller valid mx
        } else {
            l = mid + 1;  // Otherwise, increase the lower bound to find a valid mx
        }
    }

    return ans;  // Return the smallest valid mx
}
```
- **Inputs**:
  - `div1`, `div2`: The divisors.
  - `unq1`, `unq2`: The required number of unique integers divisible by `div1` and `div2`.
- **Process**:
  - Initialize the binary search range `l = 1` and `r = 10^17`.
  - For each midpoint `mid` in the binary search, use the `isPossible` function to check if it's possible to satisfy the requirements.
  - If it is possible, move the upper bound (`r`) to search for smaller values of `mx`. Otherwise, move the lower bound (`l`) to search for larger values.
- **Return**:
  - The smallest `mx` that satisfies the condition.

### Example Walkthrough

Let’s go through an example to understand how the binary search works:

#### Example Input:
```cpp
int div1 = 2, div2 = 3, unq1 = 5, unq2 = 3;
```

#### Binary Search Process:
1. Start with `l = 1` and `r = 10^17`.
2. For each `mid`, check if it’s possible to meet the required numbers of unique integers divisible by `div1` and `div2`.
3. If `mid` is valid, reduce the range by adjusting the upper bound (`r`).
4. If `mid` is invalid, increase the range by adjusting the lower bound (`l`).
5. Continue until the smallest valid `mx` is found.

### Complexity Analysis

#### Time Complexity:
- **Binary Search**: The binary search operates over a range of size \(10^{17}\), so the number of iterations is \(O(\log(10^{17})) = O(58)\).
- **`isPossible` Function**: Each time the `isPossible` function is called, it involves simple arithmetic and a call to `lcm`, which is \(O(\log(\min(div1, div2)))\). Since `lcm` is computed using the greatest common divisor (GCD), this operation is very efficient.
- **Total Time Complexity**: The total time complexity is \(O(\log(10^{17}) \cdot \log(\min(div1, div2)))\), which is highly efficient.

#### Space Complexity:
- The space complexity is \(O(1)\) because we only use a few variables to store intermediate results.

### Conclusion

This solution efficiently finds the smallest number `mx` that satisfies the required conditions using binary search and mathematical counting techniques. By leveraging the properties of divisibility and overlap using the `lcm` function, the solution optimizes the search space, ensuring it runs in logarithmic time. This approach is both time-efficient and space-efficient for large inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/description/)

---
{{< youtube g6L-jnW2n_4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
