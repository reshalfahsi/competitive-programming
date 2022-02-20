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


function breakingRecords(scores) {
    var max = scores[0];
    var min = scores[0];
    var best = 0;
    var worst = 0;
    
    for (let idx = 1; idx < scores.length; idx ++){
        if (scores[idx] > max){
            max = scores[idx];
            best++;
        }
        if (scores[idx] < min){
            min = scores[idx];
            worst++;
        }
    }
    return [best, worst];
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const n = parseInt(readLine().trim(), 10);

    const scores = readLine().replace(/\s+$/g, '').split(' ').map(scoresTemp => parseInt(scoresTemp, 10));

    const result = breakingRecords(scores);

    ws.write(result.join(' ') + '\n');

    ws.end();
}
