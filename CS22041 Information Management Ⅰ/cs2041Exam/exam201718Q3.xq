let $price := doc ("exam201718.xml")/breakfast_menu/food/price
return
<result>
  <price>
    {$price/string()}
  </price>
  <avg_price>
    {avg($price)}
  </avg_price>
</result>