# Edge-Deployed Seismic Magnitude Estimation with TinyML on ESP32

## Project Overview

This project implements a complete edge-based machine learning pipeline for seismic event analysis. It deploys a trained regression model on an ESP32 microcontroller to perform on-device prediction of earthquake magnitude based on seismic parameters. The pipeline spans from data preprocessing and model training using TensorFlow/Keras in Python to model optimization and deployment using TensorFlow Lite for Microcontrollers. Real-time inference is executed entirely on the ESP32 hardware, enabling low-latency, low-power magnitude prediction without reliance on cloud infrastructure.

---

##  Technologies Used

- Python 3.7  
- TensorFlow and Keras for model training  
- NumPy and Pandas for data preprocessing  
- TensorFlow Lite for model optimization and quantization  
- `xxd` for converting `.tflite` model to C header format  
- ESP32 DevKit v1 as the embedded hardware platform  
- Arduino IDE for ESP32 side code development  
- EloquentTinyML (wrapper around TFLite Micro) for on-device inference  

---

## System Overview

The system is architected as an end-to-end embedded machine learning pipeline, optimized for real-time edge deployment. It begins with acquisition of historical earthquake data, which includes seismic parameters such as depth, distance from epicenter, and community-reported intensity (CDI). This dataset is cleaned, normalized, and processed in Python using Pandas and NumPy. A feedforward neural network is designed and trained using TensorFlow and Keras, optimized for low-complexity inference.

Post-training, the model is converted into TensorFlow Lite format (`.tflite`) and quantized to reduce memory usage. The model is then converted into a C-style byte array using `xxd`, resulting in a header file (`.h`) compatible with microcontroller integration.

The model achieved a normalized predictive accuracy of approximately 83%, indicating its ability to consistently estimate earthquake magnitudes within a practical error margin.This demonstrates that the model is sufficiently accurate for real-time edge deployment, especially under memory and performance constraints imposed by embedded systems like ESP32.  

On the embedded side, the ESP32 microcontroller is programmed using the Arduino IDE and the EloquentTinyML library, which loads and runs the TFLite model using TensorFlow Lite Micro runtime.  
The resulting magnitude prediction is output via serial communication and can be extended to wireless protocols (e.g., Wi-Fi, MQTT) for remote transmission or alerting. This architecture ensures low-latency, low-power inference with no cloud dependency.

---

## Features

- Implements a fully embedded machine learning regression model for earthquake magnitude prediction ported onto ESP32 hardware
- Operates entirely on-device with no internet or cloud dependency  
- Supports quantized TFLite model for optimal memory footprint  
- Achieves sub-second inference latency on ESP32 hardware using EloquentTinyML  
