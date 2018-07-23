import serial

ser = serial.Serial('/dev/ttyACM3',9600)
s = []

while True:
    data = ser.readline()
    if data:
        s.append(data)
    if len(s) == 1:
        print s
        s = []
