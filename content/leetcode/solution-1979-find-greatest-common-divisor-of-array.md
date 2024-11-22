
+++
authors = ["grid47"]
title = "Leetcode 1979: Find Greatest Common Divisor of Array"
date = "2024-04-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1979: Find Greatest Common Divisor of Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Number Theory"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "sJ5pTyUWOZ0"
youtube_upload_date="2021-08-22"
youtube_thumbnail="https://i.ytimg.com/vi/sJ5pTyUWOZ0/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
    public:
        int gcd(int a, int b) {
            if (b == 0) return a;
            return gcd(b, a % b);
        }
        int findGCD(vector<int> &nums) {
            int min = 1001;
            int max = 0;
            // Find the min and max from array
            for (int e : nums) {
                if (e < min) min = e;
                if (e > max) max = e;
            }
            return gcd(min, max);
        }
};
{{< /highlight >}}
---

### Problem Statement

The goal of this problem is to find the greatest common divisor (GCD) of the minimum and maximum values from an array of integers. Given a vector of integers, the task is to determine the smallest and largest numbers in the vector and compute their GCD. This problem is essential in various mathematical and computational contexts where understanding the relationships between numbers is crucial.

### Approach

To tackle the problem, we can break it down into the following steps:

1. **Find Minimum and Maximum**: We will iterate through the array to identify the minimum and maximum values.
2. **Calculate GCD**: Once we have both values, we will utilize the Euclidean algorithm to compute their GCD.
3. **Return the Result**: The final output will be the GCD calculated in the previous step.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
```
This line defines a class `Solution`, which contains the methods needed to solve the problem.

```cpp
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
```
Here, we define a recursive function `gcd` that implements the Euclidean algorithm to compute the GCD of two integers `a` and `b`. The function works as follows:
- If `b` is zero, the GCD is `a` (base case).
- Otherwise, it recursively calls itself with `b` and the remainder of `a` divided by `b`.

```cpp
    int findGCD(vector<int> &nums) {
```
This function, `findGCD`, takes a reference to a vector of integers as its parameter.

```cpp
        int min = 1001;
        int max = 0;
```
We initialize two variables, `min` and `max`, to keep track of the smallest and largest numbers in the array. We set `min` to 1001 (assuming the numbers in the array will not exceed this) and `max` to 0.

```cpp
        // Find the min and max from array
        for (int e : nums) {
            if (e < min) min = e;
            if (e > max) max = e;
        }
```
In this loop, we iterate through each element `e` in the `nums` vector. We check if `e` is smaller than `min` or greater than `max` and update these variables accordingly. This allows us to determine the minimum and maximum values in a single pass through the array.

```cpp
        return gcd(min, max);
    }
};
```
Finally, we call the `gcd` function with `min` and `max` as arguments and return the result. This gives us the GCD of the smallest and largest numbers in the array.

### Complexity

- **Time Complexity**: The time complexity of this solution is \(O(n)\) for finding the minimum and maximum values in the array, where \(n\) is the number of elements in the input vector `nums`. The time complexity of the `gcd` function, which uses the Euclidean algorithm, is \(O(\log(\min(a, b)))\) where `a` is the minimum value and `b` is the maximum value. Overall, the dominant factor is the linear scan through the array, making the total time complexity \(O(n + \log(\min(a, b)))\).

- **Space Complexity**: The space complexity is \(O(1)\) since we are only using a constant amount of extra space for the `min` and `max` variables and do not utilize any additional data structures that scale with the input size.

### Conclusion

This solution efficiently calculates the GCD of the minimum and maximum values in an array of integers. By utilizing the Euclidean algorithm for GCD calculation and a single pass to find the minimum and maximum values, we achieve optimal performance. This problem demonstrates important concepts in number theory and algorithm design, particularly the efficiency of the Euclidean algorithm for computing GCD.

### Example Usage

Here’s how you can use the `findGCD` function within the `Solution` class:

```cpp
#include <vector>
#include <iostream>
using namespace std;

int main() {
    Solution sol;
    vector<int> nums = {2, 4, 6, 8, 10};
    int result = sol.findGCD(nums);
    cout << "The GCD of the minimum and maximum values is: " << result << endl; // Output: The GCD of the minimum and maximum values is: 2
    return 0;
}
```

### Potential Improvements and Variations

1. **Input Validation**: We can enhance the function to handle edge cases, such as empty arrays or arrays with one element.
   
2. **Iterative GCD**: Instead of using recursion, we could implement the GCD function iteratively to avoid potential stack overflow issues with large inputs.

3. **Handling Negative Numbers**: Depending on the problem constraints, we could modify the logic to handle negative numbers appropriately, since the GCD is traditionally defined for non-negative integers.

By following these principles, the solution maintains clarity and efficiency, making it suitable for a variety of applications where the relationships between numbers are analyzed.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/)

---
{{< youtube sJ5pTyUWOZ0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
