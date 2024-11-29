
+++
authors = ["grid47"]
title = "Leetcode 1109: Corporate Flight Bookings"
date = "2024-07-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1109: Corporate Flight Bookings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "geZPsJWEzfc"
youtube_upload_date="2019-12-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/geZPsJWEzfc/maxresdefault.webp"
comments = true
+++



---
You are given a list of flight bookings, where each booking specifies the flight range (from first flight to last flight) and the number of seats reserved for each of the flights in that range. You need to compute the total number of seats reserved for each flight, from flight 1 to flight n.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a list of bookings, where each element `bookings[i]` is an array containing three integers: `[firsti, lasti, seatsi]`, representing the first flight, last flight, and the number of seats reserved for each flight in the given range. Additionally, you are given an integer `n` representing the total number of flights.
- **Example:** `bookings = [[1, 2, 10], [2, 3, 20], [2, 5, 25]], n = 5`
- **Constraints:**
	- 1 <= n <= 2 * 10^4
	- 1 <= bookings.length <= 2 * 10^4
	- bookings[i].length == 3
	- 1 <= firsti <= lasti <= n
	- 1 <= seatsi <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array `answer` of length `n`, where each element `answer[i]` represents the total number of seats reserved for the i-th flight.
- **Example:** `Output: [10, 55, 45, 25, 25]`
- **Constraints:**
	- Each element in the answer array should be the sum of reserved seats for the respective flight.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the total number of reserved seats for each flight while efficiently handling multiple bookings that affect overlapping flight ranges.

- Start with an array `ans` initialized to zero, which will store the total seats for each flight.
- For each booking, increment the number of seats reserved for the first flight in the range, and decrement the number of seats for the flight right after the last flight in the range.
- Use a cumulative sum to calculate the total seats reserved for each flight.
{{< dots >}}
### Problem Assumptions ✅
- Each flight range will contain valid indexes and the number of seats will always be within the allowed range.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: bookings = [[1, 2, 10], [2, 3, 20], [2, 5, 25]], n = 5`  \
  **Explanation:** In this case, bookings affect the following flights: the first booking reserves 10 seats for flights 1 and 2. The second booking reserves 20 seats for flights 2 and 3. The third booking reserves 25 seats for flights 2 through 5. The total seats for each flight are: [10, 55, 45, 25, 25].

{{< dots >}}
## Approach 🚀
We will use a technique known as difference array to efficiently process overlapping bookings and compute the total seats reserved for each flight.

### Initial Thoughts 💭
- We need to keep track of seat reservations for overlapping flight ranges, which can be handled by using the difference array approach.
- For each booking, we will increment the start of the range and decrement the flight after the last in the range. This way, we can compute the cumulative number of reserved seats with just one pass through the array.
{{< dots >}}
### Edge Cases 🌐
- Bookings array cannot be empty as the problem guarantees at least one booking.
- The solution must handle the upper limits of input sizes efficiently (up to 20,000 flights and bookings).
- If all bookings affect the same flight range, the result should correctly accumulate the reserved seats for each flight.
- Ensure the solution works within the provided constraints of `n` and the size of the bookings array.
{{< dots >}}
## Code 💻
```cpp
vector<int> corpFlightBookings(vector<vector<int>>& bookings, int m) {

    vector<int> ans(m, 0);
    for(auto& v: bookings) {
        ans[v[0] - 1] += v[2];
        if(v[1] < m) ans[v[1]] -= v[2];
    }

    for(int j = 1; j < m; j++)
        ans[j] += ans[j-1];

    return ans;
}
```

This function calculates the number of booked seats on each flight based on a list of bookings. It uses a prefix sum approach to efficiently calculate the number of seats for each flight.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> corpFlightBookings(vector<vector<int>>& bookings, int m) {
	```
	The function `corpFlightBookings` accepts a 2D vector `bookings` representing the booking ranges (start and end flight) and an integer `m` representing the total number of flights. It returns a vector of integers where each element corresponds to the number of bookings for a flight.

2. **Initialization**
	```cpp
	    vector<int> ans(m, 0);
	```
	A vector `ans` of size `m` is initialized to zero, representing the number of bookings for each flight initially set to zero.

3. **Loop Through Bookings**
	```cpp
	    for(auto& v: bookings) {
	```
	This loop iterates over each booking in the `bookings` vector. Each booking is represented by a vector `v` of three elements: start flight, end flight, and number of seats booked.

4. **Booking Updates**
	```cpp
	        ans[v[0] - 1] += v[2];
	```
	For each booking, the number of seats booked is added to the `ans` vector at the index corresponding to the start flight (adjusted by subtracting 1 for zero-based indexing).

5. **Decrement After End Flight**
	```cpp
	        if(v[1] < m) ans[v[1]] -= v[2];
	```
	If the end flight `v[1]` is less than `m` (i.e., within the range of flights), the number of seats booked is subtracted from the `ans` vector at the index corresponding to the end flight.

6. **Prefix Sum Calculation**
	```cpp
	    for(int j = 1; j < m; j++)
	```
	This loop calculates the prefix sum for each flight, adding the number of seats booked for each previous flight to compute the total number of seats for the current flight.

7. **Prefix Sum Update**
	```cpp
	        ans[j] += ans[j-1];
	```
	The prefix sum is updated for each flight by adding the previous flight's seat count to the current flight's seat count.

8. **Return Statement**
	```cpp
	    return ans;
	```
	The function returns the `ans` vector, which contains the total number of seats booked for each flight after processing all bookings.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + m)
- **Average Case:** O(n + m)
- **Worst Case:** O(n + m)

The time complexity is O(n + m), where `n` is the number of flights and `m` is the number of bookings, as we process each booking and then compute the cumulative sum for the flights.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n), where `n` is the number of flights, due to the array used to store seat reservations for each flight.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/corporate-flight-bookings/description/)

---
{{< youtube geZPsJWEzfc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
