mkdir build
cd build
C:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -o main.gb ..\src\main.c ..\src\include\assets\sprites\TestTile.c
C:\bgb\bgb -rom main.gb