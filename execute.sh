#!/bin/bash
#执行一次
cppname=$1
inputfile=$2
outname=${cppname%.*}".out"
outputfile=${cppname%.*}"_output.txt"
$outname <$inputfile >>$outputfile 2>&1