
+++
authors = ["grid47"]
title = "Leetcode 698: Partition to K Equal Sum Subsets"
date = "2024-08-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 698: Partition to K Equal Sum Subsets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Backtracking","Bit Manipulation","Memoization","Bitmask"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/698.webp"
youtube = "mBk4I0X46oI"
youtube_upload_date="2021-10-30"
youtube_thumbnail="https://i.ytimg.com/vi/mBk4I0X46oI/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/698.webp" 
    alt="A set of numbers where they are partitioned into equal sum subsets, with each valid partition softly glowing."
    caption="Solution to LeetCode 698: Partition to K Equal Sum Subsets Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer array nums and an integer k, your task is to determine if it is possible to divide this array into k non-empty subsets such that each subset has an equal sum.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are provided with an integer array nums and an integer k.
- **Example:** `nums = [5, 2, 4, 6], k = 3`
- **Constraints:**
	- 1 <= k <= nums.length <= 16
	- 1 <= nums[i] <= 104
	- Each element in nums occurs between 1 and 4 times.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if it is possible to partition the array into k subsets with equal sums, otherwise return false.
- **Example:** `Output: false`
- **Constraints:**
	- The result should be a boolean value.

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine if it is possible to partition the array into k subsets with equal sums.

- Calculate the total sum of the elements in the array.
- If the total sum is not divisible by k, return false.
- Determine the subset sum, which is the total sum divided by k.
- Use backtracking to try to form k subsets, each having the sum equal to the subset sum.
{{< dots >}}
### Problem Assumptions ✅
- You can use each element of the array exactly once.
- All elements are non-negative integers.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [5, 2, 4, 6], k = 3`  \
  **Explanation:** It's not possible to partition the array into 3 subsets with equal sums. The total sum is 17, which is not divisible by 3.

{{< dots >}}
## Approach 🚀
We use backtracking to explore different ways of dividing the array into subsets and check if the sum of each subset equals the required subset sum.

### Initial Thoughts 💭
- If the total sum is not divisible by k, it's impossible to divide the array into subsets with equal sums.
- Backtracking will help us find a combination of subsets that satisfy the sum condition.
{{< dots >}}
### Edge Cases 🌐
- Empty input arrays are not possible, as the constraints guarantee that nums.length >= 1.
- For large inputs, we may need to optimize backtracking or consider dynamic programming techniques to avoid excessive computation.
- If all elements in the array are the same and k is 1, it's always possible to partition.
- The array size is small (up to 16), which allows for backtracking solutions.
{{< dots >}}
## Code 💻
```cpp
    bool canPartitionKSubsets(vector<int>& nums, int K) {
    int N = nums.size();
    if (K == 1) return true;
    if (N < K) return false;
    int sum = 0;
    for (int i = 0; i < N; i++) sum += nums[i];
    if (sum % K != 0) return false;

    int subset = sum / K;
    int subsetSum[K];
    bool taken[N];

    for (int i = 0; i < K; i++) subsetSum[i] = 0;
    for (int i = 0; i < N; i++) taken[i] = false;

    subsetSum[0] = nums[N - 1];
    taken[N - 1] = true;

    return canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, 0, N - 1);
}

bool canPartitionKSubsets(vector<int>& nums, int subsetSum[], bool taken[], int subset, int K, int N, int curIdx, int limitIdx) {
    if (subsetSum[curIdx] == subset) {
        if (curIdx == K - 2) return true;
        return canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, curIdx + 1, N - 1);
    }

    for (int i = limitIdx; i >= 0; i--) {
        if (taken[i]) continue;
        int tmp = subsetSum[curIdx] + nums[i];

        if (tmp <= subset) {
            taken[i] = true;
            subsetSum[curIdx] += nums[i];
            bool nxt = canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, curIdx, i - 1);
            taken[i] = false;
            subsetSum[curIdx] -= nums[i];
            if (nxt) return true;
        }
    }
    return false;
}
```

The code implements a backtracking solution to the K-Partition Problem, where the goal is to partition an array into K subsets such that each subset has equal sum. The function uses dynamic programming and recursion to explore all possible subsets and checks for valid partitions.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	    bool canPartitionKSubsets(vector<int>& nums, int K) {
	```
	Define the main function to check if the array can be partitioned into K subsets with equal sum.

2. **Variable Initialization**
	```cpp
	    int N = nums.size();
	```
	Store the size of the input array 'nums'.

3. **Conditional Check**
	```cpp
	    if (K == 1) return true;
	```
	If K equals 1, return true as any array can be partitioned into 1 subset.

4. **Boundary Check**
	```cpp
	    if (N < K) return false;
	```
	If the number of elements is less than K, return false as it's not possible to partition.

