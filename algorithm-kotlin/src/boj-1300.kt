import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val N = readLine().toLong()
    val K = readLine().toLong()

    fun decision(x : Long) : Boolean{
        var cnt = 0L
        for(i in 1..Math.min(x, N)) {
            cnt += (Math.min(x, N*i)) / i
        }
        return cnt >= K
    }
    fun optimize() : Long {
        var lo = 0L
        var hi = K + 1
        while(lo+1 < hi) {
            val mid = (lo + hi) / 2
//            println("$hi $lo $mid")
            if(decision(mid))
                hi = mid
            else
                lo = mid
        }
        return hi
    }
    println(optimize())
}