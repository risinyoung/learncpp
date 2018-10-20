set xrange [0: 0.075]
set yrange [-0.1:1]
set term png
set output output_filename
p "data.txt" u 1:2 title "Euler",\
'' u 1:3 title "Eulerpc",\
'' u 1:4 title "Eulerim" w l,\
'' u 1:5 title "Rk2",\
'' u 1:6 title "Rk4",\
'' u 1:7 title "exact"