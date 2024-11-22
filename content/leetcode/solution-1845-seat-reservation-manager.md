
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
+++



---
**Code:**

{{< highlight cpp >}}
class SeatManager {
public:
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
 */
{{< /highlight >}}
---

### Problem Statement

The problem requires us to manage seat reservations in a theater or an event venue. We need to implement a `SeatManager` class that supports two primary operations: reserving a seat and unreserving a seat. The goal is to efficiently manage available seats, ensuring that when a seat is reserved, it's marked as unavailable, and when it is unreserved, it becomes available for future reservations. The reservation system should allow for a maximum number of seats, and the operations should be efficient in terms of time complexity.

### Approach

To solve this problem, we can use a combination of a priority queue and a simple counter. The priority queue will help manage the available seats efficiently, while the counter will track the next available seat number. The operations can be outlined as follows:

1. **Initialization**: When the `SeatManager` is instantiated, we initialize the total number of seats and set up a priority queue to manage unreserved seats.

2. **Reserve Seat**:
   - If there are no available seats in the priority queue, we check if there are still seats left to reserve using the counter. If so, we increment the counter and return the next seat number.
   - If there are available seats in the priority queue, we pop the top element (the smallest available seat number) and return it as the reserved seat.

3. **Unreserve Seat**:
   - When a seat is unreserved, we need to add it back to the pool of available seats. If the seat being unreserved is the last reserved seat (tracked by the counter), we simply decrement the counter.
   - If it's not the last reserved seat, we push the seat number back into the priority queue to make it available for future reservations.

### Code Breakdown (Step by Step)

```cpp
class SeatManager {
public:
    int i, n;
    priority_queue<int, vector<int>, greater<int>> pq;
```
- We define the `SeatManager` class. It has two member variables: `i`, which tracks the next available seat number, and `n`, which stores the total number of seats. A priority queue `pq` is used to keep track of unreserved seats.

```cpp
    SeatManager(int n) {
        i = 1; // Start seat numbering from 1
        this->n = n; // Set the total number of seats
    }
```
- The constructor initializes the number of seats (`n`) and sets the counter `i` to 1, indicating that the first seat is available for reservation.

```cpp
    int reserve() {
        if(pq.empty() && i > n) {
            return -1; // No available seats
        }
        if(pq.empty()) {
            i++; // Increment the counter for the next seat
            return i - 1; // Return the last reserved seat
        }
```
- The `reserve` method first checks if there are no available seats. If the priority queue is empty and the counter has exceeded the number of seats, it returns -1 indicating no seats are available.
- If there are no seats in the priority queue, we increment the counter and return the last reserved seat number.

```cpp
        int tmp = pq.top();
        pq.pop(); // Pop the top available seat from the priority queue
        return tmp; // Return the reserved seat number
    }
```
- If there are available seats in the priority queue, we retrieve and remove the smallest seat number, which indicates an available seat, and return it.

```cpp
    void unreserve(int no) {
        if(no == i - 1) {
            i--; // If unreserving the last reserved seat, decrement the counter
            return;
        }
        pq.push(no); // Otherwise, push the seat number back into the priority queue
    }
};
```
- The `unreserve` method checks if the seat number being unreserved is the last one reserved (tracked by `i`). If so, it simply decrements the counter. Otherwise, it adds the seat back into the priority queue to mark it as available.

### Complexity

- **Time Complexity**:
  - The time complexity for both `reserve` and `unreserve` operations is \( O(\log m) \), where \( m \) is the number of unreserved seats. This is due to the priority queue operations of inserting and removing elements.
  
- **Space Complexity**:
  - The space complexity is \( O(m) \) for storing the unreserved seats in the priority queue.

### Conclusion

The `SeatManager` class efficiently manages seat reservations using a priority queue, allowing for quick allocation and deallocation of seats. By employing a simple counter to track the next available seat and a priority queue for managing unreserved seats, the implementation provides optimal performance for both reservation and unreservation operations.

This design is particularly beneficial in scenarios such as theaters, concert halls, or any event where seat management is crucial. The logic is easy to understand, and the code is concise, making it suitable for real-world applications. The flexibility of the priority queue allows for a dynamic approach to managing available seats, ensuring that the operations remain efficient even as the number of reservations fluctuates. 

In conclusion, the `SeatManager` implementation exemplifies an effective combination of data structures to solve a practical problem in seat management, showcasing good coding practices and a robust approach to handling dynamic state changes in a system.

[`Link to LeetCode Lab`](https://leetcode.com/problems/seat-reservation-manager/description/)

---
{{< youtube ahobllKXEEY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
