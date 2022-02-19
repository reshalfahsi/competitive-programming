package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
    "math"
)

func gcd(x, y int64) int64{
    if y == 0{
        return x
    }
    return gcd(y, x%y)
}

func solve(a int64, b int64, c int64) string {
    
    var num int64
    var denum int64
    
    if a + b < c{
        num = 1
        denum = 1
        //
        // A
        // #
        // # \
        // #    \       
        // #++++  \    
        // #   +    \ 
        // ############### B
        //
        // P( x + y < C ) = 1
    } else if a >= c && b >= c{
        num = c * c
        denum = 2 * a * b
        //
        // A
        // #
        // #++++++++++++
        // # \         +
        // #   \       +
        // #     \     +
        // ############### B
        //
        //  P( x + y < C ) = area of triangle / area of rectangle
        //  0.5 c^2 / a * b
        //
    } else if a <= c && b <= c{
        num = 2 * a * b - int64(math.Pow(float64(a - c + b), 2))
        denum = 2 * a * b
        //
        //   A
        //   # \
        //   #   \
        //   #+++++\+++
        //   #       \+
        //   #        +\
        //   ############### B
        //             
        //
    } else {
        A := int64(math.Max(float64(a), float64(b)))
        B := int64(math.Min(float64(a), float64(b)))
        num = c * c - int64(math.Pow(float64(c - B), 2))
        denum = 2 * A * B
        //
        //   A
        //   # \
        //   #   \
        //   #+++++\++++++
        //   #       \   +
        //   #         \ +
        //   ############### B
        //             
        //
    }
    
    scale := gcd(num, denum)
    num /= scale
    denum /= scale
    return strconv.Itoa(int(num)) + "/" + strconv.Itoa(int(denum))
}

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 16 * 1024 * 1024)

    stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
    checkError(err)

    defer stdout.Close()

    writer := bufio.NewWriterSize(stdout, 16 * 1024 * 1024)

    nTemp, err := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
    checkError(err)
    n := int64(nTemp)

    for nItr := 0; nItr < int(n); nItr++ {
        firstMultipleInput := strings.Split(strings.TrimSpace(readLine(reader)), " ")

        aTemp, err := strconv.ParseInt(firstMultipleInput[0], 10, 64)
        checkError(err)
        a := int64(aTemp)

        bTemp, err := strconv.ParseInt(firstMultipleInput[1], 10, 64)
        checkError(err)
        b := int64(bTemp)

        cTemp, err := strconv.ParseInt(firstMultipleInput[2], 10, 64)
        checkError(err)
        c := int64(cTemp)

        result := solve(a, b, c)

        fmt.Fprintf(writer, "%s\n", result)
    }

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
