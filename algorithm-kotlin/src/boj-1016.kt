import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val (min,max) = readLine().split(' ').map{it.toLong()}

    val end = Math.sqrt(max.toDouble()).toLong()
    val checkArray = BooleanArray(1000001){false}
    for (i in 2..end) {
        val ss = i * i
        val start = ((min - 1) / ss + 1) * ss
        var a = start
        while (a <= max) {
            checkArray[(a - min).toInt()] = true
            a += ss
        }
    }
    var count = 0
    for (i in 0 until max - min + 1) {
        count += if (checkArray[i.toInt()]) 1 else 0
    }
    print(max - min - count.toLong() + 1)
}
