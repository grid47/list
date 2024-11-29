
+++
authors = ["grid47"]
title = "Leetcode 1744: Can You Eat Your Favorite Candy on Your Favorite Day?"
date = "2024-05-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1744: Can You Eat Your Favorite Candy on Your Favorite Day? in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "F4JpJIntzbQ"
youtube_upload_date="2021-01-31"
youtube_thumbnail="https://i.ytimg.com/vi/F4JpJIntzbQ/maxresdefault.jpg"
comments = true
+++



---
You are given an array `candiesCount` where each element represents the number of candies of a particular type. You are also given a set of queries, each asking whether it's possible to eat a candy of a certain type on a specific day without exceeding a daily candy limit. You must follow these game rules:

- You start eating candies on day 0.
- You cannot eat candies of type `i` until you have eaten all candies of type `i-1`.
- You must eat at least one candy per day.

Your task is to return an array of booleans where each element indicates whether it's possible to eat a candy of the specified type on the given day, subject to the daily cap.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `candiesCount`, where `candiesCount[i]` indicates the number of candies of the ith type, and a 2D array `queries`, where each query specifies a favorite candy type, a day, and the daily cap of candies that can be eaten.
- **Example:** `Input: candiesCount = [6, 3, 2, 4], queries = [[1, 2, 3], [2, 7, 5], [0, 5, 10]]`
- **Constraints:**
	- 1 <= candiesCount.length <= 10^5
	- 1 <= candiesCount[i] <= 10^5
	- 1 <= queries.length <= 10^5
	- queries[i].length == 3
	- 0 <= favoriteTypei < candiesCount.length
	- 0 <= favoriteDayi <= 10^9
	- 1 <= dailyCapi <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array of booleans indicating whether it's possible to eat a candy of the specified type on the given day without exceeding the daily cap.
- **Example:** `Output: [true, false, true]`
- **Constraints:**
	- For each query, the result should be `true` if it's possible to eat a candy of the favorite type on the specified day without exceeding the daily cap, otherwise `false`.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine if, given the daily candy limit, it's possible to eat a specific type of candy on a specific day while respecting the game rules.

- 1. Compute the cumulative sum of the number of candies for each type.
- 2. For each query, calculate the minimum and maximum possible days the candy of the favorite type can be eaten, based on the daily limit.
- 3. Check if the specified day falls within the valid range of days for the favorite type and return the corresponding result.
{{< dots >}}
### Problem Assumptions ✅
- Each query is valid, meaning the favorite type and day are within the bounds of the candies array and the daily cap.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: candiesCount = [6, 3, 2, 4], queries = [[1, 2, 3], [2, 7, 5], [0, 5, 10]]`  \
  **Explanation:** For the first query, you want to check if it's possible to eat a candy of type 1 on day 2 with a daily cap of 3 candies. If you eat 3 candies per day, by day 2, you've eaten 3 candies from type 0 and 3 from type 1, so the answer is `true`.
For the second query, you cannot eat type 2 on day 7 without exceeding the daily cap of 5, so the answer is `false`.
For the third query, if you eat 10 candies per day, you will eat a candy of type 0 on day 5, so the answer is `true`.

- **Input:** `Input: candiesCount = [5, 2, 6, 4, 1], queries = [[3, 1, 2], [4, 10, 3], [3, 10, 100], [4, 100, 30], [1, 3, 1]]`  \
  **Explanation:** The answers for the queries are `false`, `true`, `true`, `false`, and `false` because they depend on the daily cap and how candies accumulate over the days.

{{< dots >}}
## Approach 🚀
The approach involves calculating the cumulative sum of candies for each type and then determining if the favorite type can be consumed on the specified day based on the daily cap.

### Initial Thoughts 💭
- We need to ensure that the solution can handle large inputs efficiently.
- The problem can be solved using prefix sums to efficiently calculate the range of possible days for each type of candy.
{{< dots >}}
### Edge Cases 🌐
- Queries should not be empty, as there's at least one query in the problem.
- The solution must handle the maximum input sizes efficiently.
- Handle cases where the favorite day is very large or the daily cap is at its maximum.
- The solution must be designed to handle the upper bounds of the constraints.
{{< dots >}}
## Code 💻
```cpp
vector<bool> canEat(vector<int>& nums, vector<vector<int>>& q) {
    typedef long long ll;
    vector<ll> cnt(nums.size() +1, 0);
    
    for(int i = 1; i < nums.size() +1; i++)
        cnt[i] += cnt[i - 1] + nums[i -1];
    
    vector<bool> res;
    for(auto & v : q) {
        ll type = v[0], day = v[1], cap = v[2];
        ll mn = cnt[type] / cap;
        ll mx = cnt[type + 1] - 1;

if (mn <= day && day <= mx) {
res.push_back(true); }
        else {
            res.push_back(false);
        }
    }
    return res;
}
```

The function `canEat` determines whether a certain type of food can be eaten on a particular day given the capacity limits and the total number of servings available for different food types.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<bool> canEat(vector<int>& nums, vector<vector<int>>& q) {
	```
	This defines the function `canEat`, which takes two parameters: a vector `nums` representing the number of servings of each food type, and a vector `q` containing queries with details about food type, day, and capacity.

