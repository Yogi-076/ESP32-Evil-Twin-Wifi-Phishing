# ESP32 Evil Twin WiFi Phishing

## 📝 Step-by-Step Setup Guide for ESP32 Evil Twin

### 🔧 Requirements

- ✅ ESP32 WROOM Development Board
- ✅ Arduino IDE Installed
- ✅ ESP32 Board Package Installed
- ✅ SPIFFS File Upload Plugin Installed

---

## 📁 Project Structure

Ensure your project folder is structured as follows:

```
ESP32-Evil-Twin/
│── data/                     # SPIFFS folder (contains phishing page)
│   ├── index1.html           # Fake login page
│   ├── assets/               # Extra resources (CSS, JS, images)
│── ESP32-Evil-Twin.ino       # Main Arduino sketch
│── README.md                 # Setup guide
```

---

## 1️⃣ Install ESP32 Board in Arduino IDE

1. Open **Arduino IDE**.
2. Go to **File > Preferences**.
3. In **Additional Board Manager URLs**, paste:
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
4. Click **OK**.
5. Go to **Tools > Board > Boards Manager**.
6. Search for **ESP32** and install it.

---

## 2️⃣ Install SPIFFS File Upload Plugin

1. Download the ESP32FS Plugin from: 🔗 [**ESP32FS Plugin GitHub**](https://github.com/me-no-dev/arduino-esp32fs-plugin)
2. Extract the downloaded ZIP file.
3. Move the extracted `ESP32FS` folder to:
   ```
   C:\Users\yourusername\Documents\Arduino\tools\
   ```
4. Restart **Arduino IDE**.
5. You should now see **Tools > ESP32 Sketch Data Upload** in the menu.

---

## 3️⃣ Open the Project in Arduino IDE

1. Download the project from **GitHub** or copy it into your **Arduino sketch folder**.
2. Open **ESP32-Evil-Twin.ino** in **Arduino IDE**.
3. In **Tools > Board**, select **ESP32 WROOM**.
4. Set the correct **COM Port** from **Tools > Port**.

---

## 4️⃣ Upload the Phishing Page (SPIFFS)

1. In **Arduino IDE**, go to **Tools > ESP32 Sketch Data Upload**.
2. Wait until the **SPIFFS file system** is uploaded.

---

## 5️⃣ Upload the Code to ESP32

1. Click the **Upload** button (➡) in **Arduino IDE**.
2. Wait for the code to flash successfully.
3. Open **Serial Monitor** (**Tools > Serial Monitor**) and set **baud rate** to **115200**.

---

## 6️⃣ Test the Evil Twin Attack

1. After flashing, **ESP32 will create a fake WiFi network** named **"Shaktiman"** (you can change this in the code).
2. **Connect** to the **"Shaktiman"** WiFi network on any device.
3. Open **any website** → You should be redirected to the **fake login page**.

---

## 📸 Output Section

### 🔹 Fake Login Page:
![Image](https://github.com/user-attachments/assets/617960cf-1471-4462-afd1-2f5eb10a0c10)

### 🔹 Captured Credentials Display:
![Image](https://github.com/user-attachments/assets/db6e9ed8-f3e9-4a4c-9b05-be6c7c1eb20d)

### 🔹 Credentials Deletion Confirmation:
![Image](https://github.com/user-attachments/assets/5b25964d-170e-45fc-9399-4f96d2b37898)

### 🔹 Serial Monitor Output:
```
[+] ESP32 Honeypot Starting...
[+] SPIFFS Mounted Successfully
[+] Hosted WiFi SSID: Shaktiman
[+] WebServer Started!
[+] Captured Credentials: user1:password1
[+] Captured Credentials: user2:password2
```

### 🎥 Video Demonstration:
[![Video](https://github.com/user-attachments/assets/b7ed73c4-8755-4408-a822-bba96530ff28)](https://github.com/user-attachments/assets/b7ed73c4-8755-4408-a822-bba96530ff28)

### 🔹 Additional Demo Screenshots:
![Image](https://github.com/user-attachments/assets/bb6a76f9-2628-4c67-9a66-9ad716e5cbec)

![Image](https://github.com/user-attachments/assets/6af3b729-bb6f-4b7c-bc3e-674d28f1db18)

---

## 7️⃣ View Captured Credentials

1. Open a browser and go to:
   ```
   http://172.0.0.1/getinfo
   ```
2. This will display **stored usernames & passwords**.

---

## 8️⃣ Delete Captured Credentials

To erase stored credentials, visit:

```
http://172.0.0.1/deleteinfo
```

This will **clear all saved data**.

---

## ✅ You're Done!

Your **ESP32 Evil Twin Attack** is now **fully set up and working**.

⚠ **Disclaimer:** This project is for **educational purposes only**. Do not use it for illegal activities.

Let me know if you have any questions! 🚀

