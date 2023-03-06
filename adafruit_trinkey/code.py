# Write your code here :-)
import time
import board
import neopixel
import usb_hid
from adafruit_hid.keyboard import Keyboard
from adafruit_hid.keyboard_layout_us import KeyboardLayoutUS
from adafruit_hid.keycode import Keycode  # pylint: disable=unused-import
from digitalio import DigitalInOut, Pull
import touchio
from adafruit_led_animation.animation.rainbow import Rainbow
from adafruit_led_animation.color import PURPLE

print("NeoKey Trinkey HID")

# create the pixel and turn it off
pixel = neopixel.NeoPixel(board.NEOPIXEL, 1, brightness=0.1, auto_write=False)
pixel.fill(0x0)

time.sleep(1)  # Sleep for a bit to avoid a race condition on some systems
keyboard = Keyboard(usb_hid.devices)
keyboard_layout = KeyboardLayoutUS(keyboard)  # We're in the US :)

# create the switch, add a pullup, start it with not being pressed
button = DigitalInOut(board.SWITCH)
button.switch_to_input(pull=Pull.DOWN)
button_state = False

# create the captouch element and start it with not touched
touch = touchio.TouchIn(board.TOUCH)
touch_state = False

# make neokey animation
rainbow_chase = Rainbow(pixel, speed=0.1, period=2)

# print a string on keypress
#key_output = (
#   {'keys': (Keycode.COMMAND, Keycode.SPACEBAR), 'delay': 0.1},
#   {'keys': "chrome\n", 'delay': 1},  # give it a moment to launch!
#   {'keys': (Keycode.COMMAND, Keycode.T), 'delay': 0.1},
#   {'keys': "your_zoom_meeting_url", 'delay': 0.1},
#   {'keys': Keycode.ENTER, 'delay': 0.1},
#   {'keys': Keycode.TAB, 'delay': 0.5},
#   {'keys': [Keycode.TAB, Keycode.TAB, Keycode.TAB, Keycode.TAB, Keycode.TAB, Keycode.TAB, Keycode.TAB, Keycode.ENTER], 'delay': 0.1},
#)

#key_output = (
#    {'keys': "hello world", 'delay': 0.5},
#)

key_output = (
    {'keys': (Keycode.ALT, Keycode.F4), 'delay': 0.1},
)

# our helper function will press the keys themselves
def make_keystrokes(keys, delay):
    if isinstance(keys, str):  # If it's a string...
        keyboard_layout.write(keys)  # ...Print the string
    elif isinstance(keys, int):  # If its a single key
        keyboard.press(keys)  # "Press"...
        keyboard.release_all()  # ..."Release"!
    elif isinstance(keys, (list, tuple)):  # If its multiple keys
        keyboard.press(*keys)  # "Press"...
        keyboard.release_all()  # ..."Release"!
    time.sleep(delay)

while True:
    
    if touch.value and not touch_state:
        print("touch")
        touch_state = True
        
    if touch.value and touch_state:
        rainbow_chase.animate()
        
    if not touch.value and touch_state:
        pixel.fill(0x0)
        pixel.show()
        touch_state = False

    if button.value and not button_state:
        pixel.fill((255, 0, 0))
        pixel.show()
        print("Button pressed.")
        button_state = True

    if not button.value and button_state:
        pixel.fill(0x0)
        pixel.show()
        print("Button released.")
        if isinstance(key_output, (list, tuple)) and isinstance(key_output[0], dict):
            for k in key_output:
                if isinstance(k['keys'], list):
                    for i in k['keys']:
                        make_keystrokes(i, k['delay'])
                else:
                     make_keystrokes(k['keys'], k['delay'])
        else:
            make_keystrokes(key_output, delay=0)
        button_state = False
        
    

