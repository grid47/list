
+++
authors = ["grid47"]
title = "Leetcode 1480: Running Sum of 1d Array"
date = "2024-06-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1480: Running Sum of 1d Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "qNbwIHhMOr8"
youtube_upload_date="2020-06-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/qNbwIHhMOr8/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++)
            nums[i] += nums[i - 1];
        return nums;
    }
};
{{< /highlight >}}
---

### Problem Statement

The goal of this problem is to compute the **running sum** of a given list of integers. The running sum at each index `i` is defined as the sum of all the elements from the start of the list up to that index `i`. For example, given an array `nums = [1, 2, 3, 4]`, the running sum would be `[1, 3, 6, 10]`, where:
- The first element is just `1`.
- The second element is `1 + 2 = 3`.
- The third element is `1 + 2 + 3 = 6`.
- The fourth element is `1 + 2 + 3 + 4 = 10`.

The task is to create a function that takes an array of integers as input and returns a new array containing the running sums.

### Approach

To achieve the desired running sum, we can follow a straightforward approach:
1. **Iterate Through the Array**: Loop through the input array starting from the second element.
2. **Update the Current Element**: For each element, add the value of the previous element to it. This can be done in-place, meaning we will modify the original array directly.
3. **Return the Updated Array**: Once the loop is complete, we return the modified array which now represents the running sums.

This approach is efficient and leverages the properties of cumulative addition to achieve the result with minimal overhead.

### Code Breakdown (Step by Step)

Here is a detailed breakdown of the code:

```cpp
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++)
            nums[i] += nums[i - 1];
        return nums;
    }
};
```

1. **Class Definition**:
   ```cpp
   class Solution {
   public:
   ```
   - This begins the definition of the `Solution` class, which contains the method for computing the running sum.

2. **Method Declaration**:
   ```cpp
   vector<int> runningSum(vector<int>& nums) {
   ```
   - The method `runningSum` is declared, which takes a reference to a vector of integers `nums` as its parameter. The function will return a vector of integers.

3. **Iterating Through the Array**:
   ```cpp
   for(int i = 1; i < nums.size(); i++)
   ```
   - A `for` loop is initiated starting from index `1`. We begin at index `1` because the running sum for index `0` is simply the first element itself, which does not require modification.

4. **Updating the Current Element**:
   ```cpp
   nums[i] += nums[i - 1];
   ```
   - Inside the loop, the current element `nums[i]` is updated by adding the value of the previous element `nums[i - 1]` to it. This effectively calculates the running sum by accumulating the previous values.

5. **Returning the Result**:
   ```cpp
   return nums;
   ```
   - After the loop completes, the updated `nums` vector (which now contains the running sums) is returned.

### Complexity

- **Time Complexity**:
  - The time complexity of this algorithm is \(O(n)\), where \(n\) is the number of elements in the input array. This is because we perform a single pass through the array to compute the running sums.

- **Space Complexity**:
  - The space complexity is \(O(1)\) if we consider the modification of the input array in place. We do not use any additional data structures that grow with the size of the input, aside from the output which is returned as a reference to the modified input.

### Conclusion

The `runningSum` method effectively computes the running sum of an array in a time-efficient manner, utilizing a simple loop to achieve the result in linear time. This solution is optimal for the problem and illustrates the use of in-place updates to minimize space complexity.

Key takeaways from this implementation include:

1. **Simplicity and Efficiency**: The approach is both simple and efficient, making it easy to understand and implement. The logic is straightforward, which minimizes the likelihood of errors.

2. **In-Place Modification**: By modifying the input array directly, we save memory and avoid unnecessary allocations, adhering to best practices for space complexity.

3. **Real-World Applications**: The running sum is a common operation in various fields such as data analysis, finance, and statistics, where cumulative totals are frequently required. This implementation can be easily adapted for more complex operations involving cumulative sums.

In summary, this implementation provides a clear and efficient solution to the problem of calculating running sums in an array, making it a valuable addition to a programmer's toolkit.

[`Link to LeetCode Lab`](https://leetcode.com/problems/running-sum-of-1d-array/description/)

---
{{< youtube qNbwIHhMOr8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
