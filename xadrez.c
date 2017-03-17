#include <stdlib.h>
#include <stdio.h>
#include <gconio.h>
#include <string.h>
int tabuleiro[8][8],temp_tab[8][8],i=10;
int id_tab[32][3];
int turn=0;
//id_tab[id][jogador]
//id_tab[id][linha]
//id_tab[id][coluna]
char l,c,l2,c2,opcoes[]={'a','b','c','d','f', 'e','g','h','A','B','C','D','E','F','G','H'};
void iniciatabuleiro();
void mostratabuleiro();
void pegajogada();
int verifica();
int troca(char t);
void jogada(int peca,int l1, int c1);
void peao(int jogador, int l1, int c1);
void turno();
void movimento(int error);
void torre(int jogador,int l1, int c1);
void bispo(int jogador,int l1, int c1);
void rei(int jogador,int l1, int c1);
void cavalo(int jogador,int l1, int c1);
void printtemptab();
int null_peca();
void relatorio(int line);
int peoes[2][8];
int erro=0;
main(){
int id,x,total,jogadas=0, ind1, ind2;
int fim=0;
	//allegro_init();
	//install_keyboard();
	//set_gfx_mode(GFX_SAFE, 640 , 480 , 0 , 0 ); /* força fullscreen */
	//textout(screen, font, "Ola Mundo!", 1, 1, makecol(255,0,0));
	//textout(screen, font, "Aperte ESC para sair!", 1, 24, makecol(255,0,0));
		textbackground(7);
		clrscr();
		iniciatabuleiro();
	/*for(id=0;id<32;id++){
		printf("%d[%d][%d][%d]\n",id,id_tab[id][0],id_tab[id][1],id_tab[id][2]);
		printf("\n");
	}*/
	do{
		do{
			mostratabuleiro();
				printf("O turn é %d",turn);
			pegajogada();
			x=verifica();
		}while(x==0);
	}while(fim==0);
getch();
}
//END_OF_MAIN()

