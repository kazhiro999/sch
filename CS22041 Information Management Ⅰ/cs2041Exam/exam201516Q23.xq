for $f in doc ("exam201516.xml")/collection/recipe/ingredient[@amount>2]/@name
return

($f/string())