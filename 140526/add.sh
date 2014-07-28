add() {
    expr $1 + $2
}

main() {
    i=$1
    j=$2
    ret=`add $i $j`
    echo $ret
}

main $1 $2
