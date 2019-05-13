count=0
while [ $? -eq 0 ] && [ ${count} -lt 50 ]
do
  count=$(( ${count}+1 ))
  ./createTest.a > input.in 
  graph/network-flow/1210.a < input.in > output_1.out
  ./test.a < input.in > output_2.out
  diff -b output_1.out output_2.out
done