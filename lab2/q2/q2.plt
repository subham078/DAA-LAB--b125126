set terminal pngcairo size 800,600
set output 'q2_graph.png'
set title "2-Way vs 3-Way Merge Sort"
set xlabel "Array Size (n)"
set ylabel "Time (seconds)"
set grid
plot "q2_data.txt" using 1:2 with linespoints title "2-Way Merge Sort", \
     "q2_data.txt" using 1:3 with linespoints title "3-Way Merge Sort"