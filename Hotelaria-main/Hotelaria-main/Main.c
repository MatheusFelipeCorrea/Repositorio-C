#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estruturas
typedef struct {
    int codigo;
    char nome[100];
    char endereco[300];
    char telefone[10];
} Cliente;

typedef struct {
    int codigo;
    char nome[100];
    char telefone[11];
    char cargo[100];
    int salario;
} Funcionario;

typedef struct {
    int codigo;
    int codigoCliente;
    int numeroQuarto;
    char dataEntrada[11];
    char dataSaida[11];
    int quantidadeDiarias;
    float valorTotal;
    int ativo; // 0 - Estadia finalizada, 1 - Estadia ativa
} Estadia;

typedef struct {
    int codigo;
    int numero;
    int quantidadeHospedes;
    float valorDiaria;
    char status[20];
} Quarto;

// Máximos
int maxFunc = 50;
int maxClient = 70;
int maxEstad = 20;
int maxQuarts = 20;

// Arrays para armazenar dados
Cliente clientes[70];
Funcionario funcionarios[50];
Estadia estadias[20];
Quarto quartos[20];

// Contadores
int totalClientes = 0;
int totalFuncionarios = 0;
int totalQuartos = 0;
int totalEstadias = 0;

// Funções para salvar dados
void salvarClientes() {
    FILE *arquivo = fopen("clientes.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo de clientes para escrita.\n");
        return;
    }
    for (int i = 0; i < totalClientes; i++) {
        fprintf(arquivo, "%d;%s;%s;%s\n", clientes[i].codigo, clientes[i].nome, clientes[i].endereco, clientes[i].telefone);
    }
    fclose(arquivo);
}

void salvarFuncionarios() {
    FILE *arquivo = fopen("funcionarios.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo de funcionários para escrita.\n");
        return;
    }
    for (int i = 0; i < totalFuncionarios; i++) {
        fprintf(arquivo, "%d;%s;%s;%s;%d\n", funcionarios[i].codigo, funcionarios[i].nome, funcionarios[i].telefone, funcionarios[i].cargo, funcionarios[i].salario);
    }
    fclose(arquivo);
}

void salvarEstadias() {
    FILE *arquivo = fopen("estadias.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo de estadias para escrita.\n");
        return;
    }
    for (int i = 0; i < totalEstadias; i++) {
        fprintf(arquivo, "%d;%d;%d;%s;%s;%d;%.2f;%d\n", estadias[i].codigo, estadias[i].codigoCliente, estadias[i].numeroQuarto, estadias[i].dataEntrada, estadias[i].dataSaida, estadias[i].quantidadeDiarias, estadias[i].valorTotal, estadias[i].ativo);
    }
    fclose(arquivo);
}

void salvarQuartos() {
    FILE *arquivo = fopen("quartos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo de quartos para escrita.\n");
        return;
    }
    for (int i = 0; i < totalQuartos; i++) {
        fprintf(arquivo, "%d;%d;%d;%.2f;%s\n", quartos[i].codigo, quartos[i].numero, quartos[i].quantidadeHospedes, quartos[i].valorDiaria, quartos[i].status);
    }
    fclose(arquivo);
}

// Funções para carregar dados
void carregarClientes() {
    FILE *arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL) {
        printf("Arquivo de clientes não encontrado. Iniciando sem clientes cadastrados.\n");
        return;
    }
    while (!feof(arquivo)) {
        Cliente c;
        if (fscanf(arquivo, "%d;%99[^;];%299[^;];%9[^\n]\n", &c.codigo, c.nome, c.endereco, c.telefone) == 4) {
            clientes[totalClientes++] = c;
        }
    }
    fclose(arquivo);
}

