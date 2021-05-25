ARG_100=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`
./push_swap $ARG_100 | wc -l
./push_swap $ARG_100 | ./checker $ARG_100
./push_swap $ARG_100 | ./checker_Mac $ARG_100
