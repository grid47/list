# Write your MySQL query statement below
SELECT a1.machine_id, ROUND(AVG(a1.timestamp - a2.timestamp), 3) processing_time
FROM Activity a1
JOIN Activity a2
ON a1.machine_id = a2.machine_id AND a1.activity_type = 'end' AND a2.activity_type = 'start'
GROUP BY machine_id;