
+++
authors = ["grid47"]
title = "Leetcode 2034: Stock Price Fluctuation "
date = "2024-04-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2034: Stock Price Fluctuation  in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Design","Heap (Priority Queue)","Data Stream","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "iJqGjXpqdYo"
youtube_upload_date="2021-10-10"
youtube_thumbnail="https://i.ytimg.com/vi/iJqGjXpqdYo/maxresdefault.jpg"
comments = true
+++



---
You are given a stream of stock price records, where each record contains a timestamp and the corresponding price of the stock. The records may not be in order, and some records may contain errors that need to be corrected. Your task is to design an algorithm that updates the stock price at a given timestamp, finds the current price at the latest timestamp, and also finds the maximum and minimum prices the stock has been based on the current records.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a sequence of operations: 'update' to update the stock price at a timestamp, and queries like 'current', 'maximum', and 'minimum' to retrieve information about the stock price.
- **Example:** `[['StockPrice', 'update', 'update', 'current', 'maximum', 'update', 'maximum', 'update', 'minimum'], [[], [1, 10], [2, 5], [], [], [1, 3], [], [4, 2], []]]`
- **Constraints:**
	- 1 <= timestamp, price <= 10^9
	- At most 10^5 operations in total
	- 'current', 'maximum', and 'minimum' will be called only after at least one 'update' operation

{{< dots >}}
### Output Specifications 📤
- **Output:** The output consists of a list of results corresponding to each operation. For 'update' operations, the result is null. For 'current', 'maximum', and 'minimum' operations, the result is the respective stock price.
- **Example:** `[null, null, null, 5, 10, null, 5, null, 2]`
- **Constraints:**
	- Ensure that each operation is performed in constant or logarithmic time for efficient handling of up to 10^5 operations.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to implement a class that can handle stock price updates and queries efficiently, keeping track of the latest, maximum, and minimum stock prices.

- 1. Store the stock prices in a map, where the key is the timestamp and the value is the price.
- 2. For 'update' operations, if the timestamp already exists, update the price; otherwise, add a new entry for the timestamp.
- 3. Keep track of the maximum and minimum prices using additional variables or sorted data structures.
- 4. For 'current', 'maximum', and 'minimum' queries, simply return the corresponding price based on the latest records.
{{< dots >}}
### Problem Assumptions ✅
- The timestamps are positive integers and can be updated multiple times.
- The 'current', 'maximum', and 'minimum' queries will only occur after at least one 'update' operation.
{{< dots >}}
## Examples 🧩
- **Input:** `['StockPrice', 'update', 'update', 'current', 'maximum', 'update', 'maximum', 'update', 'minimum']`  \
  **Explanation:** In this example, the stock prices are updated at timestamps 1 and 2. The 'current' operation returns the latest price at timestamp 2, which is 5. The 'maximum' operation returns the highest price seen so far, which is 10. After updating the price at timestamp 1, the 'maximum' becomes 5, and after adding a price at timestamp 4, the 'minimum' becomes 2.

{{< dots >}}
## Approach 🚀
We need to efficiently track stock prices over time, taking care of updates at specific timestamps and providing queries for the latest, maximum, and minimum stock prices.

### Initial Thoughts 💭
- We need a way to quickly access the latest price, the maximum price, and the minimum price.
- Using a map to store the prices by timestamp allows for efficient updates and lookups.
- To efficiently track the maximum and minimum prices, we could use additional sorted data structures or simple comparisons.
{{< dots >}}
### Edge Cases 🌐
- Ensure that 'current', 'maximum', and 'minimum' operations do not occur before an 'update'.
- Handle cases where up to 10^5 operations are performed efficiently.
- Handle edge cases where timestamps and prices are at the extreme ends of their ranges.
- Ensure that the solution runs within time limits for large inputs.
{{< dots >}}
## Code 💻
```cpp
map<int, int> mp;

public:
StockPrice() {
    
}

void update(int ts, int pc) {
    if(mp.count(ts)) {
        strm.erase(pair<int, int>(ts, mp[ts]));

        ord.erase(pair<int, int>(mp[ts], ts));
    }
    mp[ts] = pc;
    strm.insert(pair<int, int>(ts, pc));
    ord.insert(pair<int,int>(pc, ts));
}

int current() {
   cout<< strm.size() <<endl;
    return rbegin(strm)->second;
}

int maximum() {
    return rbegin(ord)->first;
}

int minimum() {
    return begin(ord)->first;
}
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
```

This code defines a class `StockPrice` that allows you to update stock prices with timestamps and retrieve the current, maximum, and minimum stock prices.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	map<int, int> mp;
	```
	A map `mp` is initialized to store the stock prices with their corresponding timestamps.

2. **Function Definition**
	```cpp
	public:
	```
	The public section of the class is defined, which allows access to the methods and the object.

3. **Constructor**
	```cpp
	StockPrice() {
	```
	The constructor for the `StockPrice` class is defined, but it is currently empty.

4. **Function Definition**
	```cpp
	void update(int ts, int pc) {
	```
	This function updates the stock price for a given timestamp `ts` and price `pc`.

5. **Condition Checking**
	```cpp
	    if(mp.count(ts)) {
	```
	If the timestamp `ts` already exists in the map, the previous entry is erased.

6. **Map Erasing**
	```cpp
	        strm.erase(pair<int, int>(ts, mp[ts]));
	```
	Erase the previous entry from `strm` (a set or multiset that stores pairs of timestamp and price).

7. **Map Erasing**
	```cpp
	        ord.erase(pair<int, int>(mp[ts], ts));
	```
	Erase the previous entry from `ord` (a set or multiset that stores pairs of price and timestamp).

8. **Map Insertion**
	```cpp
	    mp[ts] = pc;
	```
	Update the stock price for the given timestamp `ts` with the new price `pc`.

9. **Map Insertion**
	```cpp
	    strm.insert(pair<int, int>(ts, pc));
	```
	Insert the updated timestamp and price into `strm`.

10. **Map Insertion**
	```cpp
	    ord.insert(pair<int,int>(pc, ts));
	```
	Insert the updated price and timestamp into `ord`.

11. **Function Definition**
	```cpp
	int current() {
	```
	This function returns the current stock price, which is the latest price in the `strm`.

12. **Return Statement**
	```cpp
	    return rbegin(strm)->second;
	```
	Return the current stock price, which is the last element in `strm` (ordered by timestamp).

13. **Function Definition**
	```cpp
	int maximum() {
	```
	This function returns the maximum stock price from `ord`.

14. **Return Statement**
	```cpp
	    return rbegin(ord)->first;
	```
	Return the maximum stock price, which is the first element in `ord` (ordered by price).

15. **Function Definition**
	```cpp
	int minimum() {
	```
	This function returns the minimum stock price from `ord`.

16. **Return Statement**
	```cpp
	    return begin(ord)->first;
	```
	Return the minimum stock price, which is the first element in `ord` (ordered by price).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) for 'current', 'maximum', and 'minimum' queries.
- **Average Case:** O(log N) for 'update' operations if sorted structures are used.
- **Worst Case:** O(log N) for 'update' and O(1) for queries.

The time complexity of the update operation is logarithmic due to sorting, and constant for 'current', 'maximum', and 'minimum' queries.

### Space Complexity 💾
- **Best Case:** O(N)
- **Worst Case:** O(N) for storing prices and tracking the maximum and minimum values.

The space complexity is O(N) due to the need to store the prices and potentially track maximum and minimum values.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/stock-price-fluctuation/description/)

---
{{< youtube iJqGjXpqdYo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
