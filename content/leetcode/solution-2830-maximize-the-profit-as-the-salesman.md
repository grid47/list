
+++
authors = ["grid47"]
title = "Leetcode 2830: Maximize the Profit as the Salesman"
date = "2024-01-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2830: Maximize the Profit as the Salesman in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Dynamic Programming","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "lrZM1nLXcmc"
youtube_upload_date="2023-08-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/lrZM1nLXcmc/maxresdefault.webp"
comments = true
+++



---
You are a salesman with `n` houses placed on a number line, numbered from 0 to `n-1`. You are given a list of offers where each offer is of the form `[start, end, gold]`, indicating that a buyer wants to purchase all houses from index `start` to `end` (inclusive) for `gold` amount of gold. Your task is to maximize your total earnings by strategically selecting offers such that no two buyers purchase the same house.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer `n` and a list of offers. Each offer is a list of three integers `[start, end, gold]` representing a buyer's request to purchase the houses in the range `[start, end]` for `gold` amount of gold.
- **Example:** `For example, `n = 6, offers = [[0, 0, 1], [1, 3, 2], [2, 4, 2]]`.`
- **Constraints:**
	- 1 <= n <= 10^5
	- 1 <= offers.length <= 10^5
	- 0 <= start <= end <= n - 1
	- 1 <= gold <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum amount of gold that can be earned by strategically selling houses to buyers.
- **Example:** `For `n = 6, offers = [[0, 0, 1], [1, 3, 2], [2, 4, 2]]`, the output should be `4`.`
- **Constraints:**
	- The solution must avoid modifying the offers and cannot allow overlapping purchases from buyers.

{{< dots >}}
### Core Logic 🔍
**Goal:** Maximize the total gold earned by strategically selecting offers.

- Sort the offers based on the end index of the range.
- Use dynamic programming to select the best offers. For each offer, check if its range can be included without overlap with previous selections.
- For each offer, compute the maximum gold that can be earned by including that offer and the maximum gold from previously selected offers.
{{< dots >}}
### Problem Assumptions ✅
- Each buyer can only buy a continuous range of houses.
- Overlapping offers should not be selected simultaneously.
{{< dots >}}
## Examples 🧩
- **Input:** `For `n = 6, offers = [[0, 0, 1], [1, 3, 2], [2, 4, 2]]``  \
  **Explanation:** You can sell the house at index 0 to the first buyer for 1 gold, then sell the houses from index 1 to index 3 to the second buyer for 2 gold. This gives a total of 3 gold. To achieve the maximum gold, sell houses from index 0 to index 0 for 1 gold and houses from index 1 to index 3 for 2 gold, for a total of 4 gold.

{{< dots >}}
## Approach 🚀
We can solve this problem using dynamic programming. We will first sort the offers based on their end index and then use dynamic programming to select the offers that maximize our total gold.

### Initial Thoughts 💭
- This problem resembles a job scheduling problem with intervals and weights (gold).
- We can use binary search to efficiently find non-overlapping offers and maximize the total gold.
{{< dots >}}
### Edge Cases 🌐
- An empty array of offers would return a result of 0 gold.
- The solution should handle up to 100,000 offers efficiently.
- All offers may be for the same range, in which case only one offer can be selected.
- Ensure that the solution works efficiently with large input sizes.
{{< dots >}}
## Code 💻
```cpp

int n;
vector<int> mem;
vector<vector<int>> nums;

int bs(int x) {
    int ans = n;
    int l = 0, r = n - 1;
    while(l <= r) {
        int mid = l + (r - l + 1) / 2;
        if(nums[mid][0] > x) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return ans;
}

int dp(int idx) {
    // cout << n;
    if(idx >= n) return 0;
    
    if(mem[idx] != -1) return mem[idx];
    
    int ans = dp(idx + 1);
    
    int nxt = bs(nums[idx][1]);
    // cout << nxt;

    ans = max(ans, dp(nxt) + nums[idx][2]);
    
    return mem[idx] = ans;
}

int maximizeTheProfit(int x, vector<vector<int>>& nums) {
    n = nums.size();
    mem.resize(n, -1);
    sort(nums.begin(), nums.end());
    this->nums = nums;
    return dp(0);
}
```

