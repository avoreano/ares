 # ARES Reproductor de Música

Diego Godoy 21.691.839-8
Felipe Argomedo 21.715.347-6

ARES es un reproductor de música de consola desarrollado en C++ como parte del Taller 1 de la asignatura Estructuras de Datos. El programa permite cargar un catálogo de canciones desde un archivo de texto, gestionar una lista de reproducción y controlar la reproducción mediante comandos de teclado. Implementa estructuras de datos personalizadas como listas doblemente enlazadas, pilas y colas, sin el uso de librerías STL de contenedores. El estado del reproductor se guarda automáticamente en un archivo de configuración al realizar cualquier acción.


Para la compilación y ejecución de ares, se tiene que hacer doble click en el archivo compilar.bat en el explorador de windows/linux/mac.
El script compila todos los archivos fuente y ejecuta el programa automáticamente si la compilación es exitosa.

 ## Diagrama de clases:
<img width="906" height="933" alt="diagrama de clases drawio" src="https://github.com/user-attachments/assets/12a4e477-4aa3-408e-ae79-62a2a4c1f98c" />

 ## Archivos necesarios:
Antes de ejecutar asegúrate de tener en la misma carpeta que el .exe:
music_source.txt — listado de canciones con el siguiente formato:
id,nombre,artista,album,año,duracion_segundos,ruta_archivo

 ## Funcionalidades del programa:
| Tecla |                                 Acción                                |
|-------|-----------------------------------------------------------------------|
| `W` | Reproducir / Pausar la canción actual |
| `Q` | Retroceder a la canción anterior |
| `E` | Avanzar a la canción siguiente |
| `S` | Activar / Desactivar modo aleatorio |
| `R` | Cambiar modo de repetición (Desactivado → Repetir una → Repetir todas) |
| `A` | Ver lista de reproducción actual y saltar canciones |
| `L` | Ver catálogo completo, agregar o eliminar canciones |
| `X` | Guardar estado y salir del programa |

 ## Para este proyecto se utilizo:

- Lenguaje: C++14
- Compilador: GNU GCC (MinGW)
- Sin uso de librerías STL de contenedores (`vector`, `list`, `stack`, `queue`, etc.)
