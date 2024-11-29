
+++
authors = ["grid47"]
title = "Leetcode 2146: K Highest Ranked Items Within a Price Range"
date = "2024-04-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2146: K Highest Ranked Items Within a Price Range in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Breadth-First Search","Sorting","Heap (Priority Queue)","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "OOBGOENJLYo"
youtube_upload_date="2022-01-22"
youtube_thumbnail="https://i.ytimg.com/vi/OOBGOENJLYo/maxresdefault.jpg"
comments = true
+++



---
You are given a 2D grid representing a shop map with walls, empty spaces, and items with prices. Your task is to find the top `k` highest-ranked items within a given price range. The ranking is based on distance, price, row, and column number.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are provided with a 2D grid, a pricing array, a start position, and an integer `k`. The pricing array specifies the price range of items to consider.
- **Example:** ``
- **Constraints:**

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the top `k` highest-ranked items whose prices are within the specified range, ranked by distance, price, row, and column.
- **Example:** ``
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To compute the top `k` highest-ranked items based on the given ranking criteria.

- Start at the given position in the grid.
- Perform a BFS to explore reachable items.
- Filter items whose prices are within the given range.
- Sort items by their rank (distance, price, row, column).
- Return the top `k` items.
{{< dots >}}
### Problem Assumptions ✅
- The grid is not empty.
- There are reachable items within the given price range.
{{< dots >}}
## Examples 🧩
- **Input:** `For the input grid `[[2, 5, 1], [4, 6, 7]]` with pricing `[3, 6]`, start `[0, 0]`, and `k = 2`, the expected output is `[[0, 1], [1, 0]]`.`  \
  **Explanation:** Items within the price range [3, 6] are sorted by distance first, then by price, and so on.

{{< dots >}}
## Approach 🚀
To solve the problem, we need to perform a BFS to explore all reachable items and then sort them by the given ranking criteria.

### Initial Thoughts 💭
- We can use BFS to explore reachable grid cells.
- We need to prioritize items that are within the given price range.
- BFS allows us to explore the grid efficiently, while the priority queue helps in ranking items based on the specified criteria.
{{< dots >}}
### Edge Cases 🌐
- Ensure the grid is not empty.
- Consider large grids and ensure the solution scales efficiently.
- Handle cases where there are fewer than `k` reachable items.
- Ensure the grid boundaries are respected and no out-of-bound access occurs.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& price, vector<int>& start, int k) {

    int m = grid.size(), n = grid[0].size();
    queue<vector<int>> q;
    q.push(start);

    int dist = 0;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;        
    if(grid[start[0]][start[1]] >= price[0] && grid[start[0]][start[1]] <= price[1])
        pq.push({dist, grid[start[0]][start[1]], start[0], start[1]});
        
    grid[start[0]][start[1]] = 0;
    

    

    
    int dir[] = {0, 1, 0, -1, 0};

    while(!q.empty() && pq.size() < k) {
        
        int sz = q.size();
        dist++;
        while(sz--) {
            
            auto it = q.front();
            // grid[it[0]][it[1]] = 0;                
            q.pop();

            for(int i = 0; i < 4; i++) {
                int x = it[0] + dir[i], y = it[1] + dir[i + 1];
                if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 0)
                    continue;

                if(grid[x][y] > 1 && grid[x][y] >= price[0] && grid[x][y] <= price[1]) {
                    pq.push({dist, grid[x][y], x, y});
                }
                q.push({x, y});
                grid[x][y] = 0;                                        
            }
            

        }
    }

    vector<vector<int>> ans;        
    while((ans.size() < k) && !pq.empty()) {
        auto it = pq.top();
        ans.push_back({it[2], it[3]});
        pq.pop();
    }                
    
    return ans;
}
```

This function calculates the highest-ranked items within a given grid based on price criteria and the user's starting point, utilizing BFS and priority queues for efficient retrieval of the top k items.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& price, vector<int>& start, int k) {
	```
	Define the function that takes in the grid, price range, start position, and number of items to return (k).

2. **Variable Initialization**
	```cpp
	    int m = grid.size(), n = grid[0].size();
	```
	Get the dimensions of the grid (number of rows m and columns n).

3. **Queue Setup**
	```cpp
	    queue<vector<int>> q;
	```
	Initialize a queue to hold the positions (coordinates) to be processed.

