// ПРОГРАМА  демонструє  процес
//дистанційного керування Arduino пристроями
//по Bluetooth – каналу
/* Bluetooh Basic: LED ON OFF - Айшкар
  Кодер - Майхох Гіріш
  Веб-сайт - http://bit.do/Avishkar
  Завантажте додаток: https://github.com/Mayoogh/Arduino-Bluetooth-Basic
  Ця програма дозволяє вам керувати світлодіодним сигналом 
  на виході 11 Аrduino за допомогою модуля bluetooth
*/
char data = 0; // змінна для зберігання отриманих даних

void setup ()
{
  Serial.begin (9600); // Встановлюємо швидкість   послідовної передачі даних
  pinMode (11, OUTPUT); // Встановлює цифровий пін 11 як вихідний 
}
void loop()
{
  if(Serial.available () > 0)//Якщо передавані дані  отримані:
{
 // Зчитуємо вхідні дані і зберігаємо їх у змінну для зберігання отриманих даних
  data = Serial.read (); 

  Serial.print(data); // Друк значення внутрішніх даних на послідовному моніторі
  Serial.println ("\n"); // Новий рядок
  if (data == 'F') // Перевіряємо, чи значення даних дорівнює 'F'
  digitalWrite (11, HIGH); // Якщо значення 'F', то світлодіод увімкнеться
  else if (data == 'B') // Перевіряємо, чи значення даних дорівнює 'B'
  digitalWrite (11, LOW);// Якщо значення 'B', то  світлодіод вимкнеться
}
}
