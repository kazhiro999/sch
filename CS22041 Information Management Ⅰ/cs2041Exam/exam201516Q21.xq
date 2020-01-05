<Titles>
{
  for $t in doc ("exam201516.xml")/collection/recipe/title
  return
     concat($t,';')
}
</Titles>