import pygame
from pygame.locals import *
import pygame._sdl2
from pygame._sdl2.controller import Controller

# Ignore all of the orange squigglies under '_sdl2'. It's because of the underscore. It's annoying, but there's nothing
# I can do about it

# Initialize all the the pygame modules
pygame.init()

# initialize the _sdl2 modules
pygame._sdl2.controller.init()

# Initialize the controller and assign to 'con'. This assumes once controller is connected and was given index 0
con = pygame._sdl2.controller.Controller(0)

# Print out the controller button/axis/hat mapping.
print(con.get_mapping())

# Print out controller input to check mapping
while True:
    for event in pygame.event.get():
        # Print D-pad
        print("d-Pad: ", end='')
        print(con.get_button(CONTROLLER_BUTTON_DPAD_UP), end=", ")
        print(con.get_button(CONTROLLER_BUTTON_DPAD_RIGHT), end=", ")
        print(con.get_button(CONTROLLER_BUTTON_DPAD_DOWN), end=", ")
        print(con.get_button(CONTROLLER_BUTTON_DPAD_LEFT))
        # Print joysticks
        print("joysticks: ", end='')
        print(con.get_axis(CONTROLLER_AXIS_LEFTX), end=", ")
        print(con.get_axis(CONTROLLER_AXIS_LEFTY), end=", ")
        print(con.get_axis(CONTROLLER_AXIS_RIGHTX), end=", ")
        print(con.get_axis(CONTROLLER_AXIS_RIGHTY))
        # Print triggers
        print("triggers: ", end='')
        print(con.get_axis(CONTROLLER_AXIS_TRIGGERLEFT), end=", ")
        print(con.get_axis(CONTROLLER_AXIS_TRIGGERRIGHT))
        # Print bumpers and buttons
        print("bumbers/buttons: ", end='')
        print(con.get_button(CONTROLLER_BUTTON_LEFTSHOULDER), end=", ")
        print(con.get_button(CONTROLLER_BUTTON_RIGHTSHOULDER), end=", ")
        print(con.get_button(CONTROLLER_BUTTON_A), end=", ")
        print(con.get_button(CONTROLLER_BUTTON_B), end=", ")
        print(con.get_button(CONTROLLER_BUTTON_X), end=", ")
        print(con.get_button(CONTROLLER_BUTTON_Y))
        print()
        print()
