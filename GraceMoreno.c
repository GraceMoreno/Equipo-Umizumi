// funcion para realizar los movimientos, parte de Grace Moreno
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
