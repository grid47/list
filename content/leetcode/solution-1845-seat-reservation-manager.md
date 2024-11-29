
+++
authors = ["grid47"]
title = "Leetcode 1845: Seat Reservation Manager"
date = "2024-05-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1845: Seat Reservation Manager in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Design","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ahobllKXEEY"
youtube_upload_date="2021-05-01"
youtube_thumbnail="https://i.ytimg.com/vi/ahobllKXEEY/maxresdefault.jpg"
comments = true
+++



---
Design a system to manage the reservation state of n seats numbered from 1 to n. Implement the SeatManager class to handle reserving and unreserving seats. The class should be able to return the smallest available seat when reserved, and make seats available again when unreserved.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer n, which represents the number of seats. The operations are called as a sequence of commands where reserve() reserves the smallest available seat and unreserve(seatNumber) unreserves a seat.
- **Example:** `[5], [], [], [2], [], [], [], [], [5]`
- **Constraints:**
	- 1 <= n <= 10^5
	- 1 <= seatNumber <= n
	- At least one unreserved seat will be available for each reserve call.
	- seatNumber will always refer to a reserved seat for each unreserve call.

{{< dots >}}
### Output Specifications 📤
- **Output:** For each call to reserve, return the smallest available seat number. For each call to unreserve, no return value is expected, but the seat is made available again.
- **Example:** `[null, 1, 2, null, 2, 3, 4, 5, null]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The system should efficiently handle reserving and unreserving seats while keeping track of the smallest available seat number.

- Use a priority queue to keep track of available seats.
- Initialize the seats from 1 to n, making them all available initially.
- On calling reserve(), pop the smallest seat from the queue.
- On calling unreserve(), push the seat back into the priority queue.
{{< dots >}}
### Problem Assumptions ✅
- The SeatManager class is initialized correctly with n seats.
- The input operations are valid according to the problem constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `[5], [], [], [2], [], [], [], [], [5]`  \
  **Explanation:** The SeatManager starts with 5 seats. After reserving and unreserving as per the sequence, the smallest available seats are allocated, and seats are made available again after unreserving.

{{< dots >}}
## Approach 🚀
We can use a priority queue to efficiently manage seat reservations. The smallest seat number can be retrieved in O(log n) time, and unreserving a seat also takes O(log n) time.

### Initial Thoughts 💭
- A priority queue (min-heap) is a suitable data structure to manage the smallest available seat.
- We will maintain a priority queue for unreserved seats and use a simple counter to track the next available seat.
{{< dots >}}
### Edge Cases 🌐
- The input will always contain a valid n and a valid sequence of operations.
- The solution must handle the largest value of n (100,000) efficiently.
- Consider cases where unreserving a seat happens immediately after reserving the last available one.
- The operations are guaranteed to follow valid rules, with no unreserve called on an unreserved seat.
{{< dots >}}
## Code 💻
```cpp
int i, n;
priority_queue<int, vector<int>, greater<int>> pq;
SeatManager(int n) {
    i = 1;
    this->n = n;
}

int reserve() {
    if(pq.empty() && i > n) {
        return -1;
    }
    if(pq.empty()) {
        i++;
        return i - 1;
    }
    int tmp = pq.top();
    pq.pop();
    return tmp;
}

void unreserve(int no) {
    if(no == i - 1) {
        i--;
        return;
    }
    pq.push(no);
}
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
```

This code defines a `SeatManager` class with functions to reserve and unreserve seats using a priority queue. It handles seat assignment by tracking available seats and handling edge cases where no seats are available.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int i, n;
	```
	Defines two variables: `i` (current seat index) and `n` (total number of seats).

2. **Priority Queue Declaration**
	```cpp
	priority_queue<int, vector<int>, greater<int>> pq;
	```
	Declares a priority queue `pq` to manage available seat numbers in increasing order.

3. **Constructor**
	```cpp
	SeatManager(int n) {
	```
	Constructor that initializes the `SeatManager` object with a total of `n` seats.

4. **Constructor Logic**
	```cpp
	    i = 1;
	```
	Sets the starting seat index `i` to 1.

5. **Constructor Logic**
	```cpp
	    this->n = n;
	```
	Sets the total number of seats `n` based on the input argument.

6. **Reserve Function Start**
	```cpp
	int reserve() {
	```
	Defines the `reserve` function that reserves a seat and returns its seat number.

7. **Condition Check for Empty Queue and Full Seats**
	```cpp
	    if(pq.empty() && i > n) {
	```
	Checks if the priority queue is empty and all seats have been reserved.

8. **Return Statement**
	```cpp
	        return -1;
	```
	Returns -1 if no seats are available.

9. **Condition Check for Empty Queue**
	```cpp
	    }
	```
	End of the first if-condition.

10. **Reserve Logic**
	```cpp
	    if(pq.empty()) {
	```
	Checks if the priority queue is empty and there are still unreserved seats.

11. **Seat Allocation**
	```cpp
	        i++;
	```
	Increments the seat index `i` to allocate the next available seat.

12. **Seat Return**
	```cpp
	        return i - 1;
	```
	Returns the seat number `i - 1` after allocating it.

13. **Priority Queue Logic**
	```cpp
	    int tmp = pq.top();
	```
	Gets the seat number at the top of the priority queue (the smallest available seat).

14. **Priority Queue Update**
	```cpp
	    pq.pop();
	```
	Removes the seat number from the priority queue after it has been reserved.

15. **Seat Return**
	```cpp
	    return tmp;
	```
	Returns the reserved seat number from the priority queue.

16. **Unreserve Function Start**
	```cpp
	void unreserve(int no) {
	```
	Defines the `unreserve` function that releases a reserved seat.

17. **Condition Check for Last Reserved Seat**
	```cpp
	    if(no == i - 1) {
	```
	Checks if the seat to be unreserved is the last reserved seat.

18. **Seat Release**
	```cpp
	        i--;
	```
	Decrements the seat index `i` to reflect that the last reserved seat is now available.

19. **Unreserve Completion**
	```cpp
	        return;
	```
	Exits the function since the seat has been unreserved.

20. **Priority Queue Insertion**
	```cpp
	    pq.push(no);
	```
	Adds the unreserved seat number back to the priority queue.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log n)
- **Average Case:** O(log n)
- **Worst Case:** O(log n)

Both reserve and unreserve operations take O(log n) time due to the priority queue operations.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) as we store up to n seats in the priority queue.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/seat-reservation-manager/description/)

---
{{< youtube ahobllKXEEY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
