import serial
import time
ser = serial.Serial('/dev/ttyACM0', 9600)
while 1:
    '''bad code
    for i in range(5):
        ser.write(b'0')
        time.sleep(1)
    for i in range(5):
        ser.write(b'1')
        time.sleep(1)
        '''
    for i in range (11):#0-10
        write_me = chr(i)#convert int to string
        '''bad code
        write_me = write_me.split('0')
        write_me.insert(1,str(i))
        write_me = "".join(write_me)
        if write_me == '10':#get next value after '9' not 49->48
            write_me = ':'#value after '9'
        print(write_me)#check
        '''
        write_me = bytes(write_me, 'utf-8')
        ser.write(write_me)
        time.sleep(1)
    #for i in range(10):
        #ser.write(b'0')
        #time.sleep(100)

