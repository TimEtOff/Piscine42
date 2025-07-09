FT_NBR1=\"\"!\"\"!\"\"!\"\"!\"\"!\"\"
FT_NBR2=dcrcmcmooododmrrrmorcmcrmomo

NBR1=$(echo "$FT_NBR1" | tr "'\\\"?!" "01234")
echo $NBR1
NBR2=$(echo "$FT_NBR2" | tr "mrdoc" "01234")
echo $NBR2
RES=$(echo "obase=13; ibase=5; $NUM1 + $NUM2" | bc)
echo $RES
echo $RES | tr "0123456789abc" "gtaio luSnemf"