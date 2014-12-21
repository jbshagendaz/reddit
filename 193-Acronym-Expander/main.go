package main

import (
   "bufio"
   "fmt"
   "os"
   "strings"    
)

func main() {
   in := bufio.NewReader(os.Stdin)

   abbr := make(map[string]string)
   abbr["lol"] = "laugh out loud"
   abbr["dw"]  = "don't worry"
   abbr["hf"]  = "have fun"
   abbr["gg"]  = "good game"
   abbr["brb"] = "be right back"
   abbr["g2g"] = "got to go"
   abbr["wtf"] = "what the fuck"
   abbr["wp"]  = "well played"
   abbr["gl"]  = "good luck"
   abbr["imo"] = "in my opinion"

   fmt.Print("Enter Text: ") 
   text, err := in.ReadString('\n')

   if err != nil {
        fmt.Println(err)
        return
   }

   strArr := strings.Fields(text)

   for i:=0; i<len(strArr); i++ {
      if val, ok := abbr[strArr[i]]; ok {
         strArr[i] = val
      }
   }

   fmt.Println(strings.Join(strArr, " "))   
}