
+++
authors = ["grid47"]
title = "Leetcode 3190: Find Minimum Operations to Make All Elements Divisible by Three"
date = "2023-12-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3190: Find Minimum Operations to Make All Elements Divisible by Three in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "b-UBMai1bGM"
youtube_upload_date="2024-06-22"
youtube_thumbnail="https://i.ytimg.com/vi_webp/b-UBMai1bGM/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++) ans+=min(3-(nums[i]%3),nums[i]%3);
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand involves finding the minimum number of operations needed to make each element in a given array divisible by 3. The operations allowed involve changing any number by adding or subtracting 1. Each number can be changed as many times as needed, and the goal is to achieve a state where every number in the array is divisible by 3.

### Approach

To solve this problem, we need to reduce each number to its closest multiple of 3 using the fewest possible operations. Since the numbers are divisible by 3, we need to look at how far each number is from the nearest multiple of 3.

- For any number `n`, when divided by 3, we get a remainder `r = n % 3`.
- Based on the value of the remainder, we determine the minimum number of operations required to make the number divisible by 3.
  - If `r == 0`, the number is already divisible by 3, and no operation is needed.
  - If `r == 1`, we can subtract 1 to make it divisible by 3 or add 2 to make it divisible by 3.
  - If `r == 2`, we can subtract 2 to make it divisible by 3 or add 1 to make it divisible by 3.

In both the cases where `r == 1` or `r == 2`, the minimum number of operations to make the number divisible by 3 is the minimum of adding or subtracting the required number.

Thus, the task reduces to iterating over each number in the array and summing the minimum operations required for each.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0; // Initialize a variable to keep track of the total operations needed
        for(int i = 0; i < nums.size(); i++) { // Loop through each element in the array
            // Calculate the minimum operations needed for each number
            ans += min(3 - (nums[i] % 3), nums[i] % 3); 
        }
        return ans; // Return the total number of operations
    }
};
```

#### Step-by-Step Breakdown of the Code:

1. **Function Definition**:
   The function `minimumOperations` takes a reference to a vector of integers `nums` as input and returns an integer, which is the minimum number of operations needed to make each element in the array divisible by 3.

2. **Initializing the Result Variable**:
   ```cpp
   int ans = 0;
   ```
   The variable `ans` is initialized to 0, and it will be used to accumulate the total number of operations required.

3. **Iterating Over the Array**:
   ```cpp
   for(int i = 0; i < nums.size(); i++)
   ```
   The loop iterates over each element of the input vector `nums`.

4. **Calculating Operations for Each Number**:
   ```cpp
   ans += min(3 - (nums[i] % 3), nums[i] % 3);
   ```
   Inside the loop, for each number `nums[i]`, we calculate the remainder when the number is divided by 3 (`nums[i] % 3`). Based on the remainder:
   - If the remainder is 1, the number can either be increased by 2 (to reach the next multiple of 3) or decreased by 1 (to reach the previous multiple of 3). The `min` function helps choose the optimal approach by selecting the smaller number of operations.
   - If the remainder is 2, the number can either be increased by 1 (to reach the next multiple of 3) or decreased by 2 (to reach the previous multiple of 3). Similarly, the `min` function selects the optimal number of operations.

   The result of the `min` operation is added to `ans` for each element in the array.

5. **Returning the Final Result**:
   ```cpp
   return ans;
   ```
   After iterating over all the elements, the function returns the total number of operations required to make all elements divisible by 3.

### Example Walkthrough

Let’s walk through an example to better understand how this algorithm works.

#### Input:
```cpp
vector<int> nums = {2, 5, 8};
```

- For the first element, `nums[0] = 2`:
  - The remainder when 2 is divided by 3 is `2 % 3 = 2`.
  - To make 2 divisible by 3, we can subtract 2 (making it 0) or add 1 (making it 3). The minimum number of operations is 1.
  
- For the second element, `nums[1] = 5`:
  - The remainder when 5 is divided by 3 is `5 % 3 = 2`.
  - To make 5 divisible by 3, we can subtract 2 (making it 3) or add 1 (making it 6). The minimum number of operations is 1.

- For the third element, `nums[2] = 8`:
  - The remainder when 8 is divided by 3 is `8 % 3 = 2`.
  - To make 8 divisible by 3, we can subtract 2 (making it 6) or add 1 (making it 9). The minimum number of operations is 1.

#### Calculation:
- The total number of operations is `1 + 1 + 1 = 3`.

#### Output:
```cpp
3
```

### Complexity Analysis

#### Time Complexity:
- The function iterates over each element of the array exactly once, performing constant-time operations for each element. 
- Therefore, the time complexity is **O(n)**, where `n` is the size of the input array.

#### Space Complexity:
- The space complexity is **O(1)** because we are using only a constant amount of extra space, regardless of the input size. The space used by the input array is not counted towards the space complexity.

### Conclusion

This solution efficiently computes the minimum number of operations required to make each element of the array divisible by 3 by leveraging the properties of the modulo operation. By iterating through the array once and using a simple formula to compute the number of operations, the solution runs in linear time and requires constant space. This makes the solution both time-efficient and space-efficient, suitable for large inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/description/)

---
{{< youtube b-UBMai1bGM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
