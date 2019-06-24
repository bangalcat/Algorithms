import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val n = readLine().toLong()

    fun decision(x : Long) = x*x >= n

    fun optimize() : Long {
        var lo = -1L
        var hi= Math.sqrt(1L.shl(63).minus(1).toDouble()).toLong() + 1
//        for(iter in 1..200){
        while(lo + 1 < hi){
            val mid = (hi + lo) / 2
            println("$hi $lo $mid")
            if(decision(mid))
                hi = mid
            else
                lo = mid
        }
        return hi
    }
//    3037000499
//    4294967297
    println(optimize())
}