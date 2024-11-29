
+++
authors = ["grid47"]
title = "Leetcode 2560: House Robber IV"
date = "2024-02-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2560: House Robber IV in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "BJWTAclDvEA"
youtube_upload_date="2023-02-05"
youtube_thumbnail="https://i.ytimg.com/vi/BJWTAclDvEA/maxresdefault.jpg"
comments = true
+++



---
A robber is tasked with stealing money from houses lined along a street. Each house has a certain amount of money, but the robber refuses to rob adjacent houses. The robber must steal from at least 'k' houses. Your goal is to determine the minimum amount of money the robber will steal from any house, out of all the possible ways of selecting at least 'k' houses, given the constraints.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array 'nums' where each element represents the amount of money in the corresponding house. The second input is an integer 'k', representing the minimum number of houses the robber will steal from.
- **Example:** `Input: nums = [1, 2, 3, 4, 5], k = 3`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^9
	- 1 <= k <= (nums.length + 1)/2

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum capability, which is the least maximum amount of money the robber steals from any of the houses he robs.
- **Example:** `Output: 3`
- **Constraints:**
	- The result will always be a positive integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the maximum amount of money the robber steals while robbing at least 'k' houses.

- First, define the minimum and maximum possible capabilities for the robber.
- Use binary search to determine the optimal maximum capability while ensuring the robber can rob at least 'k' houses.
- Implement a helper function to check if a particular capability allows the robber to rob at least 'k' houses.
{{< dots >}}
### Problem Assumptions ✅
- It is always possible to rob at least 'k' houses.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: nums = [2, 3, 5, 9], k = 2`  \
  **Explanation:** In this example, the robber has three ways to rob two houses: (0, 2), (0, 3), and (1, 3). The corresponding maximum values of the money stolen are 5, 9, and 9. Therefore, the minimum capability is 5.

- **Input:** `Example 2: nums = [2, 7, 9, 3, 1], k = 2`  \
  **Explanation:** In this example, the robber can rob two houses with the minimum capability being 2, by robbing houses at index 0 and 4.

{{< dots >}}
## Approach 🚀
The problem can be solved by binary searching on the possible capabilities, while using a greedy strategy to check if a certain capability allows for robbing at least 'k' houses.

### Initial Thoughts 💭
- We need to find a way to minimize the maximum value that the robber can steal from a house, given the constraint of robbing at least 'k' houses.
- Binary search can be used to efficiently find the minimum maximum capability, as the solution space is bounded by the minimum and maximum values in the array.
{{< dots >}}
### Edge Cases 🌐
- If the input array is empty, the problem is invalid, as no houses exist.
- For large inputs, binary search ensures that the solution is efficient.
- If 'k' equals half the size of the array or more, the solution must still ensure that the robber steals only from non-adjacent houses.
- Handle arrays with both small and large numbers of houses efficiently.
{{< dots >}}
## Code 💻
```cpp

int n;
vector<int> nums;
vector<vector<vector<map<int, int>>>> memo;

int dp(int idx, int k, bool prv, int mx) {
    if(idx == n) return (k > 0)? INT_MAX: mx;
    
    if(memo[idx][k][prv].count(mx)) return memo[idx][k][prv][mx];
    
    int ans = dp(idx + 1, k, false, mx);
    
    if(!prv) {
        int tmp = dp(idx + 1, k - 1 < 1? 0: k-1, true, mx == 0? nums[idx]: (mx > nums[idx]) ? mx: nums[idx]);
        ans = min(ans, tmp);            
    }

    return memo[idx][k][prv][mx] = ans;
}

int minCap(vector<int>& nums, int k) {
    this->nums = nums;
    n = nums.size();
    memo.resize(n, vector<vector<map<int, int>>>(n + 1, vector<map<int,int>>(2)));
    return dp(0, k, false, 0);
}

bool can(vector<int> &nums, int k, int mid) {
    int n = nums.size();
    int cnt = 0, take = true;
    for(int i = 0; i < n; i += 1) {
        if(nums[i] <= mid && take) {
            take = false;
            cnt++;
        } else if(!take) {
            take = true;
        }
        if(cnt >= k) return true;
    }
    cnt = 0, take = true;
    for(int i = 1; i < n; i += 2) {
        if(nums[i] <= mid && take) {
            take = false;
            cnt++;
        } else if(!take) {
            take = true;
        }
        if(cnt >= k) return true;
    }        
    return false;
}

