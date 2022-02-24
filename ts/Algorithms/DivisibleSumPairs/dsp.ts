'use strict';

import { WriteStream, createWriteStream } from "fs";
process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function(inputStdin: string): void {
    inputString += inputStdin;
});

process.stdin.on('end', function(): void {
    inputLines = inputString.split('\n');
    inputString = '';

    main();
});

function readLine(): string {
    return inputLines[currentLine++];
}


function divisibleSumPairs(n: number, k: number, ar: number[]): number {
    var count: number = 0;
    
    for(let idx = 0; idx < n; idx++){
        for(let jdx = idx + 1; jdx < n; jdx++){
            var sum: number = ar[idx] + ar[jdx];
            if(sum % k == 0){
                count++;
            }
        }
    }
    
    return count;

}

function main() {
    const ws: WriteStream = createWriteStream(process.env['OUTPUT_PATH']);

    const firstMultipleInput: string[] = readLine().replace(/\s+$/g, '').split(' ');

    const n: number = parseInt(firstMultipleInput[0], 10);

    const k: number = parseInt(firstMultipleInput[1], 10);

    const ar: number[] = readLine().replace(/\s+$/g, '').split(' ').map(arTemp => parseInt(arTemp, 10));

    const result: number = divisibleSumPairs(n, k, ar);

    ws.write(result + '\n');

    ws.end();
}
