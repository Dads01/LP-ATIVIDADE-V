#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// alunos: Breno Rodrigues Gusm�o Souza
//  D�rio de Santana Meira Martfeld

typedef struct
{
    char nome[70];
    int idade;
    char rg[250];
    float salario;
} Funcionario;

void cadastrarFuncionario(Funcionario *funcionario)
{
    printf("Informe o nome do funcion�rio: ");
    scanf("%s", funcionario->nome);
    fflush(stdin);
    printf("Informe o RG do funcion�rio: ");
    scanf("%s", funcionario->rg);
    printf("Informe a idade do funcion�rio: ");
    scanf("%d", &funcionario->idade);
    printf("Informe o sal�rio do funcion�rio: ");
    scanf("%f", &funcionario->salario);
    printf("Funcion�rio cadastrado com sucesso!\n");
    system("cls || clean");
}

void exibirInformacoes(Funcionario *funcionario)
{
    printf("Nome: %s\n", funcionario->nome);
    printf("RG: %s\n", funcionario->rg);
    printf("Idade: %d\n", funcionario->idade);
    printf("Sal�rio: %.2f\n", funcionario->salario);
}

void calcularAumento(Funcionario *funcionario)
{
    float percentualAumento;
    printf("Informe o percentual de aumento: ");
    scanf("%f", &percentualAumento);
    funcionario->salario *= (1 + percentualAumento / 100);
    printf("Aumento aplicado com sucesso!\n");
    exibirInformacoes(funcionario);
}

void demitirFuncionario(Funcionario *funcionario)
{
    printf("Funcion�rio demitido com sucesso!\n");
    strcpy(funcionario->nome, "");
    funcionario->idade = 0;
    funcionario->salario = 0;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    Funcionario usuario;
    int opcao;

    do
    {
 fflush(stdin);
        printf("\n==================================================");
        printf("\nSistema de Gest�o de Recursos Humanos - Usu�rio\n");
        printf("1. Cadastrar Funcion�rio\n");
        printf("2. Exibir Informa��es do Funcion�rio\n");
        printf("3. Calcular Aumento de Sal�rio\n");
        printf("4. Demitir Funcion�rio\n");
        printf("5. Sair\n");
        printf("Escolha uma op��o:");
        scanf("%d", &opcao);
        printf("==================================================\n");
         
         
        
        switch (opcao)
        {
        case 1:
            cadastrarFuncionario(&usuario);
            break;
        case 2:
            exibirInformacoes(&usuario);
            break;
        case 3:
            calcularAumento(&usuario);
            break;
        case 4:
            demitirFuncionario(&usuario);
            break;
        case 5:
            printf("Saindo do programa. Obrigado!\n");
            break;
        default:
            printf("Op��o inv�lida. Tente novamente.\n");
        }

    } while (opcao != 5);

    return 0;
}
