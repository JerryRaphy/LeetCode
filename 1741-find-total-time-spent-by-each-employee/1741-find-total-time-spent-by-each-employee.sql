# Write your MySQL query statement below

SELECT emp_id, event_day as day, SUM(out_time - in_time)  AS total_time
FROM Employees GROUP BY day, emp_id