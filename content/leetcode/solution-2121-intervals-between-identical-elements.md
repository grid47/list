
+++
authors = ["grid47"]
title = "Leetcode 2121: Intervals Between Identical Elements"
date = "2024-04-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2121: Intervals Between Identical Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "m1yH7eaMjMc"
youtube_upload_date="2021-12-26"
youtube_thumbnail="https://i.ytimg.com/vi/m1yH7eaMjMc/maxresdefault.jpg"
comments = true
+++



---
You are given an array of integers. Your task is to calculate the sum of absolute differences between the index of each element and the indices of all other occurrences of the same element. For each element in the array, return the sum of intervals to all its identical elements in the array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a 0-indexed array of integers, arr, where arr[i] is the i-th element.
- **Example:** `arr = [5, 3, 2, 3, 5, 2, 3]`
- **Constraints:**
	- n == arr.length
	- 1 <= n <= 100000
	- 1 <= arr[i] <= 100000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array where each element at index i represents the sum of absolute differences between arr[i] and all the other elements in arr with the same value as arr[i].
- **Example:** `[8, 4, 6, 4, 8, 6, 5]`
- **Constraints:**
	- The returned array should have the same length as the input array.

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the sum of intervals between each element and all occurrences of the same element in the array.

- Create a map to store the indices of each unique element.
- For each element in the map, calculate the sum of absolute differences between the element's indices and all other indices.
- For each index in the input array, calculate the interval sum using the precomputed intervals.
{{< dots >}}
### Problem Assumptions ✅
- The input array contains at least one element.
- The array may contain duplicate values.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: [5, 3, 2, 3, 5, 2, 3]`  \
  **Explanation:** At index 0, the element 5 has another occurrence at index 4, so the interval sum is |0 - 4| = 4. For index 1, the element 3 has occurrences at indices 2, 3, and 6, so the interval sum is |1 - 2| + |1 - 3| + |1 - 6| = 4.

{{< dots >}}
## Approach 🚀
To solve this problem, we will precompute the intervals for each element in the array and then use this precomputed data to calculate the answer for each index.

### Initial Thoughts 💭
- The problem involves calculating intervals between all identical elements in the array.
- Efficiently computing the intervals for each index is key to solving the problem within the constraints.
- We need to find a way to store the indices of each element and then compute the sum of intervals efficiently.
{{< dots >}}
### Edge Cases 🌐
- If the input array is empty, return an empty result.
- Handle large arrays with up to 100,000 elements efficiently.
- If all elements are unique, the interval sum for each element will be 0.
- Ensure the solution handles arrays with up to 100,000 elements in O(n) time.
{{< dots >}}
## Code 💻
```cpp
vector<long long> getDistances(vector<int>& arr) {
    typedef long long ll;

    
    int n = arr.size();
    unordered_map<int, vector<int>> mp;
    for(int i = 0; i < n; i++)
    mp[arr[i]].push_back(i);
    
    vector<ll> pre(n, 0), suf(n, 0);
    for(auto& val : mp){
        vector<int> vec = val.second;
        for(int i = 1; i < vec.size(); i++)
pre[vec[i]] = pre[vec[i - 1]] + i* (ll) (vec[i] - vec[i - 1]);            
    }
    for(auto& val : mp){
        vector<int> vec = val.second;
        for(int i = vec.size() - 2; i >= 0; i--)
suf[vec[i]] = suf[vec[i + 1]] + ll(vec.size() - 1 - i) *(ll) (vec[i + 1] - vec[i]);     
    }            

    vector<ll> ans(n, 0);
    for(int i = 0; i < n; i++)
    ans[i] = (pre[i] + suf[i]);
   
    return ans;
}
```

This function calculates the distances for each element in the array, considering the indices of duplicate elements and computing prefix and suffix sums for efficient calculation of the distances.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<long long> getDistances(vector<int>& arr) {
	```
	The function `getDistances` calculates the distances for each element in the array, considering the positions of duplicate elements.

2. **Type Definition**
	```cpp
	    typedef long long ll;
	```
	This line defines `ll` as a type alias for `long long` to simplify the usage of large integer types.

3. **Array Initialization**
	```cpp
	    int n = arr.size();
	```
	The size of the input array `arr` is assigned to `n`, which will be used for the loop limits.

4. **Map Initialization**
	```cpp
	    unordered_map<int, vector<int>> mp;
	```
	An unordered map `mp` is created to store indices of each unique element in the array.

5. **Map Population**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	This loop iterates over the input array and populates the map `mp` with indices of each element.

6. **Map Population Continued**
	```cpp
	    mp[arr[i]].push_back(i);
	```
	For each element `arr[i]`, its index is added to the corresponding vector in the map `mp`.

7. **Prefix and Suffix Arrays**
	```cpp
	    vector<ll> pre(n, 0), suf(n, 0);
	```
	Two vectors `pre` and `suf` are initialized to store the prefix and suffix sums for the distances.

8. **Prefix Sum Calculation**
	```cpp
	    for(auto& val : mp){
	```
	This loop iterates over the map `mp` to calculate the prefix sum for each element's indices.

9. **Prefix Sum Inner Loop**
	```cpp
	        vector<int> vec = val.second;
	```
	Extracts the list of indices of a particular element from the map `mp`.

10. **Prefix Sum Update**
	```cpp
	        for(int i = 1; i < vec.size(); i++)
	```
	This loop calculates the prefix sum by updating the `pre` array for each index in `vec`.

11. **Prefix Sum Update Continued**
	```cpp
	pre[vec[i]] = pre[vec[i - 1]] + i* (ll) (vec[i] - vec[i - 1]);
	```
	The prefix sum for each index is calculated using the formula considering the distance to the previous index.

12. **Suffix Sum Loop**
	```cpp
	    for(auto& val : mp){
	```
	This loop calculates the suffix sum for each element's indices in the map `mp`.

13. **Suffix Sum Inner Loop**
	```cpp
	        vector<int> vec = val.second;
	```
	Extracts the list of indices of a particular element from the map `mp` for the suffix sum calculation.

14. **Suffix Sum Update**
	```cpp
	        for(int i = vec.size() - 2; i >= 0; i--)
	```
	This loop calculates the suffix sum by iterating in reverse through the indices in `vec`.

15. **Suffix Sum Update Continued**
	```cpp
	suf[vec[i]] = suf[vec[i + 1]] + ll(vec.size() - 1 - i) *(ll) (vec[i + 1] - vec[i]);
	```
	The suffix sum for each index is calculated based on the distance to the next index.

16. **Final Answer Array**
	```cpp
	    vector<ll> ans(n, 0);
	```
	The result vector `ans` is initialized to store the final calculated distances.

17. **Result Population**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	This loop populates the `ans` vector with the sum of the prefix and suffix values for each element.

18. **Answer Finalization**
	```cpp
	    ans[i] = (pre[i] + suf[i]);
	```
	The final value for each element is calculated as the sum of its prefix and suffix distances.

19. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the computed result array containing the distances for each element.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

In the worst case, each element is unique and we compute the intervals for each element once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We need additional space to store the indices of each unique element in the array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/intervals-between-identical-elements/description/)

---
{{< youtube m1yH7eaMjMc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
