#!/bin/bash

if [ $2 = '/' ]
then 
	scale=1
else
	scale=0
fi

var1=`echo "scale=$scale;$1$2$3" | bc`
echo "$var1"
