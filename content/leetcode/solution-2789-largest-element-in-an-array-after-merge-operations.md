
+++
authors = ["grid47"]
title = "Leetcode 2789: Largest Element in an Array after Merge Operations"
date = "2024-02-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2789: Largest Element in an Array after Merge Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "wbXDrozEtOs"
youtube_upload_date="2023-07-23"
youtube_thumbnail="https://i.ytimg.com/vi/wbXDrozEtOs/maxresdefault.jpg"
comments = true
+++



---
You are given a 0-indexed array 'nums' consisting of positive integers. You can repeatedly perform an operation where you choose an index 'i' such that 'nums[i] <= nums[i + 1]', replace 'nums[i + 1]' with 'nums[i] + nums[i + 1]', and remove 'nums[i]'. Your task is to determine the largest possible value that can remain in the array after performing any number of operations.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a 0-indexed array of positive integers, 'nums'.
- **Example:** `Input: nums = [2, 5, 7, 9, 3]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the largest possible value that can remain in the array after performing the operations.
- **Example:** `Output: 21`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the largest element that can be obtained after performing the operations.

- Iterate through the array from the last element to the first.
- For each element, check if it's greater than or equal to the previous element.
- If so, add the current element to the previous element, remove the current element, and continue.
{{< dots >}}
### Problem Assumptions ✅
- All elements in the input array are positive integers.
- The input array may contain a variety of sizes, ranging from 1 to 10^5 elements.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [2, 5, 7, 9, 3]`  \
  **Explanation:** Starting with [2, 5, 7, 9, 3], we perform the operations: [7, 7, 9, 3] -> [7, 16, 3] -> [23, 3]. The largest possible element is 21.

- **Input:** `Input: nums = [4, 1, 3]`  \
  **Explanation:** After performing the operations [5, 3] -> [8], the largest value is 8.

{{< dots >}}
## Approach 🚀
To maximize the largest element in the array, we will combine adjacent elements based on the condition that the current element is less than or equal to the next.

### Initial Thoughts 💭
- The process can be viewed as accumulating values into the largest possible element while traversing from the end of the array.
- I need to efficiently combine values when possible and keep track of the largest value in the array.
{{< dots >}}
### Edge Cases 🌐
- The input array is guaranteed to have at least one element, so no need to handle empty inputs.
- Ensure the solution is optimized for arrays with a length of up to 10^5.
- If all elements are already in decreasing order, no operation will be possible, and the largest value is the last element.
- Handle arrays with up to 10^5 elements efficiently.
{{< dots >}}
## Code 💻
```cpp
long long maxArrayValue(vector<int>& in) {

    int n = in.size();        
    vector<long long> nums(n, 0);
    
    for(int i = 0; i < n; i++)
        nums[i] = in[i];

    long long res = nums[n - 1];
    
    for(int i = n - 1; i >= 0; i--) {
        res = max(res, (long long)nums[i]);
        if(i > 0 && nums[i] >= nums[i - 1]) {
            nums[i - 1] += nums[i];
        }
    }
    return res;
}
```

This function computes the maximum possible value from a given array of integers by applying a specific transformation. It iterates over the array from the last element, updating the result if a larger value is found and adjusting the previous elements when certain conditions are met.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	long long maxArrayValue(vector<int>& in) {
	```
	The function `maxArrayValue` is declared, accepting a reference to a vector of integers `in` and returning a long long value, which is the maximum possible value after applying transformations.

2. **Empty Line**
	```cpp
	
	```
	An empty line to separate sections of code for better readability.

3. **Variable Initialization**
	```cpp
	    int n = in.size();        
	```
	The variable `n` is initialized to store the size of the input vector `in`, which is used to iterate over the array.

4. **Vector Initialization**
	```cpp
	    vector<long long> nums(n, 0);
	```
	A vector `nums` of type long long is initialized with `n` elements, all set to 0. This vector will store the transformed values of the input array.

5. **Loop Initialization**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	A for loop is initiated to iterate through the entire input vector `in`. Each element will be copied to the corresponding index in `nums`.

6. **Value Assignment**
	```cpp
	        nums[i] = in[i];
	```
	Inside the loop, each element of the input array `in` is copied into the `nums` array.

7. **Variable Initialization**
	```cpp
	    long long res = nums[n - 1];
	```
	The variable `res` is initialized with the last element of the `nums` array. This will track the maximum value during the iteration.

8. **Loop Initialization**
	```cpp
	    for(int i = n - 1; i >= 0; i--) {
	```
	A for loop is initiated to iterate through the `nums` array in reverse order, from the last element to the first.

9. **Maximum Update**
	```cpp
	        res = max(res, (long long)nums[i]);
	```
	The `res` variable is updated to the maximum of its current value and the current element in `nums`. This ensures `res` holds the largest value encountered.

10. **Condition Check**
	```cpp
	        if(i > 0 && nums[i] >= nums[i - 1]) {
	```
	An if statement checks if the current element `nums[i]` is greater than or equal to the previous element `nums[i - 1]` and if the index is greater than 0.

11. **Value Update**
	```cpp
	            nums[i - 1] += nums[i];
	```
	If the condition is true, the previous element `nums[i - 1]` is incremented by the current element `nums[i]`. This transformation ensures that larger values accumulate towards the start of the array.

12. **Return Result**
	```cpp
	    return res;
	```
	The function returns the value of `res`, which now holds the maximum possible value obtained after processing all elements of the input array.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear, O(n), as we traverse the array once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) in the worst case when storing a copy of the array, but it can be optimized to O(1) if done in-place.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/largest-element-in-an-array-after-merge-operations/description/)

---
{{< youtube wbXDrozEtOs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