int null_peca(){
	int linha, coluna, x=0;

	for(linha=0;linha<8;linha++){
		for(coluna=0;coluna<8;coluna++){
			if(temp_tab[linha][coluna]!=0){
				x++;
			}
		}
	}
	return x;
}
void turno(){
	turn++;
}
void peao(int jogador, int l1, int c1){
	int linha,coluna,id,indice,controle2=0,controle,y;
		for(y=0;y<8;y++){
			if((l1==1)&&(c1==y)&&(peoes[1][y]==0)){
				controle2=1;
				peoes[1][y]=1;
			}
		}
		for(y=0;y<8;y++){
			if((l1==6)&&(c1==y)&&(peoes[0][y]==0)){
				controle2=1;
				peoes[0][y]=1;
			}
		}

			if(jogador==0){
					linha=l1+1;
					id=2;
				}else{
					linha=l1-1;
					id=-2;
				}
			//diagonal direita
			coluna=c1+1;
			for(indice=0;indice<32;indice++){
				if((id_tab[indice][0]!=jogador)&&(id_tab[indice][1]==linha)&&(id_tab[indice][2]==coluna)){
					controle=1;
					break;
				}else{
					controle=0;
				}
			}
			if((tabuleiro[linha][coluna]!=0)&&(controle==1)&&((linha>=0)&&(coluna>=0)&&(linha<8)&&(coluna<8))){
				temp_tab[linha][coluna]=2;
			}
			//diagonal esquerda
			coluna=c1-1;
			for(indice=0;indice<32;indice++){
				if((id_tab[indice][0]!=jogador)&&(id_tab[indice][1]==linha)&&(id_tab[indice][2]==coluna)){
					controle=1;
					break;
				}else{
					controle=0;
				}
			}
			if((tabuleiro[linha][coluna]!=0)&&(controle==1)&&((linha>=0)&&(coluna>=0)&&(linha<8)&&(coluna<8))){
				temp_tab[linha][coluna]=2;
			}
			//frente
			coluna=c1;
			if((tabuleiro[linha][coluna]==0)&&((linha>=0)&&(coluna>=0)&&(linha<8)&&(coluna<8))){
				temp_tab[linha][coluna]=1;
			}
			linha=l1+id;
			if((tabuleiro[linha][coluna]==0)&&((linha>=0)&&(coluna>=0)&&(linha<8)&&(coluna<8))&&(controle2==1)){
				temp_tab[linha][coluna]=1;
			}
}
void cavalo(int jogador, int l1, int c1){
	int linha,coluna,controle,y=0;
	//primeiro L (FRENTE E DIREITA)
			coluna=c1+2;
			linha=l1+1;
			if((tabuleiro[linha][coluna]==0)&&((linha>=0)&&(coluna>=0)&&(linha<8)&&(coluna<8))){
				temp_tab[linha][coluna]=1;
			}
	//segundo L (FRENTE E ESQUERDA)
			coluna=c1-2;
			linha=l1+1;
			if((tabuleiro[linha][coluna]==0)&&((linha>=0)&&(coluna>=0)&&(linha<8)&&(coluna<8))){
				temp_tab[linha][coluna]=1;
			}
	//terceiro L (FRENTE E DIREITA)
			coluna=c1+2;
			linha=l1-1;
			if((tabuleiro[linha][coluna]==0)&&((linha>=0)&&(coluna>=0)&&(linha<8)&&(coluna<8))){
				temp_tab[linha][coluna]=1;
			}
	//quarto L (FRENTE E ESQUERDA)
			coluna=c1-2;
			linha=l1-1;
			if((tabuleiro[linha][coluna]==0)&&((linha>=0)&&(coluna>=0)&&(linha<8)&&(coluna<8))){
				temp_tab[linha][coluna]=1;
			}


//"INVERTENDO"
			//primeiro L (FRENTE E DIREITA)
			coluna=c1+1;
			linha=l1+2;
			if((tabuleiro[linha][coluna]==0)&&((linha>=0)&&(coluna>=0)&&(linha<8)&&(coluna<8))){
				temp_tab[linha][coluna]=1;
			}
	//segundo L (FRENTE E ESQUERDA)
			coluna=c1-1;
			linha=l1+2;
			if((tabuleiro[linha][coluna]==0)&&((linha>=0)&&(coluna>=0)&&(linha<8)&&(coluna<8))){
				temp_tab[linha][coluna]=1;
			}
	//terceiro L (FRENTE E DIREITA)
			coluna=c1+1;
			linha=l1-2;
			if((tabuleiro[linha][coluna]==0)&&((linha>=0)&&(coluna>=0)&&(linha<8)&&(coluna<8))){
				temp_tab[linha][coluna]=1;
			}
	//quarto L (FRENTE E ESQUERDA)
			coluna=c1-1;
			linha=l1-2;
			if((tabuleiro[linha][coluna]==0)&&((linha>=0)&&(coluna>=0)&&(linha<8)&&(coluna<8))){
				temp_tab[linha][coluna]=1;
			}


}
void rei(int jogador, int l1, int c1){
	int linha,coluna,controle,y=0,indice;
	//frente
			coluna=c1;
			linha=l1+1;
			if((tabuleiro[linha][coluna]==0)&&((linha>=0)&&(coluna>=0)&&(linha<8)&&(coluna<8))){
				temp_tab[linha][coluna]=1;
			}
	//trás
			coluna=c1;
			linha=l1-1;
			if((tabuleiro[linha][coluna]==0)&&((linha>=0)&&(coluna>=0)&&(linha<8)&&(coluna<8))){
				temp_tab[linha][coluna]=1;
			}
	//lado direito
			coluna=c1+1;
			linha=l1;
			if((tabuleiro[linha][coluna]==0)&&((linha>=0)&&(coluna>=0)&&(linha<8)&&(coluna<8))){
				temp_tab[linha][coluna]=1;
			}
	//lado esquerdo
			coluna=c1-1;
			linha=l1;
			if((tabuleiro[linha][coluna]==0)&&((linha>=0)&&(coluna>=0)&&(linha<8)&&(coluna<8))){
				temp_tab[linha][coluna]=1;
			}
	//diagonal direita superior
			coluna=c1+1;
			linha=l1-1;
			if(tabuleiro[linha][coluna]==0){
				controle=1;
			}else{
				controle=0;
			}
			for(indice=0;indice<32;indice++){
				if((id_tab[indice][1]==linha)&&(id_tab[indice][2]==coluna)&&(id_tab[indice][0]!=jogador)){
						controle=2;
				}
			}
			if((controle==1)&&((linha>=0)&&(coluna<8))){
				temp_tab[linha][coluna]=1;
			}else if((controle==2)&&(linha>=0)&&(coluna<8)){
				temp_tab[linha][coluna]=2;
			}else{
				temp_tab[linha][coluna]=0;
			}
	//diagonal esquerda superior
			coluna=c1-1;
			linha=l1-1;
			if(tabuleiro[linha][coluna]==0){
				controle=1;
			}else{
				controle=0;
			}
			for(indice=0;indice<32;indice++){
				if((id_tab[indice][1]==linha)&&(id_tab[indice][2]==coluna)&&(id_tab[indice][0]!=jogador)){
						controle=2;
				}
			}
			if((controle==1)&&((linha>=0)&&(coluna>=0))){
				temp_tab[linha][coluna]=1;
			}else if((controle==2)&&(linha>=0)&&(coluna>=0)){
				temp_tab[linha][coluna]=2;
			}else{
				temp_tab[linha][coluna]=0;
			}
	//diagonal direita inferior
			coluna=c1+1;
			linha=l1+1;
			if(tabuleiro[linha][coluna]==0){
				controle=1;
			}else{
				controle=0;
			}
			for(indice=0;indice<32;indice++){
				if((id_tab[indice][1]==linha)&&(id_tab[indice][2]==coluna)&&(id_tab[indice][0]!=jogador)){
						controle=2;
				}
			}
			if((controle==1)&&((linha<8)&&(coluna<8))){
				temp_tab[linha][coluna]=1;
			}else if((controle==2)&&(linha<8)&&(coluna<8)){
				temp_tab[linha][coluna]=2;
			}else{
				temp_tab[linha][coluna]=0;
			}
	//diagonal esquerda inferior
			coluna=c1-1;
			linha=l1+1;
			if(tabuleiro[linha][coluna]==0){
				controle=1;
			}else{
				controle=0;
			}
			for(indice=0;indice<32;indice++){
				if((id_tab[indice][1]==linha)&&(id_tab[indice][2]==coluna)&&(id_tab[indice][0]!=jogador)){
						controle=2;
				}
			}
			if((controle==1)&&((linha<8)&&(coluna>=0))){
				temp_tab[linha][coluna]=1;
			}else if((controle==2)&&(linha<8)&&(coluna>=0)){
				temp_tab[linha][coluna]=2;
			}else{
				temp_tab[linha][coluna]=0;
			}
}
void bispo(int jogador, int l1, int c1){
	int x=0,l3,c3,indice,linha,coluna,controle,mov=1,y=0;
	//diagonal direita superior
		do{
			coluna=c1+mov;
			linha=l1-mov;
			if(tabuleiro[linha][coluna]==0){
				controle=1;
				y=0;
			}else{
						controle=0;
						y=1;
			}
			for(indice=0;indice<32;indice++){
					if((id_tab[indice][1]==linha)&&(id_tab[indice][2]==coluna)&&(id_tab[indice][0]!=jogador)){
						controle=2;
						break;
					}
			}
			if((controle==1)&&(linha>=0)&&(coluna<8)){
				temp_tab[linha][coluna]=1;
			}else if((controle==2)&&(linha>=0)&&(coluna<8)){
				temp_tab[linha][coluna]=2;
			}else{
				temp_tab[linha][coluna]=0;
			}
			mov++;
		}while(((coluna<8)||(linha>=0))&&(y==0));
	//diagonal esquerda superior
		mov=1;
		do{
			coluna=c1-mov;
			linha=l1-mov;
			if(tabuleiro[linha][coluna]==0){
				controle=1;
				y=0;
			}else{
				controle=0;
				y=1;
			}
			for(indice=0;indice<32;indice++){
				if((id_tab[indice][1]==linha)&&(id_tab[indice][2]==coluna)&&(id_tab[indice][0]!=jogador)){
						controle=2;
						break;
				}
			}
			if((controle==1)&&(linha>=0)&&(coluna>=0)){
				temp_tab[linha][coluna]=1;
			}else if((controle==2)&&(linha>=0)&&(coluna>=0)){
				temp_tab[linha][coluna]=2;
			}else{
				temp_tab[linha][coluna]=0;
			}
			mov++;
		}while(((coluna>=0)||(linha>=0))&&(y==0));
	//diagonal direita inferior
		mov=1;
		do{
			coluna=c1+mov;
			linha=l1+mov;
			if(tabuleiro[linha][coluna]==0){
				controle=1;
				y=0;
			}else{
				controle=0;
				y=1;
			}
			for(indice=0;indice<32;indice++){
				if((id_tab[indice][1]==linha)&&(id_tab[indice][2]==coluna)&&(id_tab[indice][0]!=jogador)){
						controle=2;
						break;
				}
			}
			if((controle==1)&&(linha<8)&&(coluna<8)){
				temp_tab[linha][coluna]=1;
			}else if((controle==2)&&(linha<8)&&(coluna<8)){
				temp_tab[linha][coluna]=2;
			}else{
				temp_tab[linha][coluna]=0;
			}
				mov++;
		}while(((coluna<8)||(linha<8))&&(y==0));
	//diagonal esquerda inferior
		mov=1;
		do{
			coluna=c1-mov;
			linha=l1+mov;
			if(tabuleiro[linha][coluna]==0){
				controle=1;
				y=0;
			}else{
				y=1;
			}
			for(indice=0;indice<32;indice++){
				if((id_tab[indice][1]==linha)&&(id_tab[indice][2]==coluna)&&(id_tab[indice][0]!=jogador)){
						controle=2;
						break;
				}
			}
			if((controle==1)&&(linha<8)&&(coluna>=0)){
				temp_tab[linha][coluna]=1;
			}else if((controle==2)&&(linha<8)&&(coluna>=0)){
				temp_tab[linha][coluna]=2;
			}else{
				temp_tab[linha][coluna]=0;
			}
			mov++;
		}while(((coluna>=0)||(linha<8))&&(y==0));

}
void torre(int jogador, int l1, int c1){
	int x=0,l3,c3,indice,linha,coluna,controle;
	linha=l1+1;
	for(x=linha;x<8;x++){
		if(tabuleiro[x][c1]==0){
			temp_tab[x][c1]=1;
		}else{
			controle=1;
			for(indice=0;indice<32;indice++){
				if((id_tab[indice][0]!=jogador)&&((id_tab[indice][1]==x)&&(id_tab[indice][2]==c1))){
					temp_tab[x][c1]=2;
					break;
				}
			}
		break;
		}
	}
	linha=l1-1;
	for(x=linha;x>=0;x--){
		if(tabuleiro[x][c1]==0){
			temp_tab[x][c1]=1;
		}else{
			controle=2;
			for(indice=0;indice<32;indice++){
				if((id_tab[indice][0]!=jogador)&&((id_tab[indice][1]==x)&&(id_tab[indice][2]==c1))){
					temp_tab[x][c1]=2;
					break;
				}
			}
		break;
		}
	}
	coluna=c1+1;
	for(x=coluna;x<8;x++){
		if(tabuleiro[l1][x]==0){
			temp_tab[l1][x]=1;
		}else{
			controle=3;
			for(indice=0;indice<32;indice++){
				if((id_tab[indice][0]!=jogador)&&((id_tab[indice][1]==l1)&&(id_tab[indice][2]==x))){
					temp_tab[l1][x]=2;
					break;
				}
			}
		break;
		}
	}
	coluna=c1-1;
	for(x=coluna;x>=0;x--){
		if(tabuleiro[l1][x]==0){
			temp_tab[l1][x]=1;
		}else{
			controle=4;
			for(indice=0;indice<32;indice++){
				if((id_tab[indice][0]!=jogador)&&((id_tab[indice][1]==l1)&&(id_tab[indice][2]==x))){
					temp_tab[l1][x]=2;
					break;
				}
			}
		break;
		}
	}
}
int troca(char t){
	int x;
	switch(t){
		case 'A': x=0;
		break;
		case 'a': x=0;
		break;
		case 'B': x=1;
		break;
		case 'b': x=1;
		break;
		case 'C': x=2;
		break;
		case 'c': x=2;
		break;
		case 'D': x=3;
		break;
		case 'd': x=3;
		break;
		case 'E': x=4;
		break;
		case 'e': x=4;
		break;
		case 'F': x=5;
		break;
		case 'f': x=5;
		break;
		case 'G': x=6;
		break;
		case 'g': x=6;
		break;
		case 'H': x=7;
		break;
		case 'h': x=7;
		break;
	}
	return x;

}
void movimento(int error){
	int x;
	if(error==1){
		textcolor(12);
		printf("\nMovimento Inválido");
		textcolor(5);
	}
	printf("\nDigite para onde desejar mover a peça:\n\n");
	do{
		printf("Linha: ");
		scanf("%s",&l2);
		x=15;
		while(x>=0){
			if(l2==opcoes[x]){
				i=1;
			}
			x--;
		}
	}while(i==0);
	i=0;
	do{
		printf("Coluna: ");
		scanf("%s",&c2);
		x=15;
		while(x>=0){
			if(c2==opcoes[x]){
				i=1;
			}
			x--;
		}
	}while(i==0);
}
void jogada(int peca,int l1,int c1){
	int linha,coluna,x,l3,c3,indice,jogador,y;
	for(linha=0;linha<8;linha++){
		for(coluna=0;coluna<8;coluna++){
			temp_tab[linha][coluna]=0;
		}
	}
	if(turn%2==0){
		jogador=0;
	}else{
		jogador=1;
	}

	switch(peca){
		case 6:
			peao(jogador,l1,c1);
			break;
		case 4:
			torre(jogador,l1,c1);
			break;
		case 5:
			bispo(jogador,l1,c1);
			break;
		case 1:
			rei(jogador,l1,c1);
			break;
		case 3:
			cavalo(jogador,l1,c1);
			break;
	}
	x=null_peca();
	if(x!=0){
		y=0;
		do{
			printtemptab();
			movimento(erro);
			erro=0;
			l3=troca(l2);
			c3=troca(c2);

			if(temp_tab[l3][c3]==1){
				tabuleiro[l1][c1]=0;
				tabuleiro[l3][c3]=peca;
				for(indice=0;indice<32;indice++){
					if((id_tab[indice][0]==jogador)&&(id_tab[indice][1]==l1)&&(id_tab[indice][2]==c1)){
						id_tab[indice][1]=l3;
						id_tab[indice][2]=c3;
						break;
					}else{
						printf("\nerro 1\n");
					}
					y=1;
				}
			}else if(temp_tab[l3][c3]==2){
				tabuleiro[l1][c1]=0;
				tabuleiro[l3][c3]=peca;
				for(indice=0;indice<32;indice++){
					if((id_tab[indice][0]!=jogador)&&(id_tab[indice][1]==l3)&&(id_tab[indice][2]==c3)){
						id_tab[indice][1]=-1;
						id_tab[indice][2]=-1;
						break;
					}else{
						printf("\nerro 2 \n");
					}
				}
				for(indice=0;indice<32;indice++){
					if((id_tab[indice][0]==jogador)&&(id_tab[indice][1]==l1)&&(id_tab[indice][2]==c1)){
						id_tab[indice][1]=l3;
						id_tab[indice][2]=c3;
						break;
					}else{
						printf("\nerro 3\n");
					}
					y=1;
				}
			}else{
				erro++;
			}
		}while(y==0);
		turno();
	}else{
		textcolor(12);
		printf("A peça não pode ser movida para lugar nenhum, tente outra peça.");
		textcolor(0);
		pegajogada();
	}
}
int verifica(){
	int x,coluna,linha,id,l1,c1,peca,aux,jogador;

	l1=troca(l);
	c1=troca(c);
	if(turn%2==0){
		jogador=0;
	}else{
		jogador=1;
	}
	for(id=0;id<32;id++){
		if(((id_tab[id][1]==l1)&&(id_tab[id][2]==c1)&&(id_tab[id][0]==jogador))){
			aux=0;
			peca=tabuleiro[l1][c1];
			jogada(peca,l1,c1);
			break;
		}else if((id_tab[id][0]!=jogador)&&((id_tab[id][1]==l1)&&(id_tab[id][2]==c1))){
			aux=1;
			break;
		}else{
			aux=2;
		}

	}
		switch(aux){
			case 0:
				printf("\n");
				x=0;
				break;
			case 1:
				textcolor(12);
				 printf("Você não pode mover essa peça, ela é do oponente. Tente novamente!!!\n");
				 x=0;
				 textcolor(0);
				 pegajogada();
				 break;
			case 2:
				textcolor(12);
				printf("Não existe uma peça na localização (%c,%c). Tente novamente!!!\n",l,c);
				textcolor(0);
				x=0;
				pegajogada();
				break;
		}
return x;
}
void printtemptab(){
	int linha, coluna,id;
	char jogador;
	clrscr();
	textcolor(5);
	printf("\tA \tB \tC \tD \tE \tF \tG \tH\t");
	printf("\n");

	for(linha=0;linha<8;linha++){
		switch(linha){
			case  0:
					textcolor(5);
					printf("A\t");
					for(id=0;id<8;id++){
						if(id_tab[id][0]==0){
							jogador='X';
						}else if(id_tab[id][0]==1){
							jogador='Y';
						}else{
							jogador=' ';
						}
					}
					textcolor(1);
					 break;
			case  1: textcolor(5);
					printf("B\t");
					for(id=8;id<16;id++){
						if(id_tab[id][0]==0){
							jogador='X';
						}else if(id_tab[id][0]==1){
							jogador='Y';
						}else{
							jogador=' ';
						}
					}
					textcolor(1);
					 break;
			case  2:
					textcolor(5);
					 printf("C\t");
					 jogador=' ';
					textcolor(2);
					 break;
			case  3:
					textcolor(5);
					 printf("D\t");
					 jogador=' ';
					 textcolor(2);
					 break;
			case  4:
					textcolor(5);
					printf("E\t");
					jogador=' ';
					textcolor(2);
					 break;
			case  5:
					textcolor(5);
					printf("F\t");
					jogador=' ';
					textcolor(2);
					 break;
			case  6: textcolor(5);
					printf("G\t");
					for(id=16;id<24;id++){
						if(id_tab[id][0]==0){
							jogador='X';
						}else if(id_tab[id][0]==1){
							jogador='Y';
						}else{
							jogador=' ';
						}
					}
					textcolor(0);

					 break;
			case  7: textcolor(5);
					printf("H\t");
					for(id=24;id<32;id++){
						if(id_tab[id][0]==0){
							jogador='X';
						}else if(id_tab[id][0]==1){
							jogador='Y';
						}else{
							jogador=' ';
						}
					}
					textcolor(0);
					 break;
		}
		for(coluna=0;coluna<8;coluna++){
			printf("%d\t",temp_tab[linha][coluna]);
		}
	            printf("\n");
	}
}
void pegajogada(){
	int x,i=0,jogador;
	if(turn%2==0){
	printf("\nSua vez jogador branco! Digite a localização da peça que você deseja mover\n\n");
	}else{
	printf("\nSua vez jogador preto! Digite a localização da peça que você deseja mover\n\n");
	}
	do{
		printf("Linha: ");
		scanf("%s",&l);
		x=15;
		while(x>=0){
			if(l==opcoes[x]){
				i=1;
			}
			x--;
		}
	}while(i==0);
	i=0;
	do{
		printf("Coluna: ");
		scanf("%s",&c);
		x=15;
		while(x>=0){
			if(c==opcoes[x]){
				i=1;
			}
			x--;
		}
	}while(i==0);



}

