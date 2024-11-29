
+++
authors = ["grid47"]
title = "Leetcode 2680: Maximum OR"
date = "2024-02-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2680: Maximum OR in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Bit Manipulation","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "XiaXIrEHFEY"
youtube_upload_date="2023-05-13"
youtube_thumbnail="https://i.ytimg.com/vi/XiaXIrEHFEY/maxresdefault.jpg"
comments = true
+++



---
You are given a 0-indexed integer array `nums` of length `n` and an integer `k`. In each operation, you can pick an element from the array and multiply it by 2. Your goal is to determine the maximum possible value of the bitwise OR of all elements in the array after applying the operation at most `k` times.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a list of integers `nums` and an integer `k` which represents the maximum number of operations allowed.
- **Example:** `Input: nums = [5, 3, 7], k = 1`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^9
	- 1 <= k <= 15

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum possible value of the bitwise OR after applying the operation at most `k` times.
- **Example:** `Output: 15`
- **Constraints:**
	- The result should be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to maximize the bitwise OR of the array after modifying elements using the operation as optimally as possible.

- Step 1: Iterate over each element of the array.
- Step 2: For each element, calculate the result of multiplying it by 2 for up to `k` times and calculate the resulting bitwise OR.
- Step 3: Track the maximum bitwise OR across all possible operations.
{{< dots >}}
### Problem Assumptions ✅
- All input values are within the specified constraints.
- The solution should efficiently handle the maximum possible size of the array.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [5, 3, 7], k = 1`  \
  **Explanation:** In the first operation, if we multiply 3 by 2, the new array becomes [5, 6, 7]. The bitwise OR of 5, 6, and 7 is 7. Thus, the final result is 7.

- **Input:** `Input: nums = [8, 1, 2], k = 2`  \
  **Explanation:** If we multiply 8 by 2 twice, we get [32, 1, 2]. The bitwise OR of 32, 1, and 2 is 35. Thus, the final result is 35.

{{< dots >}}
## Approach 🚀
The solution involves using a greedy approach to maximize the OR by considering the impact of multiplying elements by 2 up to `k` times and calculating the OR for each possible modification.

### Initial Thoughts 💭
- We want to maximize the OR, which means we need to focus on the higher values in the array and determine if multiplying them will result in a higher OR.
- It might be useful to calculate the OR for each possible operation and compare the results.
{{< dots >}}
### Edge Cases 🌐
- The array will always contain at least one element, so there are no empty arrays.
- The solution must be optimized to handle arrays with up to 10^5 elements efficiently.
- If all elements are the same, multiplying any of them will still yield the same OR, and the OR should be calculated based on that.
- Ensure that the solution is efficient for large values of `nums[i]` and handles arrays up to the size limit.
{{< dots >}}
## Code 💻
```cpp
long long maximumOr(vector<int>& nums, int k) 
{
    //prefix or
    //suffix or
    vector<long long>prefixor;
    for(int i = 0 ; i < nums.size() ; i++)
    {
        if(i == 0) prefixor.push_back((1LL * nums[i]));
        else prefixor.push_back(((1LL*prefixor.back()) | (1LL*nums[i])));
    }    

    vector<long long>suffixor;
    for(int i = nums.size() - 1; i >= 0; i--)
    {
        if(i == (nums.size()-1))  suffixor.push_back((1LL * nums[i]));
        else suffixor.push_back(((1LL*suffixor.back()) | (1LL*nums[i])));
    }
    reverse(suffixor.begin(),suffixor.end());

    long long ans = 0;
    for(int i = 0 ; i < nums.size() ; i++)
    { 
        long long int left = 0;
        long long int self;
        long long int right = 0;
        if((i-1) >= 0)
        {
            left = prefixor[i-1];
        }
        self = (nums[i] * pow(2,k));
        if((i+1) <= nums.size()-1)
        {
            right = suffixor[i+1];
        }
        ans = max(ans , left | self | right);
    }
    return ans;
}
```

The function 'maximumOr' takes a vector of integers 'nums' and an integer 'k'. It calculates the maximum bitwise OR of a modified element of the array after considering each element, its neighbors, and the effect of the number being shifted left by k bits. It uses prefix and suffix OR arrays to optimize the calculation of the OR operation across the array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long maximumOr(vector<int>& nums, int k) 
	```
	The function 'maximumOr' is defined to take a vector of integers 'nums' and an integer 'k'. It calculates the maximum value of the bitwise OR operation across modified elements of the array.

