# Philosophers

A C implementation of the classic "Dining Philosophers" concurrency problem, developed as part of the 42 school curriculum.

## Overview

This project simulates the Dining Philosophers problem using threads and mutexes in C. The goal is to coordinate philosophers (threads) who alternately eat, think, and sleep while sharing limited resources (forks) and avoiding deadlocks and starvation.

## Features

- Each philosopher is a separate thread.
- Forks are represented by mutexes to ensure exclusive access.
- Accurate timing and logging of each philosopher's actions.
- Handles edge cases (such as a single philosopher).
- Allows optional specification of the number of meals each philosopher must eat before simulation ends.
- Clean resource management and error handling.

## Project Structure

```
philo/
├── inc/
│   └── philo.h           # Main header file
├── src/
│   ├── main.c            # Argument parsing, program entry point
│   ├── philo_init.c      # Initialization of philosophers, forks, and program state
│   ├── philo_routine.c   # Philosopher's action routines (think, eat, sleep)
│   ├── philo_utils.c     # Utility functions
│   ├── philo_utils2.c    # More utilities (printing, timing, resource cleanup)
│   ├── big_brother.c     # Monitoring thread ("big brother") for philosopher status
│   └── threads.c         # Thread creation and management
└── Makefile              # Build automation
```

## Usage

### Compilation

Navigate to the `philo` directory and run:

```bash
make
```

This will produce the `philo` executable.

### Running the Program

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

- `number_of_philosophers`: How many philosophers are sitting at the table (max 200).
- `time_to_die`: Time (ms) after which a philosopher dies if not eating.
- `time_to_eat`: Time (ms) it takes for a philosopher to eat.
- `time_to_sleep`: Time (ms) a philosopher spends sleeping.
- `number_of_times_each_philosopher_must_eat` (optional): If present, the simulation ends when each philosopher has eaten this many times.

**Example:**
```bash
./philo 5 800 200 200
./philo 5 800 200 200 7
```

## How It Works

- Each philosopher alternates between thinking, taking forks, eating, and sleeping.
- Forks are managed with mutexes to avoid race conditions.
- A "big brother" thread monitors all philosophers for death (starvation) or if all have eaten the required number of times.
- All shared state is protected by mutexes to ensure thread safety.
- Clean-up functions destroy all mutexes at the end.

## Error Handling

- Validates command-line arguments (number, value ranges).
- Handles errors in thread and mutex creation/destruction.
- Provides descriptive error messages on invalid input or system errors.

## Dependencies

- Standard C libraries: `stdio.h`, `stdlib.h`, `unistd.h`
- POSIX threads: `pthread.h`
- Time functions: `sys/time.h`

---
