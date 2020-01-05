for $accident in doc("accident.xml")/accidentList/accident,
 $person in doc("Customer.xml")/customerList/customer
where $person/@id = $accident/claim/payout/customerID
return
("Accident:", $accident/@type , $accident/date, $accident/time,$accident/location, $person/name, $person/@id)
