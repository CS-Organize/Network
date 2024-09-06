# Application Layer

## HTTP (HyperText Transfer Protocol)

Web page는 기본 object들로 구성
object : HTML 파일, JPEG 이미지, JS, CSS, Video 등의 파일 등

> http://www.someSchool.edu/someDepartment/picture.gif

- host name: `http://www.someSchool.edu`
- path name: `/someDepartment/picture.gif`

TCP를 전송 프로토콜로 사용

HTTP 서버는 클라이언트에 대한 정보를 유지하지 않으므로, HTTP를 비상태 프로토콜(stateless protocol)이라고 한다.

## Port
송신 호스트는 수신 호스트뿐만 아니라 수행되는 수신 프로세스도 식별해야 한다.

Port number이 이 목적을 위해 사용된다

## DNS (Domain Name System)
라우터는 식별자로 IP를 사용하지만
사람은 hostname를 식별자를 사용한다.

DNS란 hostname을 IP 주소로 변환해주는 서비스

## TLS

TCP를 강화한 TLS(Transport Layer Security)
**TCP, UDP 와 같은 계층의 전송 계층이 아닌 애플리케이션 계층에서 구현되었다.**

TLS를 사용하기 위해 통신하는 두 호스트는 TLS 코드를 포함해야한다.

TLS는 TCP 소켓 API와 유사한 자신의 소켓 API를 갖고 있다.

1. 애플리케이션 계층의 송신 프로세스는 평문 데이터를 TLS 소켓에게 전달
2. TLS는 데이터를 암호화한 후 TCP 소켓으로 전달
3. TCP는 수신 프로세스에 있는 TCP 수신 소켓으로 전달
4. 수신 소켓은 암호화된 데이터를 TLS로 전달
5. TLS는 암호를 풀고 평문 데이터를 수신 프로세스로 전달
