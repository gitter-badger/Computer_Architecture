#!/bin/bash
cd ../assembler/
./copy.sh
cp *.bin ../simulator
cd ../simulator/
make
./single_cycle
