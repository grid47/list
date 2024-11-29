
+++
authors = ["grid47"]
title = "Leetcode 2670: Find the Distinct Difference Array"
date = "2024-02-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2670: Find the Distinct Difference Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "ikDNBcVaq6Y"
youtube_upload_date="2023-05-07"
youtube_thumbnail="https://i.ytimg.com/vi/ikDNBcVaq6Y/maxresdefault.jpg"
comments = true
+++



---
You are given a 0-indexed integer array `nums` of length `n`. Your task is to compute the 'distinct difference array' of `nums`. The distinct difference array, `diff`, is defined such that `diff[i]` equals the difference between the number of distinct elements in the prefix `nums[0,...,i]` and the number of distinct elements in the suffix `nums[i+1,...,n-1]`. Specifically, for each index `i`, compute `diff[i] = distinct elements in the prefix - distinct elements in the suffix`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `nums` of length `n`.
- **Example:** `Input: nums = [4,5,6,7]`
- **Constraints:**
	- 1 <= n == nums.length <= 50
	- 1 <= nums[i] <= 50

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an array `diff` where each element represents the distinct difference for the corresponding index in `nums`.
- **Example:** `Output: [-3, -1, 1, 3]`
- **Constraints:**
	- The output array should have the same length as the input array `nums`.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the number of distinct elements in the prefix and suffix for each index, then compute the difference.

- Step 1: Use two maps to store the count of distinct elements in the prefix and suffix of the array.
- Step 2: Iterate through the array, updating the prefix and suffix distinct counts as you go, and compute the difference at each index.
- Step 3: Store the result in the `diff` array and return it.
{{< dots >}}
### Problem Assumptions ✅
- The input array `nums` has unique values within the range [1,50].
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [4,5,6,7]`  \
  **Explanation:** For index i = 0, the prefix has 1 distinct element (4) and the suffix has 3 distinct elements (5,6,7), so diff[0] = 1 - 3 = -2. For index i = 1, the prefix has 2 distinct elements (4,5) and the suffix has 2 distinct elements (6,7), so diff[1] = 2 - 2 = 0, and so on.

- **Input:** `Input: nums = [3, 2, 3, 4, 2]`  \
  **Explanation:** For index i = 0, the prefix has 1 distinct element (3) and the suffix has 3 distinct elements (2,4), so diff[0] = 1 - 3 = -2. For index i = 1, the prefix has 2 distinct elements (3,2) and the suffix has 3 distinct elements (4,2), so diff[1] = 2 - 3 = -1, and so on.

{{< dots >}}
## Approach 🚀
The solution calculates the number of distinct elements in both the prefix and suffix for each index in the array, then computes the difference between these two counts.

### Initial Thoughts 💭
- We need to keep track of distinct elements in both the prefix and suffix for each index.
- The task can be broken down into updating counters efficiently as we iterate over the array.
- Using maps to store the distinct element counts for both the prefix and suffix should allow us to compute the result efficiently.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one element in the array, as `n >= 1`.
- The solution should work efficiently even with the maximum input size of `n = 50`.
- If the array contains only one unique element, the result will be zero for all indices.
- Ensure the solution can handle arrays with repeated elements properly.
{{< dots >}}
## Code 💻
```cpp
vector<int> distinctDifferenceArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 0);
    map<int, int> l, r;
    for(int i = 0; i < n; i++) {
        r[nums[i]]++;
    }

    for(int i = 0; i < n; i++) {
        r[nums[i]]--;
        if(r[nums[i]] == 0) r.erase(nums[i]);
        l[nums[i]]++;
        ans[i] = l.size() - r.size();
    }
    return ans;
}
```

This function calculates the difference between the number of distinct elements in the left and right subarrays at each position in the array, storing the result in the 'ans' vector.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> distinctDifferenceArray(vector<int>& nums) {
	```
	The function starts by taking a vector 'nums' as input and will return a vector 'ans', where each element represents the difference in distinct elements between the left and right parts of the array.

2. **Array Size Calculation**
	```cpp
	    int n = nums.size();
	```
	We retrieve the size of the input array 'nums' and store it in the variable 'n'.

3. **Array Initialization**
	```cpp
	    vector<int> ans(n, 0);
	```
	We initialize a vector 'ans' of size 'n', filled with zeros, to store the results.

4. **Map Initialization**
	```cpp
	    map<int, int> l, r;
	```
	We declare two maps, 'l' and 'r', to count the frequency of distinct elements in the left and right subarrays, respectively.

5. **Right Subarray Frequency Initialization**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	We begin a loop to populate the map 'r' with the frequency of each element in the 'nums' array.

6. **Right Subarray Frequency Update**
	```cpp
	        r[nums[i]]++;
	```
	For each element in 'nums', we increment its count in the map 'r', representing the frequency in the right subarray.

7. **Main Loop Start**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	We start a loop over the array 'nums' to compute the difference in distinct elements between the left and right subarrays.

8. **Right Subarray Frequency Decrease**
	```cpp
	        r[nums[i]]--;
	```
	We decrement the frequency of the current element in 'r' as it is being moved to the left subarray.

9. **Right Subarray Frequency Clean-up**
	```cpp
	        if(r[nums[i]] == 0) r.erase(nums[i]);
	```
	If the frequency of the current element in 'r' becomes zero, we remove it from the map to maintain only the distinct elements.

10. **Left Subarray Frequency Update**
	```cpp
	        l[nums[i]]++;
	```
	We increment the frequency of the current element in 'l', adding it to the left subarray.

11. **Answer Update**
	```cpp
	        ans[i] = l.size() - r.size();
	```
	We calculate the difference in the number of distinct elements between the left and right subarrays by comparing the sizes of maps 'l' and 'r', and store the result in 'ans[i]'.

12. **Return Result**
	```cpp
	    return ans;
	```
	We return the vector 'ans', which contains the distinct difference values for each index in the input array.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) since we iterate through the array twice, which is efficient given the problem's constraints.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of the prefix and suffix maps.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-distinct-difference-array/description/)

---
{{< youtube ikDNBcVaq6Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
