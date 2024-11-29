
+++
authors = ["grid47"]
title = "Leetcode 1695: Maximum Erasure Value"
date = "2024-05-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1695: Maximum Erasure Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "XIFl0gXnq9s"
youtube_upload_date="2020-12-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/XIFl0gXnq9s/maxresdefault.webp"
comments = true
+++



---
You are given an array of positive integers. Your task is to erase a subarray containing only unique elements and return the maximum sum of the subarray you can erase.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single array 'nums', which contains positive integers.
- **Example:** `[7, 2, 1, 2, 7, 2, 3, 5]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer representing the maximum sum of a subarray containing only unique elements.
- **Example:** `13`
- **Constraints:**
	- The result is the sum of the elements in the optimal subarray.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the maximum sum of a subarray of unique elements.

- Initialize a map to track the frequency of elements in the current subarray.
- Iterate through the array and maintain a sliding window of unique elements.
- Track the sum of elements in the current subarray and update the maximum sum whenever needed.
- Return the maximum sum obtained from the sliding window.
{{< dots >}}
### Problem Assumptions ✅
- The input array will not be empty.
- The array elements will always be positive integers.
{{< dots >}}
## Examples 🧩
- **Input:** `[3, 1, 4, 5, 6]`  \
  **Explanation:** After erasing the subarray [3], the remaining subarray [1, 4, 5, 6] has a sum of 15. This is the maximum sum.

- **Input:** `[7, 2, 1, 2, 7, 2, 3, 5]`  \
  **Explanation:** The subarray with the maximum sum is [2, 1, 2, 7, 2], with a sum of 13.

{{< dots >}}
## Approach 🚀
The approach involves iterating through the array with a sliding window, adjusting the window to ensure only unique elements, and calculating the maximum sum during the process.

### Initial Thoughts 💭
- This problem involves sliding window and map usage to track frequencies of elements.
- We need to ensure that the window only contains unique elements and adjust the window efficiently when duplicates are encountered.
{{< dots >}}
### Edge Cases 🌐
- The input will not be empty as the length of nums is at least 1.
- For large inputs, ensure that the algorithm performs efficiently with a time complexity of O(n).
- The array may contain repeated elements, but we only consider subarrays with unique elements.
- The length of the array will not exceed 10^5.
{{< dots >}}
## Code 💻
```cpp
int maximumUniqueSubarray(vector<int>& nums) {
    
    int sum = 0, n = nums.size();
    map<int, int> mp;
    
    int mx = 0;
    int j = 0;
    for(int i = 0; i < n; i++) {
        mp[nums[i]]++;
        sum += nums[i];
        
        while(mp[nums[i]] > 1) {
            mp[nums[j]]--;
            sum -= nums[j];
            j++;
        }
        
        mx = max(mx, sum);
    }
    return mx;
}
```

This function finds the maximum sum of a subarray with unique elements in the given vector `nums`. It uses a sliding window approach with two pointers, a map to track the frequency of elements, and a running sum to track the current subarray's sum.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maximumUniqueSubarray(vector<int>& nums) {
	```
	Defines the function `maximumUniqueSubarray` that takes a vector `nums` and returns the maximum sum of a subarray with unique elements.

2. **Variable Initialization**
	```cpp
	    
	```
	Prepare for the following variable initializations.

3. **Variable Initialization**
	```cpp
	    int sum = 0, n = nums.size();
	```
	Initialize `sum` to 0 to track the current sum of the subarray and `n` to store the size of the input vector `nums`.

4. **Data Structure Initialization**
	```cpp
	    map<int, int> mp;
	```
	Initialize a map `mp` to store the frequency of each element in the current window (subarray).

5. **Variable Initialization**
	```cpp
	    
	```
	Prepare for the following variable initializations.

6. **Variable Initialization**
	```cpp
	    int mx = 0;
	```
	Initialize `mx` to 0, which will store the maximum sum encountered during the iteration over the subarray.

7. **Variable Initialization**
	```cpp
	    int j = 0;
	```
	Initialize `j` to 0, which will serve as the starting index for the sliding window of the subarray.

8. **Main Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Start a loop that iterates over each element `nums[i]` of the array `nums`.

9. **Frequency Update**
	```cpp
	        mp[nums[i]]++;
	```
	Increment the frequency count of the current element `nums[i]` in the map `mp`.

10. **Update Sum**
	```cpp
	        sum += nums[i];
	```
	Add the current element `nums[i]` to the running sum `sum`.

11. **Check for Duplicates**
	```cpp
	        
	```
	Check and adjust the window if there are duplicate elements.

12. **Sliding Window Adjustment**
	```cpp
	        while(mp[nums[i]] > 1) {
	```
	If the current element `nums[i]` appears more than once in the window, enter a loop to shrink the window from the left.

13. **Remove Element from Window**
	```cpp
	            mp[nums[j]]--;
	```
	Decrement the frequency of the element `nums[j]` at the left of the window in the map `mp`.

14. **Update Sum**
	```cpp
	            sum -= nums[j];
	```
	Subtract the element `nums[j]` from the running sum `sum` as it's being excluded from the window.

15. **Increment Left Pointer**
	```cpp
	            j++;
	```
	Increment the left pointer `j` to shrink the window from the left.

16. **Update Maximum Sum**
	```cpp
	        mx = max(mx, sum);
	```
	Update the variable `mx` to store the maximum subarray sum found so far.

17. **Return Result**
	```cpp
	    return mx;
	```
	Return the maximum sum `mx` of a subarray with unique elements.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The algorithm processes each element once, making the time complexity O(n), where n is the number of elements in the array.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the usage of a map to track the frequencies of elements in the current subarray.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-erasure-value/description/)

---
{{< youtube XIFl0gXnq9s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
