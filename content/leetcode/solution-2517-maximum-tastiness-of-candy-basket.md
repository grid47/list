
+++
authors = ["grid47"]
title = "Leetcode 2517: Maximum Tastiness of Candy Basket"
date = "2024-02-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2517: Maximum Tastiness of Candy Basket in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "mEZRRvBqSB0"
youtube_upload_date="2022-12-25"
youtube_thumbnail="https://i.ytimg.com/vi_webp/mEZRRvBqSB0/maxresdefault.webp"
comments = true
+++



---
You are given an array of positive integers `price` where `price[i]` denotes the price of the `i`-th candy and a positive integer `k`. The store sells baskets containing `k` distinct candies. The tastiness of a candy basket is defined as the smallest absolute difference between the prices of any two candies in the basket. Your task is to return the maximum tastiness of a candy basket that can be formed by selecting `k` distinct candies.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of positive integers `price` where each element represents the price of a candy, and a positive integer `k` which denotes the number of candies to be selected.
- **Example:** `price = [15, 3, 10, 8, 25, 4], k = 3`
- **Constraints:**
	- 2 <= k <= price.length <= 10^5
	- 1 <= price[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum tastiness of the candy basket that can be formed, or -1 if it is not possible.
- **Example:** `Output: 7`
- **Constraints:**
	- The output should be the maximum tastiness of a candy basket.

{{< dots >}}
### Core Logic 🔍
**Goal:** We need to find the maximum tastiness for a basket of `k` distinct candies from the given prices.

- Sort the array of prices.
- Use binary search to determine the maximum tastiness.
- Check if a basket with `k` candies can have the desired tastiness using a helper function.
- Return the maximum tastiness found.
{{< dots >}}
### Problem Assumptions ✅
- All elements in `price` are positive integers.
- The number of candies `k` is valid and at least 2.
{{< dots >}}
## Examples 🧩
- **Input:** `price = [15, 3, 10, 8, 25, 4], k = 3`  \
  **Explanation:** After sorting the prices, the array becomes [3, 4, 8, 10, 15, 25]. The maximum tastiness is achieved by selecting the basket with prices [15, 10, 25], where the smallest absolute difference is 7.

- **Input:** `price = [5, 6, 7, 5, 7], k = 2`  \
  **Explanation:** The array of prices is [5, 5, 6, 7, 7]. The maximum tastiness of a basket formed by selecting two candies is 1, which occurs by selecting prices [5, 6].

{{< dots >}}
## Approach 🚀
We will use binary search on the tastiness value to find the maximum tastiness for a basket of `k` distinct candies.

### Initial Thoughts 💭
- The problem requires finding the maximum tastiness of a basket of `k` distinct candies.
- Binary search can be used to efficiently find the maximum tastiness.
- We can use binary search to minimize the tastiness and check if it is possible to create a valid basket.
{{< dots >}}
### Edge Cases 🌐
- If the array `price` is empty or contains fewer than `k` elements, return -1.
- Ensure the solution is efficient enough to handle large inputs, up to 10^5 elements.
- If all elements in the `price` array are the same, the tastiness will always be 0.
- Ensure the solution handles cases where `k` is equal to the length of the `price` array.
{{< dots >}}
## Code 💻
```cpp
bool can(vector<int> nums, int mid, int k) {
    int cnt = 1, n = nums.size();
    int i = 1;
    int prv = nums[0];
    while(i < n) {
        if(nums[i] - prv >= mid) {
            cnt++;
            prv = nums[i];
        }
        if(cnt >= k) return true;
        i++;
    }
    return false;
}

int maximumTastiness(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    
    int l = 0, r = nums[n - 1] - nums[0];
    int ans = r;
    
    while(l <= r) {
        
        int mid = l + (r - l + 1) / 2;
        // cout << mid << " " << can(nums, mid, k) << "\n";
        if(can(nums, mid, k)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
        
    }
    
    return ans;
}
```

This code defines two functions, `can` and `maximumTastiness`. The `can` function checks if it is possible to select `k` elements from a sorted list of numbers where the minimum difference between any two selected elements is at least `mid`. The `maximumTastiness` function uses binary search to find the largest possible value of `mid` for which `can` returns true.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool can(vector<int> nums, int mid, int k) {
	```
	Define the `can` function that checks if it's possible to select `k` elements from the list `nums` where the minimum difference between consecutive selected elements is at least `mid`.

2. **Variable Initialization**
	```cpp
	    int cnt = 1, n = nums.size();
	```
	Initialize `cnt` to 1 (since we select the first element), and `n` to the size of the input list `nums`.

3. **Variable Initialization**
	```cpp
	    int i = 1;
	```
	Initialize the variable `i` to 1 to start the iteration from the second element in the list.

4. **Variable Initialization**
	```cpp
	    int prv = nums[0];
	```
	Store the first element of `nums` in the variable `prv` to track the previously selected element.

5. **Loop**
	```cpp
	    while(i < n) {
	```
	Start a `while` loop that iterates over the list `nums` starting from the second element.

6. **Condition Check**
	```cpp
	        if(nums[i] - prv >= mid) {
	```
	Check if the difference between the current element `nums[i]` and the previously selected element `prv` is greater than or equal to `mid`.

7. **Count Update**
	```cpp
	            cnt++;
	```
	Increment `cnt` to reflect the selection of another element that meets the condition.

8. **Update Previous Element**
	```cpp
	            prv = nums[i];
	```
	Update the `prv` variable to store the current selected element `nums[i]`.

9. **Early Exit**
	```cpp
	        if(cnt >= k) return true;
	```
	If `cnt` reaches `k`, return `true` as we have successfully selected `k` elements with the desired property.

10. **Increment Iterator**
	```cpp
	        i++;
	```
	Increment `i` to move to the next element in the list.

11. **Return Statement**
	```cpp
	    return false;
	```
	Return `false` if it's not possible to select `k` elements with the desired property.

12. **Function Definition**
	```cpp
	int maximumTastiness(vector<int>& nums, int k) {
	```
	Define the `maximumTastiness` function that aims to find the maximum possible value of `mid` for which `can(nums, mid, k)` is true.

13. **Sort Array**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	Sort the input list `nums` to facilitate the selection of elements with a minimum difference.

14. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	Store the size of the sorted `nums` list in `n`.

15. **Binary Search Setup**
	```cpp
	    int l = 0, r = nums[n - 1] - nums[0];
	```
	Initialize the binary search bounds: `l` to 0 and `r` to the difference between the largest and smallest elements in `nums`.

16. **Variable Initialization**
	```cpp
	    int ans = r;
	```
	Initialize `ans` to `r`, which represents the current best answer for the maximum tastiness.

17. **Binary Search Loop**
	```cpp
	    while(l <= r) {
	```
	Start the binary search loop with the condition `l <= r`.

18. **Midpoint Calculation**
	```cpp
	        int mid = l + (r - l + 1) / 2;
	```
	Calculate the midpoint `mid` to check the possible value of tastiness.

19. **Condition Check**
	```cpp
	        if(can(nums, mid, k)) {
	```
	Check if the current value of `mid` satisfies the condition by calling the `can` function.

20. **Update Answer**
	```cpp
	            ans = mid;
	```
	Update the best answer `ans` to the current value of `mid` if the condition is satisfied.

21. **Adjust Search Bounds**
	```cpp
	            l = mid + 1;
	```
	Adjust the lower bound `l` to search for larger values of `mid`.

22. **Adjust Search Bounds**
	```cpp
	        } else r = mid - 1;
	```
	Adjust the upper bound `r` to search for smaller values of `mid` if the condition is not satisfied.

23. **Return Answer**
	```cpp
	    return ans;
	```
	Return the final answer `ans`, which is the maximum possible tastiness.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

Sorting the array takes O(n log n) time, and the binary search is O(log n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We use O(n) space for sorting the array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-tastiness-of-candy-basket/description/)

---
{{< youtube mEZRRvBqSB0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
