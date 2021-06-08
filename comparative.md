[:arrow_left: На главную](/README.md)

# Сравнение протоклов прикалдного уровня

Данный раздел освещает целевые протоколы прикладного уровня в совокупности, что помогает сформировать общую картино по каждому отдельному решению в сравнении с остальными.

## Ссылки на детальный обзор протокола (по результатам выбора)

[MQTT](mqtt/overview-mqtt.md), [MQTT-SN](mqtt/overview-mqttsn.md), [AMQP](amqp/overview-amqp.md), [CoAP](coap/overview-coap.md), [HTTP](http/overview-http.md), [OPC UA](opcua/overview-opcua.md), [DDS](dds/overview-dds.md), [XMPP](xmpp/overview-xmpp.md)


## Обобщенная таблица с характеристиками протоколов

Таблицу можно пролистывать :arrow_right:

|           | Адапт. к IoT (ограниченность ресурсов) | Трансп.  | Кодировка               | Заголовок (байт) | Потребление | Арх-ра           | Взаимодействие | Асинхр. | Участок сети | Надежность                  | Безопасность                    |
|-----------|----------------------------------------|----------|-------------------------|------------------|-------------|------------------|----------------|---------|--------------|-----------------------------|---------------------------------|
| MQTT      | 4/4                                    | TCP      | Бинарный                | 2-4              | 3.5/4       | Pub/Sub          | С/B            | +       | C2S          | QoS 0, 1, 2                 | TLS/SSL, Login/Password         |
| MQTT-SN   | 4/4                                    | UDP      | Бинарный                | 2-5              | 4/4         | Pub/Sub          | C/G -> B       | +       | C2C          | QoS -1, 0, 1, 2             | DTLS, MQTT Auth                 |
| AMQP      | 3/4                                    | TCP      | Бинарный                | 8                | 3/4         | Pub/Sub          | C/B            | +       | S2S          | Аналог QoS 0, 1             | TLS/SSL, SASL                   |
| HTTP      | 1/4                                    | TCP      | Текст (HTTP/2 бинарный) | -                | 1/4         | Req/Res          | C/S            | -       | C2S          | TCP                         | TLS/SSL, auth Basic/Digest/NTLM |
| CoAP      | 4/4                                    | UDP      | Бинарный                | 4                | 4/4         | Req/Res          | C/S            | +       | C2S, C2C     | QoS 0, 1; децентрализация   | DTLS, стороння аутентификация   |
| OPC UA    | 3/4                                    | TCP      | Бинарный                | 8                | 3/4         | Req/Res          | C/S            | +       | C2S          | TCP + собственные механизмы | TLS, Login/Password             |
| DDS       | 3.5/4                                  | UDP, TCP | Бинарный                | 16               | 3/4         | Pub/Sub, Req/Res | C/C            | +       | C2C          | 23 QoS                      | TLS/DTLS, своя аутентификация   |
| XMPP      | 2/4                                    | TCP      | Текст (XML)             | -                | 2/4         | Req/Res          | C/S            | +       | C2S          | TCP                         | TLS, SASL                       |
| AMQP+MQTT | 4/4                                    | TCP      | Бинарный                | -                | 3/4         | Pub/Sub          | C/B            | +       | C2S, S2S     | QoS 0, 1                    | TLS, SASL                       |
| XMPP+MQTT | 3/4                                    | TCP      | Бинарный                | 2-4              | 2.5/4       | Pub/Sub          | C/S            | +       | C2S          | QoS 0, 1, 2                 | TLS, SASL                       |

Обозначения:
* C — клиент;
* S - сервер;
* B - брокер;
* Pub — публикация;
* Sub — подписка;
* Req — запрос;
* Res — ответ;
* QoS — класс качества обслуживания.

## Общая таблица с оценкой реализаций

