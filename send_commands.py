import pyautogui as pt
f= open(r'command.txt')
cont = f.readlines()
pt.alert(title='Confirmation',text='Continue?')
for i in cont:
    pt.sleep(2)
    pt.write(i)
    
