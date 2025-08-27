MSP430G2553 – Timers & Frequency Counter — README

Short Summary
------------
This repository contains assembly code for the MSP430G2553 microcontroller.
The program runs directly on the MCU and demonstrates a small embedded application built with
timers, interrupts, a button‑driven state machine (FSM), and an LCD interface.

What the Project Does
---------------------
• Two operating modes selected by push buttons (via interrupts):
  1) Countdown Timer — counts down from 01:00 to 00:00 in seconds using Timer_A0 interrupts,
     and shows the time on a character LCD. The mode ends on reaching 00:00 or when another
     mode is selected.
  2) Frequency Counter — measures the frequency of an external square‑wave clock on a GPIO pin
     using Timer_A1 in Input‑Capture mode and displays the measured value in Hz on the LCD.
     Target input range: approx. 100 Hz to 20 kHz, integer‑Hz resolution.
• Event‑driven FSM with external interrupts for button presses (short debounce only; no long delays).

Repository Files
----------------
• prelab5_main.s43  — main program, ISRs, and the FSM control flow (IAR assembly).
• prelab5_api.s43   — simple API used by the application (LCD print, mode changes, etc.).
• prelab5_hal.s43   — hardware abstraction (timers, input capture, GPIO, LCD low‑level).
• prelab5_bsp.s43   — board support (device/clock/ports setup).
• prelab5_bsp.h     — pin/port definitions and small macros used by the BSP/HAL.
(If your wiring differs, update the pin definitions in prelab5_bsp.h accordingly.)

Target Hardware
---------------
• MCU: MSP430G255
• Buttons: connected to Port 2 pins (see prelab5_bsp.h for PB0/PB1 mapping).
• LCD: data/control lines connected per the BSP header.
• External clock input (for frequency counter mode): a 0–VCC square wave fed to the designated pin
  (see prelab5_bsp.h).

How to Build & Flash (IDE Only)
-------------------------------
IAR Embedded Workbench for MSP430 
1) Create Workspace, then create a new MSP430 assembler project and select device: MSP430G2553.
2) Add main.s43, api.s43, hal.s43, bsp.s43, and bsp.h to the project.
3) Press build. Then go to Project and then Download and Debug (Ctrl+D).
   IAR will erase, program, and start a debug session on the MCU.
4) Press Run to start execution. To reprogram, stop the session and download again.

How to Use (Runtime)
--------------------
• After flashing, the program starts in an idle or default mode.
• Press the relevant button to enter the Countdown Timer mode (01:00 to 00:00 in seconds).
• Press the other button to enter the Frequency Counter mode (displays Hz).
• Return to idle or switch between modes via button presses (exact mapping defined in prelab5_bsp.h
  and near the button ISR in prelab5_main.s43).

Notes
-----
• This code is intended to be FLASHED to the MSP430G2553 MCU.
• Do not rely on hardware reset during operation; the design is event‑driven (interrupts + FSM).
• For other MSP430 families, adapt the BSP/HAL and any timer specifics as needed.
• For other MSP430 devices, update BSP/HAL layers.

License
-------
MIT 
