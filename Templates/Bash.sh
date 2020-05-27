while IFS= read -r divisor || [[ -n "$divisor" ]]; do
count=0
if [ $((${divisor} % 2 )) != 0 ];then
  count=$((1999999/${divisor}))
  if [ $((${count} % 2 )) == 0 ] ; then
    count=$((${count} / 2))
  else
    count=$((${count} / 2 + 1))
  fi
fi
echo $count
done