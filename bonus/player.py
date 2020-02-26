# -*- coding: Utf-8 -*

import socket
import constant
from my_pygame.window import Window
from my_pygame.classes import Button, RectangleShape, Image, Text, Entry
from my_pygame.colors import BLACK, GREEN, GREEN_DARK, GREEN_LIGHT, YELLOW

class PlayerServer(Window):
    def __init__(self):
        Window.__init__(self)
        params_for_all_buttons = {
            "font": ("calibiri", 50),
            "bg": GREEN,
            "over_bg": GREEN_DARK,
            "active_bg": GREEN_LIGHT,
            "over_fg": YELLOW,
            "outline": 5,
            "outline_color": BLACK
        }
        self.bg = Image(constant.IMG["menu_bg"], self.window_rect.size)
        self.logo = Image(constant.IMG["logo"])

        self.ip = socket.gethostbyname(socket.gethostname())
        self.port = 12800
        self.frame_size = int(0.5 * self.window_rect.w), int(0.5 * self.window_rect.h)

        self.frame = RectangleShape(self.frame_size, GREEN_DARK, outline=5)
        self.ip_address = Text(f"IP address: {self.ip}", ("calibri", 80), BLACK)
        self.port_of_connection = Text(f"Port: {self.port}", ("calibri", 80), BLACK)
        self.cancel_button = Button(self, "Return to menu", command=self.stop, **params_for_all_buttons)
        self.place_objects()

    def place_objects(self):
        self.bg.move(center=self.window_rect.center)
        self.logo.move(centerx=self.window_rect.centerx, y=10)
        self.frame.move(center=self.window_rect.center)
        self.ip_address.move(centerx=self.window_rect.centerx, bottom=self.frame.rect.centery - 10)
        self.port_of_connection.move(centerx=self.ip_address.rect.centerx, top=self.ip_address.rect.bottom + 20)
        self.cancel_button.move(centerx=self.frame.rect.centerx, bottom=self.frame.rect.bottom - 50)

    def check_incoming_connection(self):
        pass

class PlayerClient(Window):
    def __init__(self):
        Window.__init__(self)
        params_for_all_buttons = {
            "font": ("calibiri", 50),
            "bg": GREEN,
            "over_bg": GREEN_DARK,
            "active_bg": GREEN_LIGHT,
            "over_fg": YELLOW,
            "outline": 5,
            "outline_color": BLACK
        }
        self.bg = Image(constant.IMG["menu_bg"], self.window_rect.size)
        self.logo = Image(constant.IMG["logo"])
        self.frame_size = int(0.5 * self.window_rect.w), int(0.5 * self.window_rect.h)

        self.frame = RectangleShape(self.frame_size, GREEN_DARK, outline=5)
        self.ip = Entry(self, font=("calibri", 80), width=13, bg=GREEN, fg=BLACK, highlight_color=YELLOW, outline=5)
        self.text_ip = Text("IP adress of Player 1", ("calibri", 80), YELLOW)
        self.port = Entry(self, font=("calibri", 60), width=13, bg=GREEN, fg=BLACK, highlight_color=YELLOW, outline=5)
        self.text_port = Text("IP adress of Player 1", ("calibri", 60), YELLOW)
        self.cancel_button = Button(self, "Return to menu", command=self.stop, **params_for_all_buttons)
        self.place_objects()

    def place_objects(self):
        self.bg.move(center=self.window_rect.center)
        self.logo.move(centerx=self.window_rect.centerx, y=10)
        self.frame.move(center=self.window_rect.center)
        self.ip.move(left=self.window_rect.centerx, bottom=self.frame.rect.centery - 10)
        self.text_ip.move(centery=self.ip.rect.centery, right=self.ip.rect.left - 10)
        self.port.move(left=self.ip.rect.centerx, top=self.ip.rect.bottom + 20)
        self.text_port.move(centery=self.port.rect.centery, right=self.port.rect.left - 10)
        self.cancel_button.move(centerx=self.frame.rect.centerx, bottom=self.frame.rect.bottom - 50)

    def check_incoming_connection(self):
        pass