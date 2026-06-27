# AI-Based Low-Cost Solar Panel Cleaning System

## Problem Statement

* Dust accumulation reduces solar panel efficiency by 10–30%
* Manual cleaning is:

  * Labor-intensive
  * Unsafe
  * Irregular
* Existing automated systems are expensive (₹20,000+) and designed for large-scale solar farms

## Proposed Solution

A rail-based automated cleaning system featuring:

* Wet cleaning + microfiber wiping
* AI-based decision-making
* IoT-enabled monitoring

## AI Model Logic

###  What the Model Does

A lightweight binary image classifier:

* Input: Solar panel image
* Output: Clean (0) / Dusty (1)

### Working Pipeline

**1. Data Preparation**

* Dataset split into `/clean` and `/dusty`
* Images resized to 128×128
* Pixel normalization (0 → 1)

**2. Model Architecture (CNN)**

* Conv2D layers → detect dust patterns
* Pooling layers → reduce dimensions
* Dense layers → classification

The model learns visual patterns of dust on panels.

**3. Training**

* Learns differences between clean and dusty surfaces

**4. Output Decision**

* Probability output (0–1)

  * > 0.5 → Dusty → Cleaning required
  * < 0.5 → Clean → No action

**5. Deployment**

* Converted to TensorFlow Lite (TFLite)
* Optimized for edge devices

The lightweight AI model detects dust accumulation on solar panels and triggers cleaning only when necessary.

## Embedded System Logic (ESP32)

### Main Workflow

**1. Dust Detection**

* PM2.5 sensor measures airborne dust

**2. Efficiency Monitoring**

* Voltage & current measured via INA219
* Helps detect performance drop

**3. Data Display**

* LCD shows real-time dust and voltage data

**4. Decision Logic**

```cpp
if(pm25Value > dustThreshold)
{
  startCleaning();
}
```

## Cleaning Mechanism

### Step-by-Step Operation:

1. Pump and valve activated
2. Cleaner moves right across panel
3. Stops at limit switch
4. Moves left back to start
5. Pump and valve turned OFF

### Key Features:

* Full panel coverage
* Safe operation using limit switches
* Controlled water usage

The system monitors dust and performance, and autonomously triggers a rail-based cleaning mechanism only when required.

## System Architecture

### Hardware Components:

* ESP32 + ESP32-CAM
* DC motor (rail system)
* Water pump + solenoid valve
* Microfiber cleaning strip
* PM2.5 dust sensor
* INA219 current/voltage sensor


## Real-World Working

1. System periodically checks panel condition
2. Sensor + image data analyzed
3. Decision made (AI / threshold logic)
4. Cleaning triggered only if required
5. Data logged for monitoring


## Sustainability Impact

* 60–70% water savings
* Reduced unnecessary cleaning cycles
* Increased solar panel lifespan


## Expected Impact

* 10–20% efficiency improvement
* Reduced maintenance costs
* Affordable automation for rural users


## Future Scope

* AI-based predictive cleaning (weather integration)
* Water recycling system
* Fault detection (hotspots, cracks)
* Mobile app integration


## Conclusion

This system delivers a scalable, affordable, and intelligent solution to improve solar efficiency at the grassroots level, combining AI, IoT, and sustainable engineering.
