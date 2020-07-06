/*
Função: Jogo da velha
Autor: Marcos Fajoli
Autor: Victor Nathan
Data de Criação: 23/10/2019
Data de Modificação: 10/11/2019
*/

#include <stdio.h>
#include <windows.h>
#include <locale.h>

char jogo[3][3], nome1[40], nome2[40], m1 = ' ', m2 = ' ', marcador = ' ';
int pri = 0, col = 0, lin = 0, ptJ1 = 0, ptJ2 = 0, resto = 0, troca = 0, velha = 0, partida = 1, jogao = 1, ganhador = 0;
bool vencedor = false;

void trocarMarcadorJ1() {
	troca = 0;
	printf("Deseja trocar o marcador? (Digite \"1\" para sim e \"0\" para não): \n");
	scanf("%i", &troca);
	if(troca == 1){
		printf("O marcador foi trocado! \n\n");
		if(m1 == 'X'){
			m1 = 'O';
			m2 = 'X';
		}
		else{
			m1 = 'X';
			m2 = 'O';
		}
	}
}

void trocarMarcadorJ2() {
	troca = 0;
	printf("Deseja trocar o marcador? (Digite \"1\" para sim e \"0\" para não): \n");
	scanf("%i", &troca);
	if(troca == 1){
		printf("O marcador foi trocado! \n\n");
		if(m2 == 'X'){
			m2 = 'O';
			m1 = 'X';
		}
		else{
			m2 = 'X';
			m1 = 'O';
		}
	}
}

void ver1() {
	if((jogo[0][0] == m1 and jogo[0][1] == m1 and jogo[0][2] == m1) or (jogo[1][0] == m1 and jogo[1][1] == m1 and jogo[1][2] == m1) or (jogo[2][0] == m1 and jogo[2][1] == m1 and jogo[2][2] == m1) or (jogo[0][0] == m1 and jogo[1][0] == m1 and jogo[2][0] == m1) or (jogo[0][1] == m1 and jogo[1][1] == m1 and jogo[2][1] == m1) or (jogo[0][2] == m1 and jogo[1][2] == m1 and jogo[2][2] == m1) or (jogo[0][0] == m1 and jogo[1][1] == m1 and jogo[2][2] == m1) or (jogo[0][2] == m1 and jogo[1][1] == m1 and jogo[2][0] == m1)){
		ptJ1 += 1;
		printf("O jogador 1 venceu a partida! \n");
		vencedor = true;
		pri = 1;
		ganhador = 1;
	}
}

void ver2() {
	if((jogo[0][0] == m2 and jogo[0][1] == m2 and jogo[0][2] == m2) or (jogo[1][0] == m2 and jogo[1][1] == m2 and jogo[1][2] == m2) or (jogo[2][0] == m2 and jogo[2][1] == m2 and jogo[2][2] == m2) or (jogo[0][0] == m2 and jogo[1][0] == m2 and jogo[2][0] == m2) or (jogo[0][1] == m2 and jogo[1][1] == m2 and jogo[2][1] == m2) or (jogo[0][2] == m2 and jogo[1][2] == m2 and jogo[2][2] == m2) or (jogo[0][0] == m2 and jogo[1][1] == m2 and jogo[2][2] == m2) or (jogo[0][2] == m2 and jogo[1][1] == m2 and jogo[2][0] == m2)){
		ptJ2 += 1;
		printf("O jogador 2 venceu a partida! \n");
		vencedor = true;
		pri = 2;
		ganhador = 2;
	}
}

void tab() {
	printf("\n       |       |       \n");
	printf("   %c   |   %c   |   %c   \n", jogo[0][0], jogo[0][1], jogo[0][2]);
	printf("       |       |       \n");
	printf("-------+-------+-------\n");
	printf("       |       |       \n");
	printf("   %c   |   %c   |   %c   \n", jogo[1][0], jogo[1][1], jogo[1][2]);
	printf("       |       |       \n");
	printf("-------+-------+-------\n");
	printf("       |       |       \n");
	printf("   %c   |   %c   |   %c   \n", jogo[2][0], jogo[2][1], jogo[2][2]);
	printf("       |       |       \n");
}

