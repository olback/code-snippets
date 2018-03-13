# Makefile for generating pi examples by github.com/olback

.SILENT:

all:
	make big
	make small
	make series
	echo 'Files: '
	ls -a | grep '.out'

big:
	gcc big-numbers.c -m64 -lm -o big.out

small: 
	gcc small-numbers.c -m64 -lm -o small.out

series: 
	gcc series.c -m64 -lm -o series.out
