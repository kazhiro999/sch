<Colleagues>
{
  for $coll in doc("exam201819.xml")/DoctorDirectory/doctor/name/lastname
  return
  concat($coll,'+')
}
</Colleagues>
