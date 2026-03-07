# 🌦️ Weather Forecast Simulation (C++)

[![Language](https://img.shields.io/badge/Language-C++17-blue.svg)]()
[![Type](https://img.shields.io/badge/Project-Case%20Study-success.svg)]()
[![Platform](https://img.shields.io/badge/Platform-Console-lightgrey.svg)]()

A menu-driven C++ console project that simulates weather reporting for multiple cities using Object-Oriented Programming.

---

## 🚀 Features

- View available cities
- Check weather for a selected city
- Compare weather between two cities
- View global statistics:
  - Average temperature
  - Hottest city
  - Coldest city
- Handles invalid user input safely

---

## 🧱 Architecture

- **`WeatherData`**: city model (`name`, `temperature`, `humidity`)
- **`WeatherAnalyzer`**: static statistical analysis utilities
- **`WeatherForecastSimulation`**: menu flow and user interaction

---

## 🧠 C++ Concepts Used

- Classes & Objects
- Encapsulation (private data + getters)
- Constructors (default + parameterized)
- Arrays of objects
- Loops, conditionals, `switch`
- Static member functions
- Input validation with `cin.clear()` and `cin.ignore()`

---

## 📂 File

- `WeatherForecast.cpp`

---

##  Default Dataset
Mumbai — 32.0°C, 70.0%
Delhi — 28.5°C, 45.0%
Bangalore — 24.0°C, 60.0%
Chennai — 34.0°C, 75.0%
Kolkata — 31.0°C, 68.0%


## Future Improvements
File/database storage
Dynamic city management
Live weather API integration
Unit tests

## 👤 Author
Ankit Raj Jha
