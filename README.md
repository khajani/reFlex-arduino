# 🦾 ReFlex: The Teleoperated Hand 
ReFlex is a **teleoperated robotic hand** project where a wooden hand mimics the real-time finger movements of the user. By wearing a sensor glove equipped with **flex sensors**, the bending of each finger is captured and translated into proportional movements of the wooden hand. The hand uses a **string–elastic tendon system**, inspired by **human biomechanics**, that mimics the how tendons pull fingers closed and ligaments restore them

https://github.com/user-attachments/assets/f3a22eb1-46af-4bfc-933b-caa67ac1c6d1

## 🚀 Features
 
 - 🦾 **Real-time teleoperation** of a robotic hand   
 - 🩺 **Biomechanics-inspired tendon–ligament mechanism**   
 - 💵 **Low-cost** prototype using accessible materials   
 - 💫 **Expandable** for haptics, force feedback, or more advanced control

<img src="https://github.com/user-attachments/assets/400d0e0e-ecdc-4aea-8192-fb86611cae70" width="400"/>
<img src="https://github.com/user-attachments/assets/afcf6eee-684b-4199-9a08-980d4d8219bd" width="400"/>

Left: **Biomechanics-inspired tendon–ligament mechanism**  
Right: Smaller-sized pulley for increased torque 

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

<img width="764" height="320" alt="Brave Trug-Blad" src="https://github.com/user-attachments/assets/7368b0b5-a886-48d5-b3a8-09651e5b12e4" />   

Note: Stepper motor is not included and the driver type is different in this drawing because of TinkerCAD limitations      

<img width="496" height="386" alt="image" src="https://github.com/user-attachments/assets/4ebefe4c-3e08-40a8-8423-2ff84644e2a0" />

<img src="https://github.com/user-attachments/assets/9f52f063-0d38-463a-ac56-3bd293841769" width="400"/>

## 🔮 Future Improvements
- Design a 3D-printed hand for higher dexterity and cleaner design
- Improve finger actuation with stronger mechanism
- Implement more stepper motors and flex sensors (since time-constraint did not allow)
- Explore force feedback for haptics
