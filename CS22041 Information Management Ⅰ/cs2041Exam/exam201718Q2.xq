<Waffle_menu>
{
for $w in doc ("exam201718.xml")/breakfast_menu/food/name
where contains($w,"Waffles")
return
($w)
}
</Waffle_menu>
