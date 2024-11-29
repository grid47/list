
+++
authors = ["grid47"]
title = "Leetcode 2607: Make K-Subarray Sums Equal"
date = "2024-02-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2607: Make K-Subarray Sums Equal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Sorting","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "aBMFrPs2I5c"
youtube_upload_date="2023-04-01"
youtube_thumbnail="https://i.ytimg.com/vi/aBMFrPs2I5c/maxresdefault.jpg"
comments = true
+++



---
You are given a circular integer array arr and an integer k. In this circular array, the first element follows after the last one, and the last element precedes the first one. Your task is to determine the minimum number of operations required to make the sum of every subarray of length k equal. In each operation, you can pick any element in the array and either increase or decrease it by 1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a circular integer array arr and an integer k, which is the length of the subarrays to be considered. The array arr contains integers, and the subarray length k determines how the sum of elements is evaluated.
- **Example:** `arr = [3, 8, 4, 6], k = 3`
- **Constraints:**
	- 1 <= k <= arr.length <= 10^5
	- 1 <= arr[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of operations required to make the sum of each subarray of length k equal.
- **Example:** `Output: 4`
- **Constraints:**
	- The output is a single integer representing the minimum number of operations.

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the minimum number of operations needed to equalize the sum of all subarrays of length k.

- For each possible subarray, group the elements based on their relative positions, taking the circular nature into account.
- For each group of elements, find the median value and calculate the cost of transforming the group to have all elements equal to the median.
- Sum up the costs for all groups to determine the minimum number of operations.
{{< dots >}}
### Problem Assumptions ✅
- The array arr is circular, meaning the end wraps around to the beginning.
{{< dots >}}
## Examples 🧩
- **Input:** `arr = [1, 4, 1, 3], k = 2`  \
  **Explanation:** In this case, we need to ensure that every subarray of length 2 has the same sum. After performing one operation on index 1 (changing its value to 3), all subarrays will have a sum of 4, and the result is 1 operation.

- **Input:** `arr = [2, 5, 5, 7], k = 3`  \
  **Explanation:** In this case, we need to perform three operations on index 0 to make it equal to 5 and two operations on index 3 to make it equal to 5. After these operations, every subarray of length 3 will sum to 15, and the result is 5 operations.

{{< dots >}}
## Approach 🚀
The goal is to compute the minimal number of operations needed to equalize the sum of all subarrays of length k. This is done by grouping elements based on their position within subarrays, adjusting them to minimize the overall cost.

### Initial Thoughts 💭
- The array is circular, meaning indices must be treated modulo the array length.
- The sum of each subarray of length k must be equalized by modifying individual elements.
- One potential approach is to find the median value of each group of elements that appear at the same relative position in the subarrays and then adjust all the elements to this median.
{{< dots >}}
### Edge Cases 🌐
- An empty array should return 0 operations.
- The array can have up to 100,000 elements, so the solution must scale efficiently with the input size.
- Arrays with all identical values should require 0 operations.
- Make sure the algorithm handles large integers and computes the result within the given time constraints.
{{< dots >}}
## Code 💻
```cpp

long long solve(vector<int> nums) {
    if(nums.size() == 0) return 0;
    sort(nums.begin(), nums.end());
    int hit = nums[nums.size() / 2];
    long long res = 0;
    for(int i = 0; i < nums.size(); i++)
        res += abs(hit - nums[i]);
    return res;
}

long long makeSubKSumEqual(vector<int>& arr, int k) {
    int n = arr.size();
    set<int> cnt;
    long long res = 0;
    for(int i = 0; i < n; i++) {
        
        int j = i;
        vector<int> nums;
        while(!cnt.count(j)) {
            cnt.insert(j);
            nums.push_back(arr[j]);
            j = (j + k) % n;
        }
        res += solve(nums);
    }
    
    return res;
}
```

This is a solution for the problem of making subarrays with a given length k have equal sum. It first solves each subarray and then adds up the results.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	long long solve(vector<int> nums) {
	```
	The function 'solve' takes a vector of integers and calculates the minimum cost of making all elements equal by using the median.

2. **Condition Check**
	```cpp
	    if(nums.size() == 0) return 0;
	```
	Checks if the input vector is empty. If it is, the function returns 0.

3. **Sorting**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	Sorts the input vector 'nums' to make it easier to find the median.

4. **Median Calculation**
	```cpp
	    int hit = nums[nums.size() / 2];
	```
	Finds the median element in the sorted vector. This will be the target value for all elements.

5. **Initialization**
	```cpp
	    long long res = 0;
	```
	Initializes the result variable 'res' to accumulate the total cost.

6. **Loop**
	```cpp
	    for(int i = 0; i < nums.size(); i++)
	```
	Iterates over each element of the sorted vector to calculate the cost of converting each element to the median.

7. **Cost Calculation**
	```cpp
	        res += abs(hit - nums[i]);
	```
	Adds the absolute difference between the median and the current element to the result.

8. **Return Statement**
	```cpp
	    return res;
	```
	Returns the final accumulated cost.

9. **Function Declaration**
	```cpp
	long long makeSubKSumEqual(vector<int>& arr, int k) {
	```
	The function 'makeSubKSumEqual' calculates the total cost of making all subarrays of length k equal using the 'solve' function.

10. **Size Calculation**
	```cpp
	    int n = arr.size();
	```
	Gets the size of the input array 'arr'.

11. **Set Initialization**
	```cpp
	    set<int> cnt;
	```
	Initializes a set 'cnt' to keep track of the indices that have already been processed.

12. **Result Initialization**
	```cpp
	    long long res = 0;
	```
	Initializes the result variable 'res' to accumulate the total cost.

13. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Iterates over each element of the input array.

14. **Inner Loop Initialization**
	```cpp
	        int j = i;
	```
	Sets up the inner loop to track the indices of the subarray.

15. **Vector Initialization**
	```cpp
	        vector<int> nums;
	```
	Initializes an empty vector 'nums' to store the elements of the current subarray.

16. **Subarray Formation**
	```cpp
	        while(!cnt.count(j)) {
	```
	Processes the current element of the subarray if it hasn't been processed before.

17. **Mark Element Processed**
	```cpp
	            cnt.insert(j);
	```
	Marks the current index as processed by inserting it into the set.

18. **Push Element to Subarray**
	```cpp
	            nums.push_back(arr[j]);
	```
	Adds the element at the current index to the subarray vector.

19. **Next Index Calculation**
	```cpp
	            j = (j + k) % n;
	```
	Calculates the next index in the subarray by adding k and applying modulo to wrap around the array.

20. **Subarray Cost Calculation**
	```cpp
	        res += solve(nums);
	```
	Calculates the cost of making the current subarray equal using the 'solve' function and adds it to the result.

21. **Return Statement**
	```cpp
	    return res;
	```
	Returns the total accumulated cost of making all subarrays equal.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting operation when finding the median of each group, which takes O(n log n) time.

### Space Complexity 💾
- **Best Case:** O(k)
- **Worst Case:** O(n)

The space complexity is O(n) in the worst case due to the need to store groupings and calculate costs.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/make-k-subarray-sums-equal/description/)

---
{{< youtube aBMFrPs2I5c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
