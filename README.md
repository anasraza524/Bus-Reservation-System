# Bus Reservation System

![Watch the video](https://github.com/anasraza524/Bus-Reservation-System/raw/main/demo.mp4)

## Description

This project is a simple online bus reservation system implemented in C. It allows users to sign up, log in, book bus tickets, check seat availability, and cancel reservations. The program uses ANSI escape codes to enhance the user interface with color-coded feedback and includes a splash screen with a loading animation for a professional look.

## Features

- **User Authentication**:
  - Sign up with a unique username.
  - Log in with a username and password.
- **Bus Management**:
  - View a list of available buses with routes, charges, and timings.
  - Check the status of bus seats (booked or available).
- **Ticket Management**:
  - Book up to 5 seats per reservation.
  - Cancel booked seats.
- **User Session Management**:
  - Tracks user login status to ensure secure access.
- **Splash Screen**:
  - Dynamic loading animation on startup.

## Getting Started

### Prerequisites

- A C compiler (e.g., GCC)
- A terminal that supports ANSI escape codes

### Files

- `main.c`: Main program file containing all functions.
- `userNameList.txt`: Stores usernames.
- `userSection.txt`: Tracks current user session.
- `busSeatList.txt`: Stores bus and seat bookings.

### Compilation and Execution

1. Compile the program:
   ```sh
   gcc -o BusReservationSystem main.c
