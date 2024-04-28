#include <stdio.h>

// Fun��o para comparar duas strings completamente
int compare_strings(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        //Utiliza um loop while para percorrer os caracteres de ambas as strings at� encontrar o caractere nulo ('\0') que indica o final da string.
        if (*s1 != *s2)
            return 0; // As strings s�o diferentes
        s1++;
        s2++;
    }
    return (*s1 == '\0' && *s2 == '\0'); // Retorna 1 se as duas strings terminam ao mesmo tempo
}

// Fun��o para verificar se o usu�rio n�o consta no sistema
int usuario_nao_consta(const char *usuario) {
    if (compare_strings(usuario, "admin") || compare_strings(usuario, "usuario1") || compare_strings(usuario, "visitante")) {
        return 0; // O usu�rio foi reconhecido no sistema
    }
    return 1; // O usu�rio n�o foi reconhecido no sistema
}

int main() {
    char usuario[20];
    char senha[20];
    int usuario_reconhecido = 0;

    printf("Digite seu nome de usuario: ");
    scanf("%s", usuario);
    printf("Digite sua senha: ");
    scanf("%s", senha);

    // Verifica��o das credenciais fornecidas
    if (compare_strings(usuario, "admin") && compare_strings(senha, "admin123")) {
        printf("Bem-vindo, Administrador! Voce tem acesso total.\n");
        usuario_reconhecido = 1;
    } else if (compare_strings(usuario, "usuario1") && compare_strings(senha, "senha123")) {
        printf("Bem-vindo, Usuario! Voce tem acesso limitado a algumas informacoes.\n");
        usuario_reconhecido = 1;
    } else if (compare_strings(usuario, "visitante") && compare_strings(senha, "visitante123")) {
        printf("Bem-vindo, Visitante! Voce tem acesso limitado.\n");
        usuario_reconhecido = 1;
    }

    // Verifica se o usu�rio n�o consta no sistema
    if (usuario_nao_consta(usuario)) {
        printf("Usuario nao reconhecido no sistema.\n");
    } else if (!usuario_reconhecido) {
        printf("Senha incorreta.\n");
    }


    return 0;
}