#!/bin/bash

echo "" > script.out

for i in {0..2000}
do
	 (./old-hits <<<$i) >> script.out
done

cat script.out | grep -v "inc"
