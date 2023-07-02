/*
    Programa referente ao Primeiro trabalho Prático da Disciplina de Gerenciamento de Banco de dados.

    By Daniel Gonçalves 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

// Bibliotecas requeridas pelas system calls
#include<windows.h>
// https://www.cs.rpi.edu/academics/courses/fall01/os/
// https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-setfilepointer

int totalRegistros = 0; // armazena a quantidade de registros no arquivo criado.(inclui inválidos)
int totalValidos = 0; // armazena a quantidade de registros que são válidos

typedef struct{
    int NSEQ;
    char TEXT[46]; // textos de até 45 caracteres
}registro;
// por questões de memória, a estrutura ocupa 52 bytes, invés de 50 bytes.

/* Protótipos */
int calcularQtdRegistros(int capacidade); // ok
void gerarTextoAleatorio(registro *r); // ok

HANDLE createHeapFile(int qtdRegistros); // ok
int readRandom(HANDLE fd, int NSEQ); // ok
void isrtAtEnd(HANDLE fd); // ok
int updateRandom(HANDLE fd, int NSEQ, char *text); // ok
int deleteRandom(HANDLE fd, int NSEQ); // ok

int invalidaAleatorio(HANDLE fd, int total);// ok

double experimentoVarreduraSequencial(HANDLE fd, int nRegPag, int *nrPagLidas, int *nrRegValidos);
double experimentoAcessoAleatorio(HANDLE fd, int qtdReg, double menorTempo, int *nrRegInvalidos, int *nrRegValidos);

