Program ini berfungsi untuk **mendeteksi gas atau asap** menggunakan sensor **MQ-2**, dan **menyalakan/mematikan LED** (sebagai indikator) berdasarkan kadar gas yang terdeteksi.

---

### 🔹 1. **Deklarasi Pin**

```cpp
const int mqPin = A0;   // Sensor MQ-2 terhubung ke pin analog A0
const int ledPin = 13;  // LED indikator terhubung ke pin digital 13
```

* **A0** digunakan untuk membaca sinyal analog dari sensor MQ-2.
* **Pin 13** adalah LED internal di board Arduino (biasanya terhubung langsung ke LED bawaan).

---

### 🔹 2. **Setup**

```cpp
Serial.begin(9600);
pinMode(ledPin, OUTPUT);
```

* Mengaktifkan komunikasi **Serial Monitor** untuk menampilkan nilai sensor.
* Mengatur **pin LED** sebagai **output**.

---

### 🔹 3. **Loop (Perulangan Utama)**

```cpp
int sensorValue = analogRead(mqPin);
```

Membaca nilai analog dari **0 hingga 1023**, tergantung pada **konsentrasi gas/asap** di sekitar sensor.
Semakin tinggi nilai, semakin banyak gas yang terdeteksi.

---

### 🔹 4. **Kondisi Logika**

```cpp
if (sensorValue > 500) {
  digitalWrite(ledPin, LOW);
  Serial.println("Deteksi Gas!");
} else {
  digitalWrite(ledPin, HIGH);
}
```

* Jika nilai sensor lebih dari **500**, berarti ada gas terdeteksi.
  → LED **menyala (LOW)** dan muncul teks “Deteksi Gas!” di Serial Monitor.
* Jika nilai sensor kurang dari **500**, dianggap aman.
  → LED **mati (HIGH)**.

(*Catatan:* logika LED bisa terbalik tergantung board Arduino; pada board Uno, pin 13 LED menyala saat diberi **LOW**.)

---

### 🔹 5. **Delay**

```cpp
delay(1000);
```

Program menunggu 1 detik sebelum membaca ulang sensor.

---

## ⚡ **Wiring / Koneksi Rangkaian**

| Komponen                                       | Pin Arduino      | Keterangan                              |
| ---------------------------------------------- | ---------------- | --------------------------------------- |
| **Sensor MQ-2**                                | VCC → 5V         | Daya sensor                             |
|                                                | GND → GND        | Ground                                  |
|                                                | AOUT → A0        | Sinyal analog untuk pembacaan kadar gas |
| **LED (optional, jika ingin pakai eksternal)** | Anoda (+) → D13  | Positif LED                             |
|                                                | Katoda (–) → GND | Lewat resistor 220Ω                     |

---

## 📊 **Nilai Sensor (Referensi)**

| Nilai Analog (0–1023) | Kondisi Lingkungan        |
| --------------------- | ------------------------- |
| 0–200                 | Udara bersih              |
| 200–400               | Asap ringan / gas sedikit |
| 400–700               | Gas mulai tinggi          |
| >700                  | Bahaya, gas/asap pekat    |

Ambang batas **500** bisa diubah sesuai kebutuhan (misalnya `if (sensorValue > 400)` untuk lebih sensitif).

---

## 💡 **Tips Tambahan**

1. Sebelum digunakan, **MQ-2 perlu preheating (pemanasan)** sekitar **1–2 menit** agar pembacaan stabil.
2. Anda bisa menambahkan **buzzer** untuk alarm:

   ```cpp
   const int buzzerPin = 8;
   pinMode(buzzerPin, OUTPUT);
   if (sensorValue > 500) {
       digitalWrite(buzzerPin, HIGH);
   } else {
       digitalWrite(buzzerPin, LOW);
   }
   ```
