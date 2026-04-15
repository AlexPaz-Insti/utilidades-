////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// ZONA DE IMPORTACIÓN: FICHEROS NECESARIOS A INCLUIR
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#include "utilidades.h"   // Mi propia colección de subprogramas útiles.



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// ZONA DE MACROS, CONSTANTES Y VARIABLES GLOBALES: PARA USO GLOBAL.
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

char MSJxERROR[] = "¡VALOR NO VÁLIDO!";
char MSJxPAUSA[] = "Pulse INTRO para continuar... ";

int codigoError; // VARIABLE GLOBAL: Visible por todos los subprogramas.



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// ZONA DE CÓDIGO: CUERPOS DE LOS SUBPROGRAMAS DECLARADOS ANTES.
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

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
//    trabajo. Es una manera de crear "sinónimos" de acciones, es decir, de
//    tener disponibles varios nombres para hacer lo mismo.
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
//      Se delega toda la carga de trabajo a esta función.
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
//    Descarta los datos de entrada pendientes en el buffer.
//
//  DETALLES:
//
//    Es un envoltorio de la función vaciarBuffer().
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
//      Delega el borrado del buffer.
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
//    Programa que espera que el usuario pulse teclas a la espera de INTRO.
//
//  DETALLES:
//
//    Se basa en un bucle que va pidiendo letras del buffer de teclado y no
//    termina hasta que detecta que ha encontrado un "INTRO" (0x10). Cualquier
//    otro código ASCII introducido por el usuario se descarta. Se produce ECO
//    de cualquier tecla pulsada.
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
//      Es el programa estándar ("prefabricado") que hace la logística de
//      comunicarse con el sistema operativo y con el hardware del teclado.
//
////////////////////////////////////////////////////////////////////////////////
void vaciarBuffer (void) {
  // ENTER CREADO EN DEFINE = ASCII(10) = 0x0A
  
  // MEDIANTE BUCLE DO-WHILE:
  char letra;
  do
  {
    letra = getchar();
  } while (letra != ENTER);
  
  // MEDIANTE BUBLE WHILE:
  // while (getchar() != '\n')   ; // Bucle vacío
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void borrarPantalla (void)
//
//  USO:
//
//    Limpia la pantalla de la terminal.
//
//  DETALLES:
//
//    Delega en limpiarPantalla para ejecutar el borrado.
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
//      Ejecuta el borrado.
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
//    Limpia la pantalla ejecutando un comando del sistema.
//
//  DETALLES:
//
//    Utiliza la función system con una macro definida externamente.
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
//      Llama al sistema operativo para limpiar la terminal.
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
//    Permite bajar el cursor en la pantalla, tantas líneas como se le indique.
//
//  DETALLES:
//
//    Crea tantas líneas en blanco como se le suministre como dato. No ubica el
//    cursor de texto en ninguna coordenada concreta, sino que genera contenido
//    en blanco en la pantalla, desplazando el punto donde se escribirá texto en
//    acciones posteriores. Utiliza para ello un bucle en cuyo interior se llama
//    a printf() con el código ASCII de salto de línea '\n' ó 0x10.
//
//  PARÁMETROS DE ENTRADA:
//
//    nlineas
//
//      Variable entera que recibirá del exterior el número de líneas en blanco
//      que se va a desplazar el cursor hacia abajo.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    printf()
//
//      Es el programa estándar ("prefabricado") que hace la logística de
//      emitir por pantalla.
//
////////////////////////////////////////////////////////////////////////////////
void bajar (int nlineas) {
  while(nlineas>0)
  {
    printf("\n");   // No se puede usar "mostrar()" porque crearíamos un bucle de llamadas.
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
//    Desplaza el cursor hacia abajo un número determinado de filas.
//
//  DETALLES:
//
//    Envoltorio de la función bajar().
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable entera que representa las filas a bajar.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar()
//
//      Efectúa el desplazamiento real.
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
//    Genera saltos de línea.
//
//  DETALLES:
//
//    Envoltorio de la función bajar().
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Número de líneas a saltar.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar()
//
//      Efectúa los saltos.
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
//    Desplaza en el eje Y (filas).
//
//  DETALLES:
//
//    Envoltorio de la función bajar().
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Cantidad de filas.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar()
//
//      Realiza el salto de líneas.
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
//    Envoltorio de la función bajar().
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Cantidad de filas.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar()
//
//      Realiza el salto de líneas.
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
//    Desplazamiento vertical en el eje de las Y.
//
//  DETALLES:
//
//    Envoltorio de la función bajar().
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Cantidad de filas.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar()
//
//      Realiza el salto de líneas.
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
//    Añade espacios en blanco para mover el cursor a la derecha.
//
//  DETALLES:
//
//    Imprime espacios vacíos en un bucle.
//
//  PARÁMETROS DE ENTRADA:
//
//    ncolumnas
//
//      Número de espacios a indentar.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    printf()
//
//      Imprime los espacios en la salida estándar.
//
////////////////////////////////////////////////////////////////////////////////
void indentar (int ncolumnas) {
  for(int i=0; i<ncolumnas; i++)
  {
    printf(" ");   // No se puede usar "mostrar()" porque crearíamos un bucle de llamadas.
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
//    Mueve el cursor hacia la derecha.
//
//  DETALLES:
//
//    Envoltorio de la función indentar().
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//
//      Número de columnas a avanzar.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar()
//
//      Añade los espacios en la misma línea.
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
//    Inserta espacios a modo de tabulación.
//
//  DETALLES:
//
//    Envoltorio de la función indentar().
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//
//      Cantidad de espacios.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar()
//
//      Maneja la inserción de espacios.
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
//    Desplaza en el eje X (columnas).
//
//  DETALLES:
//
//    Envoltorio de la función indentar().
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//
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
//      Genera la distancia horizontal.
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
//    Desplazamiento horizontal.
//
//  DETALLES:
//
//    Envoltorio de la función indentar().
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//
//      Distancia horizontal.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar()
//
//      Imprime los espacios necesarios.
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
//    Desplazamiento en la horizontal.
//
//  DETALLES:
//
//    Envoltorio de la función indentar().
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//
//      Cantidad de espacios.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar()
//
//      Proporciona el desplazamiento real.
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
//    Coloca el cursor en una posición relativa dada por filas y columnas.
//
//  DETALLES:
//
//    Usa bajar e indentar de forma consecutiva.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Saltos de línea a efectuar.
//
//    ncols
//
//      Espacios a insertar en la línea destino.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar()
//
//      Baja el cursor verticalmente.
//
//    tabular()
//
//      Mueve el cursor a la derecha en la nueva línea.
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
//    Desplaza las coordenadas del cursor.
//
//  DETALLES:
//
//    Envoltorio de la función posicionar().
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Eje vertical.
//
//    ncols
//
//      Eje horizontal.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    posicionar()
//
//      Sitúa el cursor relacionalmente.
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
//    Desplaza el cursor en ejes X e Y.
//
//  DETALLES:
//
//    Envoltorio de la función posicionar().
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Componente Y.
//
//    ncols
//
//      Componente X.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    posicionar()
//
//      Lleva a cabo la ubicación final.
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
//    Pausa el flujo del programa por segundos de manera ineficiente (bucles).
//
//  DETALLES:
//
//    No debe usarse en entornos críticos ya que quema ciclos de CPU.
//
//  PARÁMETROS DE ENTRADA:
//
//    segundosmax
//
//      Valor objetivo de segundos aproximados a esperar.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    NO DEPENDE DE OTRAS FUNCIONES INTERNAS.
//
////////////////////////////////////////////////////////////////////////////////
void retardoSegundos (int segundosmax) {
  // POSIBILIDAD: Poner en función de la que usa milisegundos.
  
  // AJUSTAR CEROS DE LOS BUCLES PARA APROXIMAR EL PERIODO.

  for(int nseg=0; nseg < segundosmax ; nseg++)
  {
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
//    Pausa la ejecución en base a una aproximación a milisegundos usando bucles.
//
//  DETALLES:
//
//    Al igual que retardoSegundos, quema CPU y su exactitud depende de la máquina.
//
//  PARÁMETROS DE ENTRADA:
//
//    milisegundosmax
//
//      Cantidad de ciclos en escala milisegundo a iterar.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    NO DEPENDE DE OTRAS FUNCIONES INTERNAS.
//
////////////////////////////////////////////////////////////////////////////////
void retardoMilisegundos (int milisegundosmax) {
  int i, j;
  
  // AJUSTAR CEROS DE LOS BUCLES PARA APROXIMAR EL PERIODO.

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
//    Espera un tiempo exacto evaluando el reloj interno del sistema.
//
//  DETALLES:
//
//    Más preciso que los bucles vacíos al usar la librería time.
//
//  PARÁMETROS DE ENTRADA:
//
//    milisegundos
//
//      Tiempo de espera requerido.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    clock()
//
//      Obtiene los ticks de reloj de la CPU.
//
////////////////////////////////////////////////////////////////////////////////
void retrasoMilisegundos (int milisegundos) {
  double e = 0;

  clock_t t0 = clock();   // clock_t es un tipo interno equivalente a UINT32.
  
  do
  {
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
//    Pone el hilo en suspensión real (Sleep/sleep) permitiendo liberar CPU.
//
//  DETALLES:
//
//    Contiene bifurcaciones de compilador para funcionar en Windows o Unix.
//
//  PARÁMETROS DE ENTRADA:
//
//    segundos
//
//      Tiempo en segundos que se pausará el programa.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    Sleep() / sleep()
//
//      Llamadas a sistema para suspender la ejecución.
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
//    Pone en suspensión el proceso durante milisegundos reales.
//
//  DETALLES:
//
//    Usa Sleep en Windows y usleep en Linux/Unix.
//
//  PARÁMETROS DE ENTRADA:
//
//    milisegundos
//
//      Cantidad de milisegundos de suspensión.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    Sleep() / usleep()
//
//      Suspenden el hilo usando las llamadas del S.O.
//
////////////////////////////////////////////////////////////////////////////////
void esperarMilisegundos (int milisegundos) {
  #ifdef SO_WINDOWS
    Sleep(milisegundos);
  #else
    usleep(milisegundos*1000);   // Alternativa: nanosleep() de "time.h".
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
//    Detiene la pantalla mostrando el mensaje genérico y espera un INTRO.
//
//  DETALLES:
//
//    Utiliza una indentación por defecto de 1 salto y 2 espacios horizontales.
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
//      Invocada con valores predeterminados para la posición.
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
//    Muestra un texto de pausa estándar en las coordenadas relativas provistas.
//
//  DETALLES:
//
//    Delega a pausaGenerica() enviando la constante MSJxPAUSA.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Distancia de filas relativas.
//
//    ncols
//
//      Espaciado horizontal para el texto.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    pausaGenerica()
//
//      Construye efectivamente el proceso de pausa.
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
//    Pide una pausa tras mostrar un texto configurado en coordenadas relativas.
//
//  DETALLES:
//
//    Involucra mostrar el mensaje con posición personalizada e invocar la espera
//    de la pulsación de la tecla INTRO.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Cadena de texto a mostrar antes de la pausa.
//
//    nfils
//
//      Posición Y.
//
//    ncols
//
//      Posición X.
//
//    nuevalinea
//
//      Bandera para imprimir un enter adicional.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y()
//
//      Imprime el texto formateado.
//
//    esperarINTRO()
//
//      Vacía el buffer y aguarda al usuario.
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
//    Muestra un texto de manera directa, finalizando con un salto automático.
//
//  DETALLES:
//
//    Envoltorio simple de la función puts().
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      El arreglo de caracteres (texto) que se desea enviar a la terminal.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    puts()
//
//      Función estándar para imprimir cadenas con salto de línea.
//
////////////////////////////////////////////////////////////////////////////////
void texto (char msjtxt[]) {
  puts(msjtxt);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void separar ()
//
//  USO:
//
//    Crea una separación visual mediante salto de línea simple.
//
//  DETALLES:
//
//    Envía directamente un \n a mostrar().
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
//      Imprime el salto de línea.
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
//    Avanza el cursor al principio de la línea inferior.
//
//  DETALLES:
//
//    Utiliza saltar con valor 1.
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
//      Realiza el salto exacto.
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
//    Muestra un mensaje en la posición actual del cursor.
//
//  DETALLES:
//
//    Configura mostrar_x_y a 0,0 para que no haya desplazamiento previo.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      La cadena a mostrar en pantalla.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mostrar_x_y()
//
//      Gestiona la impresión base.
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
//    Muestra una cadena desplazándose de la posición base en filas y columnas.
//
//  DETALLES:
//
//    Llama a mensaje_x_y pasando FALSE en la bandera de salto final de línea.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Cadena texto original.
//
//    nfils
//
//      Desplazamiento vertical.
//
//    ncols
//
//      Desplazamiento horizontal.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y()
//
//      Centraliza la impresión desplazada.
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
//    Sinónimo semántico de mostrar para un texto plano, sin salto final.
//
//  DETALLES:
//
//    Utiliza parámetros a ceros para obviar posicionamientos previos.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Texto a reflejar.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    escribir_x_y()
//
//      Maneja la acción enviando los ceros explícitos.
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
//    Sinónimo de mostrar_x_y.
//
//  DETALLES:
//
//    Llama directamente a mensaje_x_y indicando no hacer nueva línea al final.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Cadena contenedora de caracteres.
//
//    nfils
//
//      Saltos pre-impresión.
//
//    ncols
//
//      Tabulaciones pre-impresión.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y()
//
//      Concentrador principal de impresión y posicionamiento.
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
//    Imprime sin afectar posiciones extra ni salto de línea.
//
//  DETALLES:
//
//    Sinónimo adicional por convención de nombres.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Mensaje objetivo.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    imprimir_x_y()
//
//      Delega enviando 0 desplazamientos.
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
//    Imprime con coordenadas relativas y sin salto.
//
//  DETALLES:
//
//    Aplica llamada a mensaje_x_y omitiendo la bandera final.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      El propio mensaje a renderizar.
//
//    nfils
//
//      Líneas bajadas previas.
//
//    ncols
//
//      Espacios introducidos previos.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y()
//
//      Función unificada de salida.
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
//    Envía texto a las coordenadas especificadas relativas.
//
//  DETALLES:
//
//    Otra envoltura más para unificar los nombres en la librería a conveniencia.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Contenido del texto.
//
//    nfils
//
//      Margen superior relativo.
//
//    ncols
//
//      Margen izquierdo relativo.
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y()
//
//      Ejecuta el bloque común subyacente.
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
//    Función central de renderizado por terminal que soporta posicionamiento y
//    finalización flexible.
//
//  DETALLES:
//
//    Acumula las acciones base de bajar(), tabular() y usa un if para generar
//    un salto en caso de que la variable booleana sea verdadera.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      La información principal a pintar en consola.
//
//    nfils
//
//      Eje de las ordenadas en saltos de línea.
//
//    ncols
//
//      Eje de las abscisas en espacios vacíos de caracter simple.
//
//    nuevalinea
//
//      Decide (TRUE) si al finalizar se hace salto de carro o se queda a la
//      espera en la misma línea (FALSE).
//
//  VALOR DE SALIDA:
//
//    NO GENERA NINGÚN VALOR DE SALIDA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    saltar()
//
//      Desplaza verticalmente.
//
//    tabular()
//
//      Desplaza horizontalmente.
//
//    printf()
//
//      Primitiva C estándar.
//
////////////////////////////////////////////////////////////////////////////////
void mensaje_x_y (char msjtxt[], int nfils, int ncols, boolean nuevalinea) {
  saltar(nfils);
  tabular(ncols);
  printf("%s", msjtxt);
  
  if (nuevalinea) printf("\n");   // ALTERNATIVA: if (nuevalinea)  putchar(ENTER);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void iniciaAleatorizador (void)
//
//  USO:
//
//    Prepara el motor interno de C para emitir números pseudo-aleatorios usando
//    el reloj de sistema como semilla base.
//
//  DETALLES:
//
//    Se debe llamar idealmente solo una vez al principio del programa.
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
//    srand()
//
//      Siembra la base matemática para la pseudo-aleatoriedad.
//
//    time()
//
//      Obtiene el tiempo actual para asegurar disparidad de semilla.
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
//    Aporta una cantidad entera entre cero y un límite estricto superior.
//
//  DETALLES:
//
//    Usa la operación módulo sobre rand() para acotar los resultados.
//
//  PARÁMETROS DE ENTRADA:
//
//    limite
//
//      Cota máxima inalcanzable. El valor devuelto siempre es estrictamente
//      inferior a este entero.
//
//  VALOR DE SALIDA:
//
//    Devuelve un int que supone la variable aleatoria calculada.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    rand()
//
//      Aporta un int aleatorio entre cero y RAND_MAX.
//
////////////////////////////////////////////////////////////////////////////////
int generaAleatorioEntero (int limite) {
  // Generará un número entre 0 y limite - 1, nunca llega a limite.
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
//    Sustitución mejorada de scanf() que impide que queden letras almacenadas
//    en el buffer de teclado para posteriores operaciones de entrada de datos.
//
//  DETALLES:
//
//    La función scanf() no retira el código ASCII de la letra INTRO del buffer
//    de teclado ni posibles letras después de un texto que se pueda convertir
//    en una cantidad. Nos ayudamos de otra función creada en esta librería,
//    vaciarBuffer() para ello. No muestra ningún mensaje por pantalla.
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    Devuelve al exterior el valor entero que a su vez ha recibido en la
//    variable "valor" de la función scanf(), mediante paso por referencia.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    scanf()
//
//      Es el programa estándar ("prefabricado") que hace la logística de
//      leer caracteres del teclado y convertirlos en la cantidad entera.
//
//    vaciarBuffer()
//
//      Limpieza para asegurar que no hay remanentes asíncronos en el buffer.
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
//    char obtenerCaracterASCII (void)
//
//  USO:
//
//    Lee y extrae un solo caracter ASCII válido ingresado por terminal.
//
//  DETALLES:
//
//    Redirecciona hacia obtenerLetra() como sinónimo conceptual.
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    Devuelve una variable tipo char conteniendo el valor ASCII leído, o nulo
//    si es inválido.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    obtenerLetra()
//
//      Contiene la verificación real del tipo y limpieza de buffer.
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
//    Lee una letra limpia desde el input estándar y filtra valores complejos.
//
//  DETALLES:
//
//    Obtiene la captura con getchar() y se asegura de que caiga bajo el rango
//    de los ASCII 128 válidos. Si no, retorna '\0'. Finalmente vacía el buffer.
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    Devuelve char validado por rango en ASCII.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    getchar()
//
//      Trae la letra primigenia pulsada.
//
//    vaciarBuffer()
//
//      Descarta cualquier cosa tecleada accidentalmente posterior al primer hit.
//
////////////////////////////////////////////////////////////////////////////////
char obtenerLetra (void) {
  char letra, valida;
  
  letra = getchar();
  
  if (letra < 128) valida = letra; // Devolveremos la letra
  else valida = '\0';  // Devolveremos la letra nula.
  
  // VACIAMOS POSIBLES CÓDIGOS EN EL BUFFER.
  //   Se incluye el INTRO EXTRA y una posible escritura de múltiples letras.
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
//    Muestra un mensaje en pantalla para pedir un dato entero al usuario. El
//    mensaje es configurable y desplazable un número de caracteres desde la
//    izquierda de la pantalla.
//
//  DETALLES:
//
//    Es como un printf() más un scanf(), mejorados. Puede desplazarse el texto
//    recibido mediante un segundo dato entero. También impide problemas del
//    buffer de teclado con scanf(). Para ello, delega el emitir el mensaje por
//    pantalla a las funciones mensaje() y mostrar(), y la toma del dato entero a la
//    función obtenerEntero().
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Variable de tipo vector de caracteres donde se recibirá el texto que se
//      debe mostrar, que debe ser una cadena terminada en '\0'.
//
//    ncols
//
//      Variable entera donde se recibirá del exterior el número de espacios en
//      blanco a añadir antes del mensaje.
//
//  VALOR DE SALIDA:
//
//    Devuelve al programa donde se invoque, un valor entero que a su vez esta
//    función ha recibido desde la función obtenerEntero().
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje()
//
//      Se encarga efectivamente de mostrar el mensaje desplazado.
//
//    mostrar()
//
//      Usada para añadir en pantalla un texto adicional después del mensaje.
//
//    obtenerEntero()
//
//      Es la función que se encarga en la práctica de obtener la cantidad.
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
//    Fuerza a la obtención de un número que sea no negativo por parte del usuario.
//
//  DETALLES:
//
//    Itera en un bucle do-while en el cual, de introducir un número negativo, 
//    advierte de manera visual bajo el texto de petición apoyado en la constante
//    MSJxERROR.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Texto principal para la pregunta.
//
//    ncols
//
//      Indentación aplicada.
//
//    mostrarerror
//
//      Bandera para activar la traza visual de texto en caso de que el usuario
//      infrinja la regla del dominio positivo.
//
//  VALOR DE SALIDA:
//
//    Un entero validado como mayor o igual a 0.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje() / mostrar() / nuevaLinea() / mensaje_x_y()
//
//      Bloques de interfaz de texto.
//
//    obtenerEntero()
//
//      El concentrador que toma efectivamente la cifra final.
//
////////////////////////////////////////////////////////////////////////////////
int pedirEnteroPositivo (char msjtxt[], int ncols, boolean mostrarerror) {
  int num;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    mostrar(": ");
    num = obtenerEntero();
    
    if (mostrarerror)
    {
      if (num < 0)
      {
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
//    Solicita al humano que alimente un input acotado en un rango cerrado.
//
//  DETALLES:
//
//    Controla robustamente mediante bucle do-while las entradas fuera de las 
//    restricciones dadas.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Cadena literal preguntada.
//
//    ncols
//
//      Desplazamiento a derecha del texto.
//
//    mostrarerror
//
//      Activa o desactiva la retroalimentación visible del error al equivocarse.
//
//    min
//
//      Límite inferior inclusivo.
//
//    max
//
//      Límite superior inclusivo.
//
//  VALOR DE SALIDA:
//
//    Devuelve un int que cumple con la regla relacional min <= int <= max.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje() / nuevaLinea() / mensaje_x_y()
//
//      Toda la logística de UI.
//
//    obtenerEntero()
//
//      El extractor validado de cifras subyacente.
//
////////////////////////////////////////////////////////////////////////////////
int pedirEnteroIntervalo (char msjtxt[], int ncols, boolean mostrarerror, int min, int max) {
  int num;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    printf(" [%d,%d]: ", min, max);
    
    num = obtenerEntero();
    
    if (mostrarerror)
    {
      if (num < min || num > max)
      {
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
//    Requiere al usuario presionar una letra en particular.
//
//  DETALLES:
//
//    Mantiene atrapado al flujo de control hasta que no se entregue exactamente
//    el caracter ASCII demandado como cuarto parámetro.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Mensaje base informativo.
//
//    ncols
//
//      Desplazamiento horizontal.
//
//    mostrarerror
//
//      Activa el texto de aviso en caso de error o mismatch.
//
//    letra
//
//      El caracter específico y exclusivo que desbloquea el flujo.
//
//  VALOR DE SALIDA:
//
//    Devuelve la misma letra (convertida a mayúscula) que servía como target.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    toupper()
//
//      Normalizador estándar para homogeneizar cotejo obviando caps lock.
//
//    mensaje() / mostrar() / nuevaLinea() / mensaje_x_y()
//
//      Pila UI.
//
//    obtenerLetra()
//
//      La lectura física protegida.
//
////////////////////////////////////////////////////////////////////////////////
int pedirLetra (char msjtxt[], int ncols, boolean mostrarerror, char letra) {
  char pedida;
  
  letra = toupper(letra);
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    mostrar(": ");
    
    pedida = obtenerLetra();
    pedida = toupper(pedida);   // Convertimos a mayúsculas para simplificar casos.
    
    if (mostrarerror)
    {
      if (letra != pedida)
      {
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
//    Aplica la típica rutina de pregunta S/N (SI o NO) de una interfaz interactiva.
//
//  DETALLES:
//
//    Garantiza que la respuesta se ciñe a las macros de constante predefinidas
//    en el header utilidades para las respuestas dicotómicas afirmativo/negativo.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Planteamiento de la decisión al usuario.
//
//    ncols
//
//      Columnas a separar del margen de la consola.
//
//    mostrarerror
//
//      Bandera para advertir error de tipeo.
//
//  VALOR DE SALIDA:
//
//    Un char que refleja de manera garantizada la macro SI o NO provistas.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje() / nuevaLinea() / mensaje_x_y()
//
//      Interacciones por pantalla.
//
//    obtenerLetra() / toupper()
//
//      Lector y normalizador a upper case para que cotejen las macros.
//
////////////////////////////////////////////////////////////////////////////////
int pedirConfirmacion (char msjtxt[], int ncols, boolean mostrarerror) {
  char letra;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    printf(" [%c/%c]: ", SI, NO);
    
    letra = obtenerLetra();
    letra = toupper(letra);   // Convertimos a mayúsculas para simplificar casos.
    
    if (mostrarerror)
    {
      if (letra != SI && letra != NO)
      {
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
//    Verifica que dos letras sean equivalentes dadas las reglas de capitalización.
//
//  DETALLES:
//
//    Se apoya en toupper para desensibilizar si así se solicita.
//
//  PARÁMETROS DE ENTRADA:
//
//    original
//
//      Caracter base a evaluar como correcto.
//
//    dada
//
//      Caracter candidato sujeto de escrutinio.
//
//    sensibleamayusculas
//
//      Condición booleana de evaluación estricta (TRUE).
//
//  VALOR DE SALIDA:
//
//    Devuelve tipo boolean (TRUE) si es un hit o de lo contrario (FALSE).
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    toupper()
//
//      Aplica la coerción en caso de desensibilización alfanumérica.
//
////////////////////////////////////////////////////////////////////////////////
boolean validarLetraUnica (char original, char dada, boolean sensibleamayusculas) {
  if (!sensibleamayusculas)
  {
    original = toupper(original);
      dada   = toupper(dada);
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
//    Contrasta que una letra dada pertenezca al pool de letras proporcionado en
//    un array de opciones permitidas.
//
//  DETALLES:
//
//    Itera el arreglo buscando un hit en conjunto, delegando la comparación final
//    uno a uno en la función validarLetraUnica.
//
//  PARÁMETROS DE ENTRADA:
//
//    letra
//
//      La letra bajo auditoría.
//
//    seleccion[]
//
//      Array / String de caracteres habilitados como posibles respuestas.
//
//    sensibleamayusculas
//
//      Booleano que transfiere la cualidad de match exacto al evaluador final.
//
//  VALOR DE SALIDA:
//
//    Genera TRUE si la letra pertenece al conjunto en base a los criterios; de 
//    lo contrario arroja FALSE.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    strlen()
//
//      Mide el espacio a iterar dentro del pool.
//
//    validarLetraUnica()
//
//      Módulo de decisión terminal por unidad.
//
////////////////////////////////////////////////////////////////////////////////
boolean validarLetraConjunto (char letra, char seleccion[], boolean sensibleamayusculas) {
  boolean resultado = FALSE;
  int largo = strlen(seleccion);
  
  for(int i = 0; i < largo ; i++)
  {
    if (validarLetraUnica(letra, seleccion[i], sensibleamayusculas))
    {
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
//    Crea un texto dinámicamente inyectando slashes ('/') entre los caracteres.
//
//  DETALLES:
//
//    Asigna memoria en el heap empleando malloc, por lo que el objeto retornado
//    debe ser liberado posteriormente con un free() desde donde se reciba el
//    puntero, para evitar fugas (memory leaks).
//
//  PARÁMETROS DE ENTRADA:
//
//    entrada[]
//
//      Un string base conteniendo el crudo de las letras.
//
//  VALOR DE SALIDA:
//
//    Devuelve un puntero de tipo char* apuntando al bloque generado y formateado.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    strlen()
//
//      Computa la longitud de bytes necesarios antes de formatear.
//
//    malloc()
//
//      Petición dinámica de bloque RAM.
//
////////////////////////////////////////////////////////////////////////////////
char *cadenaOpcionesDisponibles (char entrada[]) {
  if (entrada == NULL) return NULL;   // Si no dan nada, petas máximus ...
  
  char *textoinicial, *textofinal;
  
  textoinicial = entrada;
  
  int largoinicial, largofinal;
  
  largoinicial = strlen(textoinicial);

  if (largoinicial == 0)
  {
    // Nos dan cadena vacía, así que generamos vacía. Pero consideramos el '\0'.
    largofinal = 1;
    textofinal = (char *) malloc(1*sizeof(char));
    textofinal[0] = '\0';
  }
  else
  {
    // CASO 1: "A" -> "A" => largo 2 = 1 (letra) + 1 ('\0')
    // CASO 2: "ABC" -> "A/B/C" => largo 6 = 3 (letras) + 2 (sepadores) +1 ('\0'); 
    largofinal = 2 * largoinicial;
    textofinal = (char *) malloc(largofinal*sizeof(char));
    
    if (textofinal != NULL)
    {
      int j = 0;
      for (int i = 0; i < largoinicial; i++, j++)
      {
        textofinal[j] = textoinicial[i];
        j++;
        textofinal[j] = '/';
      }
      
      // Sustituimos la última '/' por un ' 0'.
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
//    Crea un prompt estructurado de selección múltiple (tipo menú corto de letras).
//
//  DETALLES:
//
//    Emplea cadenaOpcionesDisponibles para embellecer visualmente el pool de 
//    selecciones de forma A/B/C y después evalúa con validarLetraConjunto. Libera
//    la memoria solicitada antes de la salida.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      El requerimiento textual.
//
//    ncols
//
//      Columnas a empujar como indentado de la pregunta.
//
//    mostrarerror
//
//      Bandera activa/inactiva para reportar si se sale del pool.
//
//    seleccion[]
//
//      Conjunto estricto de carácteres que admiten una respuesta exitosa.
//
//    sensibleamayusculas
//
//      Evaluación literal de coincidencia de char con su caso.
//
//  VALOR DE SALIDA:
//
//    Devuelve un entero (char implícito) con la respuesta admitida y validada.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    cadenaOpcionesDisponibles()
//
//      Crea temporalmente el formato amigable.
//
//    mensaje() / mostrar() / nuevaLinea() / mensaje_x_y() / printf()
//
//      Bloque de interfaz terminal.
//
//    obtenerLetra() / validarLetraConjunto() / toupper()
//
//      Control lógico de la extracción de información y la comprobación.
//
//    free()
//
//      Liberador de RAM dinámico.
//
////////////////////////////////////////////////////////////////////////////////
int pedirLetraSeleccion (char msjtxt[], int ncols, boolean mostrarerror, char seleccion[], boolean sensibleamayusculas) {
  // HACER: Evitar que falle con «seleccion» a valor NULL.
  
  // Usar «cadenaOpcionesDisponibles()» implica luego liberar memoria con «free()».
  char *editada = cadenaOpcionesDisponibles(seleccion);
  
  char letra;
  
  boolean validada;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    mostrar(" [");
    printf("%s", editada);
    mostrar("]: ");
    
    letra = obtenerLetra();

    validada = validarLetraConjunto(letra, seleccion, sensibleamayusculas);
    
    if (mostrarerror)
    {
      if (!validada)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
  } while (!validada);
  
  // Liberamos la memoria para cadena modificada.
  free(editada);
  
  // Si no era sensible a mayúsculas, siempre la devolvemos mayúscula.
  if (!sensibleamayusculas) letra = toupper(letra);
  
  return letra;
}



#ifdef SO_WINDOWS

#include <conio.h>

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    char obtenerTeclaInteractiva (void)
//
//  USO:
//
//    Captura la presión en tiempo real de una tecla (modo bloqueante normalizado)
//    y soporta teclas extendidas direccionales en entornos Windows.
//
//  DETALLES:
//
//    Sortea el esquema de teclas multi-carácter de Windows usando getch con la
//    librería conio precompilada del SO.
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    Devuelve el tipo char normalizado mapeado a los inputs del teclado 
//    usando constantes personalizadas como TECLA_ARRIBA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    _getch()
//
//      Obtiene pulsaciones crudas omitiendo cualquier buffer o eco previo.
//
////////////////////////////////////////////////////////////////////////////////
char obtenerTeclaInteractiva(void) {
  int caracter = _getch();   // En Windows, getch() ya es bloqueante por defecto.

  if (caracter == 0 || caracter == 224)
  {
    // Tecla especial, depende de un segundo código. Lo leemos.
    caracter = _getch();
    
    switch(caracter)
    {
      case 72: caracter = TECLA_ARRIBA;    break;   // Flecha Arriba
      case 80: caracter = TECLA_ABAJO;     break;   // Flecha Abajo
      case 75: caracter = TECLA_IZQUIERDA; break;   // Flecha Izquierda
      case 77: caracter = TECLA_DERECHA;   break;   // Flecha Derecha
      default: caracter = TECLA_NULA;               // Tecla nula.
    }
  }
  else
  {
    // Normalización de teclas conflictivas no estándar.
    switch(caracter)
    {
      case 13: caracter = TECLA_ENTER;
      case 8:  caracter = TECLA_RETROCESO;
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
//    int obtenerTeclaInteractiva (void)
//
//  USO:
//
//    Captura interactivamente teclas directas incluyendo extendidas (como flechas)
//    sin aguardar por la pulsación de la confirmación Enter, en Linux/Unix.
//
//  DETALLES:
//
//    Modifica temporalmente los flags del TTY (TeleTYpewriter) para deshabilitar
//    el modo canónico. Adicionalmente procesa las secuencias ESC '[ X ' de 3 bytes
//    correspondientes a las macros especiales, restableciendo la terminal después.
//
//  PARÁMETROS DE ENTRADA:
//
//    NO RECIBE VALORES DE ENTRADA.
//
//  VALOR DE SALIDA:
//
//    Un código numérico normalizado y constante dependiente del archivo cabecera, 
//    representativo de la tecla obtenida.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    tcgetattr() / tcsetattr()
//
//      Obtiene y actualiza parámetros POSIX de la estructura termios.
//
//    getchar()
//
//      Rutina que drena la secuencia tecleada real.
//
//    fcntl()
//
//      Manipulador de archivos para cambiar flags a no-bloqueante por un instante.
//
////////////////////////////////////////////////////////////////////////////////
int obtenerTeclaInteractiva(void) {
  struct termios terminaloriginal, terminalnueva;
  int caracter;

  // 1. Obtenemos la configuración actual de la terminal.
  tcgetattr(STDIN_FILENO, &terminaloriginal);
  terminalnueva = terminaloriginal;

  // 2. Desactivamos el modo canónico (espera de INTRO) y el ECO (ver la tecla al pulsar).
  terminalnueva.c_lflag &= ~(ICANON | ECHO); // Quitamos espera de INTRO y eco
  tcsetattr(STDIN_FILENO, TCSANOW, &terminalnueva);
  
  // 3. El programa se detiene aquí hasta recibir un carácter.
  // Las flechas envían una secuencia de escape: 27 (ESC), 91 ('['), y una letra.
  caracter = getchar();
  
  if (caracter == ESCAPE)
  {
    // Cambiamos a NO BLOQUEANTE un instante para ver si hay bytes extra
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
    
    // Pedimos a ver si hay otro caracter.
    int siguiente = getchar();
    
    // ¿Es '[' (91)?
    if (siguiente == '[')
    {
      // Lo desechamos simplemente no usando "siguiente".

      // Pedimos el tercer código de caracter generado.
      caracter = getchar();
      
      while ((siguiente = getchar()) != EOF && siguiente != -1);

      switch(caracter)
      {
        case 'A': caracter = TECLA_ARRIBA;    break;   // Flecha Arriba
        case 'B': caracter = TECLA_ABAJO;     break;   // Flecha Abajo
        case 'D': caracter = TECLA_IZQUIERDA; break;   // Flecha Izquierda
        case 'C': caracter = TECLA_DERECHA;   break;   // Flecha Derecha
        default:  caracter = TECLA_NULA;      break;
      }
    }
    else
    {
      if (siguiente == EOF || siguiente == -1) caracter = TECLA_ESCAPE;
      else caracter = TECLA_NULA;
    }

    // Restauramos el modo BLOQUEANTE de la terminal.
    fcntl(STDIN_FILENO, F_SETFL, flags);
  }

  // 4. Restauramos la configuración original antes de salir.
  tcsetattr(STDIN_FILENO, TCSANOW, &terminaloriginal);
  
  return caracter;
}

#endif
