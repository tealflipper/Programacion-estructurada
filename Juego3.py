# -*- coding: utf-8 -*-
from time import sleep
import math
def angulo (t,x) :#convertimos un angulo dado a pendiente
    y=math.radians(t)#convierte el angulo a radianes
    y=math.tan(y)*x
    return y

intentos=int(input("Numero de intentos: "))
base=15 #base del limite del tablero
altura=15
x=0
y=0
meowx=33#posicion x de objetivo
meowy=34#posicion y de objetivo
esLimite=True
hit=False
print("\033[" + str(meowy) + ";" + str(meowx) + "H", end='')
print("<[:{v")
for i in range (intentos+1):
    n=int(input("angulo: "))
    while x<=base and esLimite:
        sleep(0.5)
        if y<altura:
            y=round(angulo(n,x))
            if meowx==x and meowy==y:
                hit=True
                esLimite=False
            print("\033[2J")
            print("\033[" + str(y) + ";" + str(x) + "H", end='') #Mueve el cursor.
            print("*")
            print("\033[" + str(meowy) + ";" + str(meowx) + "H", end='')
            print(":'v'")
            x=x+1
        else:
            esLimite=False
        print(x,y)
if hit:
    print("¡¡¡¡¡Exito!!!!!")
else:
    print("Fracaso :'v'")