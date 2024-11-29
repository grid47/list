
+++
authors = ["grid47"]
title = "Leetcode 2064: Minimized Maximum of Products Distributed to Any Store"
date = "2024-04-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2064: Minimized Maximum of Products Distributed to Any Store in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "J6D5xPSlGHY"
youtube_upload_date="2021-11-07"
youtube_thumbnail="https://i.ytimg.com/vi/J6D5xPSlGHY/maxresdefault.jpg"
comments = true
+++



---
You are given a number n representing the number of retail stores and an array of integers quantities. Each quantity[i] represents the number of products of the i-th product type available. The task is to distribute all the products to the stores in such a way that no store gets more than one product type, but may receive any quantity of that type. The goal is to minimize the maximum number of products assigned to any store. Return the smallest possible value of this maximum number of products assigned to a store.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer n followed by an array quantities representing the number of products available for each product type.
- **Example:** `Input: n = 5, quantities = [9, 5]`
- **Constraints:**
	- 1 <= m <= n <= 10^5
	- 1 <= quantities[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Output the smallest possible value of the maximum number of products given to any store.
- **Example:** `Output: 3`
- **Constraints:**
	- The result should be an integer representing the minimized maximum product distribution.

{{< dots >}}
### Core Logic 🔍
**Goal:** The objective is to find the minimum possible value of the maximum number of products assigned to any store.

- 1. Set the initial range for the maximum number of products between 1 and the maximum quantity in the quantities array.
- 2. Use binary search to narrow down the possible values of the maximum product number, checking for feasibility by calculating how many stores are needed for each potential value.
- 3. Return the smallest value that works.
{{< dots >}}
### Problem Assumptions ✅
- The number of stores, n, is always greater than or equal to the number of product types, m.
- Products are distributed efficiently to minimize the maximum number assigned to any store.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 5, quantities = [10, 5]`  \
  **Explanation:** The best distribution of the 10 products of type 0 across 4 stores could be 3, 3, 2, 2, while the 5 products of type 1 could be distributed as 3, 2. The maximum number of products assigned to any store is 3.

- **Input:** `Input: n = 6, quantities = [12, 8, 5]`  \
  **Explanation:** The 12 products of type 0 can be distributed across 4 stores with amounts 3, 3, 3, 3. The 8 products of type 1 across 2 stores as 4, 4. The 5 products of type 2 across 2 stores as 3, 2. The maximum number of products assigned to any store is 4.

- **Input:** `Input: n = 4, quantities = [5]`  \
  **Explanation:** With only 5 products of type 0 and 4 stores, the maximum distribution to any store would be 2.

{{< dots >}}
## Approach 🚀
To solve this problem, we use binary search over the possible values of the maximum number of products per store. The main challenge is checking if a given maximum can be achieved given the constraints of how products can be distributed.

### Initial Thoughts 💭
- Binary search helps find the smallest possible value of the maximum number of products that any store receives.
- The total number of stores needed for a given maximum can be computed by distributing products optimally.
- This approach uses binary search to optimize the product distribution and minimize the maximum number of products assigned to any store.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one product type and one store, so empty inputs are not a concern.
- For large inputs, make sure the binary search approach runs efficiently within the time limits.
- If there is only one store, all products must go to that store.
- Ensure that the binary search approach works within the constraints of 10^5 stores and product quantities.
{{< dots >}}
## Code 💻
```cpp

bool isPossible(vector<int>& qnty, int mid, int m, int n) {

    int cnt = 0;
        
    for(int i = 0; i < m; i++) {
        if(qnty[i] <= mid) {
            cnt++;
            continue;
        }
        // if(mid == 1) cout << qnty[i];
        int num = qnty[i];
        cnt++;
        while(num > mid) {
            cnt++;
            num -= mid;
        }
    }
    // cout << mid << " " << cnt << " " << n << "\n";
    
    return (cnt <= n);
}

int minimizedMaximum(int n, vector<int>& qnty) {
    
    int m = qnty.size();
    
    int ans = *max_element(qnty.begin(), qnty.end());
    
    int l = 1, r = ans - 1;
    
    while(l <= r) {
        int mid = l + (r - l + 1) / 2;
        // cout << mid << " ";
        if(isPossible(qnty, mid, m, n)) {
            // cout << mid << " ";
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    
    return ans;
}
```

This code defines two functions: 'isPossible' and 'minimizedMaximum'. The 'isPossible' function checks if it's possible to partition quantities into 'n' groups with a maximum value of 'mid'. The 'minimizedMaximum' function uses binary search to minimize the maximum value of these groups.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool isPossible(vector<int>& qnty, int mid, int m, int n) {
	```
	Define the 'isPossible' function, which checks if it's possible to partition the quantities into 'n' groups such that no group exceeds the value 'mid'.

2. **Variable Initialization**
	```cpp
	    int cnt = 0;
	```
	Initialize the counter 'cnt' to 0, which tracks the number of partitions.

3. **Looping**
	```cpp
	    for(int i = 0; i < m; i++) {
	```
	Start a loop that iterates through the quantities vector 'qnty'.

4. **Conditional Logic**
	```cpp
	        if(qnty[i] <= mid) {
	```
	Check if the current quantity is less than or equal to the current 'mid' value.

5. **Increment**
	```cpp
	            cnt++;
	```
	If the current quantity is less than or equal to 'mid', increment the count of partitions.

6. **Control Flow**
	```cpp
	            continue;
	```
	Skip the rest of the loop and continue with the next iteration.

7. **Variable Assignment**
	```cpp
	        int num = qnty[i];
	```
	Assign the current quantity to 'num' for further processing.

8. **Increment**
	```cpp
	        cnt++;
	```
	Increment the count for the current quantity, as it will form at least one partition.

9. **Looping**
	```cpp
	        while(num > mid) {
	```
	While the current quantity exceeds 'mid', keep breaking it down into smaller partitions.

10. **Increment**
	```cpp
	            cnt++;
	```
	Increment the count for each partition formed by dividing the quantity 'num'.

11. **Mathematical Operation**
	```cpp
	            num -= mid;
	```
	Reduce the quantity 'num' by 'mid', effectively partitioning it into smaller parts.

12. **Return Statement**
	```cpp
	    return (cnt <= n);
	```
	Return true if the total number of partitions 'cnt' is less than or equal to 'n', indicating it's possible to partition the quantities accordingly.

13. **Function Definition**
	```cpp
	int minimizedMaximum(int n, vector<int>& qnty) {
	```
	Define the 'minimizedMaximum' function, which finds the minimized maximum of partitions for the given quantities.

14. **Variable Initialization**
	```cpp
	    int m = qnty.size();
	```
	Initialize 'm' to the size of the quantities vector 'qnty'.

15. **Variable Assignment**
	```cpp
	    int ans = *max_element(qnty.begin(), qnty.end());
	```
	Initialize 'ans' to the maximum quantity in the vector 'qnty'. This represents the starting point for the binary search.

16. **Binary Search Initialization**
	```cpp
	    int l = 1, r = ans - 1;
	```
	Initialize the left ('l') and right ('r') bounds for the binary search.

17. **Binary Search Loop**
	```cpp
	    while(l <= r) {
	```
	Start the binary search loop to find the minimized maximum partition.

18. **Binary Search Midpoint**
	```cpp
	        int mid = l + (r - l + 1) / 2;
	```
	Calculate the midpoint 'mid' for the binary search to check if it's possible to partition the quantities accordingly.

19. **Conditional Logic**
	```cpp
	        if(isPossible(qnty, mid, m, n)) {
	```
	Check if it's possible to partition the quantities with the current 'mid' value.

20. **Variable Assignment**
	```cpp
	            ans = mid;
	```
	If partitioning is possible, update 'ans' to the current 'mid'.

21. **Binary Search Adjustment**
	```cpp
	            r = mid - 1;
	```
	Adjust the right bound of the binary search to search for smaller possible values.

22. **Binary Search Adjustment**
	```cpp
	        } else l = mid + 1;
	```
	If partitioning is not possible, adjust the left bound of the binary search to search for larger possible values.

23. **Return Statement**
	```cpp
	    return ans;
	```
	Return the minimized maximum partition value found by the binary search.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * log(max(quantities)))
- **Average Case:** O(m * log(max(quantities)))
- **Worst Case:** O(m * log(max(quantities)))

The binary search takes log(max(quantities)) iterations, and each check involves a linear scan over the quantities array (m), leading to an overall complexity of O(m * log(max(quantities))).

### Space Complexity 💾
- **Best Case:** O(m)
- **Worst Case:** O(m)

The space complexity is O(m) for storing the quantities array and performing the checks.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/description/)

---
{{< youtube J6D5xPSlGHY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
