#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <locale.h>
#include <ctype.h>
#include <time.h>
#define max 700
#define baixo 80
#define cima 72
#define esquerda 75
#define direita 77
#define esc 27
#define enter 13

void gotoxy (int x, int y) {
  COORD pos = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int SetColor (char color) {
  HANDLE h;
  h = GetStdHandle (STD_OUTPUT_HANDLE);
  return SetConsoleTextAttribute (h,color);
}

void borda(){                    //criação da borda do jogo
	int i,j;
	SetColor(2);
	for(i=0;i<41;i++)
		for(j=6;j<22;j++)
			if(i==0||j==6||i==40||j==21){
				gotoxy(i,j);
				printf("#");
			}
	SetColor(7);
}

void escreve(int x,int y, char texto[]){
	gotoxy(x,y);
	printf("%s",texto);
}

int repete(){
	int t;
	escreve(10,3,"Deseja jogar denovo?");
	escreve(13,4,"(S-Sim   N-Não)");
volta:
	t = getch();
	if(toupper(t)=='S')
		return 1;
	else if (toupper(t)=='N')
		return 0;
	else{
		escreve(11,5,"Resposta inválida!");
		goto volta;
	}	
}

int bateu(int x, int y, int mx[], int my[],int l){		//verifica se algo bate na cobrinha
	int i;
	for(i=0;i<=l;i++)
		if(mx[i]==x && my[i]==y){
			return 1;			
		}
	return 0;
}

void fruta(int mx[],int my[],int l, int *xf, int *yf){			//geração das frutas pelo mapa
	srand(time(NULL));
	do{
		*xf = rand()%38+1;
		*yf = rand()%14+7;
	}while(bateu(*xf,*yf,mx,my,l)==1);				//repete se a fruta for gerada em um espaço ocupado pela cobrinha
	fflush(stdin);
	SetColor(4);
	escreve(*xf,*yf,"@");
	SetColor(6);
}

void menu(){
	escreve(0,0,"  _____ ____  ____  _____  _____ _   _ _    _          ");
	escreve(0,1," / ____/ __ \\|  _ \\|  __ \\|_   _| \\ | | |  | |   /\\    ");
	escreve(0,2,"| |   | |  | | |_) | |__) | | | |  \\| | |__| |  /  \\   ");
	escreve(0,3,"| |   | |  | |  _ <|  _  /  | | | . ` |  __  | / /\\ \\  ");
	escreve(0,4,"| |___| |__| | |_) | | \\ \\ _| |_| |\\  | |  | |/ ____ \\ ");
	escreve(0,5," \\_____\\____/|____/|_|  \\_|_____|_| \\_|_|  |_/_/    \\_\\");
	escreve(2,12,"Pressione qualquer tecla para começar");
	while(!kbhit){
	}
}

void menu2(){							//menu secreto
	escreve(0,0,"  _____ ____  _____  ____ _____ _   _ _    _          ");
	escreve(0,1," / ____/ __ \\|  __ \\|  _ \\_   _| \\ | | |  | |   /\\    ");
	escreve(0,2,"| |   | |  | | |__) | |_) || | |  \\| | |__| |  /  \\   ");
	escreve(0,3,"| |   | |  | |  _  /|  _ < | | | . ` |  __  | / /\\ \\  ");
	escreve(0,4,"| |___| |__| | | \\ \\| |_) || |_| |\\  | |  | |/ ____ \\ ");
	escreve(0,5," \\_____\\____/|_|  \\_\\____/_____|_| \\_|_|  |_/_/    \\_\\ ");
	escreve(2,12,"Pressione qualquer tecla para começar");
	while(!kbhit){
	}
}

void limpamenu(){
	escreve(0,0,"                                                                 ");
	escreve(0,1,"                                                                 ");
	escreve(0,2,"                                                                 ");
	escreve(0,3,"                                                                 ");
	escreve(0,4,"                                                                 ");
	escreve(0,5,"                                                                 ");
}

int main(){
	int x=20,y=13,mx[max],my[max],l=4,i=0,xe=0,ye=0,j,xf=0,yf,flag=0,mv,flag2=0;
	char t,T;
	srand(time(NULL));
	mv = rand()%9;					//chance de 1 em 10 de aparecer o menu secreto
start:
	x = 20;
	y = 13;
	l=4;	
	flag2=flag=xe=xf=0;					
	system("cls");
	printf("\e[?25l");				//esconde o cursor
	setlocale(LC_ALL,"Portuguese");
	gotoxy(50,7);
	printf("Tamanho = %d",l);
	escreve(0,24,"Jogo feito por:");
	escreve(0,25,"Bruno de Oliveira Monchelato - 1º Ano BCC UNESP");
	escreve(0,26,"Davi Bandeca Schwingel - 1º Ano BCC UNESP");
	if(mv==0)					//mv representa o menu secreto(se mv=0, o menu é o secreto)
		menu2();
	else
		menu();
	for(i=0;i<max;i++){
		mx[i]=0;
		my[i]=0;
	}
	borda();
	escreve(0,22,"Pressione esc para pausar");
	SetColor(6);
	escreve(x,y,"O");
	t = getch();
	escreve(2,12,"                                      ");
	escreve(x,y," ");
	while(true){
	if(l>=546){					//caso a cobrinha atinja o tamanho maximo o jogador vence
		SetColor(7);
		limpamenu();
		if(mv==0)
			escreve(15,1,"POGGERS! :D");
		else
			escreve(15,1,"PARABÉNS");
		escreve(13,2,"VOCÊ GANHOU!!");
		goto denovo;
	}
	fflush(stdin);
tecla:
	if(kbhit()) do{
		t = getch();
	}while(kbhit());
	if(t!=cima&&t!=baixo&&t!=direita&&t!=esquerda&&flag2==0)		//repete caso o jogador tente comçar o jogo com uma tecla não programada
		goto tecla;
	else if(t!=cima&&t!=baixo&&t!=direita&&t!=esquerda&&t!=esc)		//evita erros caso teclas não programadas sejam pressionadas durante o jogo
		t = flag2;
	if((flag2==cima && t==baixo)||(flag2==baixo && t==cima)||(flag2==direita&&t==esquerda)||(flag2==esquerda&&t==direita)) 
		t = flag2;			//previne que o jogador vire para a direção contraria de uma vez, causando a morte da cobrinha
	usleep(200000);
	if(t==cima){
		y--;
		flag2 = t;
	}
	else if(t==baixo){
		y++;
		flag2 = t;
	}
	else if(t==esquerda){
		x--;
		flag2 = t;
	}
	else if(t==direita){
		x++;
		flag2 = t;
	}
	if(t==esc){				//Sistema de pause
		SetColor(3);
		escreve(0,22,"                                  ");
		escreve(0,22,"Jogo pausado!");
		escreve(0,23,"Pressione ESC para sair ou ENTER para continuar!");
		do{
		T = getch();
		if(T == esc){
			SetColor(7);
			goto tchau;			//vai para a tela de quando o jogador decide sair
		}
		if(T == enter){
			t = flag2;			//retoma o jogo com a cobrinha no sentido que ela estava
			escreve(0,22,"                  ");
			escreve(0,23,"                                                     ");
			SetColor(7);
			escreve(0,22,"Pressione esc para pausar");
			SetColor(6);
			goto tecla;
		}
		}while(T!=enter&&T!=esc);		//só aceita enter ou esc como resposta
	}
	if(flag==0){			//verifica se a cobrinha ainda já comeu a fruta no mapa
		fruta(mx,my,l,&xf,&yf);
		flag=1;
	}
	else if(x==xf && y==yf){		//verifica se a cobrinha passa pela fruta
		l+=4;				//aumenta o tamanho da cobrinha em 4 para o jogo não ficar tão longo
		flag=0;
		gotoxy(50,7);
				SetColor(7);
		printf("Tamanho = %d",l);
		gotoxy(x,y);
				SetColor(6);
	}
	if(x==40||x==0||y==6|y==21){		//se a cobrinha bater nas bordas ela perde
perdeu:
		limpamenu();
		SetColor(7);
		if(mv==0)
			escreve(15,1,"NOGGERS :(");
		else
			escreve(15,1,"PERDEU!!");
denovo:
		if(repete()==1)
			goto start;
		else {
tchau:
			system("cls");
			escreve(12,13,"OBRIGADO POR JOGAR!!!");
			escreve(7,15,"Pressione qualquer botão para sair");
			while(true){
				if(kbhit()){
					system("cls");
					return 0;
				}
			}
		}
	}
		mx[i]=x;			//mx e 
		my[i]=y;			//mv usados para armazenar as posições da cobrinha
		gotoxy(x,y);
		printf("O");
		i++;
	if(i>l){			//verifica se a cobinha é maior que o seu tamanho maximo
		i=l;
		for(j=0;j<i;j++){
			if((j+1)!=(l+1)){
				mx[j]=mx[j+1];		//move as posições salvas da cobrinha excluindo a mais antiga
				my[j]=my[j+1];
			}
		}
		xe=mx[0];		
		ye=my[0];
		gotoxy(xe,ye);			
		printf(" ");			//printa barra de espaço na posição mais antiga da cobrinha
		gotoxy(x,y);	
		while(bateu(x,y,mx,my,l)!=0 && bateu(x,y,mx,my,l)!=1){		//verifica se a cobrinha bate nela mesma
		}
		if(bateu(x,y,mx,my,l)==1)
			goto perdeu;
	}
		mx[i]=x;
		my[i]=y;
		gotoxy(x,y);
		printf("O");
		i++;
	}
}
