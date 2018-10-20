for($i = 4; $i -lt 8; $i ++){
    $Lambda= -100*$i
    $Lambda
    ./ex17.exe 500 $Lambda;
    $output =  "'ex17_n5_L-"+$i +".jpg'";
    gnuplot -e "output_filename = $output" ex17.plt;
}