for $list in doc("Customer.xml")/customerList/customer
order by $list/name
return
("Customer List: " , $list)

