[RFC (Request for Comments)](https://en.wikipedia.org/wiki/Request_for_Comments)란 인터넷 기술 표준 기관인 [IETF (Internet Engineering Task Force)](https://en.wikipedia.org/wiki/Internet_Engineering_Task_Force)에서 발행하는 문서의 종류다.

많은 RFC 문서들은 정보 제공용이거나 실험용이며 표준이 아니다.
하지만 IETF는 RFC로 게시된 문서 일부를 인터넷 표준으로 채택한다.

webserv 과제는 HTTP/1.1를 준수해야 하므로 2022년에 개정된 HTTP/1.1 표준 문서인 [RFC 9112](https://www.rfc-editor.org/rfc/rfc9112)를 참고하였다.
## HTTP
[HTTP(HyperText Transfer Protocol)](https://en.wikipedia.org/wiki/HTTP)는 [WWW(World Wide Web)](https://en.wikipedia.org/wiki/World_Wide_Web)에서 정보를 주고받기 위한 프로토콜이다.

여기서 말하는 [HyperText](https://en.wikipedia.org/wiki/Hypertext)란 다른 텍스트에 대한 참조가 있는 텍스트를 말한다.
html 문서의 <a href="..."></a> 태그가 이에 해당한다.

client-server 모델에서 request-response 프로토콜로 동작한다.
client는 `HTTP Request`를 server에 보내고, server는 `HTTP Response`를 client에 보낸다.

### [HTTP Request Message Format](https://en.wikipedia.org/wiki/HTTP#HTTP/1.1_request_messages)
![](/img/request.png)
```http
<method> <request-URI> <version>
<field-name>: <field-value>
...
<field-name>: <field-value>

<optional message body>
```  

#### Request-Line
```http
<method> <request-URI> <version>

GET /somedir/page.html HTTP/1.1
```
- `Method`: GET
- `Request-URI`: /somedir/page.html
- `Version`: HTTP/1.1

다른 Method들은 [여기서](https://en.wikipedia.org/wiki/HTTP#Request_methods) 볼 수 있다.

#### Header Fields
```http
<field-name>: <field-value>
Host: www.google.com
Connection: close
User-agent: Mozilla/5.0
Accept-language: en
```
`Host: hostname` 을 제외한 모든 헤더 필드는 선택 사항이다.
- `Host`: www.google.com, 객체가 존재하는 호스트(파일이 존재하는 서버)
- `Connection`: close, 서버에서 지속 연결을 원하지 않음을 알림
- `User-agent`: Mozilla/5.0, 클라이언트의 소프트웨어 정보
- `Accept-language`: en, 클라이언트가 원하는 언어

다른 HTTP 헤더 필드들은 [여기서](https://en.wikipedia.org/wiki/List_of_HTTP_header_fields) 볼 수 있다.
HTTP/1.1의 경우 최소 1개 이상의 요청 헤더 필드가 있어야 한다.

#### Message Body
```http
<optional message body>
```
`optional message body`는 사용자가 `POST` 메소드를 사용했을 때, \<form>에 입력한 데이터를 담는다.
꼭 \<form>으로 생성한 request가 반드시 `POST` 메소드를 사용해야 하는 것은 아니다.

### [HTTP Response Message Format](https://en.wikipedia.org/wiki/HTTP#HTTP/1.1_response_messages)
![](/img/response.png)
```http
<version> <status> <reason-phrase>
<field-name>: <field-value>
...
<field-name>: <field-value>

<optional message body>
```

#### Status-Line
```http
<version> <status> <reason-phrase>
HTTP/1.1 200 OK
```
- `Version`: HTTP/1.1
- `Status`: 200
- `Reason-Phrase`: OK

| Status Code |       Reason-Phrase        |                      Description                      |
| :---------: | :------------------------: | :---------------------------------------------------: |
|     200     |             OK             |               요청이 성공했고, 정보가 응답으로 보내졌다.                |
|     301     |     Moved Permanently      | 요청한 리소스가 새로운 URL로 옮겨졌다. 새로운 URL은 응답의 Location 헤더에 있다. |
|     400     |        Bad Request         |                   서버가 요청을 이해할 수 없다.                   |
|     404     |         Not Found          |                   요청한 리소스가 서버에 없다.                    |
|     505     | HTTP Version Not Supported |              서버가 요청한 HTTP 버전을 지원하지 않는다.               |
다른 Status들은 [여기서](https://en.wikipedia.org/wiki/List_of_HTTP_status_codes) 볼 수 있다.

#### Header Fields
```http
<field-name>: <field-value>
Connection: close
Date: Tue, 11 Jun 2024 22:34:12 GMT
Server: Apache/2.2.3 (CentOS)
Last-Modified: Tue, 11 Jun 2024 22:34:12 GMT
Content-Length: 6821
Content-Type: text/html
```
- `Connection`: close, 클라이언트에게 메시지를 보낸 후 TCP 연결을 닫을 것을 알림
- `Date`: Tue, 11 Jun 2024 22:34:12 GMT, 메시지가 생성되고 보내진 시간, 객체가 생성되거나 마지막으로 수정된 시간이 아님
- `Server`: Apache/2.2.3 (CentOS), 서버의 소프트웨어 정보
- `Last-Modified`: Tue, 11 Jun 2024 22:34:12 GMT, 객체가 마지막으로 수정된 시간, 캐싱에 매우 중요
- `Content-Length`: 6821, 송신되는 객체의 바이트 수
- `Content-Type`: text/html, 객체의 MIME 타입

### [Example of request and response](https://en.wikipedia.org/wiki/HTTP#HTTP/1.1_example_of_request_/_response_transaction)
#### Request
```http
GET / HTTP/1.1
Host: www.example.com
User-Agent: Mozilla/5.0
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,*/*;q=0.8
Accept-Language: en-GB,en;q=0.5
Accept-Encoding: gzip, deflate, br
Connection: keep-alive
```

#### Response
```http
HTTP/1.1 200 OK
Date: Mon, 23 May 2005 22:38:34 GMT
Content-Type: text/html; charset=UTF-8
Content-Length: 155
Last-Modified: Wed, 08 Jan 2003 23:11:55 GMT
Server: Apache/1.3.3.7 (Unix) (Red-Hat/Linux)
ETag: "3f80f-1b6-3e1cb03b"
Accept-Ranges: bytes
Connection: close

<html>
	<head>
		<title>An Example Page</title>
	</head>
	<body>
		<p>Hello World, this is a very simple HTML document.</p>
	</body>
</html>
```
