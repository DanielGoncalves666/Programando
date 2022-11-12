/*
    Programa com o intuito de extrair pequenas porções do ínicio de um arquivo para outro arquivo.

    By Daniel Gonçalves
*/

#define _LARGEFILE64_SOURCE

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Bibliotecas requeridas pelas system calls
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char fonte[31];
    char destino[31];

    if(argc < 2)
    {
        fprintf(stderr, "\nQuantidade insuficiente de argumentos.\n");
        return 1;
    }

    if(argc >= 2)
        strcpy(fonte,argv[1]);

    if(argc >= 3)
        strcpy(destino,argv[2]);
    else
        strcpy(destino, "saida.txt");
        
    int fd_origem = open(fonte, O_RDONLY | __O_LARGEFILE, S_IRWXU | S_IRWXO);   
    int fd_destino = open(destino, O_CREAT | O_RDWR | O_TRUNC | __O_LARGEFILE, S_IRWXU | S_IRWXO);
  
    if(fd_origem == -1 || fd_destino == -1)
    {
        fprintf(stderr, "\nFalha na abertura dos arquivos. %d %d\n", fd_origem, fd_destino);
    }

    int kb = 1024;   
    
    void *data = (void *) malloc(kb);
     
    for(int i = 0; i < 100; i++)
    {
        read(fd_origem, data, kb);
        write(fd_destino, data, kb);
    }
    
    close(fd_origem);
    close(fd_destino);

    return 0;
}
