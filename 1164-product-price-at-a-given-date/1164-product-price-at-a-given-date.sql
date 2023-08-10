# Write your MySQL query statement below


select t1.product_id, 

case when min(t1.change_date) > '2019-08-16' then 10 

else 

(select t2.new_price from Products t2 where t2.change_date <= '2019-08-16' and t1.product_id= t2.product_id order by t2.change_date desc limit 1)

end as price

from Products t1

group by t1.product_id;





