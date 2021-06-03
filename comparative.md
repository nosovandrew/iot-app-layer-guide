# Сравнение протоклов прикалдного уровня

Данный раздел освещает целевые протоколы прикладного уровня в совокупности, что помогает сформировать общую картино по каждому отдельному решению в сравнении с остальными.

## Обобщенная таблица с характеристиками протоколов

|           | Адаптация к IoT | Транспорт | Кодирование             | Заголовок (байт) | Архитектура      | Модель взаимодействия                            | Участок сети                 | Надежность                  | Безопасность                    | Сложность разработки |
|-----------|-----------------|-----------|-------------------------|------------------|------------------|--------------------------------------------------|------------------------------|-----------------------------|---------------------------------|----------------------|
| MQTT      | 4/4             | TCP       | Бинарный                | 2-4              | Pub/Sub          | Client/Broker                                    | Client2Server                | QoS 0, 1, 2                 | TLS/SSL, Login/Password         | 1/4                  |
| MQTT-SN   | 4/4             | UDP       | Бинарный                | 2-5              | Pub/Sub          | Client/Gateway -> MQTT-broker (централизованная) | Client2Client                | QoS -1, 0, 1, 2             | DTLS, MQTT Auth                 | 2/4                  |
| AMQP      | 3/4             | TCP       | Бинарный                | 8                | Pub/Sub          | Client/Broker                                    | Server2Server                | Аналог QoS 0, 1             | TLS/SSL, SASL                   | 1/4                  |
| HTTP      | 1/4             | TCP       | Текст (HTTP/2 бинарный) | -                | Req/Res          | Client/Server                                    | Client2Server                | TCP                         | TLS/SSL, auth Basic/Digest/NTLM | 1/4                  |
| CoAP      | 4/4             | UDP       | Бинарный                | 4                | Req/Res          | Client/Server                                    | Client2Server, Client2Client | QoS 0, 1; децентрализация   | DTLS, стороння аутентификация   | 2/4                  |
| OPC UA    | 3/4             | TCP       | Бинарный                | 8                | Req/Res          | Client/Server                                    | Client2Server                | TCP + собственные механизмы | TLS, Login/Password             | 3/4                  |
| DDS       | 3,5/4           | UDP, TCP  | Бинарный                | 16               | Pub/Sub, Req/Res | Client/Client                                    | Client2Client                | 23 уровня QoS               | TLS/DTLS, своя аутентификация   | 4/4                  |
| XMPP      | 2/4             | TCP       | Текст (XML)             | -                | Req/Res          | Client/Server                                    | Client2Server                | TCP                         | TLS, SASL                       | 3/4                  |
| AMQP+MQTT | 4/4             | TCP       | Бинарный                | -                | Pub/Sub          | Client/Broker                                    | Client2Server, Server2Server | QoS 0, 1                    | TLS, SASL?                      | 1/4                  |
| XMPP+MQTT | 3/4             | TCP       | Бинарный                | 2-4              | Pub/Sub          | Client/Server                                    | Client2Server                | ?                           | TLS, SASL?                      | 2/4                  |

