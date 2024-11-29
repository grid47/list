
+++
authors = ["grid47"]
title = "Leetcode 2948: Make Lexicographically Smallest Array by Swapping Elements"
date = "2024-01-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2948: Make Lexicographically Smallest Array by Swapping Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Union Find","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "r0981xS7CjY"
youtube_upload_date="2023-11-26"
youtube_thumbnail="https://i.ytimg.com/vi/r0981xS7CjY/maxresdefault.jpg"
comments = true
+++



---
You are given a list of integers, `nums`, and a positive integer `limit`. In each operation, you can choose two indices `i` and `j` and swap the elements at these indices if the absolute difference between `nums[i]` and `nums[j]` is less than or equal to the given `limit`. Your task is to return the lexicographically smallest array that can be obtained after applying the operation as many times as needed.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array `nums` of size `n` and an integer `limit`.
- **Example:** `nums = [1,5,3,9,8], limit = 2`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^9
	- 1 <= limit <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the lexicographically smallest array that can be obtained.
- **Example:** `Output: [1,3,5,8,9]`
- **Constraints:**
	- The output array must be lexicographically smallest.

{{< dots >}}
### Core Logic 🔍
**Goal:** We need to determine the lexicographically smallest array by swapping elements based on the given limit.

- Sort the elements of the array along with their indices.
- Group the elements that can be swapped (i.e., those whose absolute difference is less than or equal to the limit).
- Sort each group of swappable elements and place them back into their original indices.
{{< dots >}}
### Problem Assumptions ✅
- The operation is performed as many times as possible.
- The operation only applies when the absolute difference between two numbers is less than or equal to `limit`.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [1, 5, 3, 9, 8], limit = 2`  \
  **Explanation:** After sorting and applying the allowed swaps, we achieve the lexicographically smallest array [1, 3, 5, 8, 9].

- **Input:** `nums = [1, 7, 6, 18, 2, 1], limit = 3`  \
  **Explanation:** By swapping elements where the difference is within the limit, the array becomes [1, 6, 7, 18, 1, 2].

{{< dots >}}
## Approach 🚀
The approach involves sorting the array, identifying groups of elements that can be swapped, and then sorting those groups individually to achieve the lexicographically smallest array.

### Initial Thoughts 💭
- Sorting the array will help us group the elements that can be swapped.
- We need to identify swappable groups and ensure the elements within each group are sorted to achieve the lexicographically smallest result.
{{< dots >}}
### Edge Cases 🌐
- An empty input array (nums.length == 0) should return an empty array.
- For very large inputs, the algorithm should run efficiently within the time limits.
- When all elements are equal, no swaps can be performed, and the input is already the lexicographically smallest array.
- Ensure the algorithm works within the problem's constraints (time complexity must be O(n log n) or better).
{{< dots >}}
## Code 💻
```cpp
vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    vector<pair<int, int>> b;
    int n = nums.size();

    for (int i = 0; i < n; ++i)
        b.push_back(make_pair(nums[i], i));

    sort(b.begin(), b.end(), [](const auto& x, const auto& y) {
        return x.first < y.first;
    });
    vector<vector<pair<int, int>>> c = {{b[0]}};

    for (int i = 1; i < n; ++i) {
        if (b[i].first - b[i - 1].first <= limit)
            c.back().push_back(b[i]);
        else
            c.push_back({b[i]});
    }

    // internal sorting
    for (const auto& t : c) {
        vector<int> ind;
        for (const auto& p : t)
            ind.push_back(p.second);

        sort(ind.begin(), ind.end());

        for (int i = 0; i < ind.size(); ++i)
            nums[ind[i]] = t[i].first;
    }
    return nums;
}
```

This function sorts the array 'nums' in lexicographically smallest order based on the given limit between adjacent elements. It groups elements with a difference less than or equal to the limit and then sorts the elements within those groups to achieve the final result.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
	```
	Defines the function 'lexicographicallySmallestArray' which takes a reference to a vector 'nums' and an integer 'limit'. The function will return the lexicographically smallest array with specific sorting conditions.

2. **Pair Initialization**
	```cpp
	    vector<pair<int, int>> b;
	```
	Initializes a vector 'b' of pairs where each pair will store an integer from the 'nums' array and its corresponding index. This helps track the original positions of elements after sorting.

