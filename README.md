<br/>
<h1 align="center">GET NEXT LINE</h1>
<p align="center">
 <img tyle="display: block;-webkit-user-select: none;margin: auto;background-color: hsl(0, 0%, 90%);transition: background-color 300ms;" src="https://www.asidesigned.com/images/programming-projects-img/project-getnextline.jpg" height=50% width=50%>
</p>

 <p align="center">
    El objetivo de este proyecto es simple: programar una función que devuelva una línea leída de un file descriptor.
    <br/>
    <br/>
  </p>
</p>

## Contenido

* Sobre el proyecto
* Cómo usar
  * Compilación
* Uso
* Autor

## Sobre el proyecto

El propósito de get_next_line es leer de manera eficiente líneas de texto desde cualquier tipo de descriptor de archivo, ya sea un archivo regular, un descriptor de archivo abierto o la entrada estándar. La función debe ser capaz de manejar múltiples descriptores de archivos simultáneamente y devolver cada línea sucesivamente a medida que se llame.

### Características principales
 * Lectura de línea: La función get_next_line se encarga de leer y devolver una línea completa de texto en cada llamada. Una línea se considera como una secuencia de caracteres que finaliza con un salto de línea ('\n').

 * Soporte para múltiples descriptores de archivos: get_next_line debe ser capaz de manejar varios descriptores de archivos al mismo tiempo, lo que significa que puede leer de diferentes archivos o fuentes de entrada en paralelo.

 * Gestión de memoria: La función get_next_line debe ser capaz de manejar de manera eficiente la asignación y liberación de memoria para evitar fugas de memoria.

## Cómo usar

### Compilación
Ejecuta los siguientes comandos:

* Para compilar
```bash
make
```
* Para eliminar objetos:
```bash
make clean
```
* Para eliminar objetos y archivos binarios (programa):
```bash
make fclean
```
* Para recompilar:
```bash
make re
```
Este comando generará un archivo ejecutable get_next_line, al cual pasarle un archivo de texto para comprobarlo.

## Uso

Para utilizar get_next_line en un proyecto, primero debes compilarlo en tu programa. Luego, puedes llamar a la función pasándole el descriptor de archivo del cual deseas leer. La función devolverá una línea completa de texto cada vez que se llame, hasta que se alcance el final del archivo o se produzca un error.

Aquí hay un ejemplo de cómo se puede utilizar get_next_line:

```c
#include "get_next_line.h"

int main()
{
    int fd; // Descriptor de archivo
    char *line;

    fd = open("archivo.txt", O_RDONLY); // Abrir el archivo en modo lectura
    if (fd == -1)
    {
        // Manejo de error
        return 1;
    }

    while (get_next_line(fd, &line) > 0)
    {
        // Procesar la línea leída
        printf("%s\n", line);
        free(line);
    }

    // Cerrar el archivo
    close(fd);
    return 0;
}
```
Recuerda que debes incluir el archivo de encabezado get_next_line.h en tu programa para poder utilizar la función.

## Autor

* **Juan Guerrero** - *@juguerre - 42Málaga* - [Juan Guerrero](https://github.com/Folkenciyo/)

### ¿Puedes agregar más funciones a esta biblioteca? ¿Cómo?
* Haz un fork de este repositorio
* Clona tu fork del repositorio
* Contribuye
* Realiza un push
* Crea una solicitud de extracción (pull request) en este repositorio
* ¡Espera a que se fusionen los cambios!
 ¡Sé feliz! :)
---
## 🔗 Links
[![portfolio](https://img.shields.io/badge/portfolio-002?style=for-the-badge&logo=ko-fi&logoColor=white)](https://porfolio-juan-guerrero.vercel.app/)
[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/juanguerrerodeveloper/)
[![twitter](https://img.shields.io/badge/twitter-1DA1F2?style=for-the-badge&logo=twitter&logoColor=white)](https://twitter.com/JuanAGuerreroP1)

