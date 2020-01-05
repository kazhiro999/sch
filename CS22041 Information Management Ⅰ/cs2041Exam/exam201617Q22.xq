for $s in
doc("exam201617.xml")/volunteerDatabase/person
return
<SSNs>
{$s/@ssn}
</SSNs>