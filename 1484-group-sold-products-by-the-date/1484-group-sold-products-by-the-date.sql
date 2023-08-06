# Write your MySQL query statement below


 # how to aggregate the product names in one cell. In MySql, this can be done using GROUP_CONCAT, in which you can also specify the sorting mechanism for the group concatenation (aggregation)

select sell_date, COUNT(DISTINCT(product)) as num_sold, 

GROUP_CONCAT(DISTINCT(product) order by product separator ',') 

as products 

from Activities

group by sell_date order by sell_date;