
+++
authors = ["grid47"]
title = "Leetcode 3043: Find the Length of the Longest Common Prefix"
date = "2024-01-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3043: Find the Length of the Longest Common Prefix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Trie"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "06dIUJwdHlQ"
youtube_upload_date="2024-09-24"
youtube_thumbnail="https://i.ytimg.com/vi/06dIUJwdHlQ/maxresdefault.jpg"
comments = true
+++



---
You are given two arrays `arr1` and `arr2` containing positive integers. Your task is to find the length of the longest common prefix between all pairs of integers `(x, y)` such that `x` belongs to `arr1` and `y` belongs to `arr2`. A prefix of a number is any integer formed by one or more digits starting from its leftmost digit. For example, `123` is a prefix of `12345`, but `234` is not. If no common prefix exists for any pair, return 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two arrays `arr1` and `arr2` containing positive integers.
- **Example:** `arr1 = [1, 10, 100], arr2 = [1000]`
- **Constraints:**
	- 1 <= arr1.length, arr2.length <= 5 * 10^4
	- 1 <= arr1[i], arr2[i] <= 10^8

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer representing the length of the longest common prefix among all pairs of integers `(x, y)` where `x` belongs to `arr1` and `y` belongs to `arr2`.
- **Example:** `For input arr1 = [1, 10, 100] and arr2 = [1000], the output is 3, as the longest common prefix is '100'.`
- **Constraints:**
	- If no common prefix exists for any pair, return 0.

{{< dots >}}
### Core Logic 🔍
**Goal:** To solve the problem, we need to find the longest common prefix between all pairs of integers where one integer is from `arr1` and the other is from `arr2`. We can do this by checking all pairs and calculating the longest prefix for each pair.

- Iterate over all integers in `arr1` and `arr2`.
- For each pair of integers `(x, y)`, compare their digits starting from the leftmost digit to find the longest common prefix.
- Store and update the maximum length of the common prefix encountered.
{{< dots >}}
### Problem Assumptions ✅
- All elements in both arrays are positive integers.
- No number will have more than 8 digits.
{{< dots >}}
## Examples 🧩
- **Input:** `arr1 = [1, 10, 100], arr2 = [1000]`  \
  **Explanation:** The longest common prefix between the numbers in `arr1` and `arr2` is 100, found between 100 from `arr1` and 1000 from `arr2`. Hence, the output is 3.

{{< dots >}}
## Approach 🚀
We can solve this problem by comparing each integer from `arr1` with each integer from `arr2`, checking their longest common prefix. The approach involves iterating over the pairs and calculating the common prefix.

### Initial Thoughts 💭
- To check the common prefix, we can compare the digits from left to right for each pair of numbers.
- Since we are comparing pairs of numbers, it might be beneficial to store the longest common prefix and update it as we process new pairs.
{{< dots >}}
### Edge Cases 🌐
- If either `arr1` or `arr2` is empty, return 0.
- For large inputs, ensure the solution runs efficiently within time limits.
- If no common prefix exists for any pair, return 0.
- Handle all pairs efficiently, given that the arrays may contain up to 50,000 elements.
{{< dots >}}
## Code 💻
```cpp

int size(int x) {
    int sz = 0;
    while(x > 0) {
        sz++;
        x /= 10;
    }
    return sz;
}

int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    
    map<int, int> mp;
    
    int arr[] = {10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
    
    for(int x: arr1) {
        int p = x;
        int sz = 0;
        for(int i = 0; i < 8; i++) {
            
            if(p / arr[i] > 0) {
                sz++;
                mp[p / arr[i]] = sz;
                // cout << p / arr[i] << " " << sz << "\n";
            }
            
        }
    }
    int mx = 0;
    for(int x: arr2) {
        int p = x;
        for(int i = 0; i < 8; i++) {
            if(p / arr[i] > 0) 
            if(mp.count(p / arr[i]))
                mx = max(mx, mp[p / arr[i]]);
        }
    }
    return mx;
}
```

