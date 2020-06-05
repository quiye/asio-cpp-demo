# asio-cpp-demo

## Run Server

```sh
$ go run main.go
2020/06/06 01:09:28 running ...
```

## Build Client

```sh
$ g++ main.cpp -o main -I asio/asio/include -lpthread -std=c++17
```

## Run Client

```sh
$ ./main
HTTP/1.0 200 OK
Content-Type: text/plain; charset=utf-8
X-Content-Type-Options: nosniff
Date: Fri, 05 Jun 2020 16:09:42 GMT
Content-Length: 6

OK OK
```
