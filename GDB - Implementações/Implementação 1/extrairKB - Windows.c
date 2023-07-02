/*
    Programa com o intuito de extrair pequenas porções do ínicio de um arquivo para outro arquivo.

    By Daniel Gonçalves
*/

#define _LARGEFILE64_SOURCE

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Bibliotecas requeridas pelas system calls
#include<windows.h>

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

    HANDLE fd_origem = CreateFile(fonte, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    HANDLE fd_destino = CreateFile(destino, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    if(fd_origem == INVALID_HANDLE_VALUE || fd_destino == INVALID_HANDLE_VALUE)
    {
        fprintf(stderr, "\nFalha na abertura dos arquivos. %d %d\n", fd_origem, fd_destino);
    }

    int kb = 1024;

    void *data = (void *) malloc(kb);

    for(int i = 0; i < 100; i++)
    {
        ReadFile(fd_origem, data, kb, NULL, NULL);
        WriteFile(fd_destino, data, kb, NULL, NULL);
    }

    CloseHandle(fd_origem);
    CloseHandle(fd_destino);

    return 0;
}