5. **Sum Calculation**
	```cpp
	    int sum = 0;
	```
	Initialize a variable 'sum' to store the total sum of elements in the array.

6. **Sum Loop**
	```cpp
	    for (int i = 0; i < N; i++) sum += nums[i];
	```
	Loop through the array and calculate the total sum of elements.

7. **Divisibility Check**
	```cpp
	    if (sum % K != 0) return false;
	```
	Check if the total sum is divisible by K. If not, return false as partitioning is not possible.

8. **Partition Size Calculation**
	```cpp
	    int subset = sum / K;
	```
	Calculate the target sum for each subset.

9. **Array Initialization**
	```cpp
	    int subsetSum[K];
	```
	Initialize an array 'subsetSum' to store the current sum of each subset.

10. **Boolean Array Initialization**
	```cpp
	    bool taken[N];
	```
	Initialize an array 'taken' to track which elements are already included in subsets.

11. **Subset Sum Initialization**
	```cpp
	    for (int i = 0; i < K; i++) subsetSum[i] = 0;
	```
	Initialize all elements of 'subsetSum' to 0.

12. **Taken Array Initialization**
	```cpp
	    for (int i = 0; i < N; i++) taken[i] = false;
	```
	Initialize all elements of 'taken' to false, indicating no element has been selected.

13. **First Element Assignment**
	```cpp
	    subsetSum[0] = nums[N - 1];
	```
	Assign the last element of 'nums' to the first subset sum.

14. **Taken Array Update**
	```cpp
	    taken[N - 1] = true;
	```
	Mark the last element as taken.

15. **Recursive Call**
	```cpp
	    return canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, 0, N - 1);
	```
	Call the recursive function to try partitioning the remaining elements into subsets.

16. **Function End**
	```cpp
	}
	```
	End of the function definition.

17. **Recursive Function Definition**
	```cpp
	bool canPartitionKSubsets(vector<int>& nums, int subsetSum[], bool taken[], int subset, int K, int N, int curIdx, int limitIdx) {
	```
	Define the helper function that recursively attempts to partition the array into K subsets.

18. **Subset Match Check**
	```cpp
	    if (subsetSum[curIdx] == subset) {
	```
	Check if the current subset has reached the target sum.

19. **Recursive Case**
	```cpp
	        if (curIdx == K - 2) return true;
	```
	If the second last subset is valid, return true indicating success.

20. **Recursive Call**
	```cpp
	        return canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, curIdx + 1, N - 1);
	```
	Recurse to the next subset.

21. **End Subset Check**
	```cpp
	    }
	```
	End of the subset match check.

22. **Loop Through Remaining Elements**
	```cpp
	    for (int i = limitIdx; i >= 0; i--) {
	```
	Loop through the array from the current index to try adding each element to the subset.

23. **Element Skipped Check**
	```cpp
	        if (taken[i]) continue;
	```
	Skip if the element has already been taken.

24. **Subset Addition Check**
	```cpp
	        int tmp = subsetSum[curIdx] + nums[i];
	```
	Calculate the temporary sum if the current element is added to the subset.

25. **Subset Sum Condition**
	```cpp
	        if (tmp <= subset) {
	```
	Check if adding the element does not exceed the subset sum.

26. **Element Inclusion**
	```cpp
	            taken[i] = true;
	```
	Mark the element as taken.

27. **Subset Sum Update**
	```cpp
	            subsetSum[curIdx] += nums[i];
	```
	Update the sum of the current subset.

28. **Recursive Call**
	```cpp
	            bool nxt = canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, curIdx, i - 1);
	```
	Make the recursive call to attempt the next subset.

29. **Backtracking**
	```cpp
	            taken[i] = false;
	```
	Backtrack by marking the element as not taken.

30. **Subset Sum Decrease**
	```cpp
	            subsetSum[curIdx] -= nums[i];
	```
	Undo the change to the subset sum.

31. **Success Check**
	```cpp
	            if (nxt) return true;
	```
	If the recursive call succeeds, return true.

32. **Final Return**
	```cpp
	    return false;
	```
	End the function by returning false if no valid partitioning was found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(k) if the array can be immediately partitioned into equal subsets.
- **Average Case:** O(2^N), where N is the number of elements in the array, due to the backtracking search.
- **Worst Case:** O(2^N) for exploring all possible subsets.

The worst-case time complexity occurs due to the exponential search for valid subsets.

### Space Complexity 💾
- **Best Case:** O(N) for storing the state of the subsets and used elements.
- **Worst Case:** O(N) due to the space required for backtracking.

Space complexity depends on the number of subsets and the size of the array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/)

---
{{< youtube mBk4I0X46oI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
