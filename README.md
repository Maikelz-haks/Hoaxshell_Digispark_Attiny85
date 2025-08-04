## 📝 Descripción
> Script para **DigiSpark ATtiny85** que genera una shell inversa con permisos elevados desde una máquina Windows víctima hacia una máquina atacante, logrando evadir el firewall. 


## ⚙️ Funcionamiento
> El ataque se activa al conectar el dispositivo al puerto USB con la sesión iniciada: el DigiSpark emula un teclado e inyecta los comandos de forma automática, sin intervención del usuario, estableciendo la conexión con la máquina atacante la cual está escuchando solicitudes.


## 💻 Compatibilidad 
> Solo funciona correctamente bajo las siguientes condiciones:
- **Sistema operativo victima**: Windows 10/11
- **Sesión activa**: Escritorio desbloqueado y sesión iniciada


## ✅ Requerimientos
1. Tener instalado Arduino IDE [Ver Arduino IDE](https://www.arduino.cc/en/software/)
2. Instala los drivers que se encuentran en ruta config/drivers del repositorio (también puedes buscarlos manualmente si lo prefieres)
3. Descargar e instalar DigiStump Board 1.6.7 a traves del Boards Manager de Arduino
```
   https://raw.githubusercontent.com/digistump/arduino-boards-index/refs/heads/master/package_digistump_index.json
```
<img width="1006" height="672" alt="imagen" src="https://github.com/user-attachments/assets/8a467877-c94f-439b-af3d-14c5fcf3aba8" />

4. Este script fue creado para cambiar distribuciones de teclado, y es por esto que para que funcione debes copiar la carpeta DigisparkKeyboard del repositorio y pegarla en la siguiente ruta:
```
C:\Users\tu_usuario\AppData\Local\Arduino15\packages\digistump\hardware\avr\1.6.7\libraries\
```
*Con esto podremos cambiar la linea #define kbd_es_es del script .ino para usar la distribucion de teclado que gustes.*

5. Descargar e instalar la herramienta Hoaxshell de su repositorio oficial (Seguir los pasos del repositorio):
```
git clone https://github.com/t3l3machus/hoaxshell
```


## 🚀 Uso

### 1. Ejecutar Hoaxshell.py
```python
python3 ./hoaxshell.py -s IP_ATACANTE -r -H 'Authorization'
```

### 2. Copiar el token generado en $i y dejar ejecutandose.
![image](https://github.com/user-attachments/assets/8da49bb0-b57a-4613-9a5a-1bc4f6299157)


### 3. Abrir Arduino y seleccionar Digispark 16.5 Board.
<img width="858" height="131" alt="imagen" src="https://github.com/user-attachments/assets/3de241e0-7181-44e2-aa3a-a96a26e3e4c1" />

### 4. Dentro de Arduino, abrir el archivo .ino que se encuentra en la ruta script/script.ino del repositorio y modificar las siguientes variables:


- IP_AND_PORT_ATTACKER: Reemplazar por tu IP y puerto de atacante
- TOKEN: Reemplazar por el token generado por hoaxshell
- TOKEN_PART1: Reemplazar con la primera parte del token
- TOKEN_PART2: Reemplazar con la segunda parte del token
- TOKEN_PART3: Reemplazar con la tercera parte del token
- Opcional:  #define kbd_es_es Puedes cambiar esta linea revisando las opciones en config/DigisparkKeyboard/Readme.md

![image](https://github.com/user-attachments/assets/9418035f-eaa7-4b05-ae3b-a7bd19dd68d6)



### 5. Compilar el script y conectar el ATTINY 85. Una vez hecho esto, el USB estara listo para el ataque.
<img width="865" height="966" alt="imagen" src="https://github.com/user-attachments/assets/e729488c-4b31-4471-975f-26178ed15a8d" />



### 6. Conectar el dispositivo a la máquina victima y esperar la Respuesta. Si todo sale bien recibiremos la terminal.

   
![image](https://github.com/user-attachments/assets/5c8ce65b-5abe-4dae-a521-7f1f90dc95a5)


### 7. Pwned