3. **Array Size**
	```cpp
	    int n = nums.size();
	```
	Stores the size of the 'nums' array in variable 'n'. This value will be used to control loop iterations.

4. **Push Elements into Pair Vector**
	```cpp
	    for (int i = 0; i < n; ++i)
	```
	Starts a loop to iterate through the 'nums' array and creates pairs of each element along with its index, storing them in the 'b' vector.

5. **Pair Push Back**
	```cpp
	        b.push_back(make_pair(nums[i], i));
	```
	Creates a pair consisting of the current element from 'nums' and its index, then adds the pair to the 'b' vector.

6. **Sorting Step 1**
	```cpp
	    sort(b.begin(), b.end(), [](const auto& x, const auto& y) {
	```
	Sorts the vector 'b' of pairs based on the first element of each pair (the number in 'nums'). The sorting is done in ascending order.

7. **Sorting Condition**
	```cpp
	        return x.first < y.first;
	```
	Defines the sorting condition for the lambda function: sort pairs in 'b' by the integer values (the first element of the pair).

8. **Group Initialization**
	```cpp
	    vector<vector<pair<int, int>>> c = {{b[0]}};
	```
	Initializes a 2D vector 'c' to store groups of elements. The first group is initialized with the first pair from 'b'. Each group will hold elements that are close enough (difference less than or equal to 'limit').

9. **Group Formation Loop**
	```cpp
	    for (int i = 1; i < n; ++i) {
	```
	Starts a loop to iterate through the sorted pairs in 'b' and groups them based on the difference between adjacent elements.

10. **Group Condition**
	```cpp
	        if (b[i].first - b[i - 1].first <= limit)
	```
	Checks if the difference between the current element 'b[i]' and the previous one 'b[i-1]' is less than or equal to the 'limit'. If true, the current element is added to the last group.

11. **Add to Last Group**
	```cpp
	            c.back().push_back(b[i]);
	```
	Adds the current element 'b[i]' to the last group in 'c' (the most recent group formed).

12. **Start New Group**
	```cpp
	        else
	```
	If the difference between elements exceeds the 'limit', start a new group.

13. **Push New Group**
	```cpp
	            c.push_back({b[i]});
	```
	Starts a new group by adding the current pair 'b[i]' as the first element of the new group in 'c'.

14. **Sort Groups by Indices**
	```cpp
	    for (const auto& t : c) {
	```
	Iterates through each group 't' in 'c' to perform internal sorting.

15. **Index Extraction**
	```cpp
	        vector<int> ind;
	```
	Initializes a vector 'ind' to store the indices of the elements in the current group.

16. **Index Extraction Loop**
	```cpp
	        for (const auto& p : t)
	```
	Iterates through each pair 'p' in the group 't' to extract the indices and store them in 'ind'.

17. **Push Index to Vector**
	```cpp
	            ind.push_back(p.second);
	```
	Pushes the index from the current pair 'p' into the 'ind' vector.

18. **Sort Indices**
	```cpp
	        sort(ind.begin(), ind.end());
	```
	Sorts the indices in 'ind' in ascending order, so the elements can be rearranged back in their lexicographically smallest order.

19. **Rearrange Elements**
	```cpp
	        for (int i = 0; i < ind.size(); ++i)
	```
	Starts a loop to rearrange elements in 'nums' based on the sorted indices in 'ind'.

20. **Update Original Array**
	```cpp
	            nums[ind[i]] = t[i].first;
	```
	Updates the 'nums' array at index 'ind[i]' with the corresponding value from the sorted group 't'.

21. **Return Sorted Array**
	```cpp
	    return nums;
	```
	Returns the final sorted array 'nums' after rearranging all the elements.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n) for sorting the array and processing groups.
- **Average Case:** O(n log n), the time complexity of sorting and grouping.
- **Worst Case:** O(n log n), when sorting and processing all elements.

The time complexity is dominated by the sorting steps.

### Space Complexity 💾
- **Best Case:** O(n) when no swaps are needed and we just return the sorted array.
- **Worst Case:** O(n) for storing the groups of elements.

The space complexity is primarily due to storing the array and its indices.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/description/)

---
{{< youtube r0981xS7CjY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
