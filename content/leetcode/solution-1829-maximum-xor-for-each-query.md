
+++
authors = ["grid47"]
title = "Leetcode 1829: Maximum XOR for Each Query"
date = "2024-05-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1829: Maximum XOR for Each Query in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "AIGDFYa4aWM"
youtube_upload_date="2021-04-17"
youtube_thumbnail="https://i.ytimg.com/vi/AIGDFYa4aWM/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int bit) {
        int ui = 0;
        for(int x : nums)
            ui ^= x;
        int msk = (1 << bit) - 1;
        
        
        

        
        int res = ui ^ msk;
        vector<int> ans;
        ans.push_back(res);
        while(nums.size() > 1) {
            
            res ^= nums.back();
            nums.pop_back();
            ans.push_back(res);
            
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to compute the maximum XOR value of the cumulative XOR of a list of integers, progressively removing one integer at a time from the end of the list. The results need to be computed based on a given number of bits, `bit`, which defines the maximum number of bits used for representing numbers in the XOR operation.

### Approach

To solve this problem, we can break it down into the following steps:

1. **Understanding XOR Properties**: 
   - The XOR operation has some unique properties that can be leveraged. Notably, XORing a number with itself results in zero, and XORing a number with zero yields the number itself. 
   - Given this, we can derive the maximum possible XOR for any number by using the bitmask of size defined by `bit`. For example, for `bit = 3`, the maximum number that can be represented is `111` in binary, which is `7` in decimal. 

2. **Calculate the Initial XOR**: 
   - First, we calculate the cumulative XOR of all numbers in the input array `nums`. This value (`ui`) will be the basis for computing the results.
  
3. **Generate Bitmask**: 
   - Create a bitmask that consists of `bit` number of bits set to `1`. This is done by shifting `1` left by `bit` positions and subtracting `1` from it (i.e., `msk = (1 << bit) - 1`).

4. **Compute Maximum XOR Value**: 
   - The maximum XOR value we can achieve with the given numbers is obtained by XORing `ui` with the `msk`.

5. **Iteratively Update Results**:
   - Store the computed maximum XOR value in a results vector and iteratively remove numbers from the end of the array. After each removal, update the cumulative XOR value and compute the new maximum XOR value. Append this value to the results vector.

6. **Return Results**: 
   - Finally, return the results vector containing the maximum XOR values for all stages of removal.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int bit) {
```
- We define a class `Solution` that contains the method `getMaximumXor`, which takes a vector of integers `nums` and an integer `bit` as input.

```cpp
        int ui = 0;
        for(int x : nums)
            ui ^= x; // Compute the cumulative XOR of all numbers
```
- We initialize a variable `ui` to zero and compute the cumulative XOR of all elements in `nums`. This is achieved using a range-based for loop that iterates over each integer `x` in `nums` and applies the XOR operation.

```cpp
        int msk = (1 << bit) - 1; // Create the bitmask
```
- We calculate the bitmask `msk` by left-shifting `1` by `bit` positions and subtracting `1`. This effectively creates a binary number with `bit` bits set to `1`.

```cpp
        int res = ui ^ msk; // Calculate the maximum XOR value initially
        vector<int> ans; // Initialize the result vector
        ans.push_back(res); // Store the initial result
```
- We calculate the initial maximum XOR value `res` by XORing `ui` with `msk`. We then create an empty vector `ans` to store the results and push the initial maximum XOR value into it.

```cpp
        while(nums.size() > 1) { // Iteratively remove numbers from the end
            res ^= nums.back(); // Update the result by XORing the last element
            nums.pop_back(); // Remove the last element from nums
            ans.push_back(res); // Store the updated result
        }
```
- We use a while loop to continue as long as there are more than one elements in `nums`. In each iteration, we XOR the last element of `nums` with `res`, remove the last element, and store the updated `res` in the results vector `ans`.

```cpp
        return ans; // Return the final results vector
    }
};
```
- Finally, the method returns the `ans` vector containing the maximum XOR values computed at each stage.

### Complexity

- **Time Complexity**: The time complexity of the solution is \(O(n)\), where \(n\) is the number of elements in the input vector `nums`. This is because we iterate through the vector twice: once for calculating the cumulative XOR and once for iteratively updating results.

- **Space Complexity**: The space complexity is \(O(n)\) as well, due to the additional space required to store the results vector `ans`, which can potentially store up to \(n\) elements.

### Conclusion

The provided solution efficiently computes the maximum XOR values by utilizing properties of the XOR operation and bit manipulation. It systematically removes elements from the input array while maintaining the cumulative XOR, allowing for an efficient computation of results. This approach is particularly effective for scenarios where we need to compute properties related to binary representations and their interactions, making it suitable for a variety of problems in competitive programming and algorithm design.

The final output vector `ans` provides a comprehensive view of the maximum XOR values achievable at each stage of element removal, thereby encapsulating the solution's core functionality.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-xor-for-each-query/description/)

---
{{< youtube AIGDFYa4aWM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
