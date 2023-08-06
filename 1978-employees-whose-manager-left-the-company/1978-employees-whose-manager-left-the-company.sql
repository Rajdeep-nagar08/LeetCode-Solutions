# Write your MySQL query statement below



select t1.employee_id 

from Employees t1  join Employees t2 

on t1.employee_id = t2.employee_id 

where t1.salary < 30000 

and t1.manager_id not in (select employee_id from Employees)

order by t1.employee_id;



