import hid
import time
import os

vid = 0xFEED	# Change it for your device
pid = 0x1307	# Change it for your device

interfaces = hid.enumerate(vid, pid)
filtered = [x for x in interfaces if x["interface_number"] == 1]
path = filtered[0]["path"]
# print(path)

with hid.Device(path=path) as h:
  print(f'Device manufacturer: {h.manufacturer}')
  print(f'Product: {h.product}')
  print(f'Serial Number: {h.serial}')
  while True:
    msg = h.read(8).decode()
    
    if msg.startswith("LAYER:"):
      layer = int(msg[6])
      if layer == 3:
        os.system("xinput --set-prop \"Primax Kensington Eagle Trackball\" 276 0 0")
      else:
        os.system("xinput --set-prop \"Primax Kensington Eagle Trackball\" 276 1 0")
    else:
      print(msg)