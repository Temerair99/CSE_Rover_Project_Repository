import serial
import time
ser = serial.Serial('/dev/ttyACM0', 9600)

def transmit(i):
    #print( bytes( chr(i), 'utf-8') )
    ser.write( bytes( chr(i), 'utf-8') )
    
while 1:#forever loop
    #testing
    for i in range (11):#0-10
        transmit(i)
        time.sleep(1)

