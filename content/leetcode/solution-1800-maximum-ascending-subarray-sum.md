
+++
authors = ["grid47"]
title = "Leetcode 1800: Maximum Ascending Subarray Sum"
date = "2024-05-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1800: Maximum Ascending Subarray Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "uiCLUTepEJA"
youtube_upload_date="2021-03-21"
youtube_thumbnail="https://i.ytimg.com/vi/uiCLUTepEJA/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0];
        int maxi = sum;
        if(nums.size() == 1) return nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] <= nums[i-1]){
                sum = 0;
            }
                sum += nums[i];
                maxi = max(sum,maxi);
        }
            return maxi;
        }
    
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand requires us to find the maximum sum of an ascending subarray within a given array of integers. An ascending subarray is defined as a contiguous sequence of numbers where each subsequent number is strictly greater than the previous one. The task is to iterate through the array and calculate sums of all ascending subarrays, returning the maximum sum encountered during this process.

### Approach

The solution utilizes a simple linear traversal of the input array to keep track of the current sum of an ascending subarray and the maximum sum found so far. The key steps in the approach are as follows:

1. **Initialize Variables**: Start by initializing variables to store the current sum of the ascending subarray (`sum`) and the maximum sum found (`maxi`). 

2. **Iterate Through the Array**: Loop through each element in the array starting from the second element.

3. **Check for Ascending Order**: During each iteration, compare the current element with the previous one:
   - If the current element is greater than the previous one, it is part of the ascending subarray, so add it to the current sum.
   - If the current element is not greater, reset the current sum to start a new ascending subarray.

4. **Update the Maximum**: After updating the current sum, check if it is greater than the maximum sum found so far and update accordingly.

5. **Return the Result**: After iterating through the entire array, return the maximum sum.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the provided code:

```cpp
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
```
- The class `Solution` is defined with a public method `maxAscendingSum` that takes a vector of integers `nums` as input.

```cpp
        int sum = nums[0];
        int maxi = sum;
        if(nums.size() == 1) return nums[0];
```
- Two variables, `sum` and `maxi`, are initialized to the first element of the array. This initializes the current sum to the first number and sets the maximum sum to that value.
- A check is performed to see if the array has only one element. If it does, the function returns that single element as the maximum sum, since that is the only ascending subarray possible.

```cpp
        for(int i = 1; i < nums.size(); i++) {
```
- A `for` loop is initiated, starting from the second element (index 1) and iterating through the rest of the array.

```cpp
            if(nums[i] <= nums[i-1]){
                sum = 0;
            }
```
- Inside the loop, an `if` statement checks if the current element is less than or equal to the previous element. If this condition is true, it means the ascending order has been broken, so the current sum is reset to 0. 

```cpp
                sum += nums[i];
                maxi = max(sum, maxi);
```
- The current element is added to the current sum regardless of whether the order was broken or not.
- The maximum sum (`maxi`) is updated by comparing the current sum with the previously recorded maximum sum.

```cpp
        }
        return maxi;
    }
};
```
- The loop continues until all elements have been processed.
- After the loop concludes, the function returns the maximum sum found among all ascending subarrays.

### Complexity

- **Time Complexity**: The time complexity of this solution is \(O(n)\), where \(n\) is the number of elements in the input array. This is due to the single pass through the array to calculate the sums.

- **Space Complexity**: The space complexity is \(O(1)\), as only a constant amount of additional space is used for variables (`sum`, `maxi`).

### Conclusion

The provided code efficiently calculates the maximum sum of ascending subarrays using a straightforward linear traversal approach. The algorithm is optimized for both time and space, making it suitable for large input sizes. This solution illustrates the effectiveness of a greedy algorithm approach combined with careful condition checking.

By focusing on the properties of ascending sequences, the code is able to elegantly and efficiently determine the maximum ascending sum. The clear and concise structure of the code allows for easy understanding and maintenance, reinforcing good coding practices.

In competitive programming and coding interviews, this type of problem helps hone skills in array manipulation, condition checking, and maintaining state across iterations. Understanding and implementing such algorithms is crucial for developers, particularly in scenarios involving performance optimization and algorithm design.

In summary, the approach taken in this code exemplifies the principles of effective problem-solving in programming, showcasing how a clear understanding of the problem can lead to an elegant solution.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-ascending-subarray-sum/description/)

---
{{< youtube uiCLUTepEJA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
