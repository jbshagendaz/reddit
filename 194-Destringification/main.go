package main

import (
   "fmt"
   "os"
   "strings"
)

func main() {
   argsWithoutProg := os.Args[1:]

   fmt.Printf(strings.Join(argsWithoutProg, " "))
}