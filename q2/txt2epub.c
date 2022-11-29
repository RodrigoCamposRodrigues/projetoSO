#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syscall.h>
#include <unistd.h>
#include <sys/wait.h>

void pandoc_converter(char *fname) 
{
    char *command = "pandoc";
    char *setting = "-o";
    char *setting1 = "--quiet"; //para tirar os warnings
    char *arg1 = fname;
    //crio um duplicado do ficheiro que recebo, que vai ser o novo ficheiro que vou retornar
    char *output_fname = strdup(fname);
    int len = strlen(arg1);
    // tirar .txt e pôr .epub
    output_fname[len] = 'b';
    output_fname[len - 1] = 'u';
    output_fname[len - 2] = 'p';
    output_fname[len - 3] = 'e';
    output_fname[len - 4] = '.';

    //o execlp executa o comando que lhe passo em primeiro lugar com o argv que lhe passo no resto dos argumentos
    //no primeiro command é o executável e o segundo é o primeiro index do argv que é o nome do executável
    execlp(command, command, fname, setting,output_fname, setting1, (char *)0);
}

void createChild(char *fname)
{

    int pid;  // para saber se é o pai ou o filho
    int status = 0; // estado do processo

    // dar fork ao processo
    pid = fork();
    if ((pid) < 0) {
        // Se o pid for menor que 0 então dá erro
        fprintf(stderr, "Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // se o pid for 0 então este é o processo filho
        pandoc_converter(fname);
    } else {
        // se o pid for maior que 0, então este é o processo pai
        // esperar que o processo filho acabe
        printf("Waiting for child process to finish...\nConverting %s to epub...\n", fname);
    }
}

int main(int argc, char *argv[])
{
    char *file1 = argv[1];
    //para cada ficheiro recebido na linha de comandos, crio um processo filho
    for (int i = 1; i < argc; i++) 
    {
        createChild(argv[i]);
    }

    //vai esperar por todos os processos filhos
     for (int i = 1; i < argc; i++)
    {
        int status = 0;
        pid_t childpid = wait(&status);
    }
    
    system("zip ebooks *.epub");
    return (EXIT_SUCCESS);
}