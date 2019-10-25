# Masterchef Abdoel

Masterchef Abdoel sangat ahli memasak berbagai jenis menu makanan dengan menggunakan 3 bahan baku yaitu Ayam, Bebek, dan Cumi yang direpresentasikan dengan **A**, **B**, dan **C**. Beliau sangat terkenal hingga banyak restaurant ingin memakai jasa chef tersebut. Meskipun beliau sangat ahli dalam memasak, beliau kurang ahli dalam mengatur 3 bahan baku tersebut. Beliau juga ingin memaksimalkan keuntungan setiap restoran yang memakai jasanya agar pemilik restoran selalu senang. Untuk itu, chef Abdoel meminta bantuan kalian untuk mengatur 3 bahan baku yang dipakai agar memperoleh keuntungan yang maksimal pada setiap restoran yang menyewa jasa chef Abdoel.

Setiap test case yang berbeda mewakili restoran yang berbeda. Setiap restoran memiliki **N** jenis menu makanan. Setiap restoran memiliki aturan maksimal perulangan pembuatan menu makanan sebanyak **K** kali. Jumlah stok 3 jenis bahan baku pada setiap restoran berbeda-beda yang direpresentasikan dengan **totA**, **totB**, dan **totC**. Setiap menu memerlukan 3 jenis bahan baku dan keuntungan yang jumlahnya berbeda-beda yang direpresentasikan dengan **A[i]**, **B[i]**, **C[i]**, dan **P[i]**. Tentukan keuntungan maksimal yang dapat diperoleh pada setiap restoran!

## Input Format

Baris 1 adalah jumlah menu makanan pada restaurant **N** dan maksimal perulangan menu yang dapat dimasak pada restaurant **K** yang dipisahkan dengan spasi.

Baris 2 adalah jumlah maksimum masing-masing jenis bahan baku yang tersedia **totA**, **totB**, **totC** yang dipisahkan dengan spasi.

**N** baris berikutnya adalah jumlah masing-masing jenis bahan baku untuk membuat menu makanan **A[i]**, **B[i]**, **C[i]** dan keuntungan menu makanan **P[i]** yang dipisahkan dengan spasi.

## Constraints

~~~
1 <= N <= 20

1 <= K <= 7

1 <= (K+1)^N <= 10,000,000

1 <= totA, totB, totC <= 100

0 <= A[i], B[i], C[i] <= 10, dengan 1 <= i <= N

10 <= P[i] <= 100, dengan 1 <= i <= N
~~~

## Output Format

Keuntungan maksimum yang dapat diperoleh

### Sample Input 0

~~~
3 1
3 2 7
1 2 3 22
2 1 1 15
1 1 1 18
~~~

### Sample Output 0

~~~
33
~~~

### Explanation 0

Terdapat 3 menu dan maksimum perulangan memasak adalah 1.

Jika memasak menu pertama, kita tidak bisa memasak menu yang lain karena bahan baku **B** habis.

Jika memasak menu kedua, kita bisa memasak menu ketiga juga karena bahan baku masih cukup untuk memasak menu ketiga.

Maka, keuntungan maksimal adalah ketika memasak menu kedua dan ketiga dengan keuntungan total adalah 33.

## Hint

This problem can be solved using Dynamic Programming. It is a knapsack multidimensional problem.
