#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila.h"
#include "lista.h"

void cadastro(Lista li){
    Pessoa nova;
    printf("Nome:\n>> ");
    setbuf(stdin,NULL);
    gets(nova.nome);
    printf("Idade:\n>> ");
    scanf("%d", &nova.idade);
    printf("Possui comorbidade? (s/n)\n>> ");
    setbuf(stdin, NULL);
    char c = getchar();
    if(c == 's')
        nova.comorbidade = 1;
    else
        nova.comorbidade = 0;

    if(nova.comorbidade == 1)
        strcpy(nova.localVacinacao, "UTC1");
    else if(nova.idade <= 60)
            strcpy(nova.localVacinacao, "UTC2");
         else strcpy(nova.localVacinacao, "Prefeitura");

    insereLista(li, nova);
}

Data Amanha(Data hoje){
    ///Definir se o ano é bissexto
    short int bissexto; // 1 se sim, 0 se nao
    if(hoje.mes == 2){
        if(hoje.ano % 100 == 0 && hoje.ano % 400 == 0)
            bissexto = 1;
        else if(hoje.ano % 100 != 0 && hoje.ano % 4 == 0)
                bissexto = 1;
             else
                bissexto = 0;
    }

    Data amanha;
    if(hoje.dia == 31 && hoje.mes == 12){
        amanha.dia = 1;
        amanha.mes = 1;
        amanha.ano = hoje.ano + 1;
    }

    if(hoje.dia == 28 && hoje.mes == 2 && bissexto == 0){
        amanha.dia = 1;
        amanha.mes = 3;
        amanha.ano = hoje.ano;
    }

    if(hoje.dia == 28 && hoje.mes == 2 && bissexto == 1){
        amanha.dia = 29;
        amanha.mes = hoje.mes;
        amanha.ano = hoje.ano;
    }

    if(hoje.dia == 29 && hoje.mes == 2){
        amanha.dia = 1;
        amanha.mes = 3;
        amanha.ano = hoje.ano;
    }


    if(hoje.mes == 4 || hoje.mes == 6 || hoje.mes == 9 || hoje.mes == 11){
        if(hoje.dia == 30){
            amanha.dia = 1;
            amanha.mes = hoje.mes + 1;
            amanha.ano = hoje.ano;
        }

    }else if(hoje.dia == 31){
            amanha.dia = 1;
            amanha.mes = hoje.mes + 1;
            amanha.ano = hoje.ano;
            }
    return amanha;
}

