while true; do
    if ! ln ex2 ex2.lock
    then
       sleep 1
    else
        if [ ! -f ex2 ]; then echo 0 > ex2; fi
        count=0
        touch ex2
        while [[ $count != 1000 ]]; do
            count=`expr $count + 1`
            n=`tail -1 ex2`
            expr $n + 1 >> ex2
        done
        rm ex2.lock
        break
    fi
done

