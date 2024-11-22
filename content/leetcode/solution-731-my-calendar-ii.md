
+++
authors = ["grid47"]
title = "Leetcode 731: My Calendar II"
date = "2024-08-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 731: My Calendar II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Design","Segment Tree","Prefix Sum","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/731.webp"
youtube = "7utL5cTDcnA"
youtube_upload_date="2024-09-27"
youtube_thumbnail="https://i.ytimg.com/vi/7utL5cTDcnA/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/731.webp" 
    alt="A calendar with overlapping events, where conflicts are highlighted and softly glowing to indicate double-booking."
    caption="Solution to LeetCode 731: My Calendar II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class MyCalendarTwo {
    map<int, int> mp;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int bkd = 0;
    
        
        for(auto it =mp.begin(); it != mp.end(); it++) {
            
            bkd += it->second;
            
            if(bkd == 3) {
                
                mp[start]--;
                mp[end]++;
                
                return false;
            }
        }
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
{{< /highlight >}}
---

### Problem Statement

The problem involves designing a calendar system where events can be booked, and there are no restrictions on double bookings. However, the challenge arises when trying to handle triple bookings (i.e., when more than two events overlap). Your task is to implement a data structure that supports booking events, with the constraint that no more than two events can overlap at the same time.

### Approach

To solve this problem efficiently, we can use a **map** (or dictionary) to store the changes in the number of active bookings at each time point. The idea is to track the "events" of when an event starts and ends, and adjust a counter that reflects the number of overlapping events at any given moment.

The key operations in this approach involve:
1. **Incrementing a counter when an event starts**.
2. **Decrementing the counter when an event ends**.
3. **Checking if the current booking causes three simultaneous bookings at any time**. If it does, we undo the booking attempt.

We use a **map** to maintain these events, where the keys represent the times (both start and end times), and the values represent the change in the count of overlapping events at that particular time.

### Code Breakdown (Step by Step)

#### 1. **Class Definition and Data Structures**
   - The class `MyCalendarTwo` is defined with a private member `map<int, int> mp;`. The map `mp` will store the time points (start and end times of events) as keys, and the values will represent the changes in the booking count.
   
   ```cpp
   class MyCalendarTwo {
       map<int, int> mp;
   public:
       MyCalendarTwo() {}
   ```

   - The map is initialized in the constructor, and we will use it to keep track of the bookings.

#### 2. **The `book` Function**
   The `book` function is the core of the solution. It handles the task of adding a new booking (with `start` and `end` times), and ensuring that no more than two events overlap at any time.

   ```cpp
   bool book(int start, int end) {
       mp[start]++;  // Increment the count at the start time
       mp[end]--;    // Decrement the count at the end time
   ```

   - The `start` time is incremented by 1, and the `end` time is decremented by 1. This effectively marks the beginning and end of an event.

#### 3. **Checking for Triple Bookings**
   After updating the map, we need to check if the new event causes any point in time to have more than two overlapping events. We do this by iterating through the map and maintaining a running sum of the bookings.

   ```cpp
   int bkd = 0;  // To keep track of the current number of active bookings
   for (auto it = mp.begin(); it != mp.end(); it++) {
       bkd += it->second;  // Update the number of active bookings at the current time
       
       if (bkd == 3) {  // If there are 3 bookings at the same time
           mp[start]--;  // Undo the booking by decrementing the start time
           mp[end]++;    // Undo the booking by incrementing the end time
           return false; // Return false because triple booking is not allowed
       }
   }
   ```

   - The variable `bkd` tracks the cumulative count of overlapping events as we iterate through the map.
   - If at any point the value of `bkd` reaches 3, it means that three events overlap, and thus we cannot book the current event. In this case, we undo the booking attempt by decrementing the `start` time and incrementing the `end` time.
   - The function returns `false` if a triple booking occurs, indicating that the booking could not be completed.

#### 4. **Successful Booking**
   If no triple booking occurs during the iteration, the event is successfully booked, and the function returns `true` to indicate success.

   ```cpp
   return true;
   ```

#### 5. **Class Usage**
   The class can be used by first creating an instance of `MyCalendarTwo` and then calling the `book` function for each event to be booked.

   ```cpp
   MyCalendarTwo* obj = new MyCalendarTwo();
   bool param_1 = obj->book(start, end);
   ```

   The `book` function is called with the `start` and `end` times of the event, and it returns `true` if the event is successfully booked, or `false` if the event causes a triple booking.

### Complexity Analysis

#### Time Complexity:
- **O(log n)** for each booking operation, where `n` is the number of distinct time points in the map. This is because the map is implemented as a balanced binary search tree (e.g., `std::map` in C++), which allows for logarithmic time complexity for both insertion and iteration operations.
- Specifically:
  - Inserting a new event (incrementing the start time and decrementing the end time) takes O(log n) time.
  - Iterating through the map to check the number of overlapping events takes O(log n) time as well, since the map’s size can grow proportionally to the number of events booked.

#### Space Complexity:
- **O(n)**, where `n` is the number of events. In the worst case, each event might introduce a new unique time point in the map, so the space complexity is proportional to the number of events booked.

### Conclusion

The `MyCalendarTwo` class efficiently handles event bookings while ensuring that no more than two events overlap at any given time. By using a map to track the start and end times of events and applying the concept of a running sum to count the number of overlapping events, the class is able to detect and prevent triple bookings in logarithmic time. This approach optimizes both time and space complexity, making it scalable for large numbers of event bookings.

The use of a **map** ensures that the operations of insertion and iteration are efficient, and the overall time complexity of O(log n) per booking operation is optimal for this type of problem. Additionally, by applying a straightforward check for triple bookings, the algorithm guarantees that no more than two events can overlap at the same time. The `book` function ensures that users are informed if their booking request cannot be processed due to conflicting events, making the class both efficient and easy to use in scenarios where event scheduling is required.

[`Link to LeetCode Lab`](https://leetcode.com/problems/my-calendar-ii/description/)

---
{{< youtube 7utL5cTDcnA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