void iniciatabuleiro(){
	int i,i2,id=0,linha,coluna,jogador,y;
		for(id=0;id<32;id++){

			if(id<8){
				id_tab[id][1]=0;
			}else if(id<16){
				id_tab[id][1]=1;
			}else if(id<24){
				id_tab[id][1]=6;
			}else if(id<32){
				id_tab[id][1]=7;
			}
			if(id_tab[id][1]==0){
				id_tab[id][2]=id;
			}else if(id_tab[id][1]==1){
				id_tab[id][2]=id-8;
			}else if(id_tab[id][1]==6){
				id_tab[id][2]=id-16;
			}else if(id_tab[id][1]==7){
				id_tab[id][2]=id-24;
			}

			if(id<16){
				id_tab[id][0]=0;
			}else if((id>15)&&(id<32)){
				id_tab[id][0]=1;
			}
		}
	for(i2=0;i2<8;i2++){
		tabuleiro[1][i2]=6; //peões preto
		peoes[1][i2]=0;
	}
	for(i2=0;i2<8;i2++){
		tabuleiro[6][i2]=6; //peões branco2;
		peoes[0][i2]=0;
	}
	tabuleiro[0][0]=4;//torre preta
	tabuleiro[0][1]=3;//cavalo preto
	tabuleiro[0][2]=5;//bispo preto
	tabuleiro[0][3]=1;//rei preto
	tabuleiro[0][4]=2;//rainha preta
	tabuleiro[0][5]=5;//bispo preto
	tabuleiro[0][6]=3;//cavalo preto
	tabuleiro[0][7]=4; //torre preta

	tabuleiro[7][0]=4;//torre preta
	tabuleiro[7][1]=3;//cavalo preto
	tabuleiro[7][2]=5;//bispo preto
	tabuleiro[7][3]=1;//rei preto
	tabuleiro[7][4]=2;//rainha preta
	tabuleiro[7][5]=5;//bispo preto
	tabuleiro[7][6]=3;//cavalo preto
	tabuleiro[7][7]=4; //torre preta

	for(i=2;i<6;i++){
		for(i2=0;i2<8;i2++){
			tabuleiro[i][i2]=0;

		}
	}

}

