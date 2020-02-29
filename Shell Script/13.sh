#!/bin/bash

data=$(date +%H%M)

if [ $data -le 1200 ]
then
	echo "Bom dia"; whoami
elif [ $data -gt 1200 ] && [ $data -le 1800 ]
then
	echo "Boa Tarde"; whoami
else
	echo "Boa Noite"; whoami
fi
