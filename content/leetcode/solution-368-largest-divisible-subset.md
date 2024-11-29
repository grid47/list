
+++
authors = ["grid47"]
title = "Leetcode 368: Largest Divisible Subset"
date = "2024-10-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 368: Largest Divisible Subset in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/368.webp"
youtube = "wB-B8tVXaGU"
youtube_upload_date="2020-06-13"
youtube_thumbnail="https://i.ytimg.com/vi/wB-B8tVXaGU/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/368.webp" 
    alt="A sequence of numbers with the largest divisible subset glowing, showing the optimal group."
    caption="Solution to LeetCode 368: Largest Divisible Subset Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a set of distinct positive integers. Return the largest subset where every pair of elements in the subset satisfies either 'one element is divisible by the other'.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of distinct positive integers.
- **Example:** `nums = [1, 3, 5]`
- **Constraints:**
	- 1 <= nums.length <= 1000
	- 1 <= nums[i] <= 2 * 10^9
	- All elements of nums are distinct.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the largest subset such that for every pair of elements in the subset, one element is divisible by the other.
- **Example:** `Input: nums = [1, 3, 5]
Output: [1, 3]`
- **Constraints:**
	- The output should be a valid subset with the largest size.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the largest subset where every pair of elements satisfies the divisibility condition.

