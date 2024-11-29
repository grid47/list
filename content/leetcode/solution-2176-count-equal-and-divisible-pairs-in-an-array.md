
+++
authors = ["grid47"]
title = "Leetcode 2176: Count Equal and Divisible Pairs in an Array"
date = "2024-04-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2176: Count Equal and Divisible Pairs in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "25az-hMz2YE"
youtube_upload_date="2022-02-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/25az-hMz2YE/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed integer array `nums` of length `n` and an integer `k`. You need to count the number of pairs `(i, j)` where `0 <= i < j < n` such that `nums[i] == nums[j]` and the product `i * j` is divisible by `k`. Return the number of such pairs.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `nums` and an integer `k`. The array represents the magic numbers found in different bags, and `k` is a divisor used to filter the valid pairs.
- **Example:** `[5, 2, 3, 5, 2, 3], k = 6`
- **Constraints:**
	- 1 <= nums.length <= 100
	- 1 <= nums[i], k <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an integer representing the number of pairs `(i, j)` that satisfy the given conditions.
- **Example:** `3`
- **Constraints:**
	- The output must be an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find pairs `(i, j)` such that `nums[i] == nums[j]` and the product `i * j` is divisible by `k`.

- Iterate over each element in the `nums` array.
- For each element, check previously seen indices where the value is the same and check if `i * j` is divisible by `k`.
- Count all such pairs and return the count.
{{< dots >}}
### Problem Assumptions ✅
- The array `nums` is at least of length 1.
- The values in the array `nums` and `k` are positive integers.
{{< dots >}}
## Examples 🧩
- **Input:** `[5, 2, 3, 5, 2, 3], k = 6`  \
  **Explanation:** In this example, the valid pairs are (0, 3), (1, 4), and (2, 5), and the count of such pairs is 3.

{{< dots >}}
## Approach 🚀
The approach is to iterate through the array and for each element, check if any earlier occurrence of the same value forms a valid pair with the current element.

### Initial Thoughts 💭
- We need to efficiently check the conditions for each pair `(i, j)`.
- An efficient approach would involve using a map to store previously seen values and their indices.
{{< dots >}}
### Edge Cases 🌐
- The input array will not be empty due to the problem's constraints.
- The solution should efficiently handle arrays up to length 100.
- Consider the case when no value repeats in the array.
- Ensure that the solution works within the input constraints.
{{< dots >}}
## Code 💻
```cpp
int countPairs(vector<int>& nums, int k) {
    unordered_map<int,vector<int>> umap;
    int count = 0;
    for(int i = 0; i < nums.size(); i++) 
    {
        if(umap.find(nums[i]) != umap.end()) 
        {
            for(auto x : umap[nums[i]]) 
                if((i * x) % k == 0)
                    count++;
        }
        
        umap[nums[i]].push_back(i);
    }
    return count;
}
```

This function, `countPairs`, takes a vector `nums` and an integer `k`, and returns the count of pairs `(i, j)` such that `i < j` and `(i * j) % k == 0`. The function uses an unordered map to store indices of each number in the vector.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int countPairs(vector<int>& nums, int k) {
	```
	Define the function `countPairs` that takes a vector of integers `nums` and an integer `k`, and returns an integer `count` representing the number of valid pairs (i, j).

2. **Data Structure Initialization**
	```cpp
	    unordered_map<int,vector<int>> umap;
	```
	Initialize an unordered map `umap` where the key is an integer from `nums`, and the value is a vector of integers that stores indices where that number appears in `nums`.

3. **Variable Initialization**
	```cpp
	    int count = 0;
	```
	Initialize a variable `count` to 0, which will keep track of the number of valid pairs that meet the condition `(i * j) % k == 0`.

4. **Loop Start**
	```cpp
	    for(int i = 0; i < nums.size(); i++) 
	```
	Start a for loop to iterate through each index `i` of the `nums` vector.

5. **Condition Check**
	```cpp
	        if(umap.find(nums[i]) != umap.end()) 
	```
	Check if the current element `nums[i]` exists in the unordered map `umap`. If it does, proceed to find the pairs.

6. **Inner Loop Start**
	```cpp
	            for(auto x : umap[nums[i]]) 
	```
	Iterate through all the indices `x` where `nums[i]` has appeared earlier (from the unordered map `umap`).

7. **Pair Validation**
	```cpp
	                if((i * x) % k == 0)
	```
	For each index `x`, check if the product of the current index `i` and `x` is divisible by `k`. If it is, it's a valid pair.

8. **Count Update**
	```cpp
	                    count++;
	```
	Increment the `count` variable for each valid pair found.

9. **Map Update**
	```cpp
	        umap[nums[i]].push_back(i);
	```
	Add the current index `i` to the list of indices for `nums[i]` in the unordered map `umap`.

10. **Return Result**
	```cpp
	    return count;
	```
	Return the final count of valid pairs.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n^2)

The time complexity is O(n) on average, but in the worst case (when many elements are the same), it could reach O(n^2).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the map storing indices for each element in the array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/description/)

---
{{< youtube 25az-hMz2YE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
