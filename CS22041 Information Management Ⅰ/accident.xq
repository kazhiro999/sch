
for $a in
doc("accident.xml")/accidentList/accident/claim/payout[amount > 500]
return    
 <highValuePayment>    
 {$a}    
 </highValuePayment>