2. **Prefix OR Vector Initialization**
	```cpp
	    vector<long long>prefixor;
	```
	A vector 'prefixor' is initialized to store the cumulative OR values from the start of the array.

3. **Prefix OR Calculation Loop**
	```cpp
	    for(int i = 0 ; i < nums.size() ; i++)
	```
	A loop iterates through the 'nums' array to calculate the prefix OR values.

4. **First Prefix OR Value**
	```cpp
	        if(i == 0) prefixor.push_back((1LL * nums[i]));
	```
	For the first element, we initialize the prefix OR with the value of the first element.

5. **Subsequent Prefix OR Values**
	```cpp
	        else prefixor.push_back(((1LL*prefixor.back()) | (1LL*nums[i])));
	```
	For subsequent elements, the prefix OR is calculated by performing a bitwise OR with the previous prefix OR value.

6. **Suffix OR Vector Initialization**
	```cpp
	    vector<long long>suffixor;
	```
	A vector 'suffixor' is initialized to store the cumulative OR values from the end of the array.

7. **Suffix OR Calculation Loop**
	```cpp
	    for(int i = nums.size() - 1; i >= 0; i--)
	```
	A loop iterates through 'nums' in reverse to calculate the suffix OR values.

8. **First Suffix OR Value**
	```cpp
	        if(i == (nums.size()-1))  suffixor.push_back((1LL * nums[i]));
	```
	For the last element, we initialize the suffix OR with the value of the last element.

9. **Subsequent Suffix OR Values**
	```cpp
	        else suffixor.push_back(((1LL*suffixor.back()) | (1LL*nums[i])));
	```
	For subsequent elements, the suffix OR is calculated by performing a bitwise OR with the next suffix OR value.

10. **Reverse Suffix OR**
	```cpp
	    reverse(suffixor.begin(),suffixor.end());
	```
	The suffix OR vector is reversed so that it represents cumulative OR values from the start of the array.

11. **Result Initialization**
	```cpp
	    long long ans = 0;
	```
	The variable 'ans' is initialized to 0, which will store the maximum OR value found.

12. **Main Calculation Loop**
	```cpp
	    for(int i = 0 ; i < nums.size() ; i++)
	```
	A loop is initiated to calculate the OR values for each element and its neighbors.

13. **Left Value Calculation**
	```cpp
	        long long int left = 0;
	```
	The variable 'left' stores the prefix OR value of the element's left neighbor.

14. **Self Value Calculation**
	```cpp
	        long long int self;
	```
	The variable 'self' stores the OR value of the current element shifted by k bits.

15. **Right Value Calculation**
	```cpp
	        long long int right = 0;
	```
	The variable 'right' stores the suffix OR value of the element's right neighbor.

16. **Left Value Assignment**
	```cpp
	        if((i-1) >= 0)
	```
	Check if there is a left neighbor (i.e., i > 0).

17. **Left Assignment**
	```cpp
	            left = prefixor[i-1];
	```
	Assign the prefix OR value of the left neighbor.

18. **Self Calculation**
	```cpp
	        self = (nums[i] * pow(2,k));
	```
	Calculate the self value by shifting the current element by k bits.

19. **Right Value Assignment**
	```cpp
	        if((i+1) <= nums.size()-1)
	```
	Check if there is a right neighbor (i.e., i < nums.size() - 1).

20. **Right Assignment**
	```cpp
	            right = suffixor[i+1];
	```
	Assign the suffix OR value of the right neighbor.

21. **Maximum OR Update**
	```cpp
	        ans = max(ans , left | self | right);
	```
	Update the 'ans' variable with the maximum OR value found.

22. **Return Result**
	```cpp
	    return ans;
	```
	Return the maximum OR value calculated.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n * k)
- **Worst Case:** O(n * k)

We iterate through the array and perform operations on each element. The worst-case time complexity occurs when we apply up to `k` operations for each element, resulting in O(n * k).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We use additional space to store the prefix and suffix ORs, which requires O(n) space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-or/description/)

---
{{< youtube XiaXIrEHFEY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
