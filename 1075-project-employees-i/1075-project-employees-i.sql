# Write your MySQL query statement below




select t1.project_id, 

ROUND(sum(t2.experience_years)/count(t1.project_id),2) 

as average_years from

Project t1 left join Employee t2 on t1.employee_id=t2.employee_id 

group by t1.project_id;
