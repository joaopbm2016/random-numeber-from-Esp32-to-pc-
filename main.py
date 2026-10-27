import json
import serial

ser = serial.Serial('/dev/ttyUSB0', 9600)

while True:
    if ser.in_waiting > 0:
        line = ser.readline().decode('utf-8').rstrip()
        data = json.loads(line)
        print(data)