void pedirNome() {
	fflush(stdin);
	printf("Insira o nome do jogador 1: ");
	gets(nome1);
	printf("Insira o nome do jogador 2: ");
	gets(nome2);
	printf("Qual jogador será o primeiro? (\"1\" ou \"2\"): ");
	scanf("%i", &pri);
	while(pri != 1 and pri != 2){
		printf("Informe um jogador válido (\"1\" ou \"2\"): ");
		scanf("%i", &pri);
	}
	printf("Jogador 1 informe o marcador (\"X\" ou \"O\"): ");
	scanf("%s", &m1);
	while(m1 != 'X' and m1 != 'O' and m1 != 'x' and m1 != 'o'){
		printf("Jogador 1 informe um marcador válido (\"X\" ou \"O\"): ");
		scanf("%s", &m1);
	}
	
	if(m1 == 'x'){
		m1 = 'X';
	}else if(m1 == 'o'){
		m1 = 'O';
	}
	
	if(m1 == 'X'){
		m2 = 'O';
	}
	else{
		m2 = 'X';
	}
}

void jogasso() {
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			jogo[i][j]= ' ';
		}
	}

	tab();
	
	vencedor = false;
	
	for(int rodada = 0; rodada < 9; rodada++){
		resto = rodada % 2;

		if(pri == 1 and resto == 0 or pri == 2 and resto == 1){
			marcador = m1;
			printf("\nSua vez jogador %s \n\n", nome1);
		}
		else{
			marcador = m2;
			printf("\nSua vez jogador %s \n\n", nome2);
		}

		printf("Informe a linha: ");
		scanf("%i", &lin);
		while(lin > 3 or lin < 1){
			printf("Informe uma linha válida: ");
			scanf("%i", &lin);
		}
		printf("Informe a coluna: ");
		scanf("%i", &col);
		while(col > 3 or col < 1){
			printf("Informe uma coluna válida: ");
			scanf("%i", &col);
		}
		
		while(jogo[lin-1][col-1] != ' '){
			printf("Posição já utilizada! \n");
			printf("Informe a linha: ");
			scanf("%i", &lin);
			while(lin > 3 or lin < 1){
				printf("Informe uma linha válida: ");
				scanf("%i", &lin);
			}
			printf("Informe a coluna jogador: ");
			scanf("%i", &col);
			while(col > 3 or col < 1){
				printf("Informe uma coluna válida: ");
				scanf("%i", &col);
			}
			if(jogo[lin-1][col-1] == ' '){
				jogo[lin-1][col-1] = marcador;
				break;
			}
		
		}
		
		if(jogo[lin-1][col-1] == ' '){
			jogo[lin-1][col-1] = marcador;
		}
		
		tab();
		
		ver1();
		if(vencedor == true){
			break;
		}
	
		ver2();	
		if(vencedor == true){
			break;
			
		}else if(rodada == 8){
			printf("Deu Velha! \n");
			velha += 1 ;
			printf("O total de empates é %i \n\n", velha);
		}
	}
}

void placar () {
	setlocale(LC_ALL, "");
	printf("\n********** PLACAR ********** \n");
	printf("%s (%i) X (%i) %s \n", nome1, ptJ1, ptJ2, nome2);
	printf("**************************** \n\n");
}

int main () {
	setlocale(LC_ALL, "");
	while(jogao != 0){
		ptJ1 = 0;
		ptJ2 = 0;
		pedirNome();
		partida = 1;
		while(partida != 0){
			
			jogasso();
			
			placar();
			
			printf("Deseja iniciar uma nova partida (se sim digite \"1\"): \n");
			scanf("%i", &partida);
			
			if(partida != 0 and vencedor == true and ganhador == 1){
				trocarMarcadorJ1();
			}else if (partida != 0 and vencedor == true and ganhador == 2){
				trocarMarcadorJ2();
			}
		}
		if(ptJ1 > ptJ2){
			printf("****************************************\n");
			printf("O jogador %s venceu o jogo \n", nome1);
			printf("****************************************\n\n");
		}else if(ptJ2 > ptJ1){
			printf("****************************************\n");
			printf("O jogador %s venceu o jogo \n", nome2);	
			printf("****************************************\n\n");
		}else{
			printf("********************\n");
			printf("* Houve um empate! *\n");
			printf("********************\n\n");
		}
		printf("Deseja iniciar um novo jogo (se sim digite \"1\"): \n");
		scanf("%i", &jogao);
	}
}

