# -*- coding: utf-8 -*-
"""
Created on Sat Aug 31 17:16:57 2019

This code works with 'kalman_full.ino'
  > Connect your arduino to Serial port
  > Upload the 'kalman_full.ino' to your arduino
  > Eventually modify the port name "COM7" below to match yours
  > Run this code while your arduino transmits data

To run this correctly you need the Python libraries Serial, Numpy and Matplotlib


@author: rfetick
"""


from serial import Serial
import matplotlib.pyplot as plt
import numpy as np
import re

port = 'COM6'
baudrate = 57600

Nstate = 15
Nobs = 15

N = 150 # number of measurements
T = np.arange(N,dtype=float)
TT = np.concatenate((T,T[::-1]))

STATE = np.zeros((N,Nstate))
OBS = np.zeros((N,Nobs))
KAL = np.zeros((N,Nstate))
P = np.zeros((N,Nstate**2))

with Serial(port=port, baudrate=baudrate, timeout=1, writeTimeout=1) as port_serie:
    if port_serie.isOpen():
        port_serie.flush()
        for i in range(50):
            ligne = port_serie.readline() # remove first data
        for i in range(N):
            ligne = port_serie.readline()
            print(len(ligne))
            if((i%25)==0):
                print("Iteration %u / %u"%(i,N))
                print(ligne)
            try:
                temp = str(ligne)[2:-5]
                #print(temp)
                temp = re.findall('[-.0-9]+',temp)
                temp = [float(t) for t in temp]
                #print(temp)
                STATE[i,:] = temp[0:Nstate]
                OBS[i,:] = temp[Nstate:Nstate+Nobs]
                KAL[i,:] = temp[Nstate+Nobs:2*Nstate+Nobs]
                P[i,:] = temp[2*Nstate+Nobs:]
                
            except Exception as e:
                print(e)
                print("Exception: %s"%ligne)
        port_serie.close()


#%% PLOT RESULTS

state_names = {
    1:'Position X',
    2:'Position Y',
    3:'Position Z',
    4:'Speed X',
    5:'Speed Y',
    6:'Speed Z',
    7:'Accel X',
    8:'Accel Y',
    9:'Accel Z',
    10:'Heading X',
    11:'Heading Y',
    12:'Heading Z',
    13:'Ang. Velocity X',
    14:'Ang. Velocity Y',
    15:'Ang. Velocity Z',
}


def plot_nth_state(n, y_lwr, y_upr):
    PP = np.concatenate((KAL[:, 1] + np.sqrt(P[:, 4]), KAL[::-1, 1] - np.sqrt(P[::-1, 4])))
    plt.fill(TT, PP, color="C1", alpha=0.3)
    plt.plot(STATE[:, n], linewidth=4, label='True')
    plt.scatter(T,OBS[:,0],alpha=0.8,label='Obs')
    plt.plot(KAL[:, n], linewidth=2, label='Kalman')
    plt.legend()
    plt.xlabel("Time [iter]")
    plt.ylabel(state_names[n+1] if n+1 in state_names.keys() else 'None')
    plt.grid()
    plt.xlim(0, N)
    plt.ylim(y_lwr, y_upr)
    plt.show()


plt.figure(1)
plt.clf()

for i in range(Nstate):
    plot_nth_state(i, -10, 10)


