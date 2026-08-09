set terminal pngcairo size 800,600
set xlabel "Input Size (n)"
set ylabel "Time (seconds)"
set key top left
set grid

# 1. Search Operation Plot (Columns 2 to 7)
set output 'q1_Search.png'
set title "Dictionary Operations: Search(D, k)"
plot "q1_42_data.txt" using 1:2 with linespoints lw 2 title "Unsorted Array", \
     "" using 1:3 with linespoints lw 2 title "Sorted Array", \
     "" using 1:4 with linespoints lw 2 title "Singly Linked Unsorted", \
     "" using 1:5 with linespoints lw 2 title "Singly Linked Sorted", \
     "" using 1:6 with linespoints lw 2 title "Doubly Linked Unsorted", \
     "" using 1:7 with linespoints lw 2 title "Doubly Linked Sorted"

# 2. Insert Operation Plot (Columns 8 to 13)
set output 'q1_Insert.png'
set title "Dictionary Operations: Insert(D, x)"
plot "q1_42_data.txt" using 1:8 w lp lw 2 title "Unsorted Array", \
     "" using 1:9 w lp lw 2 title "Sorted Array", \
     "" using 1:10 w lp lw 2 title "Singly Linked Unsorted", \
     "" using 1:11 w lp lw 2 title "Singly Linked Sorted", \
     "" using 1:12 w lp lw 2 title "Doubly Linked Unsorted", \
     "" using 1:13 w lp lw 2 title "Doubly Linked Sorted"

# 3. Delete Operation Plot (Columns 14 to 19)
set output 'q1_Delete.png'
set title "Dictionary Operations: Delete(D, x)"
plot "q1_42_data.txt" using 1:14 w lp lw 2 title "Unsorted Array", \
     "" using 1:15 w lp lw 2 title "Sorted Array", \
     "" using 1:16 w lp lw 2 title "Singly Linked Unsorted", \
     "" using 1:17 w lp lw 2 title "Singly Linked Sorted", \
     "" using 1:18 w lp lw 2 title "Doubly Linked Unsorted", \
     "" using 1:19 w lp lw 2 title "Doubly Linked Sorted"

# 4. Max Operation Plot (Columns 20 to 25)
set output 'q1_Max.png'
set title "Dictionary Operations: Max(D)"
plot "q1_42_data.txt" using 1:20 w lp lw 2 title "Unsorted Array", \
     "" using 1:21 w lp lw 2 title "Sorted Array", \
     "" using 1:22 w lp lw 2 title "Singly Linked Unsorted", \
     "" using 1:23 w lp lw 2 title "Singly Linked Sorted", \
     "" using 1:24 w lp lw 2 title "Doubly Linked Unsorted", \
     "" using 1:25 w lp lw 2 title "Doubly Linked Sorted"

# 5. Min Operation Plot (Columns 26 to 31)
set output 'q1_Min.png'
set title "Dictionary Operations: Min(D)"
plot "q1_42_data.txt" using 1:26 w lp lw 2 title "Unsorted Array", \
     "" using 1:27 w lp lw 2 title "Sorted Array", \
     "" using 1:28 w lp lw 2 title "Singly Linked Unsorted", \
     "" using 1:29 w lp lw 2 title "Singly Linked Sorted", \
     "" using 1:30 w lp lw 2 title "Doubly Linked Unsorted", \
     "" using 1:31 w lp lw 2 title "Doubly Linked Sorted"

# 6. Predecessor Operation Plot (Columns 32 to 37)
set output 'q1_Predecessor.png'
set title "Dictionary Operations: Predecessor(D, x)"
plot "q1_42_data.txt" using 1:32 w lp lw 2 title "Unsorted Array", \
     "" using 1:33 w lp lw 2 title "Sorted Array", \
     "" using 1:34 w lp lw 2 title "Singly Linked Unsorted", \
     "" using 1:35 w lp lw 2 title "Singly Linked Sorted", \
     "" using 1:36 w lp lw 2 title "Doubly Linked Unsorted", \
     "" using 1:37 w lp lw 2 title "Doubly Linked Sorted"

# 7. Successor Operation Plot (Columns 38 to 43)
set output 'q1_Successor.png'
set title "Dictionary Operations: Successor(D, x)"
plot "q1_42_data.txt" using 1:38 w lp lw 2 title "Unsorted Array", \
     "" using 1:39 w lp lw 2 title "Sorted Array", \
     "" using 1:40 w lp lw 2 title "Singly Linked Unsorted", \
     "" using 1:41 w lp lw 2 title "Singly Linked Sorted", \
     "" using 1:42 w lp lw 2 title "Doubly Linked Unsorted", \
     "" using 1:43 w lp lw 2 title "Doubly Linked Sorted"