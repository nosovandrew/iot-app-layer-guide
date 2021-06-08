# Установка и подготовка среды разработки Arduino IDE для работы с платами Espressif:
   1. Скачиваем и устанавливаем драйвер [Cilicon Labs CP210xVCPDriver](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers) (обнаружение USBtoUART интерфейса на ПК Mac OS);
   2. Скачиваем и устанавливаем [Arduino IDE](https://www.arduino.cc/en/software);
   3. Проходим путь ```File > Preferences > Additional Boards Manager```  и в поле ссылок вствляем ```http://arduino.esp8266.com/stable/package_esp8266com_index.json``` для работы с ESP8266, либо ```https://dl.espressif.com/dl/package_esp32_index.json``` для ESP32;
   4. Проходим ```Tools > Board menu``` и выбираем нужную версию аппаратного обеспечения ```ESP8266 Boards > Generic ESP8266 Module```, либо ```ESP32 Arduino > ESP32 Dev Module```;
   5. Все готово к работе, можно писать код и загружать его в микроконтроллер!