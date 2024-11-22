
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
+++



---
**Code:**

{{< highlight cpp >}}
class StockPrice {
    set<pair<int, int>> strm, ord;
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
 */
{{< /highlight >}}
---

### Problem Statement

The task involves creating a `StockPrice` class that keeps track of stock prices over time, allowing us to:
1. Update the stock price at a specific timestamp.
2. Retrieve the most recent price.
3. Retrieve the maximum price recorded.
4. Retrieve the minimum price recorded.

Each update can replace an existing price if there’s already one recorded for a given timestamp.

### Approach

We use three main data structures:
1. A **map** (`mp`) to store the price associated with each timestamp.
2. A **set** (`strm`) to keep timestamps in order, which helps us retrieve the most recent price.
3. Another **set** (`ord`) to keep prices sorted, allowing efficient retrieval of the maximum and minimum prices.

This approach ensures that:
- `current()` retrieves the latest timestamp's price from `strm`.
- `maximum()` and `minimum()` fetch the highest and lowest prices directly from `ord`.

### Code Breakdown (Step by Step)

```cpp
class StockPrice {
    set<pair<int, int>> strm, ord;
    map<int, int> mp;
    
public:
    StockPrice() { }
```

- We declare a `StockPrice` class and initialize three data structures:
  - `strm`: A set of pairs representing `(timestamp, price)` for chronological ordering.
  - `ord`: A set of pairs representing `(price, timestamp)` for direct access to min/max prices.
  - `mp`: A map for associating each `timestamp` with its `price`, making it easy to check and update existing records.

```cpp
    void update(int ts, int pc) {
        if(mp.count(ts)) {
            strm.erase(pair<int, int>(ts, mp[ts]));
            ord.erase(pair<int, int>(mp[ts], ts));
        }
```

- `update` takes `ts` (timestamp) and `pc` (price). If there’s already a price at `ts`, we:
  - Erase the old timestamp-price pair from `strm`.
  - Erase the old price-timestamp pair from `ord`.

```cpp
        mp[ts] = pc;
        strm.insert(pair<int, int>(ts, pc));
        ord.insert(pair<int,int>(pc, ts));
    }
```

- We update `mp` with the new price for `ts`, then insert the new `(timestamp, price)` into `strm` and the `(price, timestamp)` pair into `ord`.

```cpp
    int current() {
       return rbegin(strm)->second;
    }
```

- `current()` retrieves the latest price by accessing the last element of `strm`, which holds the highest timestamp (most recent).

```cpp
    int maximum() {
        return rbegin(ord)->first;
    }
    
    int minimum() {
        return begin(ord)->first;
    }
};
```

- `maximum()` returns the largest price from `ord` by accessing its last element.
- `minimum()` returns the smallest price from `ord` by accessing its first element.

### Complexity

- **Time Complexity**:
  - **update()**: O(log n) for insertions and deletions in `set` and `map`.
  - **current(), maximum(), minimum()**: O(1) for retrieving the respective elements.
  
- **Space Complexity**: O(n), where `n` is the number of timestamps, due to storage in `map` and `set`.

### Conclusion

The `StockPrice` class offers an efficient way to manage and retrieve stock prices across timestamps. Using sorted data structures (`set` and `map`), we achieve fast operations to update, retrieve current, max, and min prices. This structure minimizes retrieval time, making it effective for real-time applications where updates and queries are frequent.

[`Link to LeetCode Lab`](https://leetcode.com/problems/stock-price-fluctuation/description/)

---
{{< youtube iJqGjXpqdYo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
