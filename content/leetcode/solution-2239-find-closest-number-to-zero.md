
+++
authors = ["grid47"]
title = "Leetcode 2239: Find Closest Number to Zero"
date = "2024-03-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2239: Find Closest Number to Zero in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "dLlKA5DQKYs"
youtube_upload_date="2024-07-03"
youtube_thumbnail="https://i.ytimg.com/vi/dLlKA5DQKYs/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
  int findClosestNumber(vector<int>& nums) {
    return *min_element(begin(nums), end(nums), [](int a, int b) {
        return abs(a) < abs(b) || (abs(a) == abs(b) && a > b);
    });
  }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires finding the number in a given array `nums` that is closest to zero. If there are multiple numbers with the same absolute value, the larger number should be selected. The task is to write a function that returns this closest number.

### Approach

The approach to solving this problem involves the following steps:

1. **Absolute Value Comparison**: 
   - We need to find the number whose absolute value is the smallest. If two numbers have the same absolute value, we need to choose the larger number.
   
2. **Using `min_element`**:
   - The `std::min_element` function can be used to find the minimum element in a collection, but in this case, we need to define a custom comparison function to account for the absolute value of the elements and handle the tie-breaking condition (when two numbers have the same absolute value).
   
3. **Custom Comparison Logic**:
   - The custom comparison function will compare the absolute values of two numbers, `a` and `b`. If the absolute value of `a` is smaller than that of `b`, `a` will be considered "less". If the absolute values are equal, we compare the numbers themselves to choose the larger one.

4. **Edge Cases**:
   - The input can include both positive and negative numbers. If the input array contains numbers like `-5` and `5`, the algorithm will return `5` because it is the larger number with the same absolute value.
   
5. **Final Result**:
   - After applying the custom comparison function, the `min_element` will return an iterator to the closest number (with tie-breaking logic handled), and we can dereference it to get the final result.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
  int findClosestNumber(vector<int>& nums) {
    return *min_element(begin(nums), end(nums), [](int a, int b) {
        return abs(a) < abs(b) || (abs(a) == abs(b) && a > b);
    });
  }
};
```

#### 1. **Function Declaration**:
```cpp
int findClosestNumber(vector<int>& nums) {
```
- We declare a public function `findClosestNumber` inside the `Solution` class. The function takes a reference to a vector of integers (`vector<int>& nums`) as its argument.
- The return type of the function is `int`, as we need to return the closest number from the array.

#### 2. **Using `min_element`**:
```cpp
return *min_element(begin(nums), end(nums), [](int a, int b) {
```
- The function uses `min_element`, which is part of the C++ Standard Library. `min_element` finds the smallest element in a range of values, specified by iterators.
- `begin(nums)` and `end(nums)` are used to define the range of the array `nums`. This will search for the smallest element in the entire array.
- A **lambda function** is passed as the third argument to `min_element`. The lambda function defines the custom comparison logic used to find the closest number.

#### 3. **Lambda Function**:
```cpp
return abs(a) < abs(b) || (abs(a) == abs(b) && a > b);
```
- The lambda function takes two integers, `a` and `b`, as its parameters.
- **First condition (`abs(a) < abs(b)`)**: The function compares the absolute values of `a` and `b`. If the absolute value of `a` is smaller than that of `b`, then `a` is considered smaller and will be selected.
- **Second condition (`abs(a) == abs(b) && a > b`)**: If the absolute values of `a` and `b` are equal, the function compares `a` and `b` directly. If `a` is greater than `b`, `a` will be selected. This ensures that if two numbers have the same absolute value, the larger one is chosen.

#### 4. **Dereferencing the Result**:
```cpp
});
```
- The lambda function ends here, and `min_element` returns an iterator to the element that meets the condition. The dereference operator (`*`) is used to get the value of the element pointed to by the iterator.
- This value is then returned as the result of the function.

### Complexity

#### Time Complexity:
- **O(n)**: The time complexity of this solution is linear, i.e., O(n), where `n` is the number of elements in the input vector `nums`.
- This is because the `min_element` function iterates over all the elements of the array to find the minimum value, and the comparison function (which involves checking the absolute value and then comparing the numbers) takes constant time for each pair of elements.

#### Space Complexity:
- **O(1)**: The space complexity is constant, i.e., O(1), as we do not use any additional data structures whose size grows with the input. We only use a few variables to store the comparison results, but the space used does not depend on the size of the input.

### Conclusion

This solution efficiently solves the problem of finding the closest number to zero in a given array, with tie-breaking logic to return the larger number when two elements have the same absolute value. By using the `min_element` function with a custom comparison lambda, the solution is both concise and clear.

The time complexity of **O(n)** ensures that the solution will perform efficiently even for large input arrays, and the constant space complexity **O(1)** makes the solution optimal in terms of memory usage.

This approach is a great example of how to leverage the power of lambda functions and standard library algorithms in C++ to solve problems in a clean and efficient manner. The ability to define custom comparison logic with lambda expressions is a powerful feature of C++ and allows for flexible and reusable code.

In summary, this solution is optimal for finding the closest number to zero in an array, handling edge cases (such as negative and positive numbers with the same absolute value) and ensuring that the code is efficient both in terms of time and space.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-closest-number-to-zero/description/)

---
{{< youtube dLlKA5DQKYs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
