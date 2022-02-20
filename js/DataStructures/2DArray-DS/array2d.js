'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.split('\n');

    main();
});

function readLine() {
    return inputString[currentLine++];
}

function hourglassSum(arr) {
    var max = -99999999;
    var direction = [[-1,-1], [-1, 0], [-1, 1],
                              [ 0, 0],
                     [1, -1], [ 1, 0], [ 1, 1]];
    
    for (let row = 1; row < arr.length - 1; row++){
        for (let col = 1; col < arr[0].length - 1; col++){
            var sum = 0;
            for (let dir = 0; dir < direction.length; dir++){
                sum += arr[row + direction[dir][0]][col + direction[dir][1]];
            }
            max = Math.max(max, sum);
        }
    }
    
    return max;
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    let arr = Array(6);

    for (let i = 0; i < 6; i++) {
        arr[i] = readLine().replace(/\s+$/g, '').split(' ').map(arrTemp => parseInt(arrTemp, 10));
    }

    const result = hourglassSum(arr);

    ws.write(result + '\n');

    ws.end();
}
