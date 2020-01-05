<friends>
{
for $last in
doc("exam201617.xml")/volunteerDatabase/person/name/lastname
return 
 concat($last, string("+"))
}
</friends>   