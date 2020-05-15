package main

import (
	"log"
	"net/http"
)

func main() {
	s := &http.Server{
		Addr:    ":8080",
		Handler: http.NotFoundHandler(),
	}
	log.Fatal(s.ListenAndServe())
}
