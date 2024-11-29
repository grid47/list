
+++
authors = ["grid47"]
title = "Leetcode 1482: Minimum Number of Days to Make m Bouquets"
date = "2024-06-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1482: Minimum Number of Days to Make m Bouquets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "C43I3Q0JLB0"
youtube_upload_date="2020-06-14"
youtube_thumbnail="https://i.ytimg.com/vi/C43I3Q0JLB0/maxresdefault.jpg"
comments = true
+++



---
You are given an integer array bloomDay, an integer m, and an integer k. Your goal is to form m bouquets using exactly k adjacent flowers. Each flower blooms on a particular day. Determine the minimum number of days required to form m bouquets, or return -1 if it is impossible.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array bloomDay, and integers m and k.
- **Example:** `[2, 5, 3, 4, 1], m = 3, k = 2`
- **Constraints:**
	- 1 <= bloomDay.length <= 10^5
	- 1 <= bloomDay[i] <= 10^9
	- 1 <= m <= 10^6
	- 1 <= k <= bloomDay.length

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer representing the minimum number of days required to form m bouquets, or -1 if it is impossible.
- **Example:** `4`
- **Constraints:**
	- The result is guaranteed to be a valid integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine the minimum number of days to wait in order to be able to make m bouquets.

- Perform a binary search on the number of days, starting with the lowest possible day and checking if it's feasible to form m bouquets in that time.
- To check if m bouquets can be formed by a certain day, count the number of adjacent flowers that bloom by that day, and see if you can form m bouquets with k flowers each.
{{< dots >}}
### Problem Assumptions ✅
- The flowers bloom on specific days and can only be used once for a bouquet.
- The flowers must be adjacent to form a bouquet.
{{< dots >}}
## Examples 🧩
- **Input:** `[2, 5, 3, 4, 1], m = 3, k = 2`  \
  **Explanation:** After 4 days, we can make 3 bouquets of 2 adjacent flowers. The solution works by checking if it's possible to make the bouquets by each day in the binary search process.

{{< dots >}}
## Approach 🚀
The solution involves performing a binary search on the number of days. For each day, we check if it's possible to make the required bouquets by counting the number of adjacent blooming flowers.

### Initial Thoughts 💭
- The problem requires determining if it is possible to make m bouquets by checking different days in a binary search approach.
- Binary search helps us efficiently find the minimum number of days, reducing the number of checks.
{{< dots >}}
### Edge Cases 🌐
- If the array is empty, return -1 as no bouquets can be made.
- Ensure the solution handles arrays with up to 10^5 elements efficiently.
- If m is 0 or k is greater than the total number of flowers, return -1.
- The algorithm must be efficient enough to handle the upper limit of input size.
{{< dots >}}
## Code 💻
```cpp
int isValid(vector<int> &bloom, int m, int mid, int k) {
    int bough = 0, cnt = 0;
    
    for(int i = 0; i < bloom.size(); i++) {
        if(bloom[i] > mid) {
            cnt = 0;
        } else if(++cnt >= k) {
            cnt = 0;
            bough++;
        }
    }
    if(bough >= m) return true;
    else return false;
}

int minDays(vector<int>& bloom, int m, int k) {
    int n = bloom.size();
    if((long)m * k > n) return -1;
    
    int l = 1, r = (int) 1e9, result;
    
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(isValid(bloom, m, mid, k)) {
            result = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    
    return result;
    
}
```

The `minDays` function solves the problem of finding the minimum day on which at least `m` bouquets can be made, where each bouquet requires `k` adjacent flowers. It uses binary search to minimize the number of days, and `isValid` is used to check if making `m` bouquets is possible on a given day.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method**
	```cpp
	int isValid(vector<int> &bloom, int m, int mid, int k) {
	```
	This function checks if it's possible to make `m` bouquets with at least `k` adjacent flowers blooming on or before day `mid`.

2. **Variable Initialization**
	```cpp
	    int bough = 0, cnt = 0;
	```
	Two variables are initialized: `bough` to count the number of bouquets and `cnt` to track the number of consecutive blooming flowers.

