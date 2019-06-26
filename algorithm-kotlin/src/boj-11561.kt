import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val T = readLine().toInt()
    fun decision(n: Long, k : Long) : Boolean{
        return n.toULong() >= (k.toULong().plus(1.toULong())) * (k.toULong()) / (2.toULong())
    }
    fun optimize(n : Long) : Long {
        var lo = 0L
        var hi = n + 1
        while(lo + 1 < hi) {
            val mid = (lo + hi) / 2
            if(decision(n, mid))
                lo = mid
            else
                hi = mid
        }
        return lo
    }
    //근의 공식
    fun calc(n : Long) : Long{
        return (-1 + Math.sqrt(1+8*n.toDouble()).toLong()) / 2
    }
    repeat(T) {
        val N = readLine().toLong()
        println(optimize(N))
    }
}