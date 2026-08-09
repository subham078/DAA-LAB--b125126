set terminal pngcairo size 800,600
set output 'q3_graph.png'
set title "Merging K Sorted Arrays (Fixed n=1000)"
set xlabel "Number of Arrays (k)"
set ylabel "Execution Time (seconds)"
set key top left
set grid
plot "q3_data.txt" using 1:2 with linespoints linewidth 2 title "Method 1 (Iterative O(k^2 * n))", \
     "q3_data.txt" using 1:3 with linespoints linewidth 2 title "Method 2 (Divide & Conquer O(k * n * log k))"