void carregarFuncionarios() {
    FILE *arquivo = fopen("funcionarios.txt", "r");
    if (arquivo == NULL) {
        printf("Arquivo de funcionários não encontrado. Iniciando sem funcionários cadastrados.\n");
        return;
    }
    while (!feof(arquivo)) {
        Funcionario f;
        if (fscanf(arquivo, "%d;%99[^;];%10[^;];%99[^;];%d\n", &f.codigo, f.nome, f.telefone, f.cargo, &f.salario) == 5) {
            funcionarios[totalFuncionarios++] = f;
        }
    }
    fclose(arquivo);
}

void carregarEstadias() {
    FILE *arquivo = fopen("estadias.txt", "r");
    if (arquivo == NULL) {
        printf("Arquivo de estadias não encontrado. Iniciando sem estadias cadastradas.\n");
        return;
    }
    while (!feof(arquivo)) {
        Estadia e;
        if (fscanf(arquivo, "%d;%d;%d;%10[^;];%10[^;];%d;%f;%d\n", &e.codigo, &e.codigoCliente, &e.numeroQuarto, e.dataEntrada, e.dataSaida, &e.quantidadeDiarias, &e.valorTotal, &e.ativo) == 8) {
            estadias[totalEstadias++] = e;
        }
    }
    fclose(arquivo);
}

void carregarQuartos() {
    FILE *arquivo = fopen("quartos.txt", "r");
    if (arquivo == NULL) {
        printf("Arquivo de quartos não encontrado. Iniciando sem quartos cadastrados.\n");
        return;
    }
    while (!feof(arquivo)) {
        Quarto q;
        if (fscanf(arquivo, "%d;%d;%d;%f;%19[^\n]\n", &q.codigo, &q.numero, &q.quantidadeHospedes, &q.valorDiaria, q.status) == 5) {
            quartos[totalQuartos++] = q;
        }
    }
    fclose(arquivo);
}

// Função para cadastrar um novo Funcionario
void cadastrarFuncionario() {
    printf("\n |CADASTRO DE FUNCIONARIO\n\n ");
    if (totalFuncionarios >= maxFunc) {
        printf("Limite de funcionarios atingido.\n");
        return;
    }

    Funcionario f;
    f.codigo = totalFuncionarios + 1; // Código automático

    printf("\nNome: ");
    scanf(" %[^\n]", f.nome);
    printf("\nTelefone: ");
    scanf(" %[^\n]", f.telefone);
    printf("\nCargo: ");
    scanf(" %[^\n]", f.cargo);
    printf("\nSalario: ");
    scanf("%d", &f.salario);

    // Verifica se já existe um funcionário com o mesmo código
    for (int i = 0; i < totalFuncionarios; i++) {
        if (funcionarios[i].codigo == f.codigo) {
            printf("Código de funcionário já existente. Tente novamente.\n");
            return;
        }
    }

    funcionarios[totalFuncionarios++] = f;
    salvarFuncionarios();

    printf("\n *Funcionario cadastrado com sucesso!\n");
    printf("\n *Codigo do funcionario: %d\n", f.codigo);
}

// Função para cadastrar um novo Cliente
void cadastrarCliente() {
    printf("\n |CADASTRO DE CLIENTE\n ");
    if (totalClientes >= maxClient) {
        printf("Limite de clientes atingido.\n");
        return;
    }

    Cliente c;
    c.codigo = totalClientes + 1; // Código automático

    printf("\nNome: ");
    scanf(" %[^\n]", c.nome);
    printf("\nEndereco: ");
    scanf(" %[^\n]", c.endereco);
    printf("\nTelefone: ");
    scanf(" %[^\n]", c.telefone);

    // Verifica se já existe um cliente com o mesmo código
    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].codigo == c.codigo) {
            printf("Código de cliente já existente. Tente novamente.\n");
            return;
        }
    }

    clientes[totalClientes++] = c;
    salvarClientes();

    printf("\n *Cliente cadastrado com sucesso!\n");
    printf("\n *Codigo do cliente: %d\n", c.codigo);
}

