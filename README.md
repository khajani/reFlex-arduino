# 🦾 ReFlex: The Teleoperated Hand 
ReFlex is a **teleoperated robotic hand** project where a wooden hand mimics the real-time finger movements of the user. By wearing a sensor glove equipped with **flex sensors**, the bending of each finger is captured and translated into proportional movements of the wooden hand. The hand uses a **string–elastic tendon system**, inspired by **human biomechanics**, that mimics the how tendons pull fingers closed and ligaments restore them

## 🚀 Features
 
 - 🦾 **Real-time teleoperation** of a robotic hand   
 - 🩺 **Biomechanics-inspired tendon–ligament mechanism**   
 - 💵 **Low-cost** prototype using accessible materials   
 - 💫 **Expandable** for haptics, force feedback, or more advanced control   

## ⚙️ How It Works

1. The user wears a glove fitted with flex sensors on each finger
2. Finger bending changes the sensor resistance, which is read by the Arduino Uno
3. These readings are mapped to motor rotations
4. Stepper motors pull strings attached to each finger tip running down the fingers of the IKEA wooden hand
5. Elastic bands restore the fingers to their neutral position when the user releases

    This string–elastic combo **functions like human tendons and ligaments**:
    - The strings act as flexor tendons, pulling fingers closed.
    - The elastic bands mimic extensor ligaments, returning fingers to rest.

This allows the wooden hand to **mirror human finger biomechanics in real time**.

## 🧰 Materials
  - Arduino Uno 
  - Flex Sensors  
  - Work Glove  
  - IKEA Wooden Hand  
  - Stepper Motors & Drivers  
  - Jumper Wires   
  - Electric Tape  
  - String  
  - Elastic Bands   
  - Hot Glue   
  - Paper Straw   
  - Zip-tie

## 🔌 Wiring & Circuit Diagram

The system involves two main parts:

**🧤 Glove Circuit:**
- Analog inputs on Arduino read finger bending 
- Flex sensor + 10 kΩ resistor form voltage divider configuration   
  - Ratio of the flex sensor resistance to the total resistance determins Vout in Arduino analog pin   
  - <img width="295" height="86" alt="image" src="https://github.com/user-attachments/assets/dfcecd2a-2d58-480f-abeb-206eb3164931" />  
    - Flat finger → sensor low resistance → voltage at analog pin higher   
    - Bent finger → sensor higher resistance → voltage at analog pin lower   
    - The Arduino reads this voltage change and interprets it as finger movement   

**✋ Hand Circuit:**

- Stepper motor driven by ULN2003 driver   
- Arduino digital pins send control signals   
- Shared 5 V & GND   

**Signal Flow:** 
Finger bend → Sensor → Arduino → Driver → Motor
  
## 🔮 Future Improvements
- Design a 3D-printed hand for higher dexterity and cleaner design
- Improve finger actuation with stronger mechanism
- Implement more stepper motors
- Explore force feedback for haptics
