# Write your MySQL query statement below



select t1.product_name, 

SUM(CASE when substr(t2.order_date,1,7)="2020-02" then t2.unit else 
    
0 end) as unit
    
    from

Products t1 join Orders t2 on t1.product_id=t2.product_id

group by t1.product_id

having SUM(CASE when substr(t2.order_date,1,7)="2020-02" then t2.unit else 
    
0 end) >= 100 ;
