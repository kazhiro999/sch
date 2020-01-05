<Healthy_options> 
{
 for $f in doc ("exam201718.xml")/breakfast_menu/food[@calories<800]
 return
  concat($f/name, '+')
}
</Healthy_options>