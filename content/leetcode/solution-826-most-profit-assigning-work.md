
+++
authors = ["grid47"]
title = "Leetcode 826: Most Profit Assigning Work"
date = "2024-08-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 826: Most Profit Assigning Work in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given a list of jobs, each with a difficulty level and a profit value, and a list of workers, each with a certain ability. A worker can only complete jobs with a difficulty level that is at most equal to the worker's ability. Each worker can complete at most one job, but jobs can be assigned to multiple workers. The goal is to calculate the maximum total profit by assigning the jobs to workers based on their abilities.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of three arrays:
1. `difficulty` - An array of integers representing the difficulty of each job.
2. `profit` - An array of integers representing the profit from each job.
3. `worker` - An array of integers representing the ability of each worker.
- **Example:** `Input: difficulty = [3, 5, 7], profit = [15, 25, 35], worker = [4, 6, 8]`
- **Constraints:**
	- 1 <= n, m <= 10^4
	- 1 <= difficulty[i], profit[i], worker[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum total profit that can be achieved by assigning jobs to workers.
- **Example:** `Output: 75`
- **Constraints:**
	- The output must be an integer representing the maximum total profit.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to match jobs to workers based on the workers' abilities, ensuring that each worker can complete a job with a difficulty level that does not exceed their ability.

- Step 1: Create pairs of jobs by combining difficulty and profit values.
- Step 2: Sort the jobs by difficulty and the workers by their abilities.
- Step 3: For each worker, check which jobs they can complete, updating the maximum profit as you assign the best possible job to each worker.
{{< dots >}}
### Problem Assumptions ✅
- All jobs have a positive profit and difficulty.
- Each worker can perform at most one job.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: difficulty = [3, 5, 7], profit = [15, 25, 35], worker = [4, 6, 8]`  \
  **Explanation:** The workers are assigned jobs of difficulty 3, 5, and 7, with profits 15, 25, and 35 respectively. The total profit is 15 + 25 + 35 = 75.

{{< dots >}}
## Approach 🚀
The approach involves sorting both the jobs and the workers, and for each worker, selecting the most profitable job they can complete. This ensures maximum profit is achieved.

### Initial Thoughts 💭
- Sorting the jobs by difficulty and workers by their ability helps in assigning jobs efficiently.
- Using a greedy strategy to assign the highest-paying job that a worker can handle will maximize the total profit.
{{< dots >}}
### Edge Cases 🌐
- If there are no workers or jobs, the profit is 0.
- Ensure that the algorithm efficiently handles the upper bounds of the input sizes.
- Handle cases where workers' abilities are less than the lowest job difficulty.
- The solution must efficiently handle inputs where the number of workers and jobs is at the upper limit (10^4).
{{< dots >}}
## Code 💻
```cpp
int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    // zip difficulty and profit of jobs
    int N = profit.size(), res = 0, i = 0;
    
    vector<pair<int, int>> jobs;
    for(int i = 0; i < N; i++)
        jobs.push_back(make_pair(difficulty[i], profit[i]));
    
    sort(jobs.begin(), jobs.end());
    sort(worker.begin(), worker.end());
    int best =  0;
    for(int eff: worker) {
        while(i < N && eff >= jobs[i].first) {
            best = max(best, jobs[i++].second);
        }
        res += best;
    }
    
    return res;
}
```

This function calculates the maximum total profit that can be obtained by assigning jobs to workers. Jobs have a difficulty and profit value, while workers have a certain efficiency. The function pairs the difficulty with the profit and assigns jobs to workers based on their efficiency.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
	```
	This is the function declaration, where `maxProfitAssignment` takes three vectors: `difficulty`, `profit`, and `worker`. It returns the maximum total profit.

2. **Variable Initialization**
	```cpp
	    int N = profit.size(), res = 0, i = 0;
	```
	The size of the profit vector is stored in `N`. The variable `res` stores the result, which is the total profit, and `i` is used to iterate through the jobs.

3. **Vector Initialization**
	```cpp
	    vector<pair<int, int>> jobs;
	```
	A vector of pairs `jobs` is created to store pairs of difficulty and profit for each job.

4. **Loop**
	```cpp
	    for(int i = 0; i < N; i++)
	```
	A loop that iterates through the jobs using index `i`.

5. **Vector Insertion**
	```cpp
	        jobs.push_back(make_pair(difficulty[i], profit[i]));
	```
	For each job, the difficulty and profit values are paired together and added to the `jobs` vector.

6. **Sorting**
	```cpp
	    sort(jobs.begin(), jobs.end());
	```
	Sort the jobs vector based on the difficulty (first element of the pair).

7. **Sorting**
	```cpp
	    sort(worker.begin(), worker.end());
	```
	Sort the worker vector based on the efficiency of workers.

8. **Variable Initialization**
	```cpp
	    int best =  0;
	```
	Initialize `best` to track the highest profit that can be assigned to a worker.

9. **Loop**
	```cpp
	    for(int eff: worker) {
	```
	A loop to iterate through each worker's efficiency.

10. **While Loop**
	```cpp
	        while(i < N && eff >= jobs[i].first) {
	```
	While the worker's efficiency is greater than or equal to the job's difficulty, continue processing the job.

11. **Max Profit Update**
	```cpp
	            best = max(best, jobs[i++].second);
	```
	Update the `best` profit with the maximum profit of jobs the worker can do, and increment `i` to check the next job.

12. **Result Update**
	```cpp
	        res += best;
	```
	Add the best profit that the current worker can achieve to the total result `res`.

13. **Return Statement**
	```cpp
	    return res;
	```
	Return the total profit `res`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n), when the jobs and workers are already sorted.
- **Average Case:** O(n log n), as sorting dominates the time complexity.
- **Worst Case:** O(n log n), due to sorting of jobs and workers.

The time complexity is O(n log n) because of the sorting steps.

### Space Complexity 💾
- **Best Case:** O(1), if sorting is done in-place.
- **Worst Case:** O(n), for storing the jobs and workers in memory.

The space complexity is O(n), as we need extra space to store the jobs.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/most-profit-assigning-work/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
