import numpy as np
import matplotlib.pylab as plt
filename = "euler.dat"
x=np.loadtxt(filename, usecols=0)
y=np.loadtxt(filename, usecols=1)
w=np.loadtxt(filename, usecols=2)
filename = "leapfrog.dat"
x2=np.loadtxt(filename, usecols=0)
y2=np.loadtxt(filename, usecols=1)
w2=np.loadtxt(filename, usecols=2)
filename = "rk4.dat"
x1=np.loadtxt(filename, usecols=0)
y1=np.loadtxt(filename, usecols=1)
w1=np.loadtxt(filename, usecols=2)

plt.figure(figsize=(10,10))
plt.subplot(3,3,1)
plt.title('Euler')
plt.xlabel('Tiempo')
plt.ylabel('Posicion')
plt.plot(x,y)
plt.xlim(0,4*np.pi)
plt.ylim(-1.5,1.5)
plt.subplot(3,3,4)
plt.xlabel('Tiempo')
plt.ylabel('Velocidad')
plt.plot(x,w)
plt.xlim(0,4*np.pi)
plt.ylim(-1.5,1.5)
plt.subplot(3,3,7)
plt.xlabel('Posicion')
plt.ylabel('Velocidad')
plt.plot(y,w)
plt.xlim(-2,2)
plt.ylim(-2,2)

plt.subplot(3,3,2)
plt.title('RK')
plt.xlabel('Tiempo')
plt.ylabel('Posicion')
plt.xlim(0,4*np.pi)
plt.ylim(-1.5,1.5)
plt.plot(x1,y1,c='green')
plt.subplot(3,3,5)
plt.xlabel('Tiempo')
plt.ylabel('Velocidad')
plt.xlim(0,4*np.pi)
plt.ylim(-1.5,1.5)
plt.plot(x1,w1,c='green')
plt.subplot(3,3,8)
plt.xlabel('Posicion')
plt.ylabel('Velocidad')
plt.plot(y1,w1,c='green')
plt.xlim(-2,2)
plt.ylim(-2,2)

plt.subplot(3,3,3)
plt.title('LeapFrog')
plt.xlabel('Tiempo')
plt.ylabel('Posicion')
plt.plot(x2,y2,c='orange')
plt.xlim(0,4*np.pi)
plt.ylim(-1.5,1.5)
plt.subplot(3,3,6)
plt.xlabel('Tiempo')
plt.ylabel('Velocidad')
plt.plot(x2,w2,c='orange')
plt.xlim(0,4*np.pi)
plt.ylim(-1.5,1.5)
plt.subplot(3,3,9)
plt.xlabel('Posicion')
plt.ylabel('Velocidad')
plt.plot(y2,w2,c='orange')
plt.xlim(-2,2)
plt.ylim(-2,2)
plt.savefig('grafica.png')