void relatorio(int line){
	int coluna;
	textcolor(5);
	if(line!=7);{
		printf(" \t\t");
	}
	for(coluna=0;coluna<8;coluna++){
		if(tabuleiro[line][coluna]==0){
			printf("|");
			printf("---");
		}else{
			printf("|");
			textbackground(0);
			printf("+++");
			textbackground(7);
		}
	}
}
void relatorio2(int line){
	int linha,coluna,indice,vazio=0;
	int reis[2],dama[2],peaoo[2]={0,0},bispos[2]={0,0},torres[2]={0,0},cavalos[2]={0,0};

	for(linha=0;linha<8;linha++){
		for(coluna=0;coluna<8;coluna++){
			switch(tabuleiro[linha][coluna]){
				case 1:
					for(indice=0;indice<32;indice++){
						if((id_tab[indice][0]==0)&&(id_tab[indice][1]==linha)&&(id_tab[indice][2]==coluna)){
							reis[0]=1;
						}else if((id_tab[indice][0]==1)&&(id_tab[indice][1]==linha)&&(id_tab[indice][2]==coluna)){
							reis[1]=1;
						}
					}
					break;
				case 2:
					for(indice=0;indice<32;indice++){
						if((id_tab[indice][0]==0)&&(id_tab[indice][1]==linha)&&(id_tab[indice][2]==coluna)){
							dama[0]=1;
						}else if((id_tab[indice][0]==1)&&(id_tab[indice][1]==linha)&&(id_tab[indice][2]==coluna)){
							dama[1]=1;
						}
					}
				break;
				case 3:
					for(indice=0;indice<32;indice++){
						if((id_tab[indice][0]==0)&&(id_tab[indice][1]==linha)&&(id_tab[indice][2]==coluna)){
							cavalos[0]+=1;
						}else if((id_tab[indice][0]==1)&&(id_tab[indice][1]==linha)&&(id_tab[indice][2]==coluna)){
							cavalos[1]+=1;
						}
					}
				break;
				case 4:
					for(indice=0;indice<32;indice++){
						if((id_tab[indice][0]==0)&&(id_tab[indice][1]==linha)&&(id_tab[indice][2]==coluna)){
							torres[0]+=1;
						}else if((id_tab[indice][0]==1)&&(id_tab[indice][1]==linha)&&(id_tab[indice][2]==coluna)){
							torres[1]+=1;
						}
					}
				break;
				case 5:
					for(indice=0;indice<32;indice++){
						if((id_tab[indice][0]==0)&&(id_tab[indice][1]==linha)&&(id_tab[indice][2]==coluna)){
							bispos[0]++;
						}else if((id_tab[indice][0]==1)&&(id_tab[indice][1]==linha)&&(id_tab[indice][2]==coluna)){
							bispos[1]++;
						}
					}
				break;
				case 6:
					for(indice=0;indice<32;indice++){
						if((id_tab[indice][0]==0)&&(id_tab[indice][1]==linha)&&(id_tab[indice][2]==coluna)){
							peaoo[0]+=1;
						}else if((id_tab[indice][0]==1)&&(id_tab[indice][1]==linha)&&(id_tab[indice][2]==coluna)){
							peaoo[1]+=1;
						}
					}
				break;
			}
		}
	}
	switch(line){
		case 0:
			printf("\t Jogador 1: ");
			textcolor(12);
			printf("Rei: %d | Dama: %d | Peões: %d |",reis[0],dama[0],peaoo[0]);
			textcolor(5);
		break;
		case 1:
			textcolor(12);
			printf("\t\t    Bispos: %d | Torres: %d | Cavalos: %d",bispos[0],torres[0],cavalos[0]);
			textcolor(5);
		break;
		case 2:
			printf("\t Jogador 2: ");
			textcolor(9);
			printf("Rei: %d | Dama: %d | Peões: %d |",reis[1],dama[1],peaoo[1]);
			textcolor(5);
		break;
		case 3:
			textcolor(9);
			printf("\t\t    Bispos: %d | Torres: %d | Cavalos: %d",bispos[1],torres[1],cavalos[1]);
			textcolor(5);
		break;
		case 4:
			textcolor(0);
			for(linha=0;linha<8;linha++){
				for(coluna=0;coluna<8;coluna++){
					if(tabuleiro[linha][coluna]==0){
						vazio++;
					}
				}
			}
			printf("\tHá %d lugares vazios no tabuleiro.",vazio);
			textcolor(5);
		break;
	}

}

