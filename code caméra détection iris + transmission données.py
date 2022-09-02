# Untitled - By: CLOAREC - jeu. avr. 14 2022

import sensor, time, image
import pyb, ustruct

#Reset sensor
sensor.reset()

#Sensor settings
sensor.set_contrast(3)
sensor.set_gainceiling(16)

#Set resolution to VGA
sensor.set_framesize(sensor.VGA)

#Bin/Crop image to 200x100, wich gives more details with less data to process
sensor.set_windowing((200,250,150,100))

sensor.set_pixformat(sensor.GRAYSCALE)

#Load haar cascade
#By default this will use all stages, lower stages is faster but less accurate
eyes_cascade = image.HaarCascade("eye", stages=24)
print(eyes_cascade)

#FPS clock
clock = time.clock()

text = "Test envois données vers arduino!\n"
#Use "ustruct" to build data packets to send
#Use "<" puts the datain the struct in little endian order
#Use "%ds" to put a string ine the data stream
data = ustruct.pack("<%ds" % len(text), text)



bus = pyb.I2C(2, pyb.I2C.SLAVE, addr=0x12)
bus.deinit()
bus = pyb.I2C(2, pyb.I2C.SLAVE, addr=0x12)
print("Waiting for Arduino...")

while(True):
    clock.tick()
    #Capture snapshot
    img = sensor.snapshot()
    #Find eyes
    #Note: Lower scale factor scales-down the image more and detects smaller objects
    #Higher threshold resultsin a higher detection rate, with more false positives
    eyes = img.find_features(eyes_cascade, threshold=0.5, scale_factor=1.5)
    detection = 0
    #Find iris
    for e in eyes:
        iris = img.find_eye(e)
        img.draw_cross(iris[0], iris[1])
        detection = 0

        #print FPS
        #Note: Actual FPS is higher, streaming the FB makes it slower
        print(clock.fps())
        if detection == 0:
            try:
                bus.send(ustruct.pack("<h", len("1")), timeout=10000) # Send the len first (16-bits).
                try:
                    bus.send("1", timeout=10000) # Send the data second.
                    print("Sent Data check!") # Only reached on no error.
                except OSError as err:
                    pass # Don't care about errors - so pass.
                    # Note that there are 3 possible errors. A timeout error, a general purpose error, or
                    # a busy error. The error codes are 116, 5, 16 respectively for "err.arg[0]".
            except OSError as err:
                pass
