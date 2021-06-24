ARG=`ps aux | grep " ./philo" | head -n 1 | awk -F ' ' '{print $2}'`
leaks $ARG