void mostratabuleiro(){
	int linha, coluna,id,x,indice,ct;
	char jogador;
	clrscr();
	textcolor(5);
	printf("       A    B   C   D   E   F   G   H\t\t\tRelatório de Jogadas:");
	printf("\n");

	for(x=1;x<=64;x++){
		if(x==1){
			textcolor(5);
			printf("A    |");
		}else if(x==9){
			textcolor(5);
			relatorio(0);
			relatorio2(0);
			printf("|\nB    |");
		}else if(x==17){
			textcolor(5);
			relatorio(1);
			relatorio2(1);
			printf("|\nC    |");
		}else if(x==25){
			textcolor(5);
			relatorio(2);
			relatorio2(2);
			printf("|\nD    |");
		}else if(x==33){
			textcolor(5);
			relatorio(3);
			relatorio2(3);
			printf("|\nE    |");
		}else if(x==41){
			textcolor(5);
			relatorio(4);
			relatorio2(4);
			printf("|\nF    |");
		}else if(x==49){
			textcolor(5);
			relatorio(5);
			printf("|\nG    |");
		}else if(x==57){
			textcolor(5);
			relatorio(6);
			printf("|\nH    |");
		}

		if(x<=8){
			ct=0;
			id=x-1;
				if(x%2==0){
						textbackground(0);
				}else{
						textbackground(14);
				}
			for(indice=0;indice<32;indice++){
				if((id_tab[indice][0]==0)&&(id_tab[indice][1]==0)&&(id_tab[indice][2]==id)){
					textcolor(12);
					printf(" %dx ",tabuleiro[0][id]);
					ct=1;
				}else if((id_tab[indice][0]==1)&&(id_tab[indice][1]==0)&&(id_tab[indice][2]==id)){
					textcolor(9);
					printf(" %dy ",tabuleiro[0][id]);
					ct=1;
				}
			}
			if(ct==0){
				textcolor(2);
				printf(" %d  ",tabuleiro[0][id]);
			}
			textbackground(7);
		}else if(x<=16){
			ct=0;
			id=x-9;
			if(x%2==0){
						textbackground(14);
				}else{
						textbackground(0);
				}
			ct=0;
			for(indice=0;indice<32;indice++){
				if((id_tab[indice][0]==0)&&(id_tab[indice][1]==1)&&(id_tab[indice][2]==id)){
					textcolor(12);
					printf(" %dx ",tabuleiro[1][id]);
					ct=1;
				}else if((id_tab[indice][0]==1)&&(id_tab[indice][1]==1)&&(id_tab[indice][2]==id)){
					textcolor(9);
					printf(" %dy ",tabuleiro[1][id]);
					ct=1;
				}
			}
			if(ct==0){
				textcolor(2);
				printf(" %d  ",tabuleiro[1][id]);
			}
			textbackground(7);
		}else if(x<=24){
			ct=0;
			id=x-17;
			if(x%2==0){
				textbackground(0);
			}else{
				textbackground(14);
			}
			ct=0;
			for(indice=0;indice<32;indice++){
				if((id_tab[indice][0]==0)&&(id_tab[indice][1]==2)&&(id_tab[indice][2]==id)){
					textcolor(12);
					printf(" %dx ",tabuleiro[2][id]);
					ct=1;
				}else if((id_tab[indice][0]==1)&&(id_tab[indice][1]==2)&&(id_tab[indice][2]==id)){
					textcolor(9);
					printf(" %dy ",tabuleiro[2][id]);
					ct=1;
				}
			}
			if(ct==0){
				textcolor(2);
				printf(" %d  ",tabuleiro[2][id]);
			}
			textbackground(7);
		}else if(x<=32){
			ct=0;
			id=x-25;
			if(x%2==0){
				textbackground(14);
			}else{
				textbackground(0);
			}			for(indice=0;indice<32;indice++){
				if((id_tab[indice][0]==0)&&(id_tab[indice][1]==3)&&(id_tab[indice][2]==id)){
					textcolor(12);
					printf(" %dx ",tabuleiro[3][id]);
					ct=1;
				}else if((id_tab[indice][0]==1)&&(id_tab[indice][1]==3)&&(id_tab[indice][2]==id)){
					textcolor(9);
					printf(" %dy ",tabuleiro[3][id]);
					ct=1;
				}else{
				}
			}
			if(ct==0){
				textcolor(2);
				printf(" %d  ",tabuleiro[3][id]);
			}
			textbackground(7);
		}else if(x<=40){
			ct=0;
			id=x-33;
			if(x%2==0){
				textbackground(0);
			}else{
				textbackground(14);
			}
			for(indice=0;indice<32;indice++){
				if((id_tab[indice][0]==0)&&(id_tab[indice][1]==4)&&(id_tab[indice][2]==id)){
					textcolor(12);
					printf(" %dx ",tabuleiro[4][id]);
					ct=1;
				}else if((id_tab[indice][0]==1)&&(id_tab[indice][1]==4)&&(id_tab[indice][2]==id)){
					textcolor(9);
					printf(" %dy ",tabuleiro[4][id]);
					ct=1;
				}else{
				}
			}
			if(ct==0){
				textcolor(2);
				printf(" %d  ",tabuleiro[4][id]);
			}
			textbackground(7);
		}else if(x<=48){
			ct=0;
			id=x-41;
			if(x%2==0){
				textbackground(14);
			}else{
				textbackground(0);
			}
			for(indice=0;indice<32;indice++){
				if((id_tab[indice][0]==0)&&(id_tab[indice][1]==5)&&(id_tab[indice][2]==id)){
					textcolor(12);
					printf(" %dx ",tabuleiro[5][id]);
					ct=1;
				}else if((id_tab[indice][0]==1)&&(id_tab[indice][1]==5)&&(id_tab[indice][2]==id)){
					textcolor(9);
					printf(" %dy ",tabuleiro[5][id]);
					ct=1;
				}else{
				}
			}
			if(ct==0){
				textcolor(2);
				printf(" %d  ",tabuleiro[5][id]);
			}
			textbackground(7);
		}else if(x<=56){
			ct=0;
			id=x-49;
			if(x%2==0){
				textbackground(0);
			}else{
				textbackground(14);
			}
			for(indice=0;indice<32;indice++){
				if((id_tab[indice][0]==0)&&(id_tab[indice][1]==6)&&(id_tab[indice][2]==id)){
					textcolor(12);
					printf(" %dx ",tabuleiro[6][id]);
					ct=1;
				}else if((id_tab[indice][0]==1)&&(id_tab[indice][1]==6)&&(id_tab[indice][2]==id)){
					textcolor(9);
					printf(" %dy ",tabuleiro[6][id]);
					ct=1;
				}else{
				}
			}
			if(ct==0){
				textcolor(2);
				printf(" %d  ",tabuleiro[6][id]);
			}
			textbackground(7);
		}else if(x<=64){
			ct=0;
			id=x-57;
			if(x%2==0){
				textbackground(14);
			}else{
				textbackground(0);
			}
			for(indice=0;indice<32;indice++){
				if((id_tab[indice][0]==0)&&(id_tab[indice][1]==7)&&(id_tab[indice][2]==id)){
					textcolor(12);
					printf(" %dx ",tabuleiro[7][id]);
					ct=1;
				}else if((id_tab[indice][0]==1)&&(id_tab[indice][1]==7)&&(id_tab[indice][2]==id)){
					textcolor(9);
					printf(" %dy ",tabuleiro[7][id]);
					ct=1;
				}else{
				}
			}
			if(ct==0){
				textcolor(2);
				printf(" %d  ",tabuleiro[7][id]);
			}
			textbackground(7);
		}
	}
	relatorio(7);
	printf("|");
	printf("\n\n");
	textcolor(0);
}
