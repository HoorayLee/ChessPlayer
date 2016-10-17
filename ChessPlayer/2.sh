#!/bin/bash

# --------------------------------------------------
# change cmd into your execution command
# cmd="python homework.py"
# cmd="time java homework"
cmd="./main"

# --------------------------------------------------
# change value table, mode, size, depth limit, init state etc.
cat << EOF > input.txt
5
ALPHABETA
X
6
20 16 1 32 30
20 12 2 11 8
28 48 9 1 1
20 12 10 6 2
25 30 23 21 10
.....
.....
.....
.....
.....
EOF

# ------------- Bash Script --------------------------------

rm total_output1.txt
touch total_output1.txt
for ((i=0; i<150; i++)); do
    str="/Users/kouruiri/Documents/ChessPlayer/ChessPlayer/testcase/random_samples_outputs/sample_"$i".txt"
    cat $str
    echo "-"
    grep '\.' output.txt > /dev/null
    if [ $? -ne 0 ]; then
        echo FINISH
        exit
    fi
    cat $str >> total_output1.txt
    echo"">>total_output1.txt
    echo "-" >> total_output1.txt
    sed -i -e  $startLine',$d' input.txt
    cat output.txt | tail -$N >> input.txt
done
