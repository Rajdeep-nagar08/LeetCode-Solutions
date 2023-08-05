# Write your MySQL query statement below


# select 

# t1.customer_id

# from 

# Customer t1 cross join Product t2 as t3

# group by t1.customer_id

# HAVING

# (SUM(CASE when t1.product_key=t2.product_key then 1 else 0 END) = 
 
#  COUNT(t2.product_key));



select customer_id from Customer group by customer_id

having

COUNT(distinct(product_key))=(select COUNT(product_key) from Product);


