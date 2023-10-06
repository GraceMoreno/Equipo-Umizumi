char matriz[3][3], opc;
int i, j;
int fila, col, ganador=0, turno=1;
int comprobadorGanar(int win,char arr[][3]);
void mostrarTabla(char arr[][3]);
void inicializarTabla(char arr[][3]);
void movimientos(char arr[][3]);
int estallenaMatriz(char arr[][3]);


//---------------------------------------------------------------------------------------------------------
int main(){
printf("Juego del gato!\n");
// llamada funcion para inicializar la tabla
inicializarTabla(matriz);
printf("Presione Y para jugar / N para salir: ");
scanf(" %c", &opc);
if(opc == 'Y' || opc == 'y'){
do{
// llamada funcion para realizar los movimientos
movimientos(matriz);
// llamada funcion para comprobar quien gano
ganador=comprobadorGanar(ganador,matriz);
} while(ganador != 1 && estallenaMatriz(matriz)==0 );
} else {
printf("\033[H\033[J");
printf("Gracias por usar el programa ten un buen dia.\n");
}
return 0;
}

//---------------------------------------------------------------------------------------------------------
// funcion para inicializar la tabla
void inicializarTabla(char arr[][3]){
for(i=0; i<3; i++){
for(j=0; j<3; j++){
arr[i][j]=' ';
printf("[%c]", arr[i][j]);
}
printf("\n");
}
}

//---------------------------------------------------------------------------------------------------------
// funcion para realizar los movimientos
void movimientos(char arr[][3]){
   if(turno%2==1 && estallenaMatriz(arr)==0 ){
do{
// turno del primer jugador
printf("Jugador 1, juegas con X: \n");
printf("Digite fila: ");
scanf(" %d", &fila);
printf("Digite columna: ");
scanf(" %d", &col);
if(arr[fila][col]=='x'||arr[fila][col]=='o'||fila>2||col>2){
printf("Coordenadas no validas, pruebe otra vez.\n");
}
}while(arr[fila][col]=='x'||arr[fila][col]=='o'||fila>2||col>2);
arr[fila][col]='x';
printf("\033[H\033[J");
// llamada a funcion para mostrar la tabla
mostrarTabla(arr);
turno++;
} else if(turno%2==0 && estallenaMatriz(arr)==0 ){
do{
// turno del segundo jugador
printf("Jugador 2, juegas con O: \n");
printf("Digite fila: ");
scanf(" %d", &fila);
printf("Digite columna: ");
scanf(" %d", &col);
if(arr[fila][col] == 'x' || arr[fila][col] == 'o' || fila > 2 || col > 2){
printf("Coordenadas no validas, pruebe otra vez.\n");
}
} while(arr[fila][col] == 'x' || arr[fila][col] == 'o' || fila > 2 || col > 2);
arr[fila][col]='o';
// llamada a funcion para mostrar la tabla
mostrarTabla(arr);
turno++;
}
}

//---------------------------------------------------------------------------------------------------------
//funcion para comprobar si la matriz esta llena
int estallenaMatriz(char arr[][3]){
   for(i=0; i<3; i++){
      for(j=0; j<3; j++){
         if( arr[i][j]==' '){
            return 0;// no esta lleno
         }
      }
   }
   return 1; // esta lleno
}

//---------------------------------------------------------------------------------------------------------
// funcion para mostrar la tabla
void mostrarTabla(char arr[][3]){
printf("\033[H\033[J");
printf("Juego del gato!\n");
for(i=0; i<3; i++){
for(j=0; j<3; j++){
printf("[%c]", matriz[i][j]);
}
printf("\n");
}
}

//---------------------------------------------------------------------------------------------------------
// funcion para comprobar quien gano
int comprobadorGanar(int win,char arr[][3]){

if(arr[0][0] == 'x' && arr[0][0] == arr[0][1] && arr[0][0] == arr[0][2]
|| arr[1][0] == 'x' && arr[1][0] == arr[1][1] && arr[1][0] == arr[1][2]
|| arr[2][0] == 'x' && arr[2][0] == arr[2][1] && arr[2][0] == arr[2][2]

|| arr[0][0] == 'x' && arr[0][0] == arr[1][0] && arr[0][0] == arr[2][0]
|| arr[0][1] == 'x' && arr[0][1] == arr[1][1] && arr[0][1] == arr[2][1]
|| arr[0][2] == 'x' && arr[0][2] == arr[1][2] && arr[0][2] == arr[2][2]

|| arr[0][0] == 'x' && arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2]
|| arr[0][2] == 'x' && arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0]){
win=1;
printf("Felicidades! Gano el jugador 1.\n");
}
if(arr[0][0] == 'o' && arr[0][0] == arr[0][1] && arr[0][0] == arr[0][2]
|| arr[1][0] == 'o' && arr[1][0] == arr[1][1] && arr[1][0] == arr[1][2]
|| arr[2][0] == 'o' && arr[2][0] == arr[2][1] && arr[2][0] == arr[2][2]

|| arr[0][0] == 'o' && arr[0][0] == arr[1][0] && arr[0][0] == arr[2][0]
|| arr[0][1] == 'o' && arr[0][1] == arr[1][1] && arr[0][1] == arr[2][1]
|| arr[0][2] == 'o' && arr[0][2] == arr[1][2] && arr[0][2] == arr[2][2]

|| arr[0][0] == 'o' && arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2]
|| arr[0][2] == 'o' && arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0]){
win=1;
printf("Felicidades! Gano el jugador 2.\n");
}
if (estallenaMatriz(arr)==1 && win==0){
printf("Empate, juego terminado.");

}
return win;
}
