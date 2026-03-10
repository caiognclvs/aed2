#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double nota, frequencia;
} Aluno;

typedef struct {
	Aluno aluno;
	struct No* proximo;
} No;

No* inserir_inicio(No* primeiro, Aluno aluno) {
	No* novo_no = malloc(sizeof(No));
	
	novo_no->aluno = aluno;
	novo_no->proximo = primeiro;
	
	return novo_no;
}

void libera_lista(No* primeiro) {
    No* temp;

    while (primeiro != NULL) {
        temp = primeiro;
        primeiro = primeiro->proximo;
        free(temp);
    }
}

int main() {

    int i, aprovados, reprovados_ambos, reprovados_nota, reprovados_frequencia;
    double soma;
    i = aprovados = reprovados_ambos = reprovados_nota = reprovados_frequencia = soma = 0;
    
    No* primeiro = NULL;
    Aluno aluno;

    for (i = 0; i < 30; i++) {
        scanf("%lf %lf", &aluno.nota, &aluno.frequencia);
        soma += aluno.nota;
        primeiro = inserir_inicio(primeiro, aluno);

        if (aluno.nota < 6.0 && aluno.frequencia < 75) reprovados_ambos++;
        else if (aluno.nota < 6.0) reprovados_nota++;
        else if (aluno.frequencia < 75) reprovados_frequencia++;
        else aprovados++;
    }

    printf("Media geral da turma: %.2lf\n", soma / 30.0);
    printf("Alunos aprovados: %d\n", aprovados);
    printf("Alunos reprovados por nota: %d\n", reprovados_nota);
    printf("Alunos reprovados por frequencia: %d\n", reprovados_frequencia);
    printf("Alunos reprovados por nota e frequencia: %d\n", reprovados_ambos);
    libera_lista(primeiro);

    return 0;
}