int main()
{
    int memoriaPC = 0; // armazena a capacidade da memória RAM, em GB, da máquina de testes
    HANDLE arquivo = INVALID_HANDLE_VALUE; // armazena o ponteiro para o arquivo criado

    srand(time(NULL));

    printf("Entre com a capacidade, em GB, da sua memória RAM: ");
    scanf("%d",&memoriaPC);

    totalRegistros = calcularQtdRegistros(memoriaPC);
    totalValidos = totalRegistros;
    if(totalRegistros < 0)
    {
        fprintf(stderr,"\nValor inválido para a memória da máquina.\n");
        return 1;
    }

    // ====================
    // totalRegistros /= 100000; // RETIRAR ANTES DOS TESTES
    // totalValidos = totalRegistros;
    // ====================

    int op = 0;

    printf("\nDeseja ler um arquivo já existente ou gerar um novo arquivo?\n 1 - Ler existente.\n Qualquer outro numero para gerar.\n");
    scanf("%d", &op);

    char opC = 'S';
    printf("\nEm caso de sucesso na abertura ou criação do arquivo, deseja realizar a bateria de testes? S - Sim\n Qualquer outro símbolo para não\n");
    scanf(" %c", &opC);

    if(op == 1)
    {
        arquivo = CreateFile("HeapFile.txt", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

        if(arquivo == INVALID_HANDLE_VALUE)
        {
            fprintf(stderr, "\nArquivo não existente.\n");
            return 1;
        }
    }
    else
    {
        arquivo = createHeapFile(totalRegistros);

        if(arquivo == INVALID_HANDLE_VALUE)
        {
            fprintf(stderr, "\n Não foi possível criar o arquivo.\n");
            return 1;
        }
    }

    if(opC != 'S')
    {
        fprintf(stdout, "\nTestes não serão realizados.\n");
        return 0;
    }

    int testes[] = {1, 1000, 10000, 1000000};
    int nrPagLidas = 0;
    int nrRegValidos = 0;
    int nrRegInvalidos = 0;
    double tempo = 0.0;
    double menorTempo = 0.0; // armazena o menor tempo de execução da bateria de testes sequencial

    printf("\nQuantidade total de Registros: %d\n", totalRegistros);
    printf("Quantidade de Registros inválidos: %d\n", invalidaAleatorio(arquivo, totalRegistros));
    printf("Quantidade de Registros Válidos: %d\n", totalValidos);

    printf("\n =================================================== \n");
    printf(" ==== Experimentos de Varredura Sequencial ====\n");

    for(int i = 0; i < 4; i++)
    {
        tempo = experimentoVarreduraSequencial(arquivo, testes[i], &nrPagLidas, &nrRegValidos);

        printf("\n\nTamanho da página: %d registros.\n", testes[i]);
        printf("Quantidade de páginas lidas: %d\n", nrPagLidas);
        printf("Número de registros válidos: %d\n", nrRegValidos);
        printf("Tempo de processamento: %lf\n", tempo);

        if(i == 0)
            menorTempo = tempo;
        else if(tempo < menorTempo)
            menorTempo = tempo;
    }

    printf("\n\n =================================================== \n");
    printf(" ==== Experimentos de Acesso Aleatório ====\n");

    tempo = experimentoAcessoAleatorio(arquivo, totalRegistros, menorTempo, &nrRegInvalidos, &nrRegValidos);

    printf("Número de registros válidos: %d\n", nrRegValidos);
    printf("Número de registros inválidos: %d\n", nrRegInvalidos);
    printf("Tempo de processamento: %lf\n", tempo);
    printf("Tempo médio de processamento por registro: %lf\n", tempo / (nrRegInvalidos + nrRegValidos));

    CloseHandle(arquivo);
    return 0;
}

/*
calcularQtdRegistros
-----------------------
Entrada: inteiro, indicando a capacidade em GB da máquina de testes
Processo: calcula a quantidade de registros que cabem em um arquivo com 5 vezes a RAM da máquina de testes
Saída: inteiro, indicando a quantidade de registros. Em caso de falha, retorna um número negativo.
*/
int calcularQtdRegistros(int capacidade)
{
    if(capacidade <= 0)
        return -1;

    unsigned long long total = (capacidade * 5) * pow(2,30); // 2^30 é 1GB
    int qtd = total / sizeof(registro);

    return qtd;
}

/*
createHeapFile
----------------
Entrada: inteiro, indicando a quantidade de registros que o arquivo precisa ter
Processo: Cria um arquivo e o preenche com a quantidade de registros passada.
Saída: inteiro, indicando o file descriptor do arquivo criado. Um valor negativo é retornado em caso de falha.
*/
HANDLE createHeapFile(int qtdRegistros)
{
    int MR = 1024 * 1024; // Mega Registros
    registro *r = (registro *) malloc(sizeof(registro) * MR);

    HANDLE fd = CreateFile("HeapFile.txt", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    if(fd != INVALID_HANDLE_VALUE)
    {
        int nseq = 0;
        for(int h = 0; h < qtdRegistros / MR; h++)
        {
            for(int i = 0; i < MR;i++)
            {
                r[i].NSEQ = nseq;
                gerarTextoAleatorio(&r[i]);
                nseq++;
            }

            WriteFile(fd, r, sizeof(registro) * MR, NULL, NULL);
        }

        if(qtdRegistros % MR != 0)
        {
            for(int i = 0; i < qtdRegistros % MR; i++)
            {
                r[i].NSEQ = nseq;
                gerarTextoAleatorio(&r[i]);
                nseq++;
            }
            WriteFile(fd, r, sizeof(registro) * (qtdRegistros % MR), NULL, NULL);
        }
    }

    free(r);

    return fd;
}

/*
gerarTextoAleatorio
--------------------
Entrada: ponteiro para um registro
Processo: gera, aleatoriamente, o texto para o registro passado
Saída: nenhuma
*/
void gerarTextoAleatorio(registro *r)
{
    for(int i = 0; i < 45; i++)
    {
        r->TEXT[i] = rand() % 93 + 33;
    }

    r->TEXT[45] = '\0';
}

/*
readRandom
------------
Entrada: inteiro, indicando o file descriptor do arquivo com registros
         inteiro, indicando o número do registro
Processo: Imprime as informações do registro informado.
Saída: inteiro, 0 para falha, 1 para sucesso
*/
int readRandom(HANDLE fd, int NSEQ)
{
    if(NSEQ < 0 || NSEQ >= totalRegistros)
        return 0;

    registro r;
    LARGE_INTEGER li;
    li.QuadPart = NSEQ * sizeof(registro);

    SetFilePointer(fd, li.LowPart, &li.HighPart, FILE_BEGIN);
    ReadFile(fd, &r, sizeof(registro), NULL, NULL);
    printf("%d %s\n", r.NSEQ, r.TEXT);

    return 1;
}


/*
isrtAtEnd
----------
Entrada: inteiro, indicando o file descriptor do arquivo com registros
Processo: insere um novo registro no final do arquivo
Saída: nenhuma
*/
void isrtAtEnd(HANDLE fd)
{
    registro r;
    r.NSEQ = totalRegistros;
    gerarTextoAleatorio(&r);

    LARGE_INTEGER li;
    li.QuadPart = 0;

    SetFilePointer(fd, li.LowPart, &li.HighPart, FILE_END);
    if(WriteFile(fd, &r, sizeof(registro), NULL, NULL) != 0)
    {
        totalRegistros++;
        totalValidos++;
    }
}

/*
updateRandom
-------------
Entrada: inteiro, indicando o file descriptor do arquivo com registros
         inteiro, indicando o número de sequência do registro a ser atualizado
         string, indicando o novo texto
Processo: Atualiza  registro NSEQ, se ele existir. Se o vetor recebido for maior que 45 caracteres o resto é ignorado.
Saída: inteiro, 0 para falha, 1 para sucesso
*/
int updateRandom(HANDLE fd, int NSEQ, char *text)
{
    if(NSEQ < 0 || NSEQ >= totalRegistros)
        return 0;

    registro r;

    LARGE_INTEGER li;
    li.QuadPart = NSEQ * sizeof(registro);

    SetFilePointer(fd, li.LowPart, &li.HighPart, FILE_BEGIN);
    ReadFile(fd, &r, sizeof(registro), NULL, NULL);

    int i;
    for(i = 0; i < 45 && i < strlen(text); i++)
    {
        r.TEXT[i] = text[i];
    }
    r.TEXT[i] = '\0';

    li.QuadPart =  - sizeof(registro);

    SetFilePointer(fd, li.LowPart, &li.HighPart, FILE_CURRENT);
    WriteFile(fd, &r, sizeof(registro), NULL, NULL);

    return 1;
}

/*
deleteRandom
--------------
Entrada: inteiro, indicando o file descriptor do arquivo com registros
         inteiro, indicando o número de sequência do registro a ser deletado
Processo: Deleta o arquivo com NSEQ especificado (torna o NSEQ um número negativo)
Saída: inteiro, 0 para falha, 1 para sucesso, 2 para registro deletado que foi restaurado
*/
int deleteRandom(HANDLE fd, int NSEQ)
{
    if(NSEQ < 0 || NSEQ >= totalRegistros)
        return 0;

    registro r;

    LARGE_INTEGER li;
    li.QuadPart = NSEQ * sizeof(registro);

    SetFilePointer(fd, li.LowPart, &li.HighPart, FILE_BEGIN);
    ReadFile(fd, &r, sizeof(registro), NULL, NULL);

    if(r.NSEQ <= 0) // inválidos permanecem válidos. Registro NSEQ=0 não pode ser invalidado pelo método utilizado
        return 2;

    r.NSEQ = abs(r.NSEQ) * -1;

    li.QuadPart = - sizeof(registro);

    SetFilePointer(fd, li.LowPart, &li.HighPart, FILE_CURRENT);
    WriteFile(fd, &r, sizeof(registro), NULL, NULL);

    totalValidos--;
    return 1;
}

/*
invalidaAleatorio
------------------
Entrada: inteiro, indicando o file descriptor do arquivo com registros
         inteiro, indicando o total de registros do arquivo
Processo: invalida (deleta) uma quantidade aleatória de registros do arquivo que foi passado
Saída: inteiro, indicando a quantidade de registros que foram invalidados
*/
int invalidaAleatorio(HANDLE fd, int total)
{
    int quantidade = rand() % (total / 10000) ; // quantidade de registros que serão invalidados
    int quantidadeFinal = quantidade;
    int NSEQ = 0;

    for(int i = 0; i < quantidade; i++)
    {
        NSEQ = rand() % total; // escolhe um registro aleatoriamente

        if( deleteRandom(fd, NSEQ) == 2)
            quantidadeFinal--;
    }

    return quantidadeFinal;
}

/*
experimentoVarreduraSequencial
---------------------
Entrada: inteiro, indicando o file descriptor do arquivo com registros
         inteiro, indicando a quantidade de registros por página

         ponteiro para inteiro, indicando a variável onde deve ser armazenada a quantidade de páginas lidas
         ponteiro para inteiro, indicnado a variável onde deve ser armazenada a quantidade de registros válidos lidos
Processo: Realiza a leitura (sequencial) completa do arquivo usando nRegPag como tamanho de bloco.
Saída: double, indicando o tempo de processamento
*/
double experimentoVarreduraSequencial(HANDLE fd, int nRegPag, int *nrPagLidas, int *nrRegValidos)
{
    clock_t ini, fim;
    registro *registros = (registro *) calloc(nRegPag, sizeof(registro));

    int fimBlocoMemoria = 0; // indica o último registro em memória
    *nrPagLidas = 0;
    *nrRegValidos = 0;

    ini = clock();

    LARGE_INTEGER li;
    li.QuadPart = 0;

    SetFilePointer(fd, li.LowPart, &li.HighPart, FILE_BEGIN);
    ReadFile(fd, registros, sizeof(registro) * nRegPag, NULL, NULL);
    fimBlocoMemoria += nRegPag;
    (*nrPagLidas)++;

    for(int i = 0; i < totalRegistros; i++)
    {
        if(i >= fimBlocoMemoria)
        {
            ReadFile(fd, registros, sizeof(registro) * nRegPag, NULL, NULL);
            fimBlocoMemoria += nRegPag;
            (*nrPagLidas)++;
        }

        if(registros[i - nRegPag * (*nrPagLidas - 1)].NSEQ >= 0)
            (*nrRegValidos)++;
    }

    fim = clock();

    free(registros);

    return ((double) fim - ini) / CLOCKS_PER_SEC;
}

/*
experimentoAcessoAleatorio
----------------------------
Entrada: inteiro, indicando o file descriptor do arquivo com registros
         inteiro, indicando a quantidade de registros

         double, indicando o menor tempo da bateria de testes sequenciais

         ponteiro para inteiro, indicnado a variável onde deve ser armazenada a quantidade de registros inválidos lidos
         ponteiro para inteiro, indicnado a variável onde deve ser armazenada a quantidade de registros válidos lidos
Processo: Realiza testes de acesso aleatório no arquivo
Saída: double, indicando o tempo de processamento
*/
double experimentoAcessoAleatorio(HANDLE fd, int qtdReg, double menorTempo, int *nrRegInvalidos, int *nrRegValidos)
{
    clock_t total = 0;
    clock_t ini, fim;
    registro r;

    int NSEQ = 0; //armazena os valores de número de sequencia aleatórios que são gerados
    *nrRegValidos = 0; // quantidade de registros válidos que foram lidos
    *nrRegInvalidos = 0; // quantidade de registridos inválidos que foram lidos
    LARGE_INTEGER li;

    do{
        NSEQ = rand() % qtdReg;

        ini = clock();

        li.QuadPart = NSEQ * sizeof(registro);

        SetFilePointer(fd, li.LowPart, &li.HighPart, FILE_BEGIN);
        ReadFile(fd, &r, sizeof(registro), NULL, NULL);

        if(r.NSEQ >= 0)
            (*nrRegValidos)++;
        else
            (*nrRegInvalidos)++;

        fim = clock();
        total += fim - ini;

        // este laço deve rodar até que o tempo total seja maior que o menor tempo de leitura sequencial de todo o arquivo
    }while( ((double) total) / CLOCKS_PER_SEC <= menorTempo);


    return ((double) total) /CLOCKS_PER_SEC;
}