2. **Type Definition**
	```cpp
	    typedef long long ll;
	```
	This line defines `ll` as an alias for `long long` to simplify the code when dealing with large integers.

3. **Array Initialization**
	```cpp
	    vector<ll> cnt(nums.size() +1, 0);
	```
	This initializes a vector `cnt` of size `nums.size() + 1` to store the cumulative sum of servings, with all elements set to 0 initially.

4. **Cumulative Sum Calculation**
	```cpp
	    for(int i = 1; i < nums.size() +1; i++)
	```
	This loop iterates over the `nums` vector to calculate the cumulative sum of servings for each food type.

5. **Cumulative Sum Update**
	```cpp
	        cnt[i] += cnt[i - 1] + nums[i -1];
	```
	For each food type, the cumulative count of servings is updated by adding the previous cumulative sum and the current number of servings.

6. **Query Processing**
	```cpp
	    vector<bool> res;
	```
	This initializes a vector `res` to store the results of the queries (whether the food can be eaten on a given day).

7. **Loop Over Queries**
	```cpp
	    for(auto & v : q) {
	```
	This loop processes each query in the vector `q`.

8. **Variable Extraction**
	```cpp
	        ll type = v[0], day = v[1], cap = v[2];
	```
	The query is unpacked into three variables: `type` (food type), `day` (the day in question), and `cap` (capacity limit for servings).

9. **Calculate Minimum Servings**
	```cpp
	        ll mn = cnt[type] / cap;
	```
	This calculates the minimum number of servings that can be eaten on the given day by dividing the cumulative servings by the capacity.

10. **Calculate Maximum Servings**
	```cpp
	        ll mx = cnt[type + 1] - 1;
	```
	This calculates the maximum number of servings available for the given food type by using the cumulative sum.

11. **Conditional Check**
	```cpp
	if (mn <= day && day <= mx) {
	```
	This checks if the day in the query falls within the allowable range of servings (between the minimum and maximum servings).

12. **Result Update (True)**
	```cpp
	res.push_back(true); }
	```
	If the day is within the allowable range, `true` is added to the result vector, indicating that the food can be eaten on that day.

13. **Result Update (False)**
	```cpp
	        else {
	```
	If the day is outside the allowable range, the code prepares to add `false` to the result vector.

14. **Result Update (False)**
	```cpp
	            res.push_back(false);
	```
	This adds `false` to the result vector, indicating that the food cannot be eaten on that day.

15. **Return Statement**
	```cpp
	    return res;
	```
	The function returns the result vector `res`, which contains the answers to each query (whether the food can be eaten on the specified day).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + q), where `n` is the length of candiesCount and `q` is the number of queries.
- **Average Case:** O(n + q), since we must compute the prefix sums and then process each query.
- **Worst Case:** O(n + q), as we process all candies and all queries.

The time complexity is linear with respect to the number of candies and queries.

### Space Complexity 💾
- **Best Case:** O(n), since we are storing the cumulative sum.
- **Worst Case:** O(n), where `n` is the length of candiesCount, as we need space to store the cumulative sums.

The space complexity is linear in the number of candy types.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/description/)

---
{{< youtube F4JpJIntzbQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