// Função para cadastrar um novo Quarto
void cadastrarQuarto() {
    printf("\n |CADASTRO DE QUARTO\n ");
    if (totalQuartos >= maxQuarts) {
        printf("Limite de quartos atingido.\n");
        return;
    }

    Quarto q;
    q.codigo = totalQuartos + 1; // Código automático

    printf("\nNúmero do quarto: ");
    scanf("%d", &q.numero);
    printf("\nQuantidade de hóspedes: ");
    scanf("%d", &q.quantidadeHospedes);
    printf("\nValor da diária: ");
    scanf("%f", &q.valorDiaria);
    printf("\nStatus (desocupado/ocupado): ");
    scanf(" %[^\n]", q.status);

    quartos[totalQuartos++] = q;
    salvarQuartos();

    printf("\n *Quarto cadastrado com sucesso!\n");
    printf("\n *Código do quarto: %d\n", q.codigo);
}

// Função para verificar sobreposição de estadias
int verificarSobreposicaoEstadia(int numeroQuarto, char *dataEntrada, char *dataSaida) {
    int diaEntrada, mesEntrada, anoEntrada;
    int diaSaida, mesSaida, anoSaida;
    sscanf(dataEntrada, "%d/%d/%d", &diaEntrada, &mesEntrada, &anoEntrada);
    sscanf(dataSaida, "%d/%d/%d", &diaSaida, &mesSaida, &anoSaida);

    for (int i = 0; i < totalEstadias; i++) {
        if (estadias[i].numeroQuarto == numeroQuarto && estadias[i].ativo == 1) {
            int diaEntradaExistente, mesEntradaExistente, anoEntradaExistente;
            int diaSaidaExistente, mesSaidaExistente, anoSaidaExistente;
            sscanf(estadias[i].dataEntrada, "%d/%d/%d", &diaEntradaExistente, &mesEntradaExistente, &anoEntradaExistente);
            sscanf(estadias[i].dataSaida, "%d/%d/%d", &diaSaidaExistente, &mesSaidaExistente, &anoSaidaExistente);

            // Verificar sobreposição de datas
            if ((anoEntrada < anoSaidaExistente || (anoEntrada == anoSaidaExistente && mesEntrada < mesSaidaExistente) ||
                (anoEntrada == anoSaidaExistente && mesEntrada == mesSaidaExistente && diaEntrada <= diaSaidaExistente)) &&
                (anoSaida > anoEntradaExistente || (anoSaida == anoEntradaExistente && mesSaida > mesEntradaExistente) ||
                (anoSaida == anoEntradaExistente && mesSaida == mesEntradaExistente && diaSaida >= diaEntradaExistente))) {
                return 1;
            }
        }
    }
    return 0;
}

