declare namespace functx = "http://www.functx.com";
declare function functx:id-from-element
  ( $element as element()? )  as xs:string? {

  data(($element/@*[id(.) is ..])[1])
 } ;
 
 let $book := doc('insurancePolicy.xml')
return ("Policy Id:", functx:id-from-element($book/policyList/insurancePolicy[2]))