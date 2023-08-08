# Write your MySQL query statement below

SELECT t1.employee_id, t1.name, 
       
SUM(case when t1.employee_id = t2.reports_to then 1 else 0 end) 
as reports_count, 
       
ROUND(AVG(t2.age)) as average_age
       
from Employees as t1

left join Employees as t2 on t1.employee_id = t2.reports_to

group by t1.employee_id, t1.name

having reports_count>0

order by t1.employee_id;
