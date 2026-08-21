# ✈️ FlightBooker

<div align="center">

### A Console-Based Flight Reservation System in C

**Authenticate → Search → Sort → Book → Manage**

A practical C project demonstrating structured programming, file handling, searching, sorting, and a complete ticket-booking workflow.

</div>

---

## 🧭 Project Overview

**FlightBooker** is a terminal-based airline reservation system written in C. It brings together user authentication, flight discovery, sorting, passenger booking, ticket generation, booking search, and cancellation in one application.

The project focuses on applying core C programming concepts to a realistic problem rather than building isolated exercises.

## ✨ Highlights

| Module | What it does |
|---|---|
| 🔐 Authentication | Sign up, login, and account management |
| 🔎 Flight Search | Find flights by source and destination |
| 📊 Sorting | Sort matching flights by time, price, or seats |
| 🎟️ Booking | Book one or multiple passengers |
| 🧾 Ticketing | Generate a formatted ticket in the terminal |
| 🔍 Booking Search | Find an existing reservation |
| ❌ Cancellation | Cancel an existing booking |
| 💾 Persistence | Store accounts, flights, and bookings in text files |

## 📸 Application Screenshots

The following screenshots show the main console workflow of FlightBooker, from authentication and flight discovery through booking and ticket management.

> **Note:** Screenshots are stored in the `docs/` directory of this repository.

### 🏠 Application Interface

![FlightBooker Screenshot 1](docs/Screenshot%202026-04-27%20190450.png)

![FlightBooker Screenshot 2](docs/Screenshot%202026-04-27%20190459.png)

### 🔎 Flight Search & Selection

![FlightBooker Flight Search](docs/Screenshot%202026-04-27%20190541.png)

![FlightBooker Flight Options](docs/Screenshot%202026-04-27%20190627.png)

### 🎟️ Booking Workflow

![FlightBooker Booking](docs/Screenshot%202026-04-27%20190648.png)

![FlightBooker Booking Details](docs/Screenshot%202026-04-27%20191414.png)

### 🧾 Ticket & Reservation Management

![FlightBooker Ticket](docs/Screenshot%202026-04-27%20191506.png)

![FlightBooker Reservation](docs/Screenshot%202026-04-27%20191536.png)

![FlightBooker Final Screen](docs/Screenshot%202026-04-27%20191613.png)

## 🧠 System Flow

```text
                 ┌──────────────┐
                 │    START     │
                 └──────┬───────┘
                        ▼
                ┌───────────────┐
                │ Authentication│
                └──────┬────────┘
                       ▼
                ┌───────────────┐
                │ Flight Search │
                └──────┬────────┘
                       ▼
              ┌──────────────────┐
              │ Sort / Compare   │
              │ Time • Price •   │
              │ Available Seats  │
              └────────┬─────────┘
                       ▼
                ┌───────────────┐
                │ Book Ticket   │
                └──────┬────────┘
                       ▼
                ┌───────────────┐
                │ Generate      │
                │ Ticket        │
                └──────┬────────┘
                       ▼
                ┌───────────────┐
                │ Search /      │
                │ Cancel Booking│
                └───────────────┘
```

## 📁 Repository Structure

```text
FlightBooker/
├── src/
│   └── project.c                 # Main application source
│
├── data/
│   ├── account.txt               # User account records
│   ├── booking.txt               # Booking records
│   └── flights.txt               # Flight dataset
│
├── docs/
│   ├── projectpresentation.html  # Project presentation
│   └── *.png                     # Application screenshots
│
└── README.md
```

## 🛠️ Concepts Demonstrated

- **Structures** for accounts, flights, and passengers
- **File handling** for persistent text-based storage
- **Searching** for flights and bookings
- **Sorting algorithms** for flight comparison
- **Functions** for modular program organization
- **Console UI** with formatted tables and ticket output
- **Authentication flow** for user access

## 🚀 Getting Started

### 1. Clone the repository

```bash
git clone https://github.com/chauhanarjit07/FlightBooker.git
cd FlightBooker
```

### 2. Compile

From the repository root:

```bash
gcc src/project.c -o FlightBooker.exe
```

> **Note:** The current source reads and writes `account.txt`, `booking.txt`, and `flights.txt` from the program's current working directory. Because these files are organized inside `data/`, run the executable from that directory.

### 3. Run

On Windows:

```bat
cd data
..\FlightBooker.exe
```

This keeps the runtime data together inside `data/` while leaving the source code and documentation cleanly separated.

> The project uses console functions such as `conio.h` and `getch()`, so compilation may require a Windows-compatible C environment.

## 📦 Data Layer

```text
data/
├── account.txt   → registered users
├── flights.txt   → available flights
└── booking.txt   → passenger bookings
```

FlightBooker intentionally uses simple text files instead of a database so the project can demonstrate **C file handling and persistent storage** directly.

## 🎯 Why This Project?

FlightBooker connects multiple programming fundamentals into one realistic workflow:

**Data → Algorithms → File Handling → User Interaction → Complete Application**

Instead of practicing sorting, structures, or file handling independently, the project shows how these concepts cooperate inside a larger system.

## 🔮 Future Scope

- Database integration with MySQL
- Improved password security
- Seat-level reservation management
- Admin dashboard for flight management
- Better cross-platform terminal support
- Stronger input validation and error handling
- Online payment simulation
- REST API / web frontend integration

## 👨‍💻 Developer

### Arjit Chauhan

B.Tech Computer Science Student · C Programmer · Problem Solver

## ⭐ Support

If FlightBooker helped you understand C programming or file-based application design, consider giving the repository a **⭐ Star**.

---

<div align="center">

**Built with C 💻 and a little ✈️ ambition**

</div>
