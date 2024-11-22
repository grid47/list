
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
+++



---
**Code:**

{{< highlight cpp >}}
struct Node {
    int time;
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
 */
{{< /highlight >}}
---

### Problem Statement

The problem is to implement a system that tracks the check-in and check-out times of passengers at various stations in an underground transportation system. The goal is to allow passengers to check in and out at different stations while being able to retrieve the average travel time between any two stations. This system involves managing user data effectively and calculating average travel times based on the recorded check-in and check-out times.

### Approach

To address this problem, we utilize a class-based design in C++, leveraging several data structures to efficiently store and manage passenger data and travel times. The following are the key components of our approach:

1. **Data Structures**:
   - **Maps**: We use two maps:
     - `cnt`: A nested map that tracks the count of trips between stations. The outer map uses the starting station as the key, while the inner map uses the destination station as the key to store the number of trips taken between the two stations.
     - `sum`: Another nested map that keeps the total travel time for each trip between stations. This allows us to compute the average travel time efficiently.
   - **Node Struct**: A simple struct `Node` is defined to store the check-in time and station name for each passenger, enabling easy retrieval of check-in information when the passenger checks out.

2. **Check-In and Check-Out Logic**:
   - **Check-In**: When a passenger checks in, we record their ID, station, and time in a map (`user`). The passenger's information is stored in a `Node` instance associated with their ID.
   - **Check-Out**: Upon checking out, we retrieve the passenger's check-in information, calculate the travel time, update the `cnt` and `sum` maps accordingly, and remove the passenger's data from the `user` map.

3. **Average Travel Time Calculation**: 
   - The `getAverageTime` function computes the average travel time between two stations by dividing the total travel time by the count of trips. This provides an efficient way to return results for any queried route.

### Code Breakdown (Step by Step)

Here’s a detailed step-by-step breakdown of the provided C++ code:

1. **Node Struct Definition**:
   ```cpp
   struct Node {
       int time;
       string station;
   };
   ```
   - A `Node` structure is defined to hold the check-in time and station name.

2. **Class Definition**:
   ```cpp
   class UndergroundSystem {
   public:
       map<string, map<string, double>> cnt, sum;
       map<int, Node> user;
   ```
   - The `UndergroundSystem` class is defined. It contains:
     - `cnt`: A map for counting trips between stations.
     - `sum`: A map for summing travel times between stations.
     - `user`: A map that holds the check-in information for each passenger based on their ID.

3. **Constructor**:
   ```cpp
       UndergroundSystem() {
       }
   ```
   - A default constructor initializes the class instance. No additional setup is required at this point.

4. **Check-In Method**:
   ```cpp
       void checkIn(int id, string name, int t) {
           Node n;
           n.time = t;
           n.station = name;
           user[id] = n;
       }
   ```
   - The `checkIn` method takes the passenger's ID, station name, and time as parameters.
   - A `Node` is created to store the current station and time.
   - This node is then stored in the `user` map using the passenger ID as the key.

5. **Check-Out Method**:
   ```cpp
       void checkOut(int id, string name, int t) {
           Node entry = user[id];
           cout << user[id].station; // Debug line (can be removed)
           user.erase(id);
           cnt[entry.station][name]++;
           sum[entry.station][name]+= t - entry.time;
       }
   ```
   - The `checkOut` method retrieves the passenger’s check-in information using their ID.
   - It calculates the travel time by subtracting the check-in time from the current time.
   - The counts and sums for trips between the checked-in and checked-out stations are updated.
   - The passenger’s information is removed from the `user` map.

6. **Average Time Calculation Method**:
   ```cpp
       double getAverageTime(string start, string end) {
           return sum[start][end] / cnt[start][end];
       }
   ```
   - The `getAverageTime` method takes the starting and ending station names as parameters.
   - It calculates the average time by dividing the total travel time (stored in `sum`) by the count of trips (stored in `cnt`).
   - The average travel time is returned as a double.

7. **Usage**:
   ```cpp
   /**
    * Your UndergroundSystem object will be instantiated and called as such:
    * UndergroundSystem* obj = new UndergroundSystem();
    * obj->checkIn(id,stationName,t);
    * obj->checkOut(id,stationName,t);
    * double param_3 = obj->getAverageTime(startStation,endStation);
    */
   ```
   - This section outlines how to create an instance of `UndergroundSystem` and how to use the provided methods.

### Complexity

- **Time Complexity**:
  - **Check-In and Check-Out**: Both operations run in \( O(1) \) time on average due to direct access to hash maps.
  - **Get Average Time**: This operation also runs in \( O(1) \) since it involves direct access to the maps for the sum and count.

- **Space Complexity**:
  - The space complexity is \( O(n) \), where \( n \) is the number of unique passengers checked in and the number of routes taken between stations. This is due to the storage requirements for the maps.

### Conclusion

This implementation of the underground system efficiently manages passenger check-ins and check-outs while providing quick access to average travel times between stations. 

Key takeaways from this solution include:

- **Efficient Data Management**: Using maps to store counts and sums allows for efficient aggregation of travel times.
- **Clear Separation of Responsibilities**: The code cleanly separates the logic for check-in, check-out, and average time calculation, improving readability and maintainability.
- **Utilization of Structs**: The `Node` struct provides a clean way to encapsulate the check-in information for passengers, making the code easier to understand.

Overall, this design demonstrates effective use of data structures and algorithms to solve a real-world problem, making it suitable for applications in transportation systems and other domains requiring similar functionalities.

[`Link to LeetCode Lab`](https://leetcode.com/problems/design-underground-system/description/)

---
{{< youtube W5QOLqXskZM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
