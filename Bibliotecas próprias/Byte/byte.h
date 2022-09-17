#ifndef BYTE_H
#define BYTE_H

/*
	Biblioteca contendo funções úteis para manipulação de bytes.
	Autor: Daniel Gonçalves
	2022
*/


unsigned char inverterBit(unsigned char b, unsigned int pos);
int statusBit(unsigned char b, unsigned int pos);
int localizarBitEsquerda(unsigned char b, short int bit);
int localizarBitDireita(unsigned char b, short int bit);


#endif
