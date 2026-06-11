# AI-Based Low-Cost Solar Panel Cleaning System

## 📌 Overview

This project presents a low-cost, AI-assisted automated solar panel cleaning system designed specifically for individual users and small-scale farmers.

Unlike existing solutions that rely on fixed time cleaning, that is timer based logic unlike traditional cleaners, our system uses AI-driven decision-making to clean panels only when required. Hence reducing water usage, energy consumption and operational cost.

## Problem Statement

-   Dust accumulation reduces solar efficiency by 10-30%
-   Manual cleaning is:
    -   Labor-intensive
    -   Unsafe
    -   Irregular
-   Existing automated solutions are:
    -   Expensive (₹20,000+)
    -   Designed for large solar farms

## Proposed Solution

We propose a rail based automated cleaning system with wet cleaning, microfiber wiping, AI based cleaning decision logic and IoT enabled monitoring

## AI Component (Key Differentiator)

### Goal:

Clean only when required, not on fixed schedules.

### Inputs:

-   Image data (ESP32-CAM)
-   Dust sensor readings
-   Time since last cleaning

### AI Model:

Lightweight CNN model is trained to classify: - Clean panel & Dusty panel

### Output:

Binary decision: - CLEAN - DO NOT CLEAN

## System Architecture

### Hardware:

-   ESP32 + ESP32-CAM
-   DC motor (rail movement)
-   Water pump + solenoid valve
-   Microfiber cleaning strip
-   Dust sensor (PM2.5)
-   Current/voltage sensor

## Circuit Diagram

## Circuit Explanation (Based on Your Diagram)

-   ESP32: Central controller for all operations
-   ESP32-CAM: Captures panel surface images
-   PM2.5 Sensor: Measures dust level
-   INA219 Sensor: Tracks panel efficiency
-   Motor Driver (L298N): Controls rail movement motor
-   MOSFETs: Control pump and valve
-   Limit Switches: Prevent over-travel
-   Buck Converter: Steps down voltage (12V → 5V)

## Working in Real Environment

1.  System periodically checks panel condition
2.  Camera + sensor data analyzed
3.  AI decides if cleaning is required
4.  If YES:
    -   Motor moves cleaner across rail
    -   Pump sprays water
    -   Microfiber wipes surface
    -   System stops at limit switch
5.  Data logged and status updated

## Sustainability Impact

-   Up to 60-70% water savings
-   Reduced unnecessary cleaning cycles
-   Increased solar panel lifespan


## Expected Impact

-   10-20% efficiency improvement
-   Reduced maintenance cost
-   Accessible automation for rural users

## Future Scope

-   Predictive cleaning using weather data
-   Water recycling system
-   Fault detection (hotspots, cracks)
-   Mobile app integration

## Conclusion

This system provides a scalable, affordable, and intelligent solution to improve solar efficiency at the grassroots level, aligning with sustainability and smart automation goals.
