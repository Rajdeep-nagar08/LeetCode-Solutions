# Write your MySQL query statement below


   select t1.product_id, ROUND(sum(t1.price*t2.units)/sum(t2.units),2) 
   
   as average_price
   
 from Prices t1 join unitsSold t2 
 
 on t1.product_id=t2.product_id and t2.purchase_date>=t1.start_date 
 
 and t2.purchase_date<=t1.end_date group by t1.product_id;
 
 





