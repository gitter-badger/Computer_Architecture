#!/bin/bash
file=example3
make clean
make -j
cp open_testcase/$file/*.bin .
./CMP
vimdiff report.rpt open_testcase/$file/report.rpt
