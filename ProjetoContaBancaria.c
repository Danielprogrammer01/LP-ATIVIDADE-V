#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>

struct contaBancaria
{
    float saldo;
    float valorInicial;
    float valorDeposito;
    float valorSaque;
};


float deposito(struct contaBancaria conta)
{
    return conta.valorInicial + conta.valorDeposito;
}

float saque(struct contaBancaria conta)
{
    return conta.saldo - conta.valorSaque;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    int codigo;
    char nomeDoTitular[999];
    char email[999];
    char idade[999];
    char cpf[999];
    char rg[999];
    char dataDeNascimento[3][999];
    char telefone [999];
    float depositoBancario;
    float saqueBancario;
    float saldo;
    float saldoPreSaque;
    float saldoPreDeposito;

    struct contaBancaria conta;

    do
    {
    printf("\n=====================\n");
    printf("\tMENU");
    printf("\n=====================\n");

    printf("Código | Descrição\n");
    printf("\n(1) - Criar Conta Bancária");
    printf("\n");
    printf("\nDigite 1 para criar uma conta: ");
    scanf("%d", &codigo);

    if (codigo != 1)
    {
        printf("\nOPÇÃO INVÁLIDA! DIGITE NOVAMENTE.\n");
    }

    } while (codigo != 1);
    
    
    do
    {
        fflush(stdin);
        system("cls || clear");

        printf("\nDigite seu nome completo: ");
        gets(nomeDoTitular);

        fflush(stdin);
        system("cls || clear");

        printf("\nDigite seu email: ");
        gets(email);

        system("cls || clear");

        printf("\nDigite seu telefone: ");
        gets(telefone);

        system("cls || clear");

        printf("\nDigite sua idade: ");
        gets(idade);

        fflush(stdin);
        system("cls || clear");

        printf("\nDigite o seu CPF: ");
        gets(cpf);

        system("cls || clear");

        printf("\nDigite seu RG: ");
        gets(rg);

        system("cls || clear");

        printf("\nDigite a data de nascimento\n");

        printf("\nDia: ");
        gets(dataDeNascimento[0]);

        printf("\nMês: ");
        gets(dataDeNascimento[1]);

        printf("\nAno: ");
        gets(dataDeNascimento[2]);

        fflush(stdin);
        system("cls || clear");

    } while (codigo != 1);

    printf("\nConta cadastrada com sucesso!\n");
    printf("\nBEM-VINDO A SUA CONTA!\n");

    do
    {

        printf("\n=====================\n");
        printf("\tMENU");
        printf("\n=====================\n");

        printf("Código | Descrição\n");
        printf("\n(1) - Depósito");
        printf("\n(2) - Saque");
        printf("\n(3) - Saldo");
        printf("\n(4) - Exibir dados pessoais");
        printf("\n(5) - Sair da Conta\n");

        printf("\nDigite a opção desejada: ");
        scanf("%d", &codigo);

        switch (codigo)
        {
        case 1:

            system("cls || clear");
            printf("\nInforme o valor do depósito: R$");
            scanf("%f", &conta.valorDeposito);

            depositoBancario = deposito(conta);
            conta.saldo = conta.saldo + conta.valorDeposito;
            saldo = conta.saldo;
            saldoPreDeposito = saldo - depositoBancario;

            system("cls || clear");
            printf("\nDepósito realizado com sucesso!\n");
            printf("\nEXTRATO: \n");
            printf ("\nSaldo pré-depósito: R$%.2f\n", saldoPreDeposito);
            printf("\nValor do depósito: R$%.2f\n", conta.valorDeposito);
            printf("\nSaldo atual da conta: R$%.2f\n", saldo);

            break;

        case 2:

            system("cls || clear");
            printf ("\nInforme o valor da saque: R$");
            scanf ("%f", &conta.valorSaque);

            saqueBancario = saque(conta);
            conta.saldo = conta.saldo - conta.valorSaque;
            saldo = saldo - saqueBancario;
            saldoPreSaque = saldo + saqueBancario;

            system("cls || clear");
            printf("\nSaque realizado com sucesso!\n");
            printf("\nEXTRATO: \n");
            printf ("\nSaldo pré-saque: R$%.2f\n", saldoPreSaque);
            printf ("\nValor do saque: R$%.2f\n",conta.valorSaque);
            printf ("\nSaldo atual da conta: R$%.2f\n", saldo);
            break;

        case 3:
            
            system("cls || clear");
            saldo = conta.saldo;
            printf("\nSaldo: R$%.2f", saldo);
            printf("\n");

            break;

        case 4:

           system("cls || clear");
           printf("Titular da conta: %s", nomeDoTitular);
           printf("\nData de Nascimento: %s/%s/%s", dataDeNascimento[0], dataDeNascimento[1], dataDeNascimento[2]);
           printf("\nIdade: %s", idade);
           printf("\nCPF: %s", cpf);
           printf("\nRG: %s", rg);
           printf("\nTelefone: %s", telefone);
           printf("\nEmail: %s", email);
           printf("\n");
            
            break;

        case 5:
            /* code */
            break;

        default:
            
            system("cls || clear");
            printf("\nOPÇÃO INVÁLIDA! DIGITE NOVAMENTE.\n");
            break;
        }

    } while (codigo != 5);

    return 0;
}