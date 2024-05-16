#include <stdio.h>
#include <stdlib.h> 

#define SALIR 3
#define NAME_SONG 99
#define MAX_SONGS 999
#define CARGAR 1
#define MOSTRAR 2

typedef struct cancion{
    char Nombre[99];
    char Artista[NAME_SONG];
    struct cancion * next;
}cancion_t; 

cancion_t * Playlist=NULL;
void menu(void);
void imprimir_cancion(cancion_t);
void pedir_datos(cancion_t * cancion);
void cargar_cancion();
void ver_lista();
void liberar_memoria(void);

int main(){
    menu();
    liberar_memoria();
    return 0;
}

void salvar_cancion(cancion_t *cancion){
    FILE *f;
    f = fopen("canciones", "a+");
    fprintf(f, "\n nombre de cancion: %s", cancion->Nombre);
    fprintf(f, "\n artista de cancion: %s", cancion->Artista);
    fclose(f);
}

void imprimir_cancion(cancion_t cancion){
    printf("Nombre: %s\n",cancion.Nombre);
    printf("Artista: %s\n",cancion.Artista);

}
void pedir_datos(cancion_t * cancion){
    printf("ingrese el nombre de la cancion:\n");
    scanf("%s",(cancion->Nombre));
    printf("ingrese el/la artista o Banda de la cancion:\n");
    scanf("%s",(cancion->Artista));

}

void menu(void){
    int opcion;
    do{
        printf("1_Cargar un nueva cancion\n");
        printf("2_Ver todas las canciones cargadas\n");
        printf("3_Salir\n");
        scanf("%d",&opcion);
        if(opcion==1)cargar_cancion();
        if(opcion==2)ver_lista();
    }while(opcion!=SALIR);
}

void cargar_cancion (){
    cancion_t *cancion_aux;
    cancion_aux = malloc(sizeof(cancion_t));

    if(cancion_aux==NULL){
        printf("Out of memory\n");
    }
    else{
        pedir_datos(cancion_aux);
        salvar_cancion(cancion_aux);
        cancion_aux->next=Playlist;
        Playlist=cancion_aux;
    }
}

void ver_lista(void){
    cancion_t *lista=Playlist;
    while(lista!=NULL){
        imprimir_cancion(*lista);
        lista=lista->next;
    }
}
void liberar_memoria(void){
    cancion_t *aux=NULL;
    while(Playlist!=NULL){
        aux=Playlist;
        Playlist=Playlist->next;
        free(aux);
    }
}

