package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strings"
)

func marsExploration(s string) int32 {
    var sum int32 = 0
    var message string = "SOS"
    for idx := 0; idx < len(s) - 2; idx += 3{
        if s[idx:idx+3] != message{
            for n, m := range message{
                if s[idx + n] != byte(m){
                    sum += 1
                }
            }
        }
    }
    return sum
}

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 16 * 1024 * 1024)

    stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
    checkError(err)

    defer stdout.Close()

    writer := bufio.NewWriterSize(stdout, 16 * 1024 * 1024)

    s := readLine(reader)

    result := marsExploration(s)

    fmt.Fprintf(writer, "%d\n", result)

    writer.Flush()
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
    if err != nil {
        panic(err)
    }
}
