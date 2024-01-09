# Write your MySQL query statement below


select distinct t1.customer_id, COUNT(t1.customer_id) as count_no_trans

from

Visits t1 left join Transactions t2 on t1.visit_id=t2.visit_id 

where t2.transaction_id is null

group by t1.customer_id

# order by t1.customer_id;