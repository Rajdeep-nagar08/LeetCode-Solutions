# Write your MySQL query statement below

select a1.machine_id, ROUND(avg(a1.timestamp-a2.timestamp),3) as processing_time from

Activity a1 JOIN Activity a2

on

a1.machine_id=a2.machine_id && a1.process_id=a2.process_id && 

a1.timestamp > a2.timestamp

GROUP BY a1.machine_id;


