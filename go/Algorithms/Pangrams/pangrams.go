package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strings"
)

func pangrams(s string) string {
    lookup := make(map[rune]int)
    for _, str := range s{
        temp := int(str)
        if temp > 90 { temp -= 32}
        str = rune(byte(temp))
        if str != ' '{
            lookup[str] = 1
        }
    }
    retval := "pangram"
    if len(lookup) < 26 { retval = "not pangram"}
    return retval
}

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 16 * 1024 * 1024)

    stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
    checkError(err)

    defer stdout.Close()

    writer := bufio.NewWriterSize(stdout, 16 * 1024 * 1024)

    s := readLine(reader)

    result := pangrams(s)

    fmt.Fprintf(writer, "%s\n", result)

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
