import serial
import time

status = {'ada': None, 'capture': '0'}

ser = serial.Serial('COM5', 9600)

def collect():
    for i in range(1, 3000):
        print('lagi ambil data.....')
        print(i)
    print('finish........')
    status['ada'] = None
    ser.write(b'4')
    ser.sendBreak(duration = 5)
    print('restart........') 
    # time.sleep(2)
    status['capture'] = '0'
    ser.reset_input_buffer()

while True:

    inp = ser.readline().decode("utf-8").rstrip("\r\n")
    status['ada'] = inp
    print(status)
    
    if status['capture'] == '0':
        if status['ada'] == 'n':
            ser.write(b'4')
            ser.reset_output_buffer()
            # ser.reset_input_buffer()

        if status['ada'] == 'y':
            ser.write(b'5')
            status['capture'] = '1'
            collect()
    
