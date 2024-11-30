#include<stdio.h>
#include<stdlib.h>
int movQueen( int col,int  linha, int n, int **m){
    for(int i = 0; i< linha; i++){
        if(m[i][col]==1)
            return 0;
    }
    for(int i = linha,j=col; i>=0 && j>=0; i--, j--){
        if( m[i][j]==1)
        return 0;
    }
        for(int i = linha,j=col; i>=0 && j< n; i--,j++){
            if( m[i][j]==1)
        return 0;
    }
    return 1;
}
int InputQueens(int linha, int n, int **mat){
    if (linha >= n) {
        return 1; 
    }
    for(int col = 0 ; col< n;col++){
        if(movQueen(col, linha,n ,mat)!=0){
        mat[linha][col]=1;
            if(InputQueens(linha+1, n,mat)!=0){
                return 1;
            }
        }
        mat[linha][col]=0;
    }
    return 0;
}

int main(){
    int n = 5;
    int **mat=(int**)calloc(n,sizeof(int*));
    for(int i = 0; i < n; i++){
        mat[i]=(int*)calloc(n,sizeof(int));
    }
    if(InputQueens(0,n, mat)){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", mat[i][j]); // Imprimir apenas os números
            }
                printf("\n");
        }
    }
    else{
        printf("Solução nao econtrada");
    }
    for (int i = 0; i < n; i++) {
        free(mat[i]);  // Liberar cada linha
    }
    free(mat);  // Liberar a matriz
}

