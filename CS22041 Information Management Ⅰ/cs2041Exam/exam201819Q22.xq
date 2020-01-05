for $num in doc("exam201819.xml")/DoctorDirectory/doctor/@medicalregnumber
return
  <RegNumber>
  {$num}
  </RegNumber>
