# Write your MySQL query statement below

SELECT t1.employee_id, t1.name, 
       
count(t2.reports_to) as reports_count,

round(avg(t2.age)) as average_age

from Employees t1 join Employees t2

on t1.employee_id=t2.reports_to

group by t1.employee_id

order by t1.employee_id;