# Network

> A repository to study and organize network.

## Network Model

![TCP/IP Model (Internet Protocol Suite)](https://www.youtube.com/watch?v=HFRU01uS9nA&t=2s)

### [OSI Model](https://en.wikipedia.org/wiki/OSI_model)

| Layer | Name                                    | Function                                                                     | Device               |
| :---: | :-------------------------------------- | :--------------------------------------------------------------------------- | :------------------- |
|   7   | [Application](/7_Application/README.md) | Network process to application. e.g. HTTP, FTP, SMTP, DNS, DHCP, Telnet, SSH | -                    |
|   6   | [Presentation]()                        | Data representation and encryption. e.g. SSL, TLS                            | -                    |
|   5   | [Session]()                             | Interhost communication. e.g. Cookies, Token                                 | -                    |
|   4   | [Transport](/4_Transport/README.md)     | End-to-end connections and reliability                                       | -                    |
|   3   | [Network]()                             | Path determination and IP                                                    | Router               |
|   2   | Data Link                               | MAC and LLC                                                                  | Switch, Bridge       |
|   1   | Physical                                | Media, signal and binary transmission                                        | Hub, Repeater, Cable |

### [TCP/IP Model](https://en.wikipedia.org/wiki/Internet_protocol_suite)

| Layer | Name                                    | Function                                                                     | Device               |
| :---: | :-------------------------------------- | :--------------------------------------------------------------------------- | :------------------- |
|   5   | [Application](/7_Application/README.md) | Network process to application. e.g. HTTP, FTP, SMTP, DNS, DHCP, Telnet, SSH | -                    |
|   4   | [Transport](/4_Transport/README.md)     | End-to-end connections and reliability                                       | -                    |
|   3   | [Network](/3_Network/README.md)       | Path determination and IP                                                    | Router               |
|   2   | [Data Link](/2_DataLink/README.md)               | MAC and LLC                                                                  | Switch, Bridge       |
|   1   | [Physical](/1_Physical/README.md)       | Media, signal and binary transmission                                        | Hub, Repeater, Cable |

### What is the difference between OSI and TCP/IP Model?

> OSI 모델은 이론적인 모델이고, TCP/IP 모델은 실제로 사용되는 모델이다.

- [Are we using TCP/IP or OSI in internet? - Stack Overflow](https://stackoverflow.com/questions/9329105/are-we-using-tcp-ip-or-osi-in-internet/28437700#28437700)
- [Does session in "http session" mean the same as in "session layer" in OSI model? - Network Engineering Stack Exchange](https://networkengineering.stackexchange.com/questions/33481/does-session-in-http-session-mean-the-same-as-in-session-layer-in-osi-model)

### Behavior by Layer

**HTTP** GET 요청 전송 => `Message` \
요청 데이터를 **TSL** 로 암호화 \
HTTP 는 상태를 유지하지 않기 때문에 효율적, 유저 편의성 위한 세션 설정(**cookie**)

HTTP는 디폴트로 **TCP**를 사용하기 때문에 헤더에서의 설정이 없다면 TCP \
이 때 데이터를 `Segment`로 쪼개고 헤더를 붙여서 `Segment`으로 만듦

패킷을 전송하기 위해서 헤더에 IP 네트워크 식별자를 붙여서 수신 호스트로 **라우팅** => `Datagram`

1. 패킷이 라우터에 도착 => 포워딩 테이블에서 경로를 확인 => 네트워크 계층
2. 라우터가 패킷(frame) 전송 => 데이터 링크 계층(실질적인 비트 전송은 물리 계층, 실제 물리적 장치 꼬임쌍선, 광섬유 등)
3. 수신 호스트에 도달할 때까지 1, 2 반복