void geracao(Lista Espera, Fila UTC1, Fila UTC2, Fila Prefeitura, Fila Sabiazinho){
    ///Pega a data do dia
    Data hoje;
    printf("Data de hoje (dd/mm/aaaa)\n>> ");
    scanf("%d/%d/%d", hoje.dia, hoje.mes, hoje.ano);

    Data amanha = Amanha(hoje);

    int i;
    Pessoa elem;
    srand(time(NULL));
    int sorteado;

    int A = 2, P = 2, C = 2; // Tipos de vacina
    for(i = 0; i < 6; i++){
        maior_idade(Espera, "UTC1", &elem);
        elem.primeiraDose = amanha;
        sorteado = rand() % 3; //sorteia de 0 a 2
        if(sorteado == 0 && A != 0){
            elem.tipoVacina = 'A';
            A--;
        }else if(sorteado == 1 && P != 0){
            elem.tipoVacina = 'P';
            P--;
        }else if(sorteado == 2 && C != 0){
            elem.tipoVacina = 'C';
            C--;
        }else{
            sorteado = rand() % 3;
        }
        insere_fim(UTC1, elem);
    }

    A = 2; P = 2; C = 2; // Tipos de vacina
    for(i = 0; i < 6; i++){
        maior_idade(Espera, "UTC2", &elem);
        elem.primeiraDose = amanha;
        sorteado = rand() % 3; //sorteia de 0 a 2
        if(sorteado == 0 && A != 0){
            elem.tipoVacina = 'A';
            A--;
        }else if(sorteado == 1 && P != 0){
            elem.tipoVacina = 'P';
            P--;
        }else if(sorteado == 2 && C != 0){
            elem.tipoVacina = 'C';
            C--;
        }else{
            sorteado = rand() % 3;
        }
        insere_fim(UTC2, elem);
    }

    A = 2; P = 2; C = 2; // Tipos de vacina
    for(i = 0; i < 6; i++){
        maior_idade(Espera, "Prefeitura", &elem);
        elem.primeiraDose = amanha;
        sorteado = rand() % 3; //sorteia de 0 a 2
        if(sorteado == 0 && A != 0){
            elem.tipoVacina = 'A';
            A--;
        }else if(sorteado == 1 && P != 0){
            elem.tipoVacina = 'P';
            P--;
        }else if(sorteado == 2 && C != 0){
            elem.tipoVacina = 'C';
            C--;
        }else{
            sorteado = rand() % 3;
        }
        insere_fim(Prefeitura, elem);
    }

    A = 4; P = 4; C = 4; // Tipos de vacina
    i = 0;
    while(i < 12){
        maior_idade(Espera, "Sabiazinho", &elem);
        if(elem.tipoVacina == 'A' && A != 0){
            A--;
            insere_fim(Sabiazinho, elem);
            i++;
        }
        if(elem.tipoVacina == 'P' && P != 0){
            P--;
            insere_fim(Sabiazinho, elem);
            i++;
        }
        if(elem.tipoVacina == 'C' && C != 0){
            C--;
            insere_fim(Sabiazinho, elem);
            i++;
        }
    }

}
Data soma30(Data hoje){
    Data destino;

    short int bissexto;
    if(hoje.ano % 100 == 0 && hoje.ano % 400 == 0)
            bissexto = 1;
        else if(hoje.ano % 100 != 0 && hoje.ano % 4 == 0)
                bissexto = 1;
             else
                bissexto = 0;

    if(hoje.mes == 1 && bissexto == 0){
        destino.dia = hoje.dia + 30;
        if(destino.dia < 31)
            destino.mes = 1;
        else if(destino.dia < 59){
            destino.mes = 2;
            destino.dia = destino.dia - 30;
        }else{
            destino.mes = 3;
            destino.dia = destino.dia - 30;
            destino.dia = destino.dia - 28;
        }
    }

    if(hoje.mes == 1 && bissexto == 1){
        destino.dia = hoje.dia + 30;
        if(destino.dia < 31)
            destino.mes = 1;
        else if(destino.dia < 60){
            destino.mes = 2;
            destino.dia = destino.dia - 30;
        }else{
            destino.mes = 3;
            destino.dia = destino.dia - 30;
            destino.dia = destino.dia - 29;
        }
    }

    if(hoje.mes == 4 || hoje.mes == 6 || hoje.mes == 9 || hoje.mes == 11){
        destino.mes = hoje.mes + 1;
        destino.dia = hoje.dia;
    }else if(hoje.dia != 1){
        destino.mes = hoje.mes + 1;
        destino.dia = hoje.dia - 1;
    }else{
        destino.mes = hoje.mes;
        destino.dia = 31;
    }
    return destino;
}

void controle(Lista Vacinados, Fila UTC1, Fila UTC2, Fila Prefeitura, Fila Sabiazinho){
    int escolha;
    Pessoa elem;
    int result;

    while(fila_vazia(UTC1) == 0 && fila_vazia(UTC2) == 0 && fila_vazia(Prefeitura) == 0 && fila_vazia(Sabiazinho) == 0){
        printf("=== Vacinacao ===\n");
        printf("Escolha o local:\n");
        printf("1)UTC1\n");
        printf("2)UTC2\n");
        printf("3)Prefeitura\n");
        printf("4)Sabiazinho\n");
        scanf("%d", &escolha);
    }

    switch(escolha){
        case 1: result = remove_ini(UTC1, &elem);
                if(result == 1){
                    if(elem.tipoVacina == 'A'){
                        elem.segundaDose = soma30(elem.primeiraDose);
                        elem.segundaDose = soma30(elem.segundaDose);
                        elem.segundaDose = soma30(elem.segundaDose);
                    }else if(elem.tipoVacina == 'P')
                        elem.segundaDose = soma30(elem.primeiraDose); ///Adaptaçao
                     else if(elem.tipoVacina == 'C'){
                        elem.segundaDose = soma30(elem.primeiraDose);
                        elem.segundaDose = soma30(elem.segundaDose);
                     }
                     strcpy(elem.localVacinacao, "Sabiazinho");
                }
                break;

        case 2: result = remove_ini(UTC2, &elem);
                if(result == 1){
                    if(elem.tipoVacina == 'A'){
                        elem.segundaDose = soma30(elem.primeiraDose);
                        elem.segundaDose = soma30(elem.segundaDose);
                        elem.segundaDose = soma30(elem.segundaDose);
                    }else if(elem.tipoVacina == 'P')
                        elem.segundaDose = soma30(elem.primeiraDose); ///Adaptaçao
                     else if(elem.tipoVacina == 'C'){
                        elem.segundaDose = soma30(elem.primeiraDose);
                        elem.segundaDose = soma30(elem.segundaDose);
                     }
                     strcpy(elem.localVacinacao, "Sabiazinho");
                }
                break;

        case 3: result = remove_ini(Prefeitura, &elem);
                if(result == 1){
                    if(elem.tipoVacina == 'A'){
                        elem.segundaDose = soma30(elem.primeiraDose);
                        elem.segundaDose = soma30(elem.segundaDose);
                        elem.segundaDose = soma30(elem.segundaDose);
                    }else if(elem.tipoVacina == 'P')
                        elem.segundaDose = soma30(elem.primeiraDose); ///Adaptaçao
                     else if(elem.tipoVacina == 'C'){
                        elem.segundaDose = soma30(elem.primeiraDose);
                        elem.segundaDose = soma30(elem.segundaDose);
                     }
                     strcpy(elem.localVacinacao, "Sabiazinho");
                }
                break;

        case 4: result = remove_ini(Sabiazinho, &elem);
                if(result == 1)
                    insereLista(Vacinados, elem);
                break;
        default: printf("Opcao invalida.\n");

    }
}

