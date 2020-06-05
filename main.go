package main

import (
	"fmt"
	"log"
	"net/http"
)

func main() {
	s := &http.Server{
		Addr: ":8080",
		Handler: func() http.Handler {
			return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
				func(w http.ResponseWriter, out string, code int) {
					log.Printf("%#v", r)
					w.Header().Set("Content-Type", "text/plain; charset=utf-8")
					w.Header().Set("X-Content-Type-Options", "nosniff")
					w.WriteHeader(code)
					fmt.Fprintln(w, out)
				}(w, "OK OK", http.StatusOK)
			})
		}(),
	}

	log.Println("running ...")
	log.Fatal(s.ListenAndServe())
}
