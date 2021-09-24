#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <conio.h>
using namespace std;


int main()
{
    setlocale (LC_ALL, "Portuguese");

    time_t rawtime;
    struct tm * timeinfo;
    int CPF_V[11], soma, resto;
    int cont, cont2;
      system("color f3");
        system("title VALIDADOR DE CPF");
    do{
        // zera valor para retorno do programa
            resto = soma = 0;
            cont = cont2 = 9;


//PARA O USUARIO DIGITAR O CPF
        cout<<"DIGITE UM NUMERO E DE ENTER"<<endl;
        do{
            for (int i = 0; i < 11; i++)
            {
                cout<<"Dígito "<<i+1<<": ";
                cin>>CPF_V[i];
            }

            for (int i = 0; i < 9; i++)
            {
                soma += CPF_V[i] * (10-i);
            }

            resto = (soma * 10) % 11;
            system("cls");
            cout<<"O CPF:   ";

            for (int i = 0; i < 11; i++)
            {
                if  ((i == 3) || (i == 6)){

                    cout<<".";
                    cout<<""<<CPF_V[i];


                }else{
                    if (i == 9){
                        cout<<"-";
                        cout<<""<<CPF_V[i];
                    }else{
                    cout<<""<<CPF_V[i];
                    }
                }
            }

            cout<<"  está certo?"<<endl;
            cout<<"***Aperte 1 para continuar ou 0 parar digitar novamente o CPF:  ";
            cin>>cont2;

        }while (cont2 != 1);

//VERIFICAÇÃO DE CPF VALIDO OU NAO.
        if ((CPF_V[9] == resto) || ((resto == 10) && (CPF_V[9] == 0)))
        {
            soma = 0;

            for (int i = 0; i < 10; i++)
            {
                soma += CPF_V[i] * (11-i);
            }

            resto = (soma * 10) % 11;

            if ((CPF_V[10] == resto) || ((resto == 10) && (CPF_V[10] == 0)))
            {
                 system("cls");
                system("color 3f");
                cout<<endl<<"O CPF É VALIDO!"<<endl;
            }
            else
            {
                 system("cls");
                system("color 4f");
                cout<<endl<<"O CPF É INVALIDO!"<<endl;
            }
        }
        else
        {
             system("cls");
            system("color 4f");
             cout<<endl<<"O CPF É INVALIDO!"<<endl;
        }

//OBTENÇÃO DE DATA E HORA DO SISTEMA
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        printf ( "Data atual do sistema é: %s", asctime (timeinfo) );

//CONSULTA DE OUTRO CPF
        cout<<endl<<"Deseja consultar outro CPF?"<<endl;
        cout<<"***Aperte 1 para ENCERRAR ou 0 para CONSULTAR outro CPF:  ";
        cin>>cont;
            if (cont == 0){
                system("cls");
                 system("color f3");}
    } while (cont != 1);
}