This is the code implementation of the problem, which involves using dynamic programming and binary search to maximize the profit. The function `maximizeTheProfit` computes the optimal solution by iterating over tasks and using a binary search to find the next possible task to include in the solution.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int n;
	```
	Declaring an integer variable `n` to store the size of the input list `nums`.

2. **Variable Initialization**
	```cpp
	vector<int> mem;
	```
	Declaring a vector `mem` to store the memoization results of the dynamic programming function `dp`.

3. **Variable Initialization**
	```cpp
	vector<vector<int>> nums;
	```
	Declaring a 2D vector `nums` to store the input data for the tasks, where each task is represented by a vector of three integers.

4. **Binary Search Function**
	```cpp
	int bs(int x) {
	```
	Defining the binary search function `bs` that finds the appropriate index based on the input value `x`.

5. **Binary Search Logic**
	```cpp
	    int ans = n;
	```
	Initializing `ans` to `n`, representing the upper limit of the binary search range.

6. **Binary Search Logic**
	```cpp
	    int l = 0, r = n - 1;
	```
	Initializing `l` and `r` as the left and right bounds of the binary search.

7. **Binary Search Loop**
	```cpp
	    while(l <= r) {
	```
	Starting the binary search loop to find the correct index.

8. **Binary Search Loop**
	```cpp
	        int mid = l + (r - l + 1) / 2;
	```
	Calculating the middle index `mid` for binary search.

9. **Binary Search Comparison**
	```cpp
	        if(nums[mid][0] > x) {
	```
	If the value at `nums[mid][0]` is greater than `x`, update the `ans` and adjust the right bound `r`.

10. **Binary Search Comparison**
	```cpp
	            ans = mid;
	```
	Update the `ans` variable with the current middle index.

11. **Binary Search Comparison**
	```cpp
	            r = mid - 1;
	```
	Update the right bound `r` to narrow down the search.

12. **Binary Search Comparison**
	```cpp
	        } else l = mid + 1;
	```
	If the value is not greater, adjust the left bound `l` to continue the search.

13. **Binary Search Conclusion**
	```cpp
	    return ans;
	```
	Return the result of the binary search, which is the appropriate index.

14. **Dynamic Programming Function**
	```cpp
	int dp(int idx) {
	```
	Defining the dynamic programming function `dp`, which calculates the maximum profit from the given index `idx`.

15. **Base Case in DP**
	```cpp
	    if(idx >= n) return 0;
	```
	Base case for the recursion: if the index exceeds or equals `n`, return 0.

16. **Memoization Check**
	```cpp
	    if(mem[idx] != -1) return mem[idx];
	```
	Check if the result for this index is already computed and stored in `mem`. If so, return the stored result.

17. **Recursive Case**
	```cpp
	    int ans = dp(idx + 1);
	```
	Recursive call to `dp` for the next index, which represents the scenario where the current task is not selected.

18. **Next Task Search**
	```cpp
	    int nxt = bs(nums[idx][1]);
	```
	Call the binary search function to find the next task that can be included after selecting the current task.

19. **Recursive Case**
	```cpp
	    ans = max(ans, dp(nxt) + nums[idx][2]);
	```
	Recursively compute the maximum profit by including the current task, adding its profit to the result from the next possible task.

20. **Memoization Update**
	```cpp
	    return mem[idx] = ans;
	```
	Store the computed result in `mem` for the current index `idx` and return the result.

21. **Main Function Start**
	```cpp
	int maximizeTheProfit(int x, vector<vector<int>>& nums) {
	```
	Defining the main function `maximizeTheProfit`, which initializes the necessary variables and starts the computation.

22. **Initialization**
	```cpp
	    n = nums.size();
	```
	Initialize `n` to be the size of the input `nums` vector.

23. **Memoization Setup**
	```cpp
	    mem.resize(n, -1);
	```
	Resize the `mem` vector to store results for each task, initializing all values to `-1` (indicating no result computed yet).

24. **Sorting**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	Sort the tasks in ascending order based on the task start times.

25. **Calling DP Function**
	```cpp
	    return dp(0);
	```
	Call the `dp` function starting from index 0, and return the computed maximum profit.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The solution involves sorting the offers and performing binary search for each offer, resulting in a time complexity of O(n log n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the dynamic programming table and storage for the sorted offers.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximize-the-profit-as-the-salesman/description/)

---
{{< youtube lrZM1nLXcmc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
