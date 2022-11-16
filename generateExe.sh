#!/bin/bash
#生成可执行文件
cppname=$1
outname=${cppname%.*}".out"
g++ $cppname -o $outname