void cadastrarEstadia() {
    printf("\n |CADASTRO DE ESTADIA\n ");
    if (totalEstadias >= maxEstad) {
        printf("Limite de estadias atingido.\n");
        return;
    }

    int codigoCliente, numeroQuarto;
    char dataEntrada[11], dataSaida[11];

    printf("\nCódigo do cliente: ");
    scanf("%d", &codigoCliente);

    // Verificar se o cliente existe
    int clienteExiste = 0;
    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].codigo == codigoCliente) {
            clienteExiste = 1;
            break;
        }
    }

    if (!clienteExiste) {
        printf("!-Cliente não encontrado-!\n");
        return;
    }

    printf("\nNúmero do quarto: ");
    scanf("%d", &numeroQuarto);

    // Verificar se o quarto existe e está desocupado
    int quartoExiste = 0;
    for (int i = 0; i < totalQuartos; i++) {
        if (quartos[i].numero == numeroQuarto && strcmp(quartos[i].status, "desocupado") == 0) {
            quartoExiste = 1;
            break;
        }
    }

    if (!quartoExiste) {
        printf("Quarto não encontrado ou ocupado.\n");
        return;
    }

    printf("\nData de entrada (dd/mm/yyyy): ");
    scanf(" %[^\n]", dataEntrada);
    printf("\nData de saída (dd/mm/yyyy): ");
    scanf(" %[^\n]", dataSaida);

    // Calcular a quantidade de diárias corretamente
    int diaEntrada, mesEntrada, anoEntrada;
    int diaSaida, mesSaida, anoSaida;
    sscanf(dataEntrada, "%d/%d/%d", &diaEntrada, &mesEntrada, &anoEntrada);
    sscanf(dataSaida, "%d/%d/%d", &diaSaida, &mesSaida, &anoSaida);

    // Calculando a quantidade de diárias considerando anos bissextos e meses com diferentes números de dias
    struct tm entrada = {0}, saida = {0};
    entrada.tm_mday = diaEntrada;
    entrada.tm_mon = mesEntrada - 1;
    entrada.tm_year = anoEntrada - 1900;
    saida.tm_mday = diaSaida;
    saida.tm_mon = mesSaida - 1;
    saida.tm_year = anoSaida - 1900;

    time_t timeEntrada = mktime(&entrada);
    time_t timeSaida = mktime(&saida);

    if (timeSaida <= timeEntrada) {
        printf("!-Data de saída inválida-!\n");
        return;
    }

    double seconds = difftime(timeSaida, timeEntrada);
    int quantidadeDiarias = seconds / (60 * 60 * 24);

    // Verificar sobreposição de estadias
    if (verificarSobreposicaoEstadia(numeroQuarto, dataEntrada, dataSaida)) {
        printf("\nO quarto já está reservado para o período informado.\n");
        return;
    }

    Estadia e;
    e.codigo = totalEstadias + 1; // Código automático
    e.codigoCliente = codigoCliente;
    e.numeroQuarto = numeroQuarto;
    strcpy(e.dataEntrada, dataEntrada);
    strcpy(e.dataSaida, dataSaida);
    e.quantidadeDiarias = quantidadeDiarias;

    // Encontrar o quarto para obter o valor da diária
    float valorDiaria = 0;
    for (int i = 0; i < totalQuartos; i++) {
        if (quartos[i].numero == numeroQuarto) {
            valorDiaria = quartos[i].valorDiaria;
            break;
        }
    }

    e.valorTotal = quantidadeDiarias * valorDiaria;
    e.ativo = 1;

    estadias[totalEstadias++] = e;
    salvarEstadias();

    // Atualizar o status do quarto para ocupado
    for (int i = 0; i < totalQuartos; i++) {
        if (quartos[i].numero == numeroQuarto) {
            strcpy(quartos[i].status, "ocupado");
            salvarQuartos();
            break;
        }
    }

    printf("\n *Estadia cadastrada com sucesso!\n");
    printf("\n *Código da estadia: %d\n", e.codigo);
}
// Função para finalizar uma estadia
void finalizarEstadia() {
    printf("\n |FINALIZAR ESTADIA\n ");
    int codigoEstadia;
    printf("\nCódigo da estadia: ");
    scanf("%d", &codigoEstadia);

    for (int i = 0; i < totalEstadias; i++) {
        if (estadias[i].codigo == codigoEstadia && estadias[i].ativo == 1) {
            estadias[i].ativo = 0;
            salvarEstadias();

            // Atualizar o status do quarto para desocupado
            for (int j = 0; j < totalQuartos; j++) {
                if (quartos[j].numero == estadias[i].numeroQuarto) {
                    strcpy(quartos[j].status, "desocupado");
                    salvarQuartos();
                    break;
                }
            }

            printf("\nEstadia finalizada. Valor total a ser pago: %.2f\n", estadias[i].valorTotal);
            return;
        }
    }

    printf("!-Estadia não encontrada ou já finalizada-!\n");
}

