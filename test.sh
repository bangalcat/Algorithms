count=0
while [ $? -eq 0 ] && [ ${count} -lt 5000 ]
do
  count=$(( ${count}+1 ))
  ./createTest.a > input.in 
  greedy/2212.a < input.in > output_1.out
  ./test.a < input.in > output_2.out
  diff -b output_1.out output_2.out
done