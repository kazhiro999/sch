let $a := doc("exam201617.xml")//volunteerDatabase/person/@age
return
<result>
   <age>
      {$a/string()}
   </age>
   <age_sum>
      {sum($a)}
   </age_sum>
</result>