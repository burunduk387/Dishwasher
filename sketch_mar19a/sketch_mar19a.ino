#define NOTE_E5  659

int noise[] =
{
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_E5
};
int noise_time[] = 
{
  8, 8, 4,
  8, 8, 4
};
int flag = 0;
const int buzzer = 9; 
const int on_off = 7; 
const int thirty_sec = 8; 
const int mosfet = 10;
const int pressure = A7;
const int water = A6;
void buzz() 
{
  int len = sizeof(noise_time) / sizeof(int);
  for (int i = 0; i < len; i++) 
  {
    int dur = 1000 / noise_time[i];
    tone(buzzer, noise[i], dur);
    delay(dur * 1.3);
    noTone(buzzer);
  }
}
void setup() 
{
  pinMode(mosfet, OUTPUT);
  pinMode(on_off, INPUT);
  pinMode(thirty_sec, INPUT);
  pinMode(mosfet, OUTPUT);
  digitalWrite(mosfet, LOW);
}
void loop() 
{
  if ((analogRead(water) <512) and (flag == 0))
  {
    flag = 1;
    buzz();
    delay(3000);
    buzz();
    delay(3000);
    buzz();
  }
   if (analogRead(water) >= 512)
  {
    flag = 0;
  }
  if ((analogRead(pressure) < 120) and (analogRead(water) >= 512))
  {
    digitalWrite(mosfet, HIGH);
    while ((analogRead(pressure) < 120) and (analogRead(water) >= 512))
    {
      delay(5000);
    }
    digitalWrite(mosfet, LOW);
  }
 /* if ((digitalRead(on_off) == HIGH) and (analogRead(water) >= 512))
  {
    digitalWrite(mosfet, HIGH);
    while (analogRead(water) >= 512)
    {
      delay(50);
      if (digitalRead(on_off) == HIGH)
      {
        break;
      }
    }
    digitalWrite(mosfet, LOW);
  }
  if ((digitalRead(thirty_sec) == HIGH) and (analogRead(water) >= 512))
  {
    digitalWrite(mosfet, HIGH);
    int i = 0;
    while ((analogRead(water) >= 512) and (i < 30000))
    {
      delay(50);
      i += 50;
    }
    digitalWrite(mosfet, LOW);
  }*/
  delay(50);
}
