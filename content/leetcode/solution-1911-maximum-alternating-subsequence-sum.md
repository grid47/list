
+++
authors = ["grid47"]
title = "Leetcode 1911: Maximum Alternating Subsequence Sum"
date = "2024-04-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1911: Maximum Alternating Subsequence Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "4v42XOuU1XA"
youtube_upload_date="2021-06-26"
youtube_thumbnail="https://i.ytimg.com/vi/4v42XOuU1XA/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        long long odd = 0, even = 0;

        for(int num : nums) {
            even = max(even, odd + num);
            odd = even - num;
        }

        return even;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem involves finding the maximum alternating sum of a sequence of integers. An alternating sum is defined as the sum of a subsequence where the elements are added and subtracted in an alternating fashion. For example, given a sequence of numbers, we want to select a subsequence such that when we sum them by alternating between addition and subtraction, the result is maximized.

### Approach

To solve this problem efficiently, we can use dynamic programming. The key idea is to maintain two states during the iteration over the numbers: one for the maximum sum when the current number is added to the subsequence (even state) and one for when it is subtracted (odd state). By keeping track of these two states, we can build up our solution iteratively.

1. **Initialization**: We start with two variables: `odd` to keep track of the maximum sum when the last number in the subsequence was subtracted, and `even` for when the last number was added.

2. **Iterating through the numbers**: For each number in the input array, we update the `even` and `odd` values based on the maximum possible sums we can achieve with or without including the current number.

3. **Final Result**: After processing all numbers, the variable `even` will contain the maximum alternating sum.

### Code Breakdown (Step by Step)

Let's analyze the code to understand its implementation:

1. **Class Definition**: The solution is encapsulated in a class named `Solution`.

   ```cpp
   class Solution {
   public:
   ```

2. **Function Signature**: The method `maxAlternatingSum` takes a vector of integers `nums` and returns a long long integer representing the maximum alternating sum.

   ```cpp
       long long maxAlternatingSum(vector<int>& nums) {
   ```

3. **State Initialization**: We declare two variables, `odd` and `even`, both initialized to 0. These will hold the maximum alternating sums for odd and even indexed selections respectively.

   ```cpp
           long long odd = 0, even = 0;
   ```

4. **Iterating Through the Input**: We use a range-based for loop to iterate through each number in the `nums` vector.

   ```cpp
           for(int num : nums) {
   ```

5. **Updating the Even State**: We calculate the new value for `even`. This is the maximum of the current `even` and the sum of `odd + num`, where `odd` represents the maximum sum obtained before adding the current number. This represents adding the current number to the subsequence.

   ```cpp
               even = max(even, odd + num);
   ```

6. **Updating the Odd State**: The `odd` state is updated to reflect the maximum sum where the last number was subtracted. This is done by subtracting the current number from the new `even` state.

   ```cpp
               odd = even - num;
   ```

7. **Returning the Result**: After processing all numbers, we return the `even` variable which holds the maximum alternating sum.

   ```cpp
           return even;
       }
   ```

### Complexity

- **Time Complexity**: The time complexity of this solution is O(n), where n is the number of elements in the input vector `nums`. We perform a single pass through the vector.

- **Space Complexity**: The space complexity is O(1) because we are using a fixed number of variables to keep track of the state, regardless of the input size.

### Conclusion

The `maxAlternatingSum` function provides an efficient solution to the problem of finding the maximum alternating sum of a sequence of integers. By using a dynamic programming approach that tracks two states, we can determine the optimal subsequence sum in linear time. This method minimizes the use of additional space, making it suitable for large inputs.

### Use Cases

1. **Financial Applications**: This algorithm can be applied to scenarios where cash flows alternate between positive and negative values, such as in investment portfolios.

2. **Game Theory**: In games that involve alternating gains and losses, this approach can be utilized to strategize optimal moves.

3. **Resource Management**: When managing resources over time where there are alternating costs and revenues, this method can help optimize the total benefit.

4. **Signal Processing**: In fields where alternating signals are processed, such as audio or telecommunications, optimizing certain metrics can be achieved using this approach.

By implementing the alternating sum calculation in this manner, developers can efficiently handle and analyze sequences of integers, enhancing the performance and responsiveness of applications. The direct approach taken in this solution ensures both clarity and efficiency, making it applicable across a wide range of practical scenarios.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-alternating-subsequence-sum/description/)

---
{{< youtube 4v42XOuU1XA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
