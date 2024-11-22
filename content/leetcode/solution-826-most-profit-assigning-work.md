
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement

In this problem, you are given three inputs:
1. `difficulty[]`: An array where each element represents the difficulty level of a job.
2. `profit[]`: An array where each element represents the profit corresponding to the job.
3. `worker[]`: An array where each element represents the ability (or skill) level of a worker.

The goal is to assign jobs to workers such that each worker can only work on jobs that are less than or equal to their ability level, and each worker can complete at most one job. The task is to maximize the total profit from all the workers' assignments.

### Approach

The problem essentially involves pairing workers with jobs in such a way that the workers are able to take on jobs that they can handle based on their ability. The goal is to maximize the total profit from the assignments, and the strategy involves the following steps:

1. **Job Matching**:
   - Each worker can handle jobs up to their own skill level, and for each job, we have a difficulty level. We need to find the best job for each worker in terms of maximum profit.

2. **Sorting the Jobs and Workers**:
   - To facilitate efficient job assignment, it is beneficial to sort both the `jobs` and `workers` arrays. Sorting the jobs array by difficulty and the workers array by ability ensures that we can assign jobs to workers in a greedy manner.

3. **Greedy Approach**:
   - Once the jobs and workers are sorted, we iterate over the workers and attempt to assign them the best job they can perform (i.e., a job that they can handle based on their skill level). We keep track of the best possible profit seen so far and update the total profit for each worker accordingly.

4. **Efficiency**:
   - The sorting step ensures that the solution runs in \(O(N \log N)\), where \(N\) is the size of the larger of the `profit[]`, `difficulty[]`, or `worker[]` arrays. This allows us to find the best job for each worker efficiently.

### Code Breakdown (Step by Step)

1. **Create a List of Jobs**:
   ```cpp
   vector<pair<int, int>> jobs;
   for(int i = 0; i < N; i++)
       jobs.push_back(make_pair(difficulty[i], profit[i]));
   ```
   - We create a vector `jobs` of pairs where each pair consists of a difficulty level and the corresponding profit of a job. This helps us easily access both values together as we process each job.

2. **Sort the Jobs and Workers**:
   ```cpp
   sort(jobs.begin(), jobs.end());
   sort(worker.begin(), worker.end());
   ```
   - First, we sort the `jobs` vector by difficulty. Sorting ensures that we can iterate through the jobs in increasing order of difficulty and pick the best job for each worker.
   - Similarly, we sort the `worker` array by the worker’s ability level. This allows us to assign jobs in an efficient way where we try to assign the easiest available job that a worker can perform.

3. **Greedy Job Assignment**:
   ```cpp
   int best =  0;
   for(int eff: worker) {
       while(i < N && eff >= jobs[i].first) {
           best = max(best, jobs[i++].second);
       }
       res += best;
   }
   ```
   - We initialize `best` to 0, which will hold the best possible profit seen so far for any worker.
   - For each worker, we iterate through the sorted jobs and check if the worker can perform the job (i.e., if the worker’s ability `eff` is greater than or equal to the job’s difficulty `jobs[i].first`).
   - If the worker can perform the job, we update `best` to be the maximum of the current `best` and the profit of the job (`jobs[i].second`), and we move to the next job (`i++`).
   - After processing all jobs that the worker can handle, we add `best` (the best possible profit for that worker) to the total profit `res`.

4. **Return the Result**:
   ```cpp
   return res;
   ```
   - Once we have processed all workers, we return `res`, which contains the total maximum profit.

### Complexity

- **Time Complexity**:
  - The sorting of the `jobs` array takes \(O(N \log N)\), where \(N\) is the number of jobs.
  - Sorting the `worker` array takes \(O(M \log M)\), where \(M\) is the number of workers.
  - The final loop over workers runs in \(O(M)\), where \(M\) is the number of workers. Inside this loop, we use a nested loop to check jobs for each worker, but the while loop is guaranteed to only process each job once, so it contributes at most \(O(N)\) operations in total.
  - Therefore, the overall time complexity is \(O(N \log N + M \log M)\).

- **Space Complexity**:
  - The space complexity is \(O(N + M)\), as we need to store the `jobs` vector (of size \(N\)) and the `worker` vector (of size \(M\)).

### Conclusion

The solution efficiently maximizes the total profit by using a greedy approach to assign jobs to workers based on their ability. By sorting both the jobs and the workers arrays, we ensure that we can easily find the best job for each worker in terms of maximum profit. The greedy nature of the algorithm ensures that we always pick the highest profit job that a worker can handle. The time complexity of \(O(N \log N + M \log M)\) is optimal for this type of problem, where sorting is necessary to enable efficient processing. This approach is both time-efficient and space-efficient, making it suitable for solving this problem in large-scale scenarios where both the number of jobs and workers can be large.

[`Link to LeetCode Lab`](https://leetcode.com/problems/most-profit-assigning-work/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
