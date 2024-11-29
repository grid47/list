
+++
authors = ["grid47"]
title = "Leetcode 2944: Minimum Number of Coins for Fruits"
date = "2024-01-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2944: Minimum Number of Coins for Fruits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Queue","Heap (Priority Queue)","Monotonic Queue"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "_Zt6ADHF8nE"
youtube_upload_date="2023-11-25"
youtube_thumbnail="https://i.ytimg.com/vi_webp/_Zt6ADHF8nE/maxresdefault.webp"
comments = true
+++



---
You are given a list of integers 'prices', where each element 'prices[i]' represents the cost to purchase the 'i'-th fruit. If you buy the 'i'-th fruit at prices[i] coins, you get all subsequent fruits for free. Your task is to determine the minimum number of coins required to purchase all the fruits.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of integers, 'prices', where each element represents the price to purchase that fruit.
- **Example:** `prices = [2, 5, 3]`
- **Constraints:**
	- 1 <= prices.length <= 1000
	- 1 <= prices[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of coins required to purchase all the fruits.
- **Example:** `For prices = [2, 5, 3], the output is 5.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the number of coins required to buy all the fruits while maximizing the rewards from purchasing fruits.

- Use dynamic programming (dp) to track the minimum coins needed to buy all the fruits.
- At each fruit, determine whether to buy it to get all subsequent fruits for free or skip it based on the cost of purchasing it.
{{< dots >}}
### Problem Assumptions ✅
- The prices array always has at least one element.
- Each price in the array is distinct and positive.
{{< dots >}}
## Examples 🧩
- **Input:** `prices = [2, 5, 3]`  \
  **Explanation:** The optimal strategy is to buy the first fruit for 2 coins and the second fruit for 5 coins, getting the third fruit for free. The total cost is 2 + 5 = 7.

- **Input:** `prices = [1, 8, 2, 3]`  \
  **Explanation:** By buying the first fruit for 1 coin and the third fruit for 2 coins, you get the second and fourth fruits for free, resulting in a total cost of 3.

{{< dots >}}
## Approach 🚀
The problem can be solved using dynamic programming, where at each fruit you decide whether to buy it based on the rewards it provides for subsequent fruits.

### Initial Thoughts 💭
- The dynamic programming approach tracks the cost of buying all fruits considering whether you buy a fruit or use a reward from a previous purchase.
- This problem is optimized by considering the cost at each fruit and how buying it minimizes the overall cost, including rewards from purchasing subsequent fruits.
{{< dots >}}
### Edge Cases 🌐
- The input prices array cannot be empty since the problem guarantees at least one fruit.
- Even though the prices array can be as large as 1000 elements, the problem is still manageable with dynamic programming.
- If all prices are equal, the optimal strategy may involve purchasing fruits based on their position in the array.
- The length of prices is manageable, but the size of individual prices can be quite large, so efficient algorithms are necessary.
{{< dots >}}
## Code 💻
```cpp
int minimumCoins(vector<int>& A) {
    int n = A.size();
    vector<int> dp(n + 1, 0);
    deque<int> q;
    for (int i = 0; i < n; i++) {
        while (!q.empty() && (q.front() + 1) * 2 < i + 1)
            q.pop_front();
        while (!q.empty() && dp[q.back()] + A[q.back()] >= dp[i] + A[i])
            q.pop_back();
        q.push_back(i);
        dp[i + 1] = dp[q.front()] + A[q.front()];
    }
    return dp[n];
}
```

This function solves the minimum coin problem by dynamically computing the minimal number of coins needed to reach each index, using a deque to optimize the solution. It keeps track of a dynamic programming array 'dp' and efficiently updates the result by popping and pushing indices into the deque based on conditions.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minimumCoins(vector<int>& A) {
	```
	Defines the function 'minimumCoins' that takes a vector 'A' of coin values and returns the minimum number of coins needed to achieve the desired total.

2. **Initialize Variables**
	```cpp
	    int n = A.size();
	```
	Initializes the variable 'n' to store the size of the input vector 'A', representing the number of available coins.

3. **Vector Initialization**
	```cpp
	    vector<int> dp(n + 1, 0);
	```
	Creates a dynamic programming array 'dp' with 'n + 1' elements, initialized to zero. 'dp[i]' will store the minimum number of coins needed for the amount 'i'.

4. **Deque Initialization**
	```cpp
	    deque<int> q;
	```
	Initializes a deque 'q' that will be used to efficiently manage indices of the 'dp' array during the dynamic programming process.

5. **Loop Initialization**
	```cpp
	    for (int i = 0; i < n; i++) {
	```
	Starts a loop that iterates over each coin in the vector 'A'.

6. **Pop Front of Deque**
	```cpp
	        while (!q.empty() && (q.front() + 1) * 2 < i + 1)
	```
	Checks if the front of the deque represents an index that is no longer relevant for computing the minimum number of coins. If so, it removes that index from the front.

7. **Pop Back of Deque**
	```cpp
	            q.pop_front();
	```
	Removes the front element from the deque, ensuring only relevant indices remain for the computation.

8. **Pop Back of Deque (Condition)**
	```cpp
	        while (!q.empty() && dp[q.back()] + A[q.back()] >= dp[i] + A[i])
	```
	Checks if the current coin value, combined with the previous best solution (stored in 'dp'), is better or worse than the existing solution. If the current solution is better, it pops elements from the back of the deque.

9. **Pop Back of Deque**
	```cpp
	            q.pop_back();
	```
	Removes the back element from the deque, as it represents a suboptimal solution compared to the current coin.

10. **Push Current Index to Deque**
	```cpp
	        q.push_back(i);
	```
	Adds the current index 'i' to the back of the deque to be considered for future iterations.

11. **Update DP Array**
	```cpp
	        dp[i + 1] = dp[q.front()] + A[q.front()];
	```
	Updates the dynamic programming array 'dp' by setting 'dp[i + 1]' to the minimum number of coins needed by taking the value from the front of the deque.

12. **Return Result**
	```cpp
	    return dp[n];
	```
	Returns the final result, which is the minimum number of coins needed to make the value 'n', stored in 'dp[n]'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear since we only iterate over the fruits once while updating the dynamic programming array.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of the dp array that tracks the minimum coins for each fruit.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-coins-for-fruits/description/)

---
{{< youtube _Zt6ADHF8nE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
