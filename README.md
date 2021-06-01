# Руководство по выбору оптимальной технологической платформы для IoT-систем в конкретных проектах

## Навигация
* [Сравнение протоколов](/comparative.md)
* [Подбор оптиамльного решения](/selection.md)
* Характеристики протоколов
  * [MQTT](mqtt/overview-mqtt.md)
  * [MQTT-SN](mqtt/overview-mqttsn.md)
  * [AMQP](amqp/overview-amqp.md)
  * [CoAP](coap/overview-coap.md)
  * [HTTP](http/overview-http.md)
  * [OPC UA](opcua/overview-opcua.md)
  * [DDS](dds/overview-dds.md)
  * [XMPP](xmpp/overview-xmpp.md)

## Описание разработки
Данный инстрмент (руководство) освещает вопросы, связанные с подбором и реализацией оптимальной технологической платформы для IoT-систем в конкретных проектах, обладающих определенным списком задач и требований.

## Область применения разработки:
#### Сетевой уровень архитектуры IoT
Сетевая моедль IoT-системы (по аналогии с TCP/IP):
| Уровень  	| Реализация  	|
|---	|---	|
| Прикладной  	| &#x2705;  	|
| Транспортный  	| &#x274E;  	|
| Сетевой 	| &#x274E;  	|
| Доступа к сети 	| &#x274E;  	|

##### Обозначения: 
* &#x2705; реализовано
* &#x274E; планируется реализация
* &#x274C; не будет реализовано

## Функционал
* технические характеристики (теоретические и экспериментальные) технологий
* руководсво по реализации демонстрационной системы на базе конкретной технологии (протокола)
* сравнительный анализ технологий
* руководство по подбору оптимального решения (технологии)

## Окружение для реализации демонстрационных систем (следуя шагам в руководстве)

##### Аппаратное обеспечение:
* компьютер под управлением ОС Mac OS (протестировано), либо Linux;
* одноплатный ПК Raspberry Pi (протестирован Raspberry Pi 1 Model B);
* микроконтроллеры фирмы Espressif:
  * ESP8266 (протестирована плата NodeMCU v2 "Amica");
  * ESP32 (протестирован ESP32-WROOM-32).

##### Программное обеспечение
* Среды разработки:
  * [Arduino IDE](https://www.arduino.cc/en/software)
  * [ESP-IDF (ESP32)](https://github.com/espressif/esp-idf)
  * [PlatformIO (расширение VS Code)](https://platformio.org)
  * [ESP8266_RTOS_SDK](https://github.com/espressif/ESP8266_RTOS_SDK)
  * Esoruino (JS)
  * NodeMCU PyFlasher
* Дополнительное ПО:
  * [Cilicon Labs CP210xVCPDriver (драйвер для обнаружения интерфейса USBtoUART под Mac OS)](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers)

*Наличие всего перечисленного не является обязательным, более конкретный список необходимого АО и ПО можно найти в руководстве по реализации конкретной системы (смотреть Навигацию)*


:arrow_up: [Переход к навигации по руководству](#навигация)

## Контактная информация
| Автор | Телеграм | Почта |
|-------|----------|-------|
| Носов Андрей   | [@andrewnosov](https://t.me/andrewnosov)      | <andrewnosov@outlook.com>  |

