
+++
authors = ["grid47"]
title = "Leetcode 396: Rotate Function"
date = "2024-09-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 396: Rotate Function in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/396.webp"
youtube = "GzBK8dxblaw"
youtube_upload_date="2024-03-21"
youtube_thumbnail="https://i.ytimg.com/vi/GzBK8dxblaw/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/396.webp" 
    alt="A glowing array where elements rotate, with each rotation step softly highlighted."
    caption="Solution to LeetCode 396: Rotate Function Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long sum = 0, fn = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            fn += i * nums[i];
        }

        long l = 1, r;
        long newfn = fn;

        while(l < n) {
            r = l + n - 1;
            long removed = (l - 1) *nums[l -1];
            long added = r * nums[r % n];

            newfn = newfn - removed + added - sum;

            fn = max(fn, newfn);
            l++;
        }
        return fn;
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

In this problem, you are tasked with calculating the maximum possible value of a rotated function `F(k)` for a given array of integers `nums`. The function `F(k)` is defined as:

\[
F(k) = \sum_{i=0}^{n-1} (nums[i] \times (i + k) \mod n)
\]

Where `n` is the length of the array, and `k` represents the number of rotations. Your goal is to find the maximum value of `F(k)` across all possible values of `k` from `0` to `n-1`.

#### Example:
- Given the array `[4, 3, 2, 6]`, the function `F(k)` calculates the sum of products of elements and their indices after rotating the array `k` times. The objective is to find the maximum value of `F(k)` for all rotations.

---

### 🧠 Approach

This problem involves efficiently computing the maximum value of `F(k)` without recalculating the function from scratch for each rotation. Instead, we use a clever technique where we build upon the previous function value (`F(k)`) to find the next one by adjusting for the rotations.

#### Key Idea:
- Instead of recalculating `F(k)` from scratch for every `k`, we can derive `F(k+1)` from `F(k)` by adjusting for the rotated elements. This allows us to optimize the calculation and avoid redundant computations.

---

### 🔨 Step-by-Step Code Breakdown

Let’s break down the code and logic to make it easier to understand:

#### Step 1: Initialize `sum` and `fn`
```cpp
long sum = 0, fn = 0;
int n = nums.size();
for(int i = 0; i < n; i++) {
    sum += nums[i];
    fn += i * nums[i];
}
```
- **sum** is the sum of all elements in the `nums` array.
- **fn** is the value of the function `F(0)`, which represents the function when no rotations have occurred. It is calculated as:
  
  \[
  F(0) = \sum_{i=0}^{n-1} (i \times nums[i])
  \]

#### Step 2: Set up variables for rotation
```cpp
long l = 1, r;
long newfn = fn;
```
- **l** is the current rotation index, starting at 1 (since `F(0)` is already computed).
- **r** will represent the last index in the rotated array after each rotation.
- **newfn** stores the current value of the function as we iterate through the rotations.

#### Step 3: Perform rotations and update `F(k)`
```cpp
while(l < n) {
    r = l + n - 1;
    long removed = (l - 1) * nums[l - 1];
    long added = r * nums[r % n];

    newfn = newfn - removed + added - sum;

    fn = max(fn, newfn);
    l++;
}
```
- The `while` loop iterates through each rotation, updating the function value for each step:
  1. **Calculate `r`**: The last index after `l` rotations is `l + n - 1`.
  2. **Calculate `removed`**: The contribution of the element at index `l-1` is removed from the function value.
  3. **Calculate `added`**: The contribution of the new element at index `r` is added to the function value.
  4. **Update `newfn`**: The value of `newfn` is updated by subtracting `removed` and adding `added`, while adjusting for the constant `sum`.
  5. **Update `fn`**: We store the maximum value of `fn` between the current and new `newfn`.
  6. **Increment `l`**: Move to the next rotation.

#### Step 4: Return the result
```cpp
return fn;
```
- Once all rotations are processed, the function returns the maximum value of `F(k)`.

---

### 📊 Example Walkthrough

Let’s walk through an example to see how the algorithm works:

**Example:**
```cpp
maxRotateFunction([4, 3, 2, 6]);
```

1. **Initial Values:**
   - `sum = 4 + 3 + 2 + 6 = 15`
   - `fn = 0 * 4 + 1 * 3 + 2 * 2 + 3 * 6 = 0 + 3 + 4 + 18 = 25`
   
2. **First rotation (`k=1`):**
   - `l = 1, r = 4`
   - `removed = 0 * 4 = 0`
   - `added = 4 * 6 = 24`
   - `newfn = 25 - 0 + 24 - 15 = 34`
   - `fn = max(25, 34) = 34`

3. **Second rotation (`k=2`):**
   - `l = 2, r = 5`
   - `removed = 1 * 3 = 3`
   - `added = 5 * 4 = 20`
   - `newfn = 34 - 3 + 20 - 15 = 36`
   - `fn = max(34, 36) = 36`

4. **Third rotation (`k=3`):**
   - `l = 3, r = 6`
   - `removed = 2 * 2 = 4`
   - `added = 6 * 3 = 18`
   - `newfn = 36 - 4 + 18 - 15 = 35`
   - `fn = max(36, 35) = 36`

- **Final result:** `36`.

---

### 📈 Complexity Analysis

- **Time Complexity**: `O(n)` where `n` is the length of the array. We only iterate over the array once to compute the initial values and then perform `n-1` rotations, each requiring constant time operations.
  
- **Space Complexity**: `O(1)`. We use a constant amount of space, as the solution does not require any additional data structures that scale with the input size.

---

### 🏁 Conclusion

This solution efficiently calculates the maximum possible value of `F(k)` for an array of integers using a rotation-based approach. Instead of recalculating the function from scratch for each rotation, we incrementally adjust the value based on the previous rotation. With a linear time complexity of `O(n)` and constant space complexity of `O(1)`, this algorithm is both time and space efficient.

💡 **Takeaway:** This problem showcases the power of leveraging previous computations and building upon them, rather than recalculating everything from scratch. It’s a great example of optimizing performance while keeping things simple and clear.

[`Link to LeetCode Lab`](https://leetcode.com/problems/rotate-function/description/)

---
{{< youtube GzBK8dxblaw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