int minCapability(vector<int>& nums, int k) {
    
    int mx = *max_element(nums.begin(), nums.end());
    int mn = *min_element(nums.begin(), nums.end());
    int l = mn, r = mx, ans = mx;
    while(l <= r) {
        int mid = l + (r - l + 1) / 2;
        // cout << mid << " " << can(nums, k, mid) << "\n";
        if(can(nums, k, mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return ans;
}
```

This code defines a dynamic programming approach to solve a problem involving arrays and binary search to minimize the largest element in a set of partitions. The solution uses memoization and efficient checks to determine the minimum capability required.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int n;
	```
	The variable `n` is used to store the size of the input array `nums`.

2. **Vector Declaration**
	```cpp
	vector<int> nums;
	```
	A vector `nums` is declared to store the input values that the algorithm will work with.

3. **Memoization**
	```cpp
	vector<vector<vector<map<int, int>>>> memo;
	```
	A 3D memoization table is initialized to store intermediate results during the dynamic programming process, helping avoid redundant calculations.

4. **Function Declaration**
	```cpp
	int dp(int idx, int k, bool prv, int mx) {
	```
	This function defines a recursive dynamic programming approach to solve the problem, where `idx` is the current index, `k` represents remaining partitions, `prv` tracks if the previous element was selected, and `mx` keeps the maximum element in the current partition.

5. **Base Case**
	```cpp
	    if(idx == n) return (k > 0)? INT_MAX: mx;
	```
	Base case: If we've reached the end of the array, return the current max value or infinity if there are still partitions left to be made.

6. **Memoization Check**
	```cpp
	    if(memo[idx][k][prv].count(mx)) return memo[idx][k][prv][mx];
	```
	Memoization check: If the result for the current state is already calculated, return it to avoid redundant computation.

7. **Recursive Step**
	```cpp
	    int ans = dp(idx + 1, k, false, mx);
	```
	Recursive call to solve the problem by excluding the current element from the partition.

8. **Conditional Branch**
	```cpp
	    if(!prv) {
	```
	Conditional check to determine whether the previous element was included in the current partition.

9. **Recursive Step with Modification**
	```cpp
	        int tmp = dp(idx + 1, k - 1 < 1? 0: k-1, true, mx == 0? nums[idx]: (mx > nums[idx]) ? mx: nums[idx]);
	```
	If not the previous element, another recursive call is made, adjusting the value of `k` and `mx` to reflect the current partitioning logic.

10. **Update Minimum Result**
	```cpp
	        ans = min(ans, tmp);            
	```
	Update the minimum answer found so far between the current result and the recursive result.

11. **Memoization Storage**
	```cpp
	    return memo[idx][k][prv][mx] = ans;
	```
	Store the result of the current state in the memoization table to avoid redundant calculations in the future.

12. **Main Function Declaration**
	```cpp
	int minCap(vector<int>& nums, int k) {
	```
	Main function declaration which initializes necessary variables and sets up the memoization table before calling the dynamic programming function.

13. **Input Handling**
	```cpp
	    this->nums = nums;
	```
	Assign the input array to the class's `nums` variable.

14. **Size Calculation**
	```cpp
	    n = nums.size();
	```
	Calculate the size of the input array.

15. **Memoization Table Resize**
	```cpp
	    memo.resize(n, vector<vector<map<int, int>>>(n + 1, vector<map<int,int>>(2)));
	```
	Resize the memoization table to match the input array size.

16. **Call Dynamic Programming Function**
	```cpp
	    return dp(0, k, false, 0);
	```
	Call the dynamic programming function to compute the result.

17. **Binary Search Setup**
	```cpp
	int mx = *max_element(nums.begin(), nums.end());
	```
	Find the maximum element in the input array, as we will use it as the upper bound for binary search.

18. **Binary Search Main Loop**
	```cpp
	    int l = mn, r = mx, ans = mx;
	    while(l <= r) {
	        int mid = l + (r - l + 1) / 2;
	```
	Set up the binary search loop where `l` and `r` are the range, and `mid` is the current middle value.

19. **Check Feasibility**
	```cpp
	        if(can(nums, k, mid)) {
	            ans = mid;
	            r = mid - 1;
	        } else l = mid + 1;
	```
	Check if the mid value satisfies the condition and adjust the binary search range accordingly.

20. **Return Answer**
	```cpp
	    return ans;
	```
	Return the final answer after the binary search has completed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log m), where n is the number of houses and m is the maximum value in the 'nums' array.
- **Average Case:** O(n log m), due to the binary search and checking each house.
- **Worst Case:** O(n log m), as the binary search goes through all possible values of the capability.

The time complexity is determined by the binary search and the checking of each house for each potential capability.

### Space Complexity 💾
- **Best Case:** O(n), as space usage is dominated by the input size and intermediate calculations.
- **Worst Case:** O(n), where n is the size of the 'nums' array, due to the space used by the binary search and the helper function.

The space complexity is O(n) because the solution stores intermediate results while performing the binary search.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/house-robber-iv/description/)

---
{{< youtube BJWTAclDvEA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
