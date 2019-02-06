#!/bin/bash
vpart_command="sudo ./vpart -u postgres -p postgres -h localhost -d sdss_extract -t star --bab"

algo="11"
key="nearest"
for t in 0.5 0.55 0.6 0.65 0.7 0.75 0.8 0.85 0.9 0.95
do
    echo $vpart_command$algo" "$t" --$key > bab${algo}_${t}_$key"
    eval $vpart_command$algo" "$t" --$key > bab${algo}_${t}_$key"  
done




