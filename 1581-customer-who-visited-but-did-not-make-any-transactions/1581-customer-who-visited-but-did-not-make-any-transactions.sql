# Write your MySQL query statement below

SELECT customer_id, COUNT(*) as count_no_trans from Visits v
LEFT JOIN Transactions t on v.visit_id = t.visit_id
WHERE t.transaction_id is NULL GROUP BY v.customer_id; 