4. **Queue Initialization**
	```cpp
	    q.push(start);
	```
	Push the starting position into the queue.

5. **Distance Initialization**
	```cpp
	    int dist = 0;
	```
	Initialize the distance variable to track the steps taken from the start.

6. **Priority Queue Setup**
	```cpp
	    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	```
	Initialize a priority queue to store items based on distance and grid value.

7. **Grid Value Check**
	```cpp
	    if(grid[start[0]][start[1]] >= price[0] && grid[start[0]][start[1]] <= price[1])
	```
	Check if the value at the starting grid position falls within the price range.

8. **Push to PQ**
	```cpp
	        pq.push({dist, grid[start[0]][start[1]], start[0], start[1]});
	```
	Push the initial position with its value to the priority queue.

9. **Mark Visited**
	```cpp
	    grid[start[0]][start[1]] = 0;
	```
	Mark the starting position as visited by setting it to 0.

10. **Direction Array Setup**
	```cpp
	    int dir[] = {0, 1, 0, -1, 0};
	```
	Define direction vectors for moving up, right, down, and left.

11. **Main Loop**
	```cpp
	    while(!q.empty() && pq.size() < k) {
	```
	Start a while loop that runs as long as the queue is not empty and the priority queue has fewer than k elements.

12. **Size Calculation**
	```cpp
	        int sz = q.size();
	```
	Store the current size of the queue.

13. **Increment Distance**
	```cpp
	        dist++;
	```
	Increment the distance counter.

14. **Process Each Queue Element**
	```cpp
	        while(sz--) {
	```
	Process each element in the queue.

15. **Pop from Queue**
	```cpp
	            auto it = q.front();
	```
	Get the front element from the queue.

16. **Pop from Queue**
	```cpp
	            q.pop();
	```
	Remove the front element from the queue.

17. **Direction Iteration**
	```cpp
	            for(int i = 0; i < 4; i++) {
	```
	Iterate over the four possible directions.

18. **Position Calculation**
	```cpp
	                int x = it[0] + dir[i], y = it[1] + dir[i + 1];
	```
	Calculate the new position based on the current direction.

19. **Bounds Check**
	```cpp
	                if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 0)
	```
	Check if the new position is within bounds and not visited.

20. **Skip Invalid Position**
	```cpp
	                    continue;
	```
	Skip this iteration if the position is invalid.

21. **Push to PQ**
	```cpp
	                if(grid[x][y] > 1 && grid[x][y] >= price[0] && grid[x][y] <= price[1]) {
	```
	Check if the position is valid for addition to the priority queue.

22. **Push to PQ**
	```cpp
	                    pq.push({dist, grid[x][y], x, y});
	```
	Push the position to the priority queue.

23. **Push to Queue**
	```cpp
	                q.push({x, y});
	```
	Push the new position into the queue for further processing.

24. **Mark Visited**
	```cpp
	                grid[x][y] = 0;
	```
	Mark the new position as visited.

25. **Result Collection**
	```cpp
	    vector<vector<int>> ans;        
	```
	Create a vector to store the resulting positions.

26. **Collect Top K Items**
	```cpp
	    while((ans.size() < k) && !pq.empty()) {
	```
	Collect the top k items from the priority queue.

27. **Pop from PQ**
	```cpp
	        auto it = pq.top();
	```
	Get the top element from the priority queue.

28. **Push to Result**
	```cpp
	        ans.push_back({it[2], it[3]});
	```
	Add the result to the answer vector.

29. **Pop from PQ**
	```cpp
	        pq.pop();
	```
	Remove the element from the priority queue.

30. **Return Result**
	```cpp
	    return ans;
	```
	Return the final result after collecting the top k items.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n) for BFS traversal.
- **Average Case:** O(m * n * log(k)) for sorting the top `k` items.
- **Worst Case:** O(m * n * log(m * n)) for sorting all items if there are many reachable items.

The time complexity involves BFS traversal and sorting operations.

### Space Complexity 💾
- **Best Case:** O(k) for storing the top `k` items.
- **Worst Case:** O(m * n) for storing the grid and items.

Space complexity is determined by the grid size and the number of items we need to store.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/description/)

---
{{< youtube OOBGOENJLYo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
