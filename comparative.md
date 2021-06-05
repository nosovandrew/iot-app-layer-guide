# Сравнение протоклов прикалдного уровня

Данный раздел освещает целевые протоколы прикладного уровня в совокупности, что помогает сформировать общую картино по каждому отдельному решению в сравнении с остальными.

## Обобщенная таблица с характеристиками протоколов

|           | Адаптация к IoT | Транспорт | Кодирование             | Заголовок (байт) | Архитектура      | Взаимодействия                                   | Асинхронность | Участок сети                 | Надежность                  | Безопасность                    | Качество реализаций | Простота разработки |
|-----------|-----------------|-----------|-------------------------|------------------|------------------|--------------------------------------------------|---------------|------------------------------|-----------------------------|---------------------------------|---------------------|---------------------|
| MQTT      | 4/4             | TCP       | Бинарный                | 2-4              | Pub/Sub          | Client/Broker                                    | +             | Client2Server                | QoS 0, 1, 2                 | TLS/SSL, Login/Password         | 4/4                 | 4/4                 |
| MQTT-SN   | 4/4             | UDP       | Бинарный                | 2-5              | Pub/Sub          | Client/Gateway -> MQTT-broker (централизованная) | +             | Client2Client                | QoS -1, 0, 1, 2             | DTLS, MQTT Auth                 | 2/4                 | 3/4                 |
| AMQP      | 3/4             | TCP       | Бинарный                | 8                | Pub/Sub          | Client/Broker                                    | +             | Server2Server                | Аналог QoS 0, 1             | TLS/SSL, SASL                   | 3/4                 | 4/4                 |
| HTTP      | 1/4             | TCP       | Текст (HTTP/2 бинарный) | -                | Req/Res          | Client/Server                                    | -             | Client2Server                | TCP                         | TLS/SSL, auth Basic/Digest/NTLM | 4/4                 | 4/4                 |
| CoAP      | 4/4             | UDP       | Бинарный                | 4                | Req/Res          | Client/Server                                    | +             | Client2Server, Client2Client | QoS 0, 1; децентрализация   | DTLS, стороння аутентификация   | 3/4                 | 3/4                 |
| OPC UA    | 3/4             | TCP       | Бинарный                | 8                | Req/Res          | Client/Server                                    | +             | Client2Server                | TCP + собственные механизмы | TLS, Login/Password             | 2/4                 | 2/4                 |
| DDS       | 3.5/4           | UDP, TCP  | Бинарный                | 16               | Pub/Sub, Req/Res | Client/Client                                    | +             | Client2Client                | 23 уровня QoS               | TLS/DTLS, своя аутентификация   | 2/4                 | 1/4                 |
| XMPP      | 2/4             | TCP       | Текст (XML)             | -                | Req/Res          | Client/Server                                    | +             | Client2Server                | TCP                         | TLS, SASL                       | 1/4                 | 2/4                 |
| AMQP+MQTT | 4/4             | TCP       | Бинарный                | -                | Pub/Sub          | Client/Broker                                    | +             | Client2Server, Server2Server | QoS 0, 1                    | TLS, SASL?                      | 4/4                 | 4/4                 |
| XMPP+MQTT | 3/4             | TCP       | Бинарный                | 2-4              | Pub/Sub          | Client/Server                                    | +             | Client2Server                | QoS 0, 1, 2                 | TLS, SASL?                      | 4/4                 | 3/4                 |

## Сравнительный анализ протоколов

### Графики (ранжирование протоколов одновременно по 2 параметрам)

Ранжирование протоколов прикалдного уровня относительно минимального "веса" единицы передаваемых данных и потребления ресурсов оборудования:

![Msg Length/Power consumption](../media/comparative/power.png)

Относительно реализации механизмов надежности и безовасности:

![Reliability/Security](../media/comparative/relisec.png)

Процесс разработки системы (сложность, затраты времени и ресурсов) и ориентация протокола на задачи и специфику IoT-систем:

![Dev complexity/IoT orientation](../media/comparative/iotorient.png)

Популярность протокола среди IoT-систем (сообщество разработчиков, количество успешных проектов) и реализации протокола (разнообразие, функционал, поддержка):

![Popularity/Implementations](../media/comparative/impl.png)

Документирование протокола и совместимость с срзличными программными и аппаратными платформами (на примере окружения, представленного на главной странице руководства):

![Documentation/Interconnection](../media/comparative/aopo.png)

Размещение протоколов по типовым зонам сети IoT относительно оптимальности использования:

![Best place in IoT network](../media/comparative/netplace.png)

[:arrow_left: На главную](/README.md)