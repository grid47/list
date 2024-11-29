
+++
authors = ["grid47"]
title = "Leetcode 2653: Sliding Subarray Beauty"
date = "2024-02-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2653: Sliding Subarray Beauty in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ovFs2xad0_Y"
youtube_upload_date="2023-04-23"
youtube_thumbnail="https://i.ytimg.com/vi_webp/ovFs2xad0_Y/maxresdefault.webp"
comments = true
+++



---
Given an integer array 'nums' containing 'n' integers, you are tasked with calculating the beauty of each subarray of size 'k'. The beauty of a subarray is defined as the xth smallest negative integer in the subarray if it exists, or 0 if there are fewer than 'x' negative integers.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array 'nums', followed by two integers 'k' and 'x'. The array 'nums' contains 'n' integers, and 'k' is the size of each subarray. The integer 'x' is the rank of the smallest negative integer to find in each subarray.
- **Example:** `Input: nums = [5,-2,-3,-4,2], k = 3, x = 2`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= k <= n
	- 1 <= x <= k
	- -50 <= nums[i] <= 50

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer array of size 'n - k + 1', where each element represents the beauty of the subarray starting at each index from 0 to n-k.
- **Example:** `Output: [-2, -3, -4]`
- **Constraints:**
	- The output should be an array of integers, each representing the beauty of the subarrays.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to efficiently find the xth smallest negative integer in each subarray of size 'k' for the given 'nums' array.

- Step 1: Initialize a frequency array to count the occurrences of numbers in the subarray.
- Step 2: For each subarray, count the negative integers and track the xth smallest negative integer.
- Step 3: Use a sliding window technique to update the subarray as you move from left to right.
- Step 4: Return the beauty values for each subarray.
{{< dots >}}
### Problem Assumptions ✅
- The input array 'nums' is valid and contains integers within the given range.
- The input values for 'k' and 'x' are always valid and within the specified bounds.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [5,-2,-3,-4,2], k = 3, x = 2`  \
  **Explanation:** For the subarray [5, -2, -3], the 2nd smallest negative number is -2. For [-2, -3, -4], the 2nd smallest negative number is -3. For [-3, -4, 2], the 2nd smallest negative number is -4. Thus, the output is [-2, -3, -4].

- **Input:** `Input: nums = [-3, 2, 4, -5, -6], k = 2, x = 1`  \
  **Explanation:** For the subarray [-3, 2], the 1st smallest negative number is -3. For [2, 4], there are no negative numbers, so the beauty is 0. For [4, -5], the 1st smallest negative number is -5. For [-5, -6], the 1st smallest negative number is -5. Thus, the output is [-3, 0, -5, -5].

{{< dots >}}
## Approach 🚀
We will use a sliding window technique to efficiently compute the beauty of each subarray. We maintain a frequency count of numbers within each window to track the negative integers, which allows us to efficiently find the xth smallest negative integer.

### Initial Thoughts 💭
- We need to extract and count negative integers for each subarray efficiently.
- Sliding window techniques will help optimize the solution by reusing computations for overlapping parts of subarrays.
- We will use a frequency array to keep track of how many times each integer occurs within the current window. This allows us to efficiently determine the xth smallest negative integer.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs because the array 'nums' is always valid with at least one element.
- When n is at its largest value (100,000), ensure that the solution can handle the input size efficiently within time limits.
- When there are no negative numbers in the subarray, the beauty should be 0.
- When there are fewer than 'x' negative numbers in a subarray, the beauty should be 0.
- Make sure the solution scales well with large values of 'n'.
{{< dots >}}
## Code 💻
```cpp

vector<int> cnt;

int no(int x) {
    int sum = 0;
    for(int i = 0; i <= 50; i++) {
        sum += cnt[i];
        if(sum >= x)
            return i - 50;
    }
    return 0;
}

vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
    
    cnt.resize(101, 0);
    
    vector<int> ans;
    
    int n = nums.size();
    for(int i = 0; i < k; i++) {
        cnt[nums[i] + 50]++;            
    }
    ans.push_back(no(x));

    for(int i = k; i < n; i++) {
        cnt[nums[i] + 50]++;
        cnt[nums[i - k] + 50]--;
        
        ans.push_back(no(x));
    }
    
    return ans;
}
```

This code defines two functions: 'no' calculates the smallest index at which the sum of elements from a count array exceeds a threshold 'x', and 'getSubarrayBeauty' computes the beauty of subarrays based on the number of elements satisfying the condition set by the 'no' function.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	vector<int> cnt;
	```
	A vector 'cnt' is declared to store the count of occurrences for each number in the range [-50, 50].

2. **Function Definition**
	```cpp
	int no(int x) {
	```
	The 'no' function is defined to calculate the smallest index where the cumulative count exceeds 'x'.

3. **Variable Initialization**
	```cpp
	    int sum = 0;
	```
	A 'sum' variable is initialized to accumulate the counts from the 'cnt' array.

4. **Loop Setup**
	```cpp
	    for(int i = 0; i <= 50; i++) {
	```
	A loop runs from 0 to 50 to accumulate the counts of elements in the 'cnt' array.

5. **Summation**
	```cpp
	        sum += cnt[i];
	```
	The count for the current index 'i' is added to 'sum'.

6. **Conditional Check**
	```cpp
	        if(sum >= x)
	```
	This condition checks if the accumulated sum has reached or exceeded the threshold 'x'.

7. **Return Statement**
	```cpp
	            return i - 50;
	```
	If the condition is satisfied, the function returns the index 'i' minus 50, adjusting the index to the original range.

8. **Return Statement**
	```cpp
	    return 0;
	```
	If no index satisfies the condition, the function returns 0.

9. **Function Definition**
	```cpp
	vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
	```
	The 'getSubarrayBeauty' function is defined to calculate the beauty of subarrays of length 'k' based on the count condition in 'no'.

10. **Resize Operation**
	```cpp
	    cnt.resize(101, 0);
	```
	The 'cnt' vector is resized to have 101 elements, all initialized to 0, to store counts for the range [-50, 50].

11. **Result Vector Initialization**
	```cpp
	    vector<int> ans;
	```
	An empty vector 'ans' is initialized to store the results of the subarray beauties.

12. **Array Length Calculation**
	```cpp
	    int n = nums.size();
	```
	The size of the 'nums' array is stored in 'n'.

13. **Initial Loop Setup**
	```cpp
	    for(int i = 0; i < k; i++) {
	```
	A loop runs from 0 to 'k' to initialize the 'cnt' array with the counts of the first 'k' elements.

14. **Count Update**
	```cpp
	        cnt[nums[i] + 50]++;
	```
	For each element in the first 'k' elements, its count in the 'cnt' array is incremented.

15. **First Subarray Calculation**
	```cpp
	    ans.push_back(no(x));
	```
	The 'no' function is called with parameter 'x' to calculate the beauty of the first subarray, and the result is added to 'ans'.

16. **Sliding Window Loop**
	```cpp
	    for(int i = k; i < n; i++) {
	```
	A loop starts from index 'k' and slides through the 'nums' array to calculate the beauty for subsequent subarrays.

17. **Count Update**
	```cpp
	        cnt[nums[i] + 50]++;
	```
	The count of the current element is updated in the 'cnt' array.

18. **Count Decrease**
	```cpp
	        cnt[nums[i - k] + 50]--;
	```
	The count of the element that is sliding out of the window is decremented in the 'cnt' array.

19. **Subarray Calculation**
	```cpp
	        ans.push_back(no(x));
	```
	The 'no' function is called to calculate the beauty for the current subarray, and the result is added to 'ans'.

20. **Return Statement**
	```cpp
	    return ans;
	```
	The function returns the vector 'ans', which contains the beauty values for each subarray.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in terms of 'n', as we update the frequency array in constant time for each element in the subarray.

### Space Complexity 💾
- **Best Case:** O(101)
- **Worst Case:** O(101)

The space complexity is constant, as we use a fixed-size frequency array to count numbers in the subarray.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sliding-subarray-beauty/description/)

---
{{< youtube ovFs2xad0_Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