void cenario(Lista Espera, Lista Vacinados, Fila UTC1, Fila UTC2, Fila Prefeitura, Fila Sabiazinho){
    Pessoa elem;
    int result;
    printf("=== Lista de espera ===\n");
    int i = 0;
    while(1){
        if(lista_vazia(Espera) == 1){
            printf("Lista Vazia.\n");
            break;
        }
        result = getPos(Espera, i, &elem);
        i++;
        if(result == 0)
            break;
        printf("%s --- %d\n", elem.nome, elem.idade);
    }

    printf("=== Lista de Vacinados ===\n");
    i = 0;
    while(1){
        if(lista_vazia(Vacinados) == 1){
            printf("Lista vazia.\n");
            break;
        }
        result = getPos(Vacinados, i, &elem);
        i++;
        if(result == 0)
            break;
        printf("%s --- %d\n", elem.nome, elem.idade);
    }

    printf("=== UTC1 ===\n");
    Fila temp = UTC1;
    while(fila_vazia(UTC1) == 0){
        remove_ini(UTC1, &elem);
        printf("%s --- %d\n", elem.nome, elem.idade);
    }
    UTC1 = temp;

    printf("=== UTC2 ===\n");
    temp = UTC2;
    while(fila_vazia(UTC2) == 0){
        remove_ini(UTC2, &elem);
        printf("%s --- %d\n", elem.nome, elem.idade);
    }
    UTC2 = temp;

    printf("=== Prefeitura ===\n");
    temp = Prefeitura;
    while(fila_vazia(Prefeitura) == 0){
        remove_ini(Prefeitura, &elem);
        printf("%s --- %d\n", elem.nome, elem.idade);
    }
    Prefeitura = temp;

    printf("=== Sabiazinho ===\n");
    temp = Sabiazinho;
    while(fila_vazia(Sabiazinho) == 0){
        remove_ini(Sabiazinho, &elem);
        printf("%s --- %d\n", elem.nome, elem.idade);
    }
    Sabiazinho = temp;
}

int main(){
    Lista Espera = cria_lista();
    Lista Vacinados = cria_lista();
    Fila UTC1 = cria_fila();
    Fila UTC2 = cria_fila();
    Fila Prefeitura = cria_fila();
    Fila Sabiazinho = cria_fila();
    int escolha;

    while(1){
        printf("==== Sistema de vacinacao ====\n");
        printf("1_Cadastro da lista de espera.\n");
        printf("2_Geracao de filas diarias.\n");
        printf("3_Controle de Vacianacao.\n");
        printf("4_Cenario da vacinacao.\n");
        printf("5_Sair.\n>> ");
        scanf("%d", &escolha);

        switch(escolha){
            case 1: cadastro(Espera);
                    break;

            case 2: geracao(Espera, UTC1, UTC2, Prefeitura, Sabiazinho);
                    break;

            case 3: controle(Vacinados, UTC1, UTC2, Prefeitura, Sabiazinho);
                    break;

            case 4: cenario(Espera, Vacinados, UTC1, UTC2, Prefeitura, Sabiazinho);
                    break;

            case 5: apaga_fila(UTC1);
                    apaga_fila(UTC2);
                    apaga_fila(Prefeitura);
                    apaga_fila(Sabiazinho);
                    free(Vacinados);
                    free(Espera);
                    break;

            default: printf("Opcao invalida.\n");
        }
    if(escolha == 5) break;
    }

    return 0;
}
