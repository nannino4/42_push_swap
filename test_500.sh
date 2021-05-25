ARG_500=`ruby -e "puts (0..500).to_a.shuffle.join(' ')"`
./push_swap $ARG_500 | wc -l
./push_swap $ARG_500 | ./checker $ARG_500
./push_swap $ARG_500 | ./checker_Mac $ARG_500
