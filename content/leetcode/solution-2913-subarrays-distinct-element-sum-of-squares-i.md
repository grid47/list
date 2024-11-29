
+++
authors = ["grid47"]
title = "Leetcode 2913: Subarrays Distinct Element Sum of Squares I"
date = "2024-01-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2913: Subarrays Distinct Element Sum of Squares I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "vBSxcFdwcQU"
youtube_upload_date="2023-10-28"
youtube_thumbnail="https://i.ytimg.com/vi/vBSxcFdwcQU/maxresdefault.jpg"
comments = true
+++



---
You are given a 0-indexed integer array `nums`. A subarray of `nums` is a contiguous sequence of elements. The distinct count of a subarray is defined as the number of unique values within that subarray. Your task is to return the sum of the squares of the distinct counts for all possible subarrays of `nums`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array `nums` of size `n` where `1 <= n <= 100`. Each element of `nums` is an integer between 1 and 100.
- **Example:** `nums = [2, 3, 2]`
- **Constraints:**
	- 1 <= nums.length <= 100
	- 1 <= nums[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the sum of the squares of distinct counts of all subarrays of `nums`.
- **Example:** `For the input `nums = [2, 3, 2]`, the output is 14.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the sum of the squares of the distinct counts of all subarrays of the input array `nums`.

- For each subarray starting from index `i` and ending at index `j`, calculate the number of distinct values in the subarray.
- Square the number of distinct values and accumulate the result.
- Repeat this for all possible subarrays in the array.
{{< dots >}}
### Problem Assumptions ✅
- The input array will contain only integers between 1 and 100.
- The array will not be empty.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [2, 3, 2]`  \
  **Explanation:** The possible subarrays are: [2], [3], [2], [2, 3], [3, 2], and [2, 3, 2]. The distinct values for each subarray are: 1, 1, 1, 2, 2, and 2 respectively. The sum of the squares of the distinct counts is: 1^2 + 1^2 + 1^2 + 2^2 + 2^2 + 2^2 = 1 + 1 + 1 + 4 + 4 + 4 = 15.

{{< dots >}}
## Approach 🚀
The key idea is to calculate the distinct count for all subarrays of the given array and then sum the squares of these counts. A map can be used to keep track of the distinct elements as we slide through each subarray.

### Initial Thoughts 💭
- The problem involves iterating over all possible subarrays of the array and calculating their distinct counts.
- Using a sliding window approach and updating the count of distinct elements for each subarray will help achieve an efficient solution.
{{< dots >}}
### Edge Cases 🌐
- The input array will not be empty as per the problem constraints.
- For larger arrays, the solution needs to efficiently handle up to 100 elements.
- Consider the case where all elements in the array are the same.
- The array length is between 1 and 100.
- Each element in the array is between 1 and 100.
{{< dots >}}
## Code 💻
```cpp
int sumCounts(vector<int>& ar) {
    int n=ar.size();
    int ans=0;
    map<int,int>fr;
    //sort(ar.begin(),ar.end());
    for(int i=0;i<n;i++){
        int val=0;
         map<int,int>fr;
        for(int j=i;j<n;j++){
            if(fr[ar[j]]==0) val++;
            fr[ar[j]]++;
            ans=ans+val*val;
        }
    }
    return ans;
}
```

The code defines the `sumCounts` function, which calculates a sum based on unique element counts in the array `ar`. It uses nested loops to iterate over the array and tracks occurrences of each element using a map. The sum is updated by squaring the count of unique elements at each step.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int sumCounts(vector<int>& ar) {
	```
	Defines the `sumCounts` function that takes a reference to a vector `ar` and returns an integer result, representing a sum based on element frequency calculations.

2. **Variable Initialization**
	```cpp
	    int n=ar.size();
	```
	Initializes variable `n` to store the size of the input vector `ar`.

3. **Variable Initialization**
	```cpp
	    int ans=0;
	```
	Initializes variable `ans` to store the final sum, which will be calculated as the function progresses.

4. **Map Initialization**
	```cpp
	    map<int,int>fr;
	```
	Initializes a map `fr` to track the frequency of each element in the vector `ar` during the iteration.

5. **Loop: Iterate Over Array**
	```cpp
	    for(int i=0;i<n;i++){
	```
	Begins a loop that iterates through each element in the array `ar` using the index `i`.

6. **Variable Initialization**
	```cpp
	        int val=0;
	```
	Initializes the variable `val` to track the count of unique elements for each subarray starting at index `i`.

7. **Map Initialization**
	```cpp
	         map<int,int>fr;
	```
	Initializes a local map `fr` inside the loop to track the frequencies of elements for each subarray.

8. **Inner Loop: Iterate Over Subarray**
	```cpp
	        for(int j=i;j<n;j++){
	```
	Begins an inner loop that iterates over the subarray starting from index `i` to the end of the array `ar`.

9. **Frequency Check: Unique Element Count**
	```cpp
	            if(fr[ar[j]]==0) val++;
	```
	Checks if the element at `ar[j]` has been encountered before in the current subarray. If not, it increments `val` to count the unique element.

10. **Update Frequency Map**
	```cpp
	            fr[ar[j]]++;
	```
	Increments the count of the element `ar[j]` in the frequency map `fr`.

11. **Update Result**
	```cpp
	            ans=ans+val*val;
	```
	Updates the result `ans` by adding the square of the count of unique elements (`val`) for the current subarray.

12. **Return Result**
	```cpp
	    return ans;
	```
	Returns the final result `ans`, which is the sum of squared unique element counts for all subarrays of `ar`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is O(n^2) because we iterate over all possible subarrays and calculate the distinct count for each.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the frequency map used to track distinct elements in each subarray.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/description/)

---
{{< youtube vBSxcFdwcQU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