// Função para pesquisar clientes
void pesquisarCliente() {
    printf("\n |PESQUISAR CLIENTE\n");
    int codigo;
    char nome[100];
    printf("\nDigite o código ou nome do cliente para pesquisa: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].codigo == codigo || strcmp(clientes[i].nome, nome) == 0) {
            printf("\nCliente encontrado:\n");
            printf("\nCódigo: %d\n", clientes[i].codigo);
            printf("\nNome: %s\n", clientes[i].nome);
            printf("\nEndereço: %s\n", clientes[i].endereco);
            printf("\nTelefone: %s\n", clientes[i].telefone);
             printf("----------------------------\n");
            return;
        }
    }

    printf("!-Cliente não encontrado-!\n");
}

// Função para pesquisar funcionários
void pesquisarFuncionario() {
    printf("\n |PESQUISAR FUNCIONARIO\n");
    int codigo;
    char nome[100];
    printf("Digite o código ou nome do funcionário para pesquisa: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < totalFuncionarios; i++) {
        if (funcionarios[i].codigo == codigo || strcmp(funcionarios[i].nome, nome) == 0) {
            printf("Funcionário encontrado:\n");
            printf("\nCódigo: %d\n", funcionarios[i].codigo);
            printf("\nNome: %s\n", funcionarios[i].nome);
            printf("\nTelefone: %s\n", funcionarios[i].telefone);
            printf("\nCargo: %s\n", funcionarios[i].cargo);
            printf("\nSalário: %d\n", funcionarios[i].salario);
            printf("----------------------------\n");
            return;
        }
    }

    printf("\n!-Funcionário não encontrado-!\n");
}

// Função para mostrar todas as estadias de um cliente
void mostrarEstadiasCliente() {
    printf("\n |ESTADIAS DO CLIENTE\n");
    int codigoCliente;
    printf("\nDigite o código do cliente: ");
    scanf("%d", &codigoCliente);

    printf("\nEstadias do cliente %d:\n", codigoCliente);
    for (int i = 0; i < totalEstadias; i++) {
        if (estadias[i].codigoCliente == codigoCliente) {
            printf("\nCódigo da estadia: %d\n", estadias[i].codigo);
            printf("\nNúmero do quarto: %d\n", estadias[i].numeroQuarto);
            printf("\nData de entrada: %s\n", estadias[i].dataEntrada);
            printf("Data de saída: %s\n", estadias[i].dataSaida);
            printf("\nQuantidade de diárias: %d\n", estadias[i].quantidadeDiarias);
            printf("\nValor total: %.2f\n", estadias[i].valorTotal);
            printf("\nStatus: %s\n", estadias[i].ativo ? "Ativa" : "Finalizada");
            printf("\n");
        }
    }
}

// Função principal (main)
int main() {
    carregarClientes();
    carregarFuncionarios();
    carregarQuartos();
    carregarEstadias();

    int opcao;

    while (1) {
        printf("\n--------------Menu--------------\n");
        printf("|1.Cadastrar cliente\n");
        printf("|2.Cadastrar funcionário\n");
        printf("|3.Cadastrar quarto\n");
        printf("|4.Cadastrar estadia\n");
        printf("|5.Finalizar estadia\n");
        printf("|6.Pesquisar cliente\n");
        printf("|7.Pesquisar funcionário\n");
        printf("|8.Mostrar estadias de um cliente\n");
        printf("|0.Sair\n");
        printf("--------------------------------\n");

        printf("\nDigite a opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                cadastrarFuncionario();
                break;
            case 3:
                cadastrarQuarto();
                break;
            case 4:
                cadastrarEstadia();
                break;
            case 5:
                finalizarEstadia();
                break;
            case 6:
                pesquisarCliente();
                break;
            case 7:
                pesquisarFuncionario();
                break;
            case 8:
                mostrarEstadiasCliente();
                break;
            case 0:
                printf("\n*-Saindo...-*\n");
                exit(0);
            default:
                printf("Opção inválida.\n");
        }
    }

    return 0;
}