|           | Качество документации | Простота разраб. | Универсальность реализаций | Реализации                                                                                                        | ПО (tested)                       | АО (tested)                      |
|-----------|-----------------------|------------------|----------------------------|-------------------------------------------------------------------------------------------------------------------|-----------------------------------|----------------------------------|
| MQTT      | 4/4                   | 4/4              | 4/4                        | [List](https://github.com/hobbyquaker/awesome-mqtt)                                                               | Arduino IDE, PlatformIO + flasher | ESP8266, ESP32, Raspberry Pi, PC |
| MQTT-SN   | 2/4                   | 3/4              | 1/4                        | [List](https://github.com/topics/mqtt-sn)                                                                         | Arduino IDE, PlatformIO + flasher | ESP8266, Raspberry Pi, PC        |
| AMQP      | 4/4                   | 4/4              | 4/4                        | [List](https://github.com/xinchen10/awesome-amqp)                                                                 | Arduino IDE                       | ESP8266, PC                      |
| HTTP      | 4/4                   | 4/4              | 4/4                        | HTTP support almost all; [HTTP/2 List](https://github.com/httpwg/http2-spec/wiki/Implementations)                 | Almost all                        | Almost all                       |
| CoAP      | 3/4                   | 3/4              | 3/4                        | [List](https://github.com/Agile-IoT/awesome-open-iot#coap)                                                        | Arduino IDE, PlatformIO           | ESP8266, ESP32, PC               |
| OPC UA    | 2/4                   | 2/4              | 3/4                        | [List](https://github.com/open62541/open62541/wiki/List-of-Open-Source-OPC-UA-Implementations)                    | PlatformIO + flasher              | ESP32, PC                        |
| DDS       | 3/4                   | 1/4              | 2/4                        | [List](https://github.com/nosovandrew/iot-app-layer-guide/blob/main/dds/overview-dds.md#список-реализаций)        | PlatformIO + flasher              | ESP8266, Raspberry Pi, PC        |
| XMPP      | 1/4                   | 2/4              | 1/4                        | [List](https://github.com/nosovandrew/iot-app-layer-guide/blob/main/xmpp/overview-xmpp.md#список-реализаций-xmpp) | PlatformIO + flasher              | ESP32, PC                        |
| AMQP+MQTT | -                     | 4/4              | 4/4                        | [RabbitMQ broker](https://www.rabbitmq.com) + реализации MQTT-клиентов                                            | Arduino IDE, PlatfromIO + flasher | ESP8266, ESP32, Raspberry Pi, PC |
| XMPP+MQTT | -                     | 3/4              | 4/4                        | [Ejabberd server](https://www.ejabberd.im) + реализации MQTT-клиентов                                             | Arduino IDE, PlatformIO + flasher | ESP8266, ESP32, Raspberry Pi, PC |



Обозначения:
* flasher — ПО для загрузки программ в аппаратную платформу (для ESP32/ESP8266 — ESP-IDF/ESP8266_RTOS_SDK).


## Сравнительный анализ протоколов

### Графики (ранжирование протоколов одновременно по 2 параметрам)

Ранжирование протоколов прикалдного уровня относительно минимального "веса" единицы передаваемых данных и потребления ресурсов оборудования:

<img src="media/comparative/power.png" alt="Msg Length/Power consumption" width="60%" />

Относительно реализации механизмов надежности и безовасности:

<img src="media/comparative/relisec.png" alt="Reliability/Security" width="60%" />

Процесс разработки системы (сложность, затраты времени и ресурсов) и ориентация протокола на задачи и специфику IoT-систем:

<img src="media/comparative/iotorient.png" alt="Dev complexity/IoT orientation" width="60%" />

Популярность протокола среди IoT-систем (сообщество разработчиков, количество успешных проектов) и реализации протокола (разнообразие, функционал, поддержка):

<img src="media/comparative/impl.png" alt="Popularity/Implementations" width="60%" />

Документирование протокола и совместимость с срзличными программными и аппаратными платформами (на примере окружения, представленного на главной странице руководства):

<img src="media/comparative/aopo.png" alt="Documentation/Interconnection" width="60%" />

Размещение протоколов по типовым зонам сети IoT относительно оптимальности использования:

<img src="media/comparative/netplace.png" alt="Best place in IoT network" width="60%" />

[:arrow_left: На главную](/README.md)