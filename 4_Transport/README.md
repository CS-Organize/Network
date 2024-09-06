# Transport Layer

## Socket

> Process is house, Socket is door
> Socket is API(Application Programming Interface) between Application and Network
> 소켓이 생성될 때 Port라고 하는 식별자가 소켓에 할당된다.

## TCP

[RFC 9293: Transmission Control Protocol (TCP)](https://www.rfc-editor.org/rfc/rfc9293.html)

- 연결지향형 서비스
  - 애플리케이션 계층 메시지를 전송하기 전에 클라이언트와 서버가 서로 전송 제어 정보를 교환하게 한다.
  - 이를 **handshake**라고 하며 이 단계를 지나면 TCP 연결이 두 프로세스의 소켓 사이에 존재하게 된다.
  - 이 연결로 서로에게 동시에 메시지를 보낼 수 있기 때문에 **전이중(full-duplex) 연결**이라고 한다.
- 신뢰적인 데이터 전송 서비스
  - TCP는 애플리케이션에서 바이트 스트림을 소켓으로 전달하면 손실되거나 중복되지 않게 수신 소켓으로 전달한다.
- 혼잡 제어 방식
  - 통신하는 프로세스의 직접 이득보다는 인터넷의 전체 성능 향상을 위한 서비스를 포함
  - 특히, TCP 혼잡 제어는 각 TCP 연결이 네트워크 대역폭을 공평하게 공유할 수 있게끔 제한

### TCP 3-way-handshake & 4-way-handshake

- `SYN` : Synchronize Sequence Numbers
- `ACK` : Acknowledge

```plaintext
1) A --> B  SYN my sequence number is X
2) A <-- B  ACK your sequence number is X
3) A <-- B  SYN my sequence number is Y
4) A --> B  ACK your sequence number is Y
```

## UDP

- 비연결형 서비스
  - 통신을 하기 전에 핸드셰이킹을 하지 않는다.
    -> 추가적인 오버헤드가 없다.
- 비신뢰적인 데이터 전송 서비스
  - 하나의 프로세스가 UDP 소켓으로 메시지를 보내면 그 메시지가 수신 소켓에 도착하는 것을 보장하지 않는다.
- 혼잡 제어 방식 X
  - UDP의 송신 측은 데이터를 원하는 속도로 하위 계층으로 보낼 수 있다.
