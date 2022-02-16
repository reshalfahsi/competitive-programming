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

func solve(steps [][]int64) int64 {
    var inter_top int64 = -1; // y
    var inter_bottom int64 = -1; // y
    var inter_left int64 = -1; // x
    var inter_right int64 = -1; // x
    
    for _, s := range steps{
        temp_top := s[0];
        temp_left := int64(0);
        temp_bottom := int64(0);
        temp_right := s[1];
        
        if inter_top == -1{
            
            inter_top = temp_top;
            inter_left = temp_left;
            inter_bottom = temp_bottom;
            inter_right = temp_right;
            
        } else{
            top := int64(math.Min(float64(inter_top), float64(temp_top)));
            left := int64(math.Max(float64(inter_left), float64(temp_left)));
            bottom := int64(math.Max(float64(inter_bottom), float64(temp_bottom)));
            right := int64(math.Min(float64(inter_right), float64(temp_right)));
            
            inter_top = top;
            inter_left = left;
            inter_bottom = bottom;
            inter_right = right;            
        }
    }
    
    A := int64(math.Max(0, float64(inter_right - inter_left)));
    B := int64(math.Max(0, float64(inter_top - inter_bottom)));

    return A * B;

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

    var steps [][]int64
    for i := 0; i < int(n); i++ {
        stepsRowTemp := strings.Split(strings.TrimRight(readLine(reader)," \t\r\n"), " ")

        var stepsRow []int64
        for _, stepsRowItem := range stepsRowTemp {
            stepsItemTemp, err := strconv.ParseInt(stepsRowItem, 10, 64)
            checkError(err)
            stepsItem := int64(stepsItemTemp)
            stepsRow = append(stepsRow, stepsItem)
        }

        if len(stepsRow) != 2 {
            panic("Bad input")
        }

        steps = append(steps, stepsRow)
    }

    result := solve(steps)

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
