
+++
authors = ["grid47"]
title = "Leetcode 729: My Calendar I"
date = "2024-08-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 729: My Calendar I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Design","Segment Tree","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/729.webp"
youtube = "fIxck3tlId4"
youtube_upload_date="2024-09-26"
youtube_thumbnail="https://i.ytimg.com/vi/fIxck3tlId4/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/729.webp" 
    alt="A calendar where events are added, with each event softly glowing as it is scheduled."
    caption="Solution to LeetCode 729: My Calendar I Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are implementing a calendar application where you can add events. Each event has a start time and end time represented by a half-open interval [start, end). An event can only be added if it does not overlap with existing events in the calendar. Return true if the event can be booked successfully, and false if it causes a conflict.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of method calls with parameters. The first call is always initializing the MyCalendar object, followed by calls to the book method.
- **Example:** `Input: ["MyCalendar", "book", "book", "book"] [[], [10, 20], [15, 25], [20, 30]]`
- **Constraints:**
	- 0 <= start < end <= 10^9
	- At most 1000 calls will be made to book.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output will be an array of results for each call. For the MyCalendar initialization, the result will be null, and for each book method call, the result will be a boolean indicating whether the event was successfully booked or not.
- **Example:** `Output: [null, true, false, true]`
- **Constraints:**
	- For each call to book, return true if the event can be booked, false otherwise.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to implement a calendar that checks for overlapping events and returns whether a new event can be added without causing a conflict.

- 1. Create a map or structure to store the events, with start times as the key.
- 2. For each new event, check if it overlaps with any existing event.
- 3. If no overlap is found, add the event to the calendar and return true.
- 4. If overlap is found, return false and do not add the event.
{{< dots >}}
### Problem Assumptions ✅
- The input start and end times are integers, and the events are well-formed.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: ["MyCalendar", "book", "book", "book"] [[], [10, 20], [15, 25], [20, 30]]`  \
  **Explanation:** In the first example, the first event is successfully booked as no previous events exist. The second event cannot be booked as it overlaps with the first event. The third event is successfully booked since it does not overlap with the first event (ends at 20).

{{< dots >}}
## Approach 🚀
The approach involves maintaining a data structure to track events and efficiently checking for overlaps when booking a new event.

### Initial Thoughts 💭
- We need to efficiently store and check for overlapping intervals.
- Using a map structure will help track the intervals and quickly check for any conflicts.
{{< dots >}}
### Edge Cases 🌐
- If no events have been booked yet, any new event can be booked.
- Ensure the solution handles up to 1000 booking attempts efficiently.
- Consider cases where the start and end times are very close, or the events have minimal overlap.
- The solution must be able to handle start and end times within the range of [0, 10^9].
{{< dots >}}
## Code 💻
```cpp
public:
MyCalendar() {
    
}

bool book(int start, int end) {
    auto nxt = mp.upper_bound(start);
    if (nxt != mp.end() && (*nxt).second < end) {
        return false;
    }
    mp[end] = start;
    return true;
}
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
```

This is the implementation of the MyCalendar class which supports booking time intervals. The method 'book' ensures that the new booking does not overlap with any existing bookings.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Access Modifier**
	```cpp
	public:
	```
	Defines the access level for the members that follow, making them accessible to other parts of the program.

2. **Constructor**
	```cpp
	MyCalendar() {
	```
	Constructor for the MyCalendar class. Initializes the calendar object.

3. **Method Definition**
	```cpp
	bool book(int start, int end) {
	```
	Defines the 'book' method which attempts to schedule a new booking from 'start' to 'end'.

4. **Variable Declaration**
	```cpp
	    auto nxt = mp.upper_bound(start);
	```
	Uses 'upper_bound' to find the first event in 'mp' that starts after the 'start' time.

5. **Conditional Check**
	```cpp
	    if (nxt != mp.end() && (*nxt).second < end) {
	```
	Checks if there is an existing booking that overlaps with the new booking.

6. **Return Statement**
	```cpp
	        return false;
	```
	If an overlap is detected, return false to indicate the booking was not successful.

7. **Map Update**
	```cpp
	    mp[end] = start;
	```
	Records the new booking in the map 'mp', where 'end' is the key and 'start' is the value.

8. **Return Statement**
	```cpp
	    return true;
	```
	If no overlap is found, return true to indicate the booking was successful.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log N)
- **Average Case:** O(log N)
- **Worst Case:** O(N)

In the worst case, we check all the events for conflicts, making the time complexity O(N), where N is the number of events. A more efficient approach could be implemented using a balanced tree or interval tree for quicker access.

### Space Complexity 💾
- **Best Case:** O(N)
- **Worst Case:** O(N)

The space complexity is O(N) as we store all booked events in the calendar.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/my-calendar-i/description/)

---
{{< youtube fIxck3tlId4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
