# Climb the Leaderboard
Alice is playing an arcade game and wants to climb to the top of the leaderboard and wants to track her ranking. The game uses [Dense Ranking](https://en.wikipedia.org/wiki/Ranking#Dense_ranking_.28.221223.22_ranking.29), so its leaderboard works like this:

* The player with the highest score is ranked number *1*  on the leaderboard.
* Players who have equal scores receive the same ranking number, and the next player(s) receive the immediately following ranking number. 

For example, the four players on the leaderboard have high scores of  *100*  , *90* , *90*  , and *80*  . Those players will have ranks *1*  ,  *2* ,  *2*  , and *3*  , respectively. If Alice's scores are *70*  ,  *80*   and  *105*  , her rankings after each game are  *4* <sup>th</sup> , *3* <sup>rd</sup>  and  *1* <sup>st</sup> .

### Function Description
Complete the climbingLeaderboard function in the editor below. It should return an integer array where each element *res[j]*  represents Alice's rank after the *j* <sup>th</sup>  game.

climbingLeaderboard has the following parameter(s):

* scores: an array of integers that represent leaderboard scores
* alice: an array of integers that represent Alice's scores

### Input Format
The first line contains an integer  *n*   , the number of players on the leaderboard. 

The next line contains  *n*   space-separated integers  *scores[i]*   , the leaderboard scores in decreasing order. 

The next line contains an integer, *m* , denoting the number games Alice plays. 

The last line contains  *m*   space-separated integers *alice[j]*  , the game scores.

### Constraint

*  *1*  <ins><</ins>   *n*   <ins><</ins>  *2 × 10* <sup>5</sup>   
*  *1*   <ins><</ins>   *m*   <ins><</ins>  *2 × 10* <sup>5</sup>   
*  *0*   <ins><</ins>   *scores[i]*   <ins><</ins>  *10* <sup>9</sup>   for   *0*   <ins><</ins>  *i*  <ins><</ins>  *n*  
*  *0*   <ins><</ins>   *alice[j]*   <ins><</ins>  *10* <sup>9</sup>   for  *0*   <ins><</ins>   *j*   <ins><</ins>  *m*    
* The existing leaderboard,  *scores* , is in descending order.
* Alice's scores, *alice* , are in ascending order.

### Subtask
