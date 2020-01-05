for $who in doc("Customer.xml")/customerList/customer,
 $paid in doc("payment.xml")/payments/payment
where $who/@id = $paid/customerID
return
("List of People who paid : ", $who/name, $who/@id, "paid with: " , $paid/@type ,"amount paid: ", $paid/bill)

