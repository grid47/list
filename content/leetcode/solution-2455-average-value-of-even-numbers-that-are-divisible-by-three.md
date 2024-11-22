
+++
authors = ["grid47"]
title = "Leetcode 2455: Average Value of Even Numbers That Are Divisible by Three"
date = "2024-03-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2455: Average Value of Even Numbers That Are Divisible by Three in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "FJVQfaZo4oA"
youtube_upload_date="2022-10-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/FJVQfaZo4oA/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int averageValue(vector<int>& nums) 
    {
     int Total_Sum=0;
        int Total_Number=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0 && nums[i]%3==0)
            {
                Total_Sum+=nums[i];
                Total_Number++;
            }
        }      
        if(Total_Sum==0) return 0;
        return Total_Sum/Total_Number;   
    }
};
{{< /highlight >}}
---

### Problem Statement:
In this problem, we are tasked with calculating the average of numbers in the given list `nums` that are divisible by both 2 and 3. If there are no numbers divisible by both 2 and 3, we are to return 0. The goal is to find the average of these numbers, rounding down to the nearest integer if necessary, or returning 0 if no such numbers exist.

### Approach:
The approach involves iterating over the array and filtering the numbers that are divisible by both 2 and 3. This is achieved by checking if each number is divisible by both 2 and 3, which is equivalent to checking if it is divisible by 6 (since 6 is the least common multiple of 2 and 3). The numbers that satisfy this condition are added to a sum, and a count of such numbers is maintained. After processing the array, the average is calculated by dividing the sum by the count of valid numbers. If no such numbers exist, the function returns 0.

### Code Breakdown (Step by Step):

Let’s break down the solution code into smaller parts to understand it clearly:

1. **Function Declaration**:
   ```cpp
   int averageValue(vector<int>& nums)
   ```
   This function `averageValue` takes one parameter:
   - `nums`: A vector of integers that represents the list of numbers from which we need to calculate the average of numbers divisible by both 2 and 3.
   
   The function returns an integer representing the average of the numbers that satisfy the divisibility condition. If no such numbers exist, the function returns 0.

2. **Variable Initialization**:
   ```cpp
   int Total_Sum = 0;
   int Total_Number = 0;
   ```
   Two integer variables are initialized:
   - `Total_Sum`: This will hold the sum of the numbers that are divisible by both 2 and 3.
   - `Total_Number`: This will keep track of how many numbers meet the divisibility condition.

3. **Loop Through the `nums` Array**:
   ```cpp
   for (int i = 0; i < nums.size(); i++)
   ```
   This loop iterates over each element in the `nums` vector using an index variable `i`. The loop will run from `i = 0` to `i < nums.size()`, which ensures that all elements of the vector are checked.

4. **Check Divisibility by Both 2 and 3**:
   ```cpp
   if (nums[i] % 2 == 0 && nums[i] % 3 == 0)
   ```
   Inside the loop, for each element `nums[i]`, we check if it is divisible by both 2 and 3:
   - `nums[i] % 2 == 0` checks if the number is divisible by 2.
   - `nums[i] % 3 == 0` checks if the number is divisible by 3.
   
   If both conditions are true, the number is divisible by 6, and we consider it for inclusion in the sum.

5. **Add to Total Sum and Increment Total Number**:
   ```cpp
   Total_Sum += nums[i];
   Total_Number++;
   ```
   If the current number satisfies the divisibility condition, it is added to `Total_Sum`, and `Total_Number` is incremented to reflect that we have found one more number that meets the condition.

6. **Check if There Are Any Valid Numbers**:
   ```cpp
   if (Total_Sum == 0) return 0;
   ```
   After the loop completes, if `Total_Sum` is still 0, this means no numbers in the array were divisible by both 2 and 3. In this case, the function returns 0, as no average can be computed.

7. **Return the Average**:
   ```cpp
   return Total_Sum / Total_Number;
   ```
   If there are valid numbers that meet the divisibility condition, we compute the average by dividing the total sum of such numbers by the count of those numbers. The result is returned as the final output of the function.

### Complexity:

1. **Time Complexity**:
   - The time complexity is determined by the single loop that iterates through the `nums` array.
   - The loop runs in \(O(N)\), where \(N\) is the number of elements in the `nums` vector.
   - Inside the loop, the operations are constant time checks (`%` operations and comparisons), so they do not affect the overall time complexity.
   
   Therefore, the time complexity of the solution is:
   \[
   O(N)
   \]
   where \(N\) is the number of elements in the input vector `nums`.

2. **Space Complexity**:
   - The space complexity is \(O(1)\), as the solution only uses a fixed amount of extra space (`Total_Sum` and `Total_Number`), regardless of the size of the input `nums`.
   
   Hence, the space complexity is:
   \[
   O(1)
   \]

### Conclusion:
The `averageValue` function is an efficient solution to the problem of calculating the average of numbers in an array that are divisible by both 2 and 3. The algorithm iterates over the array once, checking each number for divisibility by both 2 and 3, and computes the sum and count of such numbers. If no such numbers exist, it returns 0. Otherwise, it calculates and returns the average.

This solution has linear time complexity, \(O(N)\), where \(N\) is the number of elements in the input array. Since the space complexity is constant, \(O(1)\), it is memory-efficient as well. This makes the solution suitable for large inputs.

The solution is straightforward and leverages basic iteration and conditional checks to achieve the desired result. Its simplicity, combined with the efficiency of a linear time algorithm, ensures that it works well for typical input sizes.

[`Link to LeetCode Lab`](https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three/description/)

---
{{< youtube FJVQfaZo4oA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
