#include <iostream>
#include <string>
using namespace std;

char** crearmat(int,int);

void liberarMatriz(char**&,int,int);

void printmat(char**,int,int);

char** llenar(char**,int,int);

void contar(char**, int,int);

int main(){
	string cadena;
	cout<< "Ingrese la cadena inicial: ";	
	cin >> cadena;
	cout<<endl;
	int x,y;
	x=cadena.size();
	cout<<"Ingrese el alto de la matriz: ";
	cin >> y;
	cout<<endl;
	char** mat=NULL;
	mat=crearmat(x,y);
	for(int i=0;i<x;i++){
		mat[0][i]=cadena[i];
	}
	llenar(mat,x,y);
	printmat(mat,x,y);
	contar(mat,x,y);
	liberarMatriz(mat,x,y);
}
char** crearmat(int x,int y){
	char** mat=NULL;
	mat=new char*[y];
	for(int i=0;i<y;i++){
		mat[i]=new char[x];
	}
	return mat;
}
void printmat(char** mat, int x,int y){
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++){
			cout<<"["<<mat[i][j]<<"]";
		}
		cout<<endl;
	}
}
void liberarMatriz(char**& mat,int x,int y){
	for(int i=0;i<y;i++){
		delete[] mat[i];
		mat[i]=NULL;
	}
	if(mat!=NULL){
		delete[] mat;
		mat=NULL;
	}
}
char** llenar(char** mat,int x,int y){
	for (int i=1;i<y;i++){
		char* arreglo=mat[i-1];
		for(int j=0;j<x;j++){
			if(j==0&&j<x){
				if(arreglo[j]=='^'&&arreglo[j+1]=='^'){
					mat[i][j]='^';
				}
				else if(arreglo[j+1]=='^'){
					mat[i][j]='^';
				}else {
					mat[i][j]='.';
				}
			}else if(j>0&&j<x){
				if(arreglo[j-1]=='^'&&arreglo[j]=='^'&&arreglo[j+1]=='.'){
					mat[i][j]='^';
				}else if(arreglo[j-1]=='.'&&arreglo[j]=='^'&&arreglo[j+1]=='^'){
					mat[i][j]='^';
				}else if(arreglo[j-1]=='^'&&arreglo[j]=='.'&&arreglo[j+1]=='.'){
					mat[i][j]='^';
				}else if(arreglo[j-1]=='.'&&arreglo[j]=='.'&&arreglo[j+1]=='^'){
					mat[i][j]='^';
				}else{
					mat[i][j]='.';
				}
			}else if(j>0&&j==x){
				if(arreglo[j-1]=='^'&&arreglo[j]=='^'){
					mat[i][j]='^';
				}else if(arreglo[j-1]=='^'&&arreglo[j]=='.'){
					mat[i][j]='^';
				}else{
					mat[i][j]='.';
				}
			}
		}
	}
}
void contar(char** mat,int x, int y){
	int contador=0;
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++){
			if(mat[i][j]=='.'){
				contador++;
			}
		}
	}
	cout<<"El numero de casillas seguras es: "<<contador<<endl;
}
