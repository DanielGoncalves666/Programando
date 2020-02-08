#!/bin/bash

if [ $USER = daniel ] && [ -w $HOME/.bashrc ]
then
	echo "Usuário $USER tem permissão de escrita"
else
	echo "Usuário $USER não tem permissão"
fi


# and e or são o mesmos da linguagem C
