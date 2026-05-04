@echo off
echo Compilando ARES...

g++ -std=c++14 ^
    main.cpp ^
    classes/Cancion.cpp ^
    classes/Configuracion.cpp ^
    classes/Player.cpp ^
    core/Menu.cpp ^
    core/Playlist.cpp ^
    -o ares.exe

if %errorlevel% == 0 (
    echo.
    echo Compilacion exitosa. Iniciando ARES...
    echo.
    ares.exe
) else (
    echo.
    echo Error en la compilacion.
)

pause