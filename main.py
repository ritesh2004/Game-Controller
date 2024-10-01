import  sys
import time 
import serial
import pyautogui

ArduinoSerial=serial.Serial('COM6',9600)  #Specify the correct COM port
time.sleep(1)    #delay of 1 second

run = True

while run:
    try:
        data = ArduinoSerial.readline().decode('utf-8').strip('\r\n') #read the data
        x,y = data.split(",")           # assigns to x,y and z
        # print(x,y) 
        
        if (x == 'W'):
            pyautogui.keyDown('w')
            if (y == 'A'):
                pyautogui.keyUp('d')
                pyautogui.keyDown('a')
            elif (y == 'D'):
                pyautogui.keyUp('a')
                pyautogui.keyDown('d')
        else:
            pyautogui.keyUp('w')
            pyautogui.keyUp('a')
            pyautogui.keyUp('d')
            pyautogui.press('s')
        
    except ValueError as e:
        pyautogui.keyUp('w')
        pyautogui.keyUp('a')
        pyautogui.keyUp('d')
        pyautogui.press('s')
        continue