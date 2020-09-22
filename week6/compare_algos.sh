rm results.txt
touch results.txt

echo "Avg.TAT Avg.WT" > results.txt

bash ex1.sh
bash ex2.sh
bash ex3.sh

# Run this script to get the results of running three algorithms on the same input(for RR quanta are provided additionally)
# Usually, SJN outperforms both RR and FCFS. SJN might be on par with RR in AVG.WT on small tests, however.
