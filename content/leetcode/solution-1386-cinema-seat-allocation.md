
+++
authors = ["grid47"]
title = "Leetcode 1386: Cinema Seat Allocation"
date = "2024-06-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1386: Cinema Seat Allocation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
A cinema has multiple rows, each with ten seats arranged in a line. Some seats are already reserved. You need to determine the maximum number of four-person groups that can be seated in the available seats. A four-person group requires four adjacent seats in one row. If an aisle splits a group in the middle, they can still be seated if there are two consecutive seats on both sides of the aisle.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer n representing the number of rows and a list reservedSeats where each element is a pair [row, seat] indicating a reserved seat in the cinema.
- **Example:** `Input: n = 5, reservedSeats = [[1, 1], [1, 5], [2, 3], [4, 7], [5, 2], [5, 9]]`
- **Constraints:**
	- 1 <= n <= 10^9
	- 1 <= reservedSeats.length <= min(10*n, 10^4)
	- reservedSeats[i].length == 2
	- 1 <= reservedSeats[i][0] <= n
	- 1 <= reservedSeats[i][1] <= 10
	- All reservedSeats[i] are distinct.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an integer representing the maximum number of four-person groups that can be assigned to the cinema seats.
- **Example:** `Output: 6`
- **Constraints:**
	- The result should be a single integer indicating the number of groups that can be seated.

{{< dots >}}
### Core Logic 🔍
**Goal:** Maximize the number of four-person groups that can be seated in the cinema, given the reserved seats and the constraints on adjacency.

- Iterate through the reserved seats and mark the occupied positions in each row.
- For each row, check if there are four consecutive available seats either across the entire row or split by the aisle.
- Count the number of valid groups that can be seated and return the total count.
{{< dots >}}
### Problem Assumptions ✅
- There will always be enough space for at least one four-person group in some row.
- All the reserved seats are valid and within the range of the cinema's capacity.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 5, reservedSeats = [[1, 1], [1, 5], [2, 3], [4, 7], [5, 2], [5, 9]]`  \
  **Explanation:** This example shows how the rows can be divided into groups based on the reserved seats. In row 1, four seats from 2 to 5 are available for one group. Similarly, the other rows have groups formed based on available seats.

{{< dots >}}
## Approach 🚀
To solve this problem efficiently, we need to track the reserved seats for each row and calculate the number of available groups in each row while considering aisle splits.

### Initial Thoughts 💭
- The problem involves checking adjacency of seats across rows and handling aisle splits efficiently.
- We can use bit manipulation or simple checks to determine the available groups in each row.
{{< dots >}}
### Edge Cases 🌐
- Handle cases where no reserved seats are given (all seats are available).
- Handle the scenario where there are a large number of rows but only a few reserved seats.
- Ensure that edge cases such as having just one row or a row with no available seats are handled properly.
- Ensure the solution handles the large values of n efficiently.
{{< dots >}}
## Code 💻
```cpp
int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    int ans = n * 2;
    unordered_map<int, char> m;
    for(auto r: reservedSeats)
        if(r[1] > 1 && r[1] < 10)
            m[r[0]] |= 1 << (r[1] - 2);
    
    for(auto [row, seats]: m) {
        int left  = seats & 0b11110000;
        int mid   = seats & 0b00111100;
        int right = seats & 0b00001111;
        ans -= left && mid && right ? 2 : 1;
    }
    return ans;
}
```

This solution calculates the maximum number of families that can sit in a theater given the reserved seat information. It checks which seats are already occupied in each row and adjusts the count of possible families that can fit based on the seat patterns.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
	```
	Define the function `maxNumberOfFamilies` that takes the number of rows (n) and the reserved seats information (reservedSeats). The function will return the maximum number of families that can be seated.

2. **Initialization**
	```cpp
	    int ans = n * 2;
	```
	Initialize `ans` to `n * 2`, as the maximum number of families is initially assumed to be two per row.

3. **Data Structures**
	```cpp
	    unordered_map<int, char> m;
	```
	Declare an unordered map `m` to store the seat occupancy for each row. The key is the row number, and the value is a bitmask representing the reserved seats.

4. **Loop**
	```cpp
	    for(auto r: reservedSeats)
	```
	Loop through each reserved seat in the `reservedSeats` vector.

5. **Condition**
	```cpp
	        if(r[1] > 1 && r[1] < 10)
	```
	Check if the seat in the current row is reserved and falls within the valid seat range (2 to 9).

6. **Bit Manipulation**
	```cpp
	            m[r[0]] |= 1 << (r[1] - 2);
	```
	Use bit manipulation to mark the reserved seat in the map for the corresponding row. This sets the appropriate bit in the bitmask.

7. **Loop**
	```cpp
	    for(auto [row, seats]: m) {
	```
	Loop through each row and its corresponding seat bitmask stored in `m`.

8. **Bit Manipulation**
	```cpp
	        int left  = seats & 0b11110000;
	```
	Extract the left block of seats (seats 2 to 5) by using a bitmask operation.

9. **Bit Manipulation**
	```cpp
	        int mid   = seats & 0b00111100;
	```
	Extract the middle block of seats (seats 4 to 7) using another bitmask operation.

10. **Bit Manipulation**
	```cpp
	        int right = seats & 0b00001111;
	```
	Extract the right block of seats (seats 6 to 9) using a final bitmask operation.

11. **Condition**
	```cpp
	        ans -= left && mid && right ? 2 : 1;
	```
	If all three blocks (left, middle, and right) are occupied, subtract 2 from `ans` (two families can't be seated). Otherwise, subtract 1 (one family can't be seated).

12. **Return Statement**
	```cpp
	    return ans;
	```
	Return the calculated number of families that can be seated after considering all reserved seats.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution requires iterating through each row and checking available seats, which takes linear time with respect to the number of rows.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity depends on the number of rows and the reserved seats, requiring storage for each row's reserved seats.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/cinema-seat-allocation/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