- 1. Sort the input array in increasing order.
- 2. Use dynamic programming to calculate the largest subset for each element, checking if it can be part of a divisible chain.
- 3. Find the element that results in the largest subset and reconstruct the subset from it.
{{< dots >}}
### Problem Assumptions ✅
- All elements in the input list are distinct and positive.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1, 3, 5]
Output: [1, 3]`  \
  **Explanation:** The subset [1, 3] is valid because 3 is divisible by 1, and this subset is the largest possible subset that satisfies the condition.

{{< dots >}}
## Approach 🚀
The approach uses dynamic programming to track the largest divisible subset by checking divisibility between elements.

### Initial Thoughts 💭
- Sorting the array helps in checking divisibility from smaller to larger elements.
- A dynamic programming approach can efficiently track the largest divisible subset.
- We will use dynamic programming to build subsets while checking the divisibility property between elements.
{{< dots >}}
### Edge Cases 🌐
- An empty input array should return an empty output.
- Ensure the solution handles up to 1000 integers efficiently.
- Handle cases where the subset has only one element.
- The solution should respect the given constraints on input size and element values.
{{< dots >}}
## Code 💻
```cpp
vector<int> largestDivisibleSubset(vector<int>& nums) {
    if(nums.size() == 0) return nums;

    sort(nums.begin(), nums.end()); 

    int n = nums.size();       
    vector<vector<int>> dp(n, vector<int>(2, 0));
    
    for(int i = n - 1; i >= 0; i--) {
        dp[i][0] = 0;
        dp[i][1] = i;
        for(int j = i + 1; j < n; j++) {
            if((nums[j] % nums[i]) == 0) {
                if(dp[i][0] < dp[j][0]) {
                    dp[i][0] = dp[j][0];
                    dp[i][1] = j;
                }
            }
        }
        dp[i][0]++;
    }

    int mx = 0, mxi = 0;
    for(int i = 0; i < n; i++) {
        if(mx <= dp[i][0]) {
            mxi = i;
            mx = dp[i][0];
        }
    }

    vector<int> ans;
    int i = mxi;
    ans.push_back(nums[i]);
    while(dp[i][1] != i) {
        i = dp[i][1];
        ans.push_back(nums[i]);
    }
    
    return ans;
}
```

The `largestDivisibleSubset` function finds the largest subset of a list of integers where each number is divisible by at least one other number in the subset. It uses dynamic programming to track the largest subset ending at each element.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method Declaration**
	```cpp
	vector<int> largestDivisibleSubset(vector<int>& nums) {
	```
	This line declares the method `largestDivisibleSubset`, which takes a vector of integers `nums` and returns a vector of integers representing the largest divisible subset.

2. **Edge Case Check**
	```cpp
	    if(nums.size() == 0) return nums;
	```
	Checks if the input list `nums` is empty. If it is, the method returns the empty list immediately.

3. **Sorting**
	```cpp
	    sort(nums.begin(), nums.end()); 
	```
	Sorts the vector `nums` in ascending order to facilitate the identification of divisible subsets.

4. **Variable Declaration**
	```cpp
	    int n = nums.size();       
	```
	Declares an integer `n` to store the size of the `nums` vector.

5. **Dynamic Programming Table Initialization**
	```cpp
	    vector<vector<int>> dp(n, vector<int>(2, 0));
	```
	Initializes a dynamic programming table `dp` with dimensions `n x 2`. The first column (`dp[i][0]`) stores the size of the largest subset ending at index `i`, and the second column (`dp[i][1]`) stores the index of the previous element in the subset.

6. **Outer Loop**
	```cpp
	    for(int i = n - 1; i >= 0; i--) {
	```
	Starts an outer loop to iterate over each element of `nums` in reverse order.

7. **Initialization in Loop**
	```cpp
	        dp[i][0] = 0;
	```
	Initializes the subset size for the current element to `0`.

8. **Initialization in Loop**
	```cpp
	        dp[i][1] = i;
	```
	Sets the previous element index to `i` (itself) for the current element.

9. **Inner Loop**
	```cpp
	        for(int j = i + 1; j < n; j++) {
	```
	Starts an inner loop to compare the current element with all subsequent elements.

10. **Divisibility Check**
	```cpp
	            if((nums[j] % nums[i]) == 0) {
	```
	Checks if the `j`-th element is divisible by the `i`-th element. If true, they can form a divisible subset.

11. **Updating DP Table**
	```cpp
	                if(dp[i][0] < dp[j][0]) {
	```
	Compares the subset size at index `i` with the subset size at index `j`. If the subset at `j` is larger, it updates the `i`-th subset size.

12. **Updating DP Table**
	```cpp
	                    dp[i][0] = dp[j][0];
	```
	Updates the `i`-th subset size to be the same as the `j`-th subset size.

13. **Updating DP Table**
	```cpp
	                    dp[i][1] = j;
	```
	Updates the previous element index for the `i`-th element to point to `j`.

14. **End of Divisibility Check**
	```cpp
	                }
	```
	Closes the condition for checking divisibility.

15. **Increment Subset Size**
	```cpp
	        dp[i][0]++;
	```
	Increments the size of the subset ending at index `i`.

16. **Max Subset Search**
	```cpp
	    int mx = 0, mxi = 0;
	```
	Declares variables `mx` to track the maximum subset size and `mxi` to track the index of the element that starts the largest subset.

17. **Finding Max Subset**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Iterates through the `dp` table to find the largest subset.

18. **Max Subset Check**
	```cpp
	        if(mx <= dp[i][0]) {
	```
	Compares the current subset size with the maximum subset size found so far.

19. **Max Subset Update**
	```cpp
	            mxi = i;
	```
	Updates `mxi` to the current index `i` if the subset size is larger than the previously found maximum.

20. **Max Subset Update**
	```cpp
	            mx = dp[i][0];
	```
	Updates the maximum subset size to the current subset size.

21. **Subset Construction**
	```cpp
	    vector<int> ans;
	```
	Declares a vector `ans` to store the elements of the largest divisible subset.

22. **Starting Subset**
	```cpp
	    int i = mxi;
	```
	Sets `i` to the index of the largest subset.

23. **Adding Elements**
	```cpp
	    ans.push_back(nums[i]);
	```
	Adds the element at index `i` to the result vector `ans`.

24. **Loop Through Subset**
	```cpp
	    while(dp[i][1] != i) {
	```
	Loops through the `dp` table to trace the elements of the largest subset.

25. **Adding Elements**
	```cpp
	        i = dp[i][1];
	```
	Updates `i` to the previous element in the largest subset.

26. **Adding Elements**
	```cpp
	        ans.push_back(nums[i]);
	```
	Adds the element at index `i` to the result vector `ans`.

27. **Return Result**
	```cpp
	    return ans;
	```
	Returns the constructed largest divisible subset.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n) due to the sorting step.
- **Average Case:** O(n^2) due to dynamic programming checks for each element.
- **Worst Case:** O(n^2) as we check divisibility for every pair.

The time complexity is dominated by the sorting and dynamic programming steps.

### Space Complexity 💾
- **Best Case:** O(n) as we store the results in the table.
- **Worst Case:** O(n) for the dynamic programming table and result storage.

The space complexity is linear with respect to the size of the input array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/largest-divisible-subset/description/)

---
{{< youtube wB-B8tVXaGU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
