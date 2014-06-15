import serial

ser = serial.Serial('/dev/ttyACM0', 9600)
connected = False
while not connected:
	ser.read()
	connected = True

result = []
open('results.txt', 'w').close()
while True:
	try:
		with open("results.txt", "a") as file:
			file.write(ser.readline())
	except Exception, e:
		print e
		continue

