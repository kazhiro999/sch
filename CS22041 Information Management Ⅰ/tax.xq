declare function local:tax($price as xs:decimal?,$percentTax as xs:decimal?)
as xs:decimal? {
   let $tax := $price * $percentTax div 100
   return $tax
};

let $percentage:= 30

for $amount in doc("agency.xml")/agencyList/agency/actuary/amount
return( "Tax is :", (local:tax($amount, $percentage)))