This solution defines a function `longestCommonPrefix` to find the longest common prefix between two arrays of integers, utilizing a map for storing intermediate results based on the size of the numbers.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int size(int x) {
	```
	Defines the `size` function that calculates the number of digits in a given integer `x`.

2. **Variable Initialization**
	```cpp
	    int sz = 0;
	```
	Initializes a variable `sz` to 0, which will be used to count the number of digits in `x`.

3. **Loop**
	```cpp
	    while(x > 0) {
	```
	Starts a `while` loop that will continue as long as `x` is greater than 0, which means there are still digits left to process.

4. **Increment**
	```cpp
	        sz++;
	```
	Increments `sz` for each digit in `x`.

5. **Update Value**
	```cpp
	        x /= 10;
	```
	Divides `x` by 10, effectively removing the last digit in `x`.

6. **Return Statement**
	```cpp
	    return sz;
	```
	Returns the number of digits in `x`.

7. **Function Definition**
	```cpp
	int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
	```
	Defines the `longestCommonPrefix` function that finds the longest common prefix between two arrays of integers.

8. **Variable Initialization**
	```cpp
	    map<int, int> mp;
	```
	Declares a map `mp` to store the sizes of prefixes for each number in `arr1`.

9. **Array Declaration**
	```cpp
	    int arr[] = {10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
	```
	Declares an array `arr` that holds powers of 10, which will be used to extract prefixes of numbers from `arr1`.

10. **Loop**
	```cpp
	    for(int x: arr1) {
	```
	Starts a loop to iterate over each element `x` in `arr1`.

11. **Variable Initialization**
	```cpp
	        int p = x;
	```
	Assigns `x` to the variable `p` for further processing.

12. **Variable Initialization**
	```cpp
	        int sz = 0;
	```
	Initializes `sz` to 0 for counting the number of significant digits in the prefix.

13. **Inner Loop**
	```cpp
	        for(int i = 0; i < 8; i++) {
	```
	Starts a loop to iterate over the array `arr` for extracting prefixes from `p`.

14. **Condition Check**
	```cpp
	            if(p / arr[i] > 0) {
	```
	Checks if the current prefix (i.e., `p / arr[i]`) is greater than 0.

15. **Increment**
	```cpp
	                sz++;
	```
	Increments the size `sz` for each valid prefix found.

16. **Map Update**
	```cpp
	                mp[p / arr[i]] = sz;
	```
	Stores the prefix and its corresponding size in the map `mp`.

17. **Variable Initialization**
	```cpp
	    int mx = 0;
	```
	Initializes `mx` to 0, which will store the maximum length of the common prefix.

18. **Loop**
	```cpp
	    for(int x: arr2) {
	```
	Starts a loop to iterate over each element `x` in `arr2`.

19. **Variable Initialization**
	```cpp
	        int p = x;
	```
	Assigns `x` to the variable `p` for processing.

20. **Inner Loop**
	```cpp
	        for(int i = 0; i < 8; i++) {
	```
	Starts a loop to iterate over the array `arr` for checking prefixes of `p`.

21. **Condition Check**
	```cpp
	            if(p / arr[i] > 0) 
	```
	Checks if the current prefix of `p` is greater than 0.

22. **Map Lookup**
	```cpp
	            if(mp.count(p / arr[i]))
	```
	Checks if the current prefix exists in the map `mp`.

23. **Update Maximum**
	```cpp
	                mx = max(mx, mp[p / arr[i]]);
	```
	Updates the maximum length of the common prefix if a valid prefix is found in `mp`.

24. **Return Statement**
	```cpp
	    return mx;
	```
	Returns the maximum length of the common prefix found between the two arrays.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * m), where n is the length of `arr1` and m is the length of `arr2`.
- **Average Case:** O(n * m), assuming we are iterating over all pairs and comparing the digits of each pair.
- **Worst Case:** O(n * m), where n is the length of `arr1` and m is the length of `arr2`, since we compare each pair of numbers.

We need to compare each number in `arr1` with each number in `arr2`.

### Space Complexity 💾
- **Best Case:** O(1), since the space usage is constant and does not depend on the input size.
- **Worst Case:** O(1), as we only need to store variables for the maximum prefix length.

The space complexity is constant, as we are not storing extra data beyond the variables for the result.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/)

---
{{< youtube 06dIUJwdHlQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