3. **Loop**
	```cpp
	    for(int i = 0; i < bloom.size(); i++) {
	```
	This loop iterates over the `bloom` array to check the blooming status of each flower.

4. **Condition**
	```cpp
	        if(bloom[i] > mid) {
	```
	If the flower blooms after day `mid`, we reset the counter (`cnt = 0`) since no more flowers can be added to the current bouquet.

5. **Reset Counter**
	```cpp
	            cnt = 0;
	```
	Resetting the counter (`cnt`) ensures we start counting the next set of consecutive flowers.

6. **Condition**
	```cpp
	        } else if(++cnt >= k) {
	```
	If `cnt` reaches `k`, we have enough consecutive flowers to form a bouquet, so we increment the bouquet count (`bough++`).

7. **Reset Counter**
	```cpp
	            cnt = 0;
	```
	Resetting the counter (`cnt`) to 0 after forming a bouquet.

8. **Increment Bouquets**
	```cpp
	            bough++;
	```
	We increment the `bough` count when a bouquet is formed with `k` consecutive flowers.

9. **Return**
	```cpp
	    if(bough >= m) return true;
	```
	If we have formed at least `m` bouquets, return `true` to indicate that it's possible to form the bouquets within the given conditions.

10. **Return**
	```cpp
	    else return false;
	```
	If fewer than `m` bouquets were formed, return `false` to indicate that it's not possible to meet the requirement.

11. **Method**
	```cpp
	int minDays(vector<int>& bloom, int m, int k) {
	```
	The `minDays` function finds the minimum day on which at least `m` bouquets can be made, each with `k` adjacent blooming flowers.

12. **Variable Initialization**
	```cpp
	    int n = bloom.size();
	```
	The size of the `bloom` array is stored in `n`, representing the total number of flowers.

13. **Condition**
	```cpp
	    if((long)m * k > n) return -1;
	```
	If the total number of flowers is less than `m * k`, it is impossible to form `m` bouquets, so the function returns `-1`.

14. **Variable Initialization**
	```cpp
	    int l = 1, r = (int) 1e9, result;
	```
	Initialize the binary search bounds: `l` is the minimum day (1), `r` is a large upper bound (1e9), and `result` will hold the answer.

15. **Binary Search**
	```cpp
	    while(l <= r) {
	```
	Start the binary search loop, which continues as long as the lower bound `l` is less than or equal to the upper bound `r`.

16. **Mid Calculation**
	```cpp
	        int mid = l + (r - l) / 2;
	```
	Calculate the middle point `mid` between `l` and `r` to check the possibility of forming `m` bouquets within `mid` days.

17. **Condition**
	```cpp
	        if(isValid(bloom, m, mid, k)) {
	```
	Check if it's possible to form `m` bouquets within `mid` days using the `isValid` function.

18. **Result Update**
	```cpp
	            result = mid;
	```
	If it's possible to form `m` bouquets within `mid` days, update the `result` with `mid` and continue searching for smaller values of `mid`.

19. **Adjust Search Bounds**
	```cpp
	            r = mid - 1;
	```
	Adjust the upper bound `r` to `mid - 1` to search for smaller days that might still work.

20. **Else Condition**
	```cpp
	        } else {
	```
	If it's not possible to form `m` bouquets within `mid` days, we need to increase the day count.

21. **Adjust Search Bounds**
	```cpp
	            l = mid + 1;
	```
	Adjust the lower bound `l` to `mid + 1` to search for larger days.

22. **Return Result**
	```cpp
	    return result;
	```
	Return the result, which is the minimum day when at least `m` bouquets can be made.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log(max(bloomDay))) for the binary search and validation check.
- **Average Case:** O(n log(max(bloomDay)))
- **Worst Case:** O(n log(max(bloomDay)))

The time complexity is dominated by the binary search step and the validation step, both of which are O(n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n) for storing the bloomDay array.

The space complexity is O(n) due to the input array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/)

---
{{< youtube C43I3Q0JLB0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
