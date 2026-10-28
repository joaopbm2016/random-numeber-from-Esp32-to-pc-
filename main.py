import json
import serial

porta = "/dev/ttyUSB0"
baud = 115200

ser = serial.Serial(porta, baud)

while True:
  if ser.in_waiting > 0:
    raw_line = ser.readline()

    try:
      line = raw_line.decode('utf-8', errors='ignore').strip()

      if not line:
        continue

      data = json.loads(line)
      print(f"{data.get('numero')}\n ID: {data.get('ID')}")

    except (json.JSONDecodeError, UnicodeDecodeError):
      pass