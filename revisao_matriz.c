#include <stdio.h>

typedef struct {
    double nota, frequencia;
} Aluno;

int main() {

    int i, aprovados, reprovados_ambos, reprovados_nota, reprovados_frequencia;
    double soma;
    i = aprovados = reprovados_ambos = reprovados_nota = reprovados_frequencia = soma = 0;
    
    Aluno alunos[30];

    for (i = 0; i < 30; i++) {
        scanf("%lf %lf", &alunos[i].nota, &alunos[i].frequencia);
        soma += alunos[i].nota;

        if (alunos[i].nota < 6.0 && alunos[i].frequencia < 75) reprovados_ambos++;
        else if (alunos[i].nota < 6.0) reprovados_nota++;
        else if (alunos[i].frequencia < 75) reprovados_frequencia++;
        else aprovados++;
    }

    printf("Media geral da turma: %.2lf\n", soma / 30.0);
    printf("Alunos aprovados: %d\n", aprovados);
    printf("Alunos reprovados por nota: %d\n", reprovados_nota);
    printf("Alunos reprovados por frequencia: %d\n", reprovados_frequencia);
    printf("Alunos reprovados por nota e frequencia: %d\n", reprovados_ambos);

    return 0;
}
