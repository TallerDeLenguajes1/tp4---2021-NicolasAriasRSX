#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Tarea
{
    int TareaID; //Numero de iteracion
    char *Descripcion; //Breve descripcion de la tarea
    int Duracion; // entre 10 - 100
}Tareas;

void cargarTarea(Tareas ** listaTareas, int cantidadTareas);
void mostrarTareas(Tareas ** listaTareas, int cantidadTareas);

int main ()
{
    int cantTareas;
    Tareas ** tareasArreglo;
    printf("Ingrese la cantidad de tareas");
    scanf(" %d", &cantTareas);

    tareasArreglo = (Tareas **) malloc(sizeof(Tareas**) * cantTareas);

    cargarTarea(tareasArreglo, cantTareas);
    mostrarTareas(tareasArreglo, cantTareas);

    getchar();

    return 0;
}

void cargarTarea(Tareas ** listaArrTareas, int cantidadTareas)
{
    char descripcion[100];
    for (int i = 0; i < cantidadTareas; i++)
    {
        *(listaArrTareas+i)= (Tareas*)malloc(sizeof(Tareas*));
        (*(listaArrTareas + i))->TareaID= i + 1;
        (*(listaArrTareas + i))->Duracion= 10 * rand() % (100 - 10 + 1);
        printf("Ingrese la tarea %d: ", i+1);
        scanf(" %s", descripcion);
        (*(listaArrTareas + i))->Descripcion= (char *) malloc(sizeof(char) * strlen(descripcion));
        strcpy((*(listaArrTareas + i))->Descripcion, descripcion);
    }
    
}

void mostrarTareas(Tareas ** listaTareas, int cantidadTareas)
{
    printf("Listado de tareas\n");
    for (int i = 0; i < cantidadTareas; i++)
    {
        printf("Tarea numero: %d\n", i+1);
        printf("ID: %d\n", (*(listaTareas + i))->TareaID);
        printf("Descripcion: %s\n", (*(listaTareas + i))->Descripcion);
        printf("Duracion: %d\n", (*(listaTareas + i))->Duracion);
    }
    
}