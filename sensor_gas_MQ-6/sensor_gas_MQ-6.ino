const int mqPin = A0;   // Pin analog yang terhubung ke sensor MQ-2
const int ledPin = 13;  // Pin built-in LED pada Arduino

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(mqPin); // Membaca nilai analog dari sensor MQ-2
  
  // Anda dapat menambahkan perbandingan atau ambang batas yang sesuai dengan kebutuhan Anda
  // Contoh: Jika sensorValue melebihi ambang batas tertentu, aktifkan LED dan tampilkan pesan
  
  if (sensorValue > 500) {
    digitalWrite(ledPin, LOW); // Aktifkan LED jika deteksi gas
    Serial.println("Deteksi Gas!");
  } else {
    digitalWrite(ledPin, HIGH); // Matikan LED jika tidak ada deteksi gas
  }
  
  delay(1000); // Tunggu 1 detik sebelum membaca sensor lagi
}
