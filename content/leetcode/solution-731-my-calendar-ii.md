
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
comments = true
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
You are implementing a calendar system where you can add events. Each event is represented by a start time and an end time, defined as a half-open interval [startTime, endTime). You need to ensure that no more than two events overlap at any given time, or else return false. Your task is to implement a class, MyCalendarTwo, that will book events while preventing triple bookings.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of method calls with parameters. The first call is always the initialization of the MyCalendarTwo object, followed by calls to the book method.
- **Example:** `Input: ["MyCalendarTwo", "book", "book", "book", "book", "book", "book"] [[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]`
- **Constraints:**
	- 0 <= start < end <= 10^9
	- At most 1000 calls will be made to book.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output will be an array of boolean values for each call. The first call to the MyCalendarTwo constructor returns null. For each book method call, return true if the event can be booked without causing a triple booking, and false otherwise.
- **Example:** `Output: [null, true, true, true, false, true, true]`
- **Constraints:**
	- The response for each book method call is a boolean indicating whether the event was successfully booked or not.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to design a method that tracks the number of overlapping events at any time and ensures that no more than two events overlap.

- 1. Use a data structure to track the number of events occurring at any given time.
- 2. For each new booking, update the event count at the corresponding start and end times.
- 3. Check if the number of overlapping events exceeds 2 at any point.
- 4. If more than two events overlap, revert the booking and return false. Otherwise, return true.
{{< dots >}}
### Problem Assumptions ✅
- The start and end times of events are valid integers, and events are well-formed.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: ["MyCalendarTwo", "book", "book", "book", "book", "book", "book"] [[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]`  \
  **Explanation:** In this example, the first three events are successfully booked as they do not overlap more than twice. The fourth event fails as it causes a triple booking. The fifth event is booked because it only overlaps with one event at any time.

{{< dots >}}
## Approach 🚀
The approach involves using a data structure to track and manage overlapping events, ensuring no triple booking occurs.

### Initial Thoughts 💭
- We need a way to efficiently count overlapping events at any point in time.
- We can use a map to track the number of active events at any given time. This will allow us to quickly determine if adding a new event causes a triple booking.
{{< dots >}}
### Edge Cases 🌐
- If no events are booked yet, any event can be booked.
- Ensure the solution efficiently handles up to 1000 booking attempts.
- Consider events with very close start and end times that could overlap very slightly.
- The solution must handle start and end times within the range of [0, 10^9].
{{< dots >}}
## Code 💻
```cpp
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
```

This is the implementation of a calendar system that tracks events and ensures no more than two events overlap at the same time.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method Declaration**
	```cpp
	public:
	```
	Access modifier specifying that the following methods are publicly accessible.

2. **Constructor**
	```cpp
	MyCalendarTwo() {
	```
	Constructor for the MyCalendarTwo class, initializing the object.

3. **Empty Block**
	```cpp
	    
	```
	Empty line for spacing, no code here.

4. **End Block**
	```cpp
	}
	```
	Closing bracket to end the constructor.

5. **Method Declaration**
	```cpp
	bool book(int start, int end) {
	```
	Declaring the 'book' method, which checks if a new event can be booked.

6. **Update Map**
	```cpp
	    mp[start]++;
	```
	Increments the count for the 'start' time in the map, indicating the start of an event.

7. **Update Map**
	```cpp
	    mp[end]--;
	```
	Decrements the count for the 'end' time in the map, indicating the end of an event.

8. **Variable Declaration**
	```cpp
	    int bkd = 0;
	```
	Declares an integer variable 'bkd' to keep track of the number of overlapping events.

9. **ForLoop**
	```cpp
	    for(auto it =mp.begin(); it != mp.end(); it++) {
	```
	Iterates over the events in the map to check the number of overlapping events.

10. **Update Variable**
	```cpp
	        bkd += it->second;
	```
	Adds the value from the current map entry to 'bkd' to track the current overlap count.

11. **If Statement**
	```cpp
	        if(bkd == 3) {
	```
	Checks if the number of overlapping events has reached 3 (i.e., more than 2 overlapping events).

12. **Update Map**
	```cpp
	            mp[start]--;
	```
	Decrements the count for the 'start' time, effectively canceling the booking.

13. **Update Map**
	```cpp
	            mp[end]++;
	```
	Increments the count for the 'end' time to reflect the cancellation.

14. **Return Statement**
	```cpp
	            return false;
	```
	Returns 'false' to indicate that the booking cannot be made due to too many overlapping events.

15. **Return Statement**
	```cpp
	    return true;
	```
	Returns 'true' to indicate that the booking was successful.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log N)
- **Average Case:** O(log N)
- **Worst Case:** O(N)

In the worst case, we check all events for conflicts, making the time complexity O(N), where N is the number of events.

### Space Complexity 💾
- **Best Case:** O(N)
- **Worst Case:** O(N)

The space complexity is O(N) as we store the number of events in the calendar.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/my-calendar-ii/description/)

---
{{< youtube 7utL5cTDcnA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
