
+++
authors = ["grid47"]
title = "Leetcode 1396: Design Underground System"
date = "2024-06-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1396: Design Underground System in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Design"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "W5QOLqXskZM"
youtube_upload_date="2023-05-31"
youtube_thumbnail="https://i.ytimg.com/vi/W5QOLqXskZM/maxresdefault.jpg"
comments = true
+++



---
You are tasked with building a system to track customer travel times within an underground railway network. The system should calculate the average time taken to travel between two stations based on previous trips. Implement the `UndergroundSystem` class with the following methods.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of several commands, each one representing a method call to the UndergroundSystem class. Each command is represented as an array where the first element is the method name, and the rest are its respective arguments.
- **Example:** `["UndergroundSystem", "checkIn", "checkOut", "getAverageTime"]`
- **Constraints:**
	- 1 <= id, t <= 10^6
	- 1 <= stationName.length <= 10
	- All strings consist of uppercase and lowercase English letters and digits.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output for each method call will be either null (for checkIn and checkOut methods) or a double representing the average time for the given trip (for getAverageTime).
- **Example:** `[null, null, 10.00000]`
- **Constraints:**
	- Answers within 10^-5 of the actual value will be accepted.

{{< dots >}}
### Core Logic 🔍
**Goal:** To efficiently track and calculate the average travel times between stations.

- 1. Use a map to store the check-in times and stations for each customer.
- 2. When a customer checks out, calculate the travel time and update the sum and count of trips between stations.
- 3. To calculate the average time between two stations, divide the total time by the number of trips between the stations.
{{< dots >}}
### Problem Assumptions ✅
- All method calls will be valid and in chronological order.
- No customer will check in or check out at the same time.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: ["UndergroundSystem", "checkIn", "checkOut", "getAverageTime"]`  \
  **Explanation:** In this example, we simulate customers checking in and out of stations and calculating average travel times.

{{< dots >}}
## Approach 🚀
The approach involves tracking each customer's check-in and check-out times, updating a map of total travel times and counts for each trip, and calculating the average when requested.

### Initial Thoughts 💭
- Efficiently managing check-in and check-out events will be crucial for large datasets.
- Use maps for storing check-in and check-out data to ensure fast access.
- Focus on optimizing the update of travel times and counts for each station pair.
{{< dots >}}
### Edge Cases 🌐
- What if no customer checks in before calling `getAverageTime`?
- Ensure the system handles up to 20,000 method calls efficiently.
- Handle cases where a customer checks in and out multiple times for the same station pair.
- The system should work with varying customer IDs and station names.
{{< dots >}}
## Code 💻
```cpp
string station;
};

class UndergroundSystem {
public:
map<string, map<string, double>> cnt, sum;
map<int, Node> user;
UndergroundSystem() {
    
}

void checkIn(int id, string name, int t) {
    Node n;
    n.time = t;
    n.station = name;
    user[id] = n;
}

void checkOut(int id, string name, int t) {
    Node entry = user[id];
    cout << user[id].station;
    user.erase(id);
    cnt[entry.station][name]++;
    sum[entry.station][name]+= t - entry.time;
}

double getAverageTime(string start, string end) {
    return sum[start][end] / cnt[start][end];
}
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
```

This code defines the `UndergroundSystem` class that tracks the average travel time between pairs of stations, utilizing check-in and check-out functions.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	string station;
	```
	Declaring a string variable `station` to hold the station name for each user.

2. **Class Definition**
	```cpp
	class UndergroundSystem {
	```
	Beginning of the `UndergroundSystem` class definition.

3. **Access Control**
	```cpp
	public:
	```
	Public access specifier for methods and variables that follow.

4. **Map Operations**
	```cpp
	map<string, map<string, double>> cnt, sum;
	```
	Declaring two nested maps to track the count of rides (`cnt`) and the sum of times (`sum`) between station pairs.

5. **Map Operations**
	```cpp
	map<int, Node> user;
	```
	A map to store the user data by their unique ID.

6. **Constructor**
	```cpp
	UndergroundSystem() {
	```
	Constructor for the `UndergroundSystem` class, initializing necessary data structures.

7. **Method Definition**
	```cpp
	void checkIn(int id, string name, int t) {
	```
	Defines the `checkIn` method to record a user's entry at a station.

8. **Variable Initialization**
	```cpp
	    Node n;
	```
	Creates a `Node` object to store information about the user's check-in.

9. **Variable Assignment**
	```cpp
	    n.time = t;
	```
	Assigns the time of check-in to the `Node` object.

10. **Variable Assignment**
	```cpp
	    n.station = name;
	```
	Assigns the station name to the `Node` object.

11. **Data Insertion**
	```cpp
	    user[id] = n;
	```
	Inserts the user data into the `user` map with the user ID as the key.

12. **Method Definition**
	```cpp
	void checkOut(int id, string name, int t) {
	```
	Defines the `checkOut` method to record when a user exits a station.

13. **Data Retrieval**
	```cpp
	    Node entry = user[id];
	```
	Retrieves the user's check-in data from the `user` map.

14. **Data Deletion**
	```cpp
	    user.erase(id);
	```
	Removes the user from the `user` map after checking out.

15. **Map Operations**
	```cpp
	    cnt[entry.station][name]++;
	```
	Increments the count of rides between stations in the `cnt` map.

16. **Map Operations**
	```cpp
	    sum[entry.station][name]+= t - entry.time;
	```
	Adds the time spent during the ride to the `sum` map.

17. **Method Definition**
	```cpp
	double getAverageTime(string start, string end) {
	```
	Defines the `getAverageTime` method to calculate the average time between two stations.

18. **Return Statement**
	```cpp
	    return sum[start][end] / cnt[start][end];
	```
	Returns the average time by dividing the sum by the count of rides.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) for getAverageTime when there is only one trip.
- **Average Case:** O(1) for getAverageTime, O(log N) for checkIn and checkOut operations.
- **Worst Case:** O(N) for getAverageTime in cases where many trips are recorded.



### Space Complexity 💾
- **Best Case:** O(1) for operations with minimal data.
- **Worst Case:** O(N) for storing customer and trip data.



**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/design-underground-system/description/)

---
{{< youtube W5QOLqXskZM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
