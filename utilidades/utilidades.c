#include "utilidades.h"

char MSJxERROR[] = "¡VALOR NO VÁLIDO!";
char MSJxPAUSA[] = "Pulse INTRO para continuar... ";

int codigoError;

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void esperarINTRO (void)
//
//  USO:
//
//    Programa que produce una espera hasta que se pulse INTRO.
//
//  DETALLES:
//
//    Es un envoltorio de la función vaciarBuffer(), a la cual delega todo el
//    trabajo. Es una manera de crear "sinónimos" de acciones.
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    vaciarBuffer()
//
////////////////////////////////////////////////////////////////////////////////
void esperarINTRO (void) {
  vaciarBuffer();
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void descartarEntrada (void)
//
//  USO:
//
//    Limpia el buffer de entrada de datos.
//
//  DETALLES:
//    Actúa como un alias para vaciarBuffer() con el fin de mejorar la 
//    legibilidad en contextos de descarte de datos.
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    vaciarBuffer()
//
////////////////////////////////////////////////////////////////////////////////
void descartarEntrada (void) {
  vaciarBuffer();
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void vaciarBuffer (void)
//
//  USO:
//
//    Espera a que el usuario pulse teclas hasta encontrar un INTRO.
//
//  DETALLES:
//
//    Se basa en un bucle que pide caracteres y no termina hasta detectar 
//    el código ENTER. Produce eco de las teclas pulsadas.
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    getchar()
//
////////////////////////////////////////////////////////////////////////////////
void vaciarBuffer (void) {
  char letra;
  do {
    letra = getchar();
  } while (letra != ENTER);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void borrarPantalla (void)
//
//  USO:
//
//    Limpia el contenido de la terminal.
//
//  DETALLES:
//
//    Llamada envoltorio para la función limpiarPantalla().
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    limpiarPantalla()
//
////////////////////////////////////////////////////////////////////////////////
void borrarPantalla (void) {
  limpiarPantalla();
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void limpiarPantalla (void)
//
//  USO:
//
//    Ejecuta el comando del sistema para limpiar la pantalla.
//
//  DETALLES:
//
//    Utiliza la constante macro BORRAR para determinar el comando según el SO.
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    system()
//
////////////////////////////////////////////////////////////////////////////////
void limpiarPantalla (void) {
  system(BORRAR);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void bajar (int nlineas)
//
//  USO:
//
//    Desplaza el cursor hacia abajo un número determinado de líneas.
//
//  DETALLES:
//
//    Utiliza un bucle para imprimir caracteres de salto de línea '\n'.
//
//  PARÁMETROS DE ENTRADA:
//
//    nlineas
//      Cantidad entera de saltos de línea a realizar.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    printf()
//
////////////////////////////////////////////////////////////////////////////////
void bajar (int nlineas) {
  while(nlineas>0) {
    printf("\n");
    nlineas--;
  }
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void abajo (int nfils)
//
//  USO:
//
//    Mueve el cursor hacia abajo.
//
//  DETALLES:
//
//    Alias de la función bajar().
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//      Número de filas a bajar.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar()
//
////////////////////////////////////////////////////////////////////////////////
void abajo (int nfils) {
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void saltar (int nfils)
//
//  USO:
//
//    Realiza saltos de línea.
//
//  DETALLES:
//
//    Alias de la función bajar().
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//      Número de saltos de línea.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar()
//
////////////////////////////////////////////////////////////////////////////////
void saltar (int nfils) {
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarFils (int nfils)
//
//  USO:
//
//    Desplaza verticalmente el cursor.
//
//  DETALLES:
//
//    Alias de la función bajar().
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//      Número de filas.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar()
//
////////////////////////////////////////////////////////////////////////////////
void desplazarFils (int nfils) {
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarV (int nfils)
//
//  USO:
//
//    Desplazamiento vertical.
//
//  DETALLES:
//
//    Alias de la función bajar().
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//      Número de filas.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar()
//
////////////////////////////////////////////////////////////////////////////////
void desplazarV (int nfils) {
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarY (int nfils)
//
//  USO:
//
//    Desplazamiento en el eje Y (vertical).
//
//  DETALLES:
//
//    Alias de la función bajar().
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//      Número de filas.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar()
//
////////////////////////////////////////////////////////////////////////////////
void desplazarY (int nfils) {
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void indentar (int ncolumnas)
//
//  USO:
//
//    Escribe espacios en blanco a la derecha.
//
//  DETALLES:
//
//    Utiliza un bucle for para imprimir el carácter espacio ' '.
//
//  PARÁMETROS DE ENTRADA:
//
//    ncolumnas
//      Número de espacios a imprimir.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    printf()
//
////////////////////////////////////////////////////////////////////////////////
void indentar (int ncolumnas) {
  for(int i=0; i<ncolumnas; i++) {
    printf(" ");
  }
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void derecha (int ncols)
//
//  USO:
//
//    Desplaza el cursor a la derecha.
//
//  DETALLES:
//
//    Alias de la función indentar().
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//      Número de columnas.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar()
//
////////////////////////////////////////////////////////////////////////////////
void derecha (int ncols) {
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void tabular (int ncols)
//
//  USO:
//
//    Aplica una tabulación mediante espacios.
//
//  DETALLES:
//
//    Alias de la función indentar().
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//      Número de columnas.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar()
//
////////////////////////////////////////////////////////////////////////////////
void tabular (int ncols) {
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarCols (int ncols)
//
//  USO:
//
//    Desplaza el cursor horizontalmente.
//
//  DETALLES:
//
//    Alias de la función indentar().
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//      Número de columnas.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar()
//
////////////////////////////////////////////////////////////////////////////////
void desplazarCols (int ncols) {
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarX (int ncols)
//
//  USO:
//
//    Desplazamiento en el eje X.
//
//  DETALLES:
//
//    Alias de la función indentar().
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//      Número de columnas.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar()
//
////////////////////////////////////////////////////////////////////////////////
void desplazarX (int ncols) {
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarH (int ncols)
//
//  USO:
//
//    Desplazamiento horizontal.
//
//  DETALLES:
//
//    Alias de la función indentar().
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//      Número de columnas.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar()
//
////////////////////////////////////////////////////////////////////////////////
void desplazarH (int ncols) {
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void posicionar (int nfils, int ncols)
//
//  USO:
//
//    Sitúa el cursor en una coordenada relativa (filas, columnas).
//
//  DETALLES:
//
//    Combina las funciones de saltar líneas y tabular espacios.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//      Número de saltos de línea.
//
//    ncols
//      Número de espacios de indentación.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar(), tabular()
//
////////////////////////////////////////////////////////////////////////////////
void posicionar (int nfils, int ncols) {
  bajar(nfils);
  tabular(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazar (int nfils, int ncols)
//
//  USO:
//
//    Desplaza el cursor a una posición.
//
//  DETALLES:
//
//    Alias de la función posicionar().
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//      Número de filas.
//    ncols
//      Número de columnas.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    posicionar()
//
////////////////////////////////////////////////////////////////////////////////
void desplazar (int nfils, int ncols) {
  posicionar(nfils, ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarXY (int nfils, int ncols)
//
//  USO:
//
//    Desplaza el cursor en ambos ejes.
//
//  DETALLES:
//
//    Alias de la función posicionar().
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//      Coordenada Y.
//    ncols
//      Coordenada X.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    posicionar()
//
////////////////////////////////////////////////////////////////////////////////
void desplazarXY (int nfils, int ncols) {
  posicionar(nfils, ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void retardoSegundos (int segundosmax)
//
//  USO:
//
//    Genera una pausa en la ejecución basada en bucles.
//
//  DETALLES:
//
//    Utiliza bucles anidados para consumir ciclos de CPU. Poco preciso.
//
//  PARÁMETROS DE ENTRADA:
//
//    segundosmax
//      Número aproximado de segundos de espera.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    Ninguna.
//
////////////////////////////////////////////////////////////////////////////////
void retardoSegundos (int segundosmax) {
  for(int nseg=0; nseg < segundosmax ; nseg++) {
    for(int j=0; j<100; j++)
      for(int j=0; j<1000; j++)
        for(int k=0; k<1000; k++)   ;
  }
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void retardoMilisegundos (int milisegundosmax)
//
//  USO:
//
//    Genera una pausa en milisegundos mediante bucles.
//
//  DETALLES:
//
//    Método de espera activa por hardware, impreciso según la velocidad del procesador.
//
//  PARÁMETROS DE ENTRADA:
//
//    milisegundosmax
//      Cantidad de milisegundos aproximados.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    Ninguna.
//
////////////////////////////////////////////////////////////////////////////////
void retardoMilisegundos (int milisegundosmax) {
  int i, j;
  for (int nmiliseg=0; nmiliseg<milisegundosmax ; nmiliseg++)
    for (i=0; i<100; i++)
      for (j=0; j<1000; j++)   ;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void retrasoMilisegundos (int milisegundos)
//
//  USO:
//
//    Pausa la ejecución usando el reloj del sistema.
//
//  DETALLES:
//
//    Utiliza clock() para medir el tiempo transcurrido de forma más precisa.
//
//  PARÁMETROS DE ENTRADA:
//
//    milisegundos
//      Tiempo de espera en milisegundos.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    clock()
//
////////////////////////////////////////////////////////////////////////////////
void retrasoMilisegundos (int milisegundos) {
  double e = 0;
  clock_t t0 = clock();
  do {
    e = 1000*(double)(clock()-t0)/CLOCKS_PER_SEC;
  } while (e<milisegundos);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void esperarSegundos (int segundos)
//
//  USO:
//
//    Pausa la ejecución del programa durante segundos.
//
//  DETALLES:
//
//    Utiliza funciones nativas del SO (Sleep en Windows, sleep en Unix).
//
//  PARÁMETROS DE ENTRADA:
//
//    segundos
//      Tiempo a esperar.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    Sleep() o sleep()
//
////////////////////////////////////////////////////////////////////////////////
void esperarSegundos (int segundos) {
  #ifdef SO_WINDOWS
    Sleep(segundos*1000);
  #else
    sleep(segundos);
  #endif
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void esperarMilisegundos (int milisegundos)
//
//  USO:
//
//    Pausa la ejecución del programa durante milisegundos.
//
//  DETALLES:
//
//    Utiliza Sleep (Windows) o usleep (Unix) para la pausa.
//
//  PARÁMETROS DE ENTRADA:
//
//    milisegundos
//      Tiempo a esperar.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    Sleep() o usleep()
//
////////////////////////////////////////////////////////////////////////////////
void esperarMilisegundos (int milisegundos) {
  #ifdef SO_WINDOWS
    Sleep(milisegundos);
  #else
    usleep(milisegundos*1000);
  #endif
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void pausa (void)
//
//  USO:
//
//    Realiza una pausa estándar en la pantalla.
//
//  DETALLES:
//
//    Llama a pausaEstandar con coordenadas predefinidas.
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    pausaEstandar()
//
////////////////////////////////////////////////////////////////////////////////
void pausa (void) {
  pausaEstandar(1, 2);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void pausaEstandar (int nfils, int ncols)
//
//  USO:
//
//    Muestra el mensaje de pausa en una posición específica.
//
//  DETALLES:
//
//    Usa MSJxPAUSA como texto descriptivo.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//      Filas de desplazamiento.
//    ncols
//      Columnas de desplazamiento.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    pausaGenerica()
//
////////////////////////////////////////////////////////////////////////////////
void pausaEstandar (int nfils, int ncols) {
  pausaGenerica(MSJxPAUSA, nfils, ncols, FALSE);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void pausaGenerica (char msjtxt[], int nfils, int ncols, boolean nuevalinea)
//
//  USO:
//
//    Muestra un mensaje y espera al usuario.
//
//  DETALLES:
//
//    Muestra el texto en la posición indicada y llama a esperarINTRO().
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//      Cadena de texto a mostrar.
//    nfils
//      Saltos de línea.
//    ncols
//      Indentación horizontal.
//    nuevalinea
//      Booleano para añadir salto de línea final.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y(), esperarINTRO()
//
////////////////////////////////////////////////////////////////////////////////
void pausaGenerica (char msjtxt[], int nfils, int ncols, boolean nuevalinea) {
  mensaje_x_y(msjtxt, nfils, ncols, nuevalinea);
  esperarINTRO();
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void texto (char msjtxt[])
//
//  USO:
//
//    Imprime una cadena seguida de un salto de línea.
//
//  DETALLES:
//
//    Usa la función estándar puts().
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//      Texto a imprimir.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    puts()
//
////////////////////////////////////////////////////////////////////////////////
void texto (char msjtxt[]) {
  puts(msjtxt);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void separar()
//
//  USO:
//
//    Imprime un salto de línea simple.
//
//  DETALLES:
//
//    Utiliza la función mostrar() con el carácter '\n'.
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mostrar()
//
////////////////////////////////////////////////////////////////////////////////
void separar() {
  mostrar("\n");
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void nuevaLinea (void)
//
//  USO:
//
//    Genera un salto de línea.
//
//  DETALLES:
//
//    Alias para saltar(1).
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    saltar()
//
////////////////////////////////////////////////////////////////////////////////
void nuevaLinea (void) {
  saltar(1);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void mostrar (char msjtxt[])
//
//  USO:
//
//    Muestra un texto en la posición actual.
//
//  DETALLES:
//
//    Llamada simplificada a mostrar_x_y en (0,0).
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//      Texto a imprimir.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mostrar_x_y()
//
////////////////////////////////////////////////////////////////////////////////
void mostrar (char msjtxt[]) {
  mostrar_x_y (msjtxt, 0, 0);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void mostrar_x_y (char msjtxt[], int nfils, int ncols)
//
//  USO:
//
//    Muestra texto con desplazamiento.
//
//  DETALLES:
//
//    Invoca mensaje_x_y sin salto de línea final.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//      Contenido textual.
//    nfils
//      Filas.
//    ncols
//      Columnas.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y()
//
////////////////////////////////////////////////////////////////////////////////
void mostrar_x_y (char msjtxt[], int nfils, int ncols) {
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void escribir (char msjtxt[])
//
//  USO:
//
//    Escribe texto en pantalla.
//
//  DETALLES:
//
//    Equivalente a mostrar().
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//      Texto.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    escribir_x_y()
//
////////////////////////////////////////////////////////////////////////////////
void escribir (char msjtxt[]) {
  escribir_x_y (msjtxt, 0, 0);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void escribir_x_y (char msjtxt[], int nfils, int ncols)
//
//  USO:
//
//    Escribe texto con coordenadas.
//
//  DETALLES:
//
//    Envía el texto a mensaje_x_y.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//      Texto.
//    nfils
//      Fila.
//    ncols
//      Columna.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y()
//
////////////////////////////////////////////////////////////////////////////////
void escribir_x_y (char msjtxt[], int nfils, int ncols) {
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void imprimir (char msjtxt[])
//
//  USO:
//
//    Imprime texto en pantalla.
//
//  DETALLES:
//
//    Equivalente a mostrar().
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//      Texto.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    imprimir_x_y()
//
////////////////////////////////////////////////////////////////////////////////
void imprimir (char msjtxt[]) {
  imprimir_x_y (msjtxt, 0, 0);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void imprimir_x_y (char msjtxt[], int nfils, int ncols)
//
//  USO:
//
//    Imprime texto con coordenadas.
//
//  DETALLES:
//
//    Llama a mensaje_x_y.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//      Texto.
//    nfils
//      Fila.
//    ncols
//      Columna.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y()
//
////////////////////////////////////////////////////////////////////////////////
void imprimir_x_y (char msjtxt[], int nfils, int ncols) {
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void mensaje (char msjtxt[], int nfils, int ncols)
//
//  USO:
//
//    Muestra un mensaje posicionado.
//
//  DETALLES:
//
//    Encapsula la llamada a mensaje_x_y.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//      Texto.
//    nfils
//      Fila.
//    ncols
//      Columna.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y()
//
////////////////////////////////////////////////////////////////////////////////
void mensaje (char msjtxt[], int nfils, int ncols) {
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void mensaje_x_y (char msjtxt[], int nfils, int ncols, boolean nuevalinea)
//
//  USO:
//
//    Función núcleo para salida de texto con formato de posición.
//
//  DETALLES:
//
//    Aplica saltos de línea, tabulaciones y el texto. Permite salto final opcional.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//      Texto a imprimir.
//    nfils
//      Número de filas a bajar antes.
//    ncols
//      Número de columnas a tabular antes.
//    nuevalinea
//      Si es TRUE, añade un salto de línea al final.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    saltar(), tabular(), printf()
//
////////////////////////////////////////////////////////////////////////////////
void mensaje_x_y (char msjtxt[], int nfils, int ncols, boolean nuevalinea) {
  saltar(nfils);
  tabular(ncols);
  printf("%s", msjtxt);
  if (nuevalinea) printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void iniciaAleatorizador (void)
//
//  USO:
//
//    Inicializa la semilla para la generación de números aleatorios.
//
//  DETALLES:
//
//    Utiliza el tiempo actual del sistema (time(NULL)).
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    srand(), time()
//
////////////////////////////////////////////////////////////////////////////////
void iniciaAleatorizador (void) {
  srand(time(NULL));
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int generaAleatorioEntero (int limite)
//
//  USO:
//
//    Genera un número entero aleatorio.
//
//  DETALLES:
//
//    El rango del número generado es [0, limite - 1].
//
//  PARÁMETROS DE ENTRADA:
//
//    limite
//      Valor entero máximo (no incluido).
//
//  VALOR DE SALIDA:
//
//    Devuelve un int con el número aleatorio generado.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    rand()
//
////////////////////////////////////////////////////////////////////////////////
int generaAleatorioEntero (int limite) {
  return (rand() % limite);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int obtenerEntero (void)
//
//  USO:
//
//    Lee un número entero del teclado y limpia el buffer.
//
//  DETALLES:
//
//    Evita problemas de lectura de caracteres residuales tras el uso de scanf.
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    Devuelve el valor entero capturado.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    scanf(), vaciarBuffer()
//
////////////////////////////////////////////////////////////////////////////////
int obtenerEntero (void) {
  int valor;
  scanf("%d", &valor);
  vaciarBuffer();
  return valor;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    char obtenerCaracterASCII()
//
//  USO:
//
//    Lee un carácter ASCII.
//
//  DETALLES:
//
//    Alias de obtenerLetra().
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    Devuelve un char con el carácter ASCII.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    obtenerLetra()
//
////////////////////////////////////////////////////////////////////////////////
char obtenerCaracterASCII() {
  return obtenerLetra();
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    char obtenerLetra (void)
//
//  USO:
//
//    Captura una letra del teclado validando que sea ASCII.
//
//  DETALLES:
//
//    Si la letra es mayor de 127 devuelve nulo. Siempre vacía el buffer después.
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    Devuelve el char válido o '\0'.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    getchar(), vaciarBuffer()
//
////////////////////////////////////////////////////////////////////////////////
char obtenerLetra (void) {
  char letra, valida;
  letra = getchar();
  if (letra < 128) valida = letra;
  else valida = '\0';
  if (letra != ENTER) vaciarBuffer();
  return valida;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirEntero (char msjtxt[], int ncols)
//
//  USO:
//
//    Muestra un mensaje y captura un entero.
//
//  DETALLES:
//
//    Utiliza mensaje() para el texto y obtenerEntero() para el dato.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//      Texto de solicitud.
//    ncols
//      Columnas de indentación.
//
//  VALOR DE SALIDA:
//
//    Devuelve el entero introducido.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje(), mostrar(), obtenerEntero()
//
////////////////////////////////////////////////////////////////////////////////
int pedirEntero (char msjtxt[], int ncols) {
  mensaje(msjtxt, 0, ncols);
  mostrar(": ");
  return obtenerEntero();
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirEnteroPositivo (char msjtxt[], int ncols, boolean mostrarerror)
//
//  USO:
//
//    Solicita un entero y asegura que sea positivo.
//
//  DETALLES:
//
//    Bucle do-while que se repite mientras el valor sea menor que 0.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//      Texto.
//    ncols
//      Columnas.
//    mostrarerror
//      Define si se imprime mensaje de error.
//
//  VALOR DE SALIDA:
//
//    Devuelve un int positivo.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje(), mostrar(), obtenerEntero(), nuevaLinea(), mensaje_x_y()
//
////////////////////////////////////////////////////////////////////////////////
int pedirEnteroPositivo (char msjtxt[], int ncols, boolean mostrarerror) {
  int num;
  do {
    mensaje(msjtxt, 0, ncols);
    mostrar(": ");
    num = obtenerEntero();
    if (mostrarerror) {
      if (num < 0) {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
  } while (num < 0);
  return num;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirEnteroIntervalo (char msjtxt[], int ncols, boolean mostrarerror, int min, int max)
//
//  USO:
//
//    Pide un número dentro de un rango [min, max].
//
//  DETALLES:
//
//    Muestra visualmente el rango permitido al usuario.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//      Texto.
//    ncols
//      Sangría.
//    mostrarerror
//      Mostrar feedback de error.
//    min
//      Límite inferior.
//    max
//      Límite superior.
//
//  VALOR DE SALIDA:
//
//    Devuelve el entero validado.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje(), printf(), obtenerEntero(), nuevaLinea(), mensaje_x_y()
//
////////////////////////////////////////////////////////////////////////////////
int pedirEnteroIntervalo (char msjtxt[], int ncols, boolean mostrarerror, int min, int max) {
  int num;
  do {
    mensaje(msjtxt, 0, ncols);
    printf(" [%d,%d]: ", min, max);
    num = obtenerEntero();
    if (mostrarerror) {
      if (num < min || num > max) {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
  } while (num < min || num > max);
  return num;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirLetra (char msjtxt[], int ncols, boolean mostrarerror, char letra)
//
//  USO:
//
//    Solicita una letra específica al usuario.
//
//  DETALLES:
//
//    No distingue entre mayúsculas y minúsculas durante la validación.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//      Texto.
//    ncols
//      Posición X.
//    mostrarerror
//      Boolean de error.
//    letra
//      Carácter esperado.
//
//  VALOR DE SALIDA:
//
//    Devuelve el carácter capturado (en mayúsculas).
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    toupper(), mensaje(), mostrar(), obtenerLetra(), nuevaLinea(), mensaje_x_y()
//
////////////////////////////////////////////////////////////////////////////////
int pedirLetra (char msjtxt[], int ncols, boolean mostrarerror, char letra) {
  char pedida;
  letra = toupper(letra);
  do {
    mensaje(msjtxt, 0, ncols);
    mostrar(": ");
    pedida = obtenerLetra();
    pedida = toupper(pedida);
    if (mostrarerror) {
      if (letra != pedida) {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
  } while (letra != pedida);
  return pedida;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirConfirmacion (char msjtxt[], int ncols, boolean mostrarerror)
//
//  USO:
//
//    Pide una respuesta de tipo SI/NO.
//
//  DETALLES:
//
//    Utiliza las constantes SI y NO definidas externamente.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//      Texto de la pregunta.
//    ncols
//      Posición.
//    mostrarerror
//      Feedback.
//
//  VALOR DE SALIDA:
//
//    Devuelve el carácter SI o NO (validado).
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje(), printf(), obtenerLetra(), toupper(), nuevaLinea(), mensaje_x_y()
//
////////////////////////////////////////////////////////////////////////////////
int pedirConfirmacion (char msjtxt[], int ncols, boolean mostrarerror) {
  char letra;
  do {
    mensaje(msjtxt, 0, ncols);
    printf(" [%c/%c]: ", SI, NO);
    letra = obtenerLetra();
    letra = toupper(letra);
    if (mostrarerror) {
      if (letra != SI && letra != NO) {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
  } while (letra != SI && letra != NO);
  return letra;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    boolean validarLetraUnica (char original, char dada, boolean sensibleamayusculas)
//
//  USO:
//
//    Compara si dos caracteres son iguales.
//
//  DETALLES:
//
//    Permite configurar si la comparación ignora la capitalización.
//
//  PARÁMETROS DE ENTRADA:
//
//    original
//      Carácter base.
//    dada
//      Carácter a comparar.
//    sensibleamayusculas
//      Flag de sensibilidad.
//
//  VALOR DE SALIDA:
//
//    Devuelve TRUE si son iguales, FALSE si no.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    toupper()
//
////////////////////////////////////////////////////////////////////////////////
boolean validarLetraUnica (char original, char dada, boolean sensibleamayusculas) {
  if (!sensibleamayusculas) {
    original = toupper(original);
    dada = toupper(dada);
  }
  return (original == dada);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    boolean validarLetraConjunto (char letra, char seleccion[], boolean sensibleamayusculas)
//
//  USO:
//
//    Verifica si un carácter pertenece a un conjunto (string).
//
//  DETALLES:
//
//    Recorre el vector de caracteres comparando uno a uno.
//
//  PARÁMETROS DE ENTRADA:
//
//    letra
//      Carácter a buscar.
//    seleccion[]
//      Cadena con opciones válidas.
//    sensibleamayusculas
//      Flag de sensibilidad.
//
//  VALOR DE SALIDA:
//
//    Devuelve TRUE si se encuentra, FALSE si no.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    strlen(), validarLetraUnica()
//
////////////////////////////////////////////////////////////////////////////////
boolean validarLetraConjunto (char letra, char seleccion[], boolean sensibleamayusculas) {
  boolean resultado = FALSE;
  int largo = strlen(seleccion);
  for(int i = 0; i < largo ; i++) {
    if (validarLetraUnica(letra, seleccion[i], sensibleamayusculas)) {
      resultado = TRUE;
      break;
    }
  }
  return resultado;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    char *cadenaOpcionesDisponibles (char entrada[])
//
//  USO:
//
//    Formatea una cadena de opciones para mostrarla al usuario.
//
//  DETALLES:
//
//    Convierte "ABC" en "A/B/C". Reserva memoria dinámica.
//
//  PARÁMETROS DE ENTRADA:
//
//    entrada[]
//      Cadena original con opciones.
//
//  VALOR DE SALIDA:
//
//    Devuelve un puntero a la nueva cadena formateada.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    strlen(), malloc()
//
////////////////////////////////////////////////////////////////////////////////
char *cadenaOpcionesDisponibles (char entrada[]) {
  if (entrada == NULL) return NULL;
  char *textoinicial, *textofinal;
  textoinicial = entrada;
  int largoinicial, largofinal;
  largoinicial = strlen(textoinicial);
  if (largoinicial == 0) {
    largofinal = 1;
    textofinal = (char *) malloc(1*sizeof(char));
    textofinal[0] = '\0';
  } else {
    largofinal = 2 * largoinicial;
    textofinal = (char *) malloc(largofinal*sizeof(char));
    if (textofinal != NULL) {
      int j = 0;
      for (int i = 0; i < largoinicial; i++, j++) {
        textofinal[j] = textoinicial[i];
        j++;
        textofinal[j] = '/';
      }
      j--;
      textofinal[j] = '\0';
    }
  }
  return textofinal;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirLetraSeleccion (char msjtxt[], int ncols, boolean mostrarerror, char seleccion[], boolean sensibleamayusculas)
//
//  USO:
//
//    Solicita al usuario una letra que debe estar en una lista dada.
//
//  DETALLES:
//
//    Muestra las opciones disponibles entre corchetes y valida la entrada.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt[]
//      Texto.
//    ncols
//      Posición.
//    mostrarerror
//      Boolean error.
//    seleccion[]
//      Cadena de opciones válidas.
//    sensibleamayusculas
//      Flag sensibilidad.
//
//  VALOR DE SALIDA:
//
//    Devuelve la letra seleccionada.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    cadenaOpcionesDisponibles(), mensaje(), mostrar(), printf(), obtenerLetra(), 
//    validarLetraConjunto(), nuevaLinea(), mensaje_x_y(), free(), toupper()
//
////////////////////////////////////////////////////////////////////////////////
int pedirLetraSeleccion (char msjtxt[], int ncols, boolean mostrarerror, char seleccion[], boolean sensibleamayusculas) {
  char *editada = cadenaOpcionesDisponibles(seleccion);
  char letra;
  boolean validada;
  do {
    mensaje(msjtxt, 0, ncols);
    mostrar(" [");
    printf("%s", editada);
    mostrar("]: ");
    letra = obtenerLetra();
    validada = validarLetraConjunto(letra, seleccion, sensibleamayusculas);
    if (mostrarerror) {
      if (!validada) {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
  } while (!validada);
  free(editada);
  if (!sensibleamayusculas) letra = toupper(letra);
  return letra;
}

#ifdef SO_WINDOWS
#include <conio.h>
////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    char obtenerTeclaInteractiva(void)
//
//  USO:
//
//    Lee una pulsación de tecla en tiempo real (Windows).
//
//  DETALLES:
//
//    Maneja códigos extendidos para teclas de dirección.
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    Devuelve el código normalizado de la tecla pulsada.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    _getch()
//
////////////////////////////////////////////////////////////////////////////////
char obtenerTeclaInteractiva(void) {
  int caracter = _getch();
  if (caracter == 0 || caracter == 224) {
    caracter = _getch();
    switch(caracter) {
      case 72: caracter = TECLA_ARRIBA; break;
      case 80: caracter = TECLA_ABAJO; break;
      case 75: caracter = TECLA_IZQUIERDA; break;
      case 77: caracter = TECLA_DERECHA; break;
      default: caracter = TECLA_NULA;
    }
  } else {
    switch(caracter) {
      case 13: caracter = TECLA_ENTER; break;
      case 8: caracter = TECLA_RETROCESO; break;
    }
  }
  return (char)caracter;
}
#else
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int obtenerTeclaInteractiva(void)
//
//  USO:
//
//    Lee una pulsación de tecla en tiempo real (Linux/Unix).
//
//  DETALLES:
//
//    Modifica el modo del terminal para desactivar el buffer canónico y el eco.
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    Devuelve el código normalizado de la tecla pulsada.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    tcgetattr(), tcsetattr(), getchar(), fcntl()
//
////////////////////////////////////////////////////////////////////////////////
int obtenerTeclaInteractiva(void) {
  struct termios terminaloriginal, terminalnueva;
  int caracter;
  tcgetattr(STDIN_FILENO, &terminaloriginal);
  terminalnueva = terminaloriginal;
  terminalnueva.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &terminalnueva);
  caracter = getchar();
  if (caracter == ESCAPE) {
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
    int siguiente = getchar();
    if (siguiente == '[') {
      caracter = getchar();
      while ((siguiente = getchar()) != EOF && siguiente != -1);
      switch(caracter) {
        case 'A': caracter = TECLA_ARRIBA; break;
        case 'B': caracter = TECLA_ABAJO; break;
        case 'D': caracter = TECLA_IZQUIERDA; break;
        case 'C': caracter = TECLA_DERECHA; break;
        default: caracter = TECLA_NULA; break;
      }
    } else {
      if (siguiente == EOF || siguiente == -1) caracter = TECLA_ESCAPE;
      else caracter = TECLA_NULA;
    }
    fcntl(STDIN_FILENO, F_SETFL, flags);
  }
  tcsetattr(STDIN_FILENO, TCSANOW, &terminaloriginal);
  return caracter;
}
#endif
