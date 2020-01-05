for $car in doc("car.xml")/carList/car,
$name in doc("Customer.xml")/customerList/customer
where $name/name = $car/driver/name
return
<cardetails>
  {$car/@make}
  {$car/@model}
  {$car/@age}
  {$car/description}
  {$car/registrationNum}
   {$name/name}
</cardetails>