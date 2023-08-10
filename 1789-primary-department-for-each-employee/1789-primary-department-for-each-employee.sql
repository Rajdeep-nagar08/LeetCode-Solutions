# Write your MySQL query statement below


select t.employee_id, t.department_id

from(
    
select t1.employee_id, 

case when count(t1.primary_flag)=1 then t1.department_id

else

(select t2.department_id from Employee t2 where t1.employee_id=t2.employee_id and
 t2.primary_flag='Y')
 
end as department_id

from Employee t1

group by t1.employee_id

) as t

where t.department